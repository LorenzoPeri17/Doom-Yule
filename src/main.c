#include <stdlib.h>
#include <time.h>

#include "terminal.h"
#include "buffer.h"
#include "colors.h"
#include "fire.h"
#include "info.h"
#include "cli_opts.h"

static volatile int keep_running = 1;

// This is fine. A signal handler must be defined with signo as an argument
// but all we ever want to do is stop the program.
#pragma GCC diagnostic ignored "-Wunused-parameter"
void sig_handler (int signo){
    keep_running = 0;
}

int main (int argc, char **argv){

    int info = 0;
    
    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    srand(time(NULL));

    const uint32_t width = w.ws_col;
    const uint32_t height = w.ws_row;

    const uint32_t fire_height = 2 * height;
    const uint32_t fire_size = width * fire_height;

    struct Buffer buf;
    buf.size = 0;
    buf.buffer = (char *)malloc(MAXSIZE * sizeof(char));
    if (buf.buffer == NULL) {
        info = MALLOC_ERROR;
        goto free_and_exit;
    }

    uint32_t *fire_colors = (uint32_t *)malloc(fire_size * sizeof(uint32_t));
    if (fire_colors == NULL) {
        info = MALLOC_ERROR;
        goto free_and_exit;
    }

    uint32_t fire_spread = guestimate_spread(height);
    double target_fps = DEFAULT_FPS;

    init_fire(fire_colors, width, fire_height);
    clear_screen();
    term_command(CURSOR_HIDE);

    if (parse_cli_opts(argc, argv, &target_fps, &fire_spread) != 0){
        info = CLI_ERROR;
        goto free_and_exit;
    }
    
    double target_frame_time_ms;
    if (target_fps == 0){
        target_frame_time_ms = 0.0;
    } else{
        target_frame_time_ms = 1000.0 / target_fps;
    }

    double frame_time_ms;
    double initial_time;
    double missing_time;
    while (keep_running) {
        initial_time = clock();
        spread_fire(fire_colors, width, fire_size, fire_spread);
        paint_buffer(&buf, fire_colors, width, height);
        WRITE_BUFFER(buf);
        BUFFER_RESET(buf);
        frame_time_ms = (clock() - initial_time)/CLOCKS_PER_SEC * 1000.0;
        missing_time = target_frame_time_ms - frame_time_ms;
        if (missing_time > 0){
            usleep(1000.0 * missing_time);
        }
    }

free_and_exit:
    term_command(CURSOR_SHOW);
    term_command(COLOR_RESET);
    clear_screen();
    print_info(info);
    BUFFER_FREE(buf);
    return info;
}