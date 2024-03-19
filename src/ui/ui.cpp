#include <Arduino.h>
#include "ui.h"

uint32_t get_milliseconds() {
     return millis();
}

void ui_init() {
    lv_init();
    lv_tick_set_cb(get_milliseconds);

    screen_clock_init();
};
void ui_update() {
    lv_task_handler();
}