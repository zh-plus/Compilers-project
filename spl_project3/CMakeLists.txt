cmake_minimum_required(VERSION 3.10)
project(compilers CXX)

set(CMAKE_CXX_STANDARD 17)

set(SRCS main.cpp spl_driver.cpp utils.cpp ast.cpp parser.tab.cpp scanner.yy.cpp symbol.cpp visitor.cpp type.cpp type_switch.hpp semantics.cpp error.cpp information.cpp)

add_executable(splc ${SRCS})