//
// Created by 10578 on 10/29/2019.
//

#include "symbol.hpp"
#include "parser.tab.hpp"

using namespace SPL;
using namespace std;

int main() {
	vector<Symbol_Table *> scope_stacks{new Global_Symbol_Table{}};
	scope_stacks.push_back(new Local_Symbol_Table(*scope_stacks.begin()));
	scope_stacks.push_back(new Local_Symbol_Table(scope_stacks[1]));

	scope_stacks[0]->insert(new Variable_Symbol("test1", new Primitive_Type(token_type::INT)));
	scope_stacks[0]->insert(new Variable_Symbol("test2", new Primitive_Type(token_type::CHAR)));
	scope_stacks[0]->insert(new Variable_Symbol("test3", new Primitive_Type(token_type::FLOAT)));

	scope_stacks[1]->insert(new Function_Symbol("fn1", new Primitive_Type(token_type::INT),
	                                            {new Primitive_Type(token_type::FLOAT)}));

	int i = 0;
	for (auto &x: scope_stacks) {
		cout << "scope stack " << i << endl;
		for (auto &y: x->get_table()) {
			cout << "key: " << y.first << "\t=====\t"
			     << "value: " << *(y.second) << endl;
		}
		++i;
	}

	return 0;
}
