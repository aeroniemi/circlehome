#ifndef SCREEN_H
#define SCREEN_H
#include <lvgl.h>
#define SCREEN_MAX_TIMERS 5
class Screen
{
protected:
    lv_timer_t *_timers[SCREEN_MAX_TIMERS];
    lv_obj_t *_lv_screen;
    lv_group_t *_lv_group;
    lv_timer_t *_updateTimer;
    inline void _initialize()
    {
        _lv_screen = lv_obj_create(NULL);
        _lv_group = lv_group_create();
        lv_obj_set_style_bg_color(_lv_screen, lv_color_black(), LV_PART_MAIN);
        lv_obj_add_event_cb(_lv_screen, _load, LV_EVENT_SCREEN_LOAD_START, this);
        lv_obj_add_event_cb(_lv_screen, _unload, LV_EVENT_SCREEN_UNLOAD_START, this);
        _updateTimer = addTimer(_update, 200);
        };
    static void _load(lv_event_t *event);
    static void _unload(lv_event_t *event);
    static void _update(lv_timer_t *timer);

public:
    Screen(){};
    virtual void makeActive() {
        if (lv_screen_active() != _lv_screen)
            lv_screen_load(_lv_screen);
    };
    virtual bool isActive() { return lv_screen_active() == _lv_screen; };
    void initialize();
    virtual void create() = 0;
    virtual void load(lv_event_t *event) {};
    virtual void unload(lv_event_t *event) {};
    virtual void update(lv_timer_t *timer){};
    // void setEncoderRatio(int encoderRatio);
    // int getEncoderRatio();
    inline lv_timer_t * addTimer(lv_timer_cb_t callback, uint32_t period)
    {
        for (uint8_t i = 0; i < SCREEN_MAX_TIMERS; i++)
        {
            if (_timers[i] == nullptr)
            {
                _timers[i] = lv_timer_create(callback, period, this);
                return _timers[i]; // added your timer successfully
            }
        }
        return nullptr; // no space for your timer
    };
    inline lv_obj_t * getLvScreen() {
        return _lv_screen;
    }
};


#endif