/**
 * @file wd_roller.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_roller_private_gen.h"
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

static void on_roller_value_changed_cb(lv_event_t * e);

static void temperature_observer_cb(lv_observer_t *observer, lv_subject_t *subject);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void wd_roller_constructor_hook(lv_obj_t * obj)
{
    wd_roller_t * widget = (wd_roller_t *)obj;

    lv_obj_add_event_cb(widget->button_set, on_button_set_click_cb, LV_EVENT_CLICKED, widget);
    lv_obj_add_event_cb(widget->roller, on_roller_value_changed_cb, LV_EVENT_VALUE_CHANGED, widget);


}

void wd_roller_destructor_hook(lv_obj_t * obj)
{

}

void wd_roller_event_hook(lv_event_t * e)
{

}

void wd_roller_bind_temperature(lv_obj_t * wd_roller, lv_subject_t * bind_temperature)
{
    wd_roller_t * widget = (wd_roller_t *)wd_roller;
    widget->bind_temperature = bind_temperature;
    lv_subject_add_observer_obj(widget->bind_temperature, temperature_observer_cb, wd_roller, widget);
    int32_t temperature = lv_subject_get_int(widget->bind_temperature);
    int32_t index = (temperature - 180) / 5;
    index = LV_CLAMP(0, index, 6);
    lv_roller_set_selected(widget->roller, index, LV_ANIM_ON);
}

void wd_roller_bind_button_set(lv_obj_t * wd_roller, lv_subject_t * bind_button_set)
{
    wd_roller_t * widget = (wd_roller_t *)wd_roller;
    widget->bind_button_set = bind_button_set;

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void on_button_set_click_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    wd_roller_t * widget = (wd_roller_t *)lv_event_get_user_data(e);
    if (widget->bind_button_set) {
        lv_subject_set_int(widget->bind_button_set, 0);
    }   
}

static void on_roller_value_changed_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    wd_roller_t * widget = (wd_roller_t *)lv_event_get_user_data(e);
    int32_t value = lv_roller_get_selected(obj) * 5 + 180;
    if (widget->bind_temperature) {
        lv_subject_set_int(widget->bind_temperature, value);
    }   
}

static void temperature_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    wd_roller_t * widget = (wd_roller_t *)lv_observer_get_user_data(observer);
    lv_obj_t * obj = (lv_obj_t *)widget;
    int32_t temperature = lv_subject_get_int(subject);
    int32_t index = (temperature - 180) / 5;
    index = LV_CLAMP(0, index, 6);
    lv_roller_set_selected(widget->roller, index, LV_ANIM_ON);
}