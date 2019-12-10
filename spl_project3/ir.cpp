//
// Created by 10578 on 12/6/2019.
//

#include "ir.hpp"
#include "type_switch.hpp"

#include <sstream>

namespace SPL {
	long long IR_Generator::temp_value = 0;

	/**
	 * ID / INT
	 * @param node
	 * @return
	 */
	Exp_Info *IR_Generator::visit(Leaf_Exp_Node *node) {
		Exp_Info *info = node->info;
		switch (node->leaf->leaf_type) {
			case token_type::INT:
				break;
		}

		return node->info;
	}

	/**
	 * Exp Binary_OP Exp
	 * @param node
	 * @return
	 */
	Exp_Info *IR_Generator::visit(Binary_Exp_Node *node) {
		auto *node_info = node->info;
		auto *lhs_info = get_info(node->left);
		auto *rhs_info = get_info(node->right);

		switch (node->op_node->leaf_type) {
			case token_type::ASSIGN:
				node_info->code.extend(rhs_info->code);
				node_info->code.add(new Assign_Quadru());
				break;
		}

		return node_info;
	}

	/**
	 * Generate temporary name for temp value.
	 * @return
	 */
	std::string IR_Generator::gen_temp() {
		std::ostringstream name;
		name << "__" << temp_value++ << "__";

		return name.str();
	}

	Exp_Info *IR_Generator::get_info(Exp_Node *exp_node) {
		Exp_Info *result = new Unknown_Exp_Info();
		type_case(exp_node,
		          [&](Parentheses_Exp_Node *node) {
			          result = visit(dynamic_cast<Parentheses_Exp_Node *>(exp_node));
		          },
		          [&](ID_Parentheses_Exp_Node *node) {
			          result = visit(dynamic_cast<ID_Parentheses_Exp_Node *>(exp_node));
		          },
		          [&](Bracket_Exp_Node *node) {
			          result = visit(dynamic_cast<Bracket_Exp_Node *>(exp_node));
		          },
		          [&](Dot_Exp_Node *node) {
			          result = visit(dynamic_cast<Dot_Exp_Node *>(exp_node));
		          },
		          [&](Binary_Exp_Node *node) {
			          result = visit(dynamic_cast<Binary_Exp_Node *>(exp_node));
		          },
		          [&](Unary_Exp_Node *node) {
			          result = visit(dynamic_cast<Unary_Exp_Node *>(exp_node));
		          },
		          [&](Leaf_Exp_Node *node) {
			          result = visit(dynamic_cast<Leaf_Exp_Node *>(exp_node));
		          }
		);
		return result;
	}
}