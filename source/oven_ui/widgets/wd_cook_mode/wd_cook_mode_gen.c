/**
 * @file wd_cook_mode_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_cook_mode_private_gen.h"
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

void wd_cook_mode_constructor_hook(lv_obj_t * obj);
void wd_cook_mode_destructor_hook(lv_obj_t * obj);
void wd_cook_mode_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_cook_mode_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_cook_mode_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_cook_mode_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_cook_mode_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = wd_cook_mode_constructor,
    .destructor_cb = wd_cook_mode_destructor,
    .event_cb = wd_cook_mode_event,
    .instance_size = sizeof(wd_cook_mode_t),
    .editable = 1,
    .name = "wd_cook_mode"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * wd_cook_mode_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_cook_mode_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void wd_cook_mode_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_cook_mode_t * widget = (wd_cook_mode_t *)obj;
    static lv_style_t style_cook_mode;
    static lv_style_t style_mode_cont;
    static lv_style_t style_bars;
    static lv_style_t style_overlay;
    static lv_style_t style_button_set;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_cook_mode);
        lv_style_set_width(&style_cook_mode, 295);
        lv_style_set_height(&style_cook_mode, 480);
        lv_style_set_bg_color(&style_cook_mode, lv_color_hex(0xEEB111));
        lv_style_set_pad_all(&style_cook_mode, 0);
        lv_style_set_radius(&style_cook_mode, 0);
        lv_style_set_border_width(&style_cook_mode, 0);

        lv_style_init(&style_mode_cont);
        lv_style_set_layout(&style_mode_cont, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_mode_cont, LV_FLEX_FLOW_COLUMN);
        lv_style_set_pad_row(&style_mode_cont, 8);

        lv_style_init(&style_bars);
        lv_style_set_width(&style_bars, 308);
        lv_style_set_height(&style_bars, 100);
        lv_style_set_radius(&style_bars, 0);
        lv_style_set_border_width(&style_bars, 6);
        lv_style_set_bg_opa(&style_bars, 0);
        lv_style_set_border_color(&style_bars, lv_color_hex(0xffffff));
        lv_style_set_pad_all(&style_bars, 0);

        lv_style_init(&style_overlay);
        lv_style_set_width(&style_overlay, LV_SIZE_CONTENT);
        lv_style_set_height(&style_overlay, LV_SIZE_CONTENT);
        lv_style_set_radius(&style_overlay, 0);
        lv_style_set_border_width(&style_overlay, 0);
        lv_style_set_bg_color(&style_overlay, lv_color_hex(0x000000));
        lv_style_set_bg_opa(&style_overlay, 150);
        lv_style_set_pad_all(&style_overlay, 0);

        lv_style_init(&style_button_set);
        lv_style_set_width(&style_button_set, 295);
        lv_style_set_height(&style_button_set, 50);
        lv_style_set_border_width(&style_button_set, 0);
        lv_style_set_radius(&style_button_set, 6);
        lv_style_set_text_font(&style_button_set, Roboto_Medium_30);
        lv_style_set_pad_all(&style_button_set, 0);
        lv_style_set_shadow_width(&style_button_set, 39);
        lv_style_set_shadow_spread(&style_button_set, 39);
        lv_style_set_shadow_color(&style_button_set, lv_color_hex(0xEEB111));

        style_inited = true;
    }
    lv_obj_set_flag(obj, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(obj, &style_cook_mode, 0);
    lv_obj_t * mode_cont = lv_obj_create(obj);
    lv_obj_set_name(mode_cont, "mode_cont");
    lv_obj_set_scrollbar_mode(mode_cont, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_snap_y(mode_cont, LV_SCROLL_SNAP_CENTER);
    widget->mode_cont = mode_cont;
    lv_obj_add_style(mode_cont, &style_cook_mode, 0);
    lv_obj_add_style(mode_cont, &style_mode_cont, 0);
    lv_obj_t * mode_item_0 = mode_item_create(mode_cont, conventional_icon, "Conventional Cooking");
    widget->mode_item_0 = mode_item_0;
    
    lv_obj_t * mode_item_1 = mode_item_create(mode_cont, defrost_icon, "Defrost");
    widget->mode_item_1 = mode_item_1;
    
    lv_obj_t * mode_item_2 = mode_item_create(mode_cont, grill_icon, "Grill");
    widget->mode_item_2 = mode_item_2;
    
    lv_obj_t * mode_item_3 = mode_item_create(mode_cont, turbo_grill_icon, "Turbo Grilling");
    widget->mode_item_3 = mode_item_3;
    
    lv_obj_t * mode_item_4 = mode_item_create(mode_cont, moist_fan_icon, "Moist Fan Baking");
    widget->mode_item_4 = mode_item_4;
    
    lv_obj_t * mode_item_5 = mode_item_create(mode_cont, true_fan_icon, "True Fan Cooking");
    widget->mode_item_5 = mode_item_5;
    
    lv_obj_t * mode_item_6 = mode_item_create(mode_cont, bottom_heat_icon, "Bottom Heat");
    widget->mode_item_6 = mode_item_6;
    
    lv_obj_t * lv_obj_0 = lv_obj_create(obj);
    lv_obj_set_align(lv_obj_0, LV_ALIGN_TOP_MID);
    lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xEEB111), 0);
    lv_obj_set_style_bg_opa(lv_obj_0, 200, 0);
    lv_obj_set_style_shadow_opa(lv_obj_0, 200, 0);
    lv_obj_set_style_border_width(lv_obj_0, -1, 0);
    lv_obj_set_style_border_opa(lv_obj_0, 255, 0);
    lv_obj_set_style_border_color(lv_obj_0, lv_color_hex(0xEEB111), 0);
    widget->lv_obj_0 = lv_obj_0;
    lv_obj_add_style(lv_obj_0, &style_button_set, 0);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(obj);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_CENTER);
    lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_CLICKABLE, false);
    widget->lv_obj_1 = lv_obj_1;
    lv_obj_add_style(lv_obj_1, &style_bars, 0);
    
    lv_obj_t * button_set = button_set_create(obj);
    lv_obj_set_name(button_set, "button_set");
    lv_obj_set_align(button_set, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(button_set, -31);
    widget->button_set = button_set;


    wd_cook_mode_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_cook_mode_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_cook_mode_destructor_hook(obj);
}

static void wd_cook_mode_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_cook_mode_class, e);
    if(res != LV_RESULT_OK) return;

    wd_cook_mode_event_hook(e);
}

