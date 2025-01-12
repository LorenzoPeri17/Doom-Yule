#include "terminal.h"

void clear_screen(){
  write(STDOUT_FILENO, CLEAR_SCREEN, strlen(CLEAR_SCREEN));
}

void term_command(const char *command){
    write(STDOUT_FILENO, command, strlen(command));
}

