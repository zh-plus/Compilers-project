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


	Struct_Type::Struct_Type(StructSpecifier_Node *node) {
		line_no = node->propagate_line_no();
		struct_id = node->id->get_lexeme();

		// Read def_list into member.
		DefList_Node *def_list = node->def_list;
		while (!def_list->is_empty()) {
			auto info = get_info(def_list->def);
			Type *specifier_type = info.first;
			for (VarDec_Node *var_dec: *info.second) {
				Type *type = specifier_type;
				string id = var_dec->get_id();
				if (!var_dec->is_atomic()) {
					// Array type
					type = new Array_Type(specifier_type, dynamic_cast <Array_VarDec_Node *>(var_dec));
				}

				members.insert(make_pair(id, type));
			}

			def_list = def_list->def_list;
		}
	}

	Type *get_type(Specifier_Node *node) {
		if (node->type) {
			return new Primitive_Type(node->type);
		} else {
			return new Struct_Type(node->struct_specifier);
		}
	}

	Type *get_type(Specifier_Node *specifier, VarDec_Node *var_dec) {
		Type *type = get_type(specifier);
		if (!var_dec->is_atomic()) {
			type = new Array_Type(type, dynamic_cast <Array_VarDec_Node *>(var_dec));
		}

		return type;
	}

	Type *get_type(ParamDec_Node *node) {
		return get_type(node->specifier, node->var_dec);
	}


	std::pair<Type *, std::vector<VarDec_Node *> *> get_info(Def_Node *node) {
		auto specifier_type = get_type(node->specifier);
		auto *decs = new std::vector<VarDec_Node *>{};

		DecList_Node *dec_list = node->dec_list;
		while (dec_list) {
			decs->push_back(dec_list->dec->var_dec);
			dec_list = dec_list->dec_list;
		}

		return std::make_pair(specifier_type, decs);
	}

}
