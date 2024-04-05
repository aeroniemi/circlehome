#pragma once
#ifndef SCREEN_MAIN_MENU
#define SCREEN_MAIN_MENU
#include <lvgl.h>
#include "Screen.h"

class Screen_Main_Menu : public Screen
{
    void create();
};
extern Screen_Main_Menu screen_main_menu;
#endif
