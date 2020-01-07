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

		lru = new LRUAllocator<Register *>(registers.get_usable().size());

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
		// Get the occurrences of variables.
		var_occurrences.clear();
		for (auto &&code: block.instructions) {
			for (auto &&var: *code->used_var()) {
				if (var_occurrences.find(var) == var_occurrences.end()) {
					var_occurrences[var] = 1;
				} else {
					var_occurrences[var] += 1;
				}
			}
		}

		// Generate mips instructions.
		for (auto &&code: block.instructions) {
			generate(code);
		}

//		if (!block.instructions.back()->cause_jump()) {
//			store_all();
//		}
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
		// Init the param_num and arg_num
		param_num = 0;
		arg_num = 0;

		emit(ir->name + ":", false);

		// Record the previous $fp
		emit(compose({"addi", "$sp", "$sp", "-4"}));
		emit(compose({"sw", "$fp", "($sp)"}));

		// Let $fp to be current $sp
		emit(compose({"move", "$fp", "$sp"}));
		frame_offset = 0;
	}

	void Code_Generator::generate(Assign_Value_Quadru *ir) {
		string code;
		if (ir->rhs[0] == '#') { // Immediate value
			code = compose({"li"s, reg(ir->lhs, true), imm(ir->rhs, false)});
		} else {
			code = compose({"move"s, reg(ir->lhs, true), reg(ir->rhs)});
		}

		emit(code);
	}

	void Code_Generator::generate(Arith_Quadru *ir) {
		string code;
		switch (ir->op) {
			case op_type::PLUS :
				if (ir->arg2[1] == '#') {
					code = compose({"addi"s, reg(ir->lhs, true), reg(ir->arg1), imm(ir->arg2)});
				} else {
					code = compose({"add"s, reg(ir->lhs, true), reg(ir->arg1), reg(ir->arg2)});
				}
				break;
			case op_type::MINUS:
				if (ir->arg2[0] == '#') {
					code = compose({"addi"s, reg(ir->lhs, true), reg(ir->arg1), imm(ir->arg2, true)});
				} else {
					code = compose({"sub"s, reg(ir->lhs, true), reg(ir->arg1), reg(ir->arg2)});
				}
				break;
			case op_type::MUL:
				code = compose({"mul"s, reg(ir->lhs, true), reg(ir->arg1), reg(ir->arg2)});
				break;
			case op_type::DIV:
				emit(compose({"div"s, reg(ir->arg1), reg(ir->arg2)}));
				emit(compose({"mflo"s, reg(ir->lhs, true)}));
				break;
			default:
				cerr << "No other op!" << endl;
		}

		emit(code);
	}

	void Code_Generator::generate(Goto_Quadru *ir) {
		string code = compose({"j"s, ir->label->to_string()});

		// store all first
//		store_all();
		emit(code);
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

		string code = compose({op_code, reg(ir->arg1), reg(ir->arg2), ir->label->to_string()});

		// store all first
//		store_all();
		emit(code);
	}

	void Code_Generator::generate(Return_Quadru *ir) {
		string store_return_code = compose({"move"s, "$v0"s, reg(ir->name)});

		// let $sp = $fp + 4, which make $sp to be previous $sp
		emit(compose({"addi", "$sp", "$fp", "4"}));

		// let $fp = -4($sp), i.e previous $fp
		emit(compose({"lw", "$fp", "-4($sp)"}));

		emit(store_return_code);

		emit(compose({"jr"s, "$ra"s}));
	}

	void Code_Generator::generate(Param_Quadru *ir) {
		// Store parameter into temperate register
		emit(compose({"move"s, reg(ir->name), "$a" + std::to_string(param_num++)}));
	}

	void Code_Generator::generate(Arg_Quadru *ir) {
		// Add arg_name into arg_list
		arg_list.push_back(reg(ir->name));
	}

	void Code_Generator::generate(Call_Quadru *ir) {

		// Convert arg_list into code
		arg_num = arg_list.size();
		for (auto &&reg_name: arg_list) {
			emit(compose({"move"s, "$a" + std::to_string(--arg_num), reg_name}));
		}
		arg_list.clear();

		vector<Register *> stored_registers;

		// Store used & not idle registers
		for (auto r: registers.get_usable()) {
			if (!r->idle) {
				stored_registers.push_back(r);
				increase_stack();
				emit(compose({"sw"s, r->name, "($sp)"s}));
			}
		}

		// Store $ra
		increase_stack();
		emit(compose({"sw", "$ra", "($sp)"}));

		// Call
		emit(compose({"jal"s, ir->func_name}));

		// Restore $ra
		emit(compose({"lw", "$ra", "($sp)"}));
		decrease_stack();

		// Restore other registers
		for (int i = (int) (stored_registers.size()) - 1; i >= 0; --i) {
			emit(compose({"lw"s, stored_registers[i]->name, "($sp)"s}));
			decrease_stack();
		}

		// Get returned value
		emit(compose({"move"s, reg(ir->lhs, true), "$v0"s}));

		// Init the arg_num
		arg_num = 0;

	}

	void Code_Generator::generate(Read_Quadru *ir) {
		// Store $ra
		increase_stack();
		emit(compose({"sw", "$ra", "($sp)"}));

		// Call
		emit(compose({"jal", "read"}));

		// Restore $ra
		emit(compose({"lw", "$ra", "($sp)"}));
		decrease_stack();

		// Get returned value
		emit(compose({"move"s, reg(ir->name), "$v0"s}));
	}

	void Code_Generator::generate(Write_Quadru *ir) {
		// Store arg into $a0
		emit(compose({"move"s, "$a0", reg(ir->name)}));

		// Store $ra
		increase_stack();
		emit(compose({"sw", "$ra", "($sp)"}));

		// Call
		emit(compose({"jal", "write"}));

		// Restore $ra
		emit(compose({"lw", "$ra", "($sp)"}));
		decrease_stack();

		// Get returned value
		emit(compose({"move"s, reg(ir->name), "$v0"s}));
	}

	string Code_Generator::reg(const string &name, bool check_dirty) {
		string reg_name = "Undefined";

		if (auto var = variables.get(name); var != nullptr) {
			// Found in variables

			if (var->reg != nullptr) {
				// Appear in the register

				if (check_dirty && var->in_stack) {
					// lhs value and variable in memory
					var->reg->dirty = true;
				}

				reg_name = var->reg->name;

				lru->touch(registers.get_reg(reg_name));
			} else if (var->in_stack) {
				// In the memory
				Register *temp = need_reg();

//				emit(compose({"lw"s, temp->name, offset_fmt(var->stack_offset, "$sp")}));
				emit(compose({"lw"s, temp->name, offset_fmt(-var->frame_offset, "$fp")}));

				var->reg = temp;
				temp->variable = var->name;

				if (check_dirty) {
					var->reg->dirty = true;
				}

				reg_name = temp->name;
			}
		} else {
			// Not found in variables
			auto *new_var = new Variable(name);
			variables.add(new_var);

			Register *temp = need_reg();

			if (name[0] == '#') {
				// Immediate value
				emit(compose({"li"s, temp->name, get_imm_value(name)}));
			}

			new_var->reg = temp;
			temp->variable = new_var->name;

			reg_name = temp->name;
		}

		return reg_name;
	}

	string Code_Generator::imm(const string &name, bool negative) {
		return (negative ? "-" : "") + get_imm_value(name);
	}

	void Code_Generator::emit(const string &code, bool indent) {
		if (!code.empty()) {
			instr.emplace_back((indent ? "    " : "") + code);
		}
	}

	/**
	 * Store the register into memory.
	 * @param reg
	 */
	void Code_Generator::save(Register *reg) {
		if (Variable *var = variables.get(reg->variable); var != nullptr) {
			if (var->in_stack && reg->dirty) {
//				emit(compose({"sw"s, reg->name, offset_fmt(var->stack_offset, "$sp")}));
				emit(compose({"sw"s, reg->name, offset_fmt(-var->frame_offset, "$fp")}));
			}
		} else {
			var = new Variable(reg->variable);

			increase_stack();
			emit(compose({"sw"s, reg->name, offset_fmt(0, "$sp")}));

			var->reg = reg;
			var->in_stack = true;
			var->frame_offset = frame_offset;
		}

		reg->dirty = false;
	}

	string Code_Generator::compose(initializer_list<string> seq) {
		vector<string> new_seq(seq.begin(), seq.end());

		// Add ',' between first and last element
		for (int i = 1, sz = seq.size(); i < sz - 1; ++i) {
			new_seq[i] += ",";
		}

		return join(new_seq.begin(), new_seq.end());
	}

	std::string Code_Generator::offset_fmt(int offset, const std::string &name) {
		return (offset != 0 ? std::to_string(offset) : "") + "(" + name + ")";
	}

	void Code_Generator::increase_stack(int units) {
		emit(compose({"addi"s, "$sp"s, "$sp"s, "-" + std::to_string(units)}));
		frame_offset += units;
	}

	void Code_Generator::decrease_stack(int units) {
		emit(compose({"addi"s, "$sp"s, "$sp"s, std::to_string(units)}));
		frame_offset -= units;
	}

	Register *Code_Generator::need_reg() {
		Register *reg = nullptr;
		if (reg = registers.get_idle(); reg != nullptr) {
			lru->touch(reg);
		} else {
			// Find a register to be spilled
			reg = lru->touch(nullptr);
			save(reg);
		}

		reg->idle = false;

		return reg;
	}

	std::string Code_Generator::get_imm_value(const std::string &name) {
		return name.substr(1, name.size() - 1);
	}

	Quadruple *string2tac(string line) {
		while (!line.empty() && (line[line.size() - 1] == '\r' || line[line.size() - 1] == '\n')) {
			line.erase(line.size() - 1);
		}

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
				cout << "can not be others!" << endl;
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

	Variable *Variable_Collection::get(const string &name) {
		Variable *result = nullptr;
		if (variable_table.find(name) != variable_table.end()) {
			result = variable_table[name];
		}

		return result;
	}

	void Variable_Collection::add(Variable *variable) {
		variable_table[variable->name] = variable;
	}

	void Variable_Collection::clear_reg(const std::string &name) {
		if (variable_table.find(name) != variable_table.end()) {
			variable_table[name]->reg = nullptr;
		}
	}

	void Variable_Collection::remove(const std::string &name) {
		variable_table.erase(name);
	}

	vector<Register *> Register_Collection::get_usable() {
		return vector<Register *>(registers.begin() + 8, registers.begin() + 24);
	}

	Register *Register_Collection::get_idle() {
		for (Register *r: get_usable()) {
			if (r->idle) {
				return r;
			}
		}

		return nullptr;
	}

	Register *Register_Collection::get_reg(const string &reg_name) {
		for (Register *r: registers) {
			if (r->name == reg_name) {
				return r;
			}
		}

		cerr << "No register named " << reg_name << endl;
		return nullptr;
	}

	bool Register::is_imm() {
		return variable[0] == '#';
	}
}

