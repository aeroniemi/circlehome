#ifndef SCREEN_MENU
#define SCREEN_MENU
#include <lvgl.h>
#include <ha_api.h>
static lv_obj_t *screen_menu;
static lv_obj_t *menu_text;
lv_obj_t *menu_roller;
inline void screen_menu_status_update_cb(lv_timer_t *timer)
{
    log_d("Getting entity");
    Entity *led_relay = ha->getEntityByIdentifier("switch.led_relay");
    log_d("Entity acquired");
    // char text[20];
    // led_relay->getState().toCharArray(text,20);
    // char status_string[4];
    lv_label_set_text(menu_text, led_relay->getState().c_str());
    // lv_label_set_text(menu_text, itoa(ha->sendGetRequest("/api/"), status_string, 10));
};
lv_group_t *screen_menu_group;
inline void screen_menu_init()
{
    
    // lv_obj_set_style_bg_color(screen_menu, lv_color_hex(0x094074), LV_PART_MAIN);
    // menu_text = lv_label_create(screen_menu);
    // lv_obj_center(menu_text);
    // lv_label_set_text(menu_text, "Setting up connection...");
    // lv_timer_t *timer = lv_timer_create(screen_menu_status_update_cb, 10000, menu_text);
    screen_menu_group = lv_group_create();
    lv_indev_set_group(indev_encoder_4th, screen_menu_group);
    screen_menu = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_menu, lv_color_hex(0x000000), LV_STATE_ANY);
    lv_obj_clear_flag(screen_menu, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    menu_roller = lv_roller_create(screen_menu);
    lv_group_add_obj(screen_menu_group, menu_roller);
    lv_group_set_editing(screen_menu_group, true);
    lv_roller_set_options(menu_roller, ha->getRollerString("switch").c_str(), LV_ROLLER_MODE_INFINITE);
    lv_obj_set_width(menu_roller, 240);
    lv_obj_set_height(menu_roller, 240);
    lv_obj_set_align(menu_roller, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(menu_roller, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(menu_roller, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(menu_roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(menu_roller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(menu_roller, lv_color_hex(0x4055A4), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(menu_roller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    // lv_obj_add_event_cb(menu_roller, ui_event_Roller2, LV_EVENT_ALL, NULL);
};
// LV_FONT_MONTSERRAT_30






#endif

