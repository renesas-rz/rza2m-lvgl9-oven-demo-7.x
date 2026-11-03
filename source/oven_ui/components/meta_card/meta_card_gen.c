/**
 * @file meta_card_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "meta_card_gen.h"
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

lv_obj_t * meta_card_create(lv_obj_t * parent, const void * icon, const char * title, lv_subject_t * value)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_meta;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_meta);
        lv_style_set_width(&style_meta, 120);
        lv_style_set_height(&style_meta, 95);
        lv_style_set_bg_color(&style_meta, lv_color_hex(0x000000));
        lv_style_set_bg_opa(&style_meta, (255 * 32 / 100));
        lv_style_set_border_width(&style_meta, 1);
        lv_style_set_border_opa(&style_meta, (255 * 40 / 100));
        lv_style_set_border_color(&style_meta, lv_color_hex(0xeeb111));
        lv_style_set_radius(&style_meta, 16);
        lv_style_set_pad_all(&style_meta, 16);
        lv_style_set_layout(&style_meta, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_meta, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_main_place(&style_meta, LV_FLEX_ALIGN_SPACE_BETWEEN);
        lv_style_set_text_color(&style_meta, lv_color_hex(0xffffff));
        lv_style_set_text_font(&style_meta, Roboto_Bold_15);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "meta_card_#");
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_meta, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, icon);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_0, title);
    lv_obj_set_style_text_font(lv_label_0, Roboto_Regular_15, 0);
    lv_obj_set_style_pad_top(lv_label_0, 4, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_1, value, NULL);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

