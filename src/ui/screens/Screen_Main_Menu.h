#pragma once
#ifndef SCREEN_MAIN_MENU
#define SCREEN_MAIN_MENU
#include <lvgl.h>
#include "Screen.h"
#include <Arduino.h>
struct Menu_Option {
    String text;
    const void * image_src;
    Screen * screen;
    // Menu_Option(String text, void *image_src, Screen *screen) : text(text), image_src(image_src), screen(screen);
};

class Screen_Main_Menu : public Screen
{
    void create();
};
extern Screen_Main_Menu screen_main_menu;
#endif
