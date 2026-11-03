/**
 * @file wd_meal_private_gen.h
 *
 */

#ifndef WD_MEAL_PRIVATE_H
#define WD_MEAL_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "wd_meal.h"

/*********************
 *      DEFINES
 *********************/

#ifndef WD_MEAL_USER_DATA
#define WD_MEAL_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    lv_subject_t * bind_title;
    lv_subject_t * bind_description;
    lv_subject_t * bind_difficulty;
    lv_subject_t * bind_cooking;
    lv_subject_t * bind_preparation;
    lv_subject_t * bind_serves;
    lv_subject_t * bind_ingredients;
    lv_subject_t * bind_steps;
    lv_subject_t * bind_cook_time;
    lv_obj_t * favorite_cont;
    lv_obj_t * lv_image_0;
    lv_obj_t * lv_label_0;
    lv_obj_t * lv_label_1;
    lv_obj_t * lv_obj_0;
    lv_obj_t * meal_cont;
    lv_obj_t * recipe_card_0;
    lv_obj_t * recipe_card_1;
    lv_obj_t * recipe_card_2;
    lv_obj_t * button_previous;
    lv_obj_t * button_next;
    lv_obj_t * expanded_cont;
    lv_obj_t * expanded_image_cont;
    lv_obj_t * expanded_image_bg;
    lv_obj_t * recipe_info;
    lv_obj_t * select_button;
    WD_MEAL_USER_DATA
} wd_meal_t;

extern const lv_obj_class_t wd_meal_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_meal_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_MEAL_PRIVATE_H*/