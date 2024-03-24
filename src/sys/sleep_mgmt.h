#include <lvgl.h>
#include <M5Unified.h>
bool isSleeping = false;

inline void enter_sleep()
{
    M5.Lcd.setBrightness(0);
    isSleeping = true;
}
inline void exit_sleep(){
    M5.Lcd.setBrightness(255);
    isSleeping = false;
}

inline void monitor_sleep(){
    if (isSleeping) {
        if (lv_display_get_inactive_time(NULL) < 1000)
        {
            exit_sleep();
        }
    } else {
        if (lv_display_get_inactive_time(NULL) > 10 * 1000)
        {
            enter_sleep();
        }
    }
    
}