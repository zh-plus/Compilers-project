//
// Created by 10578 on 11/4/2019.
//

#include "semantics.hpp"
#include "type.hpp"
#include "visitor.hpp"
#include "symbol.hpp"


namespace SPL {

	using namespace std;

	/* Local Resolver */
	void SPL::Local_Resolver::resolve(AST *ast) {
		auto *global_scope = new Global_Symbol_Table();
		scope_stack->push_back(global_scope);

		visit(ast->program);

		ast->global_scope = global_scope;
	}

	void Local_Resolver::push_scope() {
		auto *local_scope = new Local_Symbol_Table(current_scope());
		scope_stack->push_back(local_scope);
	}

	void Local_Resolver::push_scope(Local_Symbol_Table *local_scope) {
		scope_stack->push_back(local_scope);
	}

	Symbol_Table *Local_Resolver::current_scope() {
		return scope_stack->back();
	}

	Local_Symbol_Table *Local_Resolver::pop_scope() {
		auto scope = current_scope();
		scope_stack->pop_back();
		return (Local_Symbol_Table *) scope;
	}

	void Local_Resolver::visit(CompSt_Node *node) {
		push_scope();
		Visitor::visit(node);
		node->local_scope = pop_scope();
	}

	void Local_Resolver::visit(CompSt_Node *node, Local_Symbol_Table *local_scope) {
		push_scope(local_scope);
		Visitor::visit(node);
		node->local_scope = pop_scope();
	}


	void Local_Resolver::visit(Leaf_Node *node) {
//		cout << node->to_string() << endl;
		Visitor::visit(node);
	}

	void Local_Resolver::visit(ExtDef_Node *node) {
		cout << "Visiting ExtDef_Node!" << endl;
		if (node->ext_dec_list) {
			cout << "    ext_dec_list" << endl;
			auto t_ext_dec_list = node->ext_dec_list;
			while (t_ext_dec_list) {
				auto var_symbol = new Variable_Symbol(node->specifier, node->ext_dec_list->var_dec);
				current_scope()->insert(var_symbol);

				t_ext_dec_list = t_ext_dec_list->ext_dec_list;
			}
		} else if (node->fun_dec) {
			cout << "    fun_dec" << endl;
			auto func_symbol = new Function_Symbol(node->specifier, node->fun_dec);
			current_scope()->insert(func_symbol);


			// Put parameter into scope and put them into stack
			push_scope();
			auto var_list = node->fun_dec->var_list;
			while (var_list) {
				auto var_symbol = new Variable_Symbol(var_list->param_dec);
				current_scope()->insert(var_symbol);

				var_list = var_list->var_list;
			}

			visit(node->comp_st, pop_scope());
		} else if (auto p_struct_specifier = node->specifier->struct_specifier) {
			cout << "    struct_specifier" << endl;
			current_scope()->insert(new Struct_Def_Symbol(new Struct_Type(p_struct_specifier)));
		}
	}

	std::vector<Symbol_Table *> *Local_Resolver::get_scope_stack() {
		return scope_stack;
	}


}