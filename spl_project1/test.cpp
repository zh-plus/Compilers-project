#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "utils.hpp"

using namespace std;


vector<int> get_v(){
    return vector<int>{1, 4};
}



int main() {


    const char *s = "-10";
    int a = atoi(s);

    cout << a << endl;

    const char *c = "'\x7E'";
    char ch = (char) c[1];
    char trimmed = SPL::trim(c, "'").c_str()[0];
    cout << ch << endl;

    vector<int> v = get_v();
    for (auto &x: v) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> *ve = nullptr;
    if (ve) {
        cout << "True!";
    }

    Def_Node node;
    cout << typeid(node).name() << endl;

    return 0;
}
