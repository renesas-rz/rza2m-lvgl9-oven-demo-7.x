/**
 * @file particle_system_private_gen.h
 *
 */

#ifndef PARTICLE_SYSTEM_PRIVATE_H
#define PARTICLE_SYSTEM_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "particle_system.h"

/*********************
 *      DEFINES
 *********************/

#ifndef PARTICLE_SYSTEM_USER_DATA
#define PARTICLE_SYSTEM_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    int32_t gravity;
    PARTICLE_SYSTEM_USER_DATA
} particle_system_t;

extern const lv_obj_class_t particle_system_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void particle_system_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*PARTICLE_SYSTEM_PRIVATE_H*/