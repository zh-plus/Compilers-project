//
// Created by 10578 on 10/9/2019.
//

#include "ast.hpp"
#include "visitor.hpp"
#include "symbol.hpp"

namespace SPL {

	std::string Args_Node::to_string() {
		return "Args (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> Args_Node::children() {
		if (comma && args) {
			return std::vector<AST_Node *>{exp, comma, args};
		} else {
			return std::vector<AST_Node *>{exp};
		}
	}

	void Args_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string Leaf_Node::to_string() {
		switch (leaf_type) {
			case token::INT:
				return symbol_map[leaf_type] + ": " + std::to_string(std::get<unsigned int>(value));
			case token::FLOAT:
				return symbol_map[leaf_type] + ": " + std::to_string(std::get<float>(value));
			case token::CHAR:
			case token::TYPE:
			case token::ID:
				return symbol_map[leaf_type] + ": " + info->lexeme;
			default:
				return symbol_map[leaf_type];
		}
	}

	std::vector<AST_Node *> Leaf_Node::children() {
		return std::vector<AST_Node *>();
	}

	Leaf_Node::Leaf_Node(token_type leaf_type, Scan_Info *info) : leaf_type{leaf_type}, info{info} {
		std::string lexeme = this->info->lexeme;
		line_no = this->info->line_no;

		switch (this->leaf_type) {
			case token::INT:
//                std::cout << "lexeme: " << lexeme << std::endl;
				value = (unsigned int) std::stoul(lexeme, nullptr, 0);
				break;
			case token::FLOAT:
				value = std::stof(lexeme, nullptr);
				break;
			case token::CHAR:
				value = trim(lexeme, "'").c_str()[0];
				break;
			default:
				break;
		}
	}

	bool Leaf_Node::is_leaf() {
		return true;
	}

	void Leaf_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string Leaf_Node::get_lexeme() {
		return info->lexeme;
	}

	std::vector<AST_Node *> Unary_Exp_Node::children() {
		return std::vector<AST_Node *>{this->op_node, this->node};
	}

	void Unary_Exp_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> Binary_Exp_Node::children() {
		return std::vector<AST_Node *>{this->left, this->op_node, this->right};
	}

	void Binary_Exp_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	Leaf_Node *make_leaf(token_type leaf_type, Scan_Info *info) {
		return new Leaf_Node(leaf_type, info);
	}

	Leaf_Node *make_leaf(token_type leaf_type, std::string lexeme, int line_no) {
		return new Leaf_Node(leaf_type, new Scan_Info(lexeme, line_no));
	}

	void print_ast(AST_Node *node, int indent_level) {
		if (node->is_empty()) {
			return;
		}

		std::cout << std::string(2 * indent_level, ' ') // Indent format
		          << node->to_string() << std::endl;

		for (auto &child: node->children()) {
			print_ast(child, indent_level + 1);
		}
	}

	std::string Exp_Node::to_string() {
		return "Exp (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> Parentheses_Exp_Node::children() {
		return std::vector<AST_Node *>{this->lp, this->exp, this->rp};
	}

	void Parentheses_Exp_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> ID_Parentheses_Exp_Node::children() {
		if (args != nullptr) {
			return std::vector<AST_Node *>{id, lp, args, rp};
		} else {
			return std::vector<AST_Node *>{id, lp, rp};
		}
	}

	void ID_Parentheses_Exp_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> Bracket_Exp_Node::children() {
		return std::vector<AST_Node *>{this->exp1, this->lb, this->exp2, this->rb};
	}

	void Bracket_Exp_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> Dot_Exp_Node::children() {
		return std::vector<AST_Node *>{this->exp, this->dot, this->id};
	}

	void Dot_Exp_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> Leaf_Exp_Node::children() {
		return std::vector<AST_Node *>{this->leaf};
	}

	void Leaf_Exp_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string DefList_Node::to_string() {
		return "DefList (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> DefList_Node::children() {
		return std::vector<AST_Node *>{this->def, this->def_list};
	}

	void DefList_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> Empty_DefList_Node::children() {
		return std::vector<AST_Node *>();
	}

	std::string Empty_DefList_Node::to_string() {
		return "";
	}

	void Empty_DefList_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> Def_Node::children() {
		return std::vector<AST_Node *>{this->specifier, this->dec_list, this->semi};
	}

	std::string Def_Node::to_string() {
		return "Def (" + std::to_string(line_no) + ")";
	}

	void Def_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string DecList_Node::to_string() {
		return "DecList (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> DecList_Node::children() {
		if (comma && dec_list) {
			return std::vector<AST_Node *>{this->dec, comma, dec_list};
		} else {
			return std::vector<AST_Node *>{this->dec};
		}
	}

	void DecList_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string Empty_DecList_Node::to_string() {
		return "";
	}

	std::vector<AST_Node *> Empty_DecList_Node::children() {
		return std::vector<AST_Node *>();
	}

	void Empty_DecList_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string Dec_Node::to_string() {
		return "Dec (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> Dec_Node::children() {
		if (assign && exp) {
			return std::vector<AST_Node *>{var_dec, assign, exp};
		} else {
			return std::vector<AST_Node *>{var_dec};
		}
	}

	void Dec_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string CompSt_Node::to_string() {
		return "CompSt (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> CompSt_Node::children() {
		return std::vector<AST_Node *>{lc, def_list, stmt_list, rc};
	}

	void CompSt_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string Empty_StmtList_Node::to_string() {
		return "";
	}

	std::vector<AST_Node *> Empty_StmtList_Node::children() {
		return std::vector<AST_Node *>();
	}

	void Empty_StmtList_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string StmtList_Node::to_string() {
		return "StmtList (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> StmtList_Node::children() {
		return std::vector<AST_Node *>{stmt, stmt_list};
	}

	void StmtList_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string Stmt_Node::to_string() {
		return "Stmt (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> Exp_Stmt_Node::children() {
		return std::vector<AST_Node *>{exp, semi};
	}

	void Exp_Stmt_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> CompSt_Stmt_Node::children() {
		return std::vector<AST_Node *>{comp_st};
	}

	void CompSt_Stmt_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> Return_Stmt_Node::children() {
		return std::vector<AST_Node *>{ret, exp, semi};
	}

	void Return_Stmt_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> If_Stmt_Node::children() {
		if (_else && stmt_else) {
			return std::vector<AST_Node *>{_if, lp, exp, rp, stmt_if, _else, stmt_else};
		} else {
			return std::vector<AST_Node *>{_if, lp, exp, rp, stmt_if};
		}

	}

	void If_Stmt_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> While_Stmt_Node::children() {
		return std::vector<AST_Node *>{_while, lp, exp, rp, stmt};
	}

	void While_Stmt_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string VarDec_Node::to_string() {
		return "VarDec (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> ID_VarDec_Node::children() {
		return std::vector<AST_Node *>{id};
	}

	void ID_VarDec_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> Array_VarDec_Node::children() {
		return std::vector<AST_Node *>{var_dec, lb, _int, rb};
	}

	void Array_VarDec_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string FunDec_Node::to_string() {
		return "FunDec (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> FunDec_Node::children() {
		if (var_list) {
			return std::vector<AST_Node *>{id, lp, var_list, rp};
		} else {
			return std::vector<AST_Node *>{id, lp, rp};
		}

	}

	void FunDec_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string VarList_Node::to_string() {
		return "VarList (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> VarList_Node::children() {
		if (comma && var_list) {
			return std::vector<AST_Node *>{param_dec, comma, var_list};
		} else {
			return std::vector<AST_Node *>{param_dec};
		}
	}

	void VarList_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string ParamDec_Node::to_string() {
		return "ParamDec (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> ParamDec_Node::children() {
		return std::vector<AST_Node *>{specifier, var_dec};
	}

	void ParamDec_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string Specifier_Node::to_string() {
		return "Specifier (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> Specifier_Node::children() {
		if (type) {
			return std::vector<AST_Node *>{type};
		} else {
			return std::vector<AST_Node *>{struct_specifier};
		}
	}

	void Specifier_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::vector<AST_Node *> StructSpecifier_Node::children() {
		if (lc && def_list && rc) {
			return std::vector<AST_Node *>{_struct, id, lc, def_list, rc};
		} else {
			return std::vector<AST_Node *>{_struct, id};
		}
	}

	std::string StructSpecifier_Node::to_string() {
		return "StructSpecifier (" + std::to_string(line_no) + ")";
	}

	void StructSpecifier_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string Program_Node::to_string() {
		return "Program (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> Program_Node::children() {
		return std::vector<AST_Node *>{ext_def_list};
	}

	void Program_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string ExtDefList_Node::to_string() {
		return "ExtDefList (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> ExtDefList_Node::children() {
		return std::vector<AST_Node *>{ext_def, ext_def_list};
	}

	void ExtDefList_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string Empty_ExtDefList_Node::to_string() {
		return "";
	}

	std::vector<AST_Node *> Empty_ExtDefList_Node::children() {
		return std::vector<AST_Node *>{};
	}

	void Empty_ExtDefList_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string ExtDef_Node::to_string() {
		return "ExtDef (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> ExtDef_Node::children() {
		if (ext_dec_list) {
			return std::vector<AST_Node *>{specifier, ext_dec_list, semi};
		} else if (fun_dec && comp_st) {
			return std::vector<AST_Node *>{specifier, fun_dec, comp_st};
		} else {
			return std::vector<AST_Node *>{specifier, semi};
		}
	}

	void ExtDef_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	std::string ExtDecList_Node::to_string() {
		return "ExtDecList (" + std::to_string(line_no) + ")";
	}

	std::vector<AST_Node *> ExtDecList_Node::children() {
		if (comma && ext_dec_list) {
			return std::vector<AST_Node *>{var_dec, comma, ext_dec_list};
		} else {
			return std::vector<AST_Node *>{var_dec};
		}
	}

	void ExtDecList_Node::accept(Visitor *visitor) {
		visitor->visit(this);
	}

	int AST_Node::propagate_line_no() {
		if (is_leaf() || is_empty() || line_no != INT32_MAX) {
			return line_no;
		}

		for (const auto &child: children()) {
			line_no = std::min(line_no, child->propagate_line_no());
		}

		return line_no;
	}

	bool AST_Node::is_leaf() {
		return false;
	}

	bool AST_Node::is_empty() {
		return to_string().empty();
	}

	std::vector<AST_Node *> AST_Node::children() {
		return std::vector<AST_Node *>();
	}

	void AST::print() {
		print_ast(program, 0);
	}
}