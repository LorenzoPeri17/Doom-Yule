#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "colors.h"
#include "terminal.h"

#ifndef BUFFER_H
#define BUFFER_H

#define MAXSIZE UINT32_MAX

#define UPPER_HALF "▀"
#define LOWER_HALF "▄"

#define PBUFFER_ADD_CHAR(buf, c) \
    buf->buffer[buf->size++] = c;

#define PBUFFER_ADD_STR(buf, string) \
    strcpy(buf->buffer + buf->size, string); \
    buffer->size += strlen(string); \

#define WRITE_BUFFER(buf) \
    write(STDOUT_FILENO, buf.buffer, buf.size);

#define BUFFER_FREE(buf) \
    free(buf.buffer);

#define BUFFER_RESET(buf) \
    buf.size = 0;

struct Buffer {
    uint32_t size;
    char *buffer;
};

void paint_buffer(struct Buffer *buffer, uint32_t *fire_colors, const uint32_t width, const uint32_t height);

#endif // BUFFER_H