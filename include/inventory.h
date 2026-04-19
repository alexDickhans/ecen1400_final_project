//
// Created by Alexander Dickhans on 4/18/26.
//

#ifndef FINAL_PROJECT_INVENTORY_H
#define FINAL_PROJECT_INVENTORY_H

typedef struct _inventory Inventory;

Inventory* create_inventory(void);

void destroy_inventory(Inventory* inventory);

#endif // FINAL_PROJECT_INVENTORY_H
