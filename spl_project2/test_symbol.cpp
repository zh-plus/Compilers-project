//
// Created by 10578 on 10/29/2019.
//

#include "symbol.hpp"
#include "parser.tab.hpp"

using namespace SPL;
using namespace std;

int main() {
    Symbol_Table st{};

    st.insert("test1",
              new Function_Symbol(10,
                                  new Primitive_Type(token_type::INT),
                                  {new Primitive_Type(token_type::INT), new Primitive_Type(token_type::CHAR)}));

    for (auto &x: st.get_tables()) {
        for (pair<const string, Symbol_Entry *> &y: *x) {
            cout << "key: " << y.first << "\t=====\t"
            << "value: " << *(y.second) << endl;
        }
    }

    return 0;
}
