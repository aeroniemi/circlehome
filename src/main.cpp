#include <lvgl.h>
#include "M5Dial-LVGL.h"
#include <Arduino.h>
#include "ui/ui.h"
#include "sys/sleep_mgmt.h"
#include <ha_api.h>
#include "secrets.h"
#include "ui/screens/screen_loading.h"

HomeAssistant * ha;
void log_cb(lv_log_level_t level, const char * buf)
{
  Serial.println(buf);
}




void setup()
{
    Serial.begin(115200);
    Serial.setDebugOutput(true);

    // lv_log_register_print_cb(log_cb);
    m5dial_lvgl_init();
 
    M5Dial.Display.setBrightness(70);
    screen_loading_init();
    lv_screen_load(screen_loading);
    m5dial_lvgl_next();
    ha = new HomeAssistant(SECRET_WIFI_SSID, SECRET_WIFI_PASSWORD, SECRET_HA_HOSTNAME, SECRET_HA_PORT, SECRET_HA_TOKEN);
    ha->createEntities();
    ha->updateAllStates();
    ui_init();
}

void loop()
{
    m5dial_lvgl_next();
    // monitor_sleep();
}
