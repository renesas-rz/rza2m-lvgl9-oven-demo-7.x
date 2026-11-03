/**
 * @file oven_ui_gen.h
 */

#ifndef OVEN_UI_GEN_H
#define OVEN_UI_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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

/*********************
 *      DEFINES
 *********************/

#define SCREEN_CHANGE_SPEED 500

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_blur;

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * Roboto_Regular_15;

extern lv_font_t * Roboto_Regular_20;

extern lv_font_t * Roboto_Medium_15;

extern lv_font_t * Roboto_Medium_30;

extern lv_font_t * Roboto_Medium_40;

extern lv_font_t * Roboto_Medium_50;

extern lv_font_t * Roboto_Medium_100;

extern lv_font_t * Roboto_Medium_160;

extern lv_font_t * Roboto_Bold_15;

/*----------------
 * Images
 *----------------*/

extern const void * clock_small_icon;
extern const void * clock_icon;
extern const void * heat_icon;
extern const void * back_icon;
extern const void * perf_icon;
extern const void * grill_icon;
extern const void * bottom_heat_icon;
extern const void * conventional_icon;
extern const void * defrost_icon;
extern const void * true_fan_icon;
extern const void * moist_fan_icon;
extern const void * turbo_grill_icon;
extern const void * arrow_icon;
extern const void * saved_icon;
extern const void * serving_icon;
extern const void * preparation_icon;
extern const void * difficulty_icon;
extern const void * bell_icon;
extern const void * ganoush_bg;
extern const void * lava_cake;
extern const void * salmon;
extern const void * vegetable;
extern const void * pizza;
extern const void * chicken;
extern const void * fire_sparks;
extern const void * spark1;
extern const void * spark2;
extern const void * perf_button_image;
extern const void * close_button_image;
extern const void * whirlpool_logo;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_roller_view;
extern lv_subject_t subject_meal_view;
extern lv_subject_t subject_cook_mode_view;
extern lv_subject_t subject_time_view;
extern lv_subject_t subject_temperature;
extern lv_subject_t subject_cook_time;
extern lv_subject_t subject_cook_time_fmt;
extern lv_subject_t subject_timer_trigger;
extern lv_subject_t subject_timer_stop;
extern lv_subject_t subject_timer_add;
extern lv_subject_t subject_timer_bell_view;
extern lv_subject_t subject_timer_3min_view;
extern lv_subject_t subject_show_perf_sidebar;
extern lv_subject_t subject_gpu_enable;
extern lv_subject_t subject_recipe_prep_time;
extern lv_subject_t subject_recipe_cook_time;
extern lv_subject_t subject_recipe_serves;
extern lv_subject_t subject_recipe_ability;
extern lv_subject_t subject_recipe_title;
extern lv_subject_t subject_recipe_description;
extern lv_subject_t subject_recipe_ingredients;
extern lv_subject_t subject_recipe_steps;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

void make_non_clickable_cb(lv_event_t * e);

/**
 * Initialize the component library
 */

void oven_ui_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "components/button_icon/button_icon_gen.h"
#include "components/button_set/button_set_gen.h"
#include "components/button/button_gen.h"
#include "components/meta_card/meta_card_gen.h"
#include "components/mode_item/mode_item_gen.h"
#include "components/performance_button/performance_button_gen.h"
#include "components/performance_sidebar/performance_sidebar_gen.h"
#include "components/recipe_card/recipe_card_gen.h"
#include "components/recipe_info/recipe_info_gen.h"
#include "screens/baking_gen.h"
#include "screens/launch_gen.h"
#include "screens/meals_gen.h"
#include "screens/options_gen.h"
#include "widgets/particle_system/particle_system_gen.h"
#include "widgets/wd_cook_mode/wd_cook_mode_gen.h"
#include "widgets/wd_icon/wd_icon_gen.h"
#include "widgets/wd_meal/wd_meal_gen.h"
#include "widgets/wd_recipe_bg/wd_recipe_bg_gen.h"
#include "widgets/wd_roller/wd_roller_gen.h"
#include "widgets/wd_time_selector/wd_time_selector_gen.h"
#include "widgets/wd_timer/wd_timer_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*OVEN_UI_GEN_H*/