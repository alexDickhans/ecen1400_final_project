//
// Created by Alexander Dickhans on 4/20/26.
//

#ifndef FINAL_PROJECT_FACTORY_SHOP_H
#define FINAL_PROJECT_FACTORY_SHOP_H

#include <stdio.h>

#include "factory.h"

/**
 * Struct to store a shop of factory prototypes for a user to buy
 */
typedef struct _factory_shop FactoryShop;

/**
 * Create a new factory store
 *
 * @param prototypes List of factory prototypes
 * @param len Length of the prototypes list
 * @return New factory shop if successful, if unsuccessful, returns NULL
 */
FactoryShop* create_factory_shop(const FactoryPrototype* prototypes, size_t len);

/**
 * Prints out the options for the factory shop object with all the factories and their price and rates
 *
 * @param factory_shop FactoryShop Object
 * @param start_char character to start the options at
 */
void print_options_factory_shop(const FactoryShop* factory_shop, char start_char);

/**
 * Get the option that the user selected from the print_options_factory_shop
 *
 * @param factory_shop FactoryShop object
 * @param start_char character the options started at
 * @param input the input character that the user selected
 * @return The FactoryPrototype object of the selected option if found, NULL if otherwise
 */
FactoryPrototype* get_option_factory_shop(const FactoryShop* factory_shop, char start_char, char input);

/**
 * Destroy the factory shop safely
 *
 * @param factory_shop FactoryShop object
 */
void destroy_factory_shop(FactoryShop* factory_shop);

#endif //FINAL_PROJECT_FACTORY_SHOP_H
