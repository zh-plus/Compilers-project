#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "utils.hpp"
#include "test.hpp"
#include "type_switch.hpp"

//using namespace std;
using namespace T;

class A {
public:
	int i = 0;

	virtual void accept() {
		cout << "A" << endl;
	}
};

class B : public A {
public:
	void print_i() { cout << i; }

	void accept() override {
		A::accept();
		cout << "B" << endl;
	}
};

class C {
public:
	virtual void print(A *a) {
		cout << "A" << endl;
	}

	virtual void print(B *B) {
		cout << "B" << endl;
	}
};

class Visitor {
public:
	static void visit(A *a) {
		a->accept();
	}

	static void visit(B *b) {
		b->accept();
	}
};

int value = 0;

int &r_get() {
	return value;
}

struct s {
	int a, b[10][20];
	float c;
};

struct s1 {
	int a, b[10][20];
	float c;
};

class Test {
public:
	vector<int> v;
};

struct test_s;

class MyBaseClass {
public:
	virtual ~MyBaseClass() {}
};

class MyDerivedA : public MyBaseClass {
};

class MyDerivedB : public MyBaseClass {
};

int g = 0;

int compare1(int x, int y) {
	if (x > y) { return 1; }
	else if (y > x) { return -1; }
	else { return 0; }
}

float compare2(int a, int b) {
	if (b > a) { return -1.0; }
	if (b == a) { return 0.0; }
	return 1.0;
}

int test_2_r08(int i, int m, int n) {
	if (i == 0) {
		return compare1(m, n);
	} else {
		return compare2(m, n);
	}
}


int main() {
	A *a = new A();
	A *b = new B();
	C *c = new C();

	Visitor v;
	v.visit(a);
	v.visit(b);

	struct s test_s{};
	struct s1 test_s1{};
	cout << test_s.a << endl;

	Test t;
	t.v.push_back(1);
	for (auto &x: t.v) {
		cout << x << endl;
	}

	string s1 = "1234562222";
	string s2 = "1234562222";

	cout << (s1 == s2 ? "true" : "false") << endl;

	int i = 1;
	switch (i) {
		case 1: {
			cout << 1 << endl;
		}
		case 2: {
			cout << 2 << endl;
		}
		default:
			cout << "Default" << endl;
	}

	return 0;
}
