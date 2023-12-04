#include <stdio.h>
#include <windows.h>
#include <string.h>

#define ERROR_CONSOLE_COLOR 4
#define SUCCESS_CONSOLE_COLOR 2

void swap_chars(char* first_char, char* second_char) {
    char temp_char = *first_char;
    *first_char = *second_char;
    *second_char = temp_char;
}

void print_test_info(const char* message, int error_flag) {
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (error_flag) {
        SetConsoleTextAttribute(hConsole, ERROR_CONSOLE_COLOR);
    } else {
        SetConsoleTextAttribute(hConsole, SUCCESS_CONSOLE_COLOR);
    }
    printf("%s", message);
}

char* form_complex_name(const char* name_of_test, const char* tests_number) {
    char* complex_name = (char*)malloc(strlen(name_of_test) + strlen(tests_number) + 6 + 1);

    complex_name[0] = '[';
    for (int i = 0; i < strlen(name_of_test); ++i) {
        complex_name[i + 1] = name_of_test[i];
    }

    complex_name[strlen(name_of_test) + 1] = ' ';
    complex_name[strlen(name_of_test) + 2] = 'N';

    for (int i = 0; i < strlen(tests_number); ++i) {
        complex_name[i + strlen(name_of_test) + 3] = tests_number[i];
    }

    complex_name[strlen(name_of_test) + strlen(tests_number) + 3] = ']';
    complex_name[strlen(name_of_test) + strlen(tests_number) + 4] = ':';
    complex_name[strlen(name_of_test) + strlen(tests_number) + 5] = ' ';
    complex_name[strlen(name_of_test) + strlen(tests_number) + 6] = '\0';

    return complex_name;
}

char* form_verdict(const char* verdict, const char* true_value, const char* curr_value) {
    char* full_verdict = (char*)malloc(strlen(verdict) + strlen(true_value) + strlen(curr_value) + 1);

    for (int i = 0; i < strlen(verdict); ++i) {
        full_verdict[i] = verdict[i];
    }

    full_verdict[strlen(verdict)] = '\t';

    for (int i = 0; i < strlen(true_value); ++i) {
        full_verdict[strlen(verdict) + i + 1] = true_value[i];
    }

    full_verdict[strlen(verdict) + strlen(true_value) + 1] = ' ';
    if (verdict[0] == 'P') {
        full_verdict[strlen(verdict) + strlen(true_value) + 2] = '=';
    } else {
        full_verdict[strlen(verdict) + strlen(true_value) + 2] = '!';
    }
    full_verdict[strlen(verdict) + strlen(true_value) + 3] = '=';
    full_verdict[strlen(verdict) + strlen(true_value) + 4] = ' ';

    for (int i = 0; i < strlen(curr_value); ++i) {
        full_verdict[strlen(verdict) + strlen(true_value) + 5 + i] = curr_value[i];
    }

    full_verdict[strlen(verdict) + strlen(true_value) + strlen(curr_value) + 5] = '\0';
    return full_verdict;
}

char* stoi(unsigned int number) {
    if (number == 0) {
        return "0";
    }

    unsigned int temp_number = number;
    unsigned int count_of_digits = 0;

    while (temp_number > 0) {
        ++count_of_digits;
        temp_number /= 10;
    }

    char* string_number = (char*)malloc(count_of_digits + 1);
    int i = 0;
    while (number > 0) {
        unsigned char remainder = number % 10;
        string_number[i++] = remainder + '0';
        number /= 10;
    }

    unsigned int left = 0;
    unsigned int right = count_of_digits - 1;
    while (left < right) {
        swap_chars(&string_number[left], &string_number[right]);
        ++left;
        --right;
    }
    string_number[count_of_digits] = '\0';

    return string_number;
}

char* concat(const char* first_string, const char* second_string) {
    char* result_string = (char*)malloc(strlen(first_string) + strlen(second_string) + 1);
    for (int i = 0; i < strlen(first_string); ++i) {
        result_string[i] = first_string[i];
    }
    for (int i = 0; i < strlen(second_string); ++i) {
        result_string[strlen(first_string) + i] = second_string[i];
    }
    result_string[strlen(first_string) + strlen(second_string)] = '\0';
    return result_string;
}