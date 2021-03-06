#include <utility>

//
// Created by 10578 on 2019/11/17.
//

#ifndef __INFORMATION_HPP__
#define __INFORMATION_HPP__

#include "tac.hpp"

namespace SPL {
	/* Forward Declaration */
	class Type;

	class Scan_Info {
	public:
		std::string lexeme;
		int line_no;

		Scan_Info(std::string lexeme, int line) : lexeme{std::move(lexeme)}, line_no{line} {};
	};

	class Exp_Info {
	public:
		Exp_Info() : m_is_rvalue{false}, exp_type{nullptr} {}

		Exp_Info(const Exp_Info &other);

		Exp_Info(Type *exp_type, bool t_is_rvalue);

		explicit Exp_Info(bool is_known);

		bool is_rvalue();

		bool is_lvalue();

		virtual bool is_known();

		bool compassionate(Exp_Info *other);

		/* Type checker */
		bool m_is_rvalue = false;
		Type *exp_type = nullptr;

		/* IR generator */
		std::string temp_name = "__undefined__";
		TAC code;
		bool is_address = false;

	};

	class Unknown_Exp_Info : public Exp_Info {
		bool is_known() override;
	};
}

#endif //__INFORMATION_HPP__
