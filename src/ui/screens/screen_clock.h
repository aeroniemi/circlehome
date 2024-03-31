#ifndef SCREEN_CLOCK
#define SCREEN_CLOCK
#include <lvgl.h>
#include <M5Dial.h>
lv_obj_t *screen_clock;
lv_obj_t *clock_text;
static lv_timer_t *clock_timer;
static void screen_clock_update_time(lv_timer_t *t)
{
    auto dt = M5Dial.Rtc.getTime();
    lv_label_set_text_fmt(clock_text, "%02d:%02d:%02d", dt.hours, dt.minutes, dt.seconds);
}
static void screen_clock_load(lv_event_t *e)
{
    lv_timer_resume(clock_timer);
};
static void screen_clock_unload(lv_event_t *e)
{
    lv_timer_pause(clock_timer);
};

inline void screen_clock_init()
{
    screen_clock = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_clock, lv_color_black(), LV_PART_MAIN);
    clock_text = lv_label_create(screen_clock);
    lv_obj_center(clock_text);
    lv_label_set_text(clock_text, "18:22:00");
    lv_obj_set_style_text_font(clock_text, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(clock_text, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    clock_timer = lv_timer_create(screen_clock_update_time, 1000, NULL);
    lv_timer_pause(clock_timer);
    lv_obj_add_event_cb(screen_clock, screen_clock_load, LV_EVENT_SCREEN_LOAD_START, NULL);
    lv_obj_add_event_cb(screen_clock, screen_clock_unload, LV_EVENT_SCREEN_UNLOAD_START, NULL);
}

#endif