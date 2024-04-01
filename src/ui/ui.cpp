#include <Arduino.h>
#include "M5Dial-LVGL.h"
#include <lvgl.h>
#include "ui.h"

static void return_to_menu_cb(lv_event_t *e) {
    screen_entity_menu.makeActive();
}

lv_group_t *default_group;
void ui_init()
{
    default_group = lv_group_create();
    lv_group_set_default(default_group);
    lv_indev_set_group(indev_encoder_4th, default_group);
    lv_indev_add_event_cb(indev_encoder_4th, return_to_menu_cb, LV_EVENT_LONG_PRESSED_REPEAT, NULL);
}
