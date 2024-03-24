#pragma once
#include <lvgl.h>

extern lv_group_t *default_group;
void ui_init();
extern void globalEventHandler(lv_event_t *e);