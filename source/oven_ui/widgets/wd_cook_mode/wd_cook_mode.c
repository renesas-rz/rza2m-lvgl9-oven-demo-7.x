/**
 * @file wd_cook_mode.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_cook_mode_private_gen.h"
#include "oven_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void on_button_set_click_cb(lv_event_t * e);

static void on_scroll_end_cb(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void wd_cook_mode_constructor_hook(lv_obj_t * obj)
{
    wd_cook_mode_t * widget = (wd_cook_mode_t *)obj;

    lv_obj_add_event_cb(widget->button_set, on_button_set_click_cb, LV_EVENT_CLICKED, widget);
    lv_obj_add_event_cb(widget->mode_cont, on_scroll_end_cb, LV_EVENT_SCROLL_END, widget);

    lv_obj_scroll_by_bounded(widget->mode_cont, 0, -1, LV_ANIM_OFF);

}

void wd_cook_mode_destructor_hook(lv_obj_t * obj)
{
    wd_cook_mode_t * widget = (wd_cook_mode_t *)obj;
}

void wd_cook_mode_event_hook(lv_event_t * e)
{

}

void wd_cook_mode_bind_cook_mode(lv_obj_t * wd_cook_mode, lv_subject_t * bind_cook_mode)
{
    wd_cook_mode_t * widget = (wd_cook_mode_t *)wd_cook_mode;
    widget->bind_cook_mode = bind_cook_mode;

}

void wd_cook_mode_bind_button_set(lv_obj_t * wd_cook_mode, lv_subject_t * bind_button_set)
{
    wd_cook_mode_t * widget = (wd_cook_mode_t *)wd_cook_mode;
    widget->bind_button_set = bind_button_set;

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void on_button_set_click_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    wd_cook_mode_t * widget = (wd_cook_mode_t *)lv_event_get_user_data(e);
    if (widget->bind_button_set) {
        lv_subject_set_int(widget->bind_button_set, 0);
    }   
}

static void on_scroll_end_cb(lv_event_t * e)
{
    wd_cook_mode_t * widget = (wd_cook_mode_t *)lv_event_get_user_data(e);
    int32_t scroll_y = lv_obj_get_scroll_y(widget->mode_cont);
    
    int32_t index = (scroll_y + 196) / (88 + 8);   /* A2M 800x480: (480/2 - 88/2), item 112->88, gap 10->8 */
    
    lv_obj_t * item = lv_obj_get_child(widget->mode_cont, index);
    if (!item) return;
    lv_obj_t * image = lv_obj_get_child(item, 0);
    if (!image) return;
    lv_subject_set_pointer(&subject_cook_mode_icon, lv_image_get_src(image));

}
