//
// Created by 10578 on 11/5/2019.
//

#ifndef __TYPE_HPP__
#define __TYPE_HPP__

#include <vector>
#include <unordered_map>
#include <map>
#include "parser.tab.hpp"
#include "utils.hpp"
#include "ast.hpp"

namespace SPL {
	using token_type = SPL_Parser::token_type;

	class Type {
	public:
		[[nodiscard]] virtual std::string to_string() const = 0;

		virtual ~Type() = default;

		friend std::ostream &operator<<(std::ostream &os, const Type &obj);

		int line_no;
	};

	class Primitive_Type : public Type {
	public:
		explicit Primitive_Type(token_type type) : type{type} {};

		explicit Primitive_Type(Leaf_Node *leaf);

		[[nodiscard]] std::string to_string() const override {
			return symbol_map[type];
		}

		token_type type;
	};

	class Array_Type : public Type {
	public:
		explicit Array_Type(token_type type) : type{type} {};

		explicit Array_Type(Leaf_Node *leaf);

		explicit Array_Type(Primitive_Type type);

		[[nodiscard]] std::string to_string() const override {
			return symbol_map[type];
		}

		token_type type;
	};

	class Struct_Type : public Type {
	public:
		explicit Struct_Type(StructSpecifier_Node *node);

		~Struct_Type() override {
			for (const auto& p: members) {
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

	private:
		std::map<std::string, Type *> members;
	};

	/* Useful functions */
	static Type *get_type(Specifier_Node *node);

	static std::pair<Type *, std::vector<VarDec_Node *> *> get_info(Def_Node *node);
}


#endif //__TYPE_HPP__
