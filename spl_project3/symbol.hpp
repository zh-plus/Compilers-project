//
// Created by 10578 on 10/29/2019.
//

#ifndef __SYMBOL_HPP__
#define __SYMBOL_HPP__

#include <vector>
#include <unordered_map>
#include "parser.tab.hpp"
#include "utils.hpp"
#include "type.hpp"
#include "ast.hpp"


namespace SPL {


	class Symbol_Table;

	class Local_Symbol_Table;

	class Global_Symbol_Table;

	using token_type = SPL_Parser::token_type;

	class Symbol_Entry {
	public:
		virtual ~Symbol_Entry() = default;

		friend std::ostream &operator<<(std::ostream &os, const Symbol_Entry &obj);

		virtual Type *get_type() = 0;

		[[nodiscard]] virtual std::string to_string() const = 0;

		std::string name;

		int line_no = -1;
	};

	/**
	 * Symbol for Struct definition.
	 */
	class Struct_Def_Symbol : public Symbol_Entry {
	public:
		~Struct_Def_Symbol() override {
			delete struct_type;
		}

		explicit Struct_Def_Symbol(Struct_Type *struct_type);

		Type *get_type() override;

		[[nodiscard]] std::string to_string() const override;


		Struct_Type *struct_type;
	};

	class Variable_Symbol : public Symbol_Entry {
	public:
		Variable_Symbol(std::string name, Type *type);

		Variable_Symbol(Type *type, std::string id, int line_no);

		~Variable_Symbol() override {
			delete variable_type;
		}

		Type *get_type() override;

		[[nodiscard]] std::string to_string() const override;

	private:
		Type *variable_type;
	};

	class Function_Symbol : public Symbol_Entry {
	public:
		Function_Symbol(std::string name, Type *return_type, std::initializer_list<Type *> parameters);

		Function_Symbol(Type *return_type, std::string id, int line_no, std::vector<Type *> parameter_v);

		~Function_Symbol() override {
			delete return_type;
			for (auto p: parameters) {
				delete p;
			}
		}

		Type *get_type() override;

		std::vector<Type *> get_parameters();

		[[nodiscard]] std::string to_string() const override;

	private:
		Type *return_type;
		std::vector<Type *> parameters;
	};

	class Symbol_Table {
	public:
		Symbol_Table()
				: m_children{std::vector<Local_Symbol_Table *>{}},
				  table{std::unordered_map<std::string, Symbol_Entry *>{}} {};

		virtual ~Symbol_Table();

		std::unordered_map<std::string, Symbol_Entry *> get_table();

		std::string to_string();

		void add_child(Local_Symbol_Table *local);

		void insert(Symbol_Entry *entry);

		bool contains(std::string id);

		virtual bool is_global() = 0;

		virtual Global_Symbol_Table *global_scope() = 0;

		virtual Symbol_Table *parent() = 0;

		virtual Symbol_Entry *lookup(std::string name) = 0;

	protected:

		std::vector<Local_Symbol_Table *> m_children;
		std::unordered_map<std::string, Symbol_Entry *> table;
	};

	class Local_Symbol_Table : public Symbol_Table {
	public:
		explicit Local_Symbol_Table(Symbol_Table *parent) : m_parent{parent} {
			parent->add_child(this);
		};

		~Local_Symbol_Table() override {
			delete m_parent;
		}

		std::vector<Local_Symbol_Table *> children();

		bool is_global() override;

		Global_Symbol_Table *global_scope() override;

		Symbol_Table *parent() override;

		Symbol_Entry *lookup(std::string name) override;

	private:
		Symbol_Table *m_parent;

	};

	class Global_Symbol_Table : public Symbol_Table {
	public:
		Global_Symbol_Table() : Symbol_Table() {};

		~Global_Symbol_Table() override = default;

		bool is_global() override;

		Global_Symbol_Table *global_scope() override;

		Symbol_Table *parent() override;

		Symbol_Entry *lookup(std::string name) override;

	};
}

#endif //__SYMBOL_HPP__
