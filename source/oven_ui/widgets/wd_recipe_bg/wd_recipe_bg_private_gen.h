/**
 * @file wd_recipe_bg_private_gen.h
 *
 */

#ifndef WD_RECIPE_BG_PRIVATE_H
#define WD_RECIPE_BG_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "wd_recipe_bg.h"

/*********************
 *      DEFINES
 *********************/

#ifndef WD_RECIPE_BG_USER_DATA
#define WD_RECIPE_BG_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    lv_obj_t * image;
    lv_obj_t * recipe_bg_overlay;
    WD_RECIPE_BG_USER_DATA
} wd_recipe_bg_t;

extern const lv_obj_class_t wd_recipe_bg_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_recipe_bg_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_RECIPE_BG_PRIVATE_H*/