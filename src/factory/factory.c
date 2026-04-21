//
// Created by Alexander Dickhans on 4/18/26.
//

#include "factory/factory.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Factory node implementation
struct _factory {
    char *name;
    double rate;
    double temp_sum;
    FactoryNode *next;
};

FactoryNode *create_factory(const FactoryPrototype *factory_prototype, FactoryNode* head) {
    // Allocate the factory
    FactoryNode *factory = malloc(sizeof(FactoryNode));

    // Check for proper allocations and inputs
    if (factory && factory_prototype && factory_prototype->name) {
        // Copy the name of the factory
        factory->name = strdup(factory_prototype->name);
        if (!factory->name) {
            free(factory);
            return NULL;
        }

        // Copy the other parts of the factory prototype
        factory->rate = factory_prototype->rate;
        factory->temp_sum = 0;
        factory->next = head;
        return factory;
    }

    // Free for failed allocations
    free(factory);

    return NULL;
}

int update_factory(FactoryNode *factory) {
    // Check for null factories
    if (factory == NULL) {
        return -1;
    }

    // Logic to only add once a whole pickle is made
    factory->temp_sum += factory->rate;

    const float res = floor(factory->temp_sum+0.01);

    factory->temp_sum -= res;

    return (int) roundf(res);
}

void print_factory(const FactoryNode *factory) {
    // Check to make sure the factory exists
    if (factory) {
        printf("%s, Pickling at: %.1f pickles/s\n", factory->name, factory->rate);
    }
}

float get_factory_rate(const FactoryNode *factory) {
    // Check to make sure the factory exists
    if (factory) {
        return factory->rate;
    }
    return -1;
}

void destroy_factories(FactoryNode *factory) {
    // Check factory
    if (factory) {
        // Clear all the nodes of the factory one by one until the
        do {
            FactoryNode* old_factory = factory;
            factory = factory->next;

            free(old_factory->name);
            free(old_factory);
        } while (factory);
    }

}

FactoryNode *next_factory(const FactoryNode *factory) {
    // Checks for factory existance
    if (factory) {
        return factory->next;
    }

    return NULL;
}
