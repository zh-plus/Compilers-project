//
// Created by 10578 on 12/4/2019.
//

#ifndef __TAC_HPP__
#define __TAC_HPP__

#include <utility>

#include "type.hpp"

namespace SPL {
	class Label {
	public:
		std::string name;

		Label() {
			name = "label" + std::to_string(get_number());
		};

		explicit Label(std::string name) : name{std::move(name)} {};

		[[nodiscard]] std::string to_string() const {
			return name;
		}

		static int get_number() {
			return number++;
		}

	private:
		static int number;
	};

	class Quadruple {
	public:
		virtual ~Quadruple() = default;

		[[nodiscard]] virtual std::string to_string() const = 0;

		virtual std::vector<std::string> *used_var();

		virtual bool cause_jump();
	};

	class Label_Quadru : public Quadruple {
	public:
		explicit Label_Quadru(Label *label) : label{label} {}

		explicit Label_Quadru(std::string name);

		~Label_Quadru() override {
			delete label;
		}

		[[nodiscard]] std::string to_string() const override;

		Label *label;
	};

	class Func_Quadru : public Quadruple {
	public:
		explicit Func_Quadru(std::string name) : name{std::move(name)} {}

		[[nodiscard]] std::string to_string() const override;

		std::string name;
	};

	class Assign_Quadru : public Quadruple {
	public:
		[[nodiscard]] std::string to_string() const override;

		std::vector<std::string> *used_var() override;

		std::string rhs;
		std::string lhs;
	};

	class Assign_Value_Quadru : public Assign_Quadru {
	public:
		Assign_Value_Quadru(const std::string &lhs, const std::string &rhs);
	};

	class Assign_Address_Quadru : public Assign_Quadru {
	public:
		Assign_Address_Quadru(const std::string &lhs, const std::string &rhs);
	};

	class Assign_Deref_Quadru : public Assign_Quadru {
	public:
		Assign_Deref_Quadru(const std::string &lhs, const std::string &rhs);
	};

	class Deref_Assign_Quadru : public Assign_Quadru {
	public:
		Deref_Assign_Quadru(const std::string &lhs, const std::string &rhs);
	};

	class Arith_Quadru : public Quadruple {
	public:
		Arith_Quadru(std::string lhs, std::string arg1, std::string arg2, op_type op)
				: lhs{std::move(lhs)}, arg1{std::move(arg1)}, arg2{std::move(arg2)}, op{op} {};

		Arith_Quadru(std::string lhs, std::string arg1, std::string arg2, token_type op)
				: lhs{std::move(lhs)}, arg1{std::move(arg1)}, arg2{std::move(arg2)} {
			this->op = [&]() -> op_type {
				switch (op) {
					case token_type::PLUS:
						return op_type::PLUS;
					case token_type::MINUS:
						return op_type::MINUS;
					case token_type::MUL:
						return op_type::MUL;
					case token_type::DIV:
						return op_type::DIV;
					default:
						std::cout << "Arithmetic operator can not be others!" << std::endl;
						return op_type::PLUS;
				}
			}();
		};

		[[nodiscard]] std::string to_string() const override;

		std::vector<std::string> *used_var() override;

		std::string lhs;
		std::string arg1;
		std::string arg2;
		op_type op;
	};

	class Goto_Quadru : public Quadruple {
	public:
		explicit Goto_Quadru(Label *label) : label{label} {};

		explicit Goto_Quadru(std::string name) : label{new Label(std::move(name))} {};

		~Goto_Quadru() override {
			delete label;
		}

		[[nodiscard]] std::string to_string() const override;

		bool cause_jump() override;

		Label *label;
	};

	class CGoto_Quadru : public Quadruple {
	public:
		CGoto_Quadru(std::string arg1, std::string arg2, op_type op, std::string name)
				: arg1{std::move(arg1)}, arg2{std::move(arg2)}, op{op}, label{new Label(std::move(name))} {};

		CGoto_Quadru(std::string arg1, std::string arg2, op_type op, Label *label)
				: arg1{std::move(arg1)}, arg2{std::move(arg2)}, op{op}, label{label} {};

		CGoto_Quadru(std::string arg1, std::string arg2, token_type op, Label *label)
				: arg1{std::move(arg1)}, arg2{std::move(arg2)}, label{label} {
			this->op = [&]() -> op_type {
				switch (op) {
					case token_type::LT:
						return op_type::LT;
					case token_type::LE:
						return op_type::LE;
					case token_type::GT:
						return op_type::GT;
					case token_type::GE:
						return op_type::GE;
					case token_type::NE:
						return op_type::NE;
					case token_type::EQ:
						return op_type::EQ;
					default:
						std::cout << "Relationship operator can not be others!" << std::endl;
						return op_type::LT;
				}
			}();
		};

		~CGoto_Quadru() override {
			delete label;
		}

		[[nodiscard]] std::string to_string() const override;

		std::vector<std::string> *used_var() override;

		bool cause_jump() override;

		Label *label;
		std::string arg1;
		std::string arg2;
		op_type op;
	};

	class Return_Quadru : public Quadruple {
	public:
		explicit Return_Quadru(std::string name) : name{std::move(name)} {};

		[[nodiscard]] std::string to_string() const override;

		std::vector<std::string> *used_var() override;

		bool cause_jump() override;

		std::string name;
	};

	class Dec_Quadru : public Quadruple {
	public:
		Dec_Quadru(std::string name, int size) : name{std::move(name)}, size{size} {};

		[[nodiscard]] std::string to_string() const override;

		std::vector<std::string> *used_var() override;

		std::string name;
		int size;
	};

	class Param_Quadru : public Quadruple {
	public:
		explicit Param_Quadru(std::string name) : name{std::move(name)} {};

		[[nodiscard]] std::string to_string() const override;

		std::vector<std::string> *used_var() override;

		std::string name;
	};

	class Arg_Quadru : public Quadruple {
	public:
		explicit Arg_Quadru(std::string name) : name{std::move(name)} {};

		[[nodiscard]] std::string to_string() const override;

		std::vector<std::string> *used_var() override;

		std::string name;
	};

	class Call_Quadru : public Quadruple {
	public:
		Call_Quadru(std::string lhs, std::string func_name)
				: lhs{std::move(lhs)}, func_name{std::move(func_name)} {};

		[[nodiscard]] std::string to_string() const override;

		std::vector<std::string> *used_var() override;

		std::string lhs;
		std::string func_name;
	};

	class Read_Quadru : public Quadruple {
	public:
		explicit Read_Quadru(std::string name) : name{std::move(name)} {};

		[[nodiscard]] std::string to_string() const override;

		std::vector<std::string> *used_var() override;

		std::string name;
	};

	class Write_Quadru : public Quadruple {
	public:
		explicit Write_Quadru(std::string name) : name{std::move(name)} {};

		[[nodiscard]] std::string to_string() const override;

		std::vector<std::string> *used_var() override;

		std::string name;
	};


	class TAC {
	public:
		~TAC() {
			for (auto &&ptr: instructions) {
				delete ptr;
			}
		}

		void extend(const TAC &other);

		void add(Quadruple *quadruple);

		std::vector<Quadruple *> instructions;

		void print();
	};

}


#endif //__TAC_HPP__
