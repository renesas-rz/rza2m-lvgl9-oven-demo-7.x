/**
 * @file options_gen.h
 */

#ifndef OPTIONS_H
#define OPTIONS_H

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
    OPTIONS_TIMELINE_OPEN = 0,
    OPTIONS_TIMELINE_CLOSE = 1,
    _OPTIONS_TIMELINE_CNT = 2
}options_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * options_create(void);

/**
 * Get a timeline of a options
 * @param obj          pointer to a options component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * options_get_timeline(lv_obj_t * obj, options_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*OPTIONS_H*/