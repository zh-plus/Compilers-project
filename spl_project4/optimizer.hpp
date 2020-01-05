//
// Created by 10578 on 12/16/2019.
//

#ifndef __OPTIMIZER_HPP__
#define __OPTIMIZER_HPP__

#include <vector>
#include "tac.hpp"

namespace SPL {
	class Basic_Block {
	public:

		explicit Basic_Block(int start, int end, std::vector<Quadruple *> instructions);

		void print();

		std::vector<Quadruple *> instructions;

		int start;
		int end;
	};

	class Basic_Blocks {
	public:
		explicit Basic_Blocks(std::vector<Quadruple *> instructions);

		int index_label(Label *label);

		std::vector<Quadruple *> instructions;

		std::vector<Basic_Block> blocks;
	};


	class TAC_Optimizer {
	public:
		void optimize(TAC *tac);

	private:

		/* Local Optimizations */

		int neutral_elimination(Basic_Block *block);

		TAC *tac = nullptr;

		Basic_Blocks *basic_blocks = nullptr;

	};


}

#endif //__OPTIMIZER_HPP__
