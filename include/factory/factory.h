//
// Created by Alexander Dickhans on 4/18/26.
//

#ifndef FINAL_PROJECT_FACTORY_H
#define FINAL_PROJECT_FACTORY_H

#include "inventory/resources.h"

typedef struct _factory Factory;

Factory* create_factory(void);

void destroy_factory(Factory* factory);

#endif // FINAL_PROJECT_FACTORY_H

