//
// Created by Alexander Dickhans on 4/18/26.
//

#ifndef FINAL_PROJECT_UTILS_H
#define FINAL_PROJECT_UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#include "factory/factory.h"

/**
 * Use the terminal commands to clear the output so a new frame can be drawn
 */
void clear_screen(void);

/**
 * Thanks the user for playing and displays their final score
 *
 * @param score The score to show in the closing message
 */
void show_score(int score);

/**
 * enables the raw terminal mode so no newlines are required for text must be safely disabled, or it will affect later commands
 * @param orig_termios Terminos
 */
void enable_raw_mode(struct termios *orig_termios);

/**
 * Disables the raw terminal mode
 *
 * @param orig_termios
 */
void disable_raw_mode(struct termios *orig_termios);

#endif // FINAL_PROJECT_UTILS_H
