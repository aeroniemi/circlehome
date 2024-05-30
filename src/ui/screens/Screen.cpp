#include "Screen.h"
#include <Arduino.h>
void Screen::_load(lv_event_t *event)
{
    Screen *screen = (Screen *)event->user_data;
    for (uint8_t i = 0; i < SCREEN_MAX_TIMERS; i++)
    {

        if (screen->_timers[i] == nullptr)
            return;
        lv_timer_resume(screen->_timers[i]);
    }
    screen->load(event);
};
void Screen::_unload(lv_event_t *event)
{
    Screen *screen = (Screen *)event->user_data;
    for (uint8_t i = 0; i < SCREEN_MAX_TIMERS; i++)
    {

        if (screen->_timers[i] == nullptr)
            return;
        lv_timer_pause(screen->_timers[i]);
    }
    screen->load(event);
};
void Screen::_update(lv_timer_t *timer)
{
    Screen *screen = (Screen *)timer->user_data;
    screen->update(timer);
};
void Screen::initialize()
{
    _initialize();
    create();
};
size_t Screen::instanceCount;
Screen * Screen::instances[30];