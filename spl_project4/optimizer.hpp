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

	class TAC_Optimizer {
	public:
		void optimize(TAC *tac);

	private:
		void create_blocks();

		int index_label(Label *label);

		/* Local Optimizations */

		int neutral_elimination(Basic_Block *block);

		TAC *tac;

		std::vector<Basic_Block> blocks;

	};


}

#endif //__OPTIMIZER_HPP__
