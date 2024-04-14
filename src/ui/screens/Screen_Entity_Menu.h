#ifndef SCREEN_MENU
#define SCREEN_MENU
#include <lvgl.h>
#include "Screen.h"
#include <ha_api.h>

class Screen_Entity_Menu : public Screen
{
    lv_obj_t *roller;
    lv_obj_t *clock_text;
    void create()
    {
        roller = lv_roller_create(_lv_screen);
        lv_group_add_obj(_lv_group, roller);
        lv_group_set_editing(_lv_group, true);
        lv_roller_set_options(roller, generateRollerString("light"), LV_ROLLER_MODE_INFINITE);
        lv_obj_set_style_anim_duration(roller, 10, LV_PART_MAIN);
        lv_obj_set_width(roller, 240);
        lv_obj_set_height(roller, 240);
        lv_obj_set_align(roller, LV_ALIGN_CENTER);
        lv_obj_set_style_text_font(roller, &noto_26, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(roller, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_set_style_bg_color(roller, lv_color_hex(0x4055A4), LV_PART_SELECTED | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(roller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

        lv_obj_add_event_cb(roller, roller_handler, LV_EVENT_VALUE_CHANGED, NULL);
    }
    static void roller_handler(lv_event_t *event);
    const char * generateRollerString(String domain) {
        String roller = "";
        log_d("Starting roller string");
        for (int i = 0; i < ha->getNumEntities(); i++)
        {
            if (ha->getEntityByIndex(i)->getDomain().equals(domain))
            {
                log_d("Found a device in the domain");
                roller.concat(ha->getEntityByIndex(i)->getFriendlyName());
                roller.concat("\n");
                log_d("%s", roller.c_str());
            }
        }
        roller.trim();
        if (roller.length() == 0)
        {
            roller = F("No Entities found");
        }
        return roller.c_str();
    }
};
extern Screen_Entity_Menu screen_entity_menu;
#endif
