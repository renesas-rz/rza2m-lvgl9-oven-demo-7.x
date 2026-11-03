/**
 * @file wd_icon_private_gen.h
 *
 */

#ifndef WD_ICON_PRIVATE_H
#define WD_ICON_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "wd_icon.h"

/*********************
 *      DEFINES
 *********************/

#ifndef WD_ICON_USER_DATA
#define WD_ICON_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_image_t obj;  /* Base widget to extend */
    WD_ICON_USER_DATA
} wd_icon_t;

extern const lv_obj_class_t wd_icon_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_icon_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_ICON_PRIVATE_H*/