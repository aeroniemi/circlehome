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
    lv_obj_set_style_arc_width(_arc, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(_arc, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // lv_obj_set_style_arc_color(_arc, lv_palette_darken(LV_PALETTE_BLUE, 0), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_arc_rounded(_arc, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    // lv_obj_set_style_arc_color(_arc, lv_palette_darken(LV_PALETTE_GREY, 0), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    // lv_obj_set_style_arc_rounded(_arc, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // lv_obj_set_style_arc_opa(_arc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_arc_opa(_arc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(_arc, lv_color_hex(0x111144), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(_arc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(_arc, false, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(_arc, lv_color_hex(0x4040FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(_arc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(_arc, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    _text = lv_label_create(_lv_screen);
    lv_obj_align(_text, LV_ALIGN_CENTER, 0, -20);
    lv_label_set_text(_text, "");
    lv_obj_set_style_text_font(_text, &noto_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(_text, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_timer_set_period(_updateTimer, 30);

    lv_obj_t *cancel = lv_button_create(_lv_screen);
    lv_obj_align(cancel, LV_ALIGN_CENTER, 0, 60);
    lv_obj_t *label = lv_label_create(cancel);
    lv_label_set_text(label, "Cancel");
    lv_obj_set_style_text_font(label, &noto_26, LV_PART_MAIN);
    lv_obj_center(label);
    lv_obj_add_event_cb(cancel, cancel_handler, LV_EVENT_SHORT_CLICKED, this);
}

void Screen_Timer_Countdown::cancel_handler(lv_event_t *event) {
    clock_timer.clear();
}
void Screen_Timer_Countdown::update(lv_timer_t *timer)
{
    Screen_Timer::update(timer);
    lv_arc_set_range(_arc, 0, clock_timer.getTimerLength());
    lv_arc_set_value(_arc, clock_timer.getSecondsRemaining());
    lv_label_set_text(_text, clock_timer.getTimeRemainingFormatted().c_str());
}
Screen_Timer_Countdown screen_timer_countdown;