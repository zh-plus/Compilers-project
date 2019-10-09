cmake_minimum_required(VERSION 3.10)
project(compilers CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(test spl_project1/test.cpp)
add_executable(splc spl_project1/main.cpp spl_project1/spl_driver.cpp)