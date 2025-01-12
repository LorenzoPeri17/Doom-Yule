#include "buffer.h"

#define POS(row, col) ((row) * width + col)
#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

void paint_buffer(struct Buffer *buffer, uint32_t *fire_colors, const uint32_t width, const uint32_t height){

    char bg_str[HELPER_STR_LEN];
    char fg_str[HELPER_STR_LEN];

    uint32_t fg_col, bg_col;
    // set them to a value that will never be a color
    uint32_t prev_fg_col = UINT32_MAX, prev_bg_col = UINT32_MAX; 

    uint32_t fire_row;

    PBUFFER_ADD_STR(buffer, CURSOR_HOME);
    // NEVER clear the screen here, it will cause flickering
    for (uint32_t row = 0; row < height; row++) {
        for (uint32_t col = 0; col < width; col++) {

            // There is no need to repaint the background or foreground color 
            // if it is the same as the previous one
            fire_row = 2 * row;

            bg_col = fire_palette[fire_colors[POS(fire_row, col)]];
            if (likely(bg_col != prev_bg_col)){
                set_bg_color(bg_col, bg_str);
                PBUFFER_ADD_STR(buffer, bg_str);
            }

            fg_col = fire_palette[fire_colors[POS(fire_row+1, col)]];
            if (likely(fg_col != prev_fg_col)){
                set_fg_color(fg_col, fg_str);
                PBUFFER_ADD_STR(buffer, fg_str);
            }
            
            PBUFFER_ADD_STR(buffer, LOWER_HALF);

            prev_bg_col = bg_col;
            prev_fg_col = fg_col;
        }
        if (row != height - 1) {
            PBUFFER_ADD_CHAR(buffer, '\n');
        }
    }
    return;
}