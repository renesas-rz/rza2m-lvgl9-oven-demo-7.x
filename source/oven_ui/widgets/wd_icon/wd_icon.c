/**
 * @file wd_icon.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_icon_private_gen.h"
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

void wd_icon_constructor_hook(lv_obj_t * obj)
{
    wd_icon_t * widget = (wd_icon_t *)obj;

    lv_image_bind_src(obj, &subject_cook_mode_icon);

}

void wd_icon_destructor_hook(lv_obj_t * obj)
{

}

void wd_icon_event_hook(lv_event_t * e)
{

}



/**********************
 *   STATIC FUNCTIONS
 **********************/


