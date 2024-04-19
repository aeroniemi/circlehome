#include "Screen_Timer.h"
void Screen_Timer_Set::create()
{
    // lv_obj_t* text = lv_label_create(_lv_screen);
    // lv_obj_center(text);
    // lv_label_set_text(text, "Set");
    // lv_obj_set_style_text_font(text, &noto_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_color(text, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    hoursRoller = create_time_roller(NULL, 24);
    minutesRoller = create_time_roller(NULL, 60, 1);
    secondsRoller = create_time_roller(NULL, 60, 15);
    lv_obj_align(hoursRoller, LV_ALIGN_CENTER, -60, -20);
    lv_obj_align(minutesRoller, LV_ALIGN_CENTER, 0, -20);
    lv_obj_align(secondsRoller, LV_ALIGN_CENTER, 60, -20);
    lv_obj_t *start = lv_btn_create(_lv_screen);
    lv_obj_align(start, LV_ALIGN_CENTER, 0, 80);
    lv_obj_t *label = lv_label_create(start);
    lv_label_set_text(label, "Start");
    lv_obj_set_style_text_font(label, &noto_26, LV_PART_MAIN);
    lv_obj_center(label);
    lv_obj_add_event_cb(start, start_handler, LV_EVENT_SHORT_CLICKED, this);
    // lv_obj_center(r);
    // lv_obj_center(r);
}
void Screen_Timer_Set::start_handler(lv_event_t *event)
{
    Screen_Timer_Set *screen = (Screen_Timer_Set *)event->user_data;
    char cHours[3];
    char cMinutes[3];
    char cSeconds[3];
    lv_roller_get_selected_str(screen->hoursRoller, cHours, 3);
    lv_roller_get_selected_str(screen->minutesRoller, cMinutes, 3);
    lv_roller_get_selected_str(screen->secondsRoller, cSeconds, 3);
    clock_timer.setTimer(cHours, cMinutes, cSeconds);
};
lv_obj_t *Screen_Timer_Set::create_time_roller(lv_event_cb_t *callback, int max, int interval)
{
    lv_obj_t *roller = lv_roller_create(_lv_screen);
    String text;
    text.reserve(((max + 1) * 2) / interval);
    for (int i = 0; i < max; i += interval)
    {
        if (i > 0)
            text.concat("\n");
        if (i < 10)
        {
            text.concat(0);
        }
        text.concat(i);
    }
    lv_roller_set_options(roller, text.c_str(), LV_ROLLER_MODE_NORMAL);
    lv_obj_set_style_text_font(roller, &noto_26, LV_PART_MAIN);
    return roller;
};

void Screen_Timer_Set::update(lv_timer_t *timer)
{
    Screen_Timer::update(timer);
}
Screen_Timer_Set screen_timer_set;