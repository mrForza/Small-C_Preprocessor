#include <stdlib.h>
#include <stdio.h>
#include <Data Structures/vector.h>

struct Vector* init_vector(unsigned long capacity) {
    struct Vector* vector = (struct Vector*)malloc(sizeof(struct Vector));
    vector->capacity = capacity;
    vector->size = 0;
    vector->data = (int*)malloc(capacity * sizeof(int));
    return vector;
}

struct Vector* copy_vector(struct Vector* other) {
    struct Vector* vector = (struct Vector*)malloc(sizeof(struct Vector));
    vector->capacity = other->capacity;
    vector->size = other->size;
    vector->data = (int*)malloc(vector->size * sizeof(int));

    for (int i = 0; i < vector->size; ++i) {
        vector->data[i] = other->data[i];
    }

    return vector;
}

void push_to_vector(struct Vector* vector, int num) {
    if (vector->size == vector->capacity) {
        realloc(vector->data, vector->capacity * 2);

    } else {
        vector->data[vector->size++] = num;
    }
}

void pop_from_vector(struct Vector* vector) {
    if (vector->size != 0) {
        vector->data[--vector->size] = 0;
    }
}

int get_num(struct Vector* vector, int index) {
    if (index >= 0 && index < vector->size) {
        return vector->data[index];
    }
    return 0;
}

void print_nums(struct Vector* vector) {
    for (int i = 0; i < vector->size; ++i) {
        printf("%d ", vector->data[i]);
    }
}

void destroy_vector(struct Vector* vector) {
    free(vector->data);
    free(vector);
}