#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#ifndef COLORS_H
#define COLORS_H

#define MAXCOLORS 256
#define HELPER_STR_LEN 32

#define COLOR_RESET "\e[0m"

// Se colors with a literal number
#define BG_COLOR_LIT(color) "\e[48;5;" #color "m"
#define FG_COLOR_LIT(color) "\e[38;5;" #color "m"

// Set colors with a variable
void set_bg_color(uint32_t color, char *color_str);
void set_fg_color(uint32_t color, char *color_str);

// Palette

/***********************************************

Fire palette heavily inspired by the wonderful
        DOOM-fire-zig by constant-void
  https://github.com/const-void/DOOM-fire-zig/

************************************************/

#define FIRE_BLACK 0
#define PALETTE_SIZE 26
#define FIRE_WHITE PALETTE_SIZE - 1

const uint32_t fire_palette[PALETTE_SIZE];

#endif // COLORS_H