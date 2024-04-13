#include "Screen_Timer.h"
void Screen_Timer_Alert::set_bg_color(void *obj, int32_t v)
{
    lv_obj_set_style_bg_color((lv_obj_t *)obj, lv_palette_darken(LV_PALETTE_RED, v), LV_PART_MAIN | LV_STATE_DEFAULT);
    
};
void Screen_Timer_Alert::create()
{
    lv_obj_t *text = lv_label_create(_lv_screen);
    lv_obj_center(text);
    lv_label_set_text(text, "Alert");
    lv_obj_set_style_text_font(text, &noto_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(text, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, _lv_screen);
    lv_anim_set_exec_cb(&a, set_bg_color);
    lv_anim_set_duration(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); /*Just for the demo*/
    lv_anim_set_values(&a, 0, 255);
    lv_anim_start(&a);
}

void Screen_Timer_Alert::update(lv_timer_t *timer)
{
    Screen_Timer::update(timer);
}
Screen_Timer_Alert screen_timer_alert;