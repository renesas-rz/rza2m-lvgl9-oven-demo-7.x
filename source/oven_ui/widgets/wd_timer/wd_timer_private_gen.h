/**
 * @file wd_timer_private_gen.h
 *
 */

#ifndef WD_TIMER_PRIVATE_H
#define WD_TIMER_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "wd_timer.h"

/*********************
 *      DEFINES
 *********************/

#ifndef WD_TIMER_USER_DATA
#define WD_TIMER_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    lv_subject_t * bind_cook_time;
    lv_subject_t * bind_cook_temperature;
    lv_subject_t * bind_recipe_title;
    lv_subject_t * bind_bell_view;
    lv_subject_t * bind_3min_view;
    lv_subject_t * bind_button_stop;
    lv_subject_t * bind_button_add;
    lv_subject_t * bind_trigger;
    lv_obj_t * title_label;
    lv_obj_t * lv_obj_0;
    lv_obj_t * countdown_left;
    lv_obj_t * countdown_right;
    lv_obj_t * progress_bar;
    lv_obj_t * lv_obj_1;
    lv_obj_t * wd_icon_0;
    lv_obj_t * temperature_label;
    WD_TIMER_USER_DATA
} wd_timer_t;

extern const lv_obj_class_t wd_timer_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_timer_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_TIMER_PRIVATE_H*/