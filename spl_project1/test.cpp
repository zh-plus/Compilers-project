#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "utils.hpp"

int main() {
    using namespace std;

    const char *s = "-10";
    int a = atoi(s);

    cout << a << endl;

    const char *c = "'\x7E'";
    char ch = (char) c[1];
    char trimmed = trim(c, "'").c_str()[0];
    cout << ch << endl;

    return 0;
}
