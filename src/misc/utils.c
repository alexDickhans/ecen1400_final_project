//
// Created by Alexander Dickhans on 4/18/26.
//

#include "misc/utils.h"

#include <stdio.h>
#include <stdlib.h>

void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void clean_exit(void) {
    printf("Exiting... High score...\n");
}
