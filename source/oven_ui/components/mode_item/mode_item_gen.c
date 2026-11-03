/**
 * @file mode_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "mode_item_gen.h"
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

lv_obj_t * mode_item_create(lv_obj_t * parent, const void * icon, const char * text)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_mode_item;
    static lv_style_t style_checked;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_mode_item);
        lv_style_set_width(&style_mode_item, 295);
        lv_style_set_height(&style_mode_item, 88);
        lv_style_set_pad_all(&style_mode_item, 31);
        lv_style_set_pad_top(&style_mode_item, 6);
        lv_style_set_pad_column(&style_mode_item, 19);
        lv_style_set_pad_bottom(&style_mode_item, 6);
        lv_style_set_bg_opa(&style_mode_item, 0);
        lv_style_set_text_color(&style_mode_item, lv_color_hex3(0xfff));
        lv_style_set_radius(&style_mode_item, 0);
        lv_style_set_border_width(&style_mode_item, 0);
        lv_style_set_text_font(&style_mode_item, Roboto_Medium_30);
        lv_style_set_layout(&style_mode_item, LV_LAYOUT_FLEX);
        lv_style_set_flex_cross_place(&style_mode_item, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_mode_item, LV_FLEX_ALIGN_CENTER);

        lv_style_init(&style_checked);
        lv_style_set_text_color(&style_checked, lv_color_hex3(0xfff));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "mode_item_#");

    lv_obj_add_style(lv_obj_0, &style_mode_item, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, icon);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_obj_set_flex_grow(lv_label_0, 1);
    lv_label_set_text(lv_label_0, text);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

