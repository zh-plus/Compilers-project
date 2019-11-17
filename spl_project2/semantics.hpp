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

    class Local_Resolver : public Visitor {
    public:
        using Visitor::visit;

        void resolve(AST *ast);

        void push_scope(Local_Symbol_Table *local_scope);

        void push_scope();

        Local_Symbol_Table *pop_scope();

        Symbol_Table *current_scope();

        std::vector<Symbol_Table *> get_scope_stack();

        void insert(Symbol_Entry *entry);

        void add_error(Semantic_Error *error);

        std::vector<Error *> get_errors();

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

    private:
        std::vector<Symbol_Table *> scope_stack;

        std::vector<Error *> errors;
    };

    class Dereference_Checker : public Visitor {
    public:
        using Visitor::visit;

        explicit Dereference_Checker(std::vector<Symbol_Table *> scope_stack) : scope_stack{std::move(scope_stack)} {}

        void check(AST *ast);

        void push_scope(Local_Symbol_Table *local_scope);

        void pop_scope();

        Symbol_Table *current_scope();

        /* Visitors */
        void visit(CompSt_Node *node) override;

        Exp_Info visit(Binary_Exp_Node *node) override;


    private:
        std::vector<Symbol_Table *> scope_stack;

        std::vector<Error *> errors;
    };


}

#endif //__SEMANTICS_HPP__
