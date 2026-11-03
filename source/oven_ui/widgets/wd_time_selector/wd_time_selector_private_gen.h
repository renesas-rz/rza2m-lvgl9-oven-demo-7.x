/**
 * @file wd_time_selector_private_gen.h
 *
 */

#ifndef WD_TIME_SELECTOR_PRIVATE_H
#define WD_TIME_SELECTOR_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "wd_time_selector.h"

/*********************
 *      DEFINES
 *********************/

#ifndef WD_TIME_SELECTOR_USER_DATA
#define WD_TIME_SELECTOR_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    lv_subject_t * bind_time;
    lv_subject_t * bind_button_set;
    lv_obj_t * lv_obj_0;
    lv_obj_t * roller_hour;
    lv_obj_t * roller_minute;
    lv_obj_t * lv_label_0;
    lv_obj_t * lv_label_1;
    lv_obj_t * lv_obj_1;
    lv_obj_t * lv_obj_2;
    lv_obj_t * lv_obj_3;
    lv_obj_t * button_set;
    lv_obj_t * lv_label_2;
    WD_TIME_SELECTOR_USER_DATA
} wd_time_selector_t;

extern const lv_obj_class_t wd_time_selector_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_time_selector_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_TIME_SELECTOR_PRIVATE_H*/