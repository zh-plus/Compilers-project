//
// Created by 10578 on 12/6/2019.
//

#include "ir.hpp"
#include "type_switch.hpp"
#include "symbol.hpp"

#include <sstream>

namespace SPL {
	using namespace std;

	long long IR_Generator::temp_name_value = 0;

	IR_Generator::IR_Generator(SPL::Global_Symbol_Table *top_scope) {
		scope_stack.push_back(top_scope);
	}

	void IR_Generator::generate(SPL::AST *ast) {
		visit(ast->program);
	}

	void IR_Generator::push_scope(Local_Symbol_Table *local_scope) {
		scope_stack.push_back(local_scope);
	}

	void IR_Generator::pop_scope() {
		scope_stack.pop_back();
	}

	void IR_Generator::visit(ExtDef_Node *node) {
		if (node->fun_dec) {
			visit(node->fun_dec, node->comp_st->local_scope);
			visit(node->comp_st);
		} else {
			Visitor::visit(node);
		}
	}

	void IR_Generator::visit(FunDec_Node *node, Local_Symbol_Table *local_scope) {
		string func_name = node->id->get_lexeme();
		tac.add(new Func_Quadru(func_name));

		Function_Symbol *symbol = dynamic_cast<Function_Symbol *>(
				current_scope()->lookup(func_name)
		);

		string temp_name;
		Symbol_Entry *entry;
		for (auto &&x: symbol->get_parameters()) {
			temp_name = gen_temp();
			entry = local_scope->lookup(x.first);
			entry->ir_name = temp_name;

			if (!x.second->is_primitive()) {
				entry->pass_by_address = true;
			}

			tac.add(new Param_Quadru(temp_name));
		}

		Visitor::visit(node);
	}


	/**
	 * ID / INT
	 * @param node
	 * @return
	 */
	Exp_Info *IR_Generator::visit(Leaf_Exp_Node *node) {
		Exp_Info *node_info = node->info;
		string lexeme = node->leaf->get_lexeme();
		string temp_name;

		switch (node->leaf->leaf_type) {
			case token_type::INT:
				node_info->temp_name = "#" + lexeme;
				break;
			case token_type::ID: {
				Symbol_Entry *entry = current_scope()->lookup(lexeme);
				temp_name = entry->ir_name;

				if (entry->pass_by_address) {
					node->info->is_address = true;
				}

				/* Not initialized */
				if (temp_name == "__undefined__") {
					temp_name = gen_temp();
					entry->ir_name = temp_name;

					/* Struct or Array id */
					if (auto type = entry->get_type(); !type->is_primitive()) {
						node_info->code.add(new Dec_Quadru(temp_name, type->ir_size()));
					}
				}

				node_info->temp_name = temp_name;
				break;
			}
			default:
				std::cout << "No other leaf type!" << std::endl;
		}

		return node_info;
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

		node_info->code.extend(lhs_info->code);
		node_info->code.extend(rhs_info->code);

		string lhs_name = lhs_info->temp_name;
		string rhs_name = rhs_info->temp_name;

		auto type = node->op_node->leaf_type;
		switch (type) {
			case token_type::ASSIGN: {
				if (!lhs_info->is_address) {
					if (!rhs_info->is_address) {
						// value = value
						node_info->code.add(new Assign_Value_Quadru(lhs_name, rhs_name));
					} else {
						// value = *address
						node_info->code.add(new Assign_Deref_Quadru(lhs_name, rhs_name));
					}
				} else {
					if (!rhs_info->is_address) {
						// address = value
						node_info->code.add(new Deref_Assign_Quadru(lhs_name, rhs_name));
					} else {
						// address = address
						string temp_name = gen_temp();
						node_info->code.add(new Assign_Deref_Quadru(temp_name, rhs_name));
						node_info->code.add(new Deref_Assign_Quadru(lhs_name, temp_name));
					}
				}
			}
				break;
			case token_type::PLUS:
			case token_type::MINUS:
			case token_type::MUL:
			case token_type::DIV: {
				string temp_name = gen_temp();
				node_info->temp_name = temp_name;

				if (!lhs_info->is_address) {
					if (!rhs_info->is_address) {
						// value + value
						node_info->code.add(new Arith_Quadru(temp_name, lhs_name, rhs_name, type));
					} else {
						// value + address
						string temp = gen_temp();
						node_info->code.add(new Assign_Deref_Quadru(temp, rhs_name));

						node_info->code.add(new Arith_Quadru(temp_name, lhs_name, temp, type));
					}
				} else {
					if (!rhs_info->is_address) {
						// address + value
						string temp = gen_temp();
						node_info->code.add(new Assign_Deref_Quadru(temp, lhs_name));

						node_info->code.add(new Arith_Quadru(temp_name, temp, rhs_name, type));
					} else {
						// address + address
						string temp1 = gen_temp();
						string temp2 = gen_temp();
						node_info->code.add(new Assign_Deref_Quadru(temp1, lhs_name));
						node_info->code.add(new Assign_Deref_Quadru(temp2, rhs_name));

						node_info->code.add(new Arith_Quadru(temp_name, temp1, temp2, type));
					}
				}

				break;
			}
		}

		return node_info;
	}

	Exp_Info *IR_Generator::visit(Unary_Exp_Node *node) {
		Exp_Info *node_info = node->info;

		if (node->op_node->leaf_type != token_type::MINUS) {
			std::cout << "Should be MINUS unary!" << std::endl;
			return node_info;
		}

		auto *exp_info = get_info(node->exp_node);

		string temp_name = gen_temp();
		node_info->temp_name = temp_name;
		node_info->code.add(new Arith_Quadru(temp_name, "#0", exp_info->temp_name, token_type::MINUS));

		return node_info;
	}


	Exp_Info *IR_Generator::visit(Parentheses_Exp_Node *node) {
		return get_info(node->exp);
	}

	Exp_Info *IR_Generator::visit(ID_Parentheses_Exp_Node *node) {
		Exp_Info *node_info = node->info;

		vector<Exp_Info *> arg_list;

		Args_Node *temp_args = node->args;
		Exp_Info *temp_info;
		while (temp_args) {
			temp_info = get_info(temp_args->exp);
			node_info->code.extend(temp_info->code);
			arg_list.push_back(temp_info);
			temp_args = temp_args->args;
		}

		string func_name = node->id->get_lexeme();
		string temp_name = gen_temp();
		node_info->temp_name = temp_name;

		if (func_name == "read") {
			node_info->code.add(new Read_Quadru(temp_name));
		} else if (func_name == "write") {
			string arg_name = arg_list.front()->temp_name;
			if (arg_list.front()->is_address) {
				arg_name = gen_temp();
				node_info->code.add(new Assign_Deref_Quadru(arg_name, arg_list.front()->temp_name));
			}

			node_info->code.add(new Write_Quadru(arg_name));
		} else {
			/* Other self-defined functions */

			/* Arg in reverse order */
			for (auto rit = arg_list.rbegin(); rit != arg_list.rend(); ++rit) {
				string arg_name = (*rit)->temp_name;
				if (!(*rit)->exp_type->is_primitive()) {
					arg_name.insert(0, "&");
				}

				node_info->code.add(new Arg_Quadru(arg_name));
			}

			node_info->code.add(new Call_Quadru(temp_name, func_name));
		}

		return node_info;
	}

	Exp_Info *IR_Generator::visit(Bracket_Exp_Node *node) {
		Exp_Info *node_info = node->info;

		Exp_Info *array_info = get_info(node->exp1);
		Exp_Info *index_info = get_info(node->exp2);
		node_info->code.extend(array_info->code);
		node_info->code.extend(index_info->code);

		/* lhs exp type should be array  */
		auto *array_type = dynamic_cast<Array_Type *>(array_info->exp_type);
		if (array_type == nullptr) {
			std::cout << "Should be array type!" << endl;
			return node_info;
		}

		int layer_size = array_type->get_layer_size();

		string offset_temp_name = gen_temp();
		string layer_size_name = "#" + std::to_string(layer_size);
		node_info->code.add(new Arith_Quadru(offset_temp_name, index_info->temp_name, layer_size_name, op_type::MUL));

		string temp_name = gen_temp();
		node_info->temp_name = temp_name;
		if (!array_info->is_address) {
			node_info->code.add(
					new Arith_Quadru(temp_name, "&" + array_info->temp_name, offset_temp_name, op_type::PLUS));

		} else {
			node_info->code.add(
					new Arith_Quadru(temp_name, array_info->temp_name, offset_temp_name, op_type::PLUS));
		}

		node_info->is_address = true;

		return node_info;
	}

	Exp_Info *IR_Generator::visit(Dot_Exp_Node *node) {
		Exp_Info *node_info = node->info;

		Exp_Info *exp_info = get_info(node->exp);
		node_info->code.extend(exp_info->code); // Add Dec for struct and array

		/* exp type should be struct  */
		auto *struct_type = dynamic_cast<Struct_Type *>(exp_info->exp_type);
		if (struct_type == nullptr) {
			std::cout << "Should be struct type!" << endl;
			return node_info;
		}

		string temp_name = gen_temp();
		node_info->temp_name = temp_name;

		string member_id = node->id->get_lexeme();
		int offset = struct_type->get_offset(member_id);

		/* Get address */
		if (!exp_info->is_address) {
			node_info->code.add(
					new Arith_Quadru(temp_name, "&" + exp_info->temp_name, "#" + std::to_string(offset),
					                 op_type::PLUS)
			);
		} else {
			node_info->code.add(
					new Arith_Quadru(temp_name, exp_info->temp_name, "#" + std::to_string(offset), op_type::PLUS)
			);
		}

		node_info->is_address = true;

		return node_info;
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

	void IR_Generator::visit(SPL::Exp_Stmt_Node *node) {
		auto *exp_info = get_info(node->exp);
		tac.extend(exp_info->code);
	}


	void IR_Generator::visit(Return_Stmt_Node *node) {
		Exp_Info *node_info = get_info(node->exp);
		tac.extend(node_info->code);

		tac.add(new Return_Quadru(node_info->temp_name));
	}

	void IR_Generator::visit(If_Stmt_Node *node) {
		auto *relop_exp = dynamic_cast<Binary_Exp_Node *>(node->exp);
		if (relop_exp == nullptr) {
			cout << "If stmt should have relationship exp!" << endl;
			return;
		}

		Exp_Info *left_info = get_info(relop_exp->left);
		Exp_Info *right_info = get_info(relop_exp->right);

		tac.extend(left_info->code);
		tac.extend(right_info->code);

		string left_name = left_info->temp_name;
		if (left_info->is_address) {
			left_name = gen_temp();
			tac.add(new Assign_Deref_Quadru(left_name, left_info->temp_name));
		}

		string right_name = right_info->temp_name;
		if (right_info->is_address) {
			right_name = gen_temp();
			tac.add(new Assign_Deref_Quadru(right_name, right_info->temp_name));
		}

		token_type op = relop_exp->op_node->leaf_type;

		/* If (Exp) Stmt */

		auto *true_label = new Label();
		auto *false_label = new Label();

		tac.add(new CGoto_Quadru(left_name, right_name, op, true_label));
		tac.add(new Goto_Quadru(false_label));

		tac.add(new Label_Quadru(true_label));
		check(node->stmt_if);

		Label *next_label;
		if (node->stmt_else) {
			next_label = new Label();
			tac.add(new Goto_Quadru(next_label));
		}

		tac.add(new Label_Quadru(false_label));

		/* ELSE Stmt */
		if (node->stmt_else) {
			check(node->stmt_else);
			tac.add(new Label_Quadru(next_label));
		}
	}

	void IR_Generator::visit(While_Stmt_Node *node) {
		auto *relop_exp = dynamic_cast<Binary_Exp_Node *>(node->exp);
		if (relop_exp == nullptr) {
			cout << "If stmt should have relationship exp!" << endl;
			return;
		}

		Exp_Info *left_info = get_info(relop_exp->left);
		Exp_Info *right_info = get_info(relop_exp->right);

		tac.extend(left_info->code);
		tac.extend(right_info->code);

		string left_name = left_info->temp_name;
		string right_name = right_info->temp_name;
		token_type op = relop_exp->op_node->leaf_type;

		auto *begin_label = new Label();
		auto *true_label = new Label();
		auto *false_label = new Label();

		tac.add(new Label_Quadru(begin_label));

		tac.add(new CGoto_Quadru(left_name, right_name, op, true_label));
		tac.add(new Goto_Quadru(false_label));

		tac.add(new Label_Quadru(true_label));
		check(node->stmt);

		tac.add(new Goto_Quadru(begin_label));
		tac.add(new Label_Quadru(false_label));
	}

	void IR_Generator::visit(CompSt_Node *node) {
		push_scope(node->local_scope);
		Visitor::visit(node);
		pop_scope();
	}

	/**
	 * Generate temporary name for temp value.
	 * @return
	 */
	string IR_Generator::gen_temp() {
		ostringstream name;
		name << "t" << temp_name_value++;

		return name.str();
	}

	TAC *IR_Generator::get_tac() {
		return &tac;
	}

	Symbol_Table *IR_Generator::current_scope() {
		return scope_stack.back();
	}

	void IR_Generator::visit(Dec_Node *node) {
		if (node->assign != nullptr) {
			Exp_Info *rhs_info = get_info(node->exp);
			tac.extend(rhs_info->code);

			string var_id = node->var_dec->get_id();
			Symbol_Entry *entry = current_scope()->lookup(var_id);
			entry->ir_name = gen_temp();

			string lhs_name = entry->ir_name;
			string rhs_name = rhs_info->temp_name;

			if (!rhs_info->is_address) {
				// value = value
				tac.add(new Assign_Value_Quadru(lhs_name, rhs_name));
			} else {
				// value = *address
				tac.add(new Assign_Deref_Quadru(lhs_name, rhs_name));
			}
		}

		Visitor::visit(node);
	}


}