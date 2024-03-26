#ifndef SCREEN_ON_OFF
#define SCREEN_ON_OFF
#include <lvgl.h>
#include <ha_api.h>
static lv_obj_t *screen_on_off;
static lv_obj_t *screen_on_off_arc;
static lv_obj_t *screen_on_off_entity_name;
lv_group_t *screen_on_off_group;
inline void screen_on_off_init()
{
    screen_on_off_group = lv_group_create();
    lv_indev_set_group(indev_encoder_4th, screen_on_off_group);
    screen_on_off = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_on_off, lv_color_hex(0x000000), LV_STATE_ANY);
    lv_obj_clear_flag(screen_on_off, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    screen_on_off = lv_obj_create(NULL);
    lv_obj_clear_flag(screen_on_off, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    screen_on_off_arc = lv_arc_create(screen_on_off);
    lv_obj_set_width(screen_on_off_arc, 220);
    lv_obj_set_height(screen_on_off_arc, 220);
    lv_obj_set_x(screen_on_off_arc, 2);
    lv_obj_set_y(screen_on_off_arc, 1);
    lv_obj_set_align(screen_on_off_arc, LV_ALIGN_CENTER);
    lv_arc_set_value(screen_on_off_arc, 50);
    lv_obj_set_style_arc_width(screen_on_off_arc, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(screen_on_off_arc, lv_color_hex(0xFFD640), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(screen_on_off_arc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(screen_on_off_arc, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(screen_on_off_arc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(screen_on_off_arc, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    screen_on_off_entity_name = lv_label_create(screen_on_off);
    lv_obj_set_width(screen_on_off_entity_name, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(screen_on_off_entity_name, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(screen_on_off_entity_name, 0);
    lv_obj_set_y(screen_on_off_entity_name, -20);
    lv_obj_set_align(screen_on_off_entity_name, LV_ALIGN_CENTER);
    lv_label_set_text(screen_on_off_entity_name, "Panel");
    lv_obj_clear_flag(screen_on_off_entity_name, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE); /// Flags
    lv_obj_set_style_text_font(screen_on_off_entity_name, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    screen_on_off_button = lv_imagebutton_create(screen_on_off);
    lv_imagebutton_set_src(screen_on_off_button, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &ui_img_lightbulb_off_png, NULL);
    lv_imagebutton_set_src(screen_on_off_button, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &ui_img_lightbulb_on_png, NULL);
    lv_obj_set_height(screen_on_off_button, 70);
    lv_obj_set_width(screen_on_off_button, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(screen_on_off_button, 3);
    lv_obj_set_y(screen_on_off_button, 63);
    lv_obj_set_align(screen_on_off_button, LV_ALIGN_CENTER);
};

#endif
