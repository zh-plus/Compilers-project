#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "utils.hpp"
#include "test.hpp"
#include "type_case.hpp"

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



int main() {
	A *a = new A();
	A *b = new B();
	C *c = new C();

	Visitor v;
	v.visit(a);
	v.visit(b);

	cout << "=========" << endl;

	type_case(b,
	          [&](A *first) {
		          c->print(a);
	          },
	          [&](B *second) {
		          c->print((B *) a);
	          });


	return 0;
}
