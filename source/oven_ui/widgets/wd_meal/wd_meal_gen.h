/**
 * @file wd_meal_gen.h
 *
 */

#ifndef WD_MEAL_GEN_H
#define WD_MEAL_GEN_H

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
 * Create a wd_meal object
 * @param parent pointer to an object, it will be the parent of the new wd_meal
 * @return pointer to the created wd_meal
 */
lv_obj_t * wd_meal_create(lv_obj_t * parent);
/**
 * The subject to hold the selected recipe title
 * @param obj   pointer to a wd_meal
 * @param bind_title  The subject to hold the selected recipe title
 */
void wd_meal_bind_title(lv_obj_t * wd_meal, lv_subject_t * bind_title);

/**
 * The subject to hold the selected recipe description
 * @param obj   pointer to a wd_meal
 * @param bind_description  The subject to hold the selected recipe description
 */
void wd_meal_bind_description(lv_obj_t * wd_meal, lv_subject_t * bind_description);

/**
 * The subject to hold the selected recipe difficulty
 * @param obj   pointer to a wd_meal
 * @param bind_difficulty  The subject to hold the selected recipe difficulty
 */
void wd_meal_bind_difficulty(lv_obj_t * wd_meal, lv_subject_t * bind_difficulty);

/**
 * The subject to hold the selected recipe cooking time (string)
 * @param obj   pointer to a wd_meal
 * @param bind_cooking  The subject to hold the selected recipe cooking time (string)
 */
void wd_meal_bind_cooking(lv_obj_t * wd_meal, lv_subject_t * bind_cooking);

/**
 * The subject to hold the selected recipe preparation time (string)
 * @param obj   pointer to a wd_meal
 * @param bind_preparation  The subject to hold the selected recipe preparation time (string)
 */
void wd_meal_bind_preparation(lv_obj_t * wd_meal, lv_subject_t * bind_preparation);

/**
 * The subject to hold the selected recipe servings
 * @param obj   pointer to a wd_meal
 * @param bind_serves  The subject to hold the selected recipe servings
 */
void wd_meal_bind_serves(lv_obj_t * wd_meal, lv_subject_t * bind_serves);

/**
 * The subject to hold the selected recipe ingredients
 * @param obj   pointer to a wd_meal
 * @param bind_ingredients  The subject to hold the selected recipe ingredients
 */
void wd_meal_bind_ingredients(lv_obj_t * wd_meal, lv_subject_t * bind_ingredients);

/**
 * The subject to hold the selected recipe preparation steps
 * @param obj   pointer to a wd_meal
 * @param bind_steps  The subject to hold the selected recipe preparation steps
 */
void wd_meal_bind_steps(lv_obj_t * wd_meal, lv_subject_t * bind_steps);

/**
 * The subject to hold the selected recipe cooking time (int) minutes
 * @param obj   pointer to a wd_meal
 * @param bind_cook_time  The subject to hold the selected recipe cooking time (int) minutes
 */
void wd_meal_bind_cook_time(lv_obj_t * wd_meal, lv_subject_t * bind_cook_time);

/**
 * wd_meal item
 * @param obj   pointer to a wd_meal
 * @param title  Name of the meal
 * @param description  Description of the meal
 * @param background  Background image of the meal
 * @param preparation_time  Preparation time in minutes
 * @param cook_time  Cooking time in minutes
 * @param serves  Number of people the meal serves
 * @param difficulty  Preparation difficulty
 * @param ingredients  Ingredients of the recipe
 * @param steps  Preparation steps
 */
lv_obj_t * wd_meal_add_item(lv_obj_t * wd_meal, const char * title, const char * description, const void * background, int32_t preparation_time, int32_t cook_time, const char * serves, const char * difficulty, const char * ingredients, const char * steps);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_MEAL_GEN_H*/