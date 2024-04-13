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
void setupWifi()
{
    Serial.println("Connecting to Wifi...");
    if (!settings.isKey("wifi_ssid") || !settings.isKey("wifi_password"))
    {
        error_wifi_not_defined.issue();
        return;
    }
    WiFi.begin(settings.getString("wifi_ssid"), settings.getString("wifi_password"));
    int wifi_time = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        if (wifi_time > WIFI_TIMEOUT)
        {
            error_no_wifi.issue();
            return;
        }
        delay(500);
        wifi_time += 500;
    }
    Serial.println("Connected to Wifi");
}

void setup()
{
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    // lv_log_register_print_cb(log_cb);
    m5dial_lvgl_init();
    setupPreferences();
    M5Dial.Display.setBrightness(70);
    screen_loading.initialize();
    screen_loading.makeActive();
    m5dial_lvgl_next();
    ui_init();
    if (settings.getBool("initialized"))
    {
        setupWifi();
        ha = new HomeAssistant(
            settings.getString("ha_hostname"),
            settings.getString("ha_token"),
            settings.getInt("ha_port"));
        setupTime();
        initializeScreens();
        ha->createEntities();
        ha->updateAllStates();

        screen_timer_set.makeActive();
    };
}

void loop()
{
    m5dial_lvgl_next();
    if (aero_web_server_enabled)
        server.handleClient();
    // monitor_sleep();
    clock_timer.update();
}
