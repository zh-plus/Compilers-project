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
#line 28 "parser.y" // lalr1.cc:413

    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    #include <string>

/* include for all driver functions */
#include "spl_driver.hpp"

#undef yylex
#define yylex scanner.yylex


#line 67 "parser.tab.cpp" // lalr1.cc:413


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
#line 153 "parser.tab.cpp" // lalr1.cc:479

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
      case 4: // FLOAT
        value.copy< float > (other.value);
        break;

      case 3: // INT
      case 8: // DOT
      case 9: // SEMI
      case 10: // COMMA
      case 11: // ASSIGN
      case 12: // EQ
      case 13: // LE
      case 14: // LT
      case 15: // GE
      case 16: // GT
      case 17: // NE
      case 18: // ADD
      case 19: // MINUS
      case 20: // MUL
      case 21: // DIV
      case 22: // AND
      case 23: // OR
      case 24: // NOT
      case 25: // LP
      case 26: // RP
      case 27: // LC
      case 28: // RC
      case 29: // LB
      case 30: // RB
        value.copy< int > (other.value);
        break;

      case 5: // TYPE
      case 6: // KEYWORD
      case 7: // ID
      case 31: // LINE_COMMENT
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
      case 4: // FLOAT
        value.copy< float > (v);
        break;

      case 3: // INT
      case 8: // DOT
      case 9: // SEMI
      case 10: // COMMA
      case 11: // ASSIGN
      case 12: // EQ
      case 13: // LE
      case 14: // LT
      case 15: // GE
      case 16: // GT
      case 17: // NE
      case 18: // ADD
      case 19: // MINUS
      case 20: // MUL
      case 21: // DIV
      case 22: // AND
      case 23: // OR
      case 24: // NOT
      case 25: // LP
      case 26: // RP
      case 27: // LC
      case 28: // RC
      case 29: // LB
      case 30: // RB
        value.copy< int > (v);
        break;

      case 5: // TYPE
      case 6: // KEYWORD
      case 7: // ID
      case 31: // LINE_COMMENT
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
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const float v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  SPL_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
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
      case 4: // FLOAT
        value.template destroy< float > ();
        break;

      case 3: // INT
      case 8: // DOT
      case 9: // SEMI
      case 10: // COMMA
      case 11: // ASSIGN
      case 12: // EQ
      case 13: // LE
      case 14: // LT
      case 15: // GE
      case 16: // GT
      case 17: // NE
      case 18: // ADD
      case 19: // MINUS
      case 20: // MUL
      case 21: // DIV
      case 22: // AND
      case 23: // OR
      case 24: // NOT
      case 25: // LP
      case 26: // RP
      case 27: // LC
      case 28: // RC
      case 29: // LB
      case 30: // RB
        value.template destroy< int > ();
        break;

      case 5: // TYPE
      case 6: // KEYWORD
      case 7: // ID
      case 31: // LINE_COMMENT
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
      case 4: // FLOAT
        value.move< float > (s.value);
        break;

      case 3: // INT
      case 8: // DOT
      case 9: // SEMI
      case 10: // COMMA
      case 11: // ASSIGN
      case 12: // EQ
      case 13: // LE
      case 14: // LT
      case 15: // GE
      case 16: // GT
      case 17: // NE
      case 18: // ADD
      case 19: // MINUS
      case 20: // MUL
      case 21: // DIV
      case 22: // AND
      case 23: // OR
      case 24: // NOT
      case 25: // LP
      case 26: // RP
      case 27: // LC
      case 28: // RC
      case 29: // LB
      case 30: // RB
        value.move< int > (s.value);
        break;

      case 5: // TYPE
      case 6: // KEYWORD
      case 7: // ID
      case 31: // LINE_COMMENT
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
  SPL_Parser::make_INT (const int& v, const location_type& l)
  {
    return symbol_type (token::INT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_FLOAT (const float& v, const location_type& l)
  {
    return symbol_type (token::FLOAT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_TYPE (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TYPE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_KEYWORD (const std::string& v, const location_type& l)
  {
    return symbol_type (token::KEYWORD, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_ID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::ID, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_DOT (const int& v, const location_type& l)
  {
    return symbol_type (token::DOT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_SEMI (const int& v, const location_type& l)
  {
    return symbol_type (token::SEMI, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_COMMA (const int& v, const location_type& l)
  {
    return symbol_type (token::COMMA, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_ASSIGN (const int& v, const location_type& l)
  {
    return symbol_type (token::ASSIGN, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_EQ (const int& v, const location_type& l)
  {
    return symbol_type (token::EQ, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LE (const int& v, const location_type& l)
  {
    return symbol_type (token::LE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LT (const int& v, const location_type& l)
  {
    return symbol_type (token::LT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_GE (const int& v, const location_type& l)
  {
    return symbol_type (token::GE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_GT (const int& v, const location_type& l)
  {
    return symbol_type (token::GT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_NE (const int& v, const location_type& l)
  {
    return symbol_type (token::NE, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_ADD (const int& v, const location_type& l)
  {
    return symbol_type (token::ADD, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_MINUS (const int& v, const location_type& l)
  {
    return symbol_type (token::MINUS, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_MUL (const int& v, const location_type& l)
  {
    return symbol_type (token::MUL, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_DIV (const int& v, const location_type& l)
  {
    return symbol_type (token::DIV, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_AND (const int& v, const location_type& l)
  {
    return symbol_type (token::AND, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_OR (const int& v, const location_type& l)
  {
    return symbol_type (token::OR, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_NOT (const int& v, const location_type& l)
  {
    return symbol_type (token::NOT, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LP (const int& v, const location_type& l)
  {
    return symbol_type (token::LP, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_RP (const int& v, const location_type& l)
  {
    return symbol_type (token::RP, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LC (const int& v, const location_type& l)
  {
    return symbol_type (token::LC, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_RC (const int& v, const location_type& l)
  {
    return symbol_type (token::RC, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LB (const int& v, const location_type& l)
  {
    return symbol_type (token::LB, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_RB (const int& v, const location_type& l)
  {
    return symbol_type (token::RB, v, l);
  }

  SPL_Parser::symbol_type
  SPL_Parser::make_LINE_COMMENT (const std::string& v, const location_type& l)
  {
    return symbol_type (token::LINE_COMMENT, v, l);
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
      case 4: // FLOAT
        value.move< float > (that.value);
        break;

      case 3: // INT
      case 8: // DOT
      case 9: // SEMI
      case 10: // COMMA
      case 11: // ASSIGN
      case 12: // EQ
      case 13: // LE
      case 14: // LT
      case 15: // GE
      case 16: // GT
      case 17: // NE
      case 18: // ADD
      case 19: // MINUS
      case 20: // MUL
      case 21: // DIV
      case 22: // AND
      case 23: // OR
      case 24: // NOT
      case 25: // LP
      case 26: // RP
      case 27: // LC
      case 28: // RC
      case 29: // LB
      case 30: // RB
        value.move< int > (that.value);
        break;

      case 5: // TYPE
      case 6: // KEYWORD
      case 7: // ID
      case 31: // LINE_COMMENT
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
      case 4: // FLOAT
        value.copy< float > (that.value);
        break;

      case 3: // INT
      case 8: // DOT
      case 9: // SEMI
      case 10: // COMMA
      case 11: // ASSIGN
      case 12: // EQ
      case 13: // LE
      case 14: // LT
      case 15: // GE
      case 16: // GT
      case 17: // NE
      case 18: // ADD
      case 19: // MINUS
      case 20: // MUL
      case 21: // DIV
      case 22: // AND
      case 23: // OR
      case 24: // NOT
      case 25: // LP
      case 26: // RP
      case 27: // LC
      case 28: // RC
      case 29: // LB
      case 30: // RB
        value.copy< int > (that.value);
        break;

      case 5: // TYPE
      case 6: // KEYWORD
      case 7: // ID
      case 31: // LINE_COMMENT
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
      case 4: // FLOAT
        yylhs.value.build< float > ();
        break;

      case 3: // INT
      case 8: // DOT
      case 9: // SEMI
      case 10: // COMMA
      case 11: // ASSIGN
      case 12: // EQ
      case 13: // LE
      case 14: // LT
      case 15: // GE
      case 16: // GT
      case 17: // NE
      case 18: // ADD
      case 19: // MINUS
      case 20: // MUL
      case 21: // DIV
      case 22: // AND
      case 23: // OR
      case 24: // NOT
      case 25: // LP
      case 26: // RP
      case 27: // LC
      case 28: // RC
      case 29: // LB
      case 30: // RB
        yylhs.value.build< int > ();
        break;

      case 5: // TYPE
      case 6: // KEYWORD
      case 7: // ID
      case 31: // LINE_COMMENT
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
  case 6:
#line 70 "parser.y" // lalr1.cc:859
    { driver.scan_int(yystack_[0].value.as< int > ()); }
#line 1105 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 71 "parser.y" // lalr1.cc:859
    { driver.scan_float(yystack_[0].value.as< float > ()); }
#line 1111 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 72 "parser.y" // lalr1.cc:859
    { driver.scan_type(yystack_[0].value.as< std::string > ()); }
#line 1117 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 73 "parser.y" // lalr1.cc:859
    { driver.scan_keyword(yystack_[0].value.as< std::string > ()); }
#line 1123 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 74 "parser.y" // lalr1.cc:859
    { driver.scan_id(yystack_[0].value.as< std::string > ()); }
#line 1129 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 75 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1135 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 76 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1141 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 77 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1147 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 78 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1153 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 79 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1159 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 80 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1165 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 81 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1171 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 82 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1177 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 83 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1183 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 84 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1189 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 85 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1195 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 86 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1201 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 87 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1207 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 88 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1213 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 89 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1219 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 90 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1225 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 91 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1231 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 92 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1237 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 93 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1243 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 94 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1249 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 95 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1255 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 96 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1261 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 97 "parser.y" // lalr1.cc:859
    { driver.scan_symbol(yystack_[0].value.as< int > ()); }
#line 1267 "parser.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 98 "parser.y" // lalr1.cc:859
    { driver.scan_line_comment(yystack_[0].value.as< std::string > ()); }
#line 1273 "parser.tab.cpp" // lalr1.cc:859
    break;


#line 1277 "parser.tab.cpp" // lalr1.cc:859
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


  const signed char SPL_Parser::yypact_ninf_ = -31;

  const signed char SPL_Parser::yytable_ninf_ = -1;

  const signed char
  SPL_Parser::yypact_[] =
  {
       0,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,     1,    32,   -31,   -31,   -31,   -31
  };

  const unsigned char
  SPL_Parser::yydefact_[] =
  {
       0,     2,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,     0,     4,     1,     3,     5
  };

  const signed char
  SPL_Parser::yypgoto_[] =
  {
     -31,   -31,   -31,   -30
  };

  const signed char
  SPL_Parser::yydefgoto_[] =
  {
      -1,    31,    32,    33
  };

  const unsigned char
  SPL_Parser::yytable_[] =
  {
       1,    34,    36,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    35,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30
  };

  const signed char
  SPL_Parser::yycheck_[] =
  {
       0,     0,    32,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31
  };

  const unsigned char
  SPL_Parser::yystos_[] =
  {
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    33,    34,    35,     0,     0,    35
  };

  const unsigned char
  SPL_Parser::yyr1_[] =
  {
       0,    32,    33,    33,    34,    34,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35
  };

  const unsigned char
  SPL_Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const SPL_Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "INT", "FLOAT", "TYPE",
  "KEYWORD", "ID", "DOT", "SEMI", "COMMA", "ASSIGN", "EQ", "LE", "LT",
  "GE", "GT", "NE", "ADD", "MINUS", "MUL", "DIV", "AND", "OR", "NOT", "LP",
  "RP", "LC", "RC", "LB", "RB", "LINE_COMMENT", "$accept", "list_option",
  "list", "item", YY_NULLPTR
  };


  const unsigned char
  SPL_Parser::yyrline_[] =
  {
       0,    62,    62,    62,    65,    66,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98
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
      25,    26,    27,    28,    29,    30,    31
    };
    const unsigned int user_token_number_max_ = 286;
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
#line 1633 "parser.tab.cpp" // lalr1.cc:1167
#line 101 "parser.y" // lalr1.cc:1168


void SPL::SPL_Parser::error(const location_type &l, const std::string &err_message){
    std::cerr << "Error: " << err_message << " at " << l << std::endl;
}
