//
// Created by 10578 on 10/29/2019.
//

#include <unordered_map>

#include "symbol.hpp"
#include "ast.hpp"

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

	Variable_Symbol::Variable_Symbol(Type *type, string id, int line_no) {
		this->name = id;
		this->line_no = line_no;
		this->variable_type = type;
	}

	Type *Variable_Symbol::get_type() {
		return variable_type;
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

	Type *Struct_Def_Symbol::get_type() {
		return struct_type;
	}

	string Function_Symbol::to_string() const {
		string result = "Function: Return - " + return_type->to_string();
		result += +", Parameters - ";
		for (int i = 0, sz = parameters.size(); i < sz; ++i) {
			result += parameters[i]->to_string();
			if (i != sz - 1) {
				result += ", ";
			}
		}
		return result;
	}

	Function_Symbol::Function_Symbol(std::string name, Type *return_type, std::initializer_list<Type *> parameters) {
		this->return_type = return_type;
		this->parameters = parameters;
		this->name = name;
		this->line_no = return_type->line_no;
	}

	Function_Symbol::Function_Symbol(Type *return_type, std::string name,
	                                 int line_no, vector<Type *> parameter_v) {
		this->return_type = return_type;
		this->name = name;
		this->line_no = line_no;

		this->parameters = std::move(parameter_v);
	}

	Type *Function_Symbol::get_type() {
		return return_type;
	}

	std::vector<Type *> Function_Symbol::get_parameters() {
		return parameters;
	}

	void Symbol_Table::add_child(Local_Symbol_Table *local) {
		m_children.push_back(local);
	}

	void Symbol_Table::insert(Symbol_Entry *entry) {
		if (string name = entry->name; contains(name)) {
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

	string Symbol_Table::to_string() {
		string result;
		for (auto &y: get_table()) {
			result += "key: " + y.first + "\t=====\t";
			result += "value: " + (*(y.second)).to_string() + "\n";
		}

		return result;
	}

	/**
	 * Is this(this local table) contains id, but not search the parent table.
	 * @param id searched name.
	 * @return true if found.
	 */
	bool Symbol_Table::contains(std::string id) {
		return table.find(id) != table.end();
	}

	Symbol_Entry *Global_Symbol_Table::lookup(std::string name) {
		if (contains(name)) {
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
		if (contains(name)) {
			return table[name];
		} else {
			return m_parent->lookup(name);
		}
	}

}

