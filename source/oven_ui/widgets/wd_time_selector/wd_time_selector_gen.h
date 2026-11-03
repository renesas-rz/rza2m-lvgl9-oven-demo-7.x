/**
 * @file wd_time_selector_gen.h
 *
 */

#ifndef WD_TIME_SELECTOR_GEN_H
#define WD_TIME_SELECTOR_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

#include "oven_ui_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a wd_time_selector object
 * @param parent pointer to an object, it will be the parent of the new wd_time_selector
 * @return pointer to the created wd_time_selector
 */
lv_obj_t * wd_time_selector_create(lv_obj_t * parent);
/**
 * The subject that holds the time value, to be bound to the rollers
 * @param obj   pointer to a wd_time_selector
 * @param bind_time  The subject that holds the time value, to be bound to the rollers
 */
void wd_time_selector_bind_time(lv_obj_t * wd_time_selector, lv_subject_t * bind_time);

/**
 * The subject that to be triggered when set button is clicked
 * @param obj   pointer to a wd_time_selector
 * @param bind_button_set  The subject that to be triggered when set button is clicked
 */
void wd_time_selector_bind_button_set(lv_obj_t * wd_time_selector, lv_subject_t * bind_button_set);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_TIME_SELECTOR_GEN_H*/