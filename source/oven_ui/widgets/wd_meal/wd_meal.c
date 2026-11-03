/**
 * @file wd_meal.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_meal_private_gen.h"
#include "oven_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    int32_t preparation_time;
    int32_t cook_time;
    const char * title;
    const char * description;
    const char * difficulty;
    const char * serves;
    const void * background;
    const char * ingredients;
    const char * steps;
} recipe_data_t;

typedef struct {
    int32_t x_pos;
    int32_t y_pos;
    int32_t bg_x_offset;
} position_data_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void on_scroll_cb(lv_event_t *e);

static void on_navigate_next(lv_event_t *e);
static void on_navigate_previous(lv_event_t *e);

static void on_click_recipe_cb(lv_event_t *e);

static void recipe_item_delete_cb(lv_event_t * e);
static void on_recipe_back_cb(lv_event_t *e);
static void free_user_data_cb(lv_event_t *e);

static void animation_cb(void *var, int32_t value);

static void start_animation(wd_meal_t * widget, int32_t start, int32_t end, int32_t duration);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void wd_meal_constructor_hook(lv_obj_t * obj)
{

    wd_meal_t * widget = (wd_meal_t *)obj;

    lv_obj_clean(widget->meal_cont);

    lv_obj_add_event_cb(widget->meal_cont, on_scroll_cb, LV_EVENT_SCROLL, widget);

    lv_obj_add_event_cb(widget->button_previous, on_navigate_previous, LV_EVENT_CLICKED, widget);
    lv_obj_add_event_cb(widget->button_next, on_navigate_next, LV_EVENT_CLICKED, widget);

    lv_obj_t *recipe_back_button = lv_obj_find_by_name(widget->recipe_info, "recipe_back_button");
    if (recipe_back_button)
    {
        lv_obj_add_event_cb(recipe_back_button, on_recipe_back_cb, LV_EVENT_CLICKED, widget);
    }

    position_data_t * pos_data = lv_malloc(sizeof(position_data_t));
    lv_obj_set_user_data(widget->meal_cont, pos_data);
    lv_obj_add_event_cb(widget->meal_cont, free_user_data_cb, LV_EVENT_DELETE, pos_data);

}

void wd_meal_destructor_hook(lv_obj_t * obj)
{
}

void wd_meal_event_hook(lv_event_t * e)
{

}

void wd_meal_bind_title(lv_obj_t * wd_meal, lv_subject_t * bind_title)
{
    wd_meal_t * widget = (wd_meal_t *)wd_meal;
    widget->bind_title = bind_title;
}

void wd_meal_bind_description(lv_obj_t * wd_meal, lv_subject_t * bind_description)
{
    wd_meal_t * widget = (wd_meal_t *)wd_meal;
    widget->bind_description = bind_description;
}

void wd_meal_bind_difficulty(lv_obj_t * wd_meal, lv_subject_t * bind_difficulty)
{
    wd_meal_t * widget = (wd_meal_t *)wd_meal;
    widget->bind_difficulty = bind_difficulty;
}

void wd_meal_bind_cooking(lv_obj_t * wd_meal, lv_subject_t * bind_cooking)
{
    wd_meal_t * widget = (wd_meal_t *)wd_meal;
    widget->bind_cooking = bind_cooking;
}

void wd_meal_bind_preparation(lv_obj_t * wd_meal, lv_subject_t * bind_preparation)
{
    wd_meal_t * widget = (wd_meal_t *)wd_meal;
    widget->bind_preparation = bind_preparation;
}

void wd_meal_bind_serves(lv_obj_t * wd_meal, lv_subject_t * bind_serves)
{
    wd_meal_t * widget = (wd_meal_t *)wd_meal;
    widget->bind_serves = bind_serves;
}

void wd_meal_bind_ingredients(lv_obj_t * wd_meal, lv_subject_t * bind_ingredients)
{
    wd_meal_t * widget = (wd_meal_t *)wd_meal;
    widget->bind_ingredients = bind_ingredients;
}

void wd_meal_bind_steps(lv_obj_t * wd_meal, lv_subject_t * bind_steps)
{
    wd_meal_t * widget = (wd_meal_t *)wd_meal;
    widget->bind_steps = bind_steps;
}

void wd_meal_bind_cook_time(lv_obj_t * wd_meal, lv_subject_t * bind_cook_time)
{
    wd_meal_t * widget = (wd_meal_t *)wd_meal;
    widget->bind_cook_time = bind_cook_time;
}


lv_obj_t * wd_meal_add_item(lv_obj_t * wd_meal, const char * title, const char * description, const void * background, int32_t preparation_time, int32_t cook_time, const char * serves, const char * difficulty, const char * ingredients, const char * steps)
{
    wd_meal_t * widget = (wd_meal_t *)wd_meal;
    
    char buf[50];
    lv_snprintf(buf, 50, "%d Minutes", cook_time);
    lv_obj_t * recipe_card = recipe_card_create(widget->meal_cont, title, buf, background);

    recipe_data_t * data = lv_malloc(sizeof(recipe_data_t));
    data->title = lv_strdup(title);
    data->description = lv_strdup(description);
    data->serves = lv_strdup(serves);
    data->difficulty = lv_strdup(difficulty);
    data->ingredients = lv_strdup(ingredients);
    data->steps = lv_strdup(steps);
    data->background = background;
    data->preparation_time = preparation_time;
    data->cook_time = cook_time;

    lv_obj_set_user_data(recipe_card, data);

    lv_obj_add_event_cb(recipe_card, on_click_recipe_cb, LV_EVENT_CLICKED, widget);
    lv_obj_add_event_cb(recipe_card, recipe_item_delete_cb, LV_EVENT_DELETE, NULL);

    int32_t count = lv_obj_get_child_count(widget->meal_cont);

    lv_obj_set_state(widget->button_next, LV_STATE_DISABLED, count < 3);

    lv_obj_scroll_by_bounded(widget->meal_cont, -1, 0, LV_ANIM_OFF);

    return recipe_card;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void on_scroll_cb(lv_event_t *e)
{
    wd_meal_t * widget = (wd_meal_t *)lv_event_get_user_data(e);

    int32_t scroll_x = lv_obj_get_scroll_x(widget->meal_cont);

    int32_t opa = lv_map(scroll_x, 0, 141, 255, 0);   /* A2M 800x480: 180 * 25/32 */

    int32_t scroll_r = lv_obj_get_scroll_right(widget->meal_cont);


    lv_obj_set_state(widget->button_previous, LV_STATE_DISABLED, scroll_x < 234);   /* A2M: 300 * 25/32 */
    lv_obj_set_state(widget->button_next, LV_STATE_DISABLED, scroll_r < 23);    /* A2M: 30 * 25/32 */

    lv_obj_set_style_opa(widget->favorite_cont, opa, 0);

 
    /* Parallax effect */
    int32_t count = lv_obj_get_child_count(widget->meal_cont);
    int32_t screen_w = lv_obj_get_width(widget->meal_cont);

    for (int32_t i = 0; i < count; i++) {
        lv_obj_t * cont = lv_obj_get_child(widget->meal_cont, i);
        if (!cont) continue;
        lv_obj_t * bg = lv_obj_get_child(cont, 0);
        if (!bg) continue;

        int32_t cont_w = lv_obj_get_width(cont);
        int32_t bg_w = 391; // lv_obj_get_width(bg);  /* A2M: 500 * 25/32 */


        /* Extra scrollable space of background relative to container */
        int32_t extra = bg_w - cont_w;
        if (extra <= 0) continue; // nothing to parallax

        /* Calculate container center position relative to scroll */
        int32_t cont_center = lv_obj_get_x(cont) + cont_w / 2;
        int32_t widget_center = scroll_x + screen_w / 2;

        // -1.0 = left edge, 0.0 = center, +1.0 = right edge
        float ratio = (float)(cont_center - widget_center) / (float)(screen_w / 2);

        /* Clamp ratio */
        ratio = LV_CLAMP(-5.0f, ratio, 5.0f);


        /* Apply parallax offset */
        int32_t offset = -(int32_t)(ratio * (extra / 2));

        lv_obj_set_x(bg, offset);
    }

}

static void on_navigate_next(lv_event_t *e)
{
    wd_meal_t * widget = (wd_meal_t *)lv_event_get_user_data(e);
    lv_obj_scroll_by_bounded(widget->meal_cont, -250, 0, LV_ANIM_ON);   /* A2M: 320 * 25/32 */
}

static void on_navigate_previous(lv_event_t *e)
{
    wd_meal_t * widget = (wd_meal_t *)lv_event_get_user_data(e);
    lv_obj_scroll_by_bounded(widget->meal_cont, 250, 0, LV_ANIM_ON);    /* A2M: 320 * 25/32 */
}

static void on_click_recipe_cb(lv_event_t *e)
{
    wd_meal_t * widget = (wd_meal_t *)lv_event_get_user_data(e);
    lv_obj_t * obj = lv_event_get_target(e);
    recipe_data_t * data = (recipe_data_t *)lv_obj_get_user_data(obj);
    
    int32_t scroll_x = 266 - lv_obj_get_scroll_x(widget->meal_cont);   /* A2M: 340 * 25/32 */
    int32_t pos = lv_obj_get_x(obj);

    position_data_t * pos_data = (position_data_t *)lv_obj_get_user_data(widget->meal_cont);
    if (pos_data)
    {
        pos_data->x_pos = scroll_x + pos;
    }
    lv_obj_t * bg = lv_obj_get_child(obj, 0);
    if (bg) {
        pos_data->bg_x_offset = lv_obj_get_x_aligned(bg);
    }
    lv_obj_set_x(widget->expanded_image_bg, pos_data->bg_x_offset);

    lv_image_set_src(widget->expanded_image_bg, data->background);

    lv_subject_set_pointer(&subject_recipe_bg, data->background);

    lv_obj_t *recipe_title = lv_obj_find_by_name(widget->recipe_info, "recipe_title");
    if (recipe_title)
    {
        lv_label_set_text(recipe_title, data->title);
    }
    lv_obj_t *recipe_description = lv_obj_find_by_name(widget->recipe_info, "recipe_description");
    if (recipe_description)
    {
        lv_label_set_text(recipe_description, data->description);
    }
    lv_obj_t *recipe_ingredients = lv_obj_find_by_name(widget->recipe_info, "recipe_ingredients");
    if (recipe_ingredients)
    {
        lv_label_set_text(recipe_ingredients, data->ingredients);
    }
    lv_obj_t *recipe_steps = lv_obj_find_by_name(widget->recipe_info, "recipe_steps");
    if (recipe_steps)
    {
        lv_label_set_text(recipe_steps, data->steps);
    }

    if (widget->bind_title) lv_subject_copy_string(widget->bind_title, data->title);
    if (widget->bind_serves) lv_subject_copy_string(widget->bind_serves, data->serves);
    if (widget->bind_difficulty) lv_subject_copy_string(widget->bind_difficulty, data->difficulty);
    
    char buf[50];
    if (widget->bind_preparation) {
        lv_snprintf(buf, 50, "%d Minutes", data->preparation_time);
        lv_subject_copy_string(widget->bind_preparation, buf);
    }

    if (widget->bind_cooking) {
        lv_snprintf(buf, 50, "%d Minutes", data->cook_time);
        lv_subject_copy_string(widget->bind_cooking, buf);
    }

    if (widget->bind_cook_time) {
        lv_subject_set_int(widget->bind_cook_time, data->cook_time);
    }

    lv_obj_t *recipe_scroll_cont = lv_obj_find_by_name(widget->recipe_info, "recipe_scroll_cont");
    if (recipe_scroll_cont)
    {
        lv_obj_scroll_to(recipe_scroll_cont, 0, 0, LV_ANIM_OFF);
    }
    

    start_animation(widget, 0, 512, SCREEN_CHANGE_SPEED);

}

static void recipe_item_delete_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    recipe_data_t * data = (recipe_data_t *)lv_obj_get_user_data(obj);
    if (data) {
        if (data->title) lv_free((void *)data->title);
        if (data->description) lv_free((void *)data->description);
        if (data->difficulty) lv_free((void *)data->difficulty);
        if (data->serves) lv_free((void *)data->serves);
        if (data->ingredients) lv_free((void *)data->ingredients);
        if (data->steps) lv_free((void *)data->steps);
        lv_free(data);
    }
}

static void on_recipe_back_cb(lv_event_t *e)
{
    wd_meal_t * widget = (wd_meal_t *)lv_event_get_user_data(e);
    start_animation(widget, 512, 0, SCREEN_CHANGE_SPEED);
}

static void free_user_data_cb(lv_event_t *e)
{
	lv_free(lv_event_get_user_data(e));
}

static void animation_cb(void *var, int32_t value)
{
    wd_meal_t * widget = (wd_meal_t *)var;
    int32_t v1 = LV_CLAMP(0, value, 255);
    lv_obj_set_flag(widget->expanded_cont, LV_OBJ_FLAG_HIDDEN, value == 0);
    lv_obj_set_flag(widget->select_button, LV_OBJ_FLAG_HIDDEN, v1 < 254);
    int32_t x_offset = lv_map(value, 0, 512, -391, 0);   /* A2M: 500 * 25/32 */
    lv_obj_set_x(widget->recipe_info, x_offset);

    //lv_obj_set_style_opa(widget->expanded_image_cont, v1, 0);

    position_data_t * pos_data = (position_data_t *)lv_obj_get_user_data(widget->meal_cont);
    int32_t saved_x = 266;   /* A2M: 340 * 25/32 */
    int32_t saved_bg_x = 0;
    if (pos_data)
    {
        saved_x = pos_data->x_pos;
        saved_bg_x = pos_data->bg_x_offset;
    }

    int32_t width = lv_map(v1, 0, 255, 234, 800);    /* A2M: card 300->234, full width 1024->800 */
    int32_t height = lv_map(v1, 0, 255, 375, 480);   /* A2M: card 480->375, full height 600->480 */
    int32_t radius = lv_map(v1, 0, 255, 47, 0);      /* A2M: 60 * 25/32 */
    int32_t x_pos = lv_map(v1, 0, 255, saved_x, 0);
    int32_t y_pos = lv_map(v1, 0, 255, 31, 0);       /* A2M: 40 * 25/32 */
    int32_t bg_x = lv_map(v1, 0, 255, saved_bg_x, 0);

    lv_obj_set_pos(widget->expanded_image_cont, x_pos, y_pos);
    lv_obj_set_size(widget->expanded_image_cont, width, height);
    //lv_obj_set_style_radius(widget->expanded_image_cont, radius, 0);

    lv_obj_set_x(widget->expanded_image_bg, bg_x);

}

static void start_animation(wd_meal_t * widget, int32_t start, int32_t end, int32_t duration)
{
    static lv_anim_t anim;
    lv_anim_init(&anim);
    lv_anim_set_exec_cb(&anim, animation_cb);
    lv_anim_set_var(&anim, widget);
    lv_anim_set_duration(&anim, duration);
    lv_anim_set_values(&anim, start, end);
    lv_anim_set_path_cb(&anim, lv_anim_path_ease_in_out);
    lv_anim_start(&anim);
}
