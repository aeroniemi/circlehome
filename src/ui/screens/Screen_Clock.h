#pragma once
#ifndef SCREEN_CLOCK
#define SCREEN_CLOCK
#include <lvgl.h>
#include "Screen.h"
#include <M5Dial.h>
class Screen_Clock : public Screen
{

    lv_obj_t *clock_text;
    lv_obj_t *date_text;
    inline void create()
    {
        log_d("Creating screen_clock");
        clock_text = lv_label_create(_lv_screen);
        lv_obj_center(clock_text);
        lv_label_set_text(clock_text, "18:22:00");
        lv_obj_set_style_text_font(clock_text, &noto_clock, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(clock_text, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_align(clock_text, LV_ALIGN_CENTER, 0, -15);

        date_text = lv_label_create(_lv_screen);
        lv_obj_center(date_text);
        lv_label_set_text(date_text, "Mon 23 Mar");
        lv_obj_set_style_text_font(date_text, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(date_text, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_align(date_text, LV_ALIGN_CENTER, 0, 25);
        addTimer(update_time, 1000);
    }
    static void update_time(lv_timer_t *timer);
};
extern Screen_Clock screen_clock;

#endif
