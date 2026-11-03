/**
 * @file wd_roller_gen.h
 *
 */

#ifndef WD_ROLLER_GEN_H
#define WD_ROLLER_GEN_H

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
 * Create a wd_roller object
 * @param parent pointer to an object, it will be the parent of the new wd_roller
 * @return pointer to the created wd_roller
 */
lv_obj_t * wd_roller_create(lv_obj_t * parent);
/**
 * The subject that hold the temperature value, to be bound to the roller
 * @param obj   pointer to a wd_roller
 * @param bind_temperature  The subject that hold the temperature value, to be bound to the roller
 */
void wd_roller_bind_temperature(lv_obj_t * wd_roller, lv_subject_t * bind_temperature);

/**
 * The subject that to be triggered when set button is clicked
 * @param obj   pointer to a wd_roller
 * @param bind_button_set  The subject that to be triggered when set button is clicked
 */
void wd_roller_bind_button_set(lv_obj_t * wd_roller, lv_subject_t * bind_button_set);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_ROLLER_GEN_H*/