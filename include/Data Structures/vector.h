#ifndef SMALL_C_PREPROCESSOR_VECTOR_H
#define SMALL_C_PREPROCESSOR_VECTOR_H

#define MIN_CAPACITY 4;

struct Vector {
    void** data;
    unsigned int size;
    unsigned int capacity;

    void (*init_vector) (struct Vector* vector);
    void (*copy_vector) (struct Vector* vector, struct Vector* other_vector);
    void (*destroy_vector) (struct Vector* vector);

    void (*push) (struct Vector* vector, void* pointer_to_value);
    void (*pop) (struct Vector* vector);
    void (*get) (struct Vector* vector, int index);
};

#endif
