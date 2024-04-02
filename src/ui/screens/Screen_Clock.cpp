#include "Screen_Clock.h"

void Screen_Clock::update_time(lv_timer_t * timer)
{
    Screen_Clock *screen = (Screen_Clock *)timer->user_data;
    auto dt = M5Dial.Rtc.getTime();
    lv_label_set_text_fmt(screen->clock_text, "%02d:%02d:%02d", dt.hours, dt.minutes, dt.seconds);
};

Screen_Clock screen_clock;
