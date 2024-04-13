#include "Screen_Timer.h"
void Screen_Timer_Set::create()
{
    clock_timer.setTimer("00:00:10");
    lv_obj_t* text = lv_label_create(_lv_screen);
    lv_obj_center(text);
    lv_label_set_text(text, "Set");
    lv_obj_set_style_text_font(text, &noto_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(text, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
}

void Screen_Timer_Set::update(lv_timer_t *timer)
{
    Screen_Timer::update(timer);
}
Screen_Timer_Set screen_timer_set;