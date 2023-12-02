#include <stdio.h>
#include "Data Structures/vector.h"

int main() {
    struct Vector* vector = init_vector(4);
    for (int i = 123; i <= 130; ++i) {
        push_to_vector(vector, i);
    }
    print_nums(vector);

    struct Vector* vector2 = copy_vector(vector);
    for (int i = 0; i < vector2->size; ++i) {
        vector2->data[i] += 2;
    }
    printf("\n");
    print_nums(vector2);

    pop_from_vector(vector2);
    pop_from_vector(vector2);
    printf("\n");
    print_nums(vector2);

    printf("\n");
    printf("%d", get_num(vector2, 0));
    destroy_vector(vector);
    destroy_vector(vector2);
    return 0;
}
