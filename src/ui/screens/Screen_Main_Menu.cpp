#include "Screen_Main_Menu.h"
#include "screens.h"
Menu_Option main_menu_items[] = {
    {"Settings", NULL, &screen_settings},
    {"Clock", NULL, &screen_clock},
    {"Devices", NULL, &screen_entity_menu},
    {"Loading", NULL, &screen_loading},
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
    int num_items = sizeof(main_menu_items) / sizeof(main_menu_items[0]);
    int angle_per_item = 360 / num_items;

    for (size_t i = 0; i < sizeof(main_menu_items) / sizeof(main_menu_items[0]); i++)
    {
        _create_button(main_menu_items[i], i, (angle_per_item * (i)), 70);
    }
};
void Screen_Main_Menu::_create_button(Menu_Option item, int i, int angle, int radius)
{
    lv_obj_t *button = lv_button_create(_lv_screen);
    lv_obj_align(button, LV_ALIGN_CENTER, angleToX(angle, radius), angleToY(angle, radius));
    lv_obj_set_style_radius(button, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(button, 80, 80);
    lv_obj_t *text = lv_label_create(button);
    lv_label_set_text(text, item.text.c_str());
    lv_obj_center(text);
    lv_obj_add_event_cb(button, button_handler, LV_EVENT_PRESSED, item.screen);
};
void Screen_Main_Menu::button_handler(lv_event_t *event)
{
    Screen *screen = (Screen *)event->user_data;
    screen->makeActive();
};
Screen_Main_Menu screen_main_menu;