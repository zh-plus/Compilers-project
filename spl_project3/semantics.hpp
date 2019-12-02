//
// Created by 10578 on 11/4/2019.
//

#ifndef __SEMANTICS_HPP__
#define __SEMANTICS_HPP__

#include <utility>

#include "visitor.hpp"
#include "type.hpp"
#include "symbol.hpp"
#include "information.hpp"


namespace SPL {

	/* Forward definition */
	class Symbol_Entry;

	class Symbol_Table;

	class Local_Symbol_Table;

	class Semantic_Checker : public Visitor {
	public:
		void add_error(Semantic_Error *error);

		void push_scope(Local_Symbol_Table *local_scope);

		Symbol_Table *current_scope();

		Global_Symbol_Table *top_scope();

		std::vector<Error *> get_errors();

	protected:
		std::vector<Symbol_Table *> scope_stack;

		std::vector<Error *> errors;
	};

	class Local_Resolver : public Semantic_Checker {
	public:
		using Visitor::visit;
		using Semantic_Checker::push_scope;

		void resolve(AST *ast);

		void push_scope();

		Local_Symbol_Table *pop_scope();

		std::vector<Symbol_Table *> get_scope_stack();

		void insert(Symbol_Entry *entry);

		/* Useful Function */
		Variable_Symbol *get_var_symbol(Type *specifier_type, VarDec_Node *var_dec);

		Struct_Type *get_type(StructSpecifier_Node *node);

		Function_Symbol *get_fun_symbol(Type *return_type, FunDec_Node *fun_dec);

		bool check_struct_def(Symbol_Entry *entry);

		Type *get_type(Specifier_Node *node);

		Type *get_type(Type *type, VarDec_Node *var_dec);

		std::pair<Type *, std::vector<VarDec_Node *> *> get_info(Def_Node *node);

		/* Visitors */
		void visit(CompSt_Node *node) override;

		void visit(CompSt_Node *node, Local_Symbol_Table *local_scope);

		void visit(Def_Node *node) override;

		void visit(Leaf_Node *node) override;

		void visit(ExtDef_Node *node) override;


	};

	class Type_Checker : public Semantic_Checker {
	public:
		using Visitor::visit;

		explicit Type_Checker(Global_Symbol_Table *top_scope);

		void check(AST *ast);

		void pop_scope();

		/* Help Functions */
		Exp_Info *get_info(Exp_Node *exp_node);

		Type *merge_type(Primitive_Type *lhs, Primitive_Type *rhs);

		/* Visitors */
		void visit(ExtDef_Node *node) override;

		void visit(CompSt_Node *node) override;

		void visit(Exp_Stmt_Node *node) override;

		void visit(CompSt_Stmt_Node *node) override;

		void visit(Return_Stmt_Node *node) override;

		void visit(If_Stmt_Node *node) override;

		void visit(While_Stmt_Node *node) override;

		void visit(Dec_Node *node) override;

		void visit(Leaf_Node *node) override;

		Exp_Info *visit(Leaf_Exp_Node *node) override;

		Exp_Info *visit(Binary_Exp_Node *node) override;

		Exp_Info *visit(Unary_Exp_Node *node) override;

		Exp_Info *visit(Parentheses_Exp_Node *node) override;

		Exp_Info *visit(ID_Parentheses_Exp_Node *node) override;

		Exp_Info *visit(Bracket_Exp_Node *node) override;

		Exp_Info *visit(Dot_Exp_Node *node) override;

	private:
		Type *current_return_type = nullptr;

	};


}

#endif //__SEMANTICS_HPP__
