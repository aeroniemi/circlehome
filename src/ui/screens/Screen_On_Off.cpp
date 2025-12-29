#include "Screen_On_Off.h"
void Screen_On_Off::arc_handler(lv_timer_t *timer)
{
    Screen_On_Off *screen = (Screen_On_Off *)lv_timer_get_user_data(timer);
    int arc_value = lv_arc_get_value(screen->arc);
    log_d("arc value %d", arc_value);
    if (screen->arc_last_pos == arc_value)
        return;
    screen->arc_last_pos = arc_value;
    int brightness = (arc_value * 255) / 50;
    log_d("set brightness on arc to %d", brightness);
    if (ha->getActiveEntity() == nullptr)
        return;
    Light *light = (Light *)ha->getActiveEntity();
    light->setBrightness(brightness);
}
void Screen_On_Off::button_handler(lv_event_t *event)
{
    Screen_On_Off *screen = (Screen_On_Off *)lv_event_get_user_data(event);
    ha->getActiveEntity()
        ->toggle();
}
Screen_On_Off screen_on_off;