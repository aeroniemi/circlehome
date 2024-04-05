#include "Screen_Main_Menu.h"
#include "screens.h"
Menu_Option main_menu_items[] = {
    {"Settings", NULL, &screen_main_menu},
    {"Clock", NULL, &screen_clock},
    {"Devices", NULL, &screen_entity_menu},
    {"Loading", NULL, &screen_loading},
};

void Screen_Main_Menu::create()
{
};
Screen_Main_Menu screen_main_menu;