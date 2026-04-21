//
// Created by Alexander Dickhans on 4/18/26.
//

#include "factory/factory.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <_string.h>

struct _factory {
    char *name;
    double rate;
    double temp_sum;
    FactoryNode *next;
};

FactoryNode *create_factory(const FactoryPrototype *factory_prototype, FactoryNode* head) {
    FactoryNode *factory = malloc(sizeof(FactoryNode));

    if (factory) {
        factory->name = strdup(factory_prototype->name);
        factory->rate = factory_prototype->rate;
        factory->temp_sum = 0;
        factory->next = head;
    }

    return factory;
}

int update_factory(FactoryNode *factory) {
    factory->temp_sum += factory->rate;

    const float res = floor(factory->temp_sum+0.01);

    factory->temp_sum -= res;

    return (int) roundf(res);
}

void print_factory(const FactoryNode *factory) {
    if (factory) {
        printf("%s, Pickling at: %.1f pickles/s\n", factory->name, factory->rate);
    }
}

float get_factory_rate(const FactoryNode *factory) {
    if (factory) {
        return factory->rate;
    }
    return -1;
}

void destroy_factories(FactoryNode *factory) {
    if (factory) {
        do {
            FactoryNode* old_factory = factory;
            factory = factory->next;

            free(old_factory->name);
            free(old_factory);
        } while (factory);
    }

}

FactoryNode *next_factory(const FactoryNode *factory) {
    if (factory) {
        return factory->next;
    }

    return NULL;
}
