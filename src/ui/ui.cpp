#include <Arduino.h>
#include "M5Dial-LVGL.h"
#include <lvgl.h>
#include "ui.h"
#include "screens/screen_clock.h"
#include "screens/screen_color_lamp.h"
#include "screens/screen_dim_lamp.h"
#include "screens/screen_menu.h"

// void globalEventHandler(lv_event_t *e) {
//     M5.Lcd.setBrightness(50);
//     lv_screen_load(screen_menu);
// }
lv_group_t *default_group;
void ui_init()
{
    default_group = lv_group_create();
    lv_group_set_default(default_group);
    lv_indev_set_group(indev_encoder_4th, default_group);
    screen_clock_init();
    screen_dim_lamp_init();
    screen_color_lamp_init();
    screen_menu_init();
    lv_screen_load(screen_menu);
    // lv_indev_add_event_cb(indev_touchpad, globalEventHandler, LV_EVENT_LONG_PRESSED, NULL);
    // lv_indev_add_event_cb(indev_encoder, globalEventHandler, LV_EVENT_LONG_PRESSED, NULL);
}