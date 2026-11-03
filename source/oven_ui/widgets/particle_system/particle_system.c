/**
 * @file particle_system.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "particle_system_private_gen.h"
#include "oven_ui.h"

/*********************
 *      DEFINES
 *********************/
#define VECTOR_UPSCALE_BITS 8
#define VECTOR_UPSCALE_VALUE (1 << VECTOR_UPSCALE_BITS)

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
	uint32_t birth_time;
	uint32_t death_time;
	int32_t angle;
	int32_t step_upscaled;
	int32_t acceleration_per_sec;
	int32_t motion_spin;
	int32_t rotation;
	int32_t gravity_sum;
	lv_point_t drift;
	uint16_t scale_start;
	uint16_t scale_end;
	uint16_t scale;
	lv_opa_t opa_start;
	lv_opa_t opa_end;
	lv_opa_t opa;
	lv_area_t area;
	const void * src;
}particle_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void update_timer_cb(lv_timer_t * t);
static void create_particle(lv_obj_t * obj);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void particle_system_constructor_hook(lv_obj_t * obj)
{
	particle_system_t * ps = (particle_system_t *)obj;
	lv_ll_init(&ps->particles_ll, sizeof(particle_t));
	ps->particle.speed = 100;
	ps->particle.opa_start = LV_OPA_COVER;
	ps->particle.opa_end = LV_OPA_COVER;
	ps->particle.scale_start = LV_SCALE_NONE;
	ps->particle.scale_end = LV_SCALE_NONE;
	ps->particle.lifetime = 1000;
	ps->emission.dir = PARTICLE_SYSTEM_EMISSION_DIR_UP;
	ps->emission.width = lv_pct(100);
	ps->emission.height = lv_pct(100);
	ps->emission.period = 1000;
	ps->emission.next_emission_time = lv_tick_get();

	lv_display_t * disp = lv_obj_get_display(obj);
	lv_timer_t * refr_timer = lv_display_get_refr_timer(disp);
	//uint32_t refr_perid = refr_timer ? lv_timer_get_period(refr_timer) : LV_DEF_REFR_PERIOD;
	uint32_t refr_perid = LV_DEF_REFR_PERIOD;
	ps->timer = lv_timer_create(update_timer_cb, refr_perid, obj);


    LV_IMAGE_DECLARE(spark1_data);
    LV_IMAGE_DECLARE(spark2_data);
      particle_system_set_emission_dir(obj, PARTICLE_SYSTEM_EMISSION_DIR_UP);
      static void * srcs[3] = {&spark1_data, &spark2_data};
      particle_system_set_particle_src_array(obj, srcs, 2);
      particle_system_set_emission_period(obj, 200);
      particle_system_set_particle_angle_jitter(obj, 50);
      particle_system_set_particle_lifetime(obj, 5000);
      particle_system_set_particle_scale_end(obj, 128);
      particle_system_set_particle_scale_end_jitter(obj, 64);
      particle_system_set_particle_opa_start(obj, 191);
      particle_system_set_particle_opa_start_jitter(obj, 64);
      particle_system_set_particle_opa_end(obj, 0);
      particle_system_set_particle_speed(obj, 109);   /* A2M 800x480: 140 * 25/32 */
      particle_system_set_particle_speed_jitter(obj, 47);   /* A2M: 60 * 25/32 */
      particle_system_set_particle_acceleration(obj, -8);   /* A2M: -10 * 25/32 */
      particle_system_set_particle_acceleration_jitter(obj, 5);
      particle_system_set_particle_motion_spin(obj, 20);
      particle_system_set_particle_motion_spin_jitter(obj, 20);
	  particle_system_set_particle_face_motion_dir(obj, true);

      lv_obj_set_size(obj, lv_pct(100), lv_pct(100));
      lv_obj_center(obj);


}

void particle_system_destructor_hook(lv_obj_t * obj)
{
	particle_system_t * ps = (particle_system_t *)obj;
	lv_timer_delete(ps->timer);
	lv_ll_clear(&ps->particles_ll);
}

void particle_system_event_hook(lv_event_t * e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * obj = lv_event_get_target_obj(e);

	if(code == LV_EVENT_DRAW_MAIN) {
		particle_system_t * ps = (particle_system_t *)obj;
		lv_layer_t * layer = lv_event_get_layer(e);

		lv_draw_image_dsc_t draw_dsc;
		lv_draw_image_dsc_init(&draw_dsc);
//		draw_dsc.blend_mode = LV_BLEND_MODE_ADDITIVE;

		particle_t *p;
		LV_LL_READ(&ps->particles_ll, p) {
			draw_dsc.src = p->src;
			draw_dsc.opa = p->opa;
			draw_dsc.scale_x = p->scale;
			draw_dsc.scale_y = p->scale;
			draw_dsc.pivot.x = lv_area_get_width(&p->area) / 2;
			draw_dsc.pivot.y = lv_area_get_height(&p->area) / 2;
			draw_dsc.rotation = p->rotation;
			lv_area_t a = p->area;
			lv_area_move(&a, obj->coords.x1, obj->coords.y1);
			lv_draw_image(layer, &draw_dsc, &a);
		}
	}
}


void particle_system_set_gravity(lv_obj_t * particle_system, int32_t gravity)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->gravity = gravity;
}

void particle_system_set_emission_width(lv_obj_t * particle_system, int32_t width)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->emission.width = width;
}

void particle_system_set_emission_height(lv_obj_t * particle_system, int32_t height)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->emission.width = height;
}

void particle_system_set_emission_x(lv_obj_t * particle_system, int32_t x)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->emission.x = x;
}

void particle_system_set_emission_y(lv_obj_t * particle_system, int32_t y)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->emission.y = y;
}

void particle_system_set_emission_dir(lv_obj_t * particle_system, particle_system_emission_dir_t dir)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->emission.dir = dir;
}

void particle_system_set_emission_period(lv_obj_t * particle_system, int32_t period)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->emission.period = period;
}

void particle_system_set_emission_period_randomness(lv_obj_t * particle_system, int32_t period_randomness)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->emission.period_randomness = period_randomness;
}

void particle_system_set_particle_src_array(lv_obj_t * particle_system, const void * src[], size_t src_cnt)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.src = src;
	ps->particle.src_cnt = src_cnt;
}


void particle_system_set_particle_angle_jitter(lv_obj_t * particle_system, int32_t angle_jitter)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.angle_jitter = angle_jitter;
}

void particle_system_set_particle_lifetime(lv_obj_t * particle_system, int32_t lifetime)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.lifetime = lifetime;
}

void particle_system_set_particle_lifetime_jitter(lv_obj_t * particle_system, int32_t lifetime_jitter)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.lifetime_jitter = lifetime_jitter;
}

void particle_system_set_particle_opa_start(lv_obj_t * particle_system, lv_opa_t opa_start)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.opa_start = opa_start;
}

void particle_system_set_particle_opa_start_jitter(lv_obj_t * particle_system, lv_opa_t opa_start_jitter)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.opa_start_jitter = opa_start_jitter;
}

void particle_system_set_particle_opa_end(lv_obj_t * particle_system, lv_opa_t opa_end)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.opa_end= opa_end;
}

void particle_system_set_particle_opa_end_jitter(lv_obj_t * particle_system, lv_opa_t opa_end_jitter)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.opa_end_jitter = opa_end_jitter;
}

void particle_system_set_particle_scale_start(lv_obj_t * particle_system, int32_t scale_start)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.scale_start = scale_start;
}

void particle_system_set_particle_scale_start_jitter(lv_obj_t * particle_system, int32_t scale_start_jitter)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.scale_start_jitter = scale_start_jitter;
}

void particle_system_set_particle_scale_end(lv_obj_t * particle_system, int32_t scale_end)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.scale_end = scale_end;
}

void particle_system_set_particle_scale_end_jitter(lv_obj_t * particle_system, int32_t scale_end_jtter)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.scale_end_jitter = scale_end_jtter;
}

void particle_system_set_particle_speed(lv_obj_t * particle_system, int32_t speed)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.speed = speed;
}

void particle_system_set_particle_speed_jitter(lv_obj_t * particle_system, int32_t speed_jitter)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.speed_jitter = speed_jitter;
}

void particle_system_set_particle_acceleration(lv_obj_t * particle_system, int32_t acceleration)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.acceleration = acceleration;
}

void particle_system_set_particle_acceleration_jitter(lv_obj_t * particle_system, int32_t acceleration_jitter)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.acceleration_jitter = acceleration_jitter;
}

void particle_system_set_particle_motion_spin(lv_obj_t * particle_system, int32_t motion_spin)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.motion_spin = motion_spin;
}

void particle_system_set_particle_motion_spin_jitter(lv_obj_t * particle_system, int32_t motion_spin_jitter)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.motion_spin_jitter = motion_spin_jitter;
}

void particle_system_set_particle_drift_x(lv_obj_t * particle_system, int32_t drift_x)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.drift.x = drift_x;
}

void particle_system_set_particle_drift_x_jitter(lv_obj_t * particle_system, int32_t drift_x_jitter)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.drift_jitter.x = drift_x_jitter;
}

void particle_system_set_particle_drift_y(lv_obj_t * particle_system, int32_t drift_y)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.drift.y = drift_y;
}

void particle_system_set_particle_drift_y_jitter(lv_obj_t * particle_system, int32_t drift_y_jitter)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.drift_jitter.y = drift_y_jitter;
}

void particle_system_set_particle_face_motion_dir(lv_obj_t * particle_system, bool face_motion_dir)
{
	particle_system_t * ps = (particle_system_t *) particle_system;
	ps->particle.face_motion_dir = face_motion_dir;
}


void particle_system_add_active_particles(lv_obj_t * particle_system, int32_t cnt)
{
	uint32_t i;
	for(i = 0; i < cnt; i++) {
		create_particle(particle_system);
	}

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void invalidate_particle(lv_obj_t * obj, particle_t * p)
{
	particle_system_t * ps = (particle_system_t *) obj;
	lv_area_t area_abs = p->area;

	//	lv_area_move(&area, obj->coords.x1 + ps->emission.x, obj->coords.y1 + ps->emission.y);
	lv_area_move(&area_abs, obj->coords.x1, obj->coords.y1);

	lv_point_t points[4] = {
			{area_abs.x1, area_abs.y1},
			{area_abs.x1, area_abs.y2 + 1},
			{area_abs.x2 + 1, area_abs.y1},
			{area_abs.x2 + 1, area_abs.y2 + 1},
	};

	lv_point_t pivot;
	pivot.x = area_abs.x1 + lv_area_get_width(&area_abs) / 2;
	pivot.y = area_abs.y1 + lv_area_get_width(&area_abs) / 2;
	lv_point_array_transform(points, 4, p->rotation, p->scale, p->scale,  &pivot, true);

	area_abs.x1 = LV_MIN4(points[0].x, points[1].x, points[2].x, points[3].x);
	area_abs.x2 = LV_MAX4(points[0].x, points[1].x, points[2].x, points[3].x);
	area_abs.y1 = LV_MIN4(points[0].y, points[1].y, points[2].y, points[3].y);
	area_abs.y2 = LV_MAX4(points[0].y, points[1].y, points[2].y, points[3].y);

	lv_area_increase(&area_abs, 5, 5);
	lv_obj_invalidate_area(obj, &area_abs);
}

static int32_t get_value(int32_t base, int32_t randomness)
{
	int32_t r = lv_rand(0, 2 * randomness) - randomness;
	return base + r;
}

static void create_particle(lv_obj_t * obj)
{
	particle_system_t * ps = (particle_system_t *) obj;
	uint32_t t = lv_tick_get();

	int32_t next_period = get_value(ps->emission.period, ps->emission.period_randomness);
	ps->emission.next_emission_time += next_period;

	particle_t * p = lv_ll_ins_head(&ps->particles_ll);
	lv_memzero(p, sizeof(particle_t));
	p->birth_time = t;
	int32_t lifetime = get_value(ps->particle.lifetime, ps->particle.lifetime_jitter);
	p->death_time = p->birth_time + LV_MAX(1, lifetime);

	p->src = ps->particle.src[lv_rand(0, ps->particle.src_cnt - 1)];

	lv_image_header_t img_header;
	lv_image_decoder_get_info(p->src, &img_header);
	int32_t w = lv_pct_to_px(ps->emission.width, lv_area_get_width(&obj->coords));
	int32_t h = lv_pct_to_px(ps->emission.width, lv_area_get_height(&obj->coords));
	if(w == 0) w = 1;
	if(h == 0) h = 1;
	
	lv_area_set(&p->area, 0, 0, img_header.w - 1, img_header.h - 1);

	switch(ps->emission.dir) {
	case PARTICLE_SYSTEM_EMISSION_DIR_UP:
		p->angle = get_value(270, ps->particle.angle_jitter);
		lv_area_set_pos(&p->area, lv_rand(0, w - 1), h + img_header.h);
		break;
	case PARTICLE_SYSTEM_EMISSION_DIR_DOWN:
		p->angle = get_value(90, ps->particle.angle_jitter);
		lv_area_set_pos(&p->area, lv_rand(0, w - 1), -img_header.h);
		break;
	case PARTICLE_SYSTEM_EMISSION_DIR_LEFT:
		p->angle = get_value(180, ps->particle.angle_jitter);
		lv_area_set_pos(&p->area, -img_header.w, lv_rand(0, h - 1));
		break;
	case PARTICLE_SYSTEM_EMISSION_DIR_RIGHT:
		p->angle = get_value(0, ps->particle.angle_jitter);
		lv_area_set_pos(&p->area, w + img_header.w, lv_rand(0, h - 1));
		break;
	case PARTICLE_SYSTEM_EMISSION_DIR_INSIDE:
		p->angle = lv_rand(0, 360);
		lv_area_set_pos(&p->area, lv_rand(0, w - 1), lv_rand(0, h - 1));
		break;
	}

	lv_area_move(&p->area, ps->emission.x, ps->emission.y);

	p->step_upscaled = 1000 * get_value(ps->particle.speed, ps->particle.speed_jitter);
	p->acceleration_per_sec = get_value(ps->particle.acceleration, ps->particle.acceleration_jitter);
	p->motion_spin = get_value(ps->particle.motion_spin, ps->particle.motion_spin_jitter);
	p->opa_start = get_value(ps->particle.opa_start, ps->particle.opa_start_jitter);
	p->opa_end = get_value(ps->particle.opa_end, ps->particle.opa_end_jitter);
	p->drift.x = get_value(ps->particle.drift.x, ps->particle.drift_jitter.x);
	p->scale_start = get_value(ps->particle.scale_start, ps->particle.scale_start_jitter);
	p->scale_end = get_value(ps->particle.scale_end, ps->particle.scale_end_jitter);
	p->drift.x = get_value(ps->particle.drift.x, ps->particle.drift_jitter.x);
	p->drift.y = get_value(ps->particle.drift.y, ps->particle.drift_jitter.y);

	p->opa = p->opa_start;
	p->scale = p->scale_start;
	invalidate_particle(obj, p);
}

static void cleanup_particles(lv_obj_t * obj)
{
	particle_system_t * ps = (particle_system_t *) obj;
	particle_t * p = lv_ll_get_head(&ps->particles_ll);
	uint32_t t = lv_tick_get();
	while(p) {
		particle_t * p_next = lv_ll_get_next(&ps->particles_ll, p);

		if(t >= p->death_time) {
			invalidate_particle(obj, p);
			lv_ll_remove(&ps->particles_ll, p);
			lv_free(p);
		}
		p = p_next;
	}

}

static void update_particle(lv_obj_t * obj, particle_t * p)
{
	invalidate_particle(obj, p);

	particle_system_t * ps = (particle_system_t *) obj;
	uint32_t elaps = lv_tick_elaps(ps->particle.last_update_time);
	uint32_t total_life = p->death_time - p->birth_time;
	uint32_t current_life = lv_tick_get() - p->birth_time;

	p->opa = lv_map(current_life, 0, total_life, p->opa_start, p->opa_end);
	p->scale = lv_map(current_life, 0, total_life, p->scale_start, p->scale_end);

	p->angle += (int32_t)((int32_t)p->motion_spin * elaps) / 1000;

	/*Proportional acceleration for the elapsed ms.
	 *As step is upscaled don't divide by 1000*/
	int32_t acc_prop = ((int32_t)elaps * p->acceleration_per_sec);
	p->step_upscaled += acc_prop;
	if(p->step_upscaled < 0) p->step_upscaled = 0;

	/*Step was upscaled by 1000.
	 *Divide by 100 again to get step proportional to the elapsed ms*/
	int32_t step = (((int32_t)elaps * p->step_upscaled) / (1000 * 1000));

	/*Get the drift proportional to the elapsed ms.
	 *Also upscale to get atn results later*/
	lv_point_t drift_prop;
	drift_prop.x = (((int32_t)elaps * p->drift.x * 256) / 1000);
	drift_prop.y = (((int32_t)elaps * p->drift.y * 256) / 1000);

	p->gravity_sum += (int32_t)((int32_t)ps->gravity * 256 * elaps) / 1000;

	int32_t vy = (lv_trigo_sin(p->angle) * step) >> (LV_TRIGO_SHIFT - 8);
	int32_t vx = (lv_trigo_cos(p->angle) * step) >> (LV_TRIGO_SHIFT - 8);
	vx += drift_prop.x;
	vy += drift_prop.y;
	vy += p->gravity_sum;

//	printf("%d, %d, %d, %d\n", vx, vy, step, p->angle);

	if(ps->particle.face_motion_dir) {
		if(LV_ABS(vx) > 100 || LV_ABS(vy) > 100) {
			p->rotation = lv_atan2(vy, vx) * 10;
		}
	}

	lv_area_move(&p->area, vx >> 8, vy >> 8);

	invalidate_particle(obj, p);
}

static void update_timer_cb(lv_timer_t * tmr)
{
	lv_obj_t * obj = lv_timer_get_user_data(tmr);
	particle_system_t * ps = (particle_system_t *) obj;

	uint32_t t = lv_tick_get();
	while(t >= (ps->emission.next_emission_time)) {
		create_particle(obj);
	}
	cleanup_particles(obj);

	particle_t * p;
	LV_LL_READ(&ps->particles_ll, p) {
		update_particle(obj, p);
	}

	ps->particle.last_update_time = lv_tick_get();
}

