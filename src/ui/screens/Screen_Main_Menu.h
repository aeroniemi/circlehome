#pragma once
#ifndef SCREEN_MAIN_MENU
#define SCREEN_MAIN_MENU
#include <lvgl.h>
#include "Screen.h"
#include <Arduino.h>


class Screen_Main_Menu : public Screen
{
    void create();
    void _create_button(Menu_Option item, int i, int angle, int radius);
    static void button_handler(lv_event_t *event);
    static void button_draw_handler(lv_event_t *event);
};
extern Screen_Main_Menu screen_main_menu;
#endif
