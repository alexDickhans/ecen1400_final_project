//
// Created by Alexander Dickhans on 4/18/26.
//

#include "inventory/inventory.h"

#include <stdlib.h>

struct _inventory {
    int placeholder;
};

Inventory* create_inventory(void) {
    Inventory* inventory = malloc(sizeof(Inventory));
    if (inventory) {
        inventory->placeholder = 0;
    }
    return inventory;
}

void destroy_inventory(Inventory* inventory) {
    free(inventory);
}
