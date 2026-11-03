/**
 * @file wd_time_selector_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_time_selector_private_gen.h"
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

void wd_time_selector_constructor_hook(lv_obj_t * obj);
void wd_time_selector_destructor_hook(lv_obj_t * obj);
void wd_time_selector_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_time_selector_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_time_selector_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_time_selector_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_time_selector_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = wd_time_selector_constructor,
    .destructor_cb = wd_time_selector_destructor,
    .event_cb = wd_time_selector_event,
    .instance_size = sizeof(wd_time_selector_t),
    .editable = 1,
    .name = "wd_time_selector"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * wd_time_selector_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_time_selector_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void wd_time_selector_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_time_selector_t * widget = (wd_time_selector_t *)obj;
    static lv_style_t style_selector;
    static lv_style_t style_bars;
    static lv_style_t style_roller;
    static lv_style_t style_roller_selected;
    static lv_style_t style_button_set;
    static lv_style_t style_button_click;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_selector);
        lv_style_set_width(&style_selector, 375);
        lv_style_set_height(&style_selector, 480);
        lv_style_set_bg_color(&style_selector, lv_color_hex(0xEEB111));
        lv_style_set_pad_all(&style_selector, 0);
        lv_style_set_radius(&style_selector, 0);
        lv_style_set_border_width(&style_selector, 0);
        lv_style_set_text_font(&style_selector, Roboto_Medium_100);
        lv_style_set_text_color(&style_selector, lv_color_hex(0xFFFFFF));

        lv_style_init(&style_bars);
        lv_style_set_width(&style_bars, 388);
        lv_style_set_height(&style_bars, 100);
        lv_style_set_radius(&style_bars, 0);
        lv_style_set_border_width(&style_bars, 6);
        lv_style_set_bg_opa(&style_bars, 0);
        lv_style_set_border_color(&style_bars, lv_color_hex(0xffffff));
        lv_style_set_pad_all(&style_bars, 0);

        lv_style_init(&style_roller);
        lv_style_set_width(&style_roller, 153);
        lv_style_set_height(&style_roller, 480);
        lv_style_set_bg_color(&style_roller, lv_color_hex(0xEEB111));
        lv_style_set_radius(&style_roller, 0);
        lv_style_set_border_width(&style_roller, 0);
        lv_style_set_text_color(&style_roller, lv_color_hex(0xececec));
        lv_style_set_text_font(&style_roller, Roboto_Medium_100);
        lv_style_set_text_line_space(&style_roller, 39);
        lv_style_set_pad_all(&style_roller, 0);

        lv_style_init(&style_roller_selected);
        lv_style_set_height(&style_roller_selected, 88);
        lv_style_set_bg_opa(&style_roller_selected, 0);
        lv_style_set_border_width(&style_roller_selected, 0);
        lv_style_set_text_color(&style_roller_selected, lv_color_hex(0xFFFFFF));

        lv_style_init(&style_button_set);
        lv_style_set_width(&style_button_set, 163);
        lv_style_set_height(&style_button_set, 50);
        lv_style_set_border_width(&style_button_set, 0);
        lv_style_set_radius(&style_button_set, 6);
        lv_style_set_text_font(&style_button_set, Roboto_Medium_30);
        lv_style_set_pad_all(&style_button_set, 0);
        lv_style_set_shadow_width(&style_button_set, 39);
        lv_style_set_shadow_spread(&style_button_set, 39);
        lv_style_set_shadow_color(&style_button_set, lv_color_hex(0xEEB111));

        lv_style_init(&style_button_click);
        lv_style_set_bg_color(&style_button_click, lv_color_hex(0xf6cb5f));

        style_inited = true;
    }
    lv_obj_set_flag(obj, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(obj, &style_selector, 0);
    lv_obj_t * lv_obj_0 = lv_obj_create(obj);
    widget->lv_obj_0 = lv_obj_0;
    lv_obj_add_style(lv_obj_0, &style_selector, 0);
    lv_obj_t * roller_hour = lv_roller_create(lv_obj_0);
    lv_obj_set_name(roller_hour, "roller_hour");
    lv_roller_set_options(roller_hour, "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23", LV_ROLLER_MODE_INFINITE);
    widget->roller_hour = roller_hour;
    lv_obj_add_style(roller_hour, &style_roller, 0);
    lv_obj_add_style(roller_hour, &style_roller_selected, LV_PART_SELECTED);
    
    lv_obj_t * roller_minute = lv_roller_create(lv_obj_0);
    lv_obj_set_name(roller_minute, "roller_minute");
    lv_roller_set_options(roller_minute, "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_x(roller_minute, 158);
    widget->roller_minute = roller_minute;
    lv_obj_add_style(roller_minute, &style_roller, 0);
    lv_obj_add_style(roller_minute, &style_roller_selected, LV_PART_SELECTED);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_LEFT_MID);
    lv_obj_set_x(lv_label_0, 121);
    lv_label_set_text(lv_label_0, "h");
    widget->lv_label_0 = lv_label_0;
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_obj_set_align(lv_label_1, LV_ALIGN_LEFT_MID);
    lv_obj_set_x(lv_label_1, 277);
    lv_label_set_text(lv_label_1, "m");
    widget->lv_label_1 = lv_label_1;
    
    lv_obj_t * lv_obj_1 = lv_obj_create(obj);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_CENTER);
    lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_CLICKABLE, false);
    widget->lv_obj_1 = lv_obj_1;
    lv_obj_add_style(lv_obj_1, &style_bars, 0);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(obj);
    lv_obj_set_width(lv_obj_2, 375);
    lv_obj_set_align(lv_obj_2, LV_ALIGN_TOP_MID);
    lv_obj_set_style_bg_color(lv_obj_2, lv_color_hex(0xEEB111), 0);
    lv_obj_set_style_bg_opa(lv_obj_2, 200, 0);
    lv_obj_set_style_shadow_opa(lv_obj_2, 200, 0);
    lv_obj_set_style_border_width(lv_obj_2, -1, 0);
    lv_obj_set_style_border_opa(lv_obj_2, 255, 0);
    lv_obj_set_style_border_color(lv_obj_2, lv_color_hex(0xEEB111), 0);
    widget->lv_obj_2 = lv_obj_2;
    lv_obj_add_style(lv_obj_2, &style_button_set, 0);
    
    lv_obj_t * lv_obj_3 = lv_obj_create(obj);
    lv_obj_set_width(lv_obj_3, 375);
    lv_obj_set_align(lv_obj_3, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_style_bg_color(lv_obj_3, lv_color_hex(0xEEB111), 0);
    lv_obj_set_style_bg_opa(lv_obj_3, 205, 0);
    lv_obj_set_style_shadow_opa(lv_obj_3, 205, 0);
    lv_obj_set_style_border_width(lv_obj_3, -1, 0);
    lv_obj_set_style_border_opa(lv_obj_3, 255, 0);
    lv_obj_set_style_border_color(lv_obj_3, lv_color_hex(0xEEB111), 0);
    widget->lv_obj_3 = lv_obj_3;
    lv_obj_add_style(lv_obj_3, &style_button_set, 0);
    
    lv_obj_t * button_set = lv_obj_create(obj);
    lv_obj_set_name(button_set, "button_set");
    lv_obj_set_y(button_set, 388);
    lv_obj_set_align(button_set, LV_ALIGN_TOP_MID);
    widget->button_set = button_set;
    lv_obj_add_style(button_set, &style_button_set, 0);
    lv_obj_add_style(button_set, &style_button_click, LV_STATE_PRESSED);
    lv_obj_t * lv_label_2 = lv_label_create(button_set);
    lv_label_set_text(lv_label_2, "Set");
    lv_obj_set_align(lv_label_2, LV_ALIGN_CENTER);
    widget->lv_label_2 = lv_label_2;


    wd_time_selector_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_time_selector_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_time_selector_destructor_hook(obj);
}

static void wd_time_selector_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_time_selector_class, e);
    if(res != LV_RESULT_OK) return;

    wd_time_selector_event_hook(e);
}

