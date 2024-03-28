#ifndef SCREEN_LOADING
#define SCREEN_LOADING
#include <lvgl.h>
#include <ha_api.h>
lv_obj_t *screen_loading;
inline void screen_loading_init()
{
    screen_loading = lv_obj_create(NULL);
    lv_obj_t *loading = lv_label_create(screen_loading);
    lv_obj_center(loading);
    lv_label_set_text(loading, "Loading...");
    lv_obj_set_style_bg_color(screen_loading, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(loading, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(loading, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
};
#endif
