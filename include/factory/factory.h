//
// Created by Alexander Dickhans on 4/18/26.
//

#ifndef FINAL_PROJECT_FACTORY_H
#define FINAL_PROJECT_FACTORY_H

typedef struct _factory_prototype {
    char* name;
    int cost;
    double rate;
} FactoryPrototype;

typedef struct _factory FactoryNode;

FactoryNode* create_factory(const FactoryPrototype* factory_prototype, FactoryNode* head);

int update_factory(FactoryNode* factory);

void print_factory(const FactoryNode* factory);

float get_factory_rate(const FactoryNode* factory);

FactoryNode* next_factory(const FactoryNode* factory);

void destroy_factories(FactoryNode* factory);


#endif // FINAL_PROJECT_FACTORY_H

