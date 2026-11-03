/**
 * @file button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "button_gen.h"
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

lv_obj_t * button_create(lv_obj_t * parent, const char * text)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_button;
    static lv_style_t style_button_pressed;
    static lv_style_t style_button_checked;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_button);
        lv_style_set_width(&style_button, LV_SIZE_CONTENT);
        lv_style_set_height(&style_button, 75);
        lv_style_set_bg_color(&style_button, lv_color_hex(0xEEB111));
        lv_style_set_text_font(&style_button, Roboto_Medium_30);
        lv_style_set_pad_left(&style_button, 31);
        lv_style_set_pad_right(&style_button, 31);
        lv_style_set_radius(&style_button, 6);
        lv_style_set_border_width(&style_button, 0);

        lv_style_init(&style_button_pressed);
        lv_style_set_bg_opa(&style_button_pressed, 127);

        lv_style_init(&style_button_checked);
        lv_style_set_bg_color(&style_button_checked, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&style_button_checked, 0);
        lv_style_set_border_width(&style_button_checked, 2);
        lv_style_set_text_color(&style_button_checked, lv_color_hex3(0xfff));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "button_#");

    lv_obj_add_style(lv_obj_0, &style_button, 0);
    lv_obj_add_style(lv_obj_0, &style_button_pressed, LV_STATE_PRESSED);
    lv_obj_add_style(lv_obj_0, &style_button_checked, LV_STATE_CHECKED);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_label_set_text(lv_label_0, text);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

