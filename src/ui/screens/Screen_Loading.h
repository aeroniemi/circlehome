#pragma once
#ifndef SCREEN_LOADING
#define SCREEN_LOADING
#include <lvgl.h>
#include "Screen.h"
#include <ha_api.h>

class Screen_Loading : public Screen
{
    lv_obj_t *text;
    void create()
    {
        text = lv_label_create(_lv_screen);
        lv_obj_center(text);
        lv_label_set_text(text, "Loading...");
        lv_obj_set_style_text_font(text, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(text, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    };
};
extern Screen_Loading screen_loading;
#endif
