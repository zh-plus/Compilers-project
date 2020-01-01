//
// Created by 10578 on 10/8/2019.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <regex>

#include "spl_driver.hpp"

//#define LOCAL

using namespace std;

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

#ifndef LOCAL
		string source_name(argv[1]);
		string out_name = regex_replace(source_name, regex("spl"), "ir");

		ofstream out_f(out_name);
		auto cout_buf = cout.rdbuf(out_f.rdbuf());
#endif

		if (driver.grammar_error_reported()) {
			driver.print_errors(driver.get_grammar_errors());
#ifndef LOCAL
			cout.rdbuf(cout_buf);
#endif
			return EXIT_SUCCESS;
		}

#ifdef LOCAL
		driver.get_ast()->print();
#endif

		driver.semantic_analyze();
		if (driver.semantic_error_reported()) {
			driver.print_errors(driver.get_semantic_errors());
		}

		driver.generate_ir();

#ifndef LOCAL
		cout.rdbuf(cout_buf);
#endif
	} else {
		cout << "Only one parameter permitted! Use -h to see usage." << endl;
		return EXIT_FAILURE;
	}
}
