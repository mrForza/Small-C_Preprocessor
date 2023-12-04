#include <stdio.h>
#include <stdlib.h>
#include "data_structures/vector.h"
#include "../tests/data_structures/test_vector.c"
#include <windows.h>

int main() {
    char* name = form_complex_name("", "");
    printf("%s", name);
    //test_init_and_destroy();
    return 0;
}
