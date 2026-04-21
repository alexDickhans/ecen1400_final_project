//
// Created by Alexander Dickhans on 4/20/26.
//

#ifndef FINAL_PROJECT_FACTORY_SHOP_H
#define FINAL_PROJECT_FACTORY_SHOP_H

#include "factory.h"

typedef struct _factory_shop FactoryShop;

FactoryShop* create_factory_shop(const FactoryPrototype* prototypes, int len);

void print_options_factory_shop(const FactoryShop* factory_shop, char start_char);

FactoryPrototype* get_option_factory_shop(const FactoryShop* factory_shop, char start_char, char input);

void destroy_factory_shop(FactoryShop* factory_shop);

#endif //FINAL_PROJECT_FACTORY_SHOP_H
