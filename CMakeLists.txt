cmake_minimum_required(VERSION 3.10)
project(compilers CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(test spl_project2/test.cpp spl_project2/utils.cpp)
add_executable(test_symbol spl_project2/test_symbol.cpp spl_project2/parser.tab.cpp)
add_executable(splc spl_project2/main.cpp spl_project2/spl_driver.cpp spl_project2/utils.cpp spl_project2/ast.cpp spl_project2/parser.tab.cpp spl_project2/symbol.cpp spl_project2/type_case.hpp )