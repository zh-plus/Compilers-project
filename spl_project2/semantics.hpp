//
// Created by 10578 on 11/4/2019.
//

#ifndef __SEMANTICS_HPP__
#define __SEMANTICS_HPP__

#include "ast.hpp"

namespace SPL {

	template<typename T, typename S, typename E>
	class AST_Visitor {
	public:

		/* Internal Nodes */
		virtual T visit(Program_Node *node) = 0;

		virtual T visit(ExtDefList_Node *node) = 0;

		virtual T visit(ExtDef_Node *node) = 0;

		virtual T visit(ExtDecList_Node *node) = 0;

		virtual T visit(Specifier_Node *node) = 0;

		virtual T visit(StructSpecifier_Node *node) = 0;

		virtual T visit(VarList_Node *node) = 0;

		virtual T visit(CompSt_Node *node) = 0;

		virtual T visit(StmtList_Node *node) = 0;

		virtual T visit(DefList_Node *node) = 0;

		virtual T visit(DecList_Node *node) = 0;

		virtual T visit(Args_Node *node) = 0;


		/* Declaration Node */
		virtual T visit(ID_VarDec_Node *node) = 0;

		virtual T visit(Array_VarDec_Node *node) = 0;

		virtual T visit(FunDec_Node *node) = 0;

		virtual T visit(ParamDec_Node *node) = 0;


		/* Statement Node */
		virtual S visit(Exp_Stmt_Node *node) = 0;

		virtual S visit(CompSt_Stmt_Node *node) = 0;

		virtual S visit(Return_Stmt_Node *node) = 0;

		virtual S visit(If_Stmt_Node *node) = 0;

		virtual S visit(While_Stmt_Node *node) = 0;

		/* Expression Node */
		virtual E visit(Parentheses_Exp_Node *node) = 0;

		virtual E visit(ID_Parentheses_Exp_Node *node) = 0;

		virtual E visit(Bracket_Exp_Node *node) = 0;

		virtual E visit(Dot_Exp_Node *node) = 0;

		virtual E visit(Binary_Exp_Node *node) = 0;

		virtual E visit(Unary_Exp_Node *node) = 0;

		virtual E visit(Leaf_Exp_Node *node) = 0;

		virtual E visit(Def_Node *node) = 0;


		/* Leaf Node */
		virtual void visit(Leaf_Node *node) = 0;


		/* Empty Node */
		virtual void visit(Empty_ExtDefList_Node *node) {};

		virtual void visit(Empty_StmtList_Node *node) {};

		virtual void visit(Empty_DefList_Node *node) {};

		virtual void visit(Empty_DecList_Node *node) {};
	};
}

#endif //__SEMANTICS_HPP__
