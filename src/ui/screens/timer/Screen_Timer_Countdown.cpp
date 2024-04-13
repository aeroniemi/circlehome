#include "Screen_Timer.h"
void Screen_Timer_Countdown::create()
{
    _arc = lv_arc_create(_lv_screen);

    lv_arc_set_rotation(_arc, 270);
    lv_arc_set_bg_angles(_arc, 0, 360);
    lv_obj_remove_style(_arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
    lv_obj_remove_flag(_arc, LV_OBJ_FLAG_CLICKABLE); /*To not allow adjusting by click*/
    lv_obj_center(_arc);
    lv_obj_set_size(_arc, 240, 240);
    lv_obj_set_style_arc_width(_arc, 20, LV_PART_MAIN | LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(_arc, lv_palette_darken(LV_PALETTE_GREY, 200), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(_arc, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(_arc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *text = lv_label_create(_lv_screen);
    lv_obj_center(text);
    lv_label_set_text(text, "Countdown");
    lv_obj_set_style_text_font(text, &noto_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(text, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_timer_set_period(_updateTimer, 30);
}

void Screen_Timer_Countdown::update(lv_timer_t *timer)
{
    Screen_Timer::update(timer);
    lv_arc_set_range(_arc, 0, clock_timer.getTimerLength());
    lv_arc_set_value(_arc, clock_timer.getSecondsRemaining());
}
Screen_Timer_Countdown screen_timer_countdown;