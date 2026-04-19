//
// Created by Alexander Dickhans on 4/18/26.
//

#include <stdio.h>

#include "misc/utils.h"

int main(void) {
    printf("Hello, World!\n");

    char c;

    while (scanf(" %c", &c) == 1) {
        switch (c) {
            case 'c':
                clearScreen();
                break;
            case 'p':
                printf("Hello World\n");
                break;
            case 'x':
                clean_exit();
                return 0;
            default:
                printf("unknown command\n");
                break;
        }
    }

    return 0;
}
