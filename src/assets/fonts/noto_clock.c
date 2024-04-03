/*******************************************************************************
 * Size: 52 px
 * Bpp: 4
 * Opts: --bpp 4 --size 52 --no-compress --font NotoSans-SemiBold-monospaced.ttf --symbols 0123456789:.- --format lvgl -o noto_clock.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef NOTO_CLOCK
#define NOTO_CLOCK 1
#endif

#if NOTO_CLOCK

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002D "-" */
    0x29, 0x99, 0x99, 0x99, 0x99, 0x99, 0x98, 0x3f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff,

    /* U+002E "." */
    0x0, 0x37, 0x86, 0x0, 0x0, 0xaf, 0xff, 0xfe,
    0x40, 0x5f, 0xff, 0xff, 0xfe, 0xa, 0xff, 0xff,
    0xff, 0xf2, 0xbf, 0xff, 0xff, 0xff, 0x39, 0xff,
    0xff, 0xff, 0xf2, 0x5f, 0xff, 0xff, 0xfd, 0x0,
    0x8f, 0xff, 0xfd, 0x20, 0x0, 0x26, 0x74, 0x0,
    0x0,

    /* U+0030 "0" */
    0x0, 0x0, 0x0, 0x0, 0x1, 0x46, 0x77, 0x63,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x6, 0xdf, 0xff, 0xff, 0xff, 0xfa, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xdf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x4f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xb0, 0x0, 0x0, 0x0, 0x2, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x0,
    0x0, 0x0, 0xc, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x50, 0x0, 0x0, 0x5f,
    0xff, 0xff, 0xff, 0x82, 0x0, 0x3b, 0xff, 0xff,
    0xff, 0xe0, 0x0, 0x0, 0xdf, 0xff, 0xff, 0xf5,
    0x0, 0x0, 0x0, 0x9f, 0xff, 0xff, 0xf7, 0x0,
    0x3, 0xff, 0xff, 0xff, 0x90, 0x0, 0x0, 0x0,
    0xe, 0xff, 0xff, 0xfd, 0x0, 0x8, 0xff, 0xff,
    0xff, 0x10, 0x0, 0x0, 0x0, 0x6, 0xff, 0xff,
    0xff, 0x30, 0xc, 0xff, 0xff, 0xfb, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xff, 0xff, 0xff, 0x70, 0xf,
    0xff, 0xff, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xcf, 0xff, 0xff, 0xb0, 0x3f, 0xff, 0xff, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xff, 0xff,
    0xe0, 0x6f, 0xff, 0xff, 0xf1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6f, 0xff, 0xff, 0xf1, 0x8f, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4f,
    0xff, 0xff, 0xf3, 0x9f, 0xff, 0xff, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xff, 0xf5,
    0xbf, 0xff, 0xff, 0xd0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1f, 0xff, 0xff, 0xf6, 0xbf, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xff, 0xf7, 0xcf, 0xff, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xf8, 0xcf,
    0xff, 0xff, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xff, 0xf8, 0xcf, 0xff, 0xff, 0xb0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xf8, 0xcf, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xf8, 0xbf, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf8, 0xaf, 0xff, 0xff, 0xd0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xf7,
    0x9f, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xff, 0xf5, 0x7f, 0xff, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4f, 0xff,
    0xff, 0xf4, 0x5f, 0xff, 0xff, 0xf1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6f, 0xff, 0xff, 0xf2, 0x2f,
    0xff, 0xff, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x9f, 0xff, 0xff, 0xf0, 0xf, 0xff, 0xff, 0xf7,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xff, 0xff,
    0xc0, 0xb, 0xff, 0xff, 0xfb, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xff, 0xff, 0xff, 0x90, 0x7, 0xff,
    0xff, 0xff, 0x10, 0x0, 0x0, 0x0, 0x6, 0xff,
    0xff, 0xff, 0x40, 0x1, 0xff, 0xff, 0xff, 0x90,
    0x0, 0x0, 0x0, 0xd, 0xff, 0xff, 0xff, 0x0,
    0x0, 0xbf, 0xff, 0xff, 0xf4, 0x0, 0x0, 0x0,
    0x9f, 0xff, 0xff, 0xf9, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xff, 0x82, 0x0, 0x3b, 0xff, 0xff, 0xff,
    0xf2, 0x0, 0x0, 0x9, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x0, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x1d, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd1, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xbf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfa, 0x10, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x5, 0xcf, 0xff, 0xff, 0xff, 0xfb, 0x40,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x46, 0x77, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+0031 "1" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0xff, 0xff,
    0xf6, 0x0, 0x0, 0x0, 0x0, 0x1, 0xcf, 0xff,
    0xff, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x3e, 0xff,
    0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x5, 0xff,
    0xff, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x8f,
    0xff, 0xff, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x1b,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0x0, 0x2,
    0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0x0,
    0x4f, 0xff, 0xff, 0xff, 0xaf, 0xff, 0xff, 0xf6,
    0x7, 0xff, 0xff, 0xff, 0xfa, 0xf, 0xff, 0xff,
    0xf6, 0xd, 0xff, 0xff, 0xff, 0x80, 0xf, 0xff,
    0xff, 0xf6, 0x2, 0xff, 0xff, 0xf6, 0x0, 0xf,
    0xff, 0xff, 0xf6, 0x0, 0x5f, 0xfe, 0x30, 0x0,
    0x1f, 0xff, 0xff, 0xf6, 0x0, 0x9, 0xc1, 0x0,
    0x0, 0x1f, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0xff, 0xf6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xf6, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xff, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xff,
    0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff,
    0xff, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2f, 0xff, 0xff, 0xf6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2f, 0xff, 0xff, 0xf6, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xff, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xff,
    0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff,
    0xff, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2f, 0xff, 0xff, 0xf6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2f, 0xff, 0xff, 0xf6, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xff, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xff,
    0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff,
    0xff, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2f, 0xff, 0xff, 0xf6,

    /* U+0032 "2" */
    0x0, 0x0, 0x0, 0x0, 0x3, 0x56, 0x77, 0x64,
    0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x6c, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x30, 0x0, 0x0, 0x0,
    0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf5, 0x0, 0x0, 0x6, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40,
    0x0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe0, 0x0, 0xd, 0xff,
    0xff, 0xff, 0xe9, 0x53, 0x23, 0x6d, 0xff, 0xff,
    0xff, 0xf7, 0x0, 0x2, 0xff, 0xff, 0xe6, 0x0,
    0x0, 0x0, 0x0, 0xaf, 0xff, 0xff, 0xfd, 0x0,
    0x0, 0x4f, 0xfa, 0x10, 0x0, 0x0, 0x0, 0x0,
    0xd, 0xff, 0xff, 0xff, 0x10, 0x0, 0x7, 0x60,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xff,
    0xff, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x4, 0xff, 0xff, 0xff, 0x40, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4,
    0xff, 0xff, 0xff, 0x40, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x5, 0xff, 0xff, 0xff,
    0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x8, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xd, 0xff,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xcf, 0xff, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xff, 0xff,
    0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xff, 0xff, 0xff, 0x10, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xef, 0xff,
    0xff, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xd, 0xff, 0xff, 0xff, 0xa0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xa, 0xff, 0xff, 0xff, 0xd1,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x9f, 0xff, 0xff, 0xfe, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x9, 0xff, 0xff, 0xff,
    0xe2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x8f, 0xff, 0xff, 0xfe, 0x20, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xff,
    0xff, 0xe2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xff, 0xff, 0xfe, 0x20, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xff,
    0xff, 0xff, 0xe2, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6f, 0xff, 0xff, 0xfe, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5,
    0xff, 0xff, 0xff, 0xe2, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x5f, 0xff, 0xff, 0xfe,
    0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x4, 0xff, 0xff, 0xff, 0xe2, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x4f, 0xff, 0xff,
    0xff, 0xfe, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee,
    0xee, 0xe8, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xdf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf9, 0xdf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf9, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xdf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf9,

    /* U+0033 "3" */
    0x0, 0x0, 0x0, 0x0, 0x35, 0x67, 0x76, 0x53,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x71, 0x0,
    0x0, 0x0, 0x0, 0x18, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x60, 0x0, 0x0, 0x6,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfa, 0x0, 0x0, 0x6f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x90,
    0x0, 0xc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf4, 0x0, 0x2, 0xff,
    0xff, 0xfd, 0x63, 0x0, 0x1, 0x5b, 0xff, 0xff,
    0xff, 0xfb, 0x0, 0x0, 0x7f, 0xfb, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x8f, 0xff, 0xff, 0xff, 0x0,
    0x0, 0xa, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xc, 0xff, 0xff, 0xff, 0x30, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xff, 0xff,
    0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x4, 0xff, 0xff, 0xff, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4,
    0xff, 0xff, 0xff, 0x20, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6, 0xff, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xc, 0xff, 0xff, 0xf9, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 0xff,
    0xff, 0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6, 0xff, 0xff, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x48, 0xdf,
    0xff, 0xff, 0xfa, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfd, 0x81, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd7,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x91, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x60, 0x0, 0x0, 0x0,
    0x0, 0x44, 0x44, 0x56, 0x8a, 0xef, 0xff, 0xff,
    0xff, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x4, 0xcf, 0xff, 0xff, 0xff, 0x30,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xa, 0xff, 0xff, 0xff, 0xb0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff,
    0xff, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbf, 0xff, 0xff, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x9f, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xff, 0xff,
    0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xbf, 0xff, 0xff, 0xf5, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff,
    0xff, 0xff, 0xf3, 0x20, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x9, 0xff, 0xff, 0xff, 0xf0,
    0xbd, 0x61, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x8f, 0xff, 0xff, 0xff, 0x90, 0xbf, 0xff, 0xc7,
    0x52, 0x0, 0x0, 0x3, 0x7d, 0xff, 0xff, 0xff,
    0xff, 0x20, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xef,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0, 0xbf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xa0, 0x0, 0xbf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x0,
    0x0, 0x6e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfd, 0x40, 0x0, 0x0, 0x0, 0x49,
    0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe9, 0x40,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x25, 0x67,
    0x77, 0x75, 0x41, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xa, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xff,
    0xff, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xef, 0xff, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xaf, 0xff, 0xff, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x5f, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1e,
    0xff, 0xff, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5, 0xff, 0xff, 0xef, 0xff,
    0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xef, 0xff, 0xf6, 0xff, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xaf, 0xff, 0xfb, 0x4f, 0xff, 0xff, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 0xff,
    0xff, 0x25, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1e, 0xff, 0xff, 0x90,
    0x6f, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa, 0xff, 0xff, 0xe1, 0x6, 0xff,
    0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x5, 0xff, 0xff, 0xf4, 0x0, 0x7f, 0xff, 0xff,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xef,
    0xff, 0xfa, 0x0, 0x8, 0xff, 0xff, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0xff, 0xfe,
    0x10, 0x0, 0x8f, 0xff, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5f, 0xff, 0xff, 0x50, 0x0,
    0x8, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1e, 0xff, 0xff, 0xa0, 0x0, 0x0, 0x8f,
    0xff, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xff, 0xff, 0xe1, 0x0, 0x0, 0x8, 0xff, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x5, 0xff, 0xff,
    0xf5, 0x0, 0x0, 0x0, 0x8f, 0xff, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x1, 0xef, 0xff, 0xfa, 0x0,
    0x0, 0x0, 0x8, 0xff, 0xff, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0xbf, 0xff, 0xfe, 0x10, 0x0, 0x0,
    0x0, 0x8f, 0xff, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x5f, 0xff, 0xff, 0x50, 0x0, 0x0, 0x0, 0x8,
    0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x1e, 0xff,
    0xff, 0xa0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xff,
    0xff, 0xe0, 0x0, 0x0, 0xb, 0xff, 0xff, 0xf8,
    0x66, 0x66, 0x66, 0x66, 0x6b, 0xff, 0xff, 0xff,
    0x66, 0x66, 0x50, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfd, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd1,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xd1, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x8, 0xff, 0xff, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8f, 0xff, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x8, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f,
    0xff, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xff, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x8f, 0xff, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8, 0xff, 0xff, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x8f, 0xff, 0xff, 0xe0, 0x0, 0x0,

    /* U+0035 "5" */
    0x0, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x70, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x70, 0x0, 0x0, 0x4f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x70, 0x0, 0x0,
    0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x70, 0x0, 0x0, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x70,
    0x0, 0x0, 0x8f, 0xff, 0xff, 0xec, 0xcc, 0xcc,
    0xcc, 0xcc, 0xcc, 0xcc, 0x50, 0x0, 0x0, 0x9f,
    0xff, 0xff, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xaf, 0xff, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xbf, 0xff, 0xff, 0x60, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xff,
    0xff, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xef, 0xff, 0xff, 0x40, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xff, 0xff, 0x20, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff,
    0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xff,
    0xff, 0xfe, 0x3, 0x56, 0x77, 0x64, 0x10, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x71, 0x0, 0x0, 0x0,
    0x5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x60, 0x0, 0x0, 0x6, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa,
    0x0, 0x0, 0x7, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xa0, 0x0, 0x2,
    0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf6, 0x0, 0x0, 0x5, 0xb8, 0x53,
    0x10, 0x1, 0x25, 0xaf, 0xff, 0xff, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xcf, 0xff, 0xff, 0xff, 0x50, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0xff,
    0xff, 0xff, 0xa0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xff, 0xd0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xef, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xbf, 0xff, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xcf, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x5, 0xff, 0xff, 0xff, 0x90, 0x11, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1e, 0xff,
    0xff, 0xff, 0x40, 0x4f, 0x93, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xdf, 0xff, 0xff, 0xfd, 0x0,
    0x4f, 0xff, 0xea, 0x74, 0x21, 0x1, 0x26, 0xaf,
    0xff, 0xff, 0xff, 0xf5, 0x0, 0x4f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xb0, 0x0, 0x4f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x10, 0x0, 0x4f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xb1, 0x0, 0x0, 0x2c, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe6, 0x0, 0x0,
    0x0, 0x0, 0x38, 0xdf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xb5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x35, 0x67, 0x77, 0x65, 0x20, 0x0, 0x0,
    0x0, 0x0, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x45,
    0x77, 0x77, 0x64, 0x20, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x39, 0xef, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0xa, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x1, 0xdf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0xd, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xed, 0xde, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0xaf, 0xff, 0xff, 0xff, 0xe8, 0x30, 0x0, 0x0,
    0x1, 0x40, 0x0, 0x0, 0x6, 0xff, 0xff, 0xff,
    0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xe, 0xff, 0xff, 0xfe, 0x20, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff,
    0xff, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xef, 0xff, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4,
    0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x9, 0xff, 0xff, 0xf9,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xe, 0xff, 0xff, 0xf3, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4f, 0xff, 0xff, 0xc0, 0x0,
    0x17, 0xbe, 0xff, 0xeb, 0x72, 0x0, 0x0, 0x0,
    0x7f, 0xff, 0xff, 0x90, 0x8, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x91, 0x0, 0x0, 0x9f, 0xff, 0xff,
    0x70, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x20, 0x0, 0xbf, 0xff, 0xff, 0x6b, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0x0, 0xcf,
    0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0x0, 0xdf, 0xff, 0xff, 0xff,
    0xff, 0xc7, 0x43, 0x48, 0xef, 0xff, 0xff, 0xff,
    0x50, 0xef, 0xff, 0xff, 0xff, 0xf5, 0x0, 0x0,
    0x0, 0xb, 0xff, 0xff, 0xff, 0xc0, 0xef, 0xff,
    0xff, 0xff, 0x30, 0x0, 0x0, 0x0, 0x0, 0xdf,
    0xff, 0xff, 0xf1, 0xef, 0xff, 0xff, 0xf7, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x5f, 0xff, 0xff, 0xf5,
    0xdf, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xf8, 0xcf, 0xff, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xd, 0xff,
    0xff, 0xf9, 0xbf, 0xff, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xc, 0xff, 0xff, 0xfa, 0x8f,
    0xff, 0xff, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xd, 0xff, 0xff, 0xf9, 0x5f, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xe, 0xff, 0xff,
    0xf8, 0x2f, 0xff, 0xff, 0xf5, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0xff, 0xf6, 0xd, 0xff,
    0xff, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f,
    0xff, 0xff, 0xf3, 0x7, 0xff, 0xff, 0xff, 0x50,
    0x0, 0x0, 0x0, 0x0, 0xdf, 0xff, 0xff, 0xe0,
    0x1, 0xff, 0xff, 0xff, 0xf4, 0x0, 0x0, 0x0,
    0xa, 0xff, 0xff, 0xff, 0x90, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0x92, 0x0, 0x5, 0xdf, 0xff, 0xff,
    0xff, 0x20, 0x0, 0xc, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x2, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x2d, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x10,
    0x0, 0x0, 0x0, 0x1, 0xaf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xaf, 0xff, 0xff, 0xff, 0xfe, 0x92,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x36, 0x77, 0x75, 0x20, 0x0, 0x0, 0x0, 0x0,

    /* U+0037 "7" */
    0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe2, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x2f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x2f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xd1, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xcf, 0xff, 0xff,
    0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7, 0xff, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xef, 0xff, 0xff, 0x90, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xff, 0xff,
    0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xd, 0xff, 0xff, 0xfb, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4,
    0xff, 0xff, 0xff, 0x40, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xff, 0xff,
    0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2f, 0xff, 0xff, 0xf6, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8f, 0xff, 0xff, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe,
    0xff, 0xff, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6, 0xff, 0xff, 0xff,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xdf, 0xff, 0xff, 0xd0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f,
    0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xc, 0xff, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaf,
    0xff, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xff, 0xfa,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x8, 0xff, 0xff, 0xff, 0x30, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xff, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xe, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xff,
    0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xcf, 0xff, 0xff, 0xf1,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xff, 0xff, 0xfa, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xff,
    0xff, 0xff, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2, 0xff, 0xff, 0xff, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x9f, 0xff, 0xff, 0xf5, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff,
    0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7, 0xff, 0xff, 0xff, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xef, 0xff, 0xff, 0xf1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xff,
    0xff, 0xfa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+0038 "8" */
    0x0, 0x0, 0x0, 0x0, 0x2, 0x56, 0x77, 0x64,
    0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x39, 0xef, 0xff, 0xff, 0xff, 0xfd, 0x82, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1b, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x0,
    0x3, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfc, 0x10, 0x0, 0x0, 0x1e, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,
    0x0, 0x0, 0xbf, 0xff, 0xff, 0xff, 0xe9, 0x88,
    0xaf, 0xff, 0xff, 0xff, 0xf7, 0x0, 0x2, 0xff,
    0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x9f, 0xff,
    0xff, 0xfe, 0x0, 0x7, 0xff, 0xff, 0xff, 0x40,
    0x0, 0x0, 0x0, 0x9, 0xff, 0xff, 0xff, 0x20,
    0x9, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0xff, 0xff, 0x50, 0xa, 0xff, 0xff,
    0xf9, 0x0, 0x0, 0x0, 0x0, 0x0, 0xef, 0xff,
    0xff, 0x60, 0x9, 0xff, 0xff, 0xfa, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xef, 0xff, 0xff, 0x50, 0x7,
    0xff, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xff, 0xff, 0x30, 0x3, 0xff, 0xff, 0xff,
    0x30, 0x0, 0x0, 0x0, 0x7, 0xff, 0xff, 0xfe,
    0x0, 0x0, 0xef, 0xff, 0xff, 0xe1, 0x0, 0x0,
    0x0, 0x3f, 0xff, 0xff, 0xf8, 0x0, 0x0, 0x6f,
    0xff, 0xff, 0xfe, 0x40, 0x0, 0x5, 0xff, 0xff,
    0xff, 0xe0, 0x0, 0x0, 0xb, 0xff, 0xff, 0xff,
    0xfb, 0x22, 0xbf, 0xff, 0xff, 0xff, 0x30, 0x0,
    0x0, 0x0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xe3, 0x0, 0x0, 0x0, 0x0, 0xb,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x10,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x60, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x5e, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x91, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1c, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x50, 0x0,
    0x0, 0x0, 0x3, 0xef, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf9, 0x0, 0x0, 0x0, 0x3f,
    0xff, 0xff, 0xff, 0xd5, 0x7, 0xef, 0xff, 0xff,
    0xff, 0xb0, 0x0, 0x1, 0xef, 0xff, 0xff, 0xf8,
    0x0, 0x0, 0x9, 0xff, 0xff, 0xff, 0xfa, 0x0,
    0xa, 0xff, 0xff, 0xff, 0x50, 0x0, 0x0, 0x0,
    0x4e, 0xff, 0xff, 0xff, 0x50, 0x3f, 0xff, 0xff,
    0xf7, 0x0, 0x0, 0x0, 0x0, 0x2, 0xef, 0xff,
    0xff, 0xe0, 0x8f, 0xff, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5f, 0xff, 0xff, 0xf4, 0xcf,
    0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xd, 0xff, 0xff, 0xf8, 0xef, 0xff, 0xff, 0x60,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0xff, 0xff,
    0xf9, 0xef, 0xff, 0xff, 0x50, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x9, 0xff, 0xff, 0xfa, 0xdf, 0xff,
    0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xff, 0xf8, 0xbf, 0xff, 0xff, 0xd0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xff, 0xf5,
    0x7f, 0xff, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xcf, 0xff, 0xff, 0xf1, 0x1f, 0xff, 0xff,
    0xff, 0xa2, 0x0, 0x0, 0x0, 0x3d, 0xff, 0xff,
    0xff, 0xa0, 0x8, 0xff, 0xff, 0xff, 0xff, 0xda,
    0x99, 0xae, 0xff, 0xff, 0xff, 0xff, 0x20, 0x0,
    0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf5, 0x0, 0x0, 0x1c, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x50,
    0x0, 0x0, 0x0, 0x8f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xb2, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x7d, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xa3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0x57, 0x77, 0x65, 0x20, 0x0, 0x0, 0x0, 0x0,

    /* U+0039 "9" */
    0x0, 0x0, 0x0, 0x0, 0x3, 0x57, 0x77, 0x52,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3a, 0xff, 0xff, 0xff, 0xff, 0xd8, 0x10, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1b, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xa0, 0x0, 0x0, 0x0, 0x2e, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x0,
    0x0, 0x0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x70, 0x0, 0x6, 0xff,
    0xff, 0xff, 0xfc, 0x41, 0x1, 0x5c, 0xff, 0xff,
    0xff, 0xf2, 0x0, 0xd, 0xff, 0xff, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x8f, 0xff, 0xff, 0xfa, 0x0,
    0x3f, 0xff, 0xff, 0xfa, 0x0, 0x0, 0x0, 0x0,
    0xa, 0xff, 0xff, 0xff, 0x10, 0x7f, 0xff, 0xff,
    0xf2, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff,
    0xff, 0x70, 0xaf, 0xff, 0xff, 0xd0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xaf, 0xff, 0xff, 0xc0, 0xdf,
    0xff, 0xff, 0xa0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x5f, 0xff, 0xff, 0xf1, 0xef, 0xff, 0xff, 0x90,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xff,
    0xf4, 0xef, 0xff, 0xff, 0x80, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xf6, 0xef, 0xff,
    0xff, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xff, 0xf8, 0xcf, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xf9,
    0xaf, 0xff, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xaf, 0xff, 0xff, 0xfa, 0x7f, 0xff, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0x0, 0x5, 0xff, 0xff,
    0xff, 0xfa, 0x2f, 0xff, 0xff, 0xff, 0x40, 0x0,
    0x0, 0x0, 0x5f, 0xff, 0xff, 0xff, 0xf9, 0xc,
    0xff, 0xff, 0xff, 0xf9, 0x31, 0x2, 0x5b, 0xff,
    0xff, 0xff, 0xff, 0xf9, 0x3, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff,
    0xf8, 0x0, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x8a, 0xff, 0xff, 0xf6, 0x0, 0x9,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xb,
    0xff, 0xff, 0xf5, 0x0, 0x0, 0x6f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x90, 0xd, 0xff, 0xff, 0xf3,
    0x0, 0x0, 0x0, 0x7c, 0xff, 0xff, 0xfd, 0x92,
    0x0, 0xf, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0x21, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xff, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0xff, 0xff, 0x90, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xcf, 0xff, 0xff, 0x50, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xc, 0xff, 0xff, 0xfa, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xff,
    0xff, 0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6, 0xff, 0xff, 0xff, 0xb0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xaf,
    0xff, 0xff, 0xff, 0x20, 0x0, 0x0, 0x14, 0x0,
    0x0, 0x0, 0x14, 0x9f, 0xff, 0xff, 0xff, 0xf6,
    0x0, 0x0, 0x0, 0x3f, 0xfe, 0xdd, 0xdf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xa0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfa, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x70, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xa2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0x72, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0x56, 0x77, 0x76,
    0x53, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+003A ":" */
    0x0, 0x26, 0x74, 0x0, 0x0, 0x9f, 0xff, 0xfd,
    0x30, 0x5f, 0xff, 0xff, 0xfd, 0x9, 0xff, 0xff,
    0xff, 0xf2, 0xbf, 0xff, 0xff, 0xff, 0x3a, 0xff,
    0xff, 0xff, 0xf2, 0x6f, 0xff, 0xff, 0xfe, 0x0,
    0xbf, 0xff, 0xfe, 0x40, 0x0, 0x48, 0x97, 0x10,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0x78, 0x60, 0x0, 0xa, 0xff, 0xff, 0xe4, 0x5,
    0xff, 0xff, 0xff, 0xe0, 0xaf, 0xff, 0xff, 0xff,
    0x2b, 0xff, 0xff, 0xff, 0xf3, 0x9f, 0xff, 0xff,
    0xff, 0x25, 0xff, 0xff, 0xff, 0xd0, 0x8, 0xff,
    0xff, 0xd2, 0x0, 0x2, 0x67, 0x40, 0x0};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 268, .box_w = 14, .box_h = 6, .ofs_x = 1, .ofs_y = 11},
    {.bitmap_index = 42, .adv_w = 232, .box_w = 9, .box_h = 9, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 83, .adv_w = 476, .box_w = 26, .box_h = 40, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 603, .adv_w = 476, .box_w = 18, .box_h = 38, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 945, .adv_w = 476, .box_w = 26, .box_h = 39, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1452, .adv_w = 476, .box_w = 26, .box_h = 40, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 1972, .adv_w = 476, .box_w = 29, .box_h = 38, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2523, .adv_w = 476, .box_w = 26, .box_h = 39, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 3030, .adv_w = 476, .box_w = 26, .box_h = 40, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 3550, .adv_w = 476, .box_w = 27, .box_h = 38, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4063, .adv_w = 476, .box_w = 26, .box_h = 40, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 4583, .adv_w = 476, .box_w = 26, .box_h = 40, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 5103, .adv_w = 232, .box_w = 9, .box_h = 30, .ofs_x = 3, .ofs_y = -1}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 1, 0, 2, 3, 4, 5, 6,
    7, 8, 9, 10, 11, 12};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
    {
        {.range_start = 45, .range_length = 14, .glyph_id_start = 1, .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 14, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL}};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_48;

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t noto_clock = {
#else
lv_font_t noto_clock = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 40,                              /*The maximum line height required by the font*/
    .base_line = 1,                                 /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -5,
    .underline_thickness = 3,
#endif
    .dsc = &font_dsc, /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = &lv_font_montserrat_48,
    .user_data = NULL,
};

#endif /*#if NOTO_CLOCK*/
