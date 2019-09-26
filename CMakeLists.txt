cmake_minimum_required(VERSION 3.10)
project(lab C)

set(CMAKE_C_STANDARD 11)

add_executable(test spl_lexer/test.c)
add_executable(helpler spl_lexer/helpler.c)