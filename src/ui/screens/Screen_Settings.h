#pragma once
#ifndef SCREEN_SETTINGS
#define SCREEN_SETTINGS
#include <lvgl.h>
#include "Screen.h"
class Screen_Settings : public Screen
{
    void create();
    static void resetDevice(lv_event_t *event);
};
extern Screen_Settings screen_settings;

#endif
