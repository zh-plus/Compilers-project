//
// Created by 10578 on 1/3/2020.
//

#ifndef __MIPS_HPP__
#define __MIPS_HPP__

#include <string>

#include "tac.hpp"
#include "utils.hpp"
#include "optimizer.hpp"

namespace SPL {
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

		/**
		 * Get the allocated register for variable name & immediate value.
		 * @param name
		 * @return
		 */
		std::string reg(std::string name);

		static std::string imm(const std::string &name, bool negative = false);

		void emit(const std::string &code, bool indent = true);

	private:
		TAC tac;

		std::vector<std::string> instr;

		Basic_Blocks *blocks = nullptr;
	};

	Quadruple *string2tac(const std::string &line);

}


#endif //__MIPS_HPP__
