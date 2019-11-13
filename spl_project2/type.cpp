//
// Created by 10578 on 11/5/2019.
//

#include "type.hpp"
#include "symbol.hpp"
#include "ast.hpp"
#include "semantics.hpp"

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
		} else {
			type = leaf->leaf_type;
			line_no = leaf->line_no;
		}
	}

	Array_Type::Array_Type(Leaf_Node *leaf) {
		if (leaf->leaf_type != token_type::TYPE) {
			cout << "The type class should be initialized from TYPE Leaf_Node!" << endl;
			exit(EXIT_FAILURE);
		} else {
			type = leaf->leaf_type;
			line_no = leaf->line_no;
		}
	}

	Array_Type::Array_Type(Primitive_Type type) {
		this->type = type.type;
	}

	Struct_Type::Struct_Type(StructSpecifier_Node *node) {
		struct_id = node->id->get_lexeme();

		//TODO: Read def_list into member.
		node->def_list;
	}

	Type *get_type(Specifier_Node *node) {
		if (node->type) {
			return new Primitive_Type(node->type);
		} else {
			return new Struct_Type(node->struct_specifier);
		}
	}

	std::pair<Type *, std::vector<VarDec_Node *> *> get_info(Def_Node *node) {
		auto specifier_type = get_type(node->specifier);
		auto *decs = new std::vector<VarDec_Node *>{};

		DecList_Node *dec_list = node->dec_list;
		while (dec_list->dec_list) {
			decs->push_back(dec_list->dec->var_dec);
			dec_list = dec_list->dec_list;
		}

		return std::make_pair(specifier_type, decs);
	}

}
