/*
Printing errors that have occurred during the execution of the program.
*/

#include "info.h"

void print_info(int info){
    switch (info){
        case MALLOC_ERROR:
            fprintf(stderr, "Error allocating memory\n");
            break;
        case CLI_ERROR:
            print_usage();
            break;
        default:
            break;
    }
}