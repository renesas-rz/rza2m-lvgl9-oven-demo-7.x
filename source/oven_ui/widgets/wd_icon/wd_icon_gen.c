/**
 * @file wd_icon_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_icon_private_gen.h"
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

void wd_icon_constructor_hook(lv_obj_t * obj);
void wd_icon_destructor_hook(lv_obj_t * obj);
void wd_icon_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_icon_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_icon_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_icon_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_icon_class = {
    .base_class = &lv_image_class,
    .constructor_cb = wd_icon_constructor,
    .destructor_cb = wd_icon_destructor,
    .event_cb = wd_icon_event,
    .instance_size = sizeof(wd_icon_t),
    .editable = 1,
    .name = "wd_icon"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * wd_icon_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_icon_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void wd_icon_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_icon_t * widget = (wd_icon_t *)obj;
    static lv_style_t style_image_cont;
    static lv_style_t style_image;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_image_cont);
        lv_style_set_width(&style_image_cont, LV_SIZE_CONTENT);
        lv_style_set_height(&style_image_cont, LV_SIZE_CONTENT);

        lv_style_init(&style_image);
        lv_style_set_image_recolor(&style_image, lv_color_hex(0xEEB111));
        lv_style_set_image_recolor_opa(&style_image, 255);

        style_inited = true;
    }
    lv_image_set_src(obj, grill_icon);

    lv_obj_add_style(obj, &style_image_cont, 0);
    lv_obj_add_style(obj, &style_image, LV_STATE_CHECKED);


    wd_icon_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_icon_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_icon_destructor_hook(obj);
}

static void wd_icon_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_icon_class, e);
    if(res != LV_RESULT_OK) return;

    wd_icon_event_hook(e);
}

