#pragma once
#ifndef SCREEN_SLEEP
#define SCREEN_SLEEP
#include <lvgl.h>
#include "Screen.h"
class Screen_Sleep : public Screen
{
    void create();
    void load(lv_event_t *event);
    void unload(lv_event_t *event);
    static void monitorSleep(lv_timer_t *timer);
};
extern Screen_Sleep screen_sleep;

#endif
