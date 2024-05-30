#include "Screen_Sleep.h"
#include <M5Unified.h>


void Screen_Sleep::load(lv_event_t *event)
{
    M5.Lcd.setBrightness(0);
};
void Screen_Sleep::unload(lv_event_t *event)
{
    M5.Lcd.setBrightness(255);
};
void Screen_Sleep::create() {
    lv_timer_create(monitorSleep, 100, this);
};
void Screen_Sleep::monitorSleep(lv_timer_t *timer) {
    Screen_Sleep *screen = (Screen_Sleep*)timer->user_data;
    if (screen->isActive())
    {
        if (lv_display_get_inactive_time(NULL) < 1000)
        {
            screen->makeLastActive();
        }
    }
    else
    {
        if (lv_display_get_inactive_time(NULL) > 10 * 1000)
        {
            screen->makeActive();
        }
    }
};
Screen_Sleep screen_sleep;