// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

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


// First part of user declarations.

#line 37 "parser.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.hpp"

// User implementation prologue.

#line 51 "parser.tab.cpp" // lalr1.cc:412
// Unqualified %code blocks.
#line 42 "parser.y" // lalr1.cc:413

    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    #include <string>

    /* include for all driver functions */
    #include "spl_driver.hpp"

    /* include for all AST functions */
    #include "ast.hpp"

#undef yylex
#define yylex scanner.yylex


#line 70 "parser.tab.cpp" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.y" // lalr1.cc:479
namespace SPL {
#line 156 "parser.tab.cpp" // lalr1.cc:479

  /// Build a parser object.
  SPL_Parser::SPL_Parser (SPL_Scanner  &scanner_yyarg, SPL_Driver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  SPL_Parser::~SPL_Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  SPL_Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  SPL_Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  SPL_Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 59: // Args
        value.copy< Args_Node * > (other.value);
        break;

      case 51: // CompSt
        value.copy< CompSt_Node * > (other.value);
        break;

      case 56: // DecList
        value.copy< DecList_Node * > (other.value);
        break;

      case 57: // Dec
        value.copy< Dec_Node * > (other.value);
        break;

      case 54: // DefList
        value.copy< DefList_Node * > (other.value);
        break;

      case 55: // Def
        value.copy< Def_Node * > (other.value);
        break;

      case 58: // Exp
        value.copy< Exp_Node * > (other.value);
        break;

      case 44: // ExtDecList
        value.copy< ExtDecList_Node * > (other.value);
        break;

      case 42: // ExtDefList
        value.copy< ExtDefList_Node * > (other.value);
        break;

      case 43: // ExtDef
        value.copy< ExtDef_Node * > (other.value);
        break;

      case 48: // FunDec
        value.copy< FunDec_Node * > (other.value);
        break;

      case 50: // ParamDec
        value.copy< ParamDec_Node * > (other.value);
        break;

      case 41: // Program
        value.copy< Program_Node * > (other.value);
        break;

      case 3: // INT
      case 4: // FLOAT
      case 5: // CHAR
      case 6: // TYPE
      case 7: // ID
      case 8: // STRUCT
      case 9: // IF
      case 10: // ELSE
      case 11: // WHILE
      case 12: // RETURN
      case 13: // ASSIGN
      case 14: // DOT
      case 15: // SEMI
      case 16: // COMMA
      case 17: // EQ
      case 18: // LE
      case 19: // LT
      case 20: // GE
      case 21: // GT
      case 22: // NE
      case 23: // PLUS
      case 24: // MINUS
      case 25: // MUL
      case 26: // DIV
      case 27: // AND
      case 28: // OR
      case 29: // NOT
      case 30: // LP
      case 31: // RP
      case 32: // LC
      case 33: // RC
      case 34: // LB
      case 35: // RB
      case 36: // LINE_COMMENT
        value.copy< Scan_Info * > (other.value);
        break;

      case 45: // Specifier
        value.copy< Specifier_Node * > (other.value);
        break;

      case 52: // StmtList
        value.copy< StmtList_Node * > (other.value);
        break;

      case 53: // Stmt
        value.copy< Stmt_Node * > (other.value);
        break;

      case 46: // StructSpecifier
        value.copy< StructSpecifier_Node * > (other.value);
        break;

      case 47: // VarDec
        value.copy< VarDec_Node * > (other.value);
        break;

      case 49: // VarList
        value.copy< VarList_Node * > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 59: // Args
        value.copy< Args_Node * > (v);
        break;

      case 51: // CompSt
        value.copy< CompSt_Node * > (v);
        break;

      case 56: // DecList
        value.copy< DecList_Node * > (v);
        break;

      case 57: // Dec
        value.copy< Dec_Node * > (v);
        break;

      case 54: // DefList
        value.copy< DefList_Node * > (v);
        break;

      case 55: // Def
        value.copy< Def_Node * > (v);
        break;

      case 58: // Exp
        value.copy< Exp_Node * > (v);
        break;

      case 44: // ExtDecList
        value.copy< ExtDecList_Node * > (v);
        break;

      case 42: // ExtDefList
        value.copy< ExtDefList_Node * > (v);
        break;

      case 43: // ExtDef
        value.copy< ExtDef_Node * > (v);
        break;

      case 48: // FunDec
        value.copy< FunDec_Node * > (v);
        break;

      case 50: // ParamDec
        value.copy< ParamDec_Node * > (v);
        break;

      case 41: // Program
        value.copy< Program_Node * > (v);
        break;

      case 3: // INT
      case 4: // FLOAT
      case 5: // CHAR
      case 6: // TYPE
      case 7: // ID
      case 8: // STRUCT
      case 9: // IF
      case 10: // ELSE
      case 11: // WHILE
      case 12: // RETURN
      case 13: // ASSIGN
      case 14: // DOT
      case 15: // SEMI
      case 16: // COMMA
      case 17: // EQ
      case 18: // LE
      case 19: // LT
      case 20: // GE
      case 21: // GT
      case 22: // NE
      case 23: // PLUS
      case 24: // MINUS
      case 25: // MUL
      case 26: // DIV
      case 27: // AND
      case 28: // OR
      case 29: // NOT
      case 30: // LP
      case 31: // RP
      case 32: // LC
      case 33: // RC
      case 34: // LB
      case 35: // RB
      case 36: // LINE_COMMENT
        value.copy< Scan_Info * > (v);
        break;

      case 45: // Specifier
        value.copy< Specifier_Node * > (v);
        break;

      case 52: // StmtList
        value.copy< StmtList_Node * > (v);
        break;

      case 53: // Stmt
        value.copy< Stmt_Node * > (v);
        break;

      case 46: // StructSpecifier
        value.copy< StructSpecifier_Node * > (v);
        break;

      case 47: // VarDec
        value.copy< VarDec_Node * > (v);
        break;

      case 49: // VarList
        value.copy< VarList_Node * > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Args_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const CompSt_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const DecList_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Dec_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const DefList_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Def_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Exp_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ExtDecList_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ExtDefList_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ExtDef_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const FunDec_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ParamDec_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Program_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Scan_Info * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Specifier_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const StmtList_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Stmt_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const StructSpecifier_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const VarDec_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const VarList_Node * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  SPL_Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  SPL_Parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 59: // Args
        value.template destroy< Args_Node * > ();
        break;

      case 51: // CompSt
        value.template destroy< CompSt_Node * > ();
        break;

      case 56: // DecList
        value.template destroy< DecList_Node * > ();
        break;

      case 57: // Dec
        value.template destroy< Dec_Node * > ();
        break;

      case 54: // DefList
        value.template destroy< DefList_Node * > ();
        break;

      case 55: // Def
        value.template destroy< Def_Node * > ();
        break;

      case 58: // Exp
        value.template destroy< Exp_Node * > ();
        break;

      case 44: // ExtDecList
        value.template destroy< ExtDecList_Node * > ();
        break;

      case 42: // ExtDefList
        value.template destroy< ExtDefList_Node * > ();
        break;

      case 43: // ExtDef
        value.template destroy< ExtDef_Node * > ();
        break;

      case 48: // FunDec
        value.template destroy< FunDec_Node * > ();
        break;

      case 50: // ParamDec
        value.template destroy< ParamDec_Node * > ();
        break;

      case 41: // Program
        value.template destroy< Program_Node * > ();
        break;

      case 3: // INT
      case 4: // FLOAT
      case 5: // CHAR
      case 6: // TYPE
      case 7: // ID
      case 8: // STRUCT
      case 9: // IF
      case 10: // ELSE
      case 11: // WHILE
      case 12: // RETURN
      case 13: // ASSIGN
      case 14: // DOT
      case 15: // SEMI
      case 16: // COMMA
      case 17: // EQ
      case 18: // LE
      case 19: // LT
      case 20: // GE
      case 21: // GT
      case 22: // NE
      case 23: // PLUS
      case 24: // MINUS
      case 25: // MUL
      case 26: // DIV
      case 27: // AND
      case 28: // OR
      case 29: // NOT
      case 30: // LP
      case 31: // RP
      case 32: // LC
      case 33: // RC
      case 34: // LB
      case 35: // RB
      case 36: // LINE_COMMENT
        value.template destroy< Scan_Info * > ();
        break;

      case 45: // Specifier
        value.template destroy< Specifier_Node * > ();
        break;

      case 52: // StmtList
        value.template destroy< StmtList_Node * > ();
        break;

      case 53: // Stmt
        value.template destroy< Stmt_Node * > ();
        break;

      case 46: // StructSpecifier
        value.template destroy< StructSpecifier_Node * > ();
        break;

      case 47: // VarDec
        value.template destroy< VarDec_Node * > ();
        break;

      case 49: // VarList
        value.template destroy< VarList_Node * > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  SPL_Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  SPL_Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 59: // Args
        value.move< Args_Node * > (s.value);
        break;

      case 51: // CompSt
        value.move< CompSt_Node * > (s.value);
        break;

      case 56: // DecList
        value.move< DecList_Node * > (s.value);
        break;

      case 57: // Dec
        value.move< Dec_Node * > (s.value);
        break;

      case 54: // DefList
        value.move< DefList_Node * > (s.value);
        break;

      case 55: // Def
        value.move< Def_Node * > (s.value);
        break;

      case 58: // Exp
        value.move< Exp_Node * > (s.value);
        break;

      case 44: // ExtDecList
        value.move< ExtDecList_Node * > (s.value);
        break;

      case 42: // ExtDefList
        value.move< ExtDefList_Node * > (s.value);
        break;

      case 43: // ExtDef
        value.move< ExtDef_Node * > (s.value);
        break;

      case 48: // FunDec
        value.move< FunDec_Node * > (s.value);
        break;

      case 50: // ParamDec
        value.move< ParamDec_Node * > (s.value);
        break;

      case 41: // Program
        value.move< Program_Node * > (s.value);
        break;

      case 3: // INT
      case 4: // FLOAT
      case 5: // CHAR
      case 6: // TYPE
      case 7: // ID
      case 8: // STRUCT
      case 9: // IF
      case 10: // ELSE
      case 11: // WHILE
      case 12: // RETURN
      case 13: // ASSIGN
      case 14: // DOT
      case 15: // SEMI
      case 16: // COMMA
      case 17: // EQ
      case 18: // LE
      case 19: // LT
      case 20: // GE
      case 21: // GT
      case 22: // NE
      case 23: // PLUS
      case 24: // MINUS
      case 25: // MUL
      case 26: // DIV
      case 27: // AND
      case 28: // OR
      case 29: // NOT
      case 30: // LP
      case 31: // RP
      case 32: // LC
      case 33: // RC
      case 34: // LB
      case 35: // RB
      case 36: // LINE_COMMENT
        value.move< Scan_Info * > (s.value);
        break;

      case 45: // Specifier
        value.move< Specifier_Node * > (s.value);
        break;

      case 52: // StmtList
        value.move< StmtList_Node * > (s.value);
        break;

      case 53: // Stmt
        value.move< Stmt_Node * > (s.value);
        break;

      case 46: // StructSpecifier
        value.move< StructSpecifier_Node * > (s.value);
        break;

      case 47: // VarDec
        value.move< VarDec_Node * > (s.value);
        break;

      case 49: // VarList
        value.move< VarList_Node * > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  SPL_Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  SPL_Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  SPL_Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  SPL_Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  SPL_Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  SPL_Parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  SPL_Parser::symbol_type
  SPL_Parser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_INT (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::INT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_FLOAT (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::FLOAT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_CHAR (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::CHAR, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_TYPE (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::TYPE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_ID (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::ID, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_STRUCT (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::STRUCT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_IF (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::IF, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_ELSE (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::ELSE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_WHILE (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::WHILE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_RETURN (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::RETURN, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_ASSIGN (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::ASSIGN, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_DOT (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::DOT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_SEMI (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::SEMI, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_COMMA (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::COMMA, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_EQ (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::EQ, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LE (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::LE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LT (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::LT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_GE (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::GE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_GT (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::GT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_NE (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::NE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_PLUS (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::PLUS, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_MINUS (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::MINUS, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_MUL (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::MUL, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_DIV (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::DIV, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_AND (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::AND, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_OR (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::OR, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_NOT (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::NOT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LP (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::LP, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_RP (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::RP, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LC (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::LC, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_RC (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::RC, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LB (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::LB, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_RB (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::RB, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LINE_COMMENT (const Scan_Info *& v, const location_type& l)
  {
    return symbol_type (token::LINE_COMMENT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_ERROR (const location_type& l)
  {
    return symbol_type (token::ERROR, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_ADD (const location_type& l)
  {
    return symbol_type (token::ADD, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_SUB (const location_type& l)
  {
    return symbol_type (token::SUB, l);
  }



  // by_state.
  inline
  SPL_Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  SPL_Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  SPL_Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  SPL_Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  SPL_Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  SPL_Parser::symbol_number_type
  SPL_Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  SPL_Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  SPL_Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 59: // Args
        value.move< Args_Node * > (that.value);
        break;

      case 51: // CompSt
        value.move< CompSt_Node * > (that.value);
        break;

      case 56: // DecList
        value.move< DecList_Node * > (that.value);
        break;

      case 57: // Dec
        value.move< Dec_Node * > (that.value);
        break;

      case 54: // DefList
        value.move< DefList_Node * > (that.value);
        break;

      case 55: // Def
        value.move< Def_Node * > (that.value);
        break;

      case 58: // Exp
        value.move< Exp_Node * > (that.value);
        break;

      case 44: // ExtDecList
        value.move< ExtDecList_Node * > (that.value);
        break;

      case 42: // ExtDefList
        value.move< ExtDefList_Node * > (that.value);
        break;

      case 43: // ExtDef
        value.move< ExtDef_Node * > (that.value);
        break;

      case 48: // FunDec
        value.move< FunDec_Node * > (that.value);
        break;

      case 50: // ParamDec
        value.move< ParamDec_Node * > (that.value);
        break;

      case 41: // Program
        value.move< Program_Node * > (that.value);
        break;

      case 3: // INT
      case 4: // FLOAT
      case 5: // CHAR
      case 6: // TYPE
      case 7: // ID
      case 8: // STRUCT
      case 9: // IF
      case 10: // ELSE
      case 11: // WHILE
      case 12: // RETURN
      case 13: // ASSIGN
      case 14: // DOT
      case 15: // SEMI
      case 16: // COMMA
      case 17: // EQ
      case 18: // LE
      case 19: // LT
      case 20: // GE
      case 21: // GT
      case 22: // NE
      case 23: // PLUS
      case 24: // MINUS
      case 25: // MUL
      case 26: // DIV
      case 27: // AND
      case 28: // OR
      case 29: // NOT
      case 30: // LP
      case 31: // RP
      case 32: // LC
      case 33: // RC
      case 34: // LB
      case 35: // RB
      case 36: // LINE_COMMENT
        value.move< Scan_Info * > (that.value);
        break;

      case 45: // Specifier
        value.move< Specifier_Node * > (that.value);
        break;

      case 52: // StmtList
        value.move< StmtList_Node * > (that.value);
        break;

      case 53: // Stmt
        value.move< Stmt_Node * > (that.value);
        break;

      case 46: // StructSpecifier
        value.move< StructSpecifier_Node * > (that.value);
        break;

      case 47: // VarDec
        value.move< VarDec_Node * > (that.value);
        break;

      case 49: // VarList
        value.move< VarList_Node * > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  SPL_Parser::stack_symbol_type&
  SPL_Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 59: // Args
        value.copy< Args_Node * > (that.value);
        break;

      case 51: // CompSt
        value.copy< CompSt_Node * > (that.value);
        break;

      case 56: // DecList
        value.copy< DecList_Node * > (that.value);
        break;

      case 57: // Dec
        value.copy< Dec_Node * > (that.value);
        break;

      case 54: // DefList
        value.copy< DefList_Node * > (that.value);
        break;

      case 55: // Def
        value.copy< Def_Node * > (that.value);
        break;

      case 58: // Exp
        value.copy< Exp_Node * > (that.value);
        break;

      case 44: // ExtDecList
        value.copy< ExtDecList_Node * > (that.value);
        break;

      case 42: // ExtDefList
        value.copy< ExtDefList_Node * > (that.value);
        break;

      case 43: // ExtDef
        value.copy< ExtDef_Node * > (that.value);
        break;

      case 48: // FunDec
        value.copy< FunDec_Node * > (that.value);
        break;

      case 50: // ParamDec
        value.copy< ParamDec_Node * > (that.value);
        break;

      case 41: // Program
        value.copy< Program_Node * > (that.value);
        break;

      case 3: // INT
      case 4: // FLOAT
      case 5: // CHAR
      case 6: // TYPE
      case 7: // ID
      case 8: // STRUCT
      case 9: // IF
      case 10: // ELSE
      case 11: // WHILE
      case 12: // RETURN
      case 13: // ASSIGN
      case 14: // DOT
      case 15: // SEMI
      case 16: // COMMA
      case 17: // EQ
      case 18: // LE
      case 19: // LT
      case 20: // GE
      case 21: // GT
      case 22: // NE
      case 23: // PLUS
      case 24: // MINUS
      case 25: // MUL
      case 26: // DIV
      case 27: // AND
      case 28: // OR
      case 29: // NOT
      case 30: // LP
      case 31: // RP
      case 32: // LC
      case 33: // RC
      case 34: // LB
      case 35: // RB
      case 36: // LINE_COMMENT
        value.copy< Scan_Info * > (that.value);
        break;

      case 45: // Specifier
        value.copy< Specifier_Node * > (that.value);
        break;

      case 52: // StmtList
        value.copy< StmtList_Node * > (that.value);
        break;

      case 53: // Stmt
        value.copy< Stmt_Node * > (that.value);
        break;

      case 46: // StructSpecifier
        value.copy< StructSpecifier_Node * > (that.value);
        break;

      case 47: // VarDec
        value.copy< VarDec_Node * > (that.value);
        break;

      case 49: // VarList
        value.copy< VarList_Node * > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  SPL_Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  SPL_Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  SPL_Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  SPL_Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  SPL_Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  SPL_Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  SPL_Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  SPL_Parser::debug_level_type
  SPL_Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  SPL_Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline SPL_Parser::state_type
  SPL_Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  SPL_Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  SPL_Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  SPL_Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 59: // Args
        yylhs.value.build< Args_Node * > ();
        break;

      case 51: // CompSt
        yylhs.value.build< CompSt_Node * > ();
        break;

      case 56: // DecList
        yylhs.value.build< DecList_Node * > ();
        break;

      case 57: // Dec
        yylhs.value.build< Dec_Node * > ();
        break;

      case 54: // DefList
        yylhs.value.build< DefList_Node * > ();
        break;

      case 55: // Def
        yylhs.value.build< Def_Node * > ();
        break;

      case 58: // Exp
        yylhs.value.build< Exp_Node * > ();
        break;

      case 44: // ExtDecList
        yylhs.value.build< ExtDecList_Node * > ();
        break;

      case 42: // ExtDefList
        yylhs.value.build< ExtDefList_Node * > ();
        break;

      case 43: // ExtDef
        yylhs.value.build< ExtDef_Node * > ();
        break;

      case 48: // FunDec
        yylhs.value.build< FunDec_Node * > ();
        break;

      case 50: // ParamDec
        yylhs.value.build< ParamDec_Node * > ();
        break;

      case 41: // Program
        yylhs.value.build< Program_Node * > ();
        break;

      case 3: // INT
      case 4: // FLOAT
      case 5: // CHAR
      case 6: // TYPE
      case 7: // ID
      case 8: // STRUCT
      case 9: // IF
      case 10: // ELSE
      case 11: // WHILE
      case 12: // RETURN
      case 13: // ASSIGN
      case 14: // DOT
      case 15: // SEMI
      case 16: // COMMA
      case 17: // EQ
      case 18: // LE
      case 19: // LT
      case 20: // GE
      case 21: // GT
      case 22: // NE
      case 23: // PLUS
      case 24: // MINUS
      case 25: // MUL
      case 26: // DIV
      case 27: // AND
      case 28: // OR
      case 29: // NOT
      case 30: // LP
      case 31: // RP
      case 32: // LC
      case 33: // RC
      case 34: // LB
      case 35: // RB
      case 36: // LINE_COMMENT
        yylhs.value.build< Scan_Info * > ();
        break;

      case 45: // Specifier
        yylhs.value.build< Specifier_Node * > ();
        break;

      case 52: // StmtList
        yylhs.value.build< StmtList_Node * > ();
        break;

      case 53: // Stmt
        yylhs.value.build< Stmt_Node * > ();
        break;

      case 46: // StructSpecifier
        yylhs.value.build< StructSpecifier_Node * > ();
        break;

      case 47: // VarDec
        yylhs.value.build< VarDec_Node * > ();
        break;

      case 49: // VarList
        yylhs.value.build< VarList_Node * > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 117 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Program -> (ExtDefList)" << std::endl;
  	yylhs.value.as< Program_Node * > () = new Program_Node(yystack_[0].value.as< ExtDefList_Node * > ());
  	driver.set_root(yylhs.value.as< Program_Node * > ());
  }
#line 1804 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 3:
#line 125 "parser.y" // lalr1.cc:859
    {
  	std::cout << "ExtDefList - > (ExtDef ExtDefList)" << std::endl;
  	yylhs.value.as< ExtDefList_Node * > () = new ExtDefList_Node(yystack_[1].value.as< ExtDef_Node * > (), yystack_[0].value.as< ExtDefList_Node * > ());
  }
#line 1813 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 129 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< ExtDefList_Node * > () = new Empty_ExtDefList_Node();
  }
#line 1821 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 135 "parser.y" // lalr1.cc:859
    {
    	std::cout << "ExtDef - > (Specifier ExtDecList SEMI)" << std::endl;
  	yylhs.value.as< ExtDef_Node * > () = new ExtDef_Node(yystack_[2].value.as< Specifier_Node * > (), yystack_[1].value.as< ExtDecList_Node * > (), make_leaf(token::SEMI, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 1830 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 139 "parser.y" // lalr1.cc:859
    {
  	driver.add_syntax_error(";", yystack_[1].value.as< Specifier_Node * > ());
  }
#line 1838 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 142 "parser.y" // lalr1.cc:859
    {
  	std::cout << "ExtDef - > (Specifier SEMI)" << std::endl;
  	yylhs.value.as< ExtDef_Node * > () = new ExtDef_Node(yystack_[1].value.as< Specifier_Node * > (), make_leaf(token::SEMI, yystack_[0].value.as< Scan_Info * > ()));

  }
#line 1848 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 147 "parser.y" // lalr1.cc:859
    {
  	driver.add_syntax_error(";", yystack_[0].value.as< Specifier_Node * > ());
  }
#line 1856 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 150 "parser.y" // lalr1.cc:859
    {
  	std::cout << "ExtDef - > (Specifier FunDec CompSt)" << std::endl;
  	yylhs.value.as< ExtDef_Node * > () = new ExtDef_Node(yystack_[2].value.as< Specifier_Node * > (), yystack_[1].value.as< FunDec_Node * > (), yystack_[0].value.as< CompSt_Node * > ());
  }
#line 1865 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 157 "parser.y" // lalr1.cc:859
    {
  	std::cout << "ExtDecList - > (VarDec)" << std::endl;
  	yylhs.value.as< ExtDecList_Node * > () = new ExtDecList_Node(yystack_[0].value.as< VarDec_Node * > ());
  }
#line 1874 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 161 "parser.y" // lalr1.cc:859
    {
  	std::cout << "ExtDecList - > (VarDec COMMA ExtDecList)" << std::endl;
  	yylhs.value.as< ExtDecList_Node * > () = new ExtDecList_Node(yystack_[2].value.as< VarDec_Node * > (), make_leaf(token::COMMA, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< ExtDecList_Node * > ());
  }
#line 1883 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 165 "parser.y" // lalr1.cc:859
    {
  	driver.add_syntax_error(";", yystack_[1].value.as< VarDec_Node * > ());
  }
#line 1891 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 173 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Specifier - > (TYPE) " << yystack_[0].value.as< Scan_Info * > ()->lexeme << std::endl;
  	yylhs.value.as< Specifier_Node * > () = new Specifier_Node(make_leaf(token::TYPE, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 1900 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 177 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Specifier - > (StructSpecifier)" << std::endl;
  	yylhs.value.as< Specifier_Node * > () = new Specifier_Node(yystack_[0].value.as< StructSpecifier_Node * > ());
  }
#line 1909 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 184 "parser.y" // lalr1.cc:859
    {
  	std::cout << "StructSpecifier - > (STRUCT ID LC DefList RC)" << std::endl;
  	yylhs.value.as< StructSpecifier_Node * > () = new StructSpecifier_Node(make_leaf(token::STRUCT, yystack_[4].value.as< Scan_Info * > ()),
  				      make_leaf(token::ID, yystack_[3].value.as< Scan_Info * > ()),
  				      make_leaf(token::LC, yystack_[2].value.as< Scan_Info * > ()),
  				      yystack_[1].value.as< DefList_Node * > (),
  				      make_leaf(token::RC, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 1922 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 192 "parser.y" // lalr1.cc:859
    {
  	driver.add_syntax_error("}", yystack_[3].value.as< Scan_Info * > ());
  }
#line 1930 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 195 "parser.y" // lalr1.cc:859
    {
  	std::cout << "StructSpecifier - > (STRUCT ID)" << std::endl;
  	yylhs.value.as< StructSpecifier_Node * > () = new StructSpecifier_Node(make_leaf(token::STRUCT, yystack_[1].value.as< Scan_Info * > ()),
          			      make_leaf(token::ID, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 1940 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 205 "parser.y" // lalr1.cc:859
    {
  	std::cout << "VarDec - > (ID) " << yystack_[0].value.as< Scan_Info * > ()->lexeme << std::endl;
	yylhs.value.as< VarDec_Node * > () = new ID_VarDec_Node(make_leaf(token::ID, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 1949 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 209 "parser.y" // lalr1.cc:859
    {
  	std::cout << "VarDec - > (VarDec LB INT RB)" << std::endl;
  	yylhs.value.as< VarDec_Node * > () = new Array_VarDec_Node(yystack_[3].value.as< VarDec_Node * > (),
			     	   make_leaf(token::LB, yystack_[2].value.as< Scan_Info * > ()),
			     	   make_leaf(token::INT, yystack_[1].value.as< Scan_Info * > ()),
			     	   make_leaf(token::RB, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 1961 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 216 "parser.y" // lalr1.cc:859
    {
  	driver.add_syntax_error("]", yystack_[2].value.as< VarDec_Node * > ());
  }
#line 1969 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 222 "parser.y" // lalr1.cc:859
    {
  	std::cout << "FunDec - > (ID LP VarList RP) " << yystack_[3].value.as< Scan_Info * > ()->lexeme << std::endl;
  	yylhs.value.as< FunDec_Node * > () = new FunDec_Node(make_leaf(token::ID, yystack_[3].value.as< Scan_Info * > ()),
			     make_leaf(token::LP, yystack_[2].value.as< Scan_Info * > ()),
			     yystack_[1].value.as< VarList_Node * > (),
			     make_leaf(token::RP, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 1981 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 229 "parser.y" // lalr1.cc:859
    {
    	driver.add_syntax_error(")", yystack_[2].value.as< Scan_Info * > ());
  }
#line 1989 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 232 "parser.y" // lalr1.cc:859
    {
  	std::cout << "FunDec - > (ID LP RP) " << yystack_[2].value.as< Scan_Info * > ()->lexeme << std::endl;
  	yylhs.value.as< FunDec_Node * > () = new FunDec_Node(make_leaf(token::ID, yystack_[2].value.as< Scan_Info * > ()),
			     make_leaf(token::LP, yystack_[1].value.as< Scan_Info * > ()),
			     make_leaf(token::RP, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2000 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 238 "parser.y" // lalr1.cc:859
    {
    	driver.add_syntax_error(")", yystack_[1].value.as< Scan_Info * > ());
  }
#line 2008 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 244 "parser.y" // lalr1.cc:859
    {
  	std::cout << "VarList - > (ParamDec COMMA VarList)" << std::endl;
  	yylhs.value.as< VarList_Node * > () = new VarList_Node(yystack_[2].value.as< ParamDec_Node * > (),
			      make_leaf(token::COMMA, yystack_[1].value.as< Scan_Info * > ()),
			      yystack_[0].value.as< VarList_Node * > ());
  }
#line 2019 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 250 "parser.y" // lalr1.cc:859
    {
  	std::cout << "VarList - > (ParamDec)" << std::endl;
  	yylhs.value.as< VarList_Node * > () = new VarList_Node(yystack_[0].value.as< ParamDec_Node * > ());
  }
#line 2028 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 257 "parser.y" // lalr1.cc:859
    {
  	std::cout << "ParamDec - > (Specifier VarDec)" << std::endl;
  	yylhs.value.as< ParamDec_Node * > () = new ParamDec_Node(yystack_[1].value.as< Specifier_Node * > (), yystack_[0].value.as< VarDec_Node * > ());
  }
#line 2037 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 266 "parser.y" // lalr1.cc:859
    {
  	std::cout << "CompSt - > (LC DefList StmtList RC)" << std::endl;
  	yylhs.value.as< CompSt_Node * > () = new CompSt_Node(make_leaf(token::LC, yystack_[3].value.as< Scan_Info * > ()),
		             yystack_[2].value.as< DefList_Node * > (),
		             yystack_[1].value.as< StmtList_Node * > (),
		             make_leaf(token::RC, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2049 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 273 "parser.y" // lalr1.cc:859
    {
  	driver.add_syntax_error("}", {yystack_[2].value.as< Scan_Info * > ()});
  }
#line 2057 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 279 "parser.y" // lalr1.cc:859
    {
  	std::cout << "StmtList - > (Stmt StmtList)" << std::endl;
  	yylhs.value.as< StmtList_Node * > () = new StmtList_Node(yystack_[1].value.as< Stmt_Node * > (), yystack_[0].value.as< StmtList_Node * > ());
  }
#line 2066 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 283 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< StmtList_Node * > () = new Empty_StmtList_Node();
  }
#line 2074 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 289 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Stmt - > (Exp SEMI)" << std::endl;
  	yylhs.value.as< Stmt_Node * > () = new Exp_Stmt_Node(yystack_[1].value.as< Exp_Node * > (),
  			       make_leaf(token::SEMI, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2084 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 297 "parser.y" // lalr1.cc:859
    {
  	driver.add_syntax_error(";", yystack_[0].value.as< Exp_Node * > ());
  }
#line 2092 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 300 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Stmt - > (CompSt)" << std::endl;
  	yylhs.value.as< Stmt_Node * > () = new CompSt_Stmt_Node(yystack_[0].value.as< CompSt_Node * > ());
  }
#line 2101 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 304 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Stmt - > (RETURN Exp SEMI)" << std::endl;
  	yylhs.value.as< Stmt_Node * > () = new Return_Stmt_Node(make_leaf(token::RETURN, yystack_[2].value.as< Scan_Info * > ()),
  			   	  yystack_[1].value.as< Exp_Node * > (),
          		   	  make_leaf(token::SEMI, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2112 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 310 "parser.y" // lalr1.cc:859
    {
  	driver.add_syntax_error(";", yystack_[1].value.as< Scan_Info * > ());
  }
#line 2120 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 313 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Stmt - > (IF LP Exp RP Stmt)" << std::endl;
  	yylhs.value.as< Stmt_Node * > () = new If_Stmt_Node(make_leaf(token::IF, yystack_[4].value.as< Scan_Info * > ()),
  			      make_leaf(token::LP, yystack_[3].value.as< Scan_Info * > ()),
  			      yystack_[2].value.as< Exp_Node * > (),
  			      make_leaf(token::RP, yystack_[1].value.as< Scan_Info * > ()),
          		      yystack_[0].value.as< Stmt_Node * > ());
  }
#line 2133 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 321 "parser.y" // lalr1.cc:859
    {
	driver.add_syntax_error(")", yystack_[3].value.as< Scan_Info * > ());
  }
#line 2141 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 324 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Stmt - > (IF LP Exp RP Stmt ELSE Stmt)" << std::endl;
  	yylhs.value.as< Stmt_Node * > () = new If_Stmt_Node(make_leaf(token::IF, yystack_[6].value.as< Scan_Info * > ()),
  			      make_leaf(token::LP, yystack_[5].value.as< Scan_Info * > ()),
  			      yystack_[4].value.as< Exp_Node * > (),
  			      make_leaf(token::RP, yystack_[3].value.as< Scan_Info * > ()),
          		      yystack_[2].value.as< Stmt_Node * > (),
          		      make_leaf(token::ELSE, yystack_[1].value.as< Scan_Info * > ()),
          		      yystack_[0].value.as< Stmt_Node * > ());
  }
#line 2156 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 334 "parser.y" // lalr1.cc:859
    {
	driver.add_syntax_error(")", yystack_[5].value.as< Scan_Info * > ());
  }
#line 2164 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 337 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Stmt - > (WHILE LP Exp RP Stmt)" << std::endl;
  	yylhs.value.as< Stmt_Node * > () = new While_Stmt_Node(make_leaf(token::WHILE, yystack_[4].value.as< Scan_Info * > ()),
			         make_leaf(token::LP, yystack_[3].value.as< Scan_Info * > ()),
			         yystack_[2].value.as< Exp_Node * > (),
			         make_leaf(token::RP, yystack_[1].value.as< Scan_Info * > ()),
			         yystack_[0].value.as< Stmt_Node * > ());
  }
#line 2177 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 345 "parser.y" // lalr1.cc:859
    {
	driver.add_syntax_error(")", yystack_[3].value.as< Scan_Info * > ());
  }
#line 2185 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 353 "parser.y" // lalr1.cc:859
    {
  	std::cout << "DefList - > (Def DefList)" << std::endl;
  	yylhs.value.as< DefList_Node * > () = new DefList_Node(yystack_[1].value.as< Def_Node * > (), yystack_[0].value.as< DefList_Node * > ());
  }
#line 2194 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 357 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< DefList_Node * > () = new Empty_DefList_Node();
  }
#line 2202 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 363 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Def - > (Specifier DecList SEMI)" << std::endl;
  	yylhs.value.as< Def_Node * > () = new Def_Node(yystack_[2].value.as< Specifier_Node * > (),
  	 		  yystack_[1].value.as< DecList_Node * > (),
  	 		  make_leaf(token::SEMI, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2213 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 369 "parser.y" // lalr1.cc:859
    {
  	driver.add_syntax_error(";", yystack_[1].value.as< Specifier_Node * > ());
  }
#line 2221 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 375 "parser.y" // lalr1.cc:859
    {
  	std::cout << "DecList - > (Dec)" << std::endl;
  	yylhs.value.as< DecList_Node * > () = new DecList_Node(yystack_[0].value.as< Dec_Node * > ());
  }
#line 2230 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 379 "parser.y" // lalr1.cc:859
    {
  	std::cout << "DecList - > (Dec COMMA DecList)" << std::endl;
  	yylhs.value.as< DecList_Node * > () = new DecList_Node(yystack_[2].value.as< Dec_Node * > (),
  			      make_leaf(token::COMMA, yystack_[1].value.as< Scan_Info * > ()),
  			      yystack_[0].value.as< DecList_Node * > ());
  }
#line 2241 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 388 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Dec - > (VarDec)" << std::endl;
  	yylhs.value.as< Dec_Node * > () = new Dec_Node(yystack_[0].value.as< VarDec_Node * > ());
  }
#line 2250 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 392 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Dec - > (VarDec ASSIGN Exp)" << std::endl;
  	yylhs.value.as< Dec_Node * > () = new Dec_Node(yystack_[2].value.as< VarDec_Node * > (),
  			  make_leaf(token::ASSIGN, yystack_[1].value.as< Scan_Info * > ()),
  			  yystack_[0].value.as< Exp_Node * > ());
  }
#line 2261 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 403 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Exp - > (Exp ASSIGN Exp)" << std::endl;
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::ASSIGN, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2270 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 407 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::AND, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2278 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 410 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::OR, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2286 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 413 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::LT, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2294 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 416 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::LE, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2302 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 419 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::GT, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
   }
#line 2310 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 422 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::GE, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2318 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 425 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::NE, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2326 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 428 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::EQ, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2334 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 431 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::PLUS, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2342 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 434 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::MINUS, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2350 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 437 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::MUL, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2358 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 440 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::DIV, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2366 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 443 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Parentheses_Exp_Node(make_leaf(token::LP, yystack_[2].value.as< Scan_Info * > ()),
  				      yystack_[1].value.as< Exp_Node * > (),
  				      make_leaf(token::RP, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2376 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 448 "parser.y" // lalr1.cc:859
    {
	driver.add_syntax_error(")", yystack_[1].value.as< Scan_Info * > ());
  }
#line 2384 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 451 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Unary_Exp_Node(make_leaf(token::MINUS, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2392 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 454 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Unary_Exp_Node(make_leaf(token::NOT, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2400 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 457 "parser.y" // lalr1.cc:859
    {
	yylhs.value.as< Exp_Node * > () = new ID_Parentheses_Exp_Node(make_leaf(token::ID, yystack_[3].value.as< Scan_Info * > ()),
				         make_leaf(token::LP, yystack_[2].value.as< Scan_Info * > ()),
				         yystack_[1].value.as< Args_Node * > (),
				         make_leaf(token::RP, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2411 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 463 "parser.y" // lalr1.cc:859
    {
	driver.add_syntax_error(")", yystack_[2].value.as< Scan_Info * > ());
  }
#line 2419 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 466 "parser.y" // lalr1.cc:859
    {
	yylhs.value.as< Exp_Node * > () = new ID_Parentheses_Exp_Node(make_leaf(token::ID, yystack_[2].value.as< Scan_Info * > ()),
					 make_leaf(token::LP, yystack_[1].value.as< Scan_Info * > ()),
					 make_leaf(token::RP, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2429 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 471 "parser.y" // lalr1.cc:859
    {
	driver.add_syntax_error(")", yystack_[1].value.as< Scan_Info * > ());
  }
#line 2437 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 474 "parser.y" // lalr1.cc:859
    {
	yylhs.value.as< Exp_Node * > () = new Bracket_Exp_Node(yystack_[3].value.as< Exp_Node * > (),
				  make_leaf(token::LB, yystack_[2].value.as< Scan_Info * > ()),
				  yystack_[1].value.as< Exp_Node * > (),
				  make_leaf(token::RB, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2448 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 480 "parser.y" // lalr1.cc:859
    {
	driver.add_syntax_error("]", yystack_[2].value.as< Exp_Node * > ());
  }
#line 2456 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 483 "parser.y" // lalr1.cc:859
    {
	yylhs.value.as< Exp_Node * > () = new Dot_Exp_Node(yystack_[2].value.as< Exp_Node * > (),
			      make_leaf(token::DOT, yystack_[1].value.as< Scan_Info * > ()),
			      make_leaf(token::ID, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2466 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 488 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Exp - > (ID) " << yystack_[0].value.as< Scan_Info * > ()->lexeme << std::endl;
  	yylhs.value.as< Exp_Node * > () = new Leaf_Exp_Node(make_leaf(token::ID, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2475 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 492 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Exp - > (INT) " << yystack_[0].value.as< Scan_Info * > ()->lexeme << std::endl;
  	yylhs.value.as< Exp_Node * > () = new Leaf_Exp_Node(make_leaf(token::INT, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2484 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 496 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Exp - > (FLOAT) " << yystack_[0].value.as< Scan_Info * > ()->lexeme << std::endl;
  	yylhs.value.as< Exp_Node * > () = new Leaf_Exp_Node(make_leaf(token::FLOAT, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2493 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 500 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Exp - > (CHAR) " << yystack_[0].value.as< Scan_Info * > ()->lexeme << std::endl;
  	yylhs.value.as< Exp_Node * > () = new Leaf_Exp_Node(make_leaf(token::CHAR, yystack_[0].value.as< Scan_Info * > ()));
  }
#line 2502 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 507 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Args - > (Exp COMMA Args) " << std::endl;
  	yylhs.value.as< Args_Node * > () = new Args_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::COMMA, yystack_[1].value.as< Scan_Info * > ()), yystack_[0].value.as< Args_Node * > ());
  }
#line 2511 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 511 "parser.y" // lalr1.cc:859
    {
        std::cout << "Args - > (Exp) " << std::endl;
        yylhs.value.as< Args_Node * > () = new Args_Node(yystack_[0].value.as< Exp_Node * > ());
  }
#line 2520 "parser.tab.cpp" // lalr1.cc:859
    break;


#line 2524 "parser.tab.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  SPL_Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  SPL_Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char SPL_Parser::yypact_ninf_ = -76;

  const signed char SPL_Parser::yytable_ninf_ = -67;

  const short int
  SPL_Parser::yypact_[] =
  {
      -2,   -76,     2,    50,   -76,    -2,     8,   -76,    19,   -76,
     -76,    23,   -76,    39,    30,    25,    -2,    37,   -76,   -76,
      48,    53,   -76,    -2,   -76,    48,    26,    -2,   -76,    48,
      51,    65,   -76,    49,   148,     6,    68,    74,   -76,   -76,
      58,   -76,    -2,   -76,   -76,   -76,   -76,    64,    69,    70,
     166,   166,   166,   166,   -76,    89,   148,   203,   166,   -76,
      48,   -76,   158,   166,   166,   221,   276,   152,   239,   -76,
     -76,   166,   110,   -76,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   276,   -76,   -76,
     258,    93,    84,   116,   -76,   -76,   276,   -76,   325,   325,
     325,   325,   325,   325,   276,   276,   152,   152,   312,   294,
     180,   166,   -76,   166,   148,   -76,   148,   121,   -76,   -76,
      52,   122,   -76,   148,   148,   -76,   -76
  };

  const unsigned char
  SPL_Parser::yydefact_[] =
  {
       4,    13,     0,     0,     2,     4,     8,    14,    17,     1,
       3,    18,     7,     6,    10,     0,    44,    24,     5,    18,
       0,     0,    12,    44,     9,     0,    16,    44,    23,     0,
      22,    26,    11,    20,    31,    49,    46,    47,    15,    43,
      27,    21,     0,    19,    76,    77,    78,    75,     0,     0,
       0,     0,     0,     0,    34,    29,    31,    33,     0,    45,
       0,    25,    71,     0,     0,    36,    66,    67,    65,    28,
      30,     0,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    48,    70,
      80,    69,     0,     0,    35,    64,    51,    74,    59,    55,
      54,    57,    56,    58,    60,    61,    62,    63,    52,    53,
      73,     0,    68,     0,     0,    38,     0,    42,    72,    79,
      61,    37,    41,     0,     0,    40,    39
  };

  const short int
  SPL_Parser::yypgoto_[] =
  {
     -76,   -76,   144,   -76,    24,     5,   -76,   -18,   -76,   112,
     -76,   111,   100,   -75,    -7,   -76,    98,   -76,   -50,    56
  };

  const signed char
  SPL_Parser::yydefgoto_[] =
  {
      -1,     3,     4,     5,    13,    25,     7,    14,    15,    30,
      31,    54,    55,    56,    26,    27,    36,    37,    57,    91
  };

  const signed char
  SPL_Parser::yytable_[] =
  {
      65,    66,    67,    68,     1,     6,     2,    35,    87,     8,
       6,    40,    90,    92,    93,    11,    34,   115,   117,    58,
      39,    96,    29,    12,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    19,    22,   121,
      21,   122,    35,     1,    32,     2,    20,    29,   125,   126,
       9,    16,   -66,    17,    18,    19,    33,    23,   -66,    38,
     -66,    90,   -66,   120,    21,    71,    72,   -66,    28,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    42,    41,    59,    43,   -66,    86,    44,    45,    46,
      60,    47,    21,    48,    62,    49,    50,    71,    72,    63,
      64,    74,    75,    76,    77,    78,    79,    80,   113,    82,
      83,    84,    85,    52,    53,   114,    23,    97,    86,    44,
      45,    46,    69,    47,   112,    48,    24,    49,    50,    71,
      72,   123,   124,    74,    75,    76,    77,    78,    79,    80,
     113,    82,    83,    84,    85,    52,    53,   116,    23,    10,
      86,    44,    45,    46,    61,    47,    70,    48,    88,    49,
      50,    44,    45,    46,     0,    47,    72,   119,     0,    44,
      45,    46,    51,    47,     0,    80,    81,    52,    53,     0,
      23,     0,    51,     0,     0,     0,    86,    52,    53,    89,
      51,     0,     0,    71,    72,    52,    53,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,    86,   118,    71,    72,    73,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,    71,    72,    94,    86,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,     0,    71,    72,     0,    86,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
      95,    71,    72,    86,   111,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    71,
      72,     0,    86,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,    72,     0,
      86,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,     0,     0,     0,    72,     0,    86,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    72,
       0,     0,     0,     0,     0,     0,    86,     0,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,     0,    86
  };

  const signed char
  SPL_Parser::yycheck_[] =
  {
      50,    51,    52,    53,     6,     0,     8,    25,    58,     7,
       5,    29,    62,    63,    64,     7,    23,    92,    93,    13,
      27,    71,    17,    15,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     7,    14,   114,
      34,   116,    60,     6,    20,     8,    16,    42,   123,   124,
       0,    32,     0,    30,    15,     7,     3,    32,     6,    33,
       8,   111,    10,   113,    34,    13,    14,    15,    31,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    16,    31,    15,    35,    33,    34,     3,     4,     5,
      16,     7,    34,     9,    30,    11,    12,    13,    14,    30,
      30,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     7,    34,     3,
       4,     5,    33,     7,    31,     9,    15,    11,    12,    13,
      14,    10,    10,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     5,
      34,     3,     4,     5,    42,     7,    56,     9,    60,    11,
      12,     3,     4,     5,    -1,     7,    14,   111,    -1,     3,
       4,     5,    24,     7,    -1,    23,    24,    29,    30,    -1,
      32,    -1,    24,    -1,    -1,    -1,    34,    29,    30,    31,
      24,    -1,    -1,    13,    14,    29,    30,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    34,    35,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    13,    14,    15,    34,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    13,    14,    -1,    34,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    13,    14,    34,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    13,
      14,    -1,    34,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    14,    -1,
      34,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    14,    -1,    34,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34
  };

  const unsigned char
  SPL_Parser::yystos_[] =
  {
       0,     6,     8,    41,    42,    43,    45,    46,     7,     0,
      42,     7,    15,    44,    47,    48,    32,    30,    15,     7,
      16,    34,    44,    32,    51,    45,    54,    55,    31,    45,
      49,    50,    44,     3,    54,    47,    56,    57,    33,    54,
      47,    31,    16,    35,     3,     4,     5,     7,     9,    11,
      12,    24,    29,    30,    51,    52,    53,    58,    13,    15,
      16,    49,    30,    30,    30,    58,    58,    58,    58,    33,
      52,    13,    14,    15,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    34,    58,    56,    31,
      58,    59,    58,    58,    15,    31,    58,     7,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    16,    31,    24,    31,    53,    31,    53,    35,    59,
      58,    53,    53,    10,    10,    53,    53
  };

  const unsigned char
  SPL_Parser::yyr1_[] =
  {
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      44,    44,    44,    45,    45,    46,    46,    46,    47,    47,
      47,    48,    48,    48,    48,    49,    49,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59
  };

  const unsigned char
  SPL_Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     3,     2,     2,     1,     3,
       1,     3,     2,     1,     1,     5,     4,     2,     1,     4,
       3,     4,     3,     3,     2,     3,     1,     2,     4,     3,
       2,     0,     2,     1,     1,     3,     2,     5,     4,     7,
       6,     5,     4,     2,     0,     3,     2,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     4,     3,
       3,     2,     4,     3,     3,     1,     1,     1,     1,     3,
       1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const SPL_Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "INT", "FLOAT", "CHAR",
  "TYPE", "ID", "STRUCT", "IF", "ELSE", "WHILE", "RETURN", "ASSIGN", "DOT",
  "SEMI", "COMMA", "EQ", "LE", "LT", "GE", "GT", "NE", "PLUS", "MINUS",
  "MUL", "DIV", "AND", "OR", "NOT", "LP", "RP", "LC", "RC", "LB", "RB",
  "LINE_COMMENT", "ERROR", "ADD", "SUB", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "VarDec", "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt",
  "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
  };


  const unsigned short int
  SPL_Parser::yyrline_[] =
  {
       0,   117,   117,   125,   129,   135,   139,   142,   147,   150,
     157,   161,   165,   173,   177,   184,   192,   195,   205,   209,
     216,   222,   229,   232,   238,   244,   250,   257,   266,   273,
     279,   283,   289,   297,   300,   304,   310,   313,   321,   324,
     334,   337,   345,   353,   357,   363,   369,   375,   379,   388,
     392,   403,   407,   410,   413,   416,   419,   422,   425,   428,
     431,   434,   437,   440,   443,   448,   451,   454,   457,   463,
     466,   471,   474,   480,   483,   488,   492,   496,   500,   507,
     511
  };

  // Print the state stack on the debug stream.
  void
  SPL_Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  SPL_Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  SPL_Parser::token_number_type
  SPL_Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
    };
    const unsigned int user_token_number_max_ = 294;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "parser.y" // lalr1.cc:1167
} // SPL
#line 2986 "parser.tab.cpp" // lalr1.cc:1167
#line 517 "parser.y" // lalr1.cc:1168


void SPL::SPL_Parser::error(const location_type &l, const std::string &err_message){
    std::cerr << "Auto parser error! " << l.begin << ": unknown lexeme " << err_message << std::endl;
    throw SPL_Parser::syntax_error(l, err_message);
}
