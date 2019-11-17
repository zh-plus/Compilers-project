//
// Created by 10578 on 11/5/2019.
//

#include "type.hpp"
#include "ast.hpp"

namespace SPL {
	using namespace std;

	ostream &operator<<(ostream &os, const Type &obj) {
		os << obj.to_string();
		return os;
	}

	Primitive_Type::Primitive_Type(Leaf_Node *leaf) {
		if (leaf->leaf_type != token_type::TYPE) {
			cout << "The type class should be initialized from TYPE Leaf_Node!" << endl;
			exit(EXIT_FAILURE);
		}

		string type_name = leaf->get_lexeme();
		type = [&]() {
			if (type_name == "int") {
				return primitive_type::INT;
			} else if (type_name == "float") {
				return primitive_type::FLOAT;
			} else if (type_name == "char") {
				return primitive_type::CHAR;
			} else {
				cout << "The TYPE Leaf_Node should be one of [int, float, char]!" << endl;
				exit(EXIT_FAILURE);
			}
		}();

		line_no = leaf->line_no;
	}

	Array_Type::Array_Type(Type *base_type, Array_VarDec_Node *array_node) {
		line_no = base_type->line_no;
		m_base_type = base_type;

		VarDec_Node *var_dec = array_node;
		while (!var_dec->is_atomic()) {
			shape.push_back(stoi(dynamic_cast<Array_VarDec_Node *>(var_dec)->_int->get_lexeme()));
			var_dec = dynamic_cast<Array_VarDec_Node *>(var_dec)->var_dec;
		}

		std::reverse(shape.begin(), shape.end());
	}


    Struct_Type::Struct_Type(std::string id, int line_no, std::vector<std::pair<std::string, Type *>> member_vector) {
        this->struct_id = id;
        this->line_no = line_no;

        for (auto &p: member_vector) {
            members.insert(p);
        }
    }

}
