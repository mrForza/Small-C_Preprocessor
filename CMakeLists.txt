cmake_minimum_required(VERSION 3.25)
project(Small_C_Preprocessor C)

set(CMAKE_C_STANDARD 11)
set(INCLUDE_DIR include)
set(TEST_DIR tests)

include_directories(${INCLUDE_DIR})
include_directories(${TEST_DIR})
add_executable(Small_C_Preprocessor src/main.c "include/data_structures/stack.h" "include/data_structures/vector.h" "include/data_structures/vector.c")
