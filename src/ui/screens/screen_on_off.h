#ifndef SCREEN_ON_OFF
#define SCREEN_ON_OFF
#include <lvgl.h>
#include <ha_api.h>
lv_obj_t *screen_on_off;
lv_obj_t *screen_on_off_arc;
lv_obj_t *screen_on_off_entity_name;
lv_obj_t *screen_on_off_button;
lv_group_t *screen_on_off_group;
LV_IMAGE_DECLARE(lightbulb_off);
LV_IMAGE_DECLARE(lightbulb_on);

static void on_off_btn_handler(lv_event_t *e)
{
    ha->getActiveEntity()
        ->toggle(ha);
};
int on_off_arc_last_pos;
void on_off_arc_handler(lv_timer_t * timer)
{
    int arc_value = lv_arc_get_value(screen_on_off_arc);
    log_d("arc value %d", arc_value);
    if (on_off_arc_last_pos == arc_value)
        return;
    // ha->setActiveEntity(ha->getEntityByIdentifier("light.esphome_web_2a0cc0_main_leds"));
    on_off_arc_last_pos = arc_value;
    int brightness = (arc_value * 255) / 50;
    log_d("set brightness on arc to %d", brightness);
    if (ha->getActiveEntity() == nullptr)
        return;
    dynamic_cast<Light *>(ha->getActiveEntity())->setBrightness(ha, brightness);
};
static void on_off_load_cb(lv_event_t *e)
{
    lv_label_set_text(screen_on_off_entity_name, ha->getActiveEntity()->getFriendlyName().c_str());
}
inline void screen_on_off_init()
{
    screen_on_off_group = lv_group_create();
    lv_indev_set_group(indev_encoder, screen_on_off_group);
    screen_on_off = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_on_off, lv_color_black(), LV_STATE_ANY);

    screen_on_off_arc = lv_arc_create(screen_on_off);
    lv_obj_set_width(screen_on_off_arc, 220);
    lv_obj_set_height(screen_on_off_arc, 220);
    lv_obj_set_x(screen_on_off_arc, 2);
    lv_obj_set_y(screen_on_off_arc, 1);
    lv_obj_set_align(screen_on_off_arc, LV_ALIGN_CENTER);
    lv_arc_set_value(screen_on_off_arc, 50);
    lv_arc_set_range(screen_on_off_arc, 1, 50);
    lv_obj_set_style_arc_width(screen_on_off_arc, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(screen_on_off_arc, lv_color_hex(0xFFD640), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(screen_on_off_arc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(screen_on_off_arc, 20, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // lv_obj_set_style_bg_color(screen_on_off_arc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(screen_on_off_arc, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_group_add_obj(screen_on_off_group, screen_on_off_arc);

    screen_on_off_entity_name = lv_label_create(screen_on_off);
    lv_label_set_long_mode(screen_on_off_entity_name, LV_LABEL_LONG_WRAP);
    lv_label_set_text(screen_on_off_entity_name, "Panel");
    lv_obj_set_style_text_align(screen_on_off_entity_name, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_width(screen_on_off_entity_name, 170);              /// 1
    lv_obj_set_height(screen_on_off_entity_name, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(screen_on_off_entity_name, 0);
    lv_obj_set_y(screen_on_off_entity_name, -20);
    lv_obj_set_align(screen_on_off_entity_name, LV_ALIGN_CENTER);
   
    lv_obj_clear_flag(screen_on_off_entity_name, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE); /// Flags
    lv_obj_set_style_text_font(screen_on_off_entity_name, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    screen_on_off_button = lv_imagebutton_create(screen_on_off);
    lv_imagebutton_set_src(screen_on_off_button, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &lightbulb_off, NULL);
    lv_imagebutton_set_src(screen_on_off_button, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &lightbulb_on, NULL);
    lv_obj_set_height(screen_on_off_button, 70);
    lv_obj_set_width(screen_on_off_button, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(screen_on_off_button, 3);
    lv_obj_set_y(screen_on_off_button, 63);
    lv_obj_set_align(screen_on_off_button, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(screen_on_off_button, on_off_btn_handler, LV_EVENT_CLICKED, NULL);
    lv_timer_create(on_off_arc_handler, 500, NULL);
    // lv_obj_add_event_cb(screen_on_off_arc, on_off_arc_handler, LV_EVENT_VALUE_CHANGED, NULL);
    // lv_obj_add_event_cb(screen_on_off, on_off_load_cb, LV_EVENT_SCREEN_LOAD_START, NULL);
};

#endif
