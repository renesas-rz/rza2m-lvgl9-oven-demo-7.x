/**
 * @file particle_system_gen.h
 *
 */

#ifndef PARTICLE_SYSTEM_GEN_H
#define PARTICLE_SYSTEM_GEN_H

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
typedef enum {
    PARTICLE_SYSTEM_EMISSION_DIR_UP,
    PARTICLE_SYSTEM_EMISSION_DIR_DOWN,
    PARTICLE_SYSTEM_EMISSION_DIR_LEFT,
    PARTICLE_SYSTEM_EMISSION_DIR_RIGHT,
    PARTICLE_SYSTEM_EMISSION_DIR_INSIDE,
    PARTICLE_SYSTEM_EMISSION_DIR_RADIAL
}particle_system_emission_dir_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a particle_system object
 * @param parent pointer to an object, it will be the parent of the new particle_system
 * @return pointer to the created particle_system
 */
lv_obj_t * particle_system_create(lv_obj_t * parent);
/**
 * particle_system gravity
 * @param obj   pointer to a particle_system
 * @param gravity  gravity
 */
void particle_system_set_gravity(lv_obj_t * particle_system, int32_t gravity);

/**
 * particle_system emission width
 * @param obj   pointer to a particle_system
 * @param width  width
 */
void particle_system_set_emission_width(lv_obj_t * particle_system, int32_t width);

/**
 * particle_system emission height
 * @param obj   pointer to a particle_system
 * @param height  height
 */
void particle_system_set_emission_height(lv_obj_t * particle_system, int32_t height);

/**
 * particle_system emission x
 * @param obj   pointer to a particle_system
 * @param x  x
 */
void particle_system_set_emission_x(lv_obj_t * particle_system, int32_t x);

/**
 * particle_system emission y
 * @param obj   pointer to a particle_system
 * @param y  y
 */
void particle_system_set_emission_y(lv_obj_t * particle_system, int32_t y);

/**
 * particle_system emission period
 * @param obj   pointer to a particle_system
 * @param period  period
 */
void particle_system_set_emission_period(lv_obj_t * particle_system, int32_t period);

/**
 * particle_system emission period_randomness
 * @param obj   pointer to a particle_system
 * @param period_randomness  period_randomness
 */
void particle_system_set_emission_period_randomness(lv_obj_t * particle_system, int32_t period_randomness);

/**
 * particle_system emission dir
 * @param obj   pointer to a particle_system
 * @param dir  dir
 */
void particle_system_set_emission_dir(lv_obj_t * particle_system, particle_system_emission_dir_t dir);

/**
 * particle_system particle src
 * @param obj   pointer to a particle_system
 * @param src  src
 */
void particle_system_set_particle_src(lv_obj_t * particle_system, const void * src);

/**
 * particle_system particle angle_jitter
 * @param obj   pointer to a particle_system
 * @param angle_jitter  angle_jitter
 */
void particle_system_set_particle_angle_jitter(lv_obj_t * particle_system, int32_t angle_jitter);

/**
 * particle_system particle lifetime
 * @param obj   pointer to a particle_system
 * @param lifetime  lifetime
 */
void particle_system_set_particle_lifetime(lv_obj_t * particle_system, int32_t lifetime);

/**
 * particle_system particle lifetime_jitter
 * @param obj   pointer to a particle_system
 * @param lifetime_jitter  lifetime_jitter
 */
void particle_system_set_particle_lifetime_jitter(lv_obj_t * particle_system, int32_t lifetime_jitter);

/**
 * particle_system particle opa_start
 * @param obj   pointer to a particle_system
 * @param opa_start  opa_start
 */
void particle_system_set_particle_opa_start(lv_obj_t * particle_system, lv_opa_t opa_start);

/**
 * particle_system particle opa_start_jitter
 * @param obj   pointer to a particle_system
 * @param opa_start_jitter  opa_start_jitter
 */
void particle_system_set_particle_opa_start_jitter(lv_obj_t * particle_system, lv_opa_t opa_start_jitter);

/**
 * particle_system particle opa_end
 * @param obj   pointer to a particle_system
 * @param opa_end  opa_end
 */
void particle_system_set_particle_opa_end(lv_obj_t * particle_system, lv_opa_t opa_end);

/**
 * particle_system particle opa_end_jitter
 * @param obj   pointer to a particle_system
 * @param opa_end_jitter  opa_end_jitter
 */
void particle_system_set_particle_opa_end_jitter(lv_obj_t * particle_system, lv_opa_t opa_end_jitter);

/**
 * particle_system particle scale_start
 * @param obj   pointer to a particle_system
 * @param scale_start  scale_start
 */
void particle_system_set_particle_scale_start(lv_obj_t * particle_system, int32_t scale_start);

/**
 * particle_system particle scale_start_jitter
 * @param obj   pointer to a particle_system
 * @param scale_start_jitter  scale_start_jitter
 */
void particle_system_set_particle_scale_start_jitter(lv_obj_t * particle_system, int32_t scale_start_jitter);

/**
 * particle_system particle scale_end
 * @param obj   pointer to a particle_system
 * @param scale_end  scale_end
 */
void particle_system_set_particle_scale_end(lv_obj_t * particle_system, int32_t scale_end);

/**
 * particle_system particle scale_end_jitter
 * @param obj   pointer to a particle_system
 * @param scale_end_jitter  scale_end_jitter
 */
void particle_system_set_particle_scale_end_jitter(lv_obj_t * particle_system, int32_t scale_end_jitter);

/**
 * particle_system particle speed
 * @param obj   pointer to a particle_system
 * @param speed  speed
 */
void particle_system_set_particle_speed(lv_obj_t * particle_system, int32_t speed);

/**
 * particle_system particle speed_jitter
 * @param obj   pointer to a particle_system
 * @param speed_jitter  speed_jitter
 */
void particle_system_set_particle_speed_jitter(lv_obj_t * particle_system, int32_t speed_jitter);

/**
 * particle_system particle acceleration
 * @param obj   pointer to a particle_system
 * @param acceleration  acceleration
 */
void particle_system_set_particle_acceleration(lv_obj_t * particle_system, int32_t acceleration);

/**
 * particle_system particle acceleration_jitter
 * @param obj   pointer to a particle_system
 * @param acceleration_jitter  acceleration_jitter
 */
void particle_system_set_particle_acceleration_jitter(lv_obj_t * particle_system, int32_t acceleration_jitter);

/**
 * particle_system particle motion_spin
 * @param obj   pointer to a particle_system
 * @param motion_spin  motion_spin
 */
void particle_system_set_particle_motion_spin(lv_obj_t * particle_system, int32_t motion_spin);

/**
 * particle_system particle motion_spin_jitter
 * @param obj   pointer to a particle_system
 * @param motion_spin_jitter  motion_spin_jitter
 */
void particle_system_set_particle_motion_spin_jitter(lv_obj_t * particle_system, int32_t motion_spin_jitter);

/**
 * particle_system particle drift_x
 * @param obj   pointer to a particle_system
 * @param drift_x  drift_x
 */
void particle_system_set_particle_drift_x(lv_obj_t * particle_system, int32_t drift_x);

/**
 * particle_system particle drift_x_jitter
 * @param obj   pointer to a particle_system
 * @param drift_x_jitter  drift_x_jitter
 */
void particle_system_set_particle_drift_x_jitter(lv_obj_t * particle_system, int32_t drift_x_jitter);

/**
 * particle_system particle drift_y
 * @param obj   pointer to a particle_system
 * @param drift_y  drift_y
 */
void particle_system_set_particle_drift_y(lv_obj_t * particle_system, int32_t drift_y);

/**
 * particle_system particle drift_y_jitter
 * @param obj   pointer to a particle_system
 * @param drift_y_jitter  drift_y_jitter
 */
void particle_system_set_particle_drift_y_jitter(lv_obj_t * particle_system, int32_t drift_y_jitter);

/**
 * particle_system particle face_motion_dir
 * @param obj   pointer to a particle_system
 * @param face_motion_dir  face_motion_dir
 */
void particle_system_set_particle_face_motion_dir(lv_obj_t * particle_system, bool face_motion_dir);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*PARTICLE_SYSTEM_GEN_H*/