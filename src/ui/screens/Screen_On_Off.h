
#ifndef _screen
#define _screen
#include <lvgl.h>
#include "Screen.h"
#include <ha_api.h>
LV_IMAGE_DECLARE(lightbulb_off);
LV_IMAGE_DECLARE(lightbulb_on);
class Screen_On_Off : public Screen
{
    lv_obj_t *arc;
    lv_obj_t *entity_name;
    lv_obj_t *button;
    uint8_t arc_last_pos;
    void create()
    {
        arc = lv_arc_create(_lv_screen);
        lv_obj_set_width(arc, 220);
        lv_obj_set_height(arc, 220);
        lv_obj_set_x(arc, 2);
        lv_obj_set_y(arc, 1);
        lv_obj_set_align(arc, LV_ALIGN_CENTER);
        lv_arc_set_value(arc, 50);
        lv_arc_set_range(arc, 1, 50);
        lv_obj_set_style_arc_width(arc, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_set_style_arc_color(arc, lv_color_hex(0xFFD640), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_set_style_arc_opa(arc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_set_style_arc_width(arc, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);

        // lv_obj_set_style_bg_color(arc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(arc, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
        lv_group_add_obj(_lv_group, arc);

        entity_name = lv_label_create(_lv_screen);
        lv_label_set_long_mode(entity_name, LV_LABEL_LONG_WRAP);
        lv_label_set_text(entity_name, "Panel");
        lv_obj_set_style_text_align(entity_name, LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_set_width(entity_name, 170);              /// 1
        lv_obj_set_height(entity_name, LV_SIZE_CONTENT); /// 1
        lv_obj_set_x(entity_name, 0);
        lv_obj_set_y(entity_name, -20);
        lv_obj_set_align(entity_name, LV_ALIGN_CENTER);

        lv_obj_clear_flag(entity_name, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE); /// Flags
        lv_obj_set_style_text_font(entity_name, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

        button = lv_imagebutton_create(_lv_screen);
        lv_imagebutton_set_src(button, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &lightbulb_off, NULL);
        lv_imagebutton_set_src(button, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &lightbulb_on, NULL);
        lv_obj_set_height(button, 70);
        lv_obj_set_width(button, LV_SIZE_CONTENT); /// 1
        lv_obj_set_x(button, 3);
        lv_obj_set_y(button, 63);
        lv_obj_set_align(button, LV_ALIGN_CENTER);
        lv_obj_add_event_cb(button, button_handler, LV_EVENT_PRESSED, this);
        addTimer(arc_handler, 300);
    }
    static void arc_handler(lv_timer_t *timer)
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
    static void button_handler(lv_event_t *event)
    {
        Screen_On_Off *screen = (Screen_On_Off *)event->user_data;
        ha->getActiveEntity()
            ->toggle(ha);
    }
};
extern Screen_On_Off screen_on_off;

#endif
