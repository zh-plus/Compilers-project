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
#line 53 "parser.y" // lalr1.cc:413

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


#line 71 "parser.tab.cpp" // lalr1.cc:413


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
#line 157 "parser.tab.cpp" // lalr1.cc:479

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
      case 58: // Args
        value.copy< Args_Node * > (other.value);
        break;

      case 50: // CompSt
        value.copy< CompSt_Node * > (other.value);
        break;

      case 55: // DecList
        value.copy< DecList_Node * > (other.value);
        break;

      case 56: // Dec
        value.copy< Dec_Node * > (other.value);
        break;

      case 53: // DefList
        value.copy< DefList_Node * > (other.value);
        break;

      case 54: // Def
        value.copy< Def_Node * > (other.value);
        break;

      case 57: // Exp
        value.copy< Exp_Node * > (other.value);
        break;

      case 43: // ExtDecList
        value.copy< ExtDecList_Node * > (other.value);
        break;

      case 41: // ExtDefList
        value.copy< ExtDefList_Node * > (other.value);
        break;

      case 42: // ExtDef
        value.copy< ExtDef_Node * > (other.value);
        break;

      case 47: // FunDec
        value.copy< FunDec_Node * > (other.value);
        break;

      case 49: // ParamDec
        value.copy< ParamDec_Node * > (other.value);
        break;

      case 40: // Program
        value.copy< Program_Node * > (other.value);
        break;

      case 44: // Specifier
        value.copy< Specifier_Node * > (other.value);
        break;

      case 51: // StmtList
        value.copy< StmtList_Node * > (other.value);
        break;

      case 52: // Stmt
        value.copy< Stmt_Node * > (other.value);
        break;

      case 45: // StructSpecifier
        value.copy< StructSpecifier_Node * > (other.value);
        break;

      case 46: // VarDec
        value.copy< VarDec_Node * > (other.value);
        break;

      case 48: // VarList
        value.copy< VarList_Node * > (other.value);
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
        value.copy< std::string > (other.value);
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
      case 58: // Args
        value.copy< Args_Node * > (v);
        break;

      case 50: // CompSt
        value.copy< CompSt_Node * > (v);
        break;

      case 55: // DecList
        value.copy< DecList_Node * > (v);
        break;

      case 56: // Dec
        value.copy< Dec_Node * > (v);
        break;

      case 53: // DefList
        value.copy< DefList_Node * > (v);
        break;

      case 54: // Def
        value.copy< Def_Node * > (v);
        break;

      case 57: // Exp
        value.copy< Exp_Node * > (v);
        break;

      case 43: // ExtDecList
        value.copy< ExtDecList_Node * > (v);
        break;

      case 41: // ExtDefList
        value.copy< ExtDefList_Node * > (v);
        break;

      case 42: // ExtDef
        value.copy< ExtDef_Node * > (v);
        break;

      case 47: // FunDec
        value.copy< FunDec_Node * > (v);
        break;

      case 49: // ParamDec
        value.copy< ParamDec_Node * > (v);
        break;

      case 40: // Program
        value.copy< Program_Node * > (v);
        break;

      case 44: // Specifier
        value.copy< Specifier_Node * > (v);
        break;

      case 51: // StmtList
        value.copy< StmtList_Node * > (v);
        break;

      case 52: // Stmt
        value.copy< Stmt_Node * > (v);
        break;

      case 45: // StructSpecifier
        value.copy< StructSpecifier_Node * > (v);
        break;

      case 46: // VarDec
        value.copy< VarDec_Node * > (v);
        break;

      case 48: // VarList
        value.copy< VarList_Node * > (v);
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
        value.copy< std::string > (v);
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
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
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
      case 58: // Args
        value.template destroy< Args_Node * > ();
        break;

      case 50: // CompSt
        value.template destroy< CompSt_Node * > ();
        break;

      case 55: // DecList
        value.template destroy< DecList_Node * > ();
        break;

      case 56: // Dec
        value.template destroy< Dec_Node * > ();
        break;

      case 53: // DefList
        value.template destroy< DefList_Node * > ();
        break;

      case 54: // Def
        value.template destroy< Def_Node * > ();
        break;

      case 57: // Exp
        value.template destroy< Exp_Node * > ();
        break;

      case 43: // ExtDecList
        value.template destroy< ExtDecList_Node * > ();
        break;

      case 41: // ExtDefList
        value.template destroy< ExtDefList_Node * > ();
        break;

      case 42: // ExtDef
        value.template destroy< ExtDef_Node * > ();
        break;

      case 47: // FunDec
        value.template destroy< FunDec_Node * > ();
        break;

      case 49: // ParamDec
        value.template destroy< ParamDec_Node * > ();
        break;

      case 40: // Program
        value.template destroy< Program_Node * > ();
        break;

      case 44: // Specifier
        value.template destroy< Specifier_Node * > ();
        break;

      case 51: // StmtList
        value.template destroy< StmtList_Node * > ();
        break;

      case 52: // Stmt
        value.template destroy< Stmt_Node * > ();
        break;

      case 45: // StructSpecifier
        value.template destroy< StructSpecifier_Node * > ();
        break;

      case 46: // VarDec
        value.template destroy< VarDec_Node * > ();
        break;

      case 48: // VarList
        value.template destroy< VarList_Node * > ();
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
        value.template destroy< std::string > ();
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
      case 58: // Args
        value.move< Args_Node * > (s.value);
        break;

      case 50: // CompSt
        value.move< CompSt_Node * > (s.value);
        break;

      case 55: // DecList
        value.move< DecList_Node * > (s.value);
        break;

      case 56: // Dec
        value.move< Dec_Node * > (s.value);
        break;

      case 53: // DefList
        value.move< DefList_Node * > (s.value);
        break;

      case 54: // Def
        value.move< Def_Node * > (s.value);
        break;

      case 57: // Exp
        value.move< Exp_Node * > (s.value);
        break;

      case 43: // ExtDecList
        value.move< ExtDecList_Node * > (s.value);
        break;

      case 41: // ExtDefList
        value.move< ExtDefList_Node * > (s.value);
        break;

      case 42: // ExtDef
        value.move< ExtDef_Node * > (s.value);
        break;

      case 47: // FunDec
        value.move< FunDec_Node * > (s.value);
        break;

      case 49: // ParamDec
        value.move< ParamDec_Node * > (s.value);
        break;

      case 40: // Program
        value.move< Program_Node * > (s.value);
        break;

      case 44: // Specifier
        value.move< Specifier_Node * > (s.value);
        break;

      case 51: // StmtList
        value.move< StmtList_Node * > (s.value);
        break;

      case 52: // Stmt
        value.move< Stmt_Node * > (s.value);
        break;

      case 45: // StructSpecifier
        value.move< StructSpecifier_Node * > (s.value);
        break;

      case 46: // VarDec
        value.move< VarDec_Node * > (s.value);
        break;

      case 48: // VarList
        value.move< VarList_Node * > (s.value);
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
        value.move< std::string > (s.value);
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
  SPL_Parser::make_INT (const std::string& v, const location_type& l)
  {
    return symbol_type (token::INT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_FLOAT (const std::string& v, const location_type& l)
  {
    return symbol_type (token::FLOAT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_CHAR (const std::string& v, const location_type& l)
  {
    return symbol_type (token::CHAR, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_TYPE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TYPE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_ID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::ID, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_STRUCT (const std::string& v, const location_type& l)
  {
    return symbol_type (token::STRUCT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_IF (const std::string& v, const location_type& l)
  {
    return symbol_type (token::IF, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_ELSE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::ELSE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_WHILE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::WHILE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_RETURN (const std::string& v, const location_type& l)
  {
    return symbol_type (token::RETURN, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_ASSIGN (const std::string& v, const location_type& l)
  {
    return symbol_type (token::ASSIGN, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_DOT (const std::string& v, const location_type& l)
  {
    return symbol_type (token::DOT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_SEMI (const std::string& v, const location_type& l)
  {
    return symbol_type (token::SEMI, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_COMMA (const std::string& v, const location_type& l)
  {
    return symbol_type (token::COMMA, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_EQ (const std::string& v, const location_type& l)
  {
    return symbol_type (token::EQ, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::LE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LT (const std::string& v, const location_type& l)
  {
    return symbol_type (token::LT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_GE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::GE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_GT (const std::string& v, const location_type& l)
  {
    return symbol_type (token::GT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_NE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::NE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_PLUS (const std::string& v, const location_type& l)
  {
    return symbol_type (token::PLUS, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_MINUS (const std::string& v, const location_type& l)
  {
    return symbol_type (token::MINUS, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_MUL (const std::string& v, const location_type& l)
  {
    return symbol_type (token::MUL, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_DIV (const std::string& v, const location_type& l)
  {
    return symbol_type (token::DIV, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_AND (const std::string& v, const location_type& l)
  {
    return symbol_type (token::AND, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_OR (const std::string& v, const location_type& l)
  {
    return symbol_type (token::OR, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_NOT (const std::string& v, const location_type& l)
  {
    return symbol_type (token::NOT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LP (const std::string& v, const location_type& l)
  {
    return symbol_type (token::LP, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_RP (const std::string& v, const location_type& l)
  {
    return symbol_type (token::RP, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LC (const std::string& v, const location_type& l)
  {
    return symbol_type (token::LC, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_RC (const std::string& v, const location_type& l)
  {
    return symbol_type (token::RC, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LB (const std::string& v, const location_type& l)
  {
    return symbol_type (token::LB, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_RB (const std::string& v, const location_type& l)
  {
    return symbol_type (token::RB, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LINE_COMMENT (const std::string& v, const location_type& l)
  {
    return symbol_type (token::LINE_COMMENT, v, l);
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
      case 58: // Args
        value.move< Args_Node * > (that.value);
        break;

      case 50: // CompSt
        value.move< CompSt_Node * > (that.value);
        break;

      case 55: // DecList
        value.move< DecList_Node * > (that.value);
        break;

      case 56: // Dec
        value.move< Dec_Node * > (that.value);
        break;

      case 53: // DefList
        value.move< DefList_Node * > (that.value);
        break;

      case 54: // Def
        value.move< Def_Node * > (that.value);
        break;

      case 57: // Exp
        value.move< Exp_Node * > (that.value);
        break;

      case 43: // ExtDecList
        value.move< ExtDecList_Node * > (that.value);
        break;

      case 41: // ExtDefList
        value.move< ExtDefList_Node * > (that.value);
        break;

      case 42: // ExtDef
        value.move< ExtDef_Node * > (that.value);
        break;

      case 47: // FunDec
        value.move< FunDec_Node * > (that.value);
        break;

      case 49: // ParamDec
        value.move< ParamDec_Node * > (that.value);
        break;

      case 40: // Program
        value.move< Program_Node * > (that.value);
        break;

      case 44: // Specifier
        value.move< Specifier_Node * > (that.value);
        break;

      case 51: // StmtList
        value.move< StmtList_Node * > (that.value);
        break;

      case 52: // Stmt
        value.move< Stmt_Node * > (that.value);
        break;

      case 45: // StructSpecifier
        value.move< StructSpecifier_Node * > (that.value);
        break;

      case 46: // VarDec
        value.move< VarDec_Node * > (that.value);
        break;

      case 48: // VarList
        value.move< VarList_Node * > (that.value);
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
        value.move< std::string > (that.value);
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
      case 58: // Args
        value.copy< Args_Node * > (that.value);
        break;

      case 50: // CompSt
        value.copy< CompSt_Node * > (that.value);
        break;

      case 55: // DecList
        value.copy< DecList_Node * > (that.value);
        break;

      case 56: // Dec
        value.copy< Dec_Node * > (that.value);
        break;

      case 53: // DefList
        value.copy< DefList_Node * > (that.value);
        break;

      case 54: // Def
        value.copy< Def_Node * > (that.value);
        break;

      case 57: // Exp
        value.copy< Exp_Node * > (that.value);
        break;

      case 43: // ExtDecList
        value.copy< ExtDecList_Node * > (that.value);
        break;

      case 41: // ExtDefList
        value.copy< ExtDefList_Node * > (that.value);
        break;

      case 42: // ExtDef
        value.copy< ExtDef_Node * > (that.value);
        break;

      case 47: // FunDec
        value.copy< FunDec_Node * > (that.value);
        break;

      case 49: // ParamDec
        value.copy< ParamDec_Node * > (that.value);
        break;

      case 40: // Program
        value.copy< Program_Node * > (that.value);
        break;

      case 44: // Specifier
        value.copy< Specifier_Node * > (that.value);
        break;

      case 51: // StmtList
        value.copy< StmtList_Node * > (that.value);
        break;

      case 52: // Stmt
        value.copy< Stmt_Node * > (that.value);
        break;

      case 45: // StructSpecifier
        value.copy< StructSpecifier_Node * > (that.value);
        break;

      case 46: // VarDec
        value.copy< VarDec_Node * > (that.value);
        break;

      case 48: // VarList
        value.copy< VarList_Node * > (that.value);
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
        value.copy< std::string > (that.value);
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
      case 58: // Args
        yylhs.value.build< Args_Node * > ();
        break;

      case 50: // CompSt
        yylhs.value.build< CompSt_Node * > ();
        break;

      case 55: // DecList
        yylhs.value.build< DecList_Node * > ();
        break;

      case 56: // Dec
        yylhs.value.build< Dec_Node * > ();
        break;

      case 53: // DefList
        yylhs.value.build< DefList_Node * > ();
        break;

      case 54: // Def
        yylhs.value.build< Def_Node * > ();
        break;

      case 57: // Exp
        yylhs.value.build< Exp_Node * > ();
        break;

      case 43: // ExtDecList
        yylhs.value.build< ExtDecList_Node * > ();
        break;

      case 41: // ExtDefList
        yylhs.value.build< ExtDefList_Node * > ();
        break;

      case 42: // ExtDef
        yylhs.value.build< ExtDef_Node * > ();
        break;

      case 47: // FunDec
        yylhs.value.build< FunDec_Node * > ();
        break;

      case 49: // ParamDec
        yylhs.value.build< ParamDec_Node * > ();
        break;

      case 40: // Program
        yylhs.value.build< Program_Node * > ();
        break;

      case 44: // Specifier
        yylhs.value.build< Specifier_Node * > ();
        break;

      case 51: // StmtList
        yylhs.value.build< StmtList_Node * > ();
        break;

      case 52: // Stmt
        yylhs.value.build< Stmt_Node * > ();
        break;

      case 45: // StructSpecifier
        yylhs.value.build< StructSpecifier_Node * > ();
        break;

      case 46: // VarDec
        yylhs.value.build< VarDec_Node * > ();
        break;

      case 48: // VarList
        yylhs.value.build< VarList_Node * > ();
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
        yylhs.value.build< std::string > ();
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
#line 127 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Program_Node * > () = new Program_Node(yystack_[0].value.as< ExtDefList_Node * > ());
  	driver.set_root(yylhs.value.as< Program_Node * > ());
  	std::cout << "Program -> (ExtDefList)" << std::endl;
  }
#line 1799 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 3:
#line 135 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< ExtDefList_Node * > () = new ExtDefList_Node(yystack_[1].value.as< ExtDef_Node * > (), yystack_[0].value.as< ExtDefList_Node * > ());
  	std::cout << "ExtDefList - > (ExtDef ExtDefList)" << std::endl;
  }
#line 1808 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 139 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< ExtDefList_Node * > () = new Empty_ExtDefList_Node();
  }
#line 1816 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 145 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< ExtDef_Node * > () = new ExtDef_Node(yystack_[2].value.as< Specifier_Node * > (), yystack_[1].value.as< ExtDecList_Node * > (), make_leaf(token::SEMI, yystack_[0].value.as< std::string > ()));
  	std::cout << "ExtDef - > (Specifier ExtDecList SEMI)" << std::endl;
  }
#line 1825 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 149 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< ExtDef_Node * > () = new ExtDef_Node(yystack_[1].value.as< Specifier_Node * > (), make_leaf(token::SEMI, yystack_[0].value.as< std::string > ()));
  	std::cout << "ExtDef - > (Specifier SEMI)" << std::endl;
  }
#line 1834 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 153 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< ExtDef_Node * > () = new ExtDef_Node(yystack_[2].value.as< Specifier_Node * > (), yystack_[1].value.as< FunDec_Node * > (), yystack_[0].value.as< CompSt_Node * > ());
  	std::cout << "ExtDef - > (Specifier FunDec CompSt)" << std::endl;
  }
#line 1843 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 160 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< ExtDecList_Node * > () = new ExtDecList_Node(yystack_[0].value.as< VarDec_Node * > ());
  	std::cout << "ExtDecList - > (VarDec)" << std::endl;
  }
#line 1852 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 164 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< ExtDecList_Node * > () = new ExtDecList_Node(yystack_[2].value.as< VarDec_Node * > (), make_leaf(token::COMMA, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< ExtDecList_Node * > ());
  	std::cout << "ExtDecList - > (VarDec COMMA ExtDecList)" << std::endl;
  }
#line 1861 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 173 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Specifier_Node * > () = new Specifier_Node(make_leaf(token::TYPE, yystack_[0].value.as< std::string > ()));
	std::cout << "Specifier - > (TYPE) " << yystack_[0].value.as< std::string > () << std::endl;
  }
#line 1870 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 177 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Specifier_Node * > () = new Specifier_Node(yystack_[0].value.as< StructSpecifier_Node * > ());
  	std::cout << "Specifier - > (StructSpecifier)" << std::endl;
  }
#line 1879 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 184 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< StructSpecifier_Node * > () = new StructSpecifier_Node(make_leaf(token::STRUCT, yystack_[4].value.as< std::string > ()),
  				      make_leaf(token::ID, yystack_[3].value.as< std::string > ()),
  				      make_leaf(token::LC, yystack_[2].value.as< std::string > ()),
  				      yystack_[1].value.as< DefList_Node * > (),
  				      make_leaf(token::ID, yystack_[0].value.as< std::string > ()));
  	std::cout << "StructSpecifier - > (STRUCT ID LC DefList RC)" << std::endl;
  }
#line 1892 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 192 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< StructSpecifier_Node * > () = new StructSpecifier_Node(make_leaf(token::STRUCT, yystack_[1].value.as< std::string > ()),
          			      make_leaf(token::ID, yystack_[0].value.as< std::string > ()));
  	std::cout << "StructSpecifier - > (STRUCT ID)" << std::endl;
  }
#line 1902 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 202 "parser.y" // lalr1.cc:859
    {
	yylhs.value.as< VarDec_Node * > () = new ID_VarDec_Node(make_leaf(token::ID, yystack_[0].value.as< std::string > ()));
  	std::cout << "VarDec - > (ID) " << yystack_[0].value.as< std::string > () << std::endl;
  }
#line 1911 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 206 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< VarDec_Node * > () = new Array_VarDec_Node(yystack_[3].value.as< VarDec_Node * > (),
			     	   make_leaf(token::LB, yystack_[2].value.as< std::string > ()),
			     	   make_leaf(token::INT, yystack_[1].value.as< std::string > ()),
			     	   make_leaf(token::ID, yystack_[0].value.as< std::string > ()));
  	std::cout << "VarDec - > (VarDec LB INT RB)" << std::endl;
  }
#line 1923 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 216 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< FunDec_Node * > () = new FunDec_Node(make_leaf(token::ID, yystack_[3].value.as< std::string > ()),
			     make_leaf(token::LP, yystack_[2].value.as< std::string > ()),
			     yystack_[1].value.as< VarList_Node * > (),
			     make_leaf(token::RP, yystack_[0].value.as< std::string > ()));
  	std::cout << "FunDec - > (ID LP VarList RP) " << yystack_[3].value.as< std::string > () << std::endl;
  }
#line 1935 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 223 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< FunDec_Node * > () = new FunDec_Node(make_leaf(token::ID, yystack_[2].value.as< std::string > ()),
			     make_leaf(token::LP, yystack_[1].value.as< std::string > ()),
			     make_leaf(token::RP, yystack_[0].value.as< std::string > ()));
  	std::cout << "FunDec - > (ID LP RP) " << yystack_[2].value.as< std::string > () << std::endl;
  }
#line 1946 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 232 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< VarList_Node * > () = new VarList_Node(yystack_[2].value.as< ParamDec_Node * > (),
			      make_leaf(token::COMMA, yystack_[1].value.as< std::string > ()),
			      yystack_[0].value.as< VarList_Node * > ());
  	std::cout << "VarList - > (ParamDec COMMA VarList)" << std::endl;
  }
#line 1957 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 238 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< VarList_Node * > () = new VarList_Node(yystack_[0].value.as< ParamDec_Node * > ());
  	std::cout << "VarList - > (ParamDec)" << std::endl;
  }
#line 1966 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 245 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< ParamDec_Node * > () = new ParamDec_Node(yystack_[1].value.as< Specifier_Node * > (), yystack_[0].value.as< VarDec_Node * > ());
  	std::cout << "ParamDec - > (Specifier VarDec)" << std::endl;
  }
#line 1975 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 254 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< CompSt_Node * > () = new CompSt_Node(make_leaf(token::LC, yystack_[3].value.as< std::string > ()),
		             yystack_[2].value.as< DefList_Node * > (),
		             yystack_[1].value.as< StmtList_Node * > (),
		             make_leaf(token::RC, yystack_[0].value.as< std::string > ()));
  	std::cout << "CompSt - > (LC DefList StmtList RC)" << std::endl;
  }
#line 1987 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 264 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< StmtList_Node * > () = new StmtList_Node(yystack_[1].value.as< Stmt_Node * > (), yystack_[0].value.as< StmtList_Node * > ());
  	std::cout << "StmtList - > (Stmt StmtList)" << std::endl;
  }
#line 1996 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 268 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< StmtList_Node * > () = new Empty_StmtList_Node();
  }
#line 2004 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 274 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Stmt_Node * > () = new Exp_Stmt_Node(yystack_[1].value.as< Exp_Node * > (),
  			       make_leaf(token::SEMI, yystack_[0].value.as< std::string > ()));
  	std::cout << "Stmt - > (Exp SEMI)" << std::endl;
  }
#line 2014 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 279 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Stmt_Node * > () = new CompSt_Stmt_Node(yystack_[0].value.as< CompSt_Node * > ());
  	std::cout << "Stmt - > (CompSt)" << std::endl;
  }
#line 2023 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 283 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Stmt_Node * > () = new Return_Stmt_Node(make_leaf(token::RETURN, yystack_[2].value.as< std::string > ()),
  			   	  yystack_[1].value.as< Exp_Node * > (),
          		   	  make_leaf(token::SEMI, yystack_[0].value.as< std::string > ()));
  	std::cout << "Stmt - > (RETURN Exp SEMI)" << std::endl;
  }
#line 2034 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 289 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Stmt_Node * > () = new If_Stmt_Node(make_leaf(token::IF, yystack_[4].value.as< std::string > ()),
  			      make_leaf(token::LP, yystack_[3].value.as< std::string > ()),
  			      yystack_[2].value.as< Exp_Node * > (),
  			      make_leaf(token::RP, yystack_[1].value.as< std::string > ()),
          		      yystack_[0].value.as< Stmt_Node * > ());
  	std::cout << "Stmt - > (IF LP Exp RP Stmt)" << std::endl;
  }
#line 2047 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 297 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Stmt_Node * > () = new If_Stmt_Node(make_leaf(token::IF, yystack_[6].value.as< std::string > ()),
  			      make_leaf(token::LP, yystack_[5].value.as< std::string > ()),
  			      yystack_[4].value.as< Exp_Node * > (),
  			      make_leaf(token::RP, yystack_[3].value.as< std::string > ()),
          		      yystack_[2].value.as< Stmt_Node * > (),
          		      make_leaf(token::ELSE, yystack_[1].value.as< std::string > ()),
          		      yystack_[0].value.as< Stmt_Node * > ());
  	std::cout << "Stmt - > (IF LP Exp RP Stmt ELSE Stmt)" << std::endl;
  }
#line 2062 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 307 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Stmt_Node * > () = new While_Stmt_Node(make_leaf(token::WHILE, yystack_[4].value.as< std::string > ()),
			         make_leaf(token::LP, yystack_[3].value.as< std::string > ()),
			         yystack_[2].value.as< Exp_Node * > (),
			         make_leaf(token::RP, yystack_[1].value.as< std::string > ()),
			         yystack_[0].value.as< Stmt_Node * > ());
  	std::cout << "Stmt - > (WHILE LP Exp RP Stmt)" << std::endl;
  }
#line 2075 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 320 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< DefList_Node * > () = new DefList_Node(yystack_[1].value.as< Def_Node * > (), yystack_[0].value.as< DefList_Node * > ());
  	std::cout << "DefList - > (Def DefList)" << std::endl;
  }
#line 2084 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 324 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< DefList_Node * > () = new Empty_DefList_Node();
  }
#line 2092 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 330 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Def_Node * > () = new Def_Node(yystack_[2].value.as< Specifier_Node * > (),
  	 		  yystack_[1].value.as< DecList_Node * > (),
  	 		  make_leaf(token::SEMI, yystack_[0].value.as< std::string > ()));
  	std::cout << "Def - > (Specifier DecList SEMI)" << std::endl;
  }
#line 2103 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 339 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< DecList_Node * > () = new DecList_Node(yystack_[0].value.as< Dec_Node * > ());
  	std::cout << "DecList - > (Dec)" << std::endl;
  }
#line 2112 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 343 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< DecList_Node * > () = new DecList_Node(yystack_[2].value.as< Dec_Node * > (),
  			      make_leaf(token::COMMA, yystack_[1].value.as< std::string > ()),
  			      yystack_[0].value.as< DecList_Node * > ());
  	std::cout << "DecList - > (Dec COMMA DecList)" << std::endl;
  }
#line 2123 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 352 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Dec_Node * > () = new Dec_Node(yystack_[0].value.as< VarDec_Node * > ());
  	std::cout << "Dec - > (VarDec)" << std::endl;
  }
#line 2132 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 356 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Dec_Node * > () = new Dec_Node(yystack_[2].value.as< VarDec_Node * > (),
  			  make_leaf(token::ASSIGN, yystack_[1].value.as< std::string > ()),
  			  yystack_[0].value.as< Exp_Node * > ());
  	std::cout << "Dec - > (VarDec ASSIGN Exp)" << std::endl;
  }
#line 2143 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 367 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Exp - > (Exp ASSIGN Exp)" << std::endl;
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::ASSIGN, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2152 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 371 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::AND, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2160 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 374 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::OR, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2168 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 377 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::LT, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2176 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 380 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::LE, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2184 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 383 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::GT, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
   }
#line 2192 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 386 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::GE, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2200 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 389 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::NE, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2208 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 392 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::EQ, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2216 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 395 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::PLUS, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2224 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 398 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::MINUS, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2232 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 401 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::MUL, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2240 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 404 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Binary_Exp_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::DIV, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2248 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 407 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Parentheses_Exp_Node(make_leaf(token::LP, yystack_[2].value.as< std::string > ()),
  				      yystack_[1].value.as< Exp_Node * > (),
  				      make_leaf(token::RP, yystack_[0].value.as< std::string > ()));
  }
#line 2258 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 412 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Unary_Exp_Node(make_leaf(token::MINUS, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2266 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 415 "parser.y" // lalr1.cc:859
    {
  	yylhs.value.as< Exp_Node * > () = new Unary_Exp_Node(make_leaf(token::NOT, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Exp_Node * > ());
  }
#line 2274 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 418 "parser.y" // lalr1.cc:859
    {
	yylhs.value.as< Exp_Node * > () = new ID_Parentheses_Exp_Node(make_leaf(token::ID, yystack_[3].value.as< std::string > ()),
				         make_leaf(token::LP, yystack_[2].value.as< std::string > ()),
				         yystack_[1].value.as< Args_Node * > (),
				         make_leaf(token::RP, yystack_[0].value.as< std::string > ()));
  }
#line 2285 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 424 "parser.y" // lalr1.cc:859
    {
	yylhs.value.as< Exp_Node * > () = new ID_Parentheses_Exp_Node(make_leaf(token::ID, yystack_[2].value.as< std::string > ()),
					 make_leaf(token::LP, yystack_[1].value.as< std::string > ()),
					 make_leaf(token::RP, yystack_[0].value.as< std::string > ()));
  }
#line 2295 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 429 "parser.y" // lalr1.cc:859
    {
	yylhs.value.as< Exp_Node * > () = new Bracket_Exp_Node(yystack_[3].value.as< Exp_Node * > (),
				  make_leaf(token::LB, yystack_[2].value.as< std::string > ()),
				  yystack_[1].value.as< Exp_Node * > (),
				  make_leaf(token::RB, yystack_[0].value.as< std::string > ()));
  }
#line 2306 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 435 "parser.y" // lalr1.cc:859
    {
	yylhs.value.as< Exp_Node * > () = new Dot_Exp_Node(yystack_[2].value.as< Exp_Node * > (),
			      make_leaf(token::DOT, yystack_[1].value.as< std::string > ()),
			      make_leaf(token::ID, yystack_[0].value.as< std::string > ()));
  }
#line 2316 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 440 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Exp - > (ID) " << yystack_[0].value.as< std::string > () << std::endl;
  	yylhs.value.as< Exp_Node * > () = new Leaf_Exp_Node(make_leaf(token::ID, yystack_[0].value.as< std::string > ()));
  }
#line 2325 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 444 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Exp - > (INT) " << yystack_[0].value.as< std::string > () << std::endl;
  	yylhs.value.as< Exp_Node * > () = new Leaf_Exp_Node(make_leaf(token::INT, yystack_[0].value.as< std::string > ()));
  }
#line 2334 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 448 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Exp - > (FLOAT) " << yystack_[0].value.as< std::string > () << std::endl;
  	yylhs.value.as< Exp_Node * > () = new Leaf_Exp_Node(make_leaf(token::FLOAT, yystack_[0].value.as< std::string > ()));
  }
#line 2343 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 452 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Exp - > (CHAR) " << yystack_[0].value.as< std::string > () << std::endl;
  	yylhs.value.as< Exp_Node * > () = new Leaf_Exp_Node(make_leaf(token::CHAR, yystack_[0].value.as< std::string > ()));
  }
#line 2352 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 459 "parser.y" // lalr1.cc:859
    {
  	std::cout << "Args - > (Exp COMMA Args) " << std::endl;
  	yylhs.value.as< Args_Node * > () = new Args_Node(yystack_[2].value.as< Exp_Node * > (), make_leaf(token::COMMA, yystack_[1].value.as< std::string > ()), yystack_[0].value.as< Args_Node * > ());
  }
#line 2361 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 463 "parser.y" // lalr1.cc:859
    {
        std::cout << "Args - > (Exp) " << std::endl;
        yylhs.value.as< Args_Node * > () = new Args_Node(yystack_[0].value.as< Exp_Node * > ());
  }
#line 2370 "parser.tab.cpp" // lalr1.cc:859
    break;


#line 2374 "parser.tab.cpp" // lalr1.cc:859
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


  const signed char SPL_Parser::yypact_ninf_ = -50;

  const signed char SPL_Parser::yytable_ninf_ = -1;

  const short int
  SPL_Parser::yypact_[] =
  {
      -2,   -50,     2,    18,   -50,    -2,    60,   -50,   -13,   -50,
     -50,    12,   -50,    30,    38,    20,    -2,     9,   -50,    50,
      59,    -2,   -50,    50,    33,    -2,   -50,    50,    40,    53,
     -50,   -50,    47,    44,    10,    79,    80,   -50,   -50,    61,
     -50,    -2,   -50,   -50,   -50,   -50,    67,    69,    87,    74,
      74,    74,    74,   -50,    85,    44,   111,    74,   -50,    50,
     -50,    34,    74,    74,   129,   222,    36,   147,   -50,   -50,
      74,   112,   -50,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,   222,   -50,   -50,   166,
      89,   184,   203,   -50,   -50,   222,   -50,   253,   253,   253,
     253,   253,   253,   222,   222,    36,    36,   240,    66,    88,
      74,   -50,    44,    44,   -50,   -50,   117,   -50,    44,   -50
  };

  const unsigned char
  SPL_Parser::yydefact_[] =
  {
       4,    10,     0,     0,     2,     4,     0,    11,    13,     1,
       3,    14,     6,     0,     8,     0,    31,     0,     5,     0,
       0,    31,     7,     0,     0,    31,    17,     0,     0,    19,
      14,     9,     0,    23,    35,     0,    33,    12,    30,    20,
      16,     0,    15,    58,    59,    60,    57,     0,     0,     0,
       0,     0,     0,    25,     0,    23,     0,     0,    32,     0,
      18,     0,     0,     0,     0,    51,    52,     0,    21,    22,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    34,    54,    62,
       0,     0,     0,    26,    50,    37,    56,    45,    41,    40,
      43,    42,    44,    46,    47,    48,    49,    38,    39,     0,
       0,    53,     0,     0,    55,    61,    27,    29,     0,    28
  };

  const short int
  SPL_Parser::yypgoto_[] =
  {
     -50,   -50,   116,   -50,   121,     5,   -50,   -16,   -50,   100,
     -50,   143,   104,   101,    -5,   -50,   103,   -50,   -49,    86
  };

  const signed char
  SPL_Parser::yydefgoto_[] =
  {
      -1,     3,     4,     5,    13,    23,     7,    14,    15,    28,
      29,    53,    54,    55,    24,    25,    35,    36,    56,    90
  };

  const unsigned char
  SPL_Parser::yytable_[] =
  {
      64,    65,    66,    67,     1,     6,     2,    34,    86,     8,
       6,    39,    89,    91,    92,     1,    33,     2,     9,    16,
      38,    95,    27,    57,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    43,    44,    45,
      26,    46,    17,    34,    20,    18,    27,    43,    44,    45,
      71,    46,    21,    47,    19,    48,    49,    30,    50,    79,
      80,    89,    32,    51,    52,    88,    37,    11,    50,    41,
      85,    40,    20,    51,    52,    12,    21,    43,    44,    45,
      71,    46,    42,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    58,    20,    59,    61,    50,    62,
      85,    70,    71,    51,    52,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    63,    68,    96,
     111,    10,    85,   114,    70,    71,    72,   118,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      31,    60,    70,    71,    93,    85,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    22,    69,
      70,    71,    87,    85,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,    94,    70,
      71,    85,   110,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,   115,    70,    71,     0,
      85,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,   116,   117,   112,    70,    71,    85,   119,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,     0,   113,    70,    71,    85,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,    71,     0,    85,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    71,     0,     0,
       0,     0,     0,     0,    85,     0,    79,    80,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    85
  };

  const signed char
  SPL_Parser::yycheck_[] =
  {
      49,    50,    51,    52,     6,     0,     8,    23,    57,     7,
       5,    27,    61,    62,    63,     6,    21,     8,     0,    32,
      25,    70,    17,    13,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     3,     4,     5,
      31,     7,    30,    59,    34,    15,    41,     3,     4,     5,
      14,     7,    32,     9,    16,    11,    12,     7,    24,    23,
      24,   110,     3,    29,    30,    31,    33,     7,    24,    16,
      34,    31,    34,    29,    30,    15,    32,     3,     4,     5,
      14,     7,    35,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    15,    34,    16,    30,    24,    30,
      34,    13,    14,    29,    30,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    30,    33,     7,
      31,     5,    34,    35,    13,    14,    15,    10,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      19,    41,    13,    14,    15,    34,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    15,    55,
      13,    14,    59,    34,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    13,
      14,    34,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,   110,    13,    14,    -1,
      34,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   112,   113,    31,    13,    14,    34,   118,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    13,    14,    34,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    14,    -1,    34,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34
  };

  const unsigned char
  SPL_Parser::yystos_[] =
  {
       0,     6,     8,    40,    41,    42,    44,    45,     7,     0,
      41,     7,    15,    43,    46,    47,    32,    30,    15,    16,
      34,    32,    50,    44,    53,    54,    31,    44,    48,    49,
       7,    43,     3,    53,    46,    55,    56,    33,    53,    46,
      31,    16,    35,     3,     4,     5,     7,     9,    11,    12,
      24,    29,    30,    50,    51,    52,    57,    13,    15,    16,
      48,    30,    30,    30,    57,    57,    57,    57,    33,    51,
      13,    14,    15,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    34,    57,    55,    31,    57,
      58,    57,    57,    15,    31,    57,     7,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      16,    31,    31,    31,    35,    58,    52,    52,    10,    52
  };

  const unsigned char
  SPL_Parser::yyr1_[] =
  {
       0,    39,    40,    41,    41,    42,    42,    42,    43,    43,
      44,    44,    45,    45,    46,    46,    47,    47,    48,    48,
      49,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      53,    53,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    58,    58
  };

  const unsigned char
  SPL_Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     3,     2,     3,     1,     3,
       1,     1,     5,     2,     1,     4,     4,     3,     3,     1,
       2,     4,     2,     0,     2,     1,     3,     5,     7,     5,
       2,     0,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     4,     3,     4,     3,     1,     1,     1,
       1,     3,     1
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
  "LINE_COMMENT", "ADD", "SUB", "$accept", "Program", "ExtDefList",
  "ExtDef", "ExtDecList", "Specifier", "StructSpecifier", "VarDec",
  "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList",
  "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
  };


  const unsigned short int
  SPL_Parser::yyrline_[] =
  {
       0,   127,   127,   135,   139,   145,   149,   153,   160,   164,
     173,   177,   184,   192,   202,   206,   216,   223,   232,   238,
     245,   254,   264,   268,   274,   279,   283,   289,   297,   307,
     320,   324,   330,   339,   343,   352,   356,   367,   371,   374,
     377,   380,   383,   386,   389,   392,   395,   398,   401,   404,
     407,   412,   415,   418,   424,   429,   435,   440,   444,   448,
     452,   459,   463
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
      35,    36,    37,    38
    };
    const unsigned int user_token_number_max_ = 293;
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
#line 2813 "parser.tab.cpp" // lalr1.cc:1167
#line 469 "parser.y" // lalr1.cc:1168


void SPL::SPL_Parser::error(const location_type &l, const std::string &err_message){
    std::cerr << "Error: " << err_message << " at " << l << std::endl;
}
