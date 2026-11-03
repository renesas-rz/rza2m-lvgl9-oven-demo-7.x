/**
 * @file meals_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "meals_gen.h"
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

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * meals_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "meals_#");
    lv_obj_set_style_bg_opa(lv_obj_0, 0, 0);

    lv_obj_t * wd_meal_0 = wd_meal_create(lv_obj_0);
    wd_meal_bind_title(wd_meal_0, &subject_recipe_title);
    wd_meal_bind_description(wd_meal_0, &subject_recipe_description);
    wd_meal_bind_serves(wd_meal_0, &subject_recipe_serves);
    wd_meal_bind_cooking(wd_meal_0, &subject_recipe_cook_time);
    wd_meal_bind_preparation(wd_meal_0, &subject_recipe_prep_time);
    wd_meal_bind_difficulty(wd_meal_0, &subject_recipe_ability);
    wd_meal_bind_ingredients(wd_meal_0, &subject_recipe_ingredients);
    wd_meal_bind_steps(wd_meal_0, &subject_recipe_steps);
    wd_meal_bind_cook_time(wd_meal_0, &subject_cook_time);
    wd_meal_add_item(wd_meal_0, "Classic Margherita Stone-Baked Pizza", "A crisp, golden pizza base topped with fresh tomato, melted mozzarella, and fragrant basil. Simple ingredients baked at high heat create an authentic Italian-style Margherita right at home.", pizza, 15, 12, "2-3 people", "Easy", "Pizza dough - 1 ball (250 g)\nTomato passata - 120 g\nFresh mozzarella - 125 g\nExtra-virgin olive oil - 1 tbsp\nFresh basil leaves - handful\nSalt - pinch", "1. Spread the tomato passata evenly over the rolled-out dough.\n2. Tear the mozzarella into pieces and distribute across the base.\n3. Drizzle with olive oil and sprinkle lightly with salt.\n4. Place the pizza on a baking tray or preheated stone.\n5. Insert into the oven.\n6. Select Bake, set 220°C, and cook for 12 minutes or until the crust is golden.\n7. Remove from the oven and top with fresh basil leaves.\n8. Slice and serve immediately.");
    wd_meal_add_item(wd_meal_0, "Lemon Herb Baked Salmon Fillets", "Fresh salmon is seasoned simply with lemon, herbs, and olive oil. Baking gently keeps the fillets moist and flaky, making this a light, flavorful everyday dish.", salmon, 10, 14, "4 people", "Easy", "Salmon fillets - 4 pieces (150 g each)\nLemon - 1\nOlive oil - 1 tbsp\nFresh dill - small bunch\nGarlic - 1 clove, minced\nSalt and black pepper - to taste", "1. Place the salmon fillets on a lined baking tray.\n2. Drizzle with olive oil and sprinkle with garlic, salt, and pepper.\n3. Slice the lemon and lay the slices on top of each fillet.\n4. Add small sprigs of dill.\n5. Insert the tray into the oven.\n6. Select Bake, set 200°C, and cook for 14 minutes.\n7. Remove carefully and squeeze a little fresh lemon juice over the top.\n8. Serve with extra dill if desired.");
    wd_meal_add_item(wd_meal_0, "Garlic Butter Roasted Chicken Thighs", "These chicken thighs are coated in a simple garlic butter and roasted until crisp and golden. A comforting and flavorful dish with minimal preparation.", chicken, 15, 30, "4 people", "Medium", "Chicken thighs - 6 pieces\nButter - 40 g, melted\nGarlic - 2 cloves, minced\nPaprika - 1 tsp\nThyme - 1 tsp\nSalt and pepper - to taste", "1. Mix melted butter with garlic, paprika, thyme, salt, and pepper.\n2. Place chicken thighs on a baking tray and brush generously with the garlic butter.\n3. Add an extra sprinkle of paprika for color if desired.\n4. Insert the tray into the oven.\n5. Select Roast, set 190°C, and cook for 30 minutes.\n6. Halfway through, spoon juices over the chicken.\n7. When the skin is crisp and golden, remove from the oven.\n8. Let rest 5 minutes before serving.");
    wd_meal_add_item(wd_meal_0, "Oven-Roasted Vegetable Medley", "A colorful mix of carrots, zucchini, peppers, and onions roasted until lightly caramelized. A versatile side dish that pairs with almost any main.", vegetable, 10, 9, "4 people", "Easy", "Carrots - 2\nZucchini - 2\nRed pepper - 1\nYellow pepper - 1\nRed onion - 1\nOlive oil - 2 tbsp\nSalt and pepper - to taste", "1. Cut all vegetables into even-sized pieces.\n2. Place onto a baking tray and drizzle with olive oil.\n3. Season with salt and pepper and toss to coat.\n4. Spread vegetables into a single layer.\n5. Insert tray into the oven.\n6. Select Bake, set 200°C, and cook for 18 minutes, stirring once halfway.\n7. Remove when edges begin to brown slightly.\n8. Serve immediately as a side or warm salad.");
    wd_meal_add_item(wd_meal_0, "Molten Chocolate Lava Cakes", "Soft individual chocolate cakes with a warm, molten center. Perfectly indulgent yet quick to prepare - an ideal dessert for any occasion.", lava_cake, 12, 60, "4 people", "Medium", "Dark chocolate - 120 g\nButter - 80 g\nEggs - 2 whole + 2 yolks\nSugar - 50 g\nFlour - 30 g\nCocoa powder - for dusting", "1. Melt chocolate and butter together in a heatproof bowl.\n2. Whisk in the sugar, eggs, and yolks until smooth.\n3. Fold in the flour gently.\n4. Grease four ramekins and dust with cocoa powder.\n5. Pour batter evenly into the ramekins.\n6. Insert into the oven.\n7. Select Bake, set 210°C, and cook for 9 minutes until edges set and centers remain soft.\n8. Rest 1 minute, turn out onto plates, and serve warm.");

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

