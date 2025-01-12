/***********************************************

Fire algorithm heavily inspired by the wonderful
        DOOM-fire-zig by constant-void
  https://github.com/const-void/DOOM-fire-zig/

************************************************/

#include "fire.h"


inline void init_fire(uint32_t *fire_colors, const uint32_t width, const uint32_t fire_height) {
    uint32_t i = 0;
    for (; i < width * (fire_height-1); i++) {
        fire_colors[i] = FIRE_BLACK;
    }
    // last row is white
    for (; i < width * fire_height; i++) {
        fire_colors[i] = FIRE_WHITE;
    }
    return;
}

inline void spread_fire(uint32_t *fire_colors, const uint32_t width, const uint32_t fire_size, const uint32_t mod) {
    uint_fast32_t to_spread, spread_dst, rnd;
    int_fast32_t new_pos;
    for (uint_fast32_t pos = 0; pos < fire_size; pos++) {
        to_spread = fire_colors[pos];

        // check bounds
        if ((to_spread == 0) && (pos >= width)) {
            fire_colors[pos - width] = 0;
        } else {
            rnd = (uint_fast32_t)(rand() % mod); // random integer between 0 and mod-1
            new_pos = pos - (int_fast32_t)rnd + 1;
            spread_dst = (new_pos >= 0) ? (uint_fast32_t)new_pos : pos;
            if (spread_dst >= width) {
                if (to_spread > (rnd & 1)) {
                    fire_colors[spread_dst - width] = to_spread - (rnd & 1);
                } else {
                    fire_colors[spread_dst - width] = 0;
                }
            }
        }
    }
    return;
}