//
// Created by 10578 on 10/29/2019.
//

#include "symbol.hpp"


namespace SPL {
	using namespace std;

	ostream &operator<<(ostream &os, const Symbol_Entry &obj) {
		os << obj.to_string();
		return os;
	}

	string Variable_Symbol::to_string() const {
		string result = "Variable: " + variable_type->to_string();
		return result;
	}

	Variable_Symbol::Variable_Symbol(std::string name, Type *type) {
		this->name = name;
		this->line_no = type->line_no;
		this->variable_type = type;
	}

	std::string Struct_Def_Symbol::to_string() const {
		string result = "Struct Def: " + struct_type->struct_id + ": ";
		result += struct_type->to_string();
		return result;
	}

	Struct_Def_Symbol::Struct_Def_Symbol(Struct_Type *struct_type) {
		this->name = struct_type->struct_id;
		this->line_no = struct_type->line_no;
		this->struct_type = struct_type;
	}

	string Function_Symbol::to_string() const {
		string result = "Function: Return - " + return_type->to_string();
		result += +", Parameters - ";
		for (const auto &x: parameters) {
			result += " " + x->to_string();
		}
		return result;
	}

	Function_Symbol::Function_Symbol(std::string name, Type *return_type, std::initializer_list<Type *> parameters) {
		this->return_type = return_type;
		this->parameters = parameters;
		this->name = name;
		this->line_no = return_type->line_no;
	}

	void Symbol_Table::add_child(Local_Symbol_Table *local) {
		m_children.push_back(local);
	}

	void Symbol_Table::insert(Symbol_Entry *entry) {
		if (string name = entry->name; table.find(name) != table.end()) {
			cout << "Semantic Error! " << name << " has been in symbol table at line: " << entry->line_no
			     << endl;
		} else {
			table[name] = entry;
		}
	}

	std::unordered_map<std::string, Symbol_Entry *> Symbol_Table::get_table() {
		return table;
	}

	Symbol_Table::~Symbol_Table() {
		for (auto p: m_children) {
			delete p;
		}
	}

	Symbol_Entry *Global_Symbol_Table::lookup(std::string name) {
		if (table.find(name) != table.end()) {
			return table[name];
		}

		return nullptr;
	}

	bool Global_Symbol_Table::is_global() {
		return true;
	}

	Global_Symbol_Table *Global_Symbol_Table::global_scope() {
		return this;
	}

	Symbol_Table *Global_Symbol_Table::parent() {
		return nullptr;
	}

	bool Local_Symbol_Table::is_global() {
		return false;
	}

	Global_Symbol_Table *Local_Symbol_Table::global_scope() {
		return m_parent->global_scope();
	}

	Symbol_Table *Local_Symbol_Table::parent() {
		return m_parent;
	}

	std::vector<Local_Symbol_Table *> Local_Symbol_Table::children() {
		return m_children;
	}

	Symbol_Entry *Local_Symbol_Table::lookup(std::string name) {
		if (table.find(name) != table.end()) {
			return table[name];
		} else {
			return m_parent->lookup(name);
		}
	}

}

