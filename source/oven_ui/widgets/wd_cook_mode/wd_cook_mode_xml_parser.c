/**
 * @file wd_cook_mode_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_cook_mode_gen.h"

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

void * wd_cook_mode_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = wd_cook_mode_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create wd_cook_mode");
        return NULL;
    }

    return item;
}

void wd_cook_mode_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq("bind_cook_mode", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_cook_mode bind_cook_mode", value);
                continue;
            }
            wd_cook_mode_bind_cook_mode(item, subject);
        }
        if(lv_streq("bind_button_set", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_cook_mode bind_button_set", value);
                continue;
            }
            wd_cook_mode_bind_button_set(item, subject);
        }
    }
}

void wd_cook_mode_register(void)
{
    lv_xml_register_widget("wd_cook_mode", wd_cook_mode_xml_create, wd_cook_mode_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */