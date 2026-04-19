//
// Created by Alexander Dickhans on 4/18/26.
//

#include "smelter/smelter.h"

#include <stdlib.h>

struct _smelter {
    int placeholder;
};

Smelter* create_smelter(void) {
    Smelter* smelter = malloc(sizeof(Smelter));
    if (smelter) {
        smelter->placeholder = 0;
    }
    return smelter;
}

void destroy_smelter(Smelter* smelter) {
    free(smelter);
}
