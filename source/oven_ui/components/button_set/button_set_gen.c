/**
 * @file button_set_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "button_set_gen.h"
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

lv_obj_t * button_set_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_button_set;
    static lv_style_t style_button_click;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_button_set);
        lv_style_set_width(&style_button_set, 163);
        lv_style_set_height(&style_button_set, 50);
        lv_style_set_border_width(&style_button_set, 0);
        lv_style_set_radius(&style_button_set, 6);
        lv_style_set_text_font(&style_button_set, Roboto_Medium_30);
        lv_style_set_pad_all(&style_button_set, 0);
        lv_style_set_shadow_width(&style_button_set, 62);
        lv_style_set_shadow_spread(&style_button_set, 62);
        lv_style_set_shadow_color(&style_button_set, lv_color_hex(0xEEB111));

        lv_style_init(&style_button_click);
        lv_style_set_bg_color(&style_button_click, lv_color_hex(0xf6cb5f));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "button_set_#");

    lv_obj_add_style(lv_obj_0, &style_button_set, 0);
    lv_obj_add_style(lv_obj_0, &style_button_click, LV_STATE_PRESSED);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_0, "Set");
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

