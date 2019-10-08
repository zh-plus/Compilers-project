//
// Created by 10578 on 10/8/2019.
//

#include <iostream>
#include <cstdlib>
#include <cstring>

#include "spl_driver.hpp"

int main(const int argc, const char **argv) {
    if (argc == 2) {
        SPL::SPL_Driver driver;

        if (std::strncmp(argv[1], "-o", 2) == 0) {
            driver.parse(std::cin);
        } else if (std::strncmp(argv[1], "-h", 2) == 0) {
            std::cout << "use -o for pipe to std::cin" << std::endl;
            std::cout << "just give a filename to count from a file" << std::endl;
            std::cout << "use -h to get this menu" << std::endl;
            return EXIT_SUCCESS;
        } else {
            driver.parse(argv[1]);
        }
        driver.print(std::cout) << std::endl;
    } else {
        std::cout << "Only one parameter permitted! Use -h to see usage." << std::endl;
        return EXIT_FAILURE;
    }
}
