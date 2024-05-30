#pragma once
#include <lvgl.h>
#include "screens/screens.h"

#ifndef VERSION
#define VERSION         STR_VALUE(BUILD_VERSION)
#endif
void ui_init();
extern void globalEventHandler(lv_event_t *e);

