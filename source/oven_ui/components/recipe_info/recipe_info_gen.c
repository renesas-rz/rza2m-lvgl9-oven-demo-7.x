/**
 * @file recipe_info_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "recipe_info_gen.h"
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

lv_obj_t * recipe_info_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_info;
    static lv_style_t style_info_back;
    static lv_style_t style_info_back_pressed;
    static lv_style_t style_info_details;
    static lv_style_t style_scrollbar;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_info);
        lv_style_set_width(&style_info, 312);
        lv_style_set_height(&style_info, 480);
        lv_style_set_bg_color(&style_info, lv_color_hex(0x000000));
        lv_style_set_bg_opa(&style_info, (255 * 70 / 100));
        lv_style_set_radius(&style_info, 0);
        lv_style_set_border_width(&style_info, 0);
        lv_style_set_pad_all(&style_info, 0);
        lv_style_set_flex_flow(&style_info, LV_FLEX_FLOW_COLUMN);
        lv_style_set_layout(&style_info, LV_LAYOUT_FLEX);

        lv_style_init(&style_info_back);
        lv_style_set_width(&style_info_back, lv_pct(100));
        lv_style_set_height(&style_info_back, 50);
        lv_style_set_pad_all(&style_info_back, 0);
        lv_style_set_pad_left(&style_info_back, 31);
        lv_style_set_pad_right(&style_info_back, 31);
        lv_style_set_pad_column(&style_info_back, 9);
        lv_style_set_radius(&style_info_back, 0);
        lv_style_set_border_width(&style_info_back, 0);
        lv_style_set_bg_color(&style_info_back, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&style_info_back, 0);
        lv_style_set_text_color(&style_info_back, lv_color_hex(0xffffff));
        lv_style_set_text_font(&style_info_back, Roboto_Medium_30);
        lv_style_set_layout(&style_info_back, LV_LAYOUT_FLEX);
        lv_style_set_flex_track_place(&style_info_back, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_info_back, LV_FLEX_ALIGN_CENTER);

        lv_style_init(&style_info_back_pressed);
        lv_style_set_bg_opa(&style_info_back_pressed, 127);
        lv_style_set_bg_color(&style_info_back_pressed, lv_color_hex3(0xfff));

        lv_style_init(&style_info_details);
        lv_style_set_flex_grow(&style_info_details, 1);
        lv_style_set_width(&style_info_details, 312);
        lv_style_set_radius(&style_info_details, 0);
        lv_style_set_bg_opa(&style_info_details, 0);
        lv_style_set_pad_top(&style_info_details, 0);
        lv_style_set_pad_bottom(&style_info_details, 31);
        lv_style_set_pad_left(&style_info_details, 31);
        lv_style_set_pad_right(&style_info_details, 31);
        lv_style_set_pad_column(&style_info_details, 8);
        lv_style_set_pad_row(&style_info_details, 8);
        lv_style_set_border_width(&style_info_details, 0);
        lv_style_set_layout(&style_info_details, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_info_details, LV_FLEX_FLOW_ROW_WRAP);
        lv_style_set_text_color(&style_info_details, lv_color_hex(0xffffff));
        lv_style_set_text_font(&style_info_details, Roboto_Regular_20);
        lv_style_set_text_line_space(&style_info_details, 6);

        lv_style_init(&style_scrollbar);
        lv_style_set_width(&style_scrollbar, 6);
        lv_style_set_height(&style_scrollbar, 0);
        lv_style_set_radius(&style_scrollbar, 0);
        lv_style_set_bg_color(&style_scrollbar, lv_color_hex(0xEEB111));
        lv_style_set_bg_opa(&style_scrollbar, 255);
        lv_style_set_pad_top(&style_scrollbar, 0);
        lv_style_set_pad_bottom(&style_scrollbar, 0);
        lv_style_set_pad_right(&style_scrollbar, 0);
        lv_style_set_length(&style_scrollbar, 113);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "recipe_info_#");

    lv_obj_add_style(lv_obj_0, &style_info, 0);
    lv_obj_add_style(lv_obj_0, &style_blur, 0);
    lv_obj_t * recipe_back_button = lv_obj_create(lv_obj_0);
    lv_obj_set_name(recipe_back_button, "recipe_back_button");
    lv_obj_add_style(recipe_back_button, &style_info_back, 0);
    lv_obj_add_style(recipe_back_button, &style_info_back_pressed, LV_STATE_PRESSED);
    lv_obj_add_style(recipe_back_button, &style_blur, 0);
    lv_obj_t * lv_image_0 = lv_image_create(recipe_back_button);
    lv_image_set_src(lv_image_0, back_icon);
    
    lv_obj_t * lv_label_0 = lv_label_create(recipe_back_button);
    lv_label_set_text(lv_label_0, "Back");
    lv_obj_set_style_pad_top(lv_label_0, 4, 0);
    
    lv_obj_t * recipe_scroll_cont = lv_obj_create(lv_obj_0);
    lv_obj_set_name(recipe_scroll_cont, "recipe_scroll_cont");
    lv_obj_add_style(recipe_scroll_cont, &style_info_details, 0);
    lv_obj_add_style(recipe_scroll_cont, &style_scrollbar, LV_PART_SCROLLBAR);
    lv_obj_t * meta_card_0 = meta_card_create(recipe_scroll_cont, difficulty_icon, "Ability", &subject_recipe_ability);
    
    lv_obj_t * meta_card_1 = meta_card_create(recipe_scroll_cont, clock_icon, "Cooking time", &subject_recipe_cook_time);
    
    lv_obj_t * meta_card_2 = meta_card_create(recipe_scroll_cont, preparation_icon, "Preparation time", &subject_recipe_prep_time);
    
    lv_obj_t * meta_card_3 = meta_card_create(recipe_scroll_cont, serving_icon, "Serves", &subject_recipe_serves);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(recipe_scroll_cont);
    lv_obj_set_width(lv_obj_1, lv_pct(100));
    lv_obj_set_height(lv_obj_1, LV_SIZE_CONTENT);
    lv_obj_set_style_pad_all(lv_obj_1, 0, 0);
    lv_obj_set_style_pad_top(lv_obj_1, 16, 0);
    lv_obj_add_style(lv_obj_1, &style_info_details, 0);
    lv_obj_t * recipe_title = lv_label_create(lv_obj_1);
    lv_obj_set_name(recipe_title, "recipe_title");
    lv_obj_set_width(recipe_title, lv_pct(100));
    lv_obj_set_style_text_font(recipe_title, Roboto_Medium_40, 0);
    
    lv_obj_t * recipe_description = lv_label_create(lv_obj_1);
    lv_obj_set_name(recipe_description, "recipe_description");
    lv_obj_set_width(recipe_description, lv_pct(100));
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_1);
    lv_obj_set_width(lv_label_1, lv_pct(100));
    lv_label_set_text(lv_label_1, "Ingredients");
    lv_obj_set_style_text_font(lv_label_1, Roboto_Medium_30, 0);
    lv_obj_set_style_pad_top(lv_label_1, 8, 0);
    
    lv_obj_t * recipe_ingredients = lv_label_create(lv_obj_1);
    lv_obj_set_name(recipe_ingredients, "recipe_ingredients");
    lv_obj_set_width(recipe_ingredients, lv_pct(100));
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_1);
    lv_obj_set_width(lv_label_2, lv_pct(100));
    lv_label_set_text(lv_label_2, "Steps");
    lv_obj_set_style_text_font(lv_label_2, Roboto_Medium_30, 0);
    lv_obj_set_style_pad_top(lv_label_2, 8, 0);
    
    lv_obj_t * recipe_steps = lv_label_create(lv_obj_1);
    lv_obj_set_name(recipe_steps, "recipe_steps");
    lv_obj_set_width(recipe_steps, lv_pct(100));

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

