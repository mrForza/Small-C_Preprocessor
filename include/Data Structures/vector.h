#ifndef SMALL_C_PREPROCESSOR_VECTOR_H
#define SMALL_C_PREPROCESSOR_VECTOR_H

struct Vector {
    int* data;
    unsigned int size;
    unsigned int capacity;
};

struct Vector* init_vector(unsigned long capacity); // Constructor

struct Vector* copy_vector(struct Vector* other); // Copy constructor

void push_to_vector(struct Vector* vector, int num); // Push

int get_num(struct Vector* vector, int index); // Get

void pop_from_vector(struct Vector* vector); // Pop

void print_nums(struct Vector* vector); // Print

void destroy_vector(struct Vector* vector); // Destructor

#endif
