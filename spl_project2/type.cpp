//
// Created by 10578 on 11/5/2019.
//

#include "symbol.hpp"

namespace SPL {
	using namespace std;

	ostream &operator<<(ostream &os, const Type &obj) {
		os << obj.to_string();
		return os;
	}

	Primitive_Type::Primitive_Type(SPL::Leaf_Node leaf) {
		if (leaf.leaf_type != SPL::token_type::TYPE) {
			cout << "The type class should be initialized from TYPE Leaf_Node!" << endl;
			exit(EXIT_FAILURE);
		} else {
			type = leaf.leaf_type;
			line_no = leaf.line_no;
		}
	}

	Array_Type::Array_Type(SPL::Leaf_Node leaf) {
		if (leaf.leaf_type != SPL::token_type::TYPE) {
			cout << "The type class should be initialized from TYPE Leaf_Node!" << endl;
			exit(EXIT_FAILURE);
		} else {
			type = leaf.leaf_type;
			line_no = leaf.line_no;
		}
	}
}

