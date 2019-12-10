#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <utility>

using namespace std;

class Label {
public:
	string name;

	Label() {
		name = "label_" + std::to_string(get_number());
	};

	[[nodiscard]] string to_string() const {
		return name;
	}

	static int get_number() {
		return number++;
	}

private:
	static int number;
};

int Label::number = 0;

template<typename T>
void print_labels(initializer_list<T> l) {
	for (auto &&x: l) {
		cout << x.to_string() << endl;
	}
}

int main() {
	auto l1 = Label();
	auto l2 = Label();
	auto l3 = Label();
	auto l4 = Label();

	print_labels({l1, l2, l3, l4});
	print_labels({Label(), Label()});

	int n;
	(n + 1) = 10;

	return 0;
}
