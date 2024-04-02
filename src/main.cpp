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
    ha = new HomeAssistant(SECRET_WIFI_SSID, SECRET_WIFI_PASSWORD, SECRET_HA_HOSTNAME, SECRET_HA_PORT, SECRET_HA_TOKEN);
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
