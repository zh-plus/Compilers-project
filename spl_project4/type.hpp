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

namespace SPL {
	/* Forward definition */
	class Array_VarDec_Node;

	class Leaf_Node;

	using token_type = SPL_Parser::token_type;

	enum op_type {
		PLUS, MINUS, MUL, DIV, LT, LE, GT, GE, NE, EQ
	};

	static std::unordered_map<op_type, std::string> op_map{
			{op_type::PLUS,  "+"},
			{op_type::MINUS, "-"},
			{op_type::MUL,   "*"},
			{op_type::DIV,   "/"},
			{op_type::LT,    "<"},
			{op_type::LE,    "<="},
			{op_type::GT,    ">"},
			{op_type::GE,    ">="},
			{op_type::NE,    "!="},
			{op_type::EQ,    "=="},
	};

	class Type {
	public:
		[[nodiscard]] virtual std::string to_string() const = 0;

		virtual ~Type() = default;

		friend std::ostream &operator<<(std::ostream &os, const Type &obj);

		virtual bool compassionate(Type *other) = 0;

		virtual int ir_size() = 0;

		virtual bool is_primitive();

		int line_no = -1;
	};

	enum primitive_type {
		INT, FLOAT, CHAR
	};

	class Primitive_Type : public Type {
	public:
		explicit Primitive_Type(token_type t_type);

		explicit Primitive_Type(primitive_type type) : type{type} {};

		explicit Primitive_Type(Leaf_Node *leaf);

		bool compassionate(Type *other) override;

		[[nodiscard]] std::string to_string() const override {
			return std::vector{"int", "float", "char"}[type];
		}

		int ir_size() override;

		bool is_primitive() override;

		primitive_type type;
	};

	class Array_Type : public Type {
	public:
		explicit Array_Type(Type *base_type, Array_VarDec_Node *array_node);

		Array_Type(Type *base_type, std::vector<int> shape);

		bool compassionate(Type *other) override;

		bool same_shape_of(Array_Type *other_shape);

		Type *reduce_dim();

		[[nodiscard]] std::string to_string() const override {
			std::string s = m_base_type->to_string();
			for (const auto &x: shape) {
				s += "[" + std::to_string(x) + "]";
			}
			return s;
		}

		int ir_size() override;

		int get_layer_size();

		Type *m_base_type;

		std::vector<int> shape;
	};

	class Struct_Type : public Type {
	public:

		Struct_Type(std::string id, int line_no, std::vector<std::pair<std::string, Type *>> member_vector);

		~Struct_Type() override {
			for (const auto &p: member_map) {
				delete p.second;
				member_map.erase(p.first);
			}
		}

		[[nodiscard]] std::string to_string() const override {
			std::string result = "Struct-Type:";
			for (auto &x: member_map) {
				result += " " + x.second->to_string() + "-" + x.first + ", ";
			}

			return result;
		}

		/* Semantic check related */
		bool compassionate(Type *other) override;

		bool contains(std::string id);


		/* ir related */
		int ir_size() override;

		int get_offset(const std::string &member_id);

		std::string struct_id;

		std::map<std::string, Type *> member_map;

		std::vector<std::string> member_ids;
	};
}


#endif //__TYPE_HPP__
