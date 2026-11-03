/**
 * @file wd_time_selector.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_time_selector_private_gen.h"
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
static void on_roller_hour_changed_cb(lv_event_t * e);
static void on_roller_minute_changed_cb(lv_event_t * e);

static void time_observer_cb(lv_observer_t *observer, lv_subject_t *subject);
/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void wd_time_selector_constructor_hook(lv_obj_t * obj)
{
    wd_time_selector_t * widget = (wd_time_selector_t *)obj;

    lv_obj_add_event_cb(widget->button_set, on_button_set_click_cb, LV_EVENT_CLICKED, widget);
    lv_obj_add_event_cb(widget->roller_hour, on_roller_hour_changed_cb, LV_EVENT_VALUE_CHANGED, widget);
    lv_obj_add_event_cb(widget->roller_minute, on_roller_minute_changed_cb, LV_EVENT_VALUE_CHANGED, widget);
}

void wd_time_selector_destructor_hook(lv_obj_t * obj)
{
    wd_time_selector_t * widget = (wd_time_selector_t *)obj;
}

void wd_time_selector_event_hook(lv_event_t * e)
{

}

void wd_time_selector_bind_time(lv_obj_t * wd_time_selector, lv_subject_t * bind_time)
{
    wd_time_selector_t * widget = (wd_time_selector_t *)wd_time_selector;
    widget->bind_time = bind_time;
    lv_subject_add_observer_obj(widget->bind_time, time_observer_cb, wd_time_selector, widget);

    int32_t time = lv_subject_get_int(widget->bind_time);
    lv_roller_set_selected(widget->roller_minute, time % 60, LV_ANIM_ON);
    lv_roller_set_selected(widget->roller_hour, (time / 60) % 24, LV_ANIM_ON);

}

void wd_time_selector_bind_button_set(lv_obj_t * wd_time_selector, lv_subject_t * bind_button_set)
{
    wd_time_selector_t * widget = (wd_time_selector_t *)wd_time_selector;
    widget->bind_button_set = bind_button_set;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void on_button_set_click_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    wd_time_selector_t * widget = (wd_time_selector_t *)lv_event_get_user_data(e);
    if (widget->bind_button_set) {
        lv_subject_set_int(widget->bind_button_set, 0);
    }   
}

static void on_roller_hour_changed_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    wd_time_selector_t * widget = (wd_time_selector_t *)lv_event_get_user_data(e);
    int32_t value = lv_roller_get_selected(widget->roller_hour) * 60 + (lv_roller_get_selected(widget->roller_minute));
    if (widget->bind_time) {
        lv_subject_set_int(widget->bind_time, value);
    } 

}

static void on_roller_minute_changed_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    wd_time_selector_t * widget = (wd_time_selector_t *)lv_event_get_user_data(e);
    int32_t value = lv_roller_get_selected(widget->roller_hour) * 60 + (lv_roller_get_selected(widget->roller_minute));
    if (widget->bind_time) {
        lv_subject_set_int(widget->bind_time, value);
    } 
}

static void time_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    wd_time_selector_t * widget = (wd_time_selector_t *)lv_observer_get_user_data(observer);
    lv_obj_t * obj = (lv_obj_t *)widget;
    int32_t time = lv_subject_get_int(subject);
    lv_roller_set_selected(widget->roller_minute, time % 60, LV_ANIM_ON);
    lv_roller_set_selected(widget->roller_hour, (time / 60) % 24, LV_ANIM_ON);

}
