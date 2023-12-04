#include <data_structures/vector.h>
#include <../src/utils.c>

struct InitDestroyFixture {
    struct Vector vector;
    int sample_size;
    int sample_capacity;
};

void test_size(struct InitDestroyFixture* test_cases, int size) {
    const char* name_of_test = "Check size test";
    const char* INCORRECT_SIZE = "\tThe vector has an incorrect size after initialization!\n";

    char* verdict;
    for (int i = 0; i < size; ++i) {
        char* full_name = form_complex_name(name_of_test, stoi(i));
        int error_flag = 0;

        if (test_cases[i].vector.size == test_cases[i].sample_size) {
            verdict = "PASSED";
        } else {
            verdict = "FAILURE";
            error_flag = 1;
        }
        char* full_verdict = form_verdict(
            verdict,
            stoi(test_cases[i].sample_size),
            stoi(test_cases[i].vector.size)
        );
        char* full_message = concat(full_name, full_verdict);
        print_test_info(full_message, error_flag);
        printf("%s", error_flag == 1 ? INCORRECT_SIZE : "\n");

        free(full_name);
        free(full_verdict);
        free(full_message);
    }
}

void test_capacity(struct InitDestroyFixture* test_cases, int size) {
    const char* name_of_test = "Check capacity test";
    const char* INCORRECT_SIZE = "\tThe vector has an incorrect capacity!\n";

    char* verdict;
    for (int i = 0; i < size; ++i) {
        char* full_name = form_complex_name(name_of_test, stoi(i));
        int error_flag = 0;

        if (test_cases[i].vector.capacity == test_cases[i].sample_capacity) {
            verdict = "PASSED";
        } else {
            verdict = "FAILURE";
            error_flag = 1;
        }
        char* full_verdict = form_verdict(
            verdict,
            stoi(test_cases[i].sample_capacity),
            stoi(test_cases[i].vector.capacity)
        );
        char* full_message = concat(full_name, full_verdict);
        print_test_info(full_message, error_flag);
        printf("%s", error_flag == 1 ? INCORRECT_SIZE : "\n");

        free(full_name);
        free(full_verdict);
        free(full_message);
    }
}

void test_init_and_destroy() {
    struct InitDestroyFixture test_cases[5] = {
        {{NULL,0, 0}, 0, 0},
        {{NULL,0, 0}, 0, 7},
        {{NULL,0, 0}, 0, 16},
        {{NULL,0, 0}, 0, 512},
    };
    int size = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < size; ++i) {
        init_references_to_functions((struct Vector *) &test_cases[i]);
    }

    test_cases[0].vector.init_vector((struct Vector *) &test_cases[0], 0);
    test_cases[1].vector.init_vector((struct Vector *) &test_cases[1], 7);
    test_cases[2].vector.init_vector((struct Vector *) &test_cases[2], 16);
    test_cases[3].vector.init_vector((struct Vector *) &test_cases[3], 512);

    test_size(test_cases, size);
    test_capacity(test_cases, size);
}