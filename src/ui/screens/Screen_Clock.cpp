#include "Screen_Clock.h"

static constexpr const char *const weekday[7] = {"Sun", "Mon", "Tue", "Wed",
                                                 "Thr", "Fri", "Sat"};
static constexpr const char *const month[12] = {"Jan", "Feb", "Mar", "Apr",
                                                "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
void Screen_Clock::update_time(lv_timer_t *timer)
{
    Screen_Clock *screen = (Screen_Clock *)timer->user_data;
    auto dt = M5Dial.Rtc.getDateTime();
    lv_label_set_text_fmt(screen->clock_text, "%02d:%02d:%02d", dt.time.hours, dt.time.minutes, dt.time.seconds);
    lv_label_set_text_fmt(screen->date_text, "%s %d %s", weekday[dt.date.weekDay],dt.date.date, month[dt.date.month]);
};

Screen_Clock screen_clock;
