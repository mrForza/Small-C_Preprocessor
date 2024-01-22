#include "tests.h"
#include <windows.h>
#include "file_handler/file_validator.h"

#define PASSED "this testcase has passed!\n"
#define FAILURE "this testcase has failured!\n"
#define BOOL_EXPR(value) value ? "true" : "false"

HANDLE console;

struct test_case VALIDATE_NAME_TESTCASES[5] = {
    {"correct_name", (void*)"file.c", (void*)true},
    {"no_extension", (void*)"filenamec", (void*)false},
    {"no_name", (void*)".c", (void*)false},
    {"empty_filename", (void*)"", (void*)false},
    {"forbidden_symbol", (void*)"abc+.c", (void*)false},
};


struct test_case VALIDATE_EXTENSION_TESTCASES[] = {
        {"correct_extension", (void*)"c", (void*)true},
        {"correct_extension", (void*)"h", (void*)true},
        {"incorrect_long_extension", (void*)"cpp", (void*)false},
        {"incorrect_long_extension", (void*)"class", (void*)false},
        {"incorrect_long_extension", (void*)"py", (void*)false},
        {"incorrect_long_extension", (void*)"pycache", (void*)false},
        {"incorrect_short_extension", (void*)"a", (void*)false},
        {"incorrect_short_extension", (void*)"b", (void*)false},
        {"empty_extension", (void*)"", (void*)false},
};


void test_validate_filename() {
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    unsigned long long size = sizeof(VALIDATE_NAME_TESTCASES) / sizeof(struct test_case);
    for (unsigned long long i = 0; i < size; ++i) {
        struct test_case test_case = VALIDATE_NAME_TESTCASES[i];
        SetConsoleTextAttribute(console, 1);
        printf("TestCase %llu {%s}: ", i, test_case.name);
        bool result = validate_filename((char*)test_case.input_params);
        bool expected_result = test_case.output_params;
        if ((bool*)result == (bool*)test_case.output_params) {
            SetConsoleTextAttribute(console, 2);
            printf("%s == %s\t %s", BOOL_EXPR(result), BOOL_EXPR(expected_result), PASSED);
        } else {
            SetConsoleTextAttribute(console, 4);
            printf("%s != %s\t %s", BOOL_EXPR(result), BOOL_EXPR(expected_result), FAILURE);
        }
    }
}


void test_validate_extension() {
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    unsigned long long size = sizeof(VALIDATE_EXTENSION_TESTCASES) / sizeof(struct test_case);
    for (unsigned long long i = 0; i < size; ++i) {
        struct test_case test_case = VALIDATE_EXTENSION_TESTCASES[i];
        SetConsoleTextAttribute(console, 1);
        printf("TestCase %llu {%s}: ", i, test_case.name);
        bool result = validate_extension((char*)test_case.input_params);
        bool expected_result = test_case.output_params;
        if ((bool*)result == (bool*)test_case.output_params) {
            SetConsoleTextAttribute(console, 2);
            printf("%s == %s\t %s", BOOL_EXPR(result), BOOL_EXPR(expected_result), PASSED);
        } else {
            SetConsoleTextAttribute(console, 4);
            printf("%s != %s\t %s", BOOL_EXPR(result), BOOL_EXPR(expected_result), FAILURE);
        }
    }
}