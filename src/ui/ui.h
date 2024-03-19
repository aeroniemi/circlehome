
#include <lvgl.h>

#include "screens/screen_clock.h"
#pragma once
void ui_init();
void ui_update();

extern lv_display_t * disp;
extern lv_indev_t * touchscreen;
extern lv_indev_t * encoder;