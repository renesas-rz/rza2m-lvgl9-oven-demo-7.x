/**
 * @file oven_ui.h
 */

#ifndef OVEN_UI_H
#define OVEN_UI_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "oven_ui_gen.h"


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

extern lv_subject_t subject_recipe_bg;
extern lv_subject_t subject_cook_mode_icon;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the component library
 */
void oven_ui_init(const char * asset_path);

/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*OVEN_UI_H*/