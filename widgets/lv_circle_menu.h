/**
 * @file lv_btn.h
 *
 */

#ifndef LV_CIRCLE_MENU_H
#define LV_CIRCLE_MENU_H

/*********************
 *      INCLUDES
 *********************/
#include <lvgl.h>
#include <Arduino.h>
#include "../ui/screens/Screen.h"

    /*********************
     *      DEFINES
     *********************/

    /**********************
     *      TYPEDEFS
     **********************/

    typedef struct
    {
        lv_obj_t obj;
        uint32_t option_cnt; /**< Number of options*/
        lv_circle_menu_option_t * options[option_cnt];
        uint32_t sel_opt_id; /**< Index of the current option*/
        uint32_t sel_opt_id_ori; /**< Store the original index on focus*/

    } lv_circle_menu_t;

    typedef struct
    {
        const char * text;
        const void *image_src;
        Screen *screen;
    } lv_circle_menu_option_t;
    LV_ATTRIBUTE_EXTERN_DATA extern const lv_obj_class_t lv_circle_menu_class;

    /**********************
     * GLOBAL PROTOTYPES
     **********************/

    /**
     * Create a circle_menu object
     * @param parent    pointer to an object, it will be the parent of the new circle_menu
     * @return          pointer to the created circle_menu
     */
    lv_obj_t *lv_circle_menu_create(lv_obj_t *parent);

    /*=====================
     * Setter functions
     *====================*/

    /**
     * Set the options on a circle_menu
     * @param obj       pointer to circle_menu object
     * @param options   array of options in the lv_circle_menu_option_t struct
     */
    void lv_circle_menu_set_options(lv_obj_t *obj, lv_circle_menu_option_t *options[]);

    /**
     * Set the selected option
     * @param obj       pointer to a circle_menu object
     * @param sel_opt   index of the selected option (0 ... number of option - 1);
     * @param anim   LV_ANIM_ON: set with animation; LV_ANOM_OFF set immediately
     */
    void lv_circle_menu_set_selected(lv_obj_t *obj, uint32_t sel_opt, lv_anim_enable_t anim);

    /*=====================
     * Getter functions
     *====================*/

    /**
     * Get the index of the selected option
     * @param obj       pointer to a circle_menu object
     * @return          index of the selected option (0 ... number of option - 1);
     */
    uint32_t lv_circle_menu_get_selected(const lv_obj_t *obj);
    
    /**********************
     *      MACROS
     **********************/

#endif /*LV_CIRCLE_MENU_H*/
