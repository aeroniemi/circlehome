#include "Clock.h"
#include "../ui/screens/timer/Screen_Timer.h"

void Clock::alert(){
    _state = Alert;
    screen_timer_alert.makeActive();
    M5Dial.Speaker.tone(640, 2 * 60 * 1000, 1);
    M5Dial.Speaker.setVolume(255);
    M5Dial.Display.setBrightness(255);
    
};
Clock_Timer clock_timer;
Clock_Alarm clock_alarm;