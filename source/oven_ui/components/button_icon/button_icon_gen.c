/**
 * @file button_icon_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "button_icon_gen.h"
#include "oven_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * button_icon_create(lv_obj_t * parent, int32_t rotation)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_button_icon;
    static lv_style_t style_button_icon_pressed;
    static lv_style_t style_button_icon_disabled;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_button_icon);
        lv_style_set_width(&style_button_icon, LV_SIZE_CONTENT);
        lv_style_set_height(&style_button_icon, LV_SIZE_CONTENT);
        lv_style_set_bg_opa(&style_button_icon, 0);
        lv_style_set_border_width(&style_button_icon, 0);
        lv_style_set_pad_all(&style_button_icon, 9);

        lv_style_init(&style_button_icon_pressed);
        lv_style_set_bg_opa(&style_button_icon_pressed, 127);

        lv_style_init(&style_button_icon_disabled);
        lv_style_set_image_opa(&style_button_icon_disabled, 127);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "button_icon_#");
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_STATE_TRICKLE, true);

    lv_obj_add_style(lv_obj_0, &style_button_icon, 0);
    lv_obj_add_style(lv_obj_0, &style_button_icon_pressed, LV_STATE_PRESSED);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, arrow_icon);
    lv_image_set_rotation(lv_image_0, rotation);
    lv_obj_add_style(lv_image_0, &style_button_icon_disabled, LV_STATE_DISABLED);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

