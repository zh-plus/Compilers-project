//
// Created by 10578 on 10/8/2019.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <fstream>
#include <iomanip>
#include <regex>

#include "spl_driver.hpp"

using namespace std;

template<typename InputIterator1, typename InputIterator2>
bool
range_equal(InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, InputIterator2 last2) {
	while (first1 != last1 && first2 != last2) {
		if (*first1 != *first2) return false;
		++first1;
		++first2;
	}
	return (first1 == last1) && (first2 == last2);
}

bool compare_files(const std::string &filename1, const std::string &filename2) {
	std::ifstream file1(filename1);
	std::ifstream file2(filename2);

	if (not file1.good() && not file2.good()) {
		cout << "File not good!" << endl;
		return false;
	}

	std::istreambuf_iterator<char> begin1(file1);
	std::istreambuf_iterator<char> begin2(file2);

	std::istreambuf_iterator<char> end;

	return range_equal(begin1, end, begin2, end);
}

string leading_zero(int number, int leading_width = 2) {
	stringstream ss;
	ss << setw(leading_width) << setfill('0') << number;
	return ss.str();
}

void project1(string input) {
	SPL::SPL_Driver driver;
	driver.parse(input.c_str());

	const string &source_name(input);
	string out_name = regex_replace(source_name, regex("spl"), "out");

	ofstream out_f(out_name);
	auto cout_buf = cout.rdbuf(out_f.rdbuf());

	if (driver.grammar_error_reported()) {
		driver.print_errors(driver.get_grammar_errors());
	} else {
		driver.get_ast()->print();
	}

	cout.rdbuf(cout_buf);
}

void project2(string input) {
	SPL::SPL_Driver driver;
	driver.parse(input.c_str());

	const string &source_name(input);
	string out_name = regex_replace(source_name, regex("spl"), "out");

	ofstream out_f(out_name);
	auto cout_buf = cout.rdbuf(out_f.rdbuf());

	if (driver.grammar_error_reported()) {
		driver.print_errors(driver.get_grammar_errors());
		cout.rdbuf(cout_buf);
		exit(EXIT_SUCCESS);
	}

	driver.semantic_analyze();
	if (driver.semantic_error_reported()) {
		driver.print_errors(driver.get_semantic_errors());
	}

	cout.rdbuf(cout_buf);
}

void check_test1() {
	cout << "Checking test1 ..." << endl;

	string test_spl_path;
	string test_output_name;
	string test_output_path;
	string test_ans_path;
	string command;

	/* o... files */
	for (int i = 1; i <= 1; ++i) {
		test_spl_path = "test1/test_1_o" + leading_zero(i) + ".spl";
		test_output_name = "test_1_o" + leading_zero(i) + ".out";
		test_output_path = "test1/" + test_output_name;
		test_ans_path = "test1/answer/" + test_output_name;

		project1(test_spl_path);

		if (not compare_files(test_output_path, test_ans_path)) {
			cout << "Check fail: " << test_output_path << endl;
			exit(EXIT_FAILURE);
		}
	}

	/* r... files */
	for (int i = 1; i <= 4; ++i) {
		test_spl_path = "test1/test_1_r" + leading_zero(i) + ".spl";
		test_output_name = "test_1_r" + leading_zero(i) + ".out";
		test_output_path = "test1/" + test_output_name;
		test_ans_path = "test1/answer/" + test_output_name;

		project1(test_spl_path);

		if (not compare_files(test_output_path, test_ans_path)) {
			cout << "Check fail: " << test_output_path << endl;
			exit(EXIT_FAILURE);
		}
	}
}

void check_test2() {
	cout << "Checking test2 ..." << endl;

	string test_spl_path;
	string test_output_name;
	string test_output_path;
	string test_ans_path;
	string command;

	/* o... files */
	for (int i = 1; i <= 2; ++i) {
		test_spl_path = "test2/test_2_o" + leading_zero(i) + ".spl";
		test_output_name = "test_2_o" + leading_zero(i) + ".out";
		test_output_path = "test2/" + test_output_name;
		test_ans_path = "test2/answer/" + test_output_name;

		project2(test_spl_path);

		if (not compare_files(test_output_path, test_ans_path)) {
			cout << "Check fail: " << test_output_path << endl;
			exit(EXIT_FAILURE);
		}
	}

	/* r... files */
	for (int i = 1; i <= 15; ++i) {
		test_spl_path = "test2/test_2_r" + leading_zero(i) + ".spl";
		test_output_name = "test_2_r" + leading_zero(i) + ".out";
		test_output_path = "test2/" + test_output_name;
		test_ans_path = "test2/answer/" + test_output_name;

		project2(test_spl_path);

		if (not compare_files(test_output_path, test_ans_path)) {
			cout << "Check fail: " << test_output_path << endl;
			exit(EXIT_FAILURE);
		}
	}

}

int main(const int argc, const char **argv) {
	check_test1();
	check_test2();

	cout << "Check success!" << endl;
	cout << "Done" << endl;

	return 0;
}
