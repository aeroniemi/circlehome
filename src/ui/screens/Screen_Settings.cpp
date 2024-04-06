#include <aero_preferences.h>
#include "Screen_Settings.h"
void Screen_Settings::resetDevice(lv_event_t *event)
{
    resetPreferences();
    ESP.restart();
}
void Screen_Settings::create() {
    lv_obj_t *button = lv_button_create(_lv_screen);
    lv_obj_center(button);
    lv_obj_t *text = lv_label_create(button);
    lv_label_set_text(text, "Reset Device\nSettings");
    lv_obj_center(text);
    lv_obj_add_event_cb(button, resetDevice, LV_EVENT_PRESSED, NULL);
}
Screen_Settings screen_settings;