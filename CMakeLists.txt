cmake_minimum_required(VERSION 3.25)
project(Small_C_Preprocessor C)

set(CMAKE_C_STANDARD 11)
set(INCLUDE_DIR include)
set(TEST_DIR tests)

include_directories(${INCLUDE_DIR})
include_directories(${TEST_DIR})
add_executable(
    Small_C_Preprocessor
    src/main.c
        include/file_handler/file_handler.h
        include/file_handler/file_validator.h
        include/file_handler/file_validator.c
    tests/tests.h
)
