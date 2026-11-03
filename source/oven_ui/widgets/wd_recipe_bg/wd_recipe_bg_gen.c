/**
 * @file wd_recipe_bg_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_recipe_bg_private_gen.h"
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

void wd_recipe_bg_constructor_hook(lv_obj_t * obj);
void wd_recipe_bg_destructor_hook(lv_obj_t * obj);
void wd_recipe_bg_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_recipe_bg_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_recipe_bg_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_recipe_bg_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_recipe_bg_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = wd_recipe_bg_constructor,
    .destructor_cb = wd_recipe_bg_destructor,
    .event_cb = wd_recipe_bg_event,
    .instance_size = sizeof(wd_recipe_bg_t),
    .editable = 1,
    .name = "wd_recipe_bg"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * wd_recipe_bg_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_recipe_bg_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void wd_recipe_bg_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_recipe_bg_t * widget = (wd_recipe_bg_t *)obj;
    static lv_style_t style_bg_image;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_bg_image);
        lv_style_set_width(&style_bg_image, lv_pct(100));
        lv_style_set_height(&style_bg_image, lv_pct(100));
        lv_style_set_bg_opa(&style_bg_image, 0);

        style_inited = true;
    }
    lv_obj_add_style(obj, &style_bg_image, 0);
    lv_obj_t * image = lv_image_create(obj);
    lv_obj_set_name(image, "image");
    lv_image_set_src(image, lava_cake);
    lv_obj_set_align(image, LV_ALIGN_CENTER);
    widget->image = image;
    
    lv_obj_t * recipe_bg_overlay = lv_obj_create(obj);
    lv_obj_set_name(recipe_bg_overlay, "recipe_bg_overlay");
    lv_obj_set_width(recipe_bg_overlay, lv_pct(100));
    lv_obj_set_height(recipe_bg_overlay, lv_pct(100));
    lv_obj_set_style_bg_opa(recipe_bg_overlay, 140, 0);
    lv_obj_set_style_bg_color(recipe_bg_overlay, lv_color_hex3(0x000), 0);
    lv_obj_set_style_border_width(recipe_bg_overlay, 0, 0);
    lv_obj_set_style_radius(recipe_bg_overlay, 0, 0);
    widget->recipe_bg_overlay = recipe_bg_overlay;


    wd_recipe_bg_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_recipe_bg_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_recipe_bg_destructor_hook(obj);
}

static void wd_recipe_bg_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_recipe_bg_class, e);
    if(res != LV_RESULT_OK) return;

    wd_recipe_bg_event_hook(e);
}

