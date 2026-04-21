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

void clear_screen(void);
void show_score(int score);

void enable_raw_mode(struct termios *orig_termios);

void disable_raw_mode(struct termios *orig_termios);

#endif // FINAL_PROJECT_UTILS_H
