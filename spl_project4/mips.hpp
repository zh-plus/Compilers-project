//
// Created by 10578 on 1/3/2020.
//

#ifndef __MIPS_HPP__
#define __MIPS_HPP__

#include <string>
#include <utility>
#include <map>

#include "tac.hpp"
#include "utils.hpp"
#include "optimizer.hpp"
#include "lru.hpp"

namespace SPL {

	struct Register {
		explicit Register(std::string name) : name{std::move(name)} {}

		std::string name;

		std::string variable;

		bool dirty{false};
		bool idle{true};
	};

	class Register_Collection {
	public:
		Register_Collection() {
			for (auto &&x: register_name) {
				registers.push_back(new Register(x));
			}
		}

		~Register_Collection() {
			for (auto &&x: registers) {
				delete x;
			}
		}

		std::vector<Register *> get_usable();

		Register *get_reg(const std::string &reg_name);

		Register *get_idle();

		std::vector<Register *> registers;

	private:
		std::vector<std::string> register_name{
				"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3",
				"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
				"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
				"$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra"
		};
	};

	struct Variable {
		explicit Variable(std::string name) : name{std::move(name)} {};

		std::string name;

		/* Locations that can find the variable */
		Register *reg{nullptr};

		int stack_offset{0};

		int frame_offset{0};

		bool in_stack{false};
	};

	class Variable_Collection {
	public:
		Variable *get(const std::string &name);

		void add(Variable *variable);

		std::map<std::string, Variable *> variable_table;
	};


	class Code_Generator {
	public:
		explicit Code_Generator(const std::string &ir_filename);

		void generate();

		void generate(Basic_Block &block);

		void generate(Quadruple *ir);

		void generate(Label_Quadru *ir);

		void generate(Func_Quadru *ir);

		void generate(Assign_Value_Quadru *ir);

		void generate(Arith_Quadru *ir);

		void generate(Goto_Quadru *ir);

		void generate(CGoto_Quadru *ir);

		void generate(Return_Quadru *ir);

		void generate(Param_Quadru *ir);

		void generate(Arg_Quadru *ir);

		void generate(Call_Quadru *ir);

		void generate(Read_Quadru *ir);

		void generate(Write_Quadru *ir);

		/* Help functions*/

		void print();

		std::string compose(std::initializer_list<std::string> seq);

		/**
		 * Get the allocated register for variable name & immediate value.
		 * @param name
		 * @return
		 */
		std::string reg(const std::string &name, bool check_dirty = false);

		std::string imm(const std::string &name, bool negative = false);

		void emit(const std::string &code, bool indent = true);

		std::string get_imm_value(const std::string &name);

		Register *need_reg();

		void save(Register *reg);

		std::string offset_fmt(int offset, const std::string &name);

		void increase_stack(int units = 4);

		void decrease_stack(int units = 4);

	private:
		TAC tac;

		std::vector<std::string> instr;

		Basic_Blocks *blocks = nullptr;

		Register_Collection registers;

		Variable_Collection variables;

//		/* Used in each block. Re-calculate this entering new block. */
//		std::map<std::string, int> var_occurrences;

		int param_num = 0;
		int arg_num = 0;

		int frame_offset = 0;

		std::vector<std::string> arg_list;

		/* Used in register replacement */
		LRUAllocator<Register *> *lru;

	};

	Quadruple *string2tac(std::string line);

}


#endif //__MIPS_HPP__
