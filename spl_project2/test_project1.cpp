//
// Created by 10578 on 10/29/2019.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>

#include "spl_driver.hpp"
#include "symbol.hpp"

using namespace std;
using namespace SPL;

void print_scope_stack(vector<Symbol_Table *> scope_stacks) {
    int i = 0;
    for (auto &x: scope_stacks) {
        cout << "scope stack " << i << endl;
        cout << x->to_string() << endl;
        ++i;
    }
}

int main(const int argc, const char **argv) {
    if (argc == 2) {
        SPL::SPL_Driver driver;

        if (std::strncmp(argv[1], "-o", 2) == 0) {
            driver.parse(std::cin);
        } else if (std::strncmp(argv[1], "-h", 2) == 0) {
            cout << "use -o for pipe to std::cin" << endl;
            cout << "just give a filename to count from a file" << endl;
            cout << "use -h to get this menu" << endl;
            return EXIT_SUCCESS;
        } else {
            driver.parse(argv[1]);
        }

        if (driver.grammar_error_reported()) {
            driver.print_errors(driver.get_grammar_errors());
            return EXIT_SUCCESS;
        } else {
            driver.get_ast()->print();
        }

    } else {
        cout << "Only one parameter permitted! Use -h to see usage." << endl;
        return EXIT_FAILURE;
    }
}
