#include "Screen_On_Off.h"
void Screen_On_Off::arc_handler(lv_timer_t *timer)
{
    Screen_On_Off *screen = (Screen_On_Off *)timer->user_data;
    int arc_value = lv_arc_get_value(screen->arc);
    log_d("arc value %d", arc_value);
    if (screen->arc_last_pos == arc_value)
        return;
    screen->arc_last_pos = arc_value;
    int brightness = (arc_value * 255) / 50;
    log_d("set brightness on arc to %d", brightness);
    if (ha->getActiveEntity() == nullptr)
        return;
    dynamic_cast<Light *>(ha->getActiveEntity())->setBrightness(ha, brightness);
}
void Screen_On_Off::button_handler(lv_event_t *event)
{
    Screen_On_Off *screen = (Screen_On_Off *)event->user_data;
    ha->getActiveEntity()
        ->toggle(ha);
}
Screen_On_Off screen_on_off;