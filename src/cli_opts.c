#include "cli_opts.h"

int parse_cli_opts(int argc, char **argv, double *target_fps, uint32_t *fire_size){
    int opt;
    while ((opt = getopt(argc, argv, "hf:s:")) != -1) {
        switch (opt) {
            case 'f':
                *target_fps = (double) atof(optarg);
                break;
            case 's':
                *fire_size = (uint32_t) atoi(optarg);
                if ((*fire_size < 2) || (*fire_size > 5)) {
                    return 1;
                }
                break;
            case 'h':
                return 1;
            default:
                break;
        }
    }
    return 0;
}

void print_usage(){
    printf("Usage: doom-yule [-f target_fps] [-s fire_size]\n");
    printf("Options:\n");
    printf("  -f target_fps\t\tSet the target frames per second (default: 30), set to 0 to unlock.\n");
    printf("  -s fire_spread\tApproximately set the vertical height of the fire. Must be between 2 and 5.\n\t\t\tDefault is determined by the height of the terminal.\n");
    printf("  -h\t\t\tPrint this help message\n");
    return;
}

uint32_t guestimate_spread(uint32_t height){
    if (height > 45) {
        return 5;
    } else if (height > 29) {
        return 4;
    } else {
        return 2;
    }
}