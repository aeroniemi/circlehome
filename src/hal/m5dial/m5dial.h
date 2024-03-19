#pragma once
#include <TFT_eSPI.h>
#include "../ui/ui.h"
#define DRAW_BUF_SIZE (DISP_HOR_RES * DISP_VER_RES / 10 * (LV_COLOR_DEPTH / 8))
extern uint32_t draw_buf[DRAW_BUF_SIZE / 4];

void hal_init();
void hal_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);
void hal_touch_read(lv_indev_t * indev, lv_indev_data_t * data);
void hal_encoder_read(lv_indev_t * indev, lv_indev_data_t * data);