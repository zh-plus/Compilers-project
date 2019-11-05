//
// Created by 10578 on 11/5/2019.
//

#ifndef __TYPE_HPP__
#define __TYPE_HPP__

#include <vector>
#include <unordered_map>
#include "parser.tab.hpp"
#include "utils.hpp"
#include "ast.hpp"

namespace SPL {
	class Type {
	public:
		virtual std::string to_string() const = 0;

		virtual ~Type() = default;

		friend std::ostream &operator<<(std::ostream &os, const Type &obj);

		int line_no;
	};

	class Primitive_Type : public Type {
	public:
		explicit Primitive_Type(SPL::token_type type) : type{type} {};

		explicit Primitive_Type(SPL::Leaf_Node leaf);

		std::string to_string() const override {
			return SPL::symbol_map[type];
		}

	private:
		SPL::token_type type;
	};

	class Array_Type : public Type {
	public:
		explicit Array_Type(SPL::token_type type) : type{type} {};

		explicit Array_Type(SPL::Leaf_Node leaf);

		std::string to_string() const override {
			return SPL::symbol_map[type];
		}

	private:
		SPL::token_type type;
	};

	class Struct_Type : public Type {
	public:
		Struct_Type(std::initializer_list<Type *> members) : members{members} {};

		~Struct_Type() override {
			for (auto p: members) {
				delete p;
			}
		}

		std::string to_string() const override {
			std::string result = "Struct-Type:";
			for (auto &x: members) {
				result += " " + x->to_string();
			}

			return result;
		}

	private:
		std::vector<Type *> members;
	};
}


#endif //__TYPE_HPP__
