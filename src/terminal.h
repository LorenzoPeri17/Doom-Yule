#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#ifndef TERMINAL_H
#define TERMINAL_H

#define CLEAR_SCREEN "\e[1;1H\e[2J"

#define CURSOR_HIDE  "\e[?25l"
#define CURSOR_SHOW  "\e[?25h"
#define CURSOR_HOME  "\e[1;1H"

void clear_screen();
void term_command(const char *command);

#endif // TERMINAL_H