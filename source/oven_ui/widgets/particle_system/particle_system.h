/**
 * @file particle_system.h
 *
 */

#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "particle_system_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
	int32_t width;
	int32_t height;
	int32_t x;
	int32_t y;
	particle_system_emission_dir_t dir;
	int32_t period;
	int32_t period_randomness;
	uint32_t next_emission_time;
}particle_system_emission_t;

typedef struct {
	const void ** src;
	size_t src_cnt;
	int32_t angle_jitter;
	int32_t lifetime;
	int32_t lifetime_jitter;
	int32_t speed;
	int32_t speed_jitter;
	int32_t acceleration;
	int32_t acceleration_jitter;
	lv_opa_t opa_start;
	lv_opa_t opa_start_jitter;
	lv_opa_t opa_end;
	lv_opa_t opa_end_jitter;
	int32_t motion_spin;
	int32_t motion_spin_jitter;
	lv_point_t drift;
	lv_point_t drift_jitter;
	uint32_t scale_start;
	uint32_t scale_start_jitter;
	uint32_t scale_end;
	uint32_t scale_end_jitter;
	uint32_t last_update_time;
	uint32_t face_motion_dir :1;
}particle_system_particle_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void particle_system_set_particle_src_array(lv_obj_t * particle_system, const void * src[], size_t src_cnt);

/**********************
 *      MACROS
 **********************/
#define PARTICLE_SYSTEM_USER_DATA lv_ll_t particles_ll; \
								  lv_timer_t * timer; \
								  particle_system_emission_t emission; \
								  particle_system_particle_t particle;
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*PARTICLE_SYSTEM_H*/
