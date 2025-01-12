#include "colors.h"

const uint32_t fire_palette[PALETTE_SIZE] = { 
    0,
    233, 
    234, 
    52, 
    53, 
    88, 
    89, 
    94,
    95, 
    96, 
    130, 
    131, 
    132, 
    133, 
    172, 
    214, 
    215, 
    220, 
    220, 
    221, 
    3, 
    226, 
    227, 
    230, 
    195, 
    230 
    };

// generate ANSI color string for background color
inline void set_bg_color(unsigned int color, char *color_str) {
    color_str[0] = '\0';
    snprintf(color_str, HELPER_STR_LEN, "\e[48;5;%um", color);
    return;
}

// generate ANSI color string for foreground color
inline void set_fg_color(unsigned int color, char *color_str) {
    color_str[0] = '\0';
    snprintf(color_str, HELPER_STR_LEN, "\e[38;5;%um", color);
    return;
}