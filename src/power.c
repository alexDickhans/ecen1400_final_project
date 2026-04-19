//
// Created by Alexander Dickhans on 4/18/26.
//

#include "power.h"

#include <stdlib.h>

struct _power_grid {
    int placeholder;
};

PowerGrid* create_power_grid(void) {
    PowerGrid* grid = malloc(sizeof(PowerGrid));
    if (grid) {
        grid->placeholder = 0;
    }
    return grid;
}

void destroy_power_grid(PowerGrid* grid) {
    free(grid);
}
