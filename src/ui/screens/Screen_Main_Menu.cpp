#include "Screen_Main_Menu.h"
#include "screens.h"
#include "../../widgets/lv_circle_menu.h"

lv_circle_menu_option_t main_menu_items[] = {
    {"Settings", NULL, &screen_main_menu},
    {"Clock", NULL, &screen_clock},
    {"Devices", NULL, &screen_entity_menu},
    {"Loading", NULL, &screen_loading},
    {"Timers", NULL, &screen_main_menu},
    {"Alarms", NULL, &screen_main_menu},
};

int angleToX(int angle, int radius)
{
    int x = radius * cos(radians(angle));
    return x;
}
int angleToY(int angle, int radius)
{
    int y = radius * sin(radians(angle));
    return y;
}
void Screen_Main_Menu::create()
{
    // int num_items = sizeof(main_menu_items) / sizeof(main_menu_items[0]);
    // int angle_per_item = 360 / num_items;
    lv_obj_t *circle_menu = lv_circle_menu_create(_lv_screen);
    lv_obj_set_size(circle_menu, 240, 240);
    lv_obj_center(circle_menu);
    lv_circle_menu_set_options(main_menu_items);
    // for (size_t i = 0; i < sizeof(main_menu_items) / sizeof(main_menu_items[0]); i++)
    // {
    //     _create_button(main_menu_items[i], i, angle_per_item, 75);
    // }
};
// void Screen_Main_Menu::_create_button(Menu_Option item, int i, int angle_per_item, int radius)
// {
//     int start_angle = angle_per_item * (i - 1);
//     int middle_angle = angle_per_item * (i - 1) + (angle_per_item / 2);
//     int end_angle = angle_per_item * i;
//     lv_obj_t *button = lv_button_create(_lv_screen);
//     lv_obj_align(button, LV_ALIGN_CENTER, angleToX(middle_angle, radius), angleToY(middle_angle, radius));
//     lv_obj_set_style_radius(button, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_size(button, 75, 75);
//     lv_obj_set_style_opa(button, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_t *text = lv_label_create(button);
//     lv_label_set_text(text, item.text.c_str());
//     lv_obj_center(text);
//     lv_obj_add_event_cb(button, button_handler, LV_EVENT_PRESSED, item.screen);
//     Menu_Button_Details details;
//     details.radius = radius;
//     details.startAngle = start_angle;
//     details.endAngle = end_angle;
//     details.width = radius - 20;
//     lv_obj_add_event_cb(button, button_draw_handler, LV_EVENT_DRAW_MAIN, &details);
//     // if (item.image_src != NULL) {
//     //     lv_obj_t *image = lv_image_create(button);
//     // }
// };
void Screen_Main_Menu::button_handler(lv_event_t *event)
{
    Screen *screen = (Screen *)event->user_data;
    screen->makeActive();
};
// void Screen_Main_Menu ::button_draw_handler(lv_event_t *event)
// {
//     lv_obj_t *obj = (lv_obj_t *)lv_event_get_current_target(event);
//     lv_layer_t *layer = lv_event_get_layer(event);
//     Menu_Button_Details *details = (Menu_Button_Details *)event->user_data;
//     lv_point_t center = {120, 120};
//     int32_t arc_r = 120;
//     // log_d("drawing the arc");
//     /*Draw the background arc*/
//     lv_draw_arc_dsc_t arc_dsc;
//     lv_draw_arc_dsc_init(&arc_dsc);
//     lv_obj_init_draw_arc_dsc(obj, LV_PART_MAIN, &arc_dsc);
//     arc_dsc.center = center;
//     arc_dsc.start_angle = details->startAngle;
//     arc_dsc.end_angle = details->endAngle;
//     arc_dsc.radius = details->radius;
//     arc_dsc.color = lv_color_hex(0xffffff);
//     arc_dsc.width = details->width;
//     lv_draw_arc(layer, &arc_dsc);
// }
Screen_Main_Menu screen_main_menu;