#ifndef SCREEN_DIM_LAMP
#define SCREEN_DIM_LAMP
#include <lvgl.h>
lv_obj_t *screen_dim_lamp;
inline void screen_dim_lamp_init()
{
    screen_dim_lamp = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_dim_lamp, lv_color_hex(0xD4B483), LV_PART_MAIN);
    lv_obj_t *clock_text = lv_label_create(screen_dim_lamp);
    lv_obj_center(clock_text);
    lv_label_set_text(clock_text, "Dimming");
}
#endif