/**
 * @file recipe_card_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "recipe_card_gen.h"
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

lv_obj_t * recipe_card_create(lv_obj_t * parent, const char * title, const char * time, const void * bg_image)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_card;
    static lv_style_t style_cover;
    static lv_style_t style_cont;
    static lv_style_t style_text_cont;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_card);
        lv_style_set_width(&style_card, 234);
        lv_style_set_height(&style_card, 375);
        lv_style_set_radius(&style_card, 47);
        lv_style_set_border_width(&style_card, 0);
        lv_style_set_pad_all(&style_card, 0);
        lv_style_set_text_color(&style_card, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&style_card, 0);

        lv_style_init(&style_cover);
        lv_style_set_width(&style_cover, 234);
        lv_style_set_height(&style_cover, 375);
        lv_style_set_radius(&style_cover, 47);
        lv_style_set_bg_color(&style_cover, lv_color_hex(0x000000));
        lv_style_set_bg_opa(&style_cover, 0);
        lv_style_set_border_width(&style_cover, 0);
        lv_style_set_pad_top(&style_cover, 31);
        lv_style_set_pad_bottom(&style_cover, 31);
        lv_style_set_pad_left(&style_cover, 25);
        lv_style_set_pad_right(&style_cover, 25);
        lv_style_set_layout(&style_cover, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_cover, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_main_place(&style_cover, LV_FLEX_ALIGN_END);
        lv_style_set_text_color(&style_cover, lv_color_hex(0xffffff));

        lv_style_init(&style_cont);
        lv_style_set_width(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_height(&style_cont, 30);
        lv_style_set_pad_all(&style_cont, 0);
        lv_style_set_pad_column(&style_cont, 3);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_bg_opa(&style_cont, 0);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_flex_track_place(&style_cont, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_cont, LV_FLEX_ALIGN_CENTER);

        lv_style_init(&style_text_cont);
        lv_style_set_width(&style_text_cont, LV_SIZE_CONTENT);
        lv_style_set_height(&style_text_cont, lv_pct(100));
        lv_style_set_radius(&style_text_cont, 0);
        lv_style_set_border_width(&style_text_cont, 0);
        lv_style_set_pad_all(&style_text_cont, 0);
        lv_style_set_bg_opa(&style_text_cont, 0);
        lv_style_set_layout(&style_text_cont, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_text_cont, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_main_place(&style_text_cont, LV_FLEX_ALIGN_SPACE_BETWEEN);
        lv_style_set_text_font(&style_text_cont, Roboto_Bold_15);
        lv_style_set_text_color(&style_text_cont, lv_color_hex(0xffffff));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "recipe_card_#");
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_card, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, bg_image);
    lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_CLICKABLE, false);
    lv_obj_add_style(lv_obj_1, &style_cover, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_0, title);
    lv_obj_set_width(lv_label_0, lv_pct(100));
    lv_obj_set_style_text_font(lv_label_0, Roboto_Medium_30, 0);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
    lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_CLICKABLE, false);
    lv_obj_add_style(lv_obj_2, &style_cont, 0);
    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_2);
    lv_image_set_src(lv_image_1, clock_small_icon);
    
    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_2);
    lv_obj_set_flag(lv_obj_3, LV_OBJ_FLAG_CLICKABLE, false);
    lv_obj_add_style(lv_obj_3, &style_text_cont, 0);
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_1, "Cooking time");
    lv_obj_set_style_text_font(lv_label_1, Roboto_Medium_15, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_2, time);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

