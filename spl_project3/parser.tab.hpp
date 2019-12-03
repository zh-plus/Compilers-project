// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/**
 ** \file /mnt/e/C++/compiler/compilers/spl_project3/parser.tab.hpp
 ** Define the SPL::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_MNT_E_C_COMPILER_COMPILERS_SPL_PROJECT3_PARSER_TAB_HPP_INCLUDED
# define YY_YY_MNT_E_C_COMPILER_COMPILERS_SPL_PROJECT3_PARSER_TAB_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 8 "parser.y" // lalr1.cc:377

namespace SPL {
	class Scan_Info;

	class SPL_Driver;

	class SPL_Scanner;

	class AST_Node;

	class Leaf_Node;

	class Program_Node;

	class ExtDefList_Node;

	class ExtDef_Node;

	class ExtDecList_Node;

	class Specifier_Node;

	class StructSpecifier_Node;

	class VarDec_Node;

	class FunDec_Node;

	class VarList_Node;

	class ParamDec_Node;

	class CompSt_Node;

	class StmtList_Node;

	class Stmt_Node;

	class DefList_Node;

	class Def_Node;

	class DecList_Node;

	class Dec_Node;

	class Exp_Node;

	class Args_Node;
}


#line 75 "/mnt/e/C++/compiler/compilers/spl_project3/parser.tab.hpp" // lalr1.cc:377

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"
# include "location.hh"
#include <typeinfo>

#ifndef YYASSERT

# include <cassert>

# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
 || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if !defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 5 "parser.y" // lalr1.cc:377
namespace SPL {
#line 152 "/mnt/e/C++/compiler/compilers/spl_project3/parser.tab.hpp" // lalr1.cc:377


	/// A char[S] buffer to store and retrieve objects.
	///
	/// Sort of a variant, but does not keep track of the nature
	/// of the stored data, since that knowledge is available
	/// via the current state.
	template<size_t S>
	struct variant {
		/// Type of *this.
		typedef variant<S> self_type;

		/// Empty construction.
		variant()
				: yytypeid_(YY_NULLPTR) {}

		/// Construct and fill.
		template<typename T>
		variant(const T &t)
				: yytypeid_(&typeid(T)) {
					YYASSERT (sizeof(T) <= S);
			new(yyas_<T>()) T(t);
		}

		/// Destruction, allowed only if empty.
		~variant() {
					YYASSERT (!yytypeid_);
		}

		/// Instantiate an empty \a T in here.
		template<typename T>
		T &
		build() {
					YYASSERT (!yytypeid_);
					YYASSERT (sizeof(T) <= S);
			yytypeid_ = &typeid(T);
			return *new(yyas_<T>()) T;
		}

		/// Instantiate a \a T in here from \a t.
		template<typename T>
		T &
		build(const T &t) {
					YYASSERT (!yytypeid_);
					YYASSERT (sizeof(T) <= S);
			yytypeid_ = &typeid(T);
			return *new(yyas_<T>()) T(t);
		}

		/// Accessor to a built \a T.
		template<typename T>
		T &
		as() {
					YYASSERT (*yytypeid_ == typeid(T));
					YYASSERT (sizeof(T) <= S);
			return *yyas_<T>();
		}

		/// Const accessor to a built \a T (for %printer).
		template<typename T>
		const T &
		as() const {
					YYASSERT (*yytypeid_ == typeid(T));
					YYASSERT (sizeof(T) <= S);
			return *yyas_<T>();
		}

		/// Swap the content with \a other, of same type.
		///
		/// Both variants must be built beforehand, because swapping the actual
		/// data requires reading it (with as()), and this is not possible on
		/// unconstructed variants: it would require some dynamic testing, which
		/// should not be the variant's responsability.
		/// Swapping between built and (possibly) non-built is done with
		/// variant::move ().
		template<typename T>
		void
		swap(self_type &other) {
					YYASSERT (yytypeid_);
					YYASSERT (*yytypeid_ == *other.yytypeid_);
			std::swap(as<T>(), other.as<T>());
		}

		/// Move the content of \a other to this.
		///
		/// Destroys \a other.
		template<typename T>
		void
		move(self_type &other) {
			build<T>();
			swap<T>(other);
			other.destroy<T>();
		}

		/// Copy the content of \a other to this.
		template<typename T>
		void
		copy(const self_type &other) {
			build<T>(other.as<T>());
		}

		/// Destroy the stored \a T.
		template<typename T>
		void
		destroy() {
			as<T>().~T();
			yytypeid_ = YY_NULLPTR;
		}

	private:
		/// Prohibit blind copies.
		self_type &operator=(const self_type &);

		variant(const self_type &);

		/// Accessor to raw memory as \a T.
		template<typename T>
		T *
		yyas_() {
			void *yyp = yybuffer_.yyraw;
			return static_cast<T *> (yyp);
		}

		/// Const accessor to raw memory as \a T.
		template<typename T>
		const T *
		yyas_() const {
			const void *yyp = yybuffer_.yyraw;
			return static_cast<const T *> (yyp);
		}

		union {
			/// Strongest alignment constraints.
			long double yyalign_me;
			/// A buffer large enough to store any of the semantic values.
			char yyraw[S];
		} yybuffer_;

		/// Whether the content is built: if defined, the name of the stored type.
		const std::type_info *yytypeid_;
	};


	/// A Bison parser.
	class SPL_Parser {
	public:
#ifndef YYSTYPE
		/// An auxiliary type to compute the largest semantic type.
		union union_type {
			// Args
			char dummy1[sizeof(Args_Node *)];

			// CompSt
			char dummy2[sizeof(CompSt_Node *)];

			// DecList
			char dummy3[sizeof(DecList_Node *)];

			// Dec
			char dummy4[sizeof(Dec_Node *)];

			// DefList
			char dummy5[sizeof(DefList_Node *)];

			// Def
			char dummy6[sizeof(Def_Node *)];

			// Exp
			char dummy7[sizeof(Exp_Node *)];

			// ExtDecList
			char dummy8[sizeof(ExtDecList_Node *)];

			// ExtDefList
			char dummy9[sizeof(ExtDefList_Node *)];

			// ExtDef
			char dummy10[sizeof(ExtDef_Node *)];

			// FunDec
			char dummy11[sizeof(FunDec_Node *)];

			// ParamDec
			char dummy12[sizeof(ParamDec_Node *)];

			// Program
			char dummy13[sizeof(Program_Node *)];

			// INT
			// FLOAT
			// CHAR
			// TYPE
			// ID
			// STRUCT
			// IF
			// ELSE
			// WHILE
			// RETURN
			// ASSIGN
			// DOT
			// SEMI
			// COMMA
			// EQ
			// LE
			// LT
			// GE
			// GT
			// NE
			// PLUS
			// MINUS
			// MUL
			// DIV
			// AND
			// OR
			// NOT
			// LP
			// RP
			// LC
			// RC
			// LB
			// RB
			// LINE_COMMENT
			// ERROR
			char dummy14[sizeof(Scan_Info *)];

			// Specifier
			char dummy15[sizeof(Specifier_Node *)];

			// StmtList
			char dummy16[sizeof(StmtList_Node *)];

			// Stmt
			char dummy17[sizeof(Stmt_Node *)];

			// StructSpecifier
			char dummy18[sizeof(StructSpecifier_Node *)];

			// VarDec
			char dummy19[sizeof(VarDec_Node *)];

			// VarList
			char dummy20[sizeof(VarList_Node *)];
		};

		/// Symbol semantic values.
		typedef variant<sizeof(union_type)> semantic_type;
#else
		typedef YYSTYPE semantic_type;
#endif
		/// Symbol locations.
		typedef location location_type;

		/// Syntax errors thrown from user actions.
		struct syntax_error : std::runtime_error {
			syntax_error(const location_type &l, const std::string &m);

			location_type location;
		};

		/// Tokens.
		struct token {
			enum yytokentype {
				END = 0,
				INT = 258,
				FLOAT = 259,
				CHAR = 260,
				TYPE = 261,
				ID = 262,
				STRUCT = 263,
				IF = 264,
				ELSE = 265,
				WHILE = 266,
				RETURN = 267,
				ASSIGN = 268,
				DOT = 269,
				SEMI = 270,
				COMMA = 271,
				EQ = 272,
				LE = 273,
				LT = 274,
				GE = 275,
				GT = 276,
				NE = 277,
				PLUS = 278,
				MINUS = 279,
				MUL = 280,
				DIV = 281,
				AND = 282,
				OR = 283,
				NOT = 284,
				LP = 285,
				RP = 286,
				LC = 287,
				RC = 288,
				LB = 289,
				RB = 290,
				LINE_COMMENT = 291,
				ERROR = 292,
				SUB = 293
			};
		};

		/// (External) token type, as returned by yylex.
		typedef token::yytokentype token_type;

		/// Symbol type: an internal symbol number.
		typedef int symbol_number_type;

		/// The symbol type number to denote an empty symbol.
		enum {
			empty_symbol = -2
		};

		/// Internal symbol number for tokens (subsumed by symbol_number_type).
		typedef unsigned char token_number_type;

		/// A complete symbol.
		///
		/// Expects its Base type to provide access to the symbol type
		/// via type_get().
		///
		/// Provide access to semantic value and location.
		template<typename Base>
		struct basic_symbol : Base {
			/// Alias to Base.
			typedef Base super_type;

			/// Default constructor.
			basic_symbol();

			/// Copy constructor.
			basic_symbol(const basic_symbol &other);

			/// Constructor for valueless symbols, and symbols from each type.

			basic_symbol(typename Base::kind_type t, const location_type &l);

			basic_symbol(typename Base::kind_type t, const Args_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const CompSt_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const DecList_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const Dec_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const DefList_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const Def_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const Exp_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const ExtDecList_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const ExtDefList_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const ExtDef_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const FunDec_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const ParamDec_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const Program_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const Scan_Info *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const Specifier_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const StmtList_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const Stmt_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const StructSpecifier_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const VarDec_Node *v, const location_type &l);

			basic_symbol(typename Base::kind_type t, const VarList_Node *v, const location_type &l);


			/// Constructor for symbols with semantic value.
			basic_symbol(typename Base::kind_type t,
			             const semantic_type &v,
			             const location_type &l);

			/// Destroy the symbol.
			~basic_symbol();

			/// Destroy contents, and record that is empty.
			void clear();

			/// Whether empty.
			bool empty() const;

			/// Destructive move, \a s is emptied into this.
			void move(basic_symbol &s);

			/// The semantic value.
			semantic_type value;

			/// The location.
			location_type location;

		private:
			/// Assignment operator.
			basic_symbol &operator=(const basic_symbol &other);
		};

		/// Type access provider for token (enum) based symbols.
		struct by_type {
			/// Default constructor.
			by_type();

			/// Copy constructor.
			by_type(const by_type &other);

			/// The symbol type as needed by the constructor.
			typedef token_type kind_type;

			/// Constructor from (external) token numbers.
			by_type(kind_type t);

			/// Record that this symbol is empty.
			void clear();

			/// Steal the symbol type from \a that.
			void move(by_type &that);

			/// The (internal) type number (corresponding to \a type).
			/// \a empty when empty.
			symbol_number_type type_get() const;

			/// The token.
			token_type token() const;

			/// The symbol type.
			/// \a empty_symbol when empty.
			/// An int, not token_number_type, to be able to store empty_symbol.
			int type;
		};

		/// "External" symbols: returned by the scanner.
		typedef basic_symbol<by_type> symbol_type;

		// Symbol constructors declarations.
		static inline
		symbol_type
		make_END(const location_type &l);

		static inline
		symbol_type
		make_INT(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_FLOAT(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_CHAR(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_TYPE(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_ID(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_STRUCT(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_IF(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_ELSE(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_WHILE(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_RETURN(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_ASSIGN(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_DOT(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_SEMI(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_COMMA(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_EQ(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_LE(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_LT(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_GE(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_GT(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_NE(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_PLUS(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_MINUS(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_MUL(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_DIV(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_AND(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_OR(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_NOT(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_LP(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_RP(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_LC(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_RC(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_LB(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_RB(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_LINE_COMMENT(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_ERROR(const Scan_Info *&v, const location_type &l);

		static inline
		symbol_type
		make_SUB(const location_type &l);


		/// Build a parser object.
		SPL_Parser(SPL_Scanner &scanner_yyarg, SPL_Driver &driver_yyarg);

		virtual ~SPL_Parser();

		/// Parse.
		/// \returns  0 iff parsing succeeded.
		virtual int parse();

#if YYDEBUG

		/// The current debugging stream.
		std::ostream &debug_stream() const YY_ATTRIBUTE_PURE;

		/// Set the current debugging stream.
		void set_debug_stream(std::ostream &);

		/// Type for debugging levels.
		typedef int debug_level_type;

		/// The current debugging level.
		debug_level_type debug_level() const YY_ATTRIBUTE_PURE;

		/// Set the current debugging level.
		void set_debug_level(debug_level_type l);

#endif

		/// Report a syntax error.
		/// \param loc    where the syntax error is found.
		/// \param msg    a description of the syntax error.
		virtual void error(const location_type &loc, const std::string &msg);

		/// Report a syntax error.
		void error(const syntax_error &err);

	private:
		/// This class is not copyable.
		SPL_Parser(const SPL_Parser &);

		SPL_Parser &operator=(const SPL_Parser &);

		/// State numbers.
		typedef int state_type;

		/// Generate an error message.
		/// \param yystate   the state where the error occurred.
		/// \param yyla      the lookahead token.
		virtual std::string yysyntax_error_(state_type yystate,
		                                    const symbol_type &yyla) const;

		/// Compute post-reduction state.
		/// \param yystate   the current state
		/// \param yysym     the nonterminal to push on the stack
		state_type yy_lr_goto_state_(state_type yystate, int yysym);

		/// Whether the given \c yypact_ value indicates a defaulted state.
		/// \param yyvalue   the value to check
		static bool yy_pact_value_is_default_(int yyvalue);

		/// Whether the given \c yytable_ value indicates a syntax error.
		/// \param yyvalue   the value to check
		static bool yy_table_value_is_error_(int yyvalue);

		static const signed char yypact_ninf_;
		static const signed char yytable_ninf_;

		/// Convert a scanner token number \a t to a symbol number.
		static token_number_type yytranslate_(int t);

		// Tables.
		// YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
		// STATE-NUM.
		static const short int yypact_[];

		// YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
		// Performed when YYTABLE does not specify something else to do.  Zero
		// means the default is an error.
		static const unsigned char yydefact_[];

		// YYPGOTO[NTERM-NUM].
		static const short int yypgoto_[];

		// YYDEFGOTO[NTERM-NUM].
		static const signed char yydefgoto_[];

		// YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
		// positive, shift that token.  If negative, reduce the rule whose
		// number is the opposite.  If YYTABLE_NINF, syntax error.
		static const short int yytable_[];

		static const short int yycheck_[];

		// YYSTOS[STATE-NUM] -- The (internal number of the) accessing
		// symbol of state STATE-NUM.
		static const unsigned char yystos_[];

		// YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
		static const unsigned char yyr1_[];

		// YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
		static const unsigned char yyr2_[];


#if YYDEBUG
		/// For a symbol, its name in clear.
		static const char *const yytname_[];

		// YYRLINE[YYN] -- Source line where rule number YYN was defined.
		static const unsigned short int yyrline_[];

		/// Report on the debug stream that the rule \a r is going to be reduced.
		virtual void yy_reduce_print_(int r);

		/// Print the state stack on the debug stream.
		virtual void yystack_print_();

		// Debugging.
		int yydebug_;
		std::ostream *yycdebug_;

		/// \brief Display a symbol type, value and location.
		/// \param yyo    The output stream.
		/// \param yysym  The symbol.
		template<typename Base>
		void yy_print_(std::ostream &yyo, const basic_symbol<Base> &yysym) const;

#endif

		/// \brief Reclaim the memory associated to a symbol.
		/// \param yymsg     Why this token is reclaimed.
		///                  If null, print nothing.
		/// \param yysym     The symbol.
		template<typename Base>
		void yy_destroy_(const char *yymsg, basic_symbol<Base> &yysym) const;

	private:
		/// Type access provider for state based symbols.
		struct by_state {
			/// Default constructor.
			by_state();

			/// The symbol type as needed by the constructor.
			typedef state_type kind_type;

			/// Constructor.
			by_state(kind_type s);

			/// Copy constructor.
			by_state(const by_state &other);

			/// Record that this symbol is empty.
			void clear();

			/// Steal the symbol type from \a that.
			void move(by_state &that);

			/// The (internal) type number (corresponding to \a state).
			/// \a empty_symbol when empty.
			symbol_number_type type_get() const;

			/// The state number used to denote an empty symbol.
			enum {
				empty_state = -1
			};

			/// The state.
			/// \a empty when empty.
			state_type state;
		};

		/// "Internal" symbol: element of the stack.
		struct stack_symbol_type : basic_symbol<by_state> {
			/// Superclass.
			typedef basic_symbol<by_state> super_type;

			/// Construct an empty symbol.
			stack_symbol_type();

			/// Steal the contents from \a sym to build this.
			stack_symbol_type(state_type s, symbol_type &sym);

			/// Assignment, needed by push_back.
			stack_symbol_type &operator=(const stack_symbol_type &that);
		};

		/// Stack type.
		typedef stack<stack_symbol_type> stack_type;

		/// The stack.
		stack_type yystack_;

		/// Push a new state on the stack.
		/// \param m    a debug message to display
		///             if null, no trace is output.
		/// \param s    the symbol
		/// \warning the contents of \a s.value is stolen.
		void yypush_(const char *m, stack_symbol_type &s);

		/// Push a new look ahead token on the state on the stack.
		/// \param m    a debug message to display
		///             if null, no trace is output.
		/// \param s    the state
		/// \param sym  the symbol (for its value and location).
		/// \warning the contents of \a s.value is stolen.
		void yypush_(const char *m, state_type s, symbol_type &sym);

		/// Pop \a n symbols the three stacks.
		void yypop_(unsigned int n = 1);

		/// Constants.
		enum {
			yyeof_ = 0,
			yylast_ = 461,     ///< Last index in yytable_.
			yynnts_ = 20,  ///< Number of nonterminal symbols.
			yyfinal_ = 9, ///< Termination state number.
			yyterror_ = 1,
			yyerrcode_ = 256,
			yyntokens_ = 39  ///< Number of tokens.
		};


		// User arguments.
		SPL_Scanner &scanner;
		SPL_Driver &driver;
	};


#line 5 "parser.y" // lalr1.cc:377
} // SPL
#line 982 "/mnt/e/C++/compiler/compilers/spl_project3/parser.tab.hpp" // lalr1.cc:377


#endif // !YY_YY_MNT_E_C_COMPILER_COMPILERS_SPL_PROJECT3_PARSER_TAB_HPP_INCLUDED
