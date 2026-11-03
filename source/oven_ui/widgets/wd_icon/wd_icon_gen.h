/**
 * @file wd_icon_gen.h
 *
 */

#ifndef WD_ICON_GEN_H
#define WD_ICON_GEN_H

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
 * Create a wd_icon object
 * @param parent pointer to an object, it will be the parent of the new wd_icon
 * @return pointer to the created wd_icon
 */
lv_obj_t * wd_icon_create(lv_obj_t * parent);
;

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_ICON_GEN_H*/