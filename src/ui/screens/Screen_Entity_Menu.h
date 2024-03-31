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
        lv_roller_set_options(roller, ha->getRollerString("light").c_str(), LV_ROLLER_MODE_INFINITE);
        lv_obj_set_style_anim_duration(roller, 10, LV_PART_MAIN);
        lv_obj_set_width(roller, 240);
        lv_obj_set_height(roller, 240);
        lv_obj_set_align(roller, LV_ALIGN_CENTER);
        lv_obj_set_style_text_font(roller, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(roller, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_set_style_bg_color(roller, lv_color_hex(0x4055A4), LV_PART_SELECTED | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(roller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

        lv_obj_add_event_cb(roller, roller_handler, LV_EVENT_VALUE_CHANGED, NULL);
    }
    static void roller_handler(lv_event_t *event)
    {
        Screen_Entity_Menu *screen = (Screen_Entity_Menu *)event->user_data;
        char friendlyName[40];
        lv_roller_get_selected_str(screen->roller, friendlyName, 40);
        ha->setActiveEntity(ha->getEntityByFriendlyName(friendlyName));
        lv_screen_load(ha->getActiveEntity()->getEntityPage());
        // log_d("Active Entity: %s", ha->getActiveEntity()->getIdentifier().c_str());
        //     ha->getActiveEntity()->toggle(ha);
    }
};
extern Screen_Entity_Menu screen_entity_menu;
#endif
