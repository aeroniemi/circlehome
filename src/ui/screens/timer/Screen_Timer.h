#pragma once
#ifndef SCREEN_TIMER
#define SCREEN_TIMER
#include <lvgl.h>
#include "../Screen.h"
#include "../../../classes/Clock.h"
class Screen_Timer : public Screen
{
public:
    void updateScreenState();
    void update(lv_timer_t *timer)
    {
        updateScreenState();
    }
};
class Screen_Timer_Alert : public Screen_Timer
{
public:
    static void set_bg_color(void *obj, int32_t v);
    void create();
    void update(lv_timer_t *timer) override;
};
class Screen_Timer_Countdown : public Screen_Timer
{
public:
    lv_obj_t *_arc;
    void create();
    void update(lv_timer_t *timer) override;
};
class Screen_Timer_Set : public Screen_Timer
{
public:
    void create();
    void update(lv_timer_t *timer) override;
};
extern Screen_Timer_Alert screen_timer_alert;
extern Screen_Timer_Countdown screen_timer_countdown;
extern Screen_Timer_Set screen_timer_set;

#endif
