#include "Screen_Timer.h"

void Screen_Timer::updateScreenState()
{
    switch (clock_timer.getState())
    {
    case Cleared:
        screen_timer_set.makeActive();
        break;
    case Active:
        screen_timer_countdown.makeActive();
        break;
    case Alert:
        screen_timer_alert.makeActive();
        break;
    }
};