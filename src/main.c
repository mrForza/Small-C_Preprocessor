#include <stdio.h>
#include "Data Structures/vector.h"

int main() {
    struct Vector vec;
    init_vector(&vec, 5);
    destroy_vector(&vec);
    return 0;
}
