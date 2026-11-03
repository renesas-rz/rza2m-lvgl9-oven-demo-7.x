/**
 * @file wd_timer.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_timer_private_gen.h"
#include "oven_ui.h"

/*********************
 *      DEFINES
 *********************/
#define COOK_TIME_ANIM_TIME_MULT 15
/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    int32_t cook_time; // seconds
    int32_t cook_heat;
    int32_t rem_time;
    bool mode; /* false -> heat up, true -> cooking */
    char * title;
} timer_data_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void title_observer_cb(lv_observer_t *observer, lv_subject_t *subject);
static void time_observer_cb(lv_observer_t *observer, lv_subject_t *subject);
static void temperature_observer_cb(lv_observer_t *observer, lv_subject_t *subject);

static void stop_observer_cb(lv_observer_t *observer, lv_subject_t *subject);
static void add_observer_cb(lv_observer_t *observer, lv_subject_t *subject);
static void trigger_observer_cb(lv_observer_t *observer, lv_subject_t *subject);

static void heat_up_animation_cb(void *var, int32_t value);
static void cooking_animation_cb(void *var, int32_t value);
static void bar_animation_cb(void *var, int32_t value);

static void heat_up_completed_cb(lv_anim_t * a);
static void cooking_completed_cb(lv_anim_t * a);

static void start_heat_up_animation(wd_timer_t * widget, int32_t start, int32_t end, int32_t duration);
static void start_cooking_animation(wd_timer_t * widget, int32_t start, int32_t end, int32_t duration, int32_t delay);
static void start_bar_animation(wd_timer_t * widget, int32_t start, int32_t end, int32_t duration, int32_t delay);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void wd_timer_constructor_hook(lv_obj_t * obj)
{
    wd_timer_t * widget = (wd_timer_t *)obj;
    timer_data_t * timer_data = lv_malloc(sizeof(timer_data_t));
    
    timer_data->cook_time = 150;
    timer_data->cook_heat = 180;
    timer_data->mode = false;
    lv_obj_set_user_data(obj, timer_data);

}

void wd_timer_destructor_hook(lv_obj_t * obj)
{
    wd_timer_t * widget = (wd_timer_t *)obj;
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);
    if (timer_data) {
        if (timer_data->title) {
            lv_free(timer_data->title);
        }
        lv_free(timer_data);
    }
   
}

void wd_timer_event_hook(lv_event_t * e)
{

}

void wd_timer_bind_cook_time(lv_obj_t * wd_timer, lv_subject_t * bind_cook_time)
{
    wd_timer_t * widget = (wd_timer_t *)wd_timer;
    widget->bind_cook_time = bind_cook_time;
    lv_subject_add_observer_obj(widget->bind_cook_time, time_observer_cb, wd_timer, widget);
    int32_t cook_time = lv_subject_get_int(bind_cook_time);
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(wd_timer);
    timer_data->cook_time = cook_time * 60;
}

void wd_timer_bind_cook_temperature(lv_obj_t * wd_timer, lv_subject_t * bind_cook_temperature)
{
    wd_timer_t * widget = (wd_timer_t *)wd_timer;
    widget->bind_cook_temperature = bind_cook_temperature;
    lv_subject_add_observer_obj(widget->bind_cook_temperature, temperature_observer_cb, wd_timer, widget);
    int32_t cook_temperature = lv_subject_get_int(bind_cook_temperature);
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(wd_timer);
    timer_data->cook_heat = cook_temperature;
    lv_label_set_text_fmt(widget->temperature_label, "%d°", cook_temperature);
}

void wd_timer_bind_recipe_title(lv_obj_t * wd_timer, lv_subject_t * bind_recipe_title)
{
    wd_timer_t * widget = (wd_timer_t *)wd_timer;
    widget->bind_recipe_title = bind_recipe_title;
    lv_subject_add_observer_obj(widget->bind_recipe_title, title_observer_cb, wd_timer, widget);
    const char * title = lv_subject_get_string(bind_recipe_title);
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(wd_timer);
    timer_data->title = lv_strdup(title);
    
}

void wd_timer_bind_bell_view(lv_obj_t * wd_timer, lv_subject_t * bind_bell_view)
{
    wd_timer_t * widget = (wd_timer_t *)wd_timer;
    widget->bind_bell_view = bind_bell_view;
}

void wd_timer_bind_3min_view(lv_obj_t * wd_timer, lv_subject_t * bind_3min_view)
{
    wd_timer_t * widget = (wd_timer_t *)wd_timer;
    widget->bind_3min_view = bind_3min_view;
}

void wd_timer_bind_button_stop(lv_obj_t * wd_timer, lv_subject_t * bind_button_stop)
{
    wd_timer_t * widget = (wd_timer_t *)wd_timer;
    widget->bind_button_stop = bind_button_stop;
    lv_subject_add_observer_obj(widget->bind_button_stop, stop_observer_cb, wd_timer, widget);
}

void wd_timer_bind_button_add(lv_obj_t * wd_timer, lv_subject_t * bind_button_add)
{
    wd_timer_t * widget = (wd_timer_t *)wd_timer;
    widget->bind_button_add = bind_button_add;
    lv_subject_add_observer_obj(widget->bind_button_add, add_observer_cb, wd_timer, widget);
}

void wd_timer_bind_trigger(lv_obj_t * wd_timer, lv_subject_t * bind_trigger)
{
    wd_timer_t * widget = (wd_timer_t *)wd_timer;
    widget->bind_trigger = bind_trigger;
    lv_subject_add_observer_obj(widget->bind_trigger, trigger_observer_cb, wd_timer, widget);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void title_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    wd_timer_t * widget = (wd_timer_t *)lv_observer_get_user_data(observer);
    lv_obj_t * obj = (lv_obj_t *)widget;
    const char * title = lv_subject_get_string(subject);
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);
    timer_data->title = lv_strdup(title);

}

static void time_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    wd_timer_t * widget = (wd_timer_t *)lv_observer_get_user_data(observer);
    lv_obj_t * obj = (lv_obj_t *)widget;
    int32_t cook_time = lv_subject_get_int(subject);
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);
    timer_data->cook_time = cook_time * 60;
}

static void temperature_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    wd_timer_t * widget = (wd_timer_t *)lv_observer_get_user_data(observer);
    lv_obj_t * obj = (lv_obj_t *)widget;
    int32_t cook_temperature = lv_subject_get_int(subject);
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);
    timer_data->cook_heat = cook_temperature;
    lv_label_set_text_fmt(widget->temperature_label, "%d°", cook_temperature);
}

static void stop_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    wd_timer_t * widget = (wd_timer_t *)lv_observer_get_user_data(observer);
    lv_obj_t * obj = (lv_obj_t *)widget;
    int32_t value = lv_subject_get_int(subject);
    if (value == 1)
    {
        timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);
        lv_subject_set_int(subject, 0);
    }

}

static void add_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    wd_timer_t * widget = (wd_timer_t *)lv_observer_get_user_data(observer);
    lv_obj_t * obj = (lv_obj_t *)widget;
    int32_t value = lv_subject_get_int(subject);
    if (value == 1)
    {
        timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);
        timer_data->rem_time += 180;

        int32_t rem = (int32_t)((timer_data->rem_time * 100.0) / timer_data->cook_time);

        start_cooking_animation(widget, timer_data->rem_time, 0, timer_data->rem_time * COOK_TIME_ANIM_TIME_MULT, 0);
        start_bar_animation(widget, rem, 0, timer_data->rem_time * COOK_TIME_ANIM_TIME_MULT, 0);

        lv_subject_set_int(subject, 0);
    }

}

static void trigger_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    wd_timer_t * widget = (wd_timer_t *)lv_observer_get_user_data(observer);
    lv_obj_t * obj = (lv_obj_t *)widget;
    int32_t value = lv_subject_get_int(subject);
    if (value == 1)
    {
        timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);
        lv_bar_set_value(widget->progress_bar, 0, false);
        lv_label_set_text_fmt(widget->title_label, "Fast Heat Up to %d°", timer_data->cook_heat);
        start_heat_up_animation(widget, 80, 0, 5000);
        start_bar_animation(widget, 0, 100, 5000, 0);
        lv_subject_set_int(subject, 0);
    }

}

static void heat_up_animation_cb(void *var, int32_t value)
{
    wd_timer_t * widget = (wd_timer_t *)var;
    lv_obj_t * obj = (lv_obj_t *)widget;
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);

    int32_t total = 80;
    int32_t minutes = value / 60;
    int32_t seconds = value % 60;
    int32_t progress = (value * 100) / total;

    int32_t temp = lv_map(value, 80, 0, 80, timer_data->cook_heat);
    lv_label_set_text_fmt(widget->temperature_label, "%d°", temp);

    lv_obj_set_flag(widget->countdown_right, LV_OBJ_FLAG_HIDDEN, true);
    lv_obj_set_state(widget->countdown_left, LV_STATE_CHECKED, false);
    lv_obj_set_state(widget->progress_bar, LV_STATE_CHECKED, true);
    lv_label_set_text_fmt(widget->countdown_left, "%02d:%02d", minutes, seconds);

}

static void cooking_animation_cb(void *var, int32_t value)
{
    wd_timer_t * widget = (wd_timer_t *)var;
    lv_obj_t * obj = (lv_obj_t *)widget;
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);

    int32_t total = timer_data->cook_time;
    int32_t hours = value / 3600;
    int32_t minutes = (value % 3600) / 60;
    int32_t seconds = value % 60;
    
    int32_t progress = (value * 100) / total;

    timer_data->rem_time = value;

    lv_obj_set_flag(widget->countdown_right, LV_OBJ_FLAG_HIDDEN, false);
    lv_obj_set_state(widget->countdown_left, LV_STATE_CHECKED, true);
    lv_obj_set_state(widget->progress_bar, LV_STATE_CHECKED, false);
    lv_obj_set_state(widget->countdown_right, LV_STATE_CHECKED, hours || minutes);
    lv_label_set_text_fmt(widget->countdown_left, "%02d:%02d:", hours, minutes);
    lv_label_set_text_fmt(widget->countdown_right, "%02d", seconds);

    if (widget->bind_bell_view && value != total) {
        lv_subject_set_int(widget->bind_bell_view, 0);
    }

    if (widget->bind_3min_view) {
        lv_subject_set_int(widget->bind_3min_view, hours || minutes ? 0 : seconds == 0 ? 0 : 1);
    }

}

static void bar_animation_cb(void *var, int32_t value)
{
    wd_timer_t * widget = (wd_timer_t *)var;
    lv_obj_t * obj = (lv_obj_t *)widget;
    lv_bar_set_value(widget->progress_bar, value, true);
}

static void heat_up_completed_cb(lv_anim_t * a)
{
    wd_timer_t * widget = (wd_timer_t *)lv_anim_get_user_data(a);
    lv_obj_t * obj = (lv_obj_t *)widget;
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);


    if (widget->bind_bell_view) {
        lv_subject_set_int(widget->bind_bell_view, 1);
    }

    lv_label_set_text_fmt(widget->title_label, "%s is ready in", timer_data->title);

    start_cooking_animation(widget, timer_data->cook_time, 0, timer_data->cook_time * COOK_TIME_ANIM_TIME_MULT, 500);
    start_bar_animation(widget, 100, 0, timer_data->cook_time * COOK_TIME_ANIM_TIME_MULT, 500);
}

static void cooking_completed_cb(lv_anim_t * a)
{
    wd_timer_t * widget = (wd_timer_t *)lv_anim_get_user_data(a);
    lv_obj_t * obj = (lv_obj_t *)widget;
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);

    if (widget->bind_3min_view) {
        lv_subject_set_int(widget->bind_3min_view, 0);
    }
    if (widget->bind_bell_view) {
        lv_subject_set_int(widget->bind_bell_view, 1);
    }

    lv_screen_load_anim(meals_create(), LV_SCREEN_LOAD_ANIM_FADE_IN, 500, 1000, false);
}

static void start_heat_up_animation(wd_timer_t * widget, int32_t start, int32_t end, int32_t duration)
{
    lv_obj_t * obj = (lv_obj_t *)widget;
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, widget);
    lv_anim_set_values(&a, start, end);
    lv_anim_set_time(&a, duration);
    lv_anim_set_exec_cb(&a, heat_up_animation_cb);
    lv_anim_set_completed_cb(&a, heat_up_completed_cb);
    lv_anim_set_user_data(&a, widget);
    lv_anim_start(&a);
}

static void start_cooking_animation(wd_timer_t * widget, int32_t start, int32_t end, int32_t duration, int32_t delay)
{
    lv_obj_t * obj = (lv_obj_t *)widget;
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, widget);
    lv_anim_set_values(&a, start, end);
    lv_anim_set_time(&a, duration);
    lv_anim_set_exec_cb(&a, cooking_animation_cb);
    lv_anim_set_completed_cb(&a, cooking_completed_cb);
    lv_anim_set_user_data(&a, widget);
    lv_anim_set_delay(&a, delay);
    lv_anim_start(&a);
}

static void start_bar_animation(wd_timer_t * widget, int32_t start, int32_t end, int32_t duration, int32_t delay)
{
    lv_obj_t * obj = (lv_obj_t *)widget;
    timer_data_t * timer_data = (timer_data_t *)lv_obj_get_user_data(obj);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, widget);
    lv_anim_set_values(&a, start, end);
    lv_anim_set_time(&a, duration);
    lv_anim_set_exec_cb(&a, bar_animation_cb);
    lv_anim_set_user_data(&a, widget);
    lv_anim_set_delay(&a, delay);
    lv_anim_start(&a);
}