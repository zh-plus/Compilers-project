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
//		cout << "Push scope !" << endl;
		Visitor::visit(node);
		node->local_scope = pop_scope();
//		cout << "Pop scope !" << endl;
	}

	void Local_Resolver::visit(Leaf_Node *node) {
		cout << node->to_string() << endl;
		Visitor::visit(node);
	}

	void Local_Resolver::visit(ExtDef_Node *node) {
		cout << "Visiting ExtDef_Node!" << endl;
		if (node->ext_dec_list) {
			cout << "ext_dec_list" << endl;
			Type *specifier_type = get_type(node->specifier);
			auto p_ext_dec_list = node->ext_dec_list;
			while (p_ext_dec_list) {
				Type *type = specifier_type;
				VarDec_Node *var_dec = p_ext_dec_list->var_dec;
				string id = var_dec->get_id();
				if (!var_dec->is_atomic()) {
					// Array type
					type = new Array_Type(specifier_type, dynamic_cast <Array_VarDec_Node *>(var_dec));
				}

				current_scope()->insert(new Variable_Symbol(id, type));

				p_ext_dec_list = p_ext_dec_list->ext_dec_list;
			}
		} else if (node->fun_dec) {
			cout << "fun_dec" << endl;
			// Put parameter into scope and put them into stack

		} else if (auto p_struct_specifier = node->specifier->struct_specifier) {
			cout << "struct_specifier" << endl;
			current_scope()->insert(new Struct_Def_Symbol(new Struct_Type(p_struct_specifier)));
			cout << "struct_specifier end" << endl;
		}
	}

	std::vector<Symbol_Table *> *Local_Resolver::get_scope_stack() {
		return scope_stack;
	}

}