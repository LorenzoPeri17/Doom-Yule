#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef CLI_OPTS_H
#define CLI_OPTS_H

#define DEFAULT_FPS 30.0

int parse_cli_opts(int argc, char **argv, double *target_fps, uint32_t *fire_size);
void print_usage();
uint32_t guestimate_spread(uint32_t height);

#endif // CLI_OPTS_H