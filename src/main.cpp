#include <lvgl.h>
#include <M5Dial-LVGL.h>
#include <Arduino.h>
#include "ui/ui.h"
#include "sys/sleep_mgmt.h"
#include <ha_api.h>
#include <aero_preferences.h>
// #include "ui/screens/sree.h"
#include "sys/aero_time.h"
#include <cppQueue.h>
#include <aero_error_handling.h>
#include "classes/Clock.h"
#include <ImprovWiFiLibrary.h>
#include <WiFi.h>
#include <WebServer.h>
ImprovWiFi improvSerial(&Serial);
HomeAssistant has;
HomeAssistant *ha = &has;
WebServer server(80);

Screen *global_screens[] = {
    &screen_on_off,
    &screen_loading,
    &screen_entity_menu,
    &screen_clock,
    &screen_main_menu,
    &screen_settings,
    &screen_timer_alert,
    &screen_timer_countdown,
    &screen_timer_set};
;
void log_cb(lv_log_level_t level, const char *buf)
{
    Serial.println(buf);
}

void initializeScreens()
{
    for (uint8_t i = 0; i < sizeof(global_screens) / sizeof(global_screens[0]); i++)
    {
        global_screens[i]->initialize();
    }
}
UIError error_wifi_not_defined(F("No Wifi credentials are set"));
UIError error_no_wifi(F("Credentials are set, but cannot connect to the WiFi network"));
#define WIFI_TIMEOUT 5000
void setupWifi(void *params)
{
    if (settings.isKey("wifi_ssid"))
    {
        String ssid = settings.getString("wifi_ssid", "");
        String password = settings.getString("wifi_password", "");
        if (ssid.length() > 0 && password.length() > 0)
        {
            improvSerial.tryConnectToWifi(ssid.c_str(), password.c_str());
        }
    }
    vTaskDelete(NULL);
}

void setup_web_server()
{
    server.on("/", []()
              { server.sendHeader("Location", String("http://homeassistant.local:8123/auth/authorize?client_id=http%3A%2F%2F" + WiFi.localIP().toString() + "&redirect_uri=http%3A%2F%2F" + WiFi.localIP().toString() + "/auth_callback"), true);
                                  server.send(302, "text/plain", ""); });
    server.on("/auth_callback", []()
              {
         for (int i = 0; i < server.args(); i++)
    {
        log_d("%s, %s", server.argName(i), server.arg(i));
        if (server.argName(i).equals("code")) {
            String access_code = server.arg(i);
            String refresh_token = ha->requestRefreshToken(access_code);
            if (refresh_token.length()==0) {
                log_d("Error getting refresh token");
                //error
            };
            settings.putString("ha_refresh", refresh_token);
            // ESP.restart();
        };
    };

    server.send(200, "text/plain", "Success"); });
    server.begin();
};
bool initialized = false;
bool initialized_ha = false;
void setup()
{
    Serial.begin(115200);
    sleep(2);
    setupPreferences();
    xTaskCreatePinnedToCore(
        setupWifi,   /* Function to implement the task */
        "setupWifi", /* Name of the task */
        10000,       /* Stack size in words */
        NULL,        /* Task input parameter */
        0,           /* Priority of the task */
        NULL,        /* Task handle. */
        0);          /* Core where the task should run */
    improvSerial.onImprovConnected(*storeImprovSettings);
    improvSerial.setDeviceInfo(ImprovTypes::ChipFamily::CF_ESP32_S3, "CircleHome", "1.0.0", "My Device");
    ha->setHost(settings.getString("ha_hostname", "homeasssistant.local"));
    ha->setPort(settings.getInt("ha_port", 8123));
    Serial.setDebugOutput(true);
    m5dial_lvgl_init();
    M5Dial.Display.setBrightness(70);
    screen_loading.initialize();
    screen_loading.makeActive();
    m5dial_lvgl_next();
    ui_init();
    setupTime();
    setup_web_server();
}

void loop()
{
    improvSerial.handleSerial();
    m5dial_lvgl_next();
    server.handleClient();
    monitor_sleep();
    
    if (initialized)
    {
        clock_timer.update();
        // log_d("HA is setup? %d %s", ha->isSetup(), settings.getString("ha_refresh", "none"));
        if (ha->isSetup() and not initialized_ha)
        {
            log_d("Initializing HA");   
            ha->createEntities();
            ha->updateAllStates();
            initialized_ha = true;
        };
    }
    else
    {
        if (improvSerial.isConnected())
        {
            log_d("Connected, continue");
            ha->setRefreshToken(settings.getString("ha_refresh", ""));
            log_d("access token: '%s'", ha->getToken().c_str());
            initializeScreens();
            screen_main_menu.makeActive();
            initialized = true;
        }
    };
}
