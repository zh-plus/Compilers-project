//
// Created by 10578 on 10/29/2019.
//

#ifndef __SYMBOL_HPP__
#define __SYMBOL_HPP__

#include <vector>
#include <unordered_map>
#include "parser.tab.hpp"
#include "utils.hpp"

namespace SPL {
    using namespace std;
    using token_type = SPL_Parser::token_type;

    class Type {
    public:
        virtual string to_string() const = 0;

        virtual ~Type() = default;

        friend ostream &operator<<(ostream &os, const Type &obj);
    };

    class Primitive_Type : public Type {
    public:
        explicit Primitive_Type(token_type type) : type{type} {};

        string to_string() const override {
            return symbol_map[type];
        }

    private:
        token_type type;
    };

    class Array_Type : public Type {
    public:
        explicit Array_Type(token_type type) : type{type} {};

        string to_string() const override {
            return symbol_map[type];
        }

    private:
        token_type type;
    };

    class Struct_Type : public Type {
    public:
        Struct_Type(initializer_list<Type *> members) : members{members} {};

        ~Struct_Type() override {
            for (auto p: members) {
                delete p;
            }
        }

        string to_string() const override {
            string result = "Struct-Type:";
            for (auto &x: members) {
                result += " " + x->to_string();
            }

            return result;
        }

    private:
        vector<Type *> members;
    };

    class Symbol_Entry {
    public:
        virtual ~Symbol_Entry() = default;

        void add_reference(int line_no);

        int get_decl_line();

        friend ostream &operator<<(ostream &os, const Symbol_Entry &obj);

        virtual string to_string() const = 0;

        vector<int> references;
    };

    class Variable_Symbol : public Symbol_Entry {
    public:
        Variable_Symbol(int line_no, Type *variable_type) : variable_type{variable_type} {
            references = vector<int>{line_no};
        };

        ~Variable_Symbol() override {
            delete variable_type;
        }

        string to_string() const override;

    private:
        Type *variable_type;
    };

    class Function_Symbol : public Symbol_Entry {
    public:
        Function_Symbol(int line_no, Type *return_type, initializer_list<Type *> parameters)
                : return_type{return_type}, parameters{parameters} {
            references = vector<int>{line_no};
        }

        ~Function_Symbol() override {
            delete return_type;
            for (auto p: parameters) {
                delete p;
            }
        }

        string to_string() const override;

    private:
        Type *return_type;
        vector<Type *> parameters;
    };

    class Symbol_Table {
    public:
        Symbol_Table() : tables{
                vector<unordered_map<string, Symbol_Entry *> *>{1, new unordered_map<string, Symbol_Entry *>{}}} {};

        ~Symbol_Table() {
            for (auto p: tables) {
                delete p;
            }
        }

        vector<unordered_map<string, Symbol_Entry *> *> get_tables();

        void insert(string key, Symbol_Entry *value);

        Symbol_Entry *lookup(const string &key);

        void increase_scope();

        void decrease_scope();

    private:
        int scope = 0;

        vector<unordered_map<string, Symbol_Entry *> *> tables;
    };
}

#endif //__SYMBOL_HPP__
