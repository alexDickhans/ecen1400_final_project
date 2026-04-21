//
// Created by Alexander Dickhans on 4/18/26.
//

#ifndef FINAL_PROJECT_FACTORY_H
#define FINAL_PROJECT_FACTORY_H

/**
 * Prototype for a factory with price and output as well as a name.
 */
typedef struct _factory_prototype {
    char* name;
    int cost;
    double rate;
} FactoryPrototype;

/**
 * Factory node containing name, information for production and the next node for the linked list
 */
typedef struct _factory FactoryNode;

/**
 * Creates a factory based off a given prototype
 *
 * @param factory_prototype Prototype to start from
 * @param head The next element in the linked list
 * @return A new factory pointing to the head taken from the prototype.
 */
FactoryNode* create_factory(const FactoryPrototype* factory_prototype, FactoryNode* head);

/**
 * Updates the internal logic of the factory and returns how many pickles were produced that frame
 *
 * @param factory Factory node to update
 * @return Returns the amount of whole pickles that have been produced
 */
int update_factory(FactoryNode* factory);

/**
 * Prints out information about a factory in a user-friendly way
 *
 * @param factory The factory to print information for
 */
void print_factory(const FactoryNode* factory);

/**
 * Returns the factory production rate
 * @param factory The factory to get the rate of
 * @return The rate in pickles per second that the factory produces at.
 */
float get_factory_rate(const FactoryNode* factory);

/**
 * Return the next factory node in the linked list
 * @param factory The factory in the linked list
 * @return Gives the next factory in the linked list
 */
FactoryNode* next_factory(const FactoryNode* factory);

/**
 * Safely destroys and frees all memory for the objects in the entire linked list
 *
 * @param factory The factory pointer to the first element of the linked list to destroy
 */
void destroy_factories(FactoryNode* factory);


#endif // FINAL_PROJECT_FACTORY_H

