#include "colors.h"
#include "buffer.h"

#include <stdlib.h>

#ifndef FIRE_H
#define FIRE_H

void init_fire(uint32_t *fire_colors, const uint32_t width, const uint32_t fire_height);
void spread_fire(uint32_t *fire_colors, const uint32_t width, const uint32_t fire_size, const uint32_t mod);

#endif // FIRE_H