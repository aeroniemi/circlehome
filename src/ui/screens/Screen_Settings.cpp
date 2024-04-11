#include <aero_preferences.h>
#include <aero_web_portal.h>
#include "Screen_Settings.h"
void Screen_Settings::resetDevice(lv_event_t *event)
{
    resetPreferences();
    ESP.restart();
}
void Screen_Settings::configDevice(lv_event_t *event)
{
    aero_web_portal_setup();
}
void Screen_Settings::create() {
    lv_obj_t *reset_button = lv_button_create(_lv_screen);
    lv_group_remove_obj(reset_button);
    lv_obj_align(reset_button, LV_ALIGN_CENTER, 0, 60);
    lv_obj_t *reset_text = lv_label_create(reset_button);
    lv_label_set_text(reset_text, "Reset Device\nSettings");
    lv_obj_center(reset_text);
    lv_obj_add_event_cb(reset_button, resetDevice, LV_EVENT_PRESSED, NULL);

    lv_obj_t *config_button = lv_button_create(_lv_screen);
    lv_group_remove_obj(config_button);
    lv_obj_align(config_button, LV_ALIGN_CENTER, 0, -60);
    lv_obj_t *config_text = lv_label_create(config_button);
    lv_label_set_text(config_text, "Configuration\nMode");
    lv_obj_center(config_text);
    lv_obj_add_event_cb(config_button, configDevice, LV_EVENT_PRESSED, NULL);
}
Screen_Settings screen_settings;