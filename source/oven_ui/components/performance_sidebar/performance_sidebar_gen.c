/**
 * @file performance_sidebar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "performance_sidebar_gen.h"
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

lv_obj_t * performance_sidebar_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_scrollbar;
    static lv_style_t style_switch_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, 312);
        lv_style_set_height(&style_main, 480);
        lv_style_set_bg_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_bg_opa(&style_main, (255 * 70 / 100));
        lv_style_set_radius(&style_main, 0);
        lv_style_set_border_width(&style_main, 0);
        lv_style_set_pad_all(&style_main, 31);
        lv_style_set_flex_flow(&style_main, LV_FLEX_FLOW_COLUMN);
        lv_style_set_layout(&style_main, LV_LAYOUT_FLEX);
        lv_style_set_text_font(&style_main, Roboto_Regular_15);
        lv_style_set_text_color(&style_main, lv_color_hex3(0xfff));

        lv_style_init(&style_scrollbar);
        lv_style_set_width(&style_scrollbar, 6);
        lv_style_set_height(&style_scrollbar, 0);
        lv_style_set_radius(&style_scrollbar, 0);
        lv_style_set_bg_color(&style_scrollbar, lv_color_hex(0xEEB111));
        lv_style_set_bg_opa(&style_scrollbar, 255);
        lv_style_set_pad_top(&style_scrollbar, 31);
        lv_style_set_pad_bottom(&style_scrollbar, 0);
        lv_style_set_pad_right(&style_scrollbar, 0);

        lv_style_init(&style_switch_indicator);
        lv_style_set_bg_color(&style_switch_indicator, lv_color_hex(0xEEB111));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "performance_sidebar_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_add_style(lv_obj_0, &style_blur, 0);
    lv_obj_add_style(lv_obj_0, &style_scrollbar, LV_PART_SCROLLBAR);
    lv_obj_bind_flag_if_eq(lv_obj_0, &subject_show_perf_sidebar, LV_OBJ_FLAG_HIDDEN, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, perf_icon);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_obj_set_width(lv_label_0, lv_pct(100));
    lv_label_set_text(lv_label_0, "Smart oven demo developed in LVGL Pro, running on the RZ/A2M with Linux. Rendering is accelerated by the D/AVE 2D GPU. Runs from QSPI flash, on-chip RAM and HyperRAM, with no DDR.");
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_1, "Enable GPU (D/AVE 2D)");
    lv_obj_set_style_text_font(lv_label_1, Roboto_Medium_30, 0);
    
    lv_obj_t * lv_switch_0 = lv_switch_create(lv_obj_0);
    lv_obj_bind_checked(lv_switch_0, &subject_gpu_enable);
    /* GPU switch enabled */
    lv_obj_add_style(lv_switch_0, &style_switch_indicator, LV_PART_INDICATOR | LV_STATE_CHECKED);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_2, "Hardware");
    lv_obj_set_style_text_font(lv_label_2, Roboto_Medium_30, 0);
    
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_0);
    lv_obj_set_width(lv_label_3, lv_pct(100));
    lv_label_set_text(lv_label_3, "• Renesas RZ/A2M EVK\n• MPU: 528MHz ARM Cortex-A9 (single core)\n• RAM: 4MB on-chip, 8MB external HyperRAM\n• Flash: 64MB QSPI, app runs in place (XIP)\n• GPU: D/AVE 2D (shapes, icons, sparks)\n• OS: Linux 7.3");
    
    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_4, "Display");
    lv_obj_set_style_text_font(lv_label_4, Roboto_Medium_30, 0);
    
    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_0);
    lv_obj_set_width(lv_label_5, lv_pct(100));
    lv_label_set_text(lv_label_5, "• Resolution: 800x480\n• Display Size: 7\" (RSK TFT)\n• Interface: Parallel RGB\n• Color Depth: 16-bit");
    
    lv_obj_t * lv_label_6 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_6, "Performance");
    lv_obj_set_style_text_font(lv_label_6, Roboto_Medium_30, 0);
    
    lv_obj_t * lv_label_7 = lv_label_create(lv_obj_0);
    lv_obj_set_name(lv_label_7, "perf_live");   /* A2M: updated live from oven_ui.c */
    lv_label_set_text(lv_label_7, "• Measuring...");
    
    lv_obj_t * lv_label_8 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_8, "Flash Usage");
    lv_obj_set_style_text_font(lv_label_8, Roboto_Medium_30, 0);
    
    lv_obj_t * lv_label_9 = lv_label_create(lv_obj_0);
    lv_obj_set_width(lv_label_9, lv_pct(100));
    lv_label_set_text(lv_label_9, "• Images: 6.7MB (RGB565, scaled for 800x480)\n• Fonts: 0.2MB\n• Stored in QSPI flash and read in place (XIP)");
    
    lv_obj_t * lv_label_10 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_10, "RAM Usage");
    lv_obj_set_style_text_font(lv_label_10, Roboto_Medium_30, 0);
    
    lv_obj_t * lv_label_11 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_11, "• App RAM usage (measured): ~0.2MB in HyperRAM\n• 2 frame buffers: 1.5MB in on-chip RAM\n");
    
    lv_obj_t * lv_label_12 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_12, "Graphics Features");
    lv_obj_set_style_text_font(lv_label_12, Roboto_Medium_30, 0);
    
    lv_obj_t * lv_label_13 = lv_label_create(lv_obj_0);
    lv_obj_set_width(lv_label_13, lv_pct(100));
    lv_label_set_text(lv_label_13, "• Screen transitions with animations\n• Naturally scrolling containers\n• Parallax effect on meal scrolling\n• Background Blurring\n• Particle system for sparks\n• Various layouts for responsivity");

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

