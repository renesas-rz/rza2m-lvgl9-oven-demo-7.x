/**
 * @file wd_meal_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_meal_gen.h"

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

void * wd_meal_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = wd_meal_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create wd_meal");
        return NULL;
    }

    return item;
}

void wd_meal_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];
        if(lv_streq("bind_title", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_meal bind_title", value);
                continue;
            }
            wd_meal_bind_title(item, subject);
        }
        if(lv_streq("bind_description", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_meal bind_description", value);
                continue;
            }
            wd_meal_bind_description(item, subject);
        }
        if(lv_streq("bind_difficulty", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_meal bind_difficulty", value);
                continue;
            }
            wd_meal_bind_difficulty(item, subject);
        }
        if(lv_streq("bind_cooking", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_meal bind_cooking", value);
                continue;
            }
            wd_meal_bind_cooking(item, subject);
        }
        if(lv_streq("bind_preparation", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_meal bind_preparation", value);
                continue;
            }
            wd_meal_bind_preparation(item, subject);
        }
        if(lv_streq("bind_serves", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_meal bind_serves", value);
                continue;
            }
            wd_meal_bind_serves(item, subject);
        }
        if(lv_streq("bind_ingredients", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_meal bind_ingredients", value);
                continue;
            }
            wd_meal_bind_ingredients(item, subject);
        }
        if(lv_streq("bind_steps", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_meal bind_steps", value);
                continue;
            }
            wd_meal_bind_steps(item, subject);
        }
        if(lv_streq("bind_cook_time", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_meal bind_cook_time", value);
                continue;
            }
            wd_meal_bind_cook_time(item, subject);
        }
    }
}

void * wd_meal_item_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = lv_xml_state_get_parent(state);

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create wd_meal");
        return NULL;
    }

    const char * title = lv_xml_get_value_of(attrs, "title");
    const char * description = lv_xml_get_value_of(attrs, "description");
    const void * background = lv_xml_get_image(&state->scope, lv_xml_get_value_of(attrs, "background"));
    int32_t preparation_time = lv_xml_atoi(lv_xml_get_value_of(attrs, "preparation_time"));
    int32_t cook_time = lv_xml_atoi(lv_xml_get_value_of(attrs, "cook_time"));
    const char * serves = lv_xml_get_value_of(attrs, "serves");
    const char * difficulty = lv_xml_get_value_of(attrs, "difficulty");
    const char * ingredients = lv_xml_get_value_of(attrs, "ingredients");
    const char * steps = lv_xml_get_value_of(attrs, "steps");

    return wd_meal_add_item(item, title, description, background, preparation_time, cook_time, serves, difficulty, ingredients, steps);
}

void wd_meal_item_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * parent_item = lv_xml_state_get_parent(state);
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];
    }
}

void wd_meal_register(void)
{
    lv_xml_register_widget("wd_meal", wd_meal_xml_create, wd_meal_xml_apply);
    lv_xml_register_widget("wd_meal-item", wd_meal_item_xml_create, wd_meal_item_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */