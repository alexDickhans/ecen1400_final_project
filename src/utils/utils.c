//
// Created by Alexander Dickhans on 4/18/26.
//

#include "utils/utils.h"

#include <stdio.h>
#include <stdlib.h>

void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void show_score(int score) {
    printf("Exiting... Congrats on the score: %d!\n", score);
}

void enable_raw_mode(struct termios *orig_termios) {
    // Get current terminal attributes to save them
    if (tcgetattr(STDIN_FILENO, orig_termios) == -1) {
        perror("tcgetattr");
        exit(1);
    }

    struct termios raw = *orig_termios;
    // Disable canonical mode (line buffering) and echoing
    raw.c_lflag &= ~(ICANON | ECHO);

    // Apply the new settings immediately
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
        perror("tcsetattr");
        exit(1);
    }
}

void disable_raw_mode(struct termios *orig_termios) {
    // Restore the original terminal settings
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios) == -1) {
        perror("tcsetattr");
        exit(1);
    }
}

