cmake_minimum_required(VERSION 3.10)
project(compilers CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(SPL_Parser parser.y ${CMAKE_CURRENT_SOURCE_DIR}/parser.tab.cpp)
FLEX_TARGET(SPL_Scanner scanner.l ${CMAKE_CURRENT_SOURCE_DIR}/scanner.yy.cpp)
ADD_FLEX_BISON_DEPENDENCY(SPL_Scanner SPL_Parser)

set(SRCS main.cpp spl_driver.cpp utils.cpp ast.cpp symbol.cpp visitor.cpp type.cpp type_switch.hpp semantics.cpp error.cpp information.cpp)

add_executable(splc ${SRCS} ${BISON_SPL_Parser_OUTPUTS} ${FLEX_SPL_Scanner_OUTPUTS})
