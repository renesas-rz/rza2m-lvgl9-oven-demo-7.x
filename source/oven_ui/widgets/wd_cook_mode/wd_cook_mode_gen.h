/**
 * @file wd_cook_mode_gen.h
 *
 */

#ifndef WD_COOK_MODE_GEN_H
#define WD_COOK_MODE_GEN_H

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
 * Create a wd_cook_mode object
 * @param parent pointer to an object, it will be the parent of the new wd_cook_mode
 * @return pointer to the created wd_cook_mode
 */
lv_obj_t * wd_cook_mode_create(lv_obj_t * parent);
/**
 * The subject that holds the cook mode icon
 * @param obj   pointer to a wd_cook_mode
 * @param bind_cook_mode  The subject that holds the cook mode icon
 */
void wd_cook_mode_bind_cook_mode(lv_obj_t * wd_cook_mode, lv_subject_t * bind_cook_mode);

/**
 * The subject that to be triggered when set button is clicked
 * @param obj   pointer to a wd_cook_mode
 * @param bind_button_set  The subject that to be triggered when set button is clicked
 */
void wd_cook_mode_bind_button_set(lv_obj_t * wd_cook_mode, lv_subject_t * bind_button_set);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_COOK_MODE_GEN_H*/