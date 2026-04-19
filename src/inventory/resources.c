//
// Created by Alexander Dickhans on 4/18/26.
//

#include "inventory/resources.h"

#include <stdlib.h>

struct _resource {
    int placeholder;
};

Resource* create_resource(void) {
    Resource* resource = malloc(sizeof(Resource));
    if (resource) {
        resource->placeholder = 0;
    }
    return resource;
}

void destroy_resource(Resource* resource) {
    free(resource);
}
