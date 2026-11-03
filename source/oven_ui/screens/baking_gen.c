/**
 * @file baking_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "baking_gen.h"
#include "oven_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static lv_anim_timeline_t * timeline_open_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * baking_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_baking;
    static lv_style_t style_bell_cont;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_baking);
        lv_style_set_bg_color(&style_baking, lv_color_hex(0x000000));

        lv_style_init(&style_bell_cont);
        lv_style_set_width(&style_bell_cont, LV_SIZE_CONTENT);
        lv_style_set_height(&style_bell_cont, LV_SIZE_CONTENT);
        lv_style_set_radius(&style_bell_cont, 0);
        lv_style_set_bg_opa(&style_bell_cont, 0);
        lv_style_set_border_width(&style_bell_cont, 0);
        lv_style_set_pad_all(&style_bell_cont, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "baking_#");
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_baking, 0);
    lv_obj_t * timer = wd_timer_create(lv_obj_0);
    lv_obj_set_name(timer, "timer");
    lv_obj_set_align(timer, LV_ALIGN_CENTER);
    wd_timer_bind_recipe_title(timer, &subject_recipe_title);
    wd_timer_bind_trigger(timer, &subject_timer_trigger);
    wd_timer_bind_button_stop(timer, &subject_timer_stop);
    wd_timer_bind_button_add(timer, &subject_timer_add);
    wd_timer_bind_3min_view(timer, &subject_timer_3min_view);
    wd_timer_bind_bell_view(timer, &subject_timer_bell_view);
    wd_timer_bind_cook_temperature(timer, &subject_temperature);
    wd_timer_bind_cook_time(timer, &subject_cook_time);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_x(lv_obj_1, 38);
    lv_obj_set_y(lv_obj_1, 369);
    lv_obj_add_style(lv_obj_1, &style_bell_cont, 0);
    lv_obj_bind_flag_if_eq(lv_obj_1, &subject_timer_bell_view, LV_OBJ_FLAG_HIDDEN, 0);
    lv_obj_t * bell_icon = lv_image_create(lv_obj_1);
    lv_obj_set_name(bell_icon, "bell_icon");
    lv_obj_set_style_transform_pivot_x(bell_icon, 31, 0);
    lv_obj_set_style_transform_pivot_y(bell_icon, 5, 0);
    lv_image_set_src(bell_icon, bell_icon);
    
    lv_obj_t * button_0 = button_create(lv_obj_0, "+3 min");
    lv_obj_set_x(button_0, 31);
    lv_obj_set_y(button_0, 362);
    lv_obj_set_state(button_0, LV_STATE_CHECKED, true);
    lv_obj_bind_flag_if_eq(button_0, &subject_timer_3min_view, LV_OBJ_FLAG_HIDDEN, 0);
    lv_obj_add_subject_set_int_event(button_0, &subject_timer_add, LV_EVENT_CLICKED, 1);
    
    lv_obj_t * stop = button_create(lv_obj_0, "Stop");
    lv_obj_set_name(stop, "stop");
    lv_obj_set_x(stop, -31);
    lv_obj_set_y(stop, 362);
    lv_obj_set_align(stop, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_subject_set_int_event(stop, &subject_timer_stop, LV_EVENT_CLICKED, 1);
    lv_obj_bind_flag_if_eq(stop, &subject_timer_bell_view, LV_OBJ_FLAG_HIDDEN, 1);
    lv_obj_add_screen_create_event(stop, LV_EVENT_CLICKED, meals_create, LV_SCREEN_LOAD_ANIM_FADE_IN, SCREEN_CHANGE_SPEED, 0);
    
    lv_obj_add_subject_set_int_event(lv_obj_0, &subject_timer_trigger, LV_EVENT_SCREEN_LOADED, 1);
    lv_obj_t * particle_system = particle_system_create(lv_obj_0);
    lv_obj_set_name(particle_system, "particle_system");
    lv_obj_set_flag(particle_system, LV_OBJ_FLAG_CLICKABLE, false);
    
    
    /* create animation timeline(s) */
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _BAKING_TIMELINE_CNT);
    at_array[BAKING_TIMELINE_OPEN] = timeline_open_create(lv_obj_0);
    lv_obj_set_user_data(lv_obj_0, at_array);
    lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOADED, baking_get_timeline(lv_obj_0, BAKING_TIMELINE_OPEN), 0, false);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

lv_anim_timeline_t * baking_get_timeline(lv_obj_t * obj, baking_timeline_t timeline_id)
{
    if (timeline_id >= _BAKING_TIMELINE_CNT) {
        LV_LOG_WARN("baking has no timeline with %d ID", timeline_id);
        return NULL;
    }

    lv_anim_timeline_t ** at_array = lv_obj_get_user_data(obj);
    return at_array[timeline_id];
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Helper function to execute animations */
static void int_anim_exec_cb(lv_anim_t * a, int32_t v)
{
    uint32_t data = (lv_uintptr_t)lv_anim_get_user_data(a);
    lv_style_prop_t prop = data >> 24;
    lv_style_selector_t selector = data & 0x00ffffff;

    lv_style_value_t style_value;
    style_value.num = v;
    lv_obj_set_local_style_prop(a->var, prop, style_value, selector);
}

static lv_anim_timeline_t * timeline_open_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "timer"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 3000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 500, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "stop"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 3000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 500, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "particle_system"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 3000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 500, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _BAKING_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

