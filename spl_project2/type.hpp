//
// Created by 10578 on 11/5/2019.
//

#ifndef __TYPE_HPP__
#define __TYPE_HPP__

#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include "parser.tab.hpp"
#include "utils.hpp"

namespace SPL {
	/* Forward definition */
	class Array_VarDec_Node;

	using token_type = SPL_Parser::token_type;

	class Type {
	public:
		[[nodiscard]] virtual std::string to_string() const = 0;

		virtual ~Type() = default;

		friend std::ostream &operator<<(std::ostream &os, const Type &obj);

		int line_no = -1;
	};

	enum primitive_type {
		INT, FLOAT, CHAR
	};

	class Primitive_Type : public Type {
	public:
		explicit Primitive_Type(primitive_type type) : type{type} {};

		explicit Primitive_Type(Leaf_Node *leaf);

		[[nodiscard]] std::string to_string() const override {
			return std::vector{"int", "float", "char"}[type];
		}

		primitive_type type;
	};

	class Array_Type : public Type {
	public:
		explicit Array_Type(Type *base_type, Array_VarDec_Node *array_node);

		[[nodiscard]] std::string to_string() const override {
			std::string s = m_base_type->to_string();
			for (const auto &x: shape) {
				s += "[" + std::to_string(x) + "]";
			}
			return s;
		}

		Type *m_base_type;

		std::vector<int> shape;
	};

	class Struct_Type : public Type {
	public:
		explicit Struct_Type(StructSpecifier_Node *node);

		~Struct_Type() override {
			for (const auto &p: members) {
				delete p.second;
				members.erase(p.first);
			}
		}

		[[nodiscard]] std::string to_string() const override {
			std::string result = "Struct-Type:";
			for (auto &x: members) {
				result += " " + x.second->to_string() + "-" + x.first + ", ";
			}

			return result;
		}

		std::string struct_id;

		std::map<std::string, Type *> members;
	};

	/* Useful functions */
	Type *get_type(Specifier_Node *node);

	std::pair<Type *, std::vector<VarDec_Node *> *> get_info(Def_Node *node);
}


#endif //__TYPE_HPP__
