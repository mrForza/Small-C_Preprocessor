#include <stdlib.h>
#include <data_structures/vector.h>

void init_references_to_functions(struct Vector* vector) {
    vector->init_vector = &init_vector;
    vector->destroy_vector = &destroy_vector;
}

void init_vector(struct Vector* vector, int capacity) {
    vector->capacity = capacity;
    vector->size = 0;
    vector->data = malloc(vector->capacity * sizeof(void*));
    init_references_to_functions(vector);
}

void destroy_vector(struct Vector* vector) {
    free(vector->data);
    free(vector);
}
