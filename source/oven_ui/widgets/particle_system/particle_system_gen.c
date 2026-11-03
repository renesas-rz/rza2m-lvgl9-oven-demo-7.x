/**
 * @file particle_system_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "particle_system_private_gen.h"
#include "lvgl/src/core/lv_obj_class_private.h"
#include "oven_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void particle_system_constructor_hook(lv_obj_t * obj);
void particle_system_destructor_hook(lv_obj_t * obj);
void particle_system_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void particle_system_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void particle_system_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void particle_system_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t particle_system_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = particle_system_constructor,
    .destructor_cb = particle_system_destructor,
    .event_cb = particle_system_event,
    .instance_size = sizeof(particle_system_t),
    .editable = 1,
    .name = "particle_system"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * particle_system_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&particle_system_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void particle_system_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    particle_system_t * widget = (particle_system_t *)obj;

    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }
    


    particle_system_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void particle_system_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    particle_system_destructor_hook(obj);
}

static void particle_system_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&particle_system_class, e);
    if(res != LV_RESULT_OK) return;

    particle_system_event_hook(e);
}

