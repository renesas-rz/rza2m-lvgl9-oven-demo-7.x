/**
 * @file wd_timer_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_timer_gen.h"

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "src/lvgl_private.h"
#else
    #include "lvgl/src/lvgl_private.h"
#endif

#if LV_USE_XML

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void * wd_timer_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = wd_timer_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create wd_timer");
        return NULL;
    }

    return item;
}

void wd_timer_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];


        if(lv_streq("bind_cook_time", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_timer bind_cook_time", value);
                continue;
            }
            wd_timer_bind_cook_time(item, subject);
        }
        if(lv_streq("bind_cook_temperature", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_timer bind_cook_temperature", value);
                continue;
            }
            wd_timer_bind_cook_temperature(item, subject);
        }
        if(lv_streq("bind_recipe_title", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_timer bind_recipe_title", value);
                continue;
            }
            wd_timer_bind_recipe_title(item, subject);
        }

        if(lv_streq("bind_button_stop", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_timer bind_button_stop", value);
                continue;
            }
            wd_timer_bind_button_stop(item, subject);
        }
        if(lv_streq("bind_button_add", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_timer bind_button_add", value);
                continue;
            }
            wd_timer_bind_button_add(item, subject);
        }
        if(lv_streq("bind_bell_view", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_timer bind_bell_view", value);
                continue;
            }
            wd_timer_bind_bell_view(item, subject);
        }
        if(lv_streq("bind_3min_view", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_timer bind_3min_view", value);
                continue;
            }
            wd_timer_bind_3min_view(item, subject);
        }
        if(lv_streq("bind_trigger", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_timer bind_trigger", value);
                continue;
            }
            wd_timer_bind_trigger(item, subject);
        }
    }
}

void wd_timer_register(void)
{
    lv_xml_register_widget("wd_timer", wd_timer_xml_create, wd_timer_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */