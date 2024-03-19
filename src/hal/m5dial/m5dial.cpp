#ifdef M5STACK_DIAL
#include "m5dial.h"
uint32_t draw_buf[DRAW_BUF_SIZE / 4];
void hal_init()
{
    disp = lv_tft_espi_create(DISP_HOR_RES, DISP_VER_RES, draw_buf, sizeof(draw_buf));
}
void hal_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    lv_disp_flush_ready(disp);
}
void hal_touch_read(lv_indev_t *indev, lv_indev_data_t *data) {}
void hal_encoder_read(lv_indev_t *indev, lv_indev_data_t *data) {}

#endif