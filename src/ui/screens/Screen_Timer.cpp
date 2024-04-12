#include "Screen_Timer.h"

void Screen_Timer::set_angle(void *obj, int32_t v)
{
    lv_arc_set_value((lv_obj_t*)obj, v);
}

void Screen_Timer::create()
{
    lv_obj_t *countdown_arc = lv_arc_create(_lv_screen);
    lv_arc_set_rotation(countdown_arc, 270);
    lv_arc_set_bg_angles(countdown_arc, 0, 360);
    lv_obj_remove_style(countdown_arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
    lv_obj_remove_flag(countdown_arc, LV_OBJ_FLAG_CLICKABLE); /*To not allow adjusting by click*/
    lv_obj_center(countdown_arc);
    lv_obj_set_size(countdown_arc, 240, 240);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, countdown_arc);
    lv_anim_set_exec_cb(&a, set_angle);
    lv_anim_set_duration(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); /*Just for the demo*/
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_start(&a);
}
Screen_Timer screen_timer;