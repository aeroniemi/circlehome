#ifndef CLASS_CLOCK
#define CLASS_CLOCK
#include <Arduino.h>
#include <time.h>
#include <M5Dial.h>
enum Clock_State
{
    Cleared,
    Active,
    Alert
};
class Clock
{
public:
    Clock(){};
    time_t expire_time;
    String name;
    Clock_State _state;
    bool isAlert()
    {
        return _state == Alert;
    }
    bool isCleared()
    {
        return _state == Cleared;
    }
    bool isActive()
    {
        return _state == Active;
    };
    void alert()
    {
        _state = Alert;
        M5Dial.Speaker.tone(640, 2 * 60 * 1000, 1);
        M5Dial.Speaker.setVolume(55);
    };
    Clock_State getState() {
        return _state;
    }
    void clear()
    {
        _state = Cleared;
        M5Dial.Speaker.stop(1);
    }
    virtual void update() = 0;
};
class Clock_Alarm : public Clock
{
public:
    bool setAlarm(String str_time);
    void update(){};
};

class Clock_Timer : public Clock
{
public:
    uint16_t length_ms;
    uint16_t getTimerLength()
    {
        return length_ms;
    }
    String getTimerLengthFormatted();
    void setTimer(String str_time = "12:34:56")
    {
        int hours = str_time.substring(0, 2).toInt();
        int minutes = str_time.substring(3, 5).toInt();
        int seconds = str_time.substring(6, 8).toInt();
        log_d("H %d M %d S %d", hours, minutes, seconds);
        length_ms = (hours * 60 * 60) + (minutes * 60) + seconds;
        time_t now = time(&now);
        expire_time = now + length_ms;
        _state = Active;
    }
    time_t getSecondsRemaining()
    {
        time_t now = time(&now);
        return expire_time - now;
    }
    void update()
    {
        if (isCleared())
            return;
        time_t current_time = time(&current_time);
        log_d("Now: %d Expire: %d Seconds: %d", current_time, expire_time, getSecondsRemaining());

        if (getSecondsRemaining() <= 0)
        {
            if (!isAlert())
                alert();
            if (getSecondsRemaining() < 0.5 * 60 * -1) // 2 minutes
                clear();
        }
    }
};
extern Clock_Timer clock_timer;
extern Clock_Alarm clock_alarm;
#endif