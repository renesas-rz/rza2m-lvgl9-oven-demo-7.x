/*
 * Smart-oven LVGL 9 demo on RZ/A2M EVK (Linux 7.x, VDC6 fbdev, 800x480)
 * Shapes and images (icons, sparks) are drawn by the D/AVE 2D GPU straight
 * into the frame buffer. Large photos and text stay in software.
 *
 * Env:  LV_FBDEV=/dev/fb0  LV_EVDEV=/dev/input/event0
 *       OVEN_GPU=0         start with the GPU switch off (default on)
 *       OVEN_DISP=fbdev    use LVGL's stock fbdev driver (software only, old path)
 *       A2M_FB_SINGLE=1    force single buffer
 *       A2M_FB_NOVSYNC=1   no vsync wait (test only: tears)
 *       A2M_TEXCACHE_KB=n  D/AVE texture budget in KB (default 512)
 *       A2M_DAVE_MIN_AREA=n smaller tasks stay in software (default 4096 px)
 *       A2M_DAVE_POLICY=all  every supported task to D/AVE (default: smart)
 *       A2M_MAX_FPS=n      frame-rate cap, e.g. 40 (default: no cap); frees CPU
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "oven_ui/oven_ui.h"
#include "oven_ui/screens/meals_gen.h"
#include "a2m_disp.h"
#include "bsp_api.h"

static const char * getenv_def(const char * name, const char * def)
{
    const char * v = getenv(name);
    return (v && v[0]) ? v : def;
}

static void gpu_switch_cb(lv_observer_t * o, lv_subject_t * s)
{
    LV_UNUSED(o);
    printf("GPU (D/AVE 2D) %s\n", lv_subject_get_int(s) ? "ON" : "OFF");
    lv_obj_invalidate(lv_screen_active());   /* redraw everything with the new renderer */
}

int main(int argc, char ** argv)
{
    (void)argc;
    (void)argv;

    const char * fb = getenv_def("LV_FBDEV", "/dev/fb0");
    const char * ev = getenv_def("LV_EVDEV", "/dev/input/event0");
    bool stock = strcmp(getenv_def("OVEN_DISP", "a2m"), "fbdev") == 0;

    lv_init();

    lv_display_t * disp;
    if(stock) {
        disp = lv_linux_fbdev_create();
        if(disp) lv_linux_fbdev_set_file(disp, fb);
        printf("Display: LVGL stock fbdev driver (D/AVE cannot reach its buffers)\n");
    }
    else {
        disp = a2m_disp_create(fb);
    }
    if(disp == NULL) { fprintf(stderr, "display init failed\n"); return 1; }
    printf("Display %s: %d x %d\n", fb,
           (int)lv_display_get_horizontal_resolution(disp),
           (int)lv_display_get_vertical_resolution(disp));
    printf("D/AVE 2D: %s\n", lv_draw_dave2d_a2m_available() ? "ready" : "NOT available (software only)");

    /* Optional frame-rate cap: LVGL refreshes at most every 1000/n ms */
    const char * mf = getenv("A2M_MAX_FPS");
    if(mf && atoi(mf) > 0) {
        uint32_t period = 1000 / (uint32_t)atoi(mf);
        if(period < 1) period = 1;
        lv_timer_set_period(lv_display_get_refr_timer(disp), period);
        printf("Frame-rate cap: %d FPS (refresh every %u ms)\n", atoi(mf), (unsigned)period);
    }

    lv_indev_t * touch = lv_evdev_create(LV_INDEV_TYPE_POINTER, ev);
    if(touch == NULL) fprintf(stderr, "warning: no touch input on %s\n", ev);
    else lv_indev_set_display(touch, disp);

    oven_ui_init("");
    if(strcmp(getenv_def("OVEN_GPU", "1"), "0") == 0 || !lv_draw_dave2d_a2m_available())
        lv_subject_set_int(&subject_gpu_enable, 0);
    lv_subject_add_observer(&subject_gpu_enable, gpu_switch_cb, NULL);

    lv_screen_load(meals_create());
    lv_sysmon_hide_memory(NULL);
    lv_sysmon_hide_performance(NULL);

    while(1) {
        uint32_t idle_ms = lv_timer_handler();
        if(idle_ms > 5) idle_ms = 5;
        usleep(idle_ms * 1000);
    }
    return 0;
}
