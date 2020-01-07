#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <utility>
#include <unistd.h>

#include "utils.hpp"

using namespace std;

void write(int n) {
	cout << n << endl;
}

int read() {
	int result = 0;
	cin >> result;
	return result;
}

int hanoi(int n, int p1, int p2, int p3) {
	if (n == 1) {
		write(p1 * 10000 + p3);
	} else {
		hanoi(n - 1, p1, p3, p2);
		write(p1 * 10000 + p3);
		hanoi(n - 1, p2, p1, p3);
	}
	return 0;
}

int main() {
	int sum = 1;
	hanoi(sum, 1, 2, 3);
	return 0;
}




//121