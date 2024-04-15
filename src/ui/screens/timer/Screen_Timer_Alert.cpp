#include "Screen_Timer.h"
void Screen_Timer_Alert::set_bg_color(lv_timer_t *timer)
{
    Screen_Timer_Alert *screen = (Screen_Timer_Alert *)timer->user_data;
    lv_color_t color;

    if (screen->lit)
    {
        color = lv_color_black();
        screen->lit = false;
    }
    else
    {
        screen->lit = true;
        lv_palette_main(LV_PALETTE_RED);
    };
    lv_obj_set_style_bg_color(screen->_lv_screen, color, LV_PART_MAIN);
};
void Screen_Timer_Alert::clickHandler(lv_event_t *event){
    clock_timer.clear();
};
void Screen_Timer_Alert::create()
{
    lv_obj_t *text = lv_label_create(_lv_screen);
    lv_obj_center(text);
    lv_label_set_text(text, "Timer\nExpired");
    lv_obj_set_style_text_align(text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(text, &noto_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(text, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    addTimer(set_bg_color, 1000);
    lv_obj_add_event_cb(_lv_screen, clickHandler, LV_EVENT_PRESSED, this);
}

void Screen_Timer_Alert::update(lv_timer_t *timer)
{
    Screen_Timer::update(timer);
}
Screen_Timer_Alert screen_timer_alert;