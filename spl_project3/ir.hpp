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

	/* Forward definition */
	class Symbol_Entry;

	class Symbol_Table;

	class Local_Symbol_Table;

	class IR_Generator : public Visitor {
	public:
		using Visitor::visit;

		explicit IR_Generator(Global_Symbol_Table *top_scope);

		void generate(AST *ast);

		/* visitor */
		void visit(FunDec_Node *node, Local_Symbol_Table *local_scope);


		Exp_Info *visit(Leaf_Exp_Node *node) override;

		Exp_Info *visit(Binary_Exp_Node *node) override;

		Exp_Info *visit(Unary_Exp_Node *node) override;

		Exp_Info *visit(Parentheses_Exp_Node *node) override;

		Exp_Info *visit(ID_Parentheses_Exp_Node *node) override;

		Exp_Info *visit(Bracket_Exp_Node *node) override;

		Exp_Info *visit(Dot_Exp_Node *node) override;

		void visit(Exp_Stmt_Node *node) override;

		void visit(Return_Stmt_Node *node) override;

		void visit(If_Stmt_Node *node) override;

		void visit(While_Stmt_Node *node) override;

		void visit(ExtDef_Node *node) override;

		void visit(CompSt_Node *node) override;

		void visit(Dec_Node *node) override;

		/* Help function */
		std::string gen_temp();

		Exp_Info *get_info(Exp_Node *exp_node);

		void push_scope(Local_Symbol_Table *local_scope);

		void pop_scope();

		Symbol_Table *current_scope();

		TAC *get_tac();

	protected:
		std::vector<Symbol_Table *> scope_stack;

		static long long temp_name_value;

		TAC tac;
	};
}

#endif //__IR_HPP__
