/**
 * @file wd_timer_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_timer_private_gen.h"
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

void wd_timer_constructor_hook(lv_obj_t * obj);
void wd_timer_destructor_hook(lv_obj_t * obj);
void wd_timer_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_timer_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_timer_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_timer_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_timer_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = wd_timer_constructor,
    .destructor_cb = wd_timer_destructor,
    .event_cb = wd_timer_event,
    .instance_size = sizeof(wd_timer_t),
    .editable = 1,
    .name = "wd_timer"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * wd_timer_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_timer_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void wd_timer_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_timer_t * widget = (wd_timer_t *)obj;
    static lv_style_t style_bar_white;
    static lv_style_t style_bar_yellow;
    static lv_style_t style_text_yellow;
    static lv_style_t style_ver;
    static lv_style_t style_hor;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_bar_white);
        lv_style_set_bg_color(&style_bar_white, lv_color_hex(0xffffff));
        lv_style_set_width(&style_bar_white, 625);
        lv_style_set_height(&style_bar_white, 9);

        lv_style_init(&style_bar_yellow);
        lv_style_set_bg_color(&style_bar_yellow, lv_color_hex(0xeeb111));

        lv_style_init(&style_text_yellow);
        lv_style_set_text_color(&style_text_yellow, lv_color_hex(0xEEB111));

        lv_style_init(&style_ver);
        lv_style_set_width(&style_ver, 625);
        lv_style_set_height(&style_ver, LV_SIZE_CONTENT);
        lv_style_set_pad_all(&style_ver, 0);
        lv_style_set_radius(&style_ver, 0);
        lv_style_set_bg_opa(&style_ver, 0);
        lv_style_set_border_width(&style_ver, 0);
        lv_style_set_layout(&style_ver, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_ver, LV_FLEX_FLOW_COLUMN);
        lv_style_set_pad_row(&style_ver, 31);
        lv_style_set_flex_cross_place(&style_ver, LV_FLEX_ALIGN_CENTER);
        lv_style_set_text_font(&style_ver, Roboto_Medium_30);
        lv_style_set_text_color(&style_ver, lv_color_hex(0xffffff));

        lv_style_init(&style_hor);
        lv_style_set_width(&style_hor, LV_SIZE_CONTENT);
        lv_style_set_height(&style_hor, LV_SIZE_CONTENT);
        lv_style_set_pad_all(&style_hor, 0);
        lv_style_set_radius(&style_hor, 0);
        lv_style_set_bg_opa(&style_hor, 0);
        lv_style_set_border_width(&style_hor, 0);
        lv_style_set_layout(&style_hor, LV_LAYOUT_FLEX);
        lv_style_set_text_color(&style_hor, lv_color_hex(0xffffff));
        lv_style_set_flex_cross_place(&style_hor, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_hor, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_column(&style_hor, 0);

        style_inited = true;
    }
    lv_obj_add_style(obj, &style_ver, 0);
    lv_obj_t * title_label = lv_label_create(obj);
    lv_obj_set_name(title_label, "title_label");
    lv_label_set_text(title_label, "Loading");
    widget->title_label = title_label;
    
    lv_obj_t * lv_obj_0 = lv_obj_create(obj);
    widget->lv_obj_0 = lv_obj_0;
    lv_obj_add_style(lv_obj_0, &style_hor, 0);
    lv_obj_t * countdown_left = lv_label_create(lv_obj_0);
    lv_obj_set_name(countdown_left, "countdown_left");
    lv_label_set_text(countdown_left, "00:00");
    lv_obj_set_style_text_font(countdown_left, Roboto_Medium_160, 0);
    widget->countdown_left = countdown_left;
    lv_obj_add_style(countdown_left, &style_text_yellow, LV_STATE_CHECKED);
    
    lv_obj_t * countdown_right = lv_label_create(lv_obj_0);
    lv_obj_set_name(countdown_right, "countdown_right");
    lv_label_set_text(countdown_right, "00");
    lv_obj_set_style_text_font(countdown_right, Roboto_Medium_160, 0);
    lv_obj_set_flag(countdown_right, LV_OBJ_FLAG_HIDDEN, true);
    widget->countdown_right = countdown_right;
    lv_obj_add_style(countdown_right, &style_text_yellow, LV_STATE_CHECKED);
    
    lv_obj_t * progress_bar = lv_bar_create(obj);
    lv_obj_set_name(progress_bar, "progress_bar");
    lv_bar_set_value(progress_bar, 100, false);
    lv_obj_set_state(progress_bar, LV_STATE_CHECKED, true);
    widget->progress_bar = progress_bar;
    lv_obj_add_style(progress_bar, &style_bar_white, 0);
    lv_obj_add_style(progress_bar, &style_bar_white, LV_PART_INDICATOR);
    lv_obj_add_style(progress_bar, &style_bar_yellow, 0);
    lv_obj_add_style(progress_bar, &style_bar_yellow, LV_PART_INDICATOR | LV_STATE_CHECKED);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(obj);
    lv_obj_set_style_pad_column(lv_obj_1, 16, 0);
    widget->lv_obj_1 = lv_obj_1;
    lv_obj_add_style(lv_obj_1, &style_hor, 0);
    lv_obj_t * wd_icon_0 = wd_icon_create(lv_obj_1);
    widget->wd_icon_0 = wd_icon_0;
    
    lv_obj_t * temperature_label = lv_label_create(lv_obj_1);
    lv_obj_set_name(temperature_label, "temperature_label");
    lv_label_set_text(temperature_label, "180°");
    lv_obj_set_style_text_font(temperature_label, Roboto_Medium_100, 0);
    widget->temperature_label = temperature_label;


    wd_timer_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_timer_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_timer_destructor_hook(obj);
}

static void wd_timer_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_timer_class, e);
    if(res != LV_RESULT_OK) return;

    wd_timer_event_hook(e);
}

