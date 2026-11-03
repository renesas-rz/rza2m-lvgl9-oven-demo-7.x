/**
 * @file wd_recipe_bg.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_recipe_bg_private_gen.h"
#include "oven_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void wd_recipe_bg_constructor_hook(lv_obj_t * obj)
{
    wd_recipe_bg_t * widget = (wd_recipe_bg_t *)obj;
    // lv_image_bind_src(widget->image, &subject_recipe_bg);

    const void * bg = lv_subject_get_pointer(&subject_recipe_bg);
    lv_image_set_src(widget->image, bg);

}

void wd_recipe_bg_destructor_hook(lv_obj_t * obj)
{

}

void wd_recipe_bg_event_hook(lv_event_t * e)
{

}



/**********************
 *   STATIC FUNCTIONS
 **********************/