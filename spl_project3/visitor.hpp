//
// Created by 10578 on 11/4/2019.
//

#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include "ast.hpp"

namespace SPL {

	class Exp_Info;

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

		virtual T visit(CompSt_Node *node) = 0;

		virtual T visit(StmtList_Node *node) = 0;

		virtual T visit(DefList_Node *node) = 0;

		virtual T visit(DecList_Node *node) = 0;

		virtual T visit(VarList_Node *node) = 0;

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


		/* Definition Node */
		virtual T visit(Def_Node *node) = 0;

		virtual T visit(Dec_Node *node) = 0;

		/* Leaf Node */
		virtual void visit(Leaf_Node *node) = 0;

		/* Empty Node */
		virtual void visit(Empty_ExtDefList_Node *node) = 0;

		virtual void visit(Empty_StmtList_Node *node) = 0;

		virtual void visit(Empty_DefList_Node *node) = 0;

		virtual void visit(Empty_DecList_Node *node) = 0;
	};

	class Visitor : public AST_Visitor<void, void, Exp_Info *> {
	public:
		/* Internal Nodes */
		void visit(Program_Node *node) override;

		void visit(ExtDefList_Node *node) override;

		void visit(ExtDef_Node *node) override;

		void visit(ExtDecList_Node *node) override;

		void visit(Specifier_Node *node) override;

		void visit(StructSpecifier_Node *node) override;

		void visit(CompSt_Node *node) override;

		void visit(StmtList_Node *node) override;

		void visit(DefList_Node *node) override;

		void visit(DecList_Node *node) override;

		void visit(VarList_Node *node) override;

		void visit(Args_Node *node) override;

		/* Declaration Node */
		void visit(ID_VarDec_Node *node) override;

		void visit(Array_VarDec_Node *node) override;

		void visit(FunDec_Node *node) override;

		void visit(ParamDec_Node *node) override;

		/* Statement Node */
		void visit(Exp_Stmt_Node *node) override;

		void visit(CompSt_Stmt_Node *node) override;

		void visit(Return_Stmt_Node *node) override;

		void visit(If_Stmt_Node *node) override;

		void visit(While_Stmt_Node *node) override;

		/* Expression Node */
		Exp_Info *visit(Parentheses_Exp_Node *node) override;

		Exp_Info *visit(ID_Parentheses_Exp_Node *node) override;

		Exp_Info *visit(Bracket_Exp_Node *node) override;

		Exp_Info *visit(Dot_Exp_Node *node) override;

		Exp_Info *visit(Binary_Exp_Node *node) override;

		Exp_Info *visit(Unary_Exp_Node *node) override;

		Exp_Info *visit(Leaf_Exp_Node *node) override;

		/* Definition Node */
		void visit(Def_Node *node) override;

		void visit(Dec_Node *node) override;


		/* Leaf Node */
		void visit(Leaf_Node *node) override;


		/* Empty Node */
		void visit(Empty_ExtDefList_Node *node) override {};

		void visit(Empty_StmtList_Node *node) override {};

		void visit(Empty_DefList_Node *node) override {};

		void visit(Empty_DecList_Node *node) override {};


		/* Help function */
		void visit_children(AST_Node *node);

		void check(AST_Node *node);
	};


}

#endif //__VISITOR_HPP__
