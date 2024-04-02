#include "Screen.h"
#include <Arduino.h>
void Screen::_load(lv_event_t *event)
{
    for (uint8_t i = 0; i < SCREEN_MAX_TIMERS; i++)
    {
        Screen *screen = (Screen *)event->user_data;
        if (screen->_timers[i] == nullptr)
            return;
        lv_timer_resume(screen->_timers[i]);
    }
};
void Screen::_unload(lv_event_t *event)
{
    for (uint8_t i = 0; i < SCREEN_MAX_TIMERS; i++)
    {
        Screen *screen = (Screen *)event->user_data;
        if (screen->_timers[i] == nullptr)
            return;
        lv_timer_pause(screen->_timers[i]);
    }
};
void Screen::_update(lv_event_t *event){};
void Screen::initialize()
{
    Serial.println("init class");
    _initialize();
    create();
};