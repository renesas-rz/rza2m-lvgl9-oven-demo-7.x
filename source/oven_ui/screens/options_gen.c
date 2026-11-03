/**
 * @file options_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "options_gen.h"
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
static lv_anim_timeline_t * timeline_close_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * options_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_options;
    static lv_style_t style_row;
    static lv_style_t style_column;
    static lv_style_t style_roller;
    static lv_style_t style_roller_selected;
    static lv_style_t style_overlay;
    static lv_style_t style_button_set;
    static lv_style_t style_bar;
    static lv_style_t style_button_click;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_options);
        lv_style_set_bg_opa(&style_options, 0);

        lv_style_init(&style_row);
        lv_style_set_width(&style_row, LV_SIZE_CONTENT);
        lv_style_set_height(&style_row, LV_SIZE_CONTENT);
        lv_style_set_bg_opa(&style_row, 0);
        lv_style_set_radius(&style_row, 0);
        lv_style_set_pad_all(&style_row, 0);
        lv_style_set_pad_right(&style_row, 31);
        lv_style_set_pad_left(&style_row, 31);
        lv_style_set_border_width(&style_row, 0);
        lv_style_set_layout(&style_row, LV_LAYOUT_FLEX);
        lv_style_set_flex_main_place(&style_row, LV_FLEX_ALIGN_SPACE_BETWEEN);

        lv_style_init(&style_column);
        lv_style_set_width(&style_column, LV_SIZE_CONTENT);
        lv_style_set_height(&style_column, LV_SIZE_CONTENT);
        lv_style_set_pad_all(&style_column, 0);
        lv_style_set_pad_row(&style_column, 22);
        lv_style_set_bg_opa(&style_column, 0);
        lv_style_set_layout(&style_column, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_column, LV_FLEX_FLOW_COLUMN);
        lv_style_set_text_font(&style_column, Roboto_Medium_30);
        lv_style_set_text_color(&style_column, lv_color_hex(0xFFFFFF));
        lv_style_set_radius(&style_column, 0);
        lv_style_set_border_width(&style_column, 0);

        lv_style_init(&style_roller);
        lv_style_set_width(&style_roller, 231);
        lv_style_set_height(&style_roller, 480);
        lv_style_set_bg_color(&style_roller, lv_color_hex(0xEEB111));
        lv_style_set_radius(&style_roller, 0);
        lv_style_set_border_width(&style_roller, 0);
        lv_style_set_text_color(&style_roller, lv_color_hex(0xececec));
        lv_style_set_text_font(&style_roller, Roboto_Medium_100);
        lv_style_set_pad_all(&style_roller, 0);

        lv_style_init(&style_roller_selected);
        lv_style_set_height(&style_roller_selected, 88);
        lv_style_set_bg_opa(&style_roller_selected, 0);
        lv_style_set_border_width(&style_roller_selected, 6);
        lv_style_set_border_color(&style_roller_selected, lv_color_hex(0xFFFFFF));
        lv_style_set_border_side(&style_roller_selected, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_text_color(&style_roller_selected, lv_color_hex(0xFFFFFF));

        lv_style_init(&style_overlay);
        lv_style_set_width(&style_overlay, lv_pct(100));
        lv_style_set_height(&style_overlay, lv_pct(100));
        lv_style_set_radius(&style_overlay, 0);
        lv_style_set_border_width(&style_overlay, 0);
        lv_style_set_bg_color(&style_overlay, lv_color_hex(0x000000));
        lv_style_set_bg_opa(&style_overlay, 150);
        lv_style_set_pad_all(&style_overlay, 0);

        lv_style_init(&style_button_set);
        lv_style_set_width(&style_button_set, 163);
        lv_style_set_height(&style_button_set, 50);
        lv_style_set_border_width(&style_button_set, 0);
        lv_style_set_radius(&style_button_set, 6);
        lv_style_set_text_font(&style_button_set, Roboto_Medium_30);
        lv_style_set_pad_all(&style_button_set, 0);
        lv_style_set_shadow_width(&style_button_set, 39);
        lv_style_set_shadow_spread(&style_button_set, 39);
        lv_style_set_shadow_color(&style_button_set, lv_color_hex(0xEEB111));

        lv_style_init(&style_bar);
        lv_style_set_width(&style_bar, lv_pct(100));
        lv_style_set_height(&style_bar, 6);
        lv_style_set_radius(&style_bar, 0);
        lv_style_set_border_width(&style_bar, 0);
        lv_style_set_bg_color(&style_bar, lv_color_hex(0xFFFFFF));
        lv_style_set_pad_all(&style_bar, 0);

        lv_style_init(&style_button_click);
        lv_style_set_bg_color(&style_button_click, lv_color_hex(0xf6cb5f));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "options_#");
    lv_obj_set_style_bg_opa(lv_obj_0, 0, 0);

    lv_obj_t * wd_recipe_bg_0 = wd_recipe_bg_create(lv_obj_0);
    
    lv_obj_t * turn_on = button_create(lv_obj_0, "Turn on");
    lv_obj_set_name(turn_on, "turn_on");
    lv_obj_set_x(turn_on, -31);
    lv_obj_set_y(turn_on, 362);
    lv_obj_set_align(turn_on, LV_ALIGN_TOP_RIGHT);
    lv_obj_bind_flag_if_eq(turn_on, &subject_roller_view, LV_OBJ_FLAG_HIDDEN, 1);
    lv_obj_bind_flag_if_eq(turn_on, &subject_cook_mode_view, LV_OBJ_FLAG_HIDDEN, 1);
    lv_obj_bind_flag_if_eq(turn_on, &subject_time_view, LV_OBJ_FLAG_HIDDEN, 1);
    lv_obj_add_screen_create_event(turn_on, LV_EVENT_CLICKED, baking_create, LV_SCREEN_LOAD_ANIM_FADE_IN, 0, 1000);
    lv_obj_add_event_cb(turn_on, make_non_clickable_cb, LV_EVENT_CLICKED, NULL);
    
    lv_obj_t * main_row = lv_obj_create(lv_obj_0);
    lv_obj_set_width(main_row, lv_pct(100));
    lv_obj_set_y(main_row, 152);
    lv_obj_set_name(main_row, "main_row");
    lv_obj_add_style(main_row, &style_row, 0);
    lv_obj_t * lv_obj_1 = lv_obj_create(main_row);
    lv_obj_add_style(lv_obj_1, &style_column, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_0, "Function");
    
    lv_obj_t * wd_icon_0 = wd_icon_create(lv_obj_1);
    lv_obj_set_state(wd_icon_0, LV_STATE_CHECKED, true);
    
    lv_obj_add_subject_set_int_event(lv_obj_1, &subject_cook_mode_view, LV_EVENT_CLICKED, 1);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(main_row);
    lv_obj_add_style(lv_obj_2, &style_column, 0);
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_1, "Temperature");
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_2, "190°");
    lv_label_bind_text(lv_label_2, &subject_temperature, "%d°");
    lv_obj_set_style_text_font(lv_label_2, Roboto_Medium_100, 0);
    lv_obj_set_style_pad_top(lv_label_2, 0, 0);
    lv_obj_set_style_pad_bottom(lv_label_2, 0, 0);
    
    lv_obj_add_subject_set_int_event(lv_obj_2, &subject_roller_view, LV_EVENT_CLICKED, 1);
    
    lv_obj_t * lv_obj_3 = lv_obj_create(main_row);
    lv_obj_add_style(lv_obj_3, &style_column, 0);
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_3, "Timer");
    
    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_4, "00h 30m");
    lv_label_bind_text(lv_label_4, &subject_cook_time_fmt, NULL);
    lv_obj_set_style_text_font(lv_label_4, Roboto_Medium_100, 0);
    
    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_5, "Oven will turn off when timer ends.");
    lv_obj_set_style_text_font(lv_label_5, Roboto_Regular_20, 0);
    lv_obj_set_style_pad_top(lv_label_5, -4, 0);
    
    lv_obj_add_subject_set_int_event(lv_obj_3, &subject_time_view, LV_EVENT_CLICKED, 1);
    
    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_0);
    lv_obj_add_style(lv_obj_4, &style_overlay, 0);
    lv_obj_bind_flag_if_eq(lv_obj_4, &subject_roller_view, LV_OBJ_FLAG_HIDDEN, 0);
    lv_obj_t * wd_roller_0 = wd_roller_create(lv_obj_4);
    lv_obj_set_x(wd_roller_0, 176);
    wd_roller_bind_temperature(wd_roller_0, &subject_temperature);
    wd_roller_bind_button_set(wd_roller_0, &subject_roller_view);
    
    lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_0);
    lv_obj_add_style(lv_obj_5, &style_overlay, 0);
    lv_obj_bind_flag_if_eq(lv_obj_5, &subject_cook_mode_view, LV_OBJ_FLAG_HIDDEN, 0);
    lv_obj_t * wd_cook_mode_0 = wd_cook_mode_create(lv_obj_5);
    wd_cook_mode_bind_button_set(wd_cook_mode_0, &subject_cook_mode_view);
    
    lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_0);
    lv_obj_add_style(lv_obj_6, &style_overlay, 0);
    lv_obj_bind_flag_if_eq(lv_obj_6, &subject_time_view, LV_OBJ_FLAG_HIDDEN, 0);
    lv_obj_t * wd_time_selector_0 = wd_time_selector_create(lv_obj_6);
    lv_obj_set_align(wd_time_selector_0, LV_ALIGN_TOP_RIGHT);
    wd_time_selector_bind_time(wd_time_selector_0, &subject_cook_time);
    wd_time_selector_bind_button_set(wd_time_selector_0, &subject_time_view);
    
    
    /* create animation timeline(s) */
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _OPTIONS_TIMELINE_CNT);
    at_array[OPTIONS_TIMELINE_OPEN] = timeline_open_create(lv_obj_0);
    at_array[OPTIONS_TIMELINE_CLOSE] = timeline_close_create(lv_obj_0);
    lv_obj_set_user_data(lv_obj_0, at_array);
    lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOADED, options_get_timeline(lv_obj_0, OPTIONS_TIMELINE_OPEN), 0, false);
    lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_UNLOAD_START, options_get_timeline(lv_obj_0, OPTIONS_TIMELINE_CLOSE), 0, false);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

lv_anim_timeline_t * options_get_timeline(lv_obj_t * obj, options_timeline_t timeline_id)
{
    if (timeline_id >= _OPTIONS_TIMELINE_CNT) {
        LV_LOG_WARN("options has no timeline with %d ID", timeline_id);
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
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "recipe_bg_overlay"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, SCREEN_CHANGE_SPEED);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "main_row"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, SCREEN_CHANGE_SPEED);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "main_row"));
    lv_anim_set_values(&a, -20, 0);
    lv_anim_set_duration(&a, SCREEN_CHANGE_SPEED);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "turn_on"));
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, SCREEN_CHANGE_SPEED);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "turn_on"));
    lv_anim_set_values(&a, 20, 0);
    lv_anim_set_duration(&a, SCREEN_CHANGE_SPEED);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    return at;
}

static lv_anim_timeline_t * timeline_close_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;

    selector_and_prop = ((LV_STYLE_BG_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "recipe_bg_overlay"));
    lv_anim_set_values(&a, 140, 255);
    lv_anim_set_duration(&a, 1000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "main_row"));
    lv_anim_set_values(&a, 255, 0);
    lv_anim_set_duration(&a, SCREEN_CHANGE_SPEED);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "turn_on"));
    lv_anim_set_values(&a, 255, 0);
    lv_anim_set_duration(&a, SCREEN_CHANGE_SPEED);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _OPTIONS_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

