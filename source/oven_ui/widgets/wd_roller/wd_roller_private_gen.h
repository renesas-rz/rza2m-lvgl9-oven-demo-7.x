/**
 * @file wd_roller_private_gen.h
 *
 */

#ifndef WD_ROLLER_PRIVATE_H
#define WD_ROLLER_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "wd_roller.h"

/*********************
 *      DEFINES
 *********************/

#ifndef WD_ROLLER_USER_DATA
#define WD_ROLLER_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    lv_subject_t * bind_temperature;
    lv_subject_t * bind_button_set;
    lv_obj_t * roller;
    lv_obj_t * lv_obj_0;
    lv_obj_t * lv_obj_1;
    lv_obj_t * button_set;
    lv_obj_t * lv_label_0;
    WD_ROLLER_USER_DATA
} wd_roller_t;

extern const lv_obj_class_t wd_roller_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_roller_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_ROLLER_PRIVATE_H*/