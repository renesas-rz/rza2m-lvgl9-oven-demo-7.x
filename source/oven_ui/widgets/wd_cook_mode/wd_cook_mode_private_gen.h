/**
 * @file wd_cook_mode_private_gen.h
 *
 */

#ifndef WD_COOK_MODE_PRIVATE_H
#define WD_COOK_MODE_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "wd_cook_mode.h"

/*********************
 *      DEFINES
 *********************/

#ifndef WD_COOK_MODE_USER_DATA
#define WD_COOK_MODE_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    lv_subject_t * bind_cook_mode;
    lv_subject_t * bind_button_set;
    lv_obj_t * mode_cont;
    lv_obj_t * mode_item_0;
    lv_obj_t * mode_item_1;
    lv_obj_t * mode_item_2;
    lv_obj_t * mode_item_3;
    lv_obj_t * mode_item_4;
    lv_obj_t * mode_item_5;
    lv_obj_t * mode_item_6;
    lv_obj_t * lv_obj_0;
    lv_obj_t * lv_obj_1;
    lv_obj_t * button_set;
    WD_COOK_MODE_USER_DATA
} wd_cook_mode_t;

extern const lv_obj_class_t wd_cook_mode_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_cook_mode_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_COOK_MODE_PRIVATE_H*/