//
// Created by 10578 on 11/4/2019.
//

#ifndef __SEMANTICS_HPP__
#define __SEMANTICS_HPP__

#include "visitor.hpp"
#include "type.hpp"
#include "symbol.hpp"

namespace SPL {

	class Local_Resolver : public Visitor {
	public:
		using Visitor::visit;

		Local_Resolver() : scope_stack{new std::vector<Symbol_Table *>{}} {}

		void resolve(AST *ast);

		void push_scope();

		Local_Symbol_Table * pop_scope();

		Symbol_Table *current_scope();

		/* Visitors */
		void visit(CompSt_Node *node) override;

		void visit(Leaf_Node *node) override;




	private:
		std::vector<Symbol_Table *> *scope_stack;

	};


}

#endif //__SEMANTICS_HPP__
