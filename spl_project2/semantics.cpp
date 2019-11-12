//
// Created by 10578 on 11/4/2019.
//

#include "visitor.hpp"
#include "semantics.hpp"


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
}