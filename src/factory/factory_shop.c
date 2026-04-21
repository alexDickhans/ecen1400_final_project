//
// Created by Alexander Dickhans on 4/20/26.
//

#include "factory/factory_shop.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _factory_shop {
    FactoryPrototype *prototypes;
    int prototypes_len;
};

FactoryShop *create_factory_shop(const FactoryPrototype *prototypes, const int len) {
    FactoryShop *factory_shop = malloc(sizeof(FactoryShop));

    if (factory_shop) {
        factory_shop->prototypes = malloc(sizeof(FactoryPrototype) * len);
        memcpy(factory_shop->prototypes, prototypes, sizeof(FactoryPrototype) * len);
        factory_shop->prototypes_len = len;
    }

    return factory_shop;
}

void print_options_factory_shop(const FactoryShop *factory_shop, const char start_char) {
    if (factory_shop == NULL) {
        printf("No factory shop to print options for\n");
        return;
    }

    for (int i = 0; i < factory_shop->prototypes_len; ++i) {
        printf("(%c): %s, rate: %.1f, for %d pickles\n", start_char + i, factory_shop->prototypes[i].name,
               factory_shop->prototypes[i].rate, factory_shop->prototypes[i].cost);
    }
}

FactoryPrototype *get_option_factory_shop(const FactoryShop *factory_shop, const char start_char, const char input) {
    if (factory_shop) {
        const int index = input - start_char;
        if (index < 0 || index >= factory_shop->prototypes_len) { return NULL; }
        return &factory_shop->prototypes[index];
    }

    return NULL;
}

void destroy_factory_shop(FactoryShop *factory_shop) {
    if (factory_shop) {
        free(factory_shop->prototypes);
        free(factory_shop);
    }
}
