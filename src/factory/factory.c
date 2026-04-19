//
// Created by Alexander Dickhans on 4/18/26.
//

#include "factory/factory.h"

#include <stdlib.h>

struct _factory {
    int placeholder;
};

Factory* create_factory(void) {
    Factory* factory = malloc(sizeof(Factory));
    if (factory) {
        factory->placeholder = 0;
    }
    return factory;
}

void destroy_factory(Factory* factory) {
    free(factory);
}
