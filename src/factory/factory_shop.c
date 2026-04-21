//
// Created by Alexander Dickhans on 4/20/26.
//

#include "factory/factory_shop.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Factory Shop implementation
struct _factory_shop {
    FactoryPrototype *prototypes;
    int prototypes_len;
};

FactoryShop *create_factory_shop(const FactoryPrototype *prototypes, const size_t len) {
    // Allocate a factory
    FactoryShop *factory_shop = malloc(sizeof(FactoryShop));

    // Chack allocations
    if (factory_shop && prototypes) {
        // malloc space for the prototypes
        factory_shop->prototypes = malloc(sizeof(FactoryPrototype) * len);
        if (!factory_shop->prototypes) {
            free(factory_shop);
            return NULL;
        }

        // Copy prototype data over
        memcpy(factory_shop->prototypes, prototypes, sizeof(FactoryPrototype) * len);
        factory_shop->prototypes_len = len;
        return factory_shop;
    }

    // Free memory if fails
    free(factory_shop);
    return NULL;
}

void print_options_factory_shop(const FactoryShop *factory_shop, const char start_char) {
    // Check if the factory is null
    if (factory_shop == NULL) {
        printf("No factory shop to print options for\n");
        return;
    }

    // Print out each of the options for the factory
    for (int i = 0; i < factory_shop->prototypes_len; ++i) {
        printf("(%c): %s, rate: %.1f, for %d pickles\n", start_char + i, factory_shop->prototypes[i].name,
               factory_shop->prototypes[i].rate, factory_shop->prototypes[i].cost);
    }
}

FactoryPrototype *get_option_factory_shop(const FactoryShop *factory_shop, const char start_char, const char input) {
    // Check bounds and pointers
    if (factory_shop) {
        const int index = input - start_char;
        if (index < 0 || index >= factory_shop->prototypes_len) { return NULL; }
        return &factory_shop->prototypes[index];
    }

    return NULL;
}

void destroy_factory_shop(FactoryShop *factory_shop) {
    // Check for nullptrs and free memory
    if (factory_shop) {
        free(factory_shop->prototypes);
        free(factory_shop);
    }
}
