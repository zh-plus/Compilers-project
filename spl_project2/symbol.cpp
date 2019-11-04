//
// Created by 10578 on 10/29/2019.
//

#include "symbol.hpp"

namespace SPL {
    Symbol_Entry *Symbol_Table::lookup(const string &key) {
        for (auto &table: tables) {
            if (table->find(key) != table->end()) {
                return table->at(key);
            }
        }
        return nullptr;
    }

    void Symbol_Table::insert(string key, Symbol_Entry *value) {
        if (Symbol_Entry *entry = lookup(key)) {
            entry->add_reference(value->get_decl_line());
        } else {
            tables.back()->insert(make_pair(key, value));
        }
    }

    void Symbol_Table::increase_scope() {
        tables.emplace_back();
    }

    void Symbol_Table::decrease_scope() {
        tables.pop_back();
    }

    vector<unordered_map<string, Symbol_Entry *> *> Symbol_Table::get_tables() {
        return tables;
    }

    void Symbol_Entry::add_reference(int line_no) {
        references.emplace_back(line_no);
    }

    int Symbol_Entry::get_decl_line() {
        return *references.begin();
    }

    ostream &operator<<(ostream &os, const Symbol_Entry &obj) {
        os << obj.to_string() << endl;
        return os;
    }

    ostream &operator<<(ostream &os, const Type &obj) {
        os << obj.to_string() << endl;
        return os;
    }

    string Variable_Symbol::to_string() const {
        string result = "Variable: " + variable_type->to_string() + ": referenced in line";
        for (const auto &x: references) {
            result += " " + std::to_string(x);
        }
        return result;
    }

    string Function_Symbol::to_string() const {
        string result = "Function: Return - " + return_type->to_string();
        result +=  + ", Parameters - ";
        for (const auto &x: parameters) {
            result += " " + x->to_string();
        }
        result += ": referenced in line";
        for (const auto &x: references) {
            result += " " + std::to_string(x);
        }
        return result;
    }
}

