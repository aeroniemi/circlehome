#ifndef SCREEN_MENU
#define SCREEN_MENU
#include <lvgl.h>
#include <ha_api.h>
lv_obj_t *screen_menu;
lv_obj_t *menu_text;
lv_obj_t *menu_roller;
void roller_event_cb(lv_event_t *e)
{
    char friendlyName[40];
    lv_roller_get_selected_str(menu_roller, friendlyName, 40);
    ha->setActiveEntity(ha->getEntityByFriendlyName(friendlyName));
    lv_screen_load(ha->getActiveEntity()->getEntityPage());
    // log_d("Active Entity: %s", ha->getActiveEntity()->getIdentifier().c_str());
    //     ha->getActiveEntity()->toggle(ha);
}
lv_group_t *screen_menu_group;
inline void screen_menu_init()
{
    screen_menu_group = lv_group_create();
    lv_indev_set_group(indev_encoder_4th, screen_menu_group);
    screen_menu = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_menu, lv_color_hex(0x000000), LV_STATE_ANY);
    lv_obj_clear_flag(screen_menu, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    menu_roller = lv_roller_create(screen_menu);
    lv_group_add_obj(screen_menu_group, menu_roller);
    lv_group_set_editing(screen_menu_group, true);
    lv_roller_set_options(menu_roller, ha->getRollerString("light").c_str(), LV_ROLLER_MODE_INFINITE);
    lv_obj_set_style_anim_duration(menu_roller, 10, LV_PART_MAIN);
    lv_obj_set_width(menu_roller, 240);
    lv_obj_set_height(menu_roller, 240);
    lv_obj_set_align(menu_roller, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(menu_roller, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(menu_roller, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(menu_roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(menu_roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(menu_roller, lv_color_hex(0x4055A4), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(menu_roller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    // lv_obj_add_event_cb(menu_roller, roller_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
};
#endif

