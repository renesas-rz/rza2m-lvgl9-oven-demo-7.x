/**
 * @file performance_button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "performance_button_gen.h"
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

lv_obj_t * performance_button_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_checked;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, 78);
        lv_style_set_height(&style_main, 78);
        lv_style_set_bg_image_src(&style_main, perf_button_image);

        lv_style_init(&style_checked);
        lv_style_set_bg_image_src(&style_checked, close_button_image);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "performance_button_#");
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_CHECKABLE, true);
    lv_obj_bind_checked(lv_obj_0, &subject_show_perf_sidebar);

    lv_obj_remove_style_all(lv_obj_0);
    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_add_style(lv_obj_0, &style_checked, LV_STATE_CHECKED);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

