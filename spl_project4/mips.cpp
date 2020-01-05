//
// Created by 10578 on 1/3/2020.
//

#include <fstream>
#include <sstream>

#include "mips.hpp"
#include "type_switch.hpp"


namespace SPL {
	using namespace std;

	Code_Generator::Code_Generator(const string &ir_filename) {
		ifstream ir_file(ir_filename);

		string line;
		while (getline(ir_file, line)) {
			if (!line.empty()) {
				tac.add(string2tac(line));
			}
		}

		blocks = new Basic_Blocks(tac.instructions);

		// Load Read & Write asm code
		string code = ".data\n"
		              "_prompt: .asciiz \"Enter an integer:\"\n"
		              "_ret: .asciiz \"\\n\"\n"
		              ".globl main\n"
		              ".text\n"
		              "read:\n"
		              "    li $v0, 4\n"
		              "    la $a0, _prompt\n"
		              "    syscall\n"
		              "    li $v0, 5\n"
		              "    syscall\n"
		              "    jr $ra\n"
		              "write:\n"
		              "    li $v0, 1\n"
		              "    syscall\n"
		              "    li $v0, 4\n"
		              "    la $a0, _ret\n"
		              "    syscall\n"
		              "    move $v0, $0\n"
		              "    jr $ra";
		vector<string> code_seq = split(code, "\n");
		instr.reserve(instr.size() + distance(code_seq.begin(), code_seq.end()));
		instr.insert(instr.end(), code_seq.begin(), code_seq.end());
	}

	void Code_Generator::print() {
		for (auto &&x: instr) {
			cout << x << endl;
		}
	}

	void Code_Generator::generate() {
		for (auto &&block: blocks->blocks) {
			generate(block);
		}
	}

	void Code_Generator::generate(Basic_Block &block) {
		for (auto &&code: block.instructions) {
			generate(code);
		}
	}

	void Code_Generator::generate(Quadruple *ir) {
		type_case(ir,
		          [&](Label_Quadru *quadru) { generate(quadru); },
		          [&](Func_Quadru *quadru) { generate(quadru); },
		          [&](Assign_Value_Quadru *quadru) { generate(quadru); },
		          [&](Arith_Quadru *quadru) { generate(quadru); },
		          [&](Goto_Quadru *quadru) { generate(quadru); },
		          [&](CGoto_Quadru *quadru) { generate(quadru); },
		          [&](Return_Quadru *quadru) { generate(quadru); },
		          [&](Param_Quadru *quadru) { generate(quadru); },
		          [&](Arg_Quadru *quadru) { generate(quadru); },
		          [&](Call_Quadru *quadru) { generate(quadru); },
		          [&](Read_Quadru *quadru) { generate(quadru); },
		          [&](Write_Quadru *quadru) { generate(quadru); }
		);
	}

	void Code_Generator::generate(Label_Quadru *ir) {
		emit(ir->label->name + ":", false);
	}

	void Code_Generator::generate(Func_Quadru *ir) {
		instr.emplace_back("Func_Quadru: " + ir->to_string());
	}

	void Code_Generator::generate(Assign_Value_Quadru *ir) {
		string code;
		if (ir->rhs[0] == '#') { // Immediate value
			code = join({"li"s, reg(ir->lhs), imm(ir->rhs, false)});
		} else {
			code = join({"move"s, reg(ir->lhs), reg(ir->rhs)});
		}

		emit(code);
	}

	void Code_Generator::generate(Arith_Quadru *ir) {
		string code;
		switch (ir->op) {
			case op_type::PLUS :
				if (ir->arg2[1] == '#') {
					code = join({"addi"s, reg(ir->lhs), reg(ir->arg1), imm(ir->arg2)});
				} else {
					code = join({"add"s, reg(ir->lhs), reg(ir->arg1), reg(ir->arg2)});
				}
				break;
			case op_type::MINUS:
				if (ir->arg2[1] == '#') {
					code = join({"addi"s, reg(ir->lhs), reg(ir->arg1), imm(ir->arg2, true)});
				} else {
					code = join({"sub"s, reg(ir->lhs), reg(ir->arg1), reg(ir->arg2)});
				}
				break;
			case op_type::MUL:
				code = join({"mul"s, reg(ir->lhs), reg(ir->arg1), reg(ir->arg2)});
				break;
			case op_type::DIV:
				emit(join({"div"s, reg(ir->arg1), reg(ir->arg2)}));
				emit(join({"mflo"s, reg(ir->lhs)}));
				break;
			default:
				cerr << "No other op!" << endl;
		}

		emit(code);
	}

	void Code_Generator::generate(Goto_Quadru *ir) {
		emit(join({"j"s, ir->label->to_string()}));
	}

	void Code_Generator::generate(CGoto_Quadru *ir) {
		string op_code;
		switch (ir->op) {
			case op_type::LT:
				op_code = "blt";
				break;
			case op_type::LE:
				op_code = "ble";
				break;
			case op_type::GT:
				op_code = "bgt";
				break;
			case op_type::GE:
				op_code = "bge";
				break;
			case op_type::NE:
				op_code = "bne";
				break;
			case op_type::EQ:
				op_code = "beq";
				break;
			default:
				cerr << "No other op!" << endl;
		}

		emit(join({op_code, reg(ir->arg1), reg(ir->arg2), ir->label->to_string()}));
	}

	void Code_Generator::generate(Return_Quadru *ir) {
		emit(join({"move"s, "$v0"s, reg(ir->name)}));
		emit(join({"jr"s, "$ra"s}));
	}

	void Code_Generator::generate(Param_Quadru *ir) {
		instr.emplace_back("Param_Quadru: " + ir->to_string());
	}

	void Code_Generator::generate(Arg_Quadru *ir) {
		instr.emplace_back("Arg_Quadru: " + ir->to_string());
	}

	void Code_Generator::generate(Call_Quadru *ir) {
		instr.emplace_back("Call_Quadru: " + ir->to_string());
	}

	void Code_Generator::generate(Read_Quadru *ir) {
		instr.emplace_back("Read_Quadru: " + ir->to_string());
	}

	void Code_Generator::generate(Write_Quadru *ir) {
		instr.emplace_back("Write_Quadru: " + ir->to_string());
	}

	std::string Code_Generator::reg(std::string name) {
		return name;
	}

	std::string Code_Generator::imm(const std::string &name, bool negative) {
		return (negative ? "-" : "") + name.substr(1, name.size() - 1);
	}

	void Code_Generator::emit(const std::string &code, bool indent) {
		if (!code.empty()) {
			instr.emplace_back((indent ? "    " : "") + code);
		}
	}

	Quadruple *string2tac(const std::string &line) {
		auto tokens = split(line);
		Quadruple *quadruple = nullptr;
		if (tokens[0] == "LABEL") {
			quadruple = new Label_Quadru(tokens[1]);
		} else if (tokens[0] == "FUNCTION") {
			quadruple = new Func_Quadru(tokens[1]);
		} else if (tokens[1] == ":=") {
			if (tokens.size() == 3) {
				quadruple = new Assign_Value_Quadru(tokens[0], tokens[2]);
			} else if (tokens.size() == 5) {
				op_type op;
				switch (tokens[3][0]) {
					case '+':
						op = op_type::PLUS;
						break;
					case '-':
						op = op_type::MINUS;
						break;
					case '*':
						op = op_type::MUL;
						break;
					case '/':
						op = op_type::DIV;
						break;
				}

				quadruple = new Arith_Quadru(tokens[0], tokens[2], tokens[4], op);
			} else if (tokens.size() == 4) {
				quadruple = new Call_Quadru(tokens[0], tokens[3]);
			}

		} else if (tokens[0] == "GOTO") {
			quadruple = new Goto_Quadru(tokens[1]);
		} else if (tokens[0] == "IF") {
			op_type op;
			if (tokens[2] == "<") {
				op = op_type::LT;
			} else if (tokens[2] == "<=") {
				op = op_type::LE;
			} else if (tokens[2] == ">") {
				op = op_type::GT;
			} else if (tokens[2] == ">=") {
				op = op_type::GE;
			} else if (tokens[2] == "!=") {
				op = op_type::NE;
			} else if (tokens[2] == "==") {
				op = op_type::EQ;
			} else {
				std::cout << "can not be others!" << std::endl;
			}

			quadruple = new CGoto_Quadru(tokens[1], tokens[3], op, tokens[5]);
		} else if (tokens[0] == "RETURN") {
			quadruple = new Return_Quadru(tokens[1]);
		} else if (tokens[0] == "PARAM") {
			quadruple = new Param_Quadru(tokens[1]);
		} else if (tokens[0] == "ARG") {
			quadruple = new Arg_Quadru(tokens[1]);
		} else if (tokens[0] == "ARG") {
			quadruple = new Arg_Quadru(tokens[1]);
		} else if (tokens[0] == "READ") {
			quadruple = new Read_Quadru(tokens[1]);
		} else if (tokens[0] == "WRITE") {
			quadruple = new Write_Quadru(tokens[1]);
		}

		return quadruple;
	}
}

