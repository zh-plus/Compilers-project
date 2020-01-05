//
// Created by 10578 on 12/4/2019.
//

#include "tac.hpp"

#include <utility>
#include "utils.hpp"

namespace SPL {
	using namespace std;
	using namespace std::string_literals;

	int Label::number = 1;


	std::string Assign_Quadru::to_string() const {
		return join({lhs, rhs}, " := ");
	}

	Assign_Value_Quadru::Assign_Value_Quadru(const std::string &lhs, const std::string &rhs) {
		this->lhs = lhs;
		this->rhs = rhs;
	}

	Assign_Address_Quadru::Assign_Address_Quadru(const std::string &lhs, const std::string &rhs) {
		this->lhs = lhs;
		this->rhs = "&" + rhs;
	}

	Assign_Deref_Quadru::Assign_Deref_Quadru(const std::string &lhs, const std::string &rhs) {
		this->lhs = lhs;
		this->rhs = "*" + rhs;
	}

	Deref_Assign_Quadru::Deref_Assign_Quadru(const std::string &lhs, const std::string &rhs) {
		this->lhs = "*" + lhs;
		this->rhs = rhs;
	}

	std::string Arith_Quadru::to_string() const {
		return join({lhs, ":="s, arg1, op_map[op], arg2}, " ");
	}

	std::string Goto_Quadru::to_string() const {
		return join({"GOTO"s, label->name}, " ");
	}

	std::string CGoto_Quadru::to_string() const {
		return join({"IF"s, arg1, op_map[op], arg2, "GOTO"s, label->name}, " ");
	}

	std::string Return_Quadru::to_string() const {
		return join({"RETURN"s, name}, " ");
	}

	std::string Dec_Quadru::to_string() const {
		return join({"DEC"s, name, std::to_string(size)}, " ");
	}

	std::string Param_Quadru::to_string() const {
		return join({"PARAM"s, name}, " ");
	}

	std::string Arg_Quadru::to_string() const {
		return join({"ARG"s, name}, " ");
	}

	std::string Call_Quadru::to_string() const {
		return join({lhs, ":="s, "CALL"s, func_name}, " ");
	}

	std::string Read_Quadru::to_string() const {
		return join({"READ"s, name}, " ");
	}

	std::string Write_Quadru::to_string() const {
		return join({"WRITE"s, name}, " ");
	}

	void TAC::extend(const TAC &other) {
		auto other_ins = other.instructions;
		instructions.reserve(instructions.size() + other_ins.size());
		instructions.insert(instructions.end(), other_ins.begin(), other_ins.end());
	}

	void TAC::add(Quadruple *quadruple) {
		instructions.push_back(quadruple);
	}

	std::string Label_Quadru::to_string() const {
		return join({"LABEL"s, label->name, ":"s}, " ");
	}

	Label_Quadru::Label_Quadru(std::string name) {
		label = new Label(std::move(name));
	}

	std::string Func_Quadru::to_string() const {
		return join({"FUNCTION"s, name, ":"s}, " ");
	}

	void TAC::print() {
		for (auto &&x:instructions) {
			std::cout << x->to_string() << std::endl;
		}
	}

	Quadruple *make_assign(string lhs, string rhs) {

	}
}