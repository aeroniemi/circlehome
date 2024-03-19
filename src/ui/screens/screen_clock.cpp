
#include "../ui.h"
#include "screen_clock.h"
lv_obj_t *screen_clock;
lv_obj_t *clock_text;
void screen_clock_init()
{
    screen_clock = lv_obj_create(NULL);
    clock_text = lv_label_create(screen_clock);
    lv_label_set_text(clock_text, "18:22:00");
    lv_obj_set_style_text_font(clock_text, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
}
