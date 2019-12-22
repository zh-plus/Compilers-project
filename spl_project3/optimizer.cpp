//
// Created by 10578 on 12/16/2019.
//

#include <unordered_set>

#include "optimizer.hpp"
#include "type_switch.hpp"

namespace SPL {
	using namespace std;

	void Basic_Block::print() {
		for (auto &&x: instructions) {
			cout << x->to_string() << endl;
		}
	}

	Basic_Block::Basic_Block(int start, int end, std::vector<Quadruple *> instructions) {
		this->start = start;
		this->end = end;

		this->instructions = vector<Quadruple *>(instructions.begin(), instructions.end());
	}

	void TAC_Optimizer::optimize(TAC *tac) {
		this->tac = tac;
		create_blocks();

		for (auto &&x: this->blocks) {
			cout << "     ===Block" << x.start << "-" << x.end << "===     " << endl;
			x.print();
		}
	}

	void TAC_Optimizer::create_blocks() {
		unordered_set<int> leaders; // Leaders except 0
		for (int i = 0, sz = tac->instructions.size(); i < sz; ++i) {
			type_case(tac->instructions[i],
			          [&](Goto_Quadru *quadru) {
				          leaders.insert(i + 1);
				          leaders.insert(index_label(quadru->label));
			          },
			          [&](CGoto_Quadru *quadru) {
				          leaders.insert(i + 1);
				          leaders.insert(index_label(quadru->label));
			          },
			          [&](Quadruple *quadru) {
				          // Default: Pass
			          });
		}

		std::vector<Quadruple *> instructions;
		int start = 0;
		for (int i = 0, sz = tac->instructions.size(); i < sz; ++i) {
			if (leaders.find(i) != leaders.end()) {
				blocks.emplace_back(start, i, instructions);

				start = i;
				instructions.clear();
			}

			instructions.push_back(tac->instructions[i]);

			if (i == sz - 1) {
				blocks.emplace_back(start, sz, instructions);
			}
		}
	}

	int TAC_Optimizer::index_label(Label *label) {
		for (int i = 0, sz = tac->instructions.size(); i < sz; ++i) {
			if (auto quadru = dynamic_cast<Label_Quadru *>(tac->instructions[i])) {
				if (quadru->label == label) {
					return i;
				}
			}
		}

		cout << "Label " << label->name << " not in instructions!" << endl;
		return -1;
	}

	/**
	 * Perform neutral elimination on block
	 * z := x + 0 => z := x
	 * y := y - 0 => y := y
	 * @param block: Basic_Block
	 * @return the number of optimized instructions
	 */
	int TAC_Optimizer::neutral_elimination(Basic_Block *block) {
		for (auto &instr: block->instructions) {
//			if (auto arith_quadru = dynamic_cast<Arith_Quadru *>(instr)) {
//				if (arith_quadru->arg1 == "#0") {
//					instr = make_assign(arith_quadru->lhs, arith_quadru->arg2);
//				} else if (arith_quadru->arg2 == "#0") {
//					instr = make_assign(arith_quadru->lhs, arith_quadru->arg1);
//				}
//			}
		}

		return 0;
	}

}