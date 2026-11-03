/**
 * @file oven_ui.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "oven_ui.h"
#include "lvgl_private.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void cook_timer_observer_cb(lv_observer_t *observer, lv_subject_t *subject);
static void info_observer_cb(lv_observer_t *observer, lv_subject_t *subject);
static lv_obj_t * perf_live_label;   /* A2M: live FPS/CPU line in the performance sidebar */

/**********************
 *  STATIC VARIABLES
 **********************/

lv_subject_t subject_recipe_bg;
lv_subject_t subject_cook_mode_icon;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void oven_ui_init(const char * asset_path)
{

    oven_ui_init_gen(asset_path);

    lv_subject_init_pointer(&subject_recipe_bg, vegetable);
    lv_subject_init_pointer(&subject_cook_mode_icon, grill_icon);

#if LV_USE_XML
    lv_xml_register_subject(NULL, "subject_recipe_bg", &subject_recipe_bg);
    lv_xml_register_subject(NULL, "subject_cook_mode_icon", &subject_cook_mode_icon);
#endif /* LV_USE_XML */

    lv_obj_remove_flag(lv_layer_top(), LV_OBJ_FLAG_SCROLLABLE);

    lv_observer_t * cook_timer_observer = lv_subject_add_observer(&subject_cook_time, cook_timer_observer_cb, NULL);

    /* Add your own custom code here if needed */
    lv_obj_set_style_bg_opa(lv_layer_bottom(), 0, 0);
    lv_obj_t * perf_sidebar = performance_sidebar_create(lv_layer_top());
    lv_obj_align(perf_sidebar, LV_ALIGN_RIGHT_MID, 0, 0);
    perf_live_label = lv_obj_find_by_name(perf_sidebar, "perf_live");
    lv_obj_t * perf_button = performance_button_create(lv_layer_top());
    lv_obj_align(perf_button, LV_ALIGN_TOP_RIGHT, 3, 3);

#if !defined(LV_EDITOR_PREVIEW)
    lv_style_set_blur_radius(&style_blur, 50);
    lv_style_set_blur_backdrop(&style_blur, true);
#endif

    lv_obj_t * info_label = lv_label_create(lv_layer_top());
    lv_obj_set_width(info_label, 104);   /* A2M: wide enough for "CPU: 100%" at the 16 px font */
    lv_obj_set_style_bg_color(info_label, lv_color_hex(0xEEB111), 0);
    lv_obj_set_style_bg_opa(info_label, 255, 0);
    lv_obj_set_style_pad_all(info_label, 8, 0);
    lv_obj_set_style_pad_bottom(info_label, 16, 0);
    lv_obj_set_style_text_font(info_label, Roboto_Regular_20, 0);
    lv_obj_set_style_text_color(info_label, lv_color_white(), 0);
    lv_obj_set_style_radius(info_label, 5, 0);
    lv_obj_align(info_label, LV_ALIGN_BOTTOM_MID, 0, 9);

    lv_display_t * disp = lv_display_get_default();
    lv_subject_add_observer_obj(&disp->perf_sysmon_backend.subject, info_observer_cb, info_label, NULL);

    lv_obj_set_style_bg_opa(lv_layer_bottom(), 0, 0);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

void make_non_clickable_cb(lv_event_t * e)
{
    lv_obj_remove_flag(lv_event_get_target(e), LV_OBJ_FLAG_CLICKABLE);
}

static void cook_timer_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    int32_t cook_time = lv_subject_get_int(subject);
    /* Handle cook time changes here */
    int32_t hour = cook_time / 60;
    int32_t minute = cook_time % 60;

    char buf[10];
    lv_snprintf(buf, sizeof(buf), "%02dh %02dm", hour, minute);
    lv_subject_copy_string(&subject_cook_time_fmt, buf);
}

static void info_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    /* A2M: show frames actually rendered per second, not LVGL refresh cycles.
     * LVGL's calculated.fps counts every refresh period (~60/s) even when nothing is drawn.
     * render_cnt counts real redraws; the report timestamp is still the previous one here. */
    const lv_sysmon_perf_info_t * perf = lv_subject_get_pointer(subject);
    uint32_t elaps = lv_tick_elaps(perf->measured.last_report_timestamp);
    uint32_t fps = elaps ? (perf->measured.render_cnt * 1000 + elaps / 2) / elaps : 0;
    uint32_t cpu = perf->calculated.cpu;   /* system-wide CPU from /proc/stat (lv_os_get_idle_percent) */

    static uint32_t fps_sum = 0, cpu_sum = 0, samples = 0;
    fps_sum += fps; cpu_sum += cpu; samples++;

    lv_label_set_text_fmt(lv_observer_get_target_obj(observer),
    		"FPS: %d\n"
    		"CPU: %d%%",
			(int)fps, (int)cpu);

    if(perf_live_label) {
        lv_label_set_text_fmt(perf_live_label,
            "\xe2\x80\xa2 FPS (frames drawn): %d\n"
            "\xe2\x80\xa2 CPU load (system): %d%%\n"
            "\xe2\x80\xa2 Average since start: %d FPS, %d%% CPU\n"
            "\xe2\x80\xa2 LVGL render, 800x480 RGB565",
            (int)fps, (int)cpu, (int)(fps_sum / samples), (int)(cpu_sum / samples));
    }
}

