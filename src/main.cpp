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
#include <aero_web_portal.h>
#include "classes/Clock.h"
#include <ImprovWiFiLibrary.h>

ImprovWiFi improvSerial(&Serial);
HomeAssistant *ha;

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
bool initialized = false;
void setup()
{
    Serial.begin(115200);
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
    Serial.setDebugOutput(true);
    m5dial_lvgl_init();
    M5Dial.Display.setBrightness(70);
    screen_loading.initialize();
    screen_loading.makeActive();
    m5dial_lvgl_next();
    ui_init();
    setupTime();
}

void loop()
{
    improvSerial.handleSerial();
    m5dial_lvgl_next();
    if (aero_web_server_enabled)
        server.handleClient();
    // monitor_sleep();
    if (initialized)
    {
        clock_timer.update();
    }
    else
    {
        if (improvSerial.isConnected())
        {
            log_d("Connected, continue");
            ha = new HomeAssistant(
                settings.getString("ha_hostname", "homeasssistant.local"),
                settings.getString("ha_token", ""),
                settings.getInt("ha_port", 8123));

            initializeScreens();
            ha->createEntities();
            ha->updateAllStates();
            screen_main_menu.makeActive();
            initialized = true;
        }
    };
}
