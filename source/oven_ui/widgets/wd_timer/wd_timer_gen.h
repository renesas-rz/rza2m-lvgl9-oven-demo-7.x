/**
 * @file wd_timer_gen.h
 *
 */

#ifndef WD_TIMER_GEN_H
#define WD_TIMER_GEN_H

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
 * Create a wd_timer object
 * @param parent pointer to an object, it will be the parent of the new wd_timer
 * @return pointer to the created wd_timer
 */
lv_obj_t * wd_timer_create(lv_obj_t * parent);
/**
 * The subject that holds the cooking time (minutes) of the recipe
 * @param obj   pointer to a wd_timer
 * @param bind_cook_time  The subject that holds the cooking time (minutes) of the recipe
 */
void wd_timer_bind_cook_time(lv_obj_t * wd_timer, lv_subject_t * bind_cook_time);

/**
 * The subject that holds the cooking temperature of the recipe
 * @param obj   pointer to a wd_timer
 * @param bind_cook_temperature  The subject that holds the cooking temperature of the recipe
 */
void wd_timer_bind_cook_temperature(lv_obj_t * wd_timer, lv_subject_t * bind_cook_temperature);

/**
 * The subject that holds the cooking temperature of the recipe
 * @param obj   pointer to a wd_timer
 * @param bind_recipe_title  The subject that holds the cooking temperature of the recipe
 */
void wd_timer_bind_recipe_title(lv_obj_t * wd_timer, lv_subject_t * bind_recipe_title);

/**
 * The subject that toggles visibility of the bell icon
 * @param obj   pointer to a wd_timer
 * @param bind_bell_view  The subject that toggles visibility of the bell icon
 */
void wd_timer_bind_bell_view(lv_obj_t * wd_timer, lv_subject_t * bind_bell_view);

/**
 * The subject that toggles visibility of the +3 min button
 * @param obj   pointer to a wd_timer
 * @param bind_3min_view  The subject that toggles visibility of the +3 min button
 */
void wd_timer_bind_3min_view(lv_obj_t * wd_timer, lv_subject_t * bind_3min_view);

/**
 * The subject that is triggered by the stop button. Used to receive click event
 * @param obj   pointer to a wd_timer
 * @param bind_button_stop  The subject that is triggered by the stop button. Used to receive click event
 */
void wd_timer_bind_button_stop(lv_obj_t * wd_timer, lv_subject_t * bind_button_stop);

/**
 * The subject that is triggered by the +3 min button. Used to receive click event
 * @param obj   pointer to a wd_timer
 * @param bind_button_add  The subject that is triggered by the +3 min button. Used to receive click event
 */
void wd_timer_bind_button_add(lv_obj_t * wd_timer, lv_subject_t * bind_button_add);

/**
 * The subject that triggers the timer. Set to 1 to trigger
 * @param obj   pointer to a wd_timer
 * @param bind_trigger  The subject that triggers the timer. Set to 1 to trigger
 */
void wd_timer_bind_trigger(lv_obj_t * wd_timer, lv_subject_t * bind_trigger);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_TIMER_GEN_H*/