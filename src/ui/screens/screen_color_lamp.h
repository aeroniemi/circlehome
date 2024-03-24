#ifndef SCREEN_COLOR_LAMP
#define SCREEN_COLOR_LAMP
#include <lvgl.h>
lv_obj_t *screen_color_lamp;
inline void screen_color_lamp_init()
{
    screen_color_lamp = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen_color_lamp, lv_color_hex(0x48A9A6), LV_PART_MAIN);
    lv_obj_t *clock_text = lv_label_create(screen_color_lamp);
    lv_obj_center(clock_text);
    lv_label_set_text(clock_text, "Colour");
}
#endif