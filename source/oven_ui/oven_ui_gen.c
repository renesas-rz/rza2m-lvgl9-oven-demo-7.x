/**
 * @file oven_ui_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "oven_ui_gen.h"

#if LV_USE_XML
#include "widgets/particle_system/particle_system_private_gen.h"
#include "widgets/wd_cook_mode/wd_cook_mode_private_gen.h"
#include "widgets/wd_icon/wd_icon_private_gen.h"
#include "widgets/wd_meal/wd_meal_private_gen.h"
#include "widgets/wd_recipe_bg/wd_recipe_bg_private_gen.h"
#include "widgets/wd_roller/wd_roller_private_gen.h"
#include "widgets/wd_time_selector/wd_time_selector_private_gen.h"
#include "widgets/wd_timer/wd_timer_private_gen.h"
#endif /* LV_USE_XML */

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

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * Roboto_Regular_15;
extern lv_font_t Roboto_Regular_15_data;
lv_font_t * Roboto_Regular_20;
extern lv_font_t Roboto_Regular_20_data;
lv_font_t * Roboto_Medium_15;
extern lv_font_t Roboto_Medium_15_data;
lv_font_t * Roboto_Medium_30;
extern lv_font_t Roboto_Medium_30_data;
lv_font_t * Roboto_Medium_40;
extern lv_font_t Roboto_Medium_40_data;
lv_font_t * Roboto_Medium_50;
extern lv_font_t Roboto_Medium_50_data;
lv_font_t * Roboto_Medium_100;
extern lv_font_t Roboto_Medium_100_data;
lv_font_t * Roboto_Medium_160;
extern lv_font_t Roboto_Medium_160_data;
lv_font_t * Roboto_Bold_15;
extern lv_font_t Roboto_Bold_15_data;

/*----------------
 * Images
 *----------------*/

const void * clock_small_icon;
extern const void * clock_small_icon_data;
const void * clock_icon;
extern const void * clock_icon_data;
const void * heat_icon;
extern const void * heat_icon_data;
const void * back_icon;
extern const void * back_icon_data;
const void * perf_icon;
extern const void * perf_icon_data;
const void * grill_icon;
extern const void * grill_icon_data;
const void * bottom_heat_icon;
extern const void * bottom_heat_icon_data;
const void * conventional_icon;
extern const void * conventional_icon_data;
const void * defrost_icon;
extern const void * defrost_icon_data;
const void * true_fan_icon;
extern const void * true_fan_icon_data;
const void * moist_fan_icon;
extern const void * moist_fan_icon_data;
const void * turbo_grill_icon;
extern const void * turbo_grill_icon_data;
const void * arrow_icon;
extern const void * arrow_icon_data;
const void * saved_icon;
extern const void * saved_icon_data;
const void * serving_icon;
extern const void * serving_icon_data;
const void * preparation_icon;
extern const void * preparation_icon_data;
const void * difficulty_icon;
extern const void * difficulty_icon_data;
const void * bell_icon;
extern const void * bell_icon_data;
const void * ganoush_bg;
extern const void * ganoush_bg_data;
const void * lava_cake;
extern const void * lava_cake_data;
const void * salmon;
extern const void * salmon_data;
const void * vegetable;
extern const void * vegetable_data;
const void * pizza;
extern const void * pizza_data;
const void * chicken;
extern const void * chicken_data;
const void * fire_sparks;
extern const void * fire_sparks_data;
const void * spark1;
extern const void * spark1_data;
const void * spark2;
extern const void * spark2_data;
const void * perf_button_image;
extern const void * perf_button_image_data;
const void * close_button_image;
extern const void * close_button_image_data;
const void * whirlpool_logo;
extern const void * whirlpool_logo_data;

/*----------------
 * Global styles
 *----------------*/

lv_style_t style_blur;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_roller_view;
lv_subject_t subject_meal_view;
lv_subject_t subject_cook_mode_view;
lv_subject_t subject_time_view;
lv_subject_t subject_temperature;
lv_subject_t subject_cook_time;
lv_subject_t subject_cook_time_fmt;
lv_subject_t subject_timer_trigger;
lv_subject_t subject_timer_stop;
lv_subject_t subject_timer_add;
lv_subject_t subject_timer_bell_view;
lv_subject_t subject_timer_3min_view;
lv_subject_t subject_show_perf_sidebar;
lv_subject_t subject_gpu_enable;
lv_subject_t subject_recipe_prep_time;
lv_subject_t subject_recipe_cook_time;
lv_subject_t subject_recipe_serves;
lv_subject_t subject_recipe_ability;
lv_subject_t subject_recipe_title;
lv_subject_t subject_recipe_description;
lv_subject_t subject_recipe_ingredients;
lv_subject_t subject_recipe_steps;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void oven_ui_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Fonts
     *----------------*/

    /* get font 'Roboto_Regular_15' from a C array */
    Roboto_Regular_15 = &Roboto_Regular_15_data;
    /* get font 'Roboto_Regular_20' from a C array */
    Roboto_Regular_20 = &Roboto_Regular_20_data;
    /* get font 'Roboto_Medium_15' from a C array */
    Roboto_Medium_15 = &Roboto_Medium_15_data;
    /* get font 'Roboto_Medium_30' from a C array */
    Roboto_Medium_30 = &Roboto_Medium_30_data;
    /* get font 'Roboto_Medium_40' from a C array */
    Roboto_Medium_40 = &Roboto_Medium_40_data;
    /* get font 'Roboto_Medium_50' from a C array */
    Roboto_Medium_50 = &Roboto_Medium_50_data;
    /* get font 'Roboto_Medium_100' from a C array */
    Roboto_Medium_100 = &Roboto_Medium_100_data;
    /* get font 'Roboto_Medium_160' from a C array */
    Roboto_Medium_160 = &Roboto_Medium_160_data;
    /* get font 'Roboto_Bold_15' from a C array */
    Roboto_Bold_15 = &Roboto_Bold_15_data;


    /*----------------
     * Images
     *----------------*/
    clock_small_icon = &clock_small_icon_data;
    clock_icon = &clock_icon_data;
    heat_icon = &heat_icon_data;
    back_icon = &back_icon_data;
    perf_icon = &perf_icon_data;
    grill_icon = &grill_icon_data;
    bottom_heat_icon = &bottom_heat_icon_data;
    conventional_icon = &conventional_icon_data;
    defrost_icon = &defrost_icon_data;
    true_fan_icon = &true_fan_icon_data;
    moist_fan_icon = &moist_fan_icon_data;
    turbo_grill_icon = &turbo_grill_icon_data;
    arrow_icon = &arrow_icon_data;
    saved_icon = &saved_icon_data;
    serving_icon = &serving_icon_data;
    preparation_icon = &preparation_icon_data;
    difficulty_icon = &difficulty_icon_data;
    bell_icon = &bell_icon_data;
    ganoush_bg = &ganoush_bg_data;
    lava_cake = &lava_cake_data;
    salmon = &salmon_data;
    vegetable = &vegetable_data;
    pizza = &pizza_data;
    chicken = &chicken_data;
    fire_sparks = &fire_sparks_data;
    spark1 = &spark1_data;
    spark2 = &spark2_data;
    perf_button_image = &perf_button_image_data;
    close_button_image = &close_button_image_data;
    whirlpool_logo = &whirlpool_logo_data;

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_blur);

        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&subject_roller_view, 0);
    lv_subject_set_min_value_int(&subject_roller_view, 0);
    lv_subject_set_max_value_int(&subject_roller_view, 1);
    lv_subject_init_int(&subject_meal_view, 0);
    lv_subject_set_min_value_int(&subject_meal_view, 0);
    lv_subject_set_max_value_int(&subject_meal_view, 1);
    lv_subject_init_int(&subject_cook_mode_view, 0);
    lv_subject_set_min_value_int(&subject_cook_mode_view, 0);
    lv_subject_set_max_value_int(&subject_cook_mode_view, 1);
    lv_subject_init_int(&subject_time_view, 0);
    lv_subject_set_min_value_int(&subject_time_view, 0);
    lv_subject_set_max_value_int(&subject_time_view, 1);
    lv_subject_init_int(&subject_temperature, 190);
    lv_subject_init_int(&subject_cook_time, 160);
    static char subject_cook_time_fmt_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_cook_time_fmt_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_cook_time_fmt,
                           subject_cook_time_fmt_buf,
                           subject_cook_time_fmt_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "02h 40m"
                          );
    lv_subject_init_int(&subject_timer_trigger, 0);
    lv_subject_init_int(&subject_timer_stop, 0);
    lv_subject_init_int(&subject_timer_add, 0);
    lv_subject_init_int(&subject_timer_bell_view, 0);
    lv_subject_init_int(&subject_timer_3min_view, 0);
    lv_subject_init_int(&subject_show_perf_sidebar, 0);
    lv_subject_init_int(&subject_gpu_enable, 1);   /* GPU on (main.c: OVEN_GPU=0 to start off) */
    static char subject_recipe_prep_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_recipe_prep_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_recipe_prep_time,
                           subject_recipe_prep_time_buf,
                           subject_recipe_prep_time_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "25 minutes"
                          );
    static char subject_recipe_cook_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_recipe_cook_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_recipe_cook_time,
                           subject_recipe_cook_time_buf,
                           subject_recipe_cook_time_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "15 minutes"
                          );
    static char subject_recipe_serves_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_recipe_serves_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_recipe_serves,
                           subject_recipe_serves_buf,
                           subject_recipe_serves_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "4 people"
                          );
    static char subject_recipe_ability_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_recipe_ability_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_recipe_ability,
                           subject_recipe_ability_buf,
                           subject_recipe_ability_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Easy"
                          );
    static char subject_recipe_title_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_recipe_title_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_recipe_title,
                           subject_recipe_title_buf,
                           subject_recipe_title_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Baba Ganoush"
                          );
    static char subject_recipe_description_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_recipe_description_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_recipe_description,
                           subject_recipe_description_buf,
                           subject_recipe_description_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "A simple ingredient like aubergine becomes something unique with the right combination of herbs and spices that create a carousel of sensations when you taste this simple but intriguing recipe"
                          );
    static char subject_recipe_ingredients_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_recipe_ingredients_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_recipe_ingredients,
                           subject_recipe_ingredients_buf,
                           subject_recipe_ingredients_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Pizza dough - 1 ball (250 g)\nTomato passata - 120 g\nFresh mozzarella - 125 g\nExtra-virgin olive oil - 1 tbsp\nFresh basil leaves - handful\nSalt - pinch"
                          );
    static char subject_recipe_steps_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_recipe_steps_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_recipe_steps,
                           subject_recipe_steps_buf,
                           subject_recipe_steps_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Spread the tomato passata evenly over the rolled-out dough.\nTear the mozzarella into pieces and distribute across the base.\nDrizzle with olive oil and sprinkle lightly with salt.\nPlace the pizza on a baking tray or preheated stone.\nInsert into the oven.\nSelect Bake, set 220°C, and cook for 12 minutes or until the crust is golden.\nRemove from the oven and top with fresh basil leaves.\nSlice and serve immediately."
                          );

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */
    particle_system_register();
    wd_cook_mode_register();
    wd_icon_register();
    wd_meal_register();
    wd_recipe_bg_register();
    wd_roller_register();
    wd_time_selector_register();
    wd_timer_register();

    /* Register fonts */
    lv_xml_register_font(NULL, "Roboto_Regular_15", Roboto_Regular_15);
    lv_xml_register_font(NULL, "Roboto_Regular_20", Roboto_Regular_20);
    lv_xml_register_font(NULL, "Roboto_Medium_15", Roboto_Medium_15);
    lv_xml_register_font(NULL, "Roboto_Medium_30", Roboto_Medium_30);
    lv_xml_register_font(NULL, "Roboto_Medium_40", Roboto_Medium_40);
    lv_xml_register_font(NULL, "Roboto_Medium_50", Roboto_Medium_50);
    lv_xml_register_font(NULL, "Roboto_Medium_100", Roboto_Medium_100);
    lv_xml_register_font(NULL, "Roboto_Medium_160", Roboto_Medium_160);
    lv_xml_register_font(NULL, "Roboto_Bold_15", Roboto_Bold_15);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_roller_view", &subject_roller_view);
    lv_xml_register_subject(NULL, "subject_meal_view", &subject_meal_view);
    lv_xml_register_subject(NULL, "subject_cook_mode_view", &subject_cook_mode_view);
    lv_xml_register_subject(NULL, "subject_time_view", &subject_time_view);
    lv_xml_register_subject(NULL, "subject_temperature", &subject_temperature);
    lv_xml_register_subject(NULL, "subject_cook_time", &subject_cook_time);
    lv_xml_register_subject(NULL, "subject_cook_time_fmt", &subject_cook_time_fmt);
    lv_xml_register_subject(NULL, "subject_timer_trigger", &subject_timer_trigger);
    lv_xml_register_subject(NULL, "subject_timer_stop", &subject_timer_stop);
    lv_xml_register_subject(NULL, "subject_timer_add", &subject_timer_add);
    lv_xml_register_subject(NULL, "subject_timer_bell_view", &subject_timer_bell_view);
    lv_xml_register_subject(NULL, "subject_timer_3min_view", &subject_timer_3min_view);
    lv_xml_register_subject(NULL, "subject_show_perf_sidebar", &subject_show_perf_sidebar);
    lv_xml_register_subject(NULL, "subject_gpu_enable", &subject_gpu_enable);
    lv_xml_register_subject(NULL, "subject_recipe_prep_time", &subject_recipe_prep_time);
    lv_xml_register_subject(NULL, "subject_recipe_cook_time", &subject_recipe_cook_time);
    lv_xml_register_subject(NULL, "subject_recipe_serves", &subject_recipe_serves);
    lv_xml_register_subject(NULL, "subject_recipe_ability", &subject_recipe_ability);
    lv_xml_register_subject(NULL, "subject_recipe_title", &subject_recipe_title);
    lv_xml_register_subject(NULL, "subject_recipe_description", &subject_recipe_description);
    lv_xml_register_subject(NULL, "subject_recipe_ingredients", &subject_recipe_ingredients);
    lv_xml_register_subject(NULL, "subject_recipe_steps", &subject_recipe_steps);

    /* Register callbacks */
    lv_xml_register_event_cb(NULL, "make_non_clickable_cb", make_non_clickable_cb);
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "clock_small_icon", clock_small_icon);
    lv_xml_register_image(NULL, "clock_icon", clock_icon);
    lv_xml_register_image(NULL, "heat_icon", heat_icon);
    lv_xml_register_image(NULL, "back_icon", back_icon);
    lv_xml_register_image(NULL, "perf_icon", perf_icon);
    lv_xml_register_image(NULL, "grill_icon", grill_icon);
    lv_xml_register_image(NULL, "bottom_heat_icon", bottom_heat_icon);
    lv_xml_register_image(NULL, "conventional_icon", conventional_icon);
    lv_xml_register_image(NULL, "defrost_icon", defrost_icon);
    lv_xml_register_image(NULL, "true_fan_icon", true_fan_icon);
    lv_xml_register_image(NULL, "moist_fan_icon", moist_fan_icon);
    lv_xml_register_image(NULL, "turbo_grill_icon", turbo_grill_icon);
    lv_xml_register_image(NULL, "arrow_icon", arrow_icon);
    lv_xml_register_image(NULL, "saved_icon", saved_icon);
    lv_xml_register_image(NULL, "serving_icon", serving_icon);
    lv_xml_register_image(NULL, "preparation_icon", preparation_icon);
    lv_xml_register_image(NULL, "difficulty_icon", difficulty_icon);
    lv_xml_register_image(NULL, "bell_icon", bell_icon);
    lv_xml_register_image(NULL, "ganoush_bg", ganoush_bg);
    lv_xml_register_image(NULL, "lava_cake", lava_cake);
    lv_xml_register_image(NULL, "salmon", salmon);
    lv_xml_register_image(NULL, "vegetable", vegetable);
    lv_xml_register_image(NULL, "pizza", pizza);
    lv_xml_register_image(NULL, "chicken", chicken);
    lv_xml_register_image(NULL, "fire_sparks", fire_sparks);
    lv_xml_register_image(NULL, "spark1", spark1);
    lv_xml_register_image(NULL, "spark2", spark2);
    lv_xml_register_image(NULL, "perf_button_image", perf_button_image);
    lv_xml_register_image(NULL, "close_button_image", close_button_image);
    lv_xml_register_image(NULL, "whirlpool_logo", whirlpool_logo);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */
#if defined(LV_EDITOR_PREVIEW)
void __attribute__((weak)) make_non_clickable_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("make_non_clickable_cb was called\n");
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/