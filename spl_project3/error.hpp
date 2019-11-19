//
// Created by 10578 on 2019/11/16.
//

#ifndef __ERROR_HPP__
#define __ERROR_HPP__

#include "scanner.hpp"
#include "information.hpp"

namespace SPL {
	/* Forward definition */
	class Scan_Info;

	class Error {
	public:
		int line_no;

		virtual std::string to_string() = 0;

		bool operator<(const Error &obj);
	};

	class Lexical_Error : public Error {
	public:
		explicit Lexical_Error(Scan_Info *info);

		std::string to_string() override;

		Scan_Info *info{};
	};

	class Syntax_Error : public Error {
	public:
		std::unordered_map<std::string, std::string> punctuation_map{
				{";", "semicolon"},
				{",", "comma"},
				{")", "closing parenthesis"},
				{"]", "closing bracket"},
				{"}", "closing curly bracket"},
		};

		explicit Syntax_Error(Scan_Info *info);

		Syntax_Error(std::string lexeme, int line_no);

		std::string to_string() override;

		Scan_Info *info{};
	};

	class Semantic_Error : public Error {
	public:
		virtual std::string get_message() = 0;

		std::string to_string() override;

		int error_type = -1;
	};

	class Semantic_Error1 : public Semantic_Error {
	public:
		Semantic_Error1(int error_line, std::string variable_id) {
			this->error_type = 1;
			this->line_no = error_line;
			this->variable_id = variable_id;
		};

		std::string get_message() override;

	private:
		std::string variable_id;

	};


	class Semantic_Error2 : public Semantic_Error {
	public:
		Semantic_Error2(int error_line, std::string func_id) {
			this->error_type = 2;
			this->line_no = error_line;
			this->func_id = func_id;
		};

		std::string get_message() override;

	private:
		std::string func_id;

	};

	class Semantic_Error3 : public Semantic_Error {
	public:
		Semantic_Error3(int error_line, int defined_line, std::string variable_id) {
			this->error_type = 3;
			this->line_no = error_line;
			this->defined_line = defined_line;
			this->variable_id = variable_id;
		};

		std::string get_message() override;

	private:
		int defined_line;

		std::string variable_id;
	};

	class Semantic_Error4 : public Semantic_Error {
	public:
		Semantic_Error4(int error_line, int defined_line, std::string func_id) {
			this->error_type = 4;
			this->line_no = error_line;
			this->defined_line = defined_line;
			this->func_id = func_id;
		};

		std::string get_message() override;

	private:
		int defined_line;

		std::string func_id;
	};

	class Semantic_Error5 : public Semantic_Error {
	public:
		Semantic_Error5(int error_line) {
			this->error_type = 5;
			this->line_no = error_line;
		};

		std::string get_message() override;
	};

	class Semantic_Error6 : public Semantic_Error {
	public:
		explicit Semantic_Error6(int error_line) {
			this->error_type = 6;
			this->line_no = error_line;
		};

		std::string get_message() override;
	};

	class Semantic_Error7 : public Semantic_Error {
	public:
		explicit Semantic_Error7(int error_line) {
			this->error_type = 7;
			this->line_no = error_line;
		};

		std::string get_message() override;
	};

	class Semantic_Error8 : public Semantic_Error {
	public:
		explicit Semantic_Error8(int error_line) {
			this->error_type = 8;
			this->line_no = error_line;
		};

		std::string get_message() override;
	};

	class Semantic_Error9 : public Semantic_Error {
	public:
		explicit Semantic_Error9(int error_line) {
			this->error_type = 9;
			this->line_no = error_line;
		};

		std::string get_message() override;
	};

	class Semantic_Error10 : public Semantic_Error {
	public:
		explicit Semantic_Error10(int error_line) {
			this->error_type = 10;
			this->line_no = error_line;
		};

		std::string get_message() override;
	};

	class Semantic_Error11 : public Semantic_Error {
	public:
		explicit Semantic_Error11(int error_line) {
			this->error_type = 11;
			this->line_no = error_line;
		};

		std::string get_message() override;
	};

	class Semantic_Error12 : public Semantic_Error {
	public:
		explicit Semantic_Error12(int error_line) {
			this->error_type = 12;
			this->line_no = error_line;
		};

		std::string get_message() override;
	};

	class Semantic_Error13 : public Semantic_Error {
	public:
		explicit Semantic_Error13(int error_line) {
			this->error_type = 13;
			this->line_no = error_line;
		};

		std::string get_message() override;
	};

	class Semantic_Error14 : public Semantic_Error {
	public:
		explicit Semantic_Error14(int error_line) {
			this->error_type = 14;
			this->line_no = error_line;
		};

		std::string get_message() override;
	};

	class Semantic_Error15 : public Semantic_Error {
	public:
		explicit Semantic_Error15(int error_line, int defined_line, std::string struct_id) {
			this->error_type = 15;
			this->line_no = error_line;
			this->defined_line = defined_line;
			this->struct_id = struct_id;
		};

		std::string get_message() override;

	public:
		int defined_line;
		std::string struct_id;
	};

	class Semantic_Error16 : public Semantic_Error {
	public:
		explicit Semantic_Error16(int error_line, std::string struct_id) {
			this->error_type = 16;
			this->line_no = error_line;
			this->struct_id = struct_id;
		};

		std::string get_message() override;

	public:
		std::string struct_id;
	};

	class Semantic_Error17 : public Semantic_Error {
	public:
		explicit Semantic_Error17(int error_line, std::string struct_id) {
			this->error_type = 17;
			this->line_no = error_line;
			this->struct_id = struct_id;
		};

		std::string get_message() override;

	public:
		std::string struct_id;
	};
}

#endif //__ERROR_HPP__
