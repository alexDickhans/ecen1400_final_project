//
// Created by Alexander Dickhans on 4/18/26.
//

#include "factory/recipe.h"

#include <stdlib.h>

struct _recipe {
    int placeholder;
};

Recipe* create_recipe(void) {
    Recipe* recipe = malloc(sizeof(Recipe));
    if (recipe) {
        recipe->placeholder = 0;
    }
    return recipe;
}

void destroy_recipe(Recipe* recipe) {
    free(recipe);
}
