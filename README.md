# RZ/A2M EVK: LVGL 9 smart-oven demo (Linux 7.3)

LVGL 9 smart-oven UI on the RZ/A2M EVK with the RZ/A2M Linux 7.x BSP. Shapes and images are drawn by the D/AVE 2D GPU; the app and its images run in place from QSPI flash, with 8 MB HyperRAM and no DDR. 800x480 RSK TFT with touch, starts at boot.

Two ways to use it:

| Path | For | Section |
|---|---|---|
| Prebuilt images | Flash and run, no build | [Quick start](#quick-start-prebuilt) |
| Build from source | Build the BSP and the demo yourself | [Build from source](#build-from-source) |

## Contents

| Path | Content |
|---|---|
| `prebuilt/` | Flash images (U-Boot, DTB, kernel, rootfs with the demo) and the flash tools |
| `source/` | Demo source, Makefile and `install.sh` |

| In `source/` | Content |
|---|---|
| `main.c`, `a2m_disp.c/.h` | App entry, VDC6 frame buffer display backend with D/AVE 2D |
| `a2m_texcache.c/.h` | D/AVE 2D texture cache |
| `bsp_api.h` | Header included by LVGL's D/AVE 2D draw unit |
| `lv_conf.h` | LVGL configuration |
| `oven_ui/` | Oven UI (LVGL Pro project and generated C) |
| `lvgl/` | LVGL 9 |
| `dave_driver/` | D/AVE 2D user-space library (`/dev/dave2d`) |
| `bsp/S99demo` | Starts the demo at boot |
| `install.sh` | Builds the demo with the BSP toolchain and installs it in the BSP rootfs overlay |

## Hardware

| Item | Detail |
|---|---|
| Board | RZ/A2M EVK with the RSK TFT APP BOARD (800x480 LCD) |
| Debugger | SEGGER J-Link, 20-pin cable on CN5 |
| Console | USB serial on CN5 ("UART"), 115200 baud |
| Power | 5 V on CN13 |

| SUB SW6 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | Use |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Program mode | OFF | ON | OFF | ON | ON | ON | – | – | – | – | Flashing with J-Link |
| Run mode | OFF | OFF | OFF | ON | ON | ON | ON | OFF | OFF | OFF | Running (correct LCD colors) |

Power off before changing switches.

## Quick start (prebuilt)

| File in `prebuilt/` | QSPI address |
|---|---|
| `u-boot.bin` | 0x20000000 |
| `r7s9210-rza2mevb.dtb.bin` | 0x200C0000 |
| `xipImage.bin` | 0x20200000 |
| `rootfs.cramfs.bin` | 0x20800000 |

1. Program mode, power on, press a key in the terminal to stop in U-Boot.
2. Flash (needs the SEGGER J-Link software):

| Host | Command |
|---|---|
| Windows | Double-click `prebuilt\Program_QSPI.bat`, then type `all` (or `uboot`, `dtb`, `kernel`, `rootfs`) |
| Ubuntu | `./prebuilt/flash.sh all` (or `uboot`, `dtb`, `kernel`, `rootfs`) |

3. Power off, run mode, power on.

The demo starts about 3 s after power-on. Login on the console: `root`, no password.

## Build from source

Needs the [RZ/A2M Linux 7.x BSP](https://github.com/renesas-rz/rza_linux-7.x_bsp), built once (`config`, `buildroot`, `kernel`, `u-boot`, `images`) as described in its README.

1. Clone this demo next to the BSP, then recreate the BSP container with the demo mounted as well (from the BSP folder):

```
git clone https://github.com/renesas-rz/rza2m-lvgl9-oven-demo-7.x.git ../rza2m-lvgl9-oven-demo-7.x
docker rm -f rza2m7
docker run -it --name rza2m7 \
  -v "$PWD":/work/rza_linux-7.x_bsp \
  -v "$(dirname "$PWD")"/rza2m-lvgl9-oven-demo-7.x:/work/oven-demo \
  rza2m-bsp7:22.04
```

2. In the container, build the demo, install it in the BSP and rebuild the rootfs:

```
cd /work/oven-demo/source
./install.sh /work/rza_linux-7.x_bsp
cd /work/rza_linux-7.x_bsp
./build.sh buildroot
./build.sh images
```

`install.sh` puts `oven_a2m` in `/root/bin` and `S99demo` in `/etc/init.d` of the rootfs. The images are in the BSP's `output/images/`; copy the four `.bin` files into `prebuilt/` and flash as in the quick start.

To take the demo out of the BSP again: `./install.sh /work/rza_linux-7.x_bsp rza2mevb remove`, then `./build.sh buildroot` and `./build.sh images`.

## Running

| Task | Command (board console) |
|---|---|
| Stop the demo | `killall oven_a2m` |
| Start it again | `/etc/init.d/S99demo start` |
| GPU on / off | Sidebar switch "Enable GPU (D/AVE 2D)" |

| Environment variable | Effect |
|---|---|
| `A2M_MAX_FPS=n` | Frame-rate cap (S99demo uses 30) |
| `OVEN_GPU=0` | Start with the GPU switch off |
| `A2M_TEXCACHE_KB=n` | D/AVE texture budget in KB (default 512) |
| `LV_FBDEV`, `LV_EVDEV` | Display and touch devices (default `/dev/fb0`, `/dev/input/event0`) |

## Troubleshooting

| Symptom | Fix |
|---|---|
| LCD colors wrong | SW6 in run mode (all 10 positions) |
| Board stops at the U-Boot prompt | An older environment is saved in flash: `env default -a; saveenv`, then `reset` |
| J-Link not found (Windows) | Install the SEGGER J-Link software (default folder `C:\Program Files\SEGGER\`) |
| J-Link not found (Ubuntu) | Install the J-Link DEB package, or `JLINK=<path to JLinkExe> ./prebuilt/flash.sh` |
