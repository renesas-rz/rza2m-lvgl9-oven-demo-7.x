/**
 * @file wd_roller_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_roller_private_gen.h"
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

void wd_roller_constructor_hook(lv_obj_t * obj);
void wd_roller_destructor_hook(lv_obj_t * obj);
void wd_roller_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_roller_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_roller_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_roller_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_roller_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = wd_roller_constructor,
    .destructor_cb = wd_roller_destructor,
    .event_cb = wd_roller_event,
    .instance_size = sizeof(wd_roller_t),
    .editable = 1,
    .name = "wd_roller"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * wd_roller_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_roller_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void wd_roller_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_roller_t * widget = (wd_roller_t *)obj;
    static lv_style_t style_roller;
    static lv_style_t style_roller_selected;
    static lv_style_t style_overlay;
    static lv_style_t style_button_set;
    static lv_style_t style_bar;
    static lv_style_t style_button_click;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_roller);
        lv_style_set_width(&style_roller, 231);
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
        lv_style_set_border_width(&style_roller_selected, 6);
        lv_style_set_border_color(&style_roller_selected, lv_color_hex(0xFFFFFF));
        lv_style_set_border_side(&style_roller_selected, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_text_color(&style_roller_selected, lv_color_hex(0xFFFFFF));

        lv_style_init(&style_overlay);
        lv_style_set_width(&style_overlay, LV_SIZE_CONTENT);
        lv_style_set_height(&style_overlay, LV_SIZE_CONTENT);
        lv_style_set_radius(&style_overlay, 0);
        lv_style_set_border_width(&style_overlay, 0);
        lv_style_set_bg_color(&style_overlay, lv_color_hex(0x000000));
        lv_style_set_bg_opa(&style_overlay, 150);
        lv_style_set_pad_all(&style_overlay, 0);

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

        lv_style_init(&style_bar);
        lv_style_set_width(&style_bar, lv_pct(100));
        lv_style_set_height(&style_bar, 6);
        lv_style_set_radius(&style_bar, 0);
        lv_style_set_border_width(&style_bar, 0);
        lv_style_set_bg_color(&style_bar, lv_color_hex(0xFFFFFF));
        lv_style_set_pad_all(&style_bar, 0);

        lv_style_init(&style_button_click);
        lv_style_set_bg_color(&style_button_click, lv_color_hex(0xf6cb5f));

        style_inited = true;
    }
    lv_obj_add_style(obj, &style_overlay, 0);
    lv_obj_t * roller = lv_roller_create(obj);
    lv_obj_set_name(roller, "roller");
    lv_roller_set_options(roller, "180°\n185°\n190°\n195°\n200°\n205°\n210°", LV_ROLLER_MODE_NORMAL);
    widget->roller = roller;
    lv_obj_add_style(roller, &style_roller, 0);
    lv_obj_add_style(roller, &style_roller_selected, LV_PART_SELECTED);
    lv_obj_t * lv_obj_0 = lv_obj_create(roller);
    lv_obj_set_align(lv_obj_0, LV_ALIGN_TOP_MID);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_CLICKABLE, false);
    lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xEEB111), 0);
    lv_obj_set_style_bg_opa(lv_obj_0, 200, 0);
    lv_obj_set_style_shadow_opa(lv_obj_0, 200, 0);
    lv_obj_set_style_border_width(lv_obj_0, -1, 0);
    lv_obj_set_style_border_opa(lv_obj_0, 255, 0);
    lv_obj_set_style_border_color(lv_obj_0, lv_color_hex(0xEEB111), 0);
    widget->lv_obj_0 = lv_obj_0;
    lv_obj_add_style(lv_obj_0, &style_button_set, 0);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(roller);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_obj_1, 180);
    lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_CLICKABLE, false);
    widget->lv_obj_1 = lv_obj_1;
    lv_obj_add_style(lv_obj_1, &style_bar, 0);
    
    lv_obj_t * button_set = lv_obj_create(roller);
    lv_obj_set_name(button_set, "button_set");
    lv_obj_set_y(button_set, 388);
    lv_obj_set_align(button_set, LV_ALIGN_TOP_MID);
    widget->button_set = button_set;
    lv_obj_add_style(button_set, &style_button_set, 0);
    lv_obj_add_style(button_set, &style_button_click, LV_STATE_PRESSED);
    lv_obj_t * lv_label_0 = lv_label_create(button_set);
    lv_label_set_text(lv_label_0, "Set");
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    widget->lv_label_0 = lv_label_0;


    wd_roller_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_roller_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_roller_destructor_hook(obj);
}

static void wd_roller_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_roller_class, e);
    if(res != LV_RESULT_OK) return;

    wd_roller_event_hook(e);
}

