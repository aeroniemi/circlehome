#ifndef SCREEN_CLOCK
#define SCREEN_CLOCK
#include <lvgl.h>
lv_obj_t *screen_clock;
inline void screen_clock_init()
{
    screen_clock = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_clock, lv_color_hex(0x094074), LV_PART_MAIN);
    lv_obj_t *clock_text = lv_label_create(screen_clock);
    lv_obj_center(clock_text);
    lv_label_set_text(clock_text, "18:22:00");

    lv_group_t *engr = lv_group_create();
    lv_indev_set_group(indev_encoder, engr);
    lv_obj_t *label = lv_label_create(screen_clock);

    /*Create an Arc*/
    lv_obj_t *arc = lv_arc_create(screen_clock);
    lv_group_set_editing(engr, true);
    lv_group_add_obj(engr, arc);
    lv_obj_set_size(arc, 200, 200);
    lv_arc_set_rotation(arc, 135);
    lv_arc_set_bg_angles(arc, 0, 270);
    lv_arc_set_value(arc, 10);
    lv_obj_center(arc);
    // lv_obj_add_event_cb(screen_clock, screen_clock_update, LV_EVENT_ALL, nullptr);
}

#endif