/**
 * @file lv_circle_menu.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_circle_menu.h"

/*********************
 *      DEFINES
 *********************/
#define MY_CLASS (&lv_circle_menu_class)
#define MY_CLASS_LABEL &lv_circle_menu_label_class
#define MY_CLASS_IMAGE &lv_circle_menu_image_class

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_circle_menu_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj);
static void lv_circle_menu_event(const lv_obj_class_t *class_p, lv_event_t *e);
static void lv_circle_menu_label_event(const lv_obj_class_t *class_p, lv_event_t *e);
static void lv_circle_menu_image_event(const lv_obj_class_t *class_p, lv_event_t *e);
static void draw_main(lv_event_t *e);
static void draw_label(lv_event_t *e);
static void draw_image(lv_event_t *e);
/**********************
 *  STATIC VARIABLES
 **********************/
const lv_obj_class_t lv_circle_menu_class = {
    .constructor_cb = lv_circle_menu_constructor,
    .width_def = LV_SIZE_CONTENT,
    .height_def = LV_SIZE_CONTENT,
    .group_def = LV_OBJ_CLASS_GROUP_DEF_TRUE,
    .instance_size = sizeof(lv_circle_menu_t),
    .base_class = &lv_obj_class,
    .name = "circle-menu",
};

const lv_obj_class_t lv_circle_menu_label_class = {
    .event_cb = lv_circle_menu_label_event,
    .instance_size = sizeof(lv_label_t),
    .base_class = &lv_label_class,
    .name = "circle-menu-label",
};

const lv_obj_class_t lv_circle_menu_image_class = {
    .event_cb = lv_circle_menu_image_event,
    .instance_size = sizeof(lv_image_t),
    .base_class = &lv_image_class,
    .name = "circle-menu-image",
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t *lv_circle_menu_create(lv_obj_t *parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t *obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}

/*=====================
 * Setter functions
 *====================*/

void lv_circle_menu_set_options(lv_obj_t *obj, lv_circle_menu_option_t *options[])
{
    LV_ASSERT_OBJ(obj, MY_CLASS);
    LV_ASSERT_NULL(options);

    lv_circle_menu_t *circle_menu = (lv_circle_menu_t *)obj;
}

void lv_circle_menu_set_selected(lv_obj_t *obj, uint32_t sel_opt, lv_anim_enable_t anim)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    /*Set the value even if it's the same as the current value because
     *if moving to the next option with an animation which was just deleted in the PRESS Call the ancestor's event handler
     *nothing will continue the animation.*/

    lv_circle_menu_t *circle_menu = (lv_circle_menu_t *)obj;

    circle_menu->sel_opt_id = sel_opt < circle_menu->option_cnt ? sel_opt : circle_menu->option_cnt - 1;
    circle_menu->sel_opt_id_ori = circle_menu->sel_opt_id;

    refr_position(obj, anim);
}

/*=====================
 * Getter functions
 *====================*/

uint32_t lv_circle_menu_get_selected(const lv_obj_t *obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_circle_menu_t *circle_menu = (lv_circle_menu_t *)obj;
    return circle_menu->sel_opt_id;
}
/**
 * Get the options of a circle_menu
 * @param circle_menu pointer to circle_menu object
 * @return the options separated by '\n'-s (E.g. "Option1\nOption2\nOption3")
 */
const char *lv_circle_menu_get_options(const lv_obj_t *obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_circle_menu_t *circle_menu = (lv_circle_menu_t *)obj;
    return circle_menu->options;
}

uint32_t lv_circle_menu_get_option_count(const lv_obj_t *obj)
{
    LV_ASSERT_OBJ(obj, MY_CLASS);

    lv_circle_menu_t *circle_menu = (lv_circle_menu_t *)obj;
    return circle_menu->option_cnt;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void lv_circle_menu_constructor(const lv_obj_class_t *class_p, lv_obj_t *obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    lv_circle_menu_t *circle_menu = (lv_circle_menu_t *)obj;

    circle_menu->option_cnt = 0;
    circle_menu->sel_opt_id = 0;

    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);

    lv_obj_t *label = lv_obj_class_create_obj(&lv_circle_menu_label_class, obj);
    lv_obj_class_init_obj(label);

    lv_obj_t *image = lv_obj_class_create_obj(&lv_circle_menu_image_class, obj);
    lv_obj_class_init_obj(image);

    LV_TRACE_OBJ_CREATE("finished");
};
static void lv_circle_menu_event(const lv_obj_class_t *class_p, lv_event_t *e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /*Call the ancestor's event handler*/
    res = lv_obj_event_base(MY_CLASS, e);
    if (res != LV_RESULT_OK)
        return;

    const lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_current_target(e);
    lv_circle_menu_t *circle_menu = (lv_circle_menu_t *)obj;

    if (code == LV_EVENT_GET_SELF_SIZE)
    {
        lv_point_t *p = lv_event_get_param(e);
        p->x = get_selected_label_width(obj);
    }
    else if (code == LV_EVENT_STYLE_CHANGED)
    {
        lv_obj_t *label = get_label(obj);
        /*Be sure the label's style is updated before processing the circle_menu*/
        if (label)
            lv_obj_send_event(label, LV_EVENT_STYLE_CHANGED, NULL);
        lv_obj_refresh_self_size(obj);
        refr_position(obj, LV_ANIM_OFF);
    }
    else if (code == LV_EVENT_SIZE_CHANGED)
    {
        refr_position(obj, LV_ANIM_OFF);
    }
    else if (code == LV_EVENT_PRESSED)
    {
    }
    else if (code == LV_EVENT_PRESSING)
    {
    }
    else if (code == LV_EVENT_RELEASED || code == LV_EVENT_PRESS_LOST)
    {
    }
    else if (code == LV_EVENT_FOCUSED)
    {
        lv_group_t *g = lv_obj_get_group(obj);
        lv_indev_type_t indev_type = lv_indev_get_type(lv_indev_active());

        /*Encoders need special handling*/
        if (indev_type == LV_INDEV_TYPE_ENCODER)
        {
            const bool editing = lv_group_get_editing(g);

            /*Save the current state when entered to edit mode*/
            if (editing)
            {
                circle_menu->sel_opt_id_ori = circle_menu->sel_opt_id;
            }
            else
            { /*In navigate mode revert the original value*/
                if (circle_menu->sel_opt_id != circle_menu->sel_opt_id_ori)
                {
                    circle_menu->sel_opt_id = circle_menu->sel_opt_id_ori;
                    refr_position(obj, LV_ANIM_ON);
                }
            }
        }
        else
        {
            /*Save the current value. Used to revert this
             *state if ENTER won't be pressed*/
            circle_menu->sel_opt_id_ori = circle_menu->sel_opt_id;
        }
    }
    else if (code == LV_EVENT_DEFOCUSED)
    {
        /*Revert the original state*/
        if (circle_menu->sel_opt_id != circle_menu->sel_opt_id_ori)
        {
            circle_menu->sel_opt_id = circle_menu->sel_opt_id_ori;
            refr_position(obj, LV_ANIM_ON);
        }
    }
    else if (code == LV_EVENT_KEY)
    {
        uint32_t c = lv_event_get_key(e);
        if (c == LV_KEY_RIGHT || c == LV_KEY_DOWN)
        {
            if (circle_menu->sel_opt_id + 1 < circle_menu->option_cnt)
            {
                uint32_t ori_id = circle_menu->sel_opt_id_ori; /*lv_circle_menu_set_selected will overwrite this*/
                lv_circle_menu_set_selected(obj, circle_menu->sel_opt_id + 1, LV_ANIM_ON);
                circle_menu->sel_opt_id_ori = ori_id;
            }
        }
        else if (c == LV_KEY_LEFT || c == LV_KEY_UP)
        {
            if (circle_menu->sel_opt_id > 0)
            {
                uint32_t ori_id = circle_menu->sel_opt_id_ori; /*lv_circle_menu_set_selected will overwrite this*/
                lv_circle_menu_set_selected(obj, circle_menu->sel_opt_id - 1, LV_ANIM_ON);
                circle_menu->sel_opt_id_ori = ori_id;
            }
        }
    }
    else if (code == LV_EVENT_ROTARY)
    {
        int32_t r = lv_event_get_rotary_diff(e);
        int32_t new_id = circle_menu->sel_opt_id + r;
        new_id = LV_CLAMP(0, new_id, (int32_t)circle_menu->option_cnt - 1);
        if ((int32_t)circle_menu->sel_opt_id != new_id)
        {
            uint32_t ori_id = circle_menu->sel_opt_id_ori; /*lv_circle_menu_set_selected will overwrite this*/
            lv_circle_menu_set_selected(obj, new_id, LV_ANIM_ON);
            circle_menu->sel_opt_id_ori = ori_id;
        }
    }
    else if (code == LV_EVENT_REFR_EXT_DRAW_SIZE)
    {
        lv_obj_t *label = get_label(obj);
        lv_obj_refresh_ext_draw_size(label);
    }
    else if (code == LV_EVENT_DRAW_MAIN || code == LV_EVENT_DRAW_POST)
    {
        draw_main(e);
    }
};
static void lv_circle_menu_label_event(const lv_obj_class_t *class_p, lv_event_t *e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    lv_event_code_t code = lv_event_get_code(e);
    /*LV_EVENT_DRAW_MAIN will be called in the draw function*/
    if (code != LV_EVENT_DRAW_MAIN)
    {
        /* Call the ancestor's event handler */
        res = lv_obj_event_base(MY_CLASS_LABEL, e);
        if (res != LV_RESULT_OK)
            return;
    }

    lv_obj_t *label = lv_event_get_current_target(e);
    if (code == LV_EVENT_REFR_EXT_DRAW_SIZE)
    {
        /*If the selected text has a larger font it needs some extra space to draw it*/
        int32_t *s = lv_event_get_param(e);
        lv_obj_t *obj = lv_obj_get_parent(label);
        int32_t sel_w = get_selected_label_width(obj);
        int32_t label_w = lv_obj_get_width(label);
        *s = LV_MAX(*s, sel_w - label_w);
    }
    else if (code == LV_EVENT_SIZE_CHANGED)
    {
        refr_position(lv_obj_get_parent(label), LV_ANIM_OFF);
    }
    else if (code == LV_EVENT_DRAW_MAIN)
    {
        draw_label(e);
    }
}