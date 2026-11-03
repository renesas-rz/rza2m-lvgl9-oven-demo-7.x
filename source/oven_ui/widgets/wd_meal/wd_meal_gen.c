/**
 * @file wd_meal_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_meal_private_gen.h"
#include "lvgl/src/core/lv_obj_class_private.h"
#include "oven_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void wd_meal_constructor_hook(lv_obj_t * obj);
void wd_meal_destructor_hook(lv_obj_t * obj);
void wd_meal_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_meal_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_meal_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_meal_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_meal_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = wd_meal_constructor,
    .destructor_cb = wd_meal_destructor,
    .event_cb = wd_meal_event,
    .instance_size = sizeof(wd_meal_t),
    .editable = 1,
    .name = "wd_meal"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * wd_meal_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_meal_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void wd_meal_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_meal_t * widget = (wd_meal_t *)obj;
    static lv_style_t style_wd_meal;
    static lv_style_t style_recipe_cont;
    static lv_style_t style_expanded;
    static lv_style_t style_favorite_cont;
    static lv_style_t style_scrollbar;
    static lv_style_t style_scrollbar_bg;
    static lv_style_t style_card;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_wd_meal);
        lv_style_set_width(&style_wd_meal, lv_pct(100));
        lv_style_set_height(&style_wd_meal, lv_pct(100));
        lv_style_set_bg_color(&style_wd_meal, lv_color_hex(0x271f16));
        lv_style_set_bg_opa(&style_wd_meal, 255);

        lv_style_init(&style_recipe_cont);
        lv_style_set_width(&style_recipe_cont, 800);
        lv_style_set_height(&style_recipe_cont, 414);
        lv_style_set_bg_opa(&style_recipe_cont, 0);
        lv_style_set_border_width(&style_recipe_cont, 0);
        lv_style_set_pad_all(&style_recipe_cont, 0);
        lv_style_set_pad_left(&style_recipe_cont, 266);
        lv_style_set_pad_right(&style_recipe_cont, 31);
        lv_style_set_pad_column(&style_recipe_cont, 16);
        lv_style_set_layout(&style_recipe_cont, LV_LAYOUT_FLEX);

        lv_style_init(&style_expanded);
        lv_style_set_width(&style_expanded, lv_pct(100));
        lv_style_set_height(&style_expanded, lv_pct(100));
        lv_style_set_radius(&style_expanded, 0);
        lv_style_set_border_width(&style_expanded, 0);
        lv_style_set_bg_opa(&style_expanded, 0);
        lv_style_set_bg_color(&style_expanded, lv_color_hex3(0x000));
        lv_style_set_bg_image_recolor(&style_expanded, lv_color_hex3(0x000));
        lv_style_set_bg_image_recolor_opa(&style_expanded, (255 * 20 / 100));
        lv_style_set_pad_all(&style_expanded, 0);

        lv_style_init(&style_favorite_cont);
        lv_style_set_width(&style_favorite_cont, 219);
        lv_style_set_height(&style_favorite_cont, 375);
        lv_style_set_layout(&style_favorite_cont, LV_LAYOUT_FLEX);
        lv_style_set_flex_main_place(&style_favorite_cont, LV_FLEX_ALIGN_END);
        lv_style_set_flex_flow(&style_favorite_cont, LV_FLEX_FLOW_COLUMN);
        lv_style_set_pad_all(&style_favorite_cont, 0);
        lv_style_set_pad_bottom(&style_favorite_cont, 31);
        lv_style_set_pad_top(&style_favorite_cont, 31);
        lv_style_set_pad_row(&style_favorite_cont, 16);
        lv_style_set_radius(&style_favorite_cont, 0);
        lv_style_set_border_width(&style_favorite_cont, 0);
        lv_style_set_text_font(&style_favorite_cont, Roboto_Regular_15);
        lv_style_set_text_color(&style_favorite_cont, lv_color_hex3(0xfff));
        lv_style_set_bg_opa(&style_favorite_cont, 0);

        lv_style_init(&style_scrollbar);
        lv_style_set_width(&style_scrollbar, 9);
        lv_style_set_radius(&style_scrollbar, 5);
        lv_style_set_bg_color(&style_scrollbar, lv_color_hex(0xEEB111));
        lv_style_set_bg_opa(&style_scrollbar, 255);
        lv_style_set_pad_top(&style_scrollbar, 0);
        lv_style_set_pad_bottom(&style_scrollbar, 0);
        lv_style_set_pad_left(&style_scrollbar, 35);
        lv_style_set_pad_right(&style_scrollbar, 670);
        lv_style_set_length(&style_scrollbar, 48);

        lv_style_init(&style_scrollbar_bg);
        lv_style_set_width(&style_scrollbar_bg, 96);
        lv_style_set_height(&style_scrollbar_bg, 9);
        lv_style_set_radius(&style_scrollbar_bg, 5);
        lv_style_set_border_width(&style_scrollbar_bg, 0);
        lv_style_set_bg_color(&style_scrollbar_bg, lv_color_hex(0xEEB111));
        lv_style_set_bg_opa(&style_scrollbar_bg, (255 * 30 / 100));
        lv_style_set_pad_top(&style_scrollbar_bg, 0);
        lv_style_set_pad_bottom(&style_scrollbar_bg, 0);
        lv_style_set_pad_right(&style_scrollbar_bg, 39);

        lv_style_init(&style_card);
        lv_style_set_width(&style_card, 234);
        lv_style_set_height(&style_card, 375);
        lv_style_set_radius(&style_card, 0);
        lv_style_set_border_width(&style_card, 0);
        lv_style_set_pad_all(&style_card, 0);
        lv_style_set_bg_color(&style_card, lv_color_hex3(0x000));
        lv_style_set_text_color(&style_card, lv_color_hex(0xffffff));

        style_inited = true;
    }
    lv_obj_add_style(obj, &style_wd_meal, 0);
    lv_obj_t * favorite_cont = lv_obj_create(obj);
    lv_obj_set_name(favorite_cont, "favorite_cont");
    lv_obj_set_x(favorite_cont, 31);
    lv_obj_set_y(favorite_cont, 31);
    widget->favorite_cont = favorite_cont;
    lv_obj_add_style(favorite_cont, &style_favorite_cont, 0);
    lv_obj_t * lv_image_0 = lv_image_create(favorite_cont);
    lv_image_set_src(lv_image_0, saved_icon);
    widget->lv_image_0 = lv_image_0;
    
    lv_obj_t * lv_label_0 = lv_label_create(favorite_cont);
    lv_obj_set_width(lv_label_0, lv_pct(100));
    lv_label_set_text(lv_label_0, "Favorite Meals");
    lv_obj_set_style_text_font(lv_label_0, Roboto_Medium_50, 0);
    widget->lv_label_0 = lv_label_0;
    
    lv_obj_t * lv_label_1 = lv_label_create(favorite_cont);
    lv_obj_set_width(lv_label_1, lv_pct(60));
    lv_label_set_text(lv_label_1, "Use the mobile app to manage your meals.");
    widget->lv_label_1 = lv_label_1;
    
    lv_obj_t * lv_obj_0 = lv_obj_create(obj);
    lv_obj_set_x(lv_obj_0, 35);
    lv_obj_set_y(lv_obj_0, 436);
    widget->lv_obj_0 = lv_obj_0;
    lv_obj_add_style(lv_obj_0, &style_scrollbar_bg, 0);
    
    lv_obj_t * meal_cont = lv_obj_create(obj);
    lv_obj_set_name(meal_cont, "meal_cont");
    lv_obj_set_y(meal_cont, 31);
    widget->meal_cont = meal_cont;
    lv_obj_add_style(meal_cont, &style_recipe_cont, 0);
    lv_obj_add_style(meal_cont, &style_scrollbar, LV_PART_SCROLLBAR);
    lv_obj_t * recipe_card_0 = recipe_card_create(meal_cont, "Baba Ganoush", "25 Minutes", vegetable);
    widget->recipe_card_0 = recipe_card_0;
    lv_obj_add_subject_set_int_event(recipe_card_0, &subject_meal_view, LV_EVENT_CLICKED, 1);
    
    lv_obj_t * recipe_card_1 = recipe_card_create(meal_cont, "Honey glazed salmon with lime and raspberries", "25 Minutes", ganoush_bg);
    widget->recipe_card_1 = recipe_card_1;
    
    lv_obj_t * recipe_card_2 = recipe_card_create(meal_cont, "Baba Ganoush", "25 Minutes", ganoush_bg);
    widget->recipe_card_2 = recipe_card_2;
    
    lv_obj_t * button_previous = button_icon_create(obj, 1800);
    lv_obj_set_name(button_previous, "button_previous");
    lv_obj_set_align(button_previous, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_x(button_previous, -66);
    lv_obj_set_y(button_previous, -8);
    lv_obj_set_state(button_previous, LV_STATE_DISABLED, true);
    widget->button_previous = button_previous;
    
    lv_obj_t * button_next = button_icon_create(obj, 0);
    lv_obj_set_name(button_next, "button_next");
    lv_obj_set_align(button_next, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_x(button_next, -16);
    lv_obj_set_y(button_next, -8);
    widget->button_next = button_next;
    
    lv_obj_t * expanded_cont = lv_obj_create(obj);
    lv_obj_set_name(expanded_cont, "expanded_cont");
    lv_obj_set_align(expanded_cont, LV_ALIGN_CENTER);
    lv_obj_set_flag(expanded_cont, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_flag(expanded_cont, LV_OBJ_FLAG_HIDDEN, true);
    widget->expanded_cont = expanded_cont;
    lv_obj_add_style(expanded_cont, &style_expanded, 0);
    lv_obj_t * expanded_image_cont = lv_obj_create(expanded_cont);
    lv_obj_set_name(expanded_image_cont, "expanded_image_cont");
    lv_obj_set_flag(expanded_image_cont, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_y(expanded_image_cont, 31);
    lv_obj_set_x(expanded_image_cont, 266);
    widget->expanded_image_cont = expanded_image_cont;
    lv_obj_add_style(expanded_image_cont, &style_card, 0);
    lv_obj_t * expanded_image_bg = lv_image_create(expanded_image_cont);
    lv_obj_set_name(expanded_image_bg, "expanded_image_bg");
    lv_image_set_src(expanded_image_bg, vegetable);
    lv_obj_set_align(expanded_image_bg, LV_ALIGN_CENTER);
    widget->expanded_image_bg = expanded_image_bg;
    
    lv_obj_t * recipe_info = recipe_info_create(expanded_cont);
    lv_obj_set_name(recipe_info, "recipe_info");
    lv_obj_set_x(recipe_info, -312);
    widget->recipe_info = recipe_info;
    
    lv_obj_t * select_button = button_create(expanded_cont, "Select Meal");
    lv_obj_set_name(select_button, "select_button");
    lv_obj_set_x(select_button, -31);
    lv_obj_set_y(select_button, 362);
    lv_obj_set_align(select_button, LV_ALIGN_TOP_RIGHT);
    widget->select_button = select_button;
    lv_obj_add_screen_create_event(select_button, LV_EVENT_CLICKED, options_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);


    wd_meal_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_meal_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_meal_destructor_hook(obj);
}

static void wd_meal_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_meal_class, e);
    if(res != LV_RESULT_OK) return;

    wd_meal_event_hook(e);
}

