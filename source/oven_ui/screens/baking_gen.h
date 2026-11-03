/**
 * @file baking_gen.h
 */

#ifndef BAKING_H
#define BAKING_H

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

/**********************
 *      TYPEDEFS
 **********************/

typedef enum {
    BAKING_TIMELINE_OPEN = 0,
    _BAKING_TIMELINE_CNT = 1
}baking_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * baking_create(void);

/**
 * Get a timeline of a baking
 * @param obj          pointer to a baking component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * baking_get_timeline(lv_obj_t * obj, baking_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*BAKING_H*/