#ifndef LV_CIRCLE_MENU_H
#define LV_CIRCLE_MENU_H

/*********************
 *      INCLUDES
 *********************/
#include <lvgl.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct
{
    int32_t num_items;
    int32_t active_item;
    lv_obj_t obj;
    int32_t rotation;
    lv_value_precise_t indic_angle_start;
    lv_value_precise_t indic_angle_end;
    lv_value_precise_t bg_angle_start;
    lv_value_precise_t bg_angle_end;
    int32_t value;     /*Current value of the arc*/
    int32_t min_value; /*Minimum value of the arc*/
    int32_t max_value; /*Maximum value of the arc*/
    uint32_t dragging : 1;
    uint32_t type : 2;
    uint32_t min_close : 1;        /*1: the last pressed angle was closer to minimum end*/
    uint32_t in_out : 1;           /* 1: The click was within the background arc angles. 0: Click outside */
    uint32_t chg_rate;             /*Drag angle rate of change of the arc (degrees/sec)*/
    uint32_t last_tick;            /*Last dragging event timestamp of the arc*/
    lv_value_precise_t last_angle; /*Last dragging angle of the arc*/
    int16_t knob_offset;           /*knob offset from the main arc*/
} lv_cmenu_t;

LV_ATTRIBUTE_EXTERN_DATA extern const lv_obj_class_t lv_arc_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create an arc object
 * @param parent    pointer to an object, it will be the parent of the new arc
 * @return          pointer to the created arc
 */
lv_obj_t *lv_cmenu_create(lv_obj_t *parent);

/*======================
 * Add/remove functions
 *=====================*/

/*=====================
 * Setter functions
 *====================*/
void lv_cmenu_set_active_item(lv_obj_t *obj, int32_t active_item);
void lv_cmenu_set_num_items(lv_obj_t *obj, int32_t num_items);
void lv_cmenu_set_change_rate(lv_obj_t *obj, uint32_t rate);

/*=====================
 * Getter functions
 *====================*/

int32_t lv_cmenu_get_active_item(const lv_obj_t *obj);
int32_t lv_cmenu_get_num_items(const lv_obj_t *obj);
int32_t lv_cmenu_get_change_rate(const lv_obj_t *obj);

/*=====================
 * Other functions
 *====================*/

/**
 * Align an object to the current position of the arc (knob)
 * @param obj           pointer to an arc object
 * @param obj_to_align  pointer to an object to align
 * @param r_offset      consider the radius larger with this value (< 0: for smaller radius)
 */
void lv_cmenu_align_obj_to_angle(const lv_obj_t *obj, lv_obj_t *obj_to_align, int32_t r_offset);

/**
 * Rotate an object to the current position of the arc (knob)
 * @param obj            pointer to an arc object
 * @param obj_to_rotate  pointer to an object to rotate
 * @param r_offset       consider the radius larger with this value (< 0: for smaller radius)
 */
void lv_cmenu_rotate_obj_to_angle(const lv_obj_t *obj, lv_obj_t *obj_to_rotate, int32_t r_offset);

/**********************
 *      MACROS
 **********************/

#endif /*LV_ARC_H*/
