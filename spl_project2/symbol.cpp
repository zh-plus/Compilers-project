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

	string Function_Symbol::to_string() const {
		string result = "Function: Return - " + return_type->to_string();
		result += +", Parameters - ";
		for (const auto &x: parameters) {
			result += " " + x->to_string();
		}
		return result;
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

