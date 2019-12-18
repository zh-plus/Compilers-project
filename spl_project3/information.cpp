//
// Created by 10578 on 2019/11/17.
//

#include "type.hpp"
#include "information.hpp"


namespace SPL {

	bool Exp_Info::is_rvalue() {
		return m_is_rvalue;
	}

	bool Exp_Info::is_lvalue() {
		return !m_is_rvalue;
	}

	Exp_Info::Exp_Info(Type *exp_type, bool t_is_rvalue) {
		this->exp_type = exp_type;
		this->m_is_rvalue = t_is_rvalue;
	}

	Exp_Info::Exp_Info(const Exp_Info &other) {
		this->exp_type = other.exp_type;
		this->m_is_rvalue = other.m_is_rvalue;
	}

	Exp_Info::Exp_Info(bool is_known) {
		this->exp_type = nullptr;
		this->m_is_rvalue = false;
	}

	bool Exp_Info::is_known() {
		return true;
	}

	bool Exp_Info::compassionate(Exp_Info *other) {
		return exp_type->compassionate(other->exp_type);
	}


	bool Unknown_Exp_Info::is_known() {
		return false;
	}
}