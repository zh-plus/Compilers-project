//
// Created by 10578 on 11/4/2019.
//

#include "visitor.hpp"
#include "semantics.hpp"

namespace SPL {

	/* Visitor */
	void Visitor::visit(Program_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(ExtDefList_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(ExtDef_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(Leaf_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(Specifier_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(ExtDecList_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(StructSpecifier_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(CompSt_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(StmtList_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(DefList_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(DecList_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(VarList_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(Args_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(ID_VarDec_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(Array_VarDec_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(FunDec_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(ParamDec_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(Exp_Stmt_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(CompSt_Stmt_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(Return_Stmt_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(If_Stmt_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(While_Stmt_Node *node) {
		visit_children(node);
	}

    Exp_Info *Visitor::visit(Parentheses_Exp_Node *node) {
		visit_children(node);
	}

    Exp_Info *Visitor::visit(ID_Parentheses_Exp_Node *node) {
		visit_children(node);
	}

    Exp_Info *Visitor::visit(Bracket_Exp_Node *node) {
		visit_children(node);
	}

    Exp_Info *Visitor::visit(Dot_Exp_Node *node) {
		visit_children(node);
	}

    Exp_Info *Visitor::visit(Binary_Exp_Node *node) {
		visit_children(node);
	}

    Exp_Info *Visitor::visit(Unary_Exp_Node *node) {
		visit_children(node);
	}

    Exp_Info *Visitor::visit(Leaf_Exp_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(Def_Node *node) {
		visit_children(node);
	}

	void Visitor::visit(Dec_Node *node) {
		visit_children(node);
	}

	void Visitor::check(AST_Node *node) {
		if (!node->is_empty()) {
			node->accept(this);
		}
	}

	void Visitor::visit_children(AST_Node *node) {
		for (auto &child: node->children()) {
			check(child);
		}
	}

	/* Local Resolver */
}