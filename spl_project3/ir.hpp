//
// Created by 10578 on 12/6/2019.
//

#ifndef __IR_HPP__
#define __IR_HPP__

#include "tac.hpp"
#include "information.hpp"
#include "visitor.hpp"
#include "type.hpp"

namespace SPL {
	class IR_Generator : public Visitor {
	public:
		using Visitor::visit;

		/* visitor */
		Exp_Info *visit(Leaf_Exp_Node *node) override;

		Exp_Info *visit(Binary_Exp_Node *node) override;

		Exp_Info *visit(Unary_Exp_Node *node) override;

		Exp_Info *visit(Parentheses_Exp_Node *node) override;

		Exp_Info *visit(ID_Parentheses_Exp_Node *node) override;

		Exp_Info *visit(Bracket_Exp_Node *node) override;

		Exp_Info *visit(Dot_Exp_Node *node) override;

		/* Help function */
		std::string gen_temp();

		Exp_Info *get_info(Exp_Node *exp_node);

	private:
		static long long temp_value;
	};
}

#endif //__IR_HPP__
