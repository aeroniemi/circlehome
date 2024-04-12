#pragma once
#ifndef SCREEN_TIMER
#define SCREEN_TIMER
#include <lvgl.h>
#include "Screen.h"
class Screen_Timer : public Screen
{
    lv_obj_t * countdown_arc;
    void create();
    static void set_angle(void *obj, int32_t v);
};
extern Screen_Timer screen_timer;

#endif
