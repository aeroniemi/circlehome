#include <lvgl.h>
#include <M5Dial-LVGL.h>
#include <Arduino.h>
#include "ui/ui.h"
#include "sys/sleep_mgmt.h"
#include <ha_api.h>
#include "secrets.h"
// #include "ui/screens/sree.h"
#include "sys/aero_time.h"
#include <cppQueue.h>
#include "sys/error_handling.h"
HomeAssistant *ha;

Screen *global_screens[] = {
    &screen_on_off,
    &screen_loading,
    &screen_entity_menu,
    &screen_clock};
void log_cb(lv_log_level_t level, const char *buf)
{
    Serial.println(buf);
}
void initializeScreens()
{
    for (uint8_t i = 0; i < sizeof(global_screens)/sizeof(global_screens[0]) ; i++)
    {
        global_screens[i]->initialize();
    }
}
UIError error_wifi_not_defined(F("No Wifi credentials are set"));
UIError error_no_wifi(F("Credentials are set, but cannot connect to the WiFi network"));
void setupWifi() {
    Serial.println("Connecting to Wifi...");
    if (SECRET_WIFI_SSID == "" or SECRET_WIFI_PASSWORD == "") {
        error_wifi_not_defined.issue();
        return;
    }
    WiFi.begin(SECRET_WIFI_SSID, SECRET_WIFI_PASSWORD);
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
    M5Dial.Display.setBrightness(70);
    screen_loading.initialize();
    screen_loading.makeActive();
    m5dial_lvgl_next();
    setupWifi();
    ha = new HomeAssistant(SECRET_HA_HOSTNAME, SECRET_HA_PORT, SECRET_HA_TOKEN);
    setupTime();
    initializeScreens();
    ha->createEntities();
    ha->updateAllStates();
    ui_init();
    screen_clock.makeActive();
}

void loop()
{
    m5dial_lvgl_next();
    // monitor_sleep();
}
