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
		basic_blocks = new Basic_Blocks(tac->instructions);
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

	Basic_Blocks::Basic_Blocks(std::vector<Quadruple *> instructions) {
		this->instructions = instructions;

		unordered_set<int> leaders; // Leaders except 0
		for (int i = 0, sz = instructions.size(); i < sz; ++i) {
			type_case(instructions[i],
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

		std::vector<Quadruple *> temp_instrs;
		int start = 0;
		for (int i = 0, sz = instructions.size(); i < sz; ++i) {
			if (leaders.find(i) != leaders.end()) {
				blocks.emplace_back(start, i, temp_instrs);

				start = i;
				temp_instrs.clear();
			}

			temp_instrs.push_back(instructions[i]);

			if (i == sz - 1) {
				blocks.emplace_back(start, sz, temp_instrs);
			}
		}
	}

	int Basic_Blocks::index_label(Label *label) {
		for (int i = 0, sz = instructions.size(); i < sz; ++i) {
			if (auto quadru = dynamic_cast<Label_Quadru *>(instructions[i])) {
				if (quadru->label->name == label->name) {
					return i;
				}
			}
		}

		cout << "Label " << label->name << " not in instructions!" << endl;
		return -1;
	}
}