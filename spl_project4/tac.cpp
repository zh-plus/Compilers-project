//
// Created by 10578 on 12/4/2019.
//

#include "tac.hpp"

#include <utility>
#include "utils.hpp"

namespace SPL {
	using namespace std;
	using namespace string_literals;

	int Label::number = 1;


	string Assign_Quadru::to_string() const {
		return join({lhs, rhs}, " := ");
	}

	vector<string> *Assign_Quadru::used_var() {
		auto result = new vector{lhs};
		if (rhs[0] != '#') {
			result->push_back(rhs);
		}

		return result;
	}

	Assign_Value_Quadru::Assign_Value_Quadru(const string &lhs, const string &rhs) {
		this->lhs = lhs;
		this->rhs = rhs;
	}

	Assign_Address_Quadru::Assign_Address_Quadru(const string &lhs, const string &rhs) {
		this->lhs = lhs;
		this->rhs = "&" + rhs;
	}

	Assign_Deref_Quadru::Assign_Deref_Quadru(const string &lhs, const string &rhs) {
		this->lhs = lhs;
		this->rhs = "*" + rhs;
	}

	Deref_Assign_Quadru::Deref_Assign_Quadru(const string &lhs, const string &rhs) {
		this->lhs = "*" + lhs;
		this->rhs = rhs;
	}

	string Arith_Quadru::to_string() const {
		return join({lhs, ":="s, arg1, op_map[op], arg2}, " ");
	}

	vector<string> *Arith_Quadru::used_var() {
		auto result = new vector<string>{lhs};

		switch (op) {
			case op_type::PLUS:
			case op_type::MINUS:
				if (arg1[0] != '#') {
					result->push_back(arg1);
				}
				if (arg2[0] != '#') {
					result->push_back(arg2);
				}
				break;
			case op_type::MUL:
			case op_type::DIV:
				result->push_back(arg1);
				result->push_back(arg2);
				break;
			default:
				cerr << "Should not be other op!" << endl;
		};

		return result;
	}

	string Goto_Quadru::to_string() const {
		return join({"GOTO"s, label->name}, " ");
	}

	bool Goto_Quadru::cause_jump() {
		return true;
	}

	string CGoto_Quadru::to_string() const {
		return join({"IF"s, arg1, op_map[op], arg2, "GOTO"s, label->name}, " ");
	}

	vector<string> *CGoto_Quadru::used_var() {
		return new vector<string>{arg1, arg2};
	}

	bool CGoto_Quadru::cause_jump() {
		return true;
	}

	string Return_Quadru::to_string() const {
		return join({"RETURN"s, name}, " ");
	}

	vector<string> *Return_Quadru::used_var() {
		return new vector<string>{name};
	}

	bool Return_Quadru::cause_jump() {
		return true;
	}

	string Dec_Quadru::to_string() const {
		return join({"DEC"s, name, std::to_string(size)}, " ");
	}

	vector<string> *Dec_Quadru::used_var() {
		return new vector<string>{name};
	}

	string Param_Quadru::to_string() const {
		return join({"PARAM"s, name}, " ");
	}

	vector<string> *Param_Quadru::used_var() {
		return new vector<string>{name};
	}

	string Arg_Quadru::to_string() const {
		return join({"ARG"s, name}, " ");
	}

	vector<string> *Arg_Quadru::used_var() {
		return new vector<string>{name};
	}

	string Call_Quadru::to_string() const {
		return join({lhs, ":="s, "CALL"s, func_name}, " ");
	}

	vector<string> *Call_Quadru::used_var() {
		return new vector<string>{lhs};
	}

	string Read_Quadru::to_string() const {
		return join({"READ"s, name}, " ");
	}

	vector<string> *Read_Quadru::used_var() {
		return new vector<string>{name};
	}

	string Write_Quadru::to_string() const {
		return join({"WRITE"s, name}, " ");
	}

	vector<string> *Write_Quadru::used_var() {
		return new vector<string>{name};
	}

	void TAC::extend(const TAC &other) {
		auto other_ins = other.instructions;
		instructions.reserve(instructions.size() + other_ins.size());
		instructions.insert(instructions.end(), other_ins.begin(), other_ins.end());
	}

	void TAC::add(Quadruple *quadruple) {
		instructions.push_back(quadruple);
	}

	string Label_Quadru::to_string() const {
		return join({"LABEL"s, label->name, ":"s}, " ");
	}

	Label_Quadru::Label_Quadru(string name) {
		label = new Label(move(name));
	}

	string Func_Quadru::to_string() const {
		return join({"FUNCTION"s, name, ":"s}, " ");
	}

	void TAC::print() {
		for (auto &&x:instructions) {
			cout << x->to_string() << endl;
		}
	}

	vector<string> *Quadruple::used_var() {
		return new vector<string>{};
	}

	bool Quadruple::cause_jump() {
		return false;
	}
}