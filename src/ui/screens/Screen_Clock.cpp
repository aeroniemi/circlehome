#include "Screen_Clock.h"

static constexpr const char *const weekday[7] = {"Sun", "Mon", "Tue", "Wed",
                                                 "Thr", "Fri", "Sat"};
static constexpr const char *const month[12] = {"Jan", "Feb", "Mar", "Apr",
                                                "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
void Screen_Clock::update_time(lv_timer_t *timer)
{
    Screen_Clock *screen = (Screen_Clock *)timer->user_data;
    time_t utc = time(nullptr);
    tm * lt = localtime(&utc);
    lv_label_set_text_fmt(screen->clock_text, "%02d:%02d:%02d", lt->tm_hour, lt->tm_min, lt->tm_sec);
    lv_label_set_text_fmt(screen->date_text, "%s %d %s", weekday[lt->tm_wday], lt->tm_mday, month[lt->tm_mon]);
};

Screen_Clock screen_clock;
