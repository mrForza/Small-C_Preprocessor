cmake_minimum_required(VERSION 3.25)
project(Small_C_Preprocessor C)

set(CMAKE_C_STANDARD 11)
set(INCLUDE_DIR include)

include_directories(${INCLUDE_DIR})
add_executable(Small_C_Preprocessor src/main.c "include/Data Structures/stack.h" "include/Data Structures/vector.h" "include/Data Structures/vector.c")
