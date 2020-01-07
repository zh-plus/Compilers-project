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

#ifndef LOCAL
		string source_name(argv[1]);
		string out_name = regex_replace(source_name, regex("ir"), "s");

		ofstream out_f(out_name);
		auto cout_buf = cout.rdbuf(out_f.rdbuf());
#endif

		driver.ir2asm(argv[1]);

#ifndef LOCAL
		cout.rdbuf(cout_buf);
#endif
	} else {
		cout << "Only one parameter permitted! Use -h to see usage." << endl;
		return EXIT_FAILURE;
	}
}
