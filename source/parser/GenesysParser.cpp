// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "GenesysParser.h"


// Unqualified %code blocks.
#line 62 "bisonparser.yy"

# include "Genesys++-driver.h"


#line 51 "../GenesysParser.cpp"


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


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
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
    while (false)
# endif


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
      *yycdebug_ << '\n';                       \
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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 143 "../GenesysParser.cpp"

  /// Build a parser object.
  genesyspp_parser::genesyspp_parser (genesyspp_driver& driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  genesyspp_parser::~genesyspp_parser ()
  {}

  genesyspp_parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  genesyspp_parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  genesyspp_parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  genesyspp_parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  genesyspp_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  genesyspp_parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  genesyspp_parser::symbol_kind_type
  genesyspp_parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  genesyspp_parser::stack_symbol_type::stack_symbol_type ()
  {}

  genesyspp_parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMD: // NUMD
      case symbol_kind::S_NUMH: // NUMH
      case symbol_kind::S_CTEZERO: // CTEZERO
      case symbol_kind::S_oLE: // oLE
      case symbol_kind::S_oGE: // oGE
      case symbol_kind::S_oEQ: // oEQ
      case symbol_kind::S_oNE: // oNE
      case symbol_kind::S_oAND: // oAND
      case symbol_kind::S_oOR: // oOR
      case symbol_kind::S_oNAND: // oNAND
      case symbol_kind::S_oXOR: // oXOR
      case symbol_kind::S_oNOT: // oNOT
      case symbol_kind::S_fSIN: // fSIN
      case symbol_kind::S_fCOS: // fCOS
      case symbol_kind::S_fROUND: // fROUND
      case symbol_kind::S_fMOD: // fMOD
      case symbol_kind::S_fTRUNC: // fTRUNC
      case symbol_kind::S_fFRAC: // fFRAC
      case symbol_kind::S_fEXP: // fEXP
      case symbol_kind::S_fSQRT: // fSQRT
      case symbol_kind::S_fLOG: // fLOG
      case symbol_kind::S_fLN: // fLN
      case symbol_kind::S_mathMIN: // mathMIN
      case symbol_kind::S_mathMAX: // mathMAX
      case symbol_kind::S_fVAL: // fVAL
      case symbol_kind::S_fEVAL: // fEVAL
      case symbol_kind::S_fLENG: // fLENG
      case symbol_kind::S_fRND1: // fRND1
      case symbol_kind::S_fEXPO: // fEXPO
      case symbol_kind::S_fNORM: // fNORM
      case symbol_kind::S_fUNIF: // fUNIF
      case symbol_kind::S_fWEIB: // fWEIB
      case symbol_kind::S_fLOGN: // fLOGN
      case symbol_kind::S_fGAMM: // fGAMM
      case symbol_kind::S_fERLA: // fERLA
      case symbol_kind::S_fTRIA: // fTRIA
      case symbol_kind::S_fBETA: // fBETA
      case symbol_kind::S_fDISC: // fDISC
      case symbol_kind::S_fTNOW: // fTNOW
      case symbol_kind::S_fTFIN: // fTFIN
      case symbol_kind::S_fMAXREP: // fMAXREP
      case symbol_kind::S_fNUMREP: // fNUMREP
      case symbol_kind::S_fIDENT: // fIDENT
      case symbol_kind::S_simulEntitiesWIP: // simulEntitiesWIP
      case symbol_kind::S_cIF: // cIF
      case symbol_kind::S_cELSE: // cELSE
      case symbol_kind::S_cFOR: // cFOR
      case symbol_kind::S_cTO: // cTO
      case symbol_kind::S_cDO: // cDO
      case symbol_kind::S_ATRIB: // ATRIB
      case symbol_kind::S_CSTAT: // CSTAT
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_fCOUNT: // fCOUNT
      case symbol_kind::S_ILLEGAL: // ILLEGAL
      case symbol_kind::S_RESOURCE: // RESOURCE
      case symbol_kind::S_fNR: // fNR
      case symbol_kind::S_fMR: // fMR
      case symbol_kind::S_fIRF: // fIRF
      case symbol_kind::S_fRESSEIZES: // fRESSEIZES
      case symbol_kind::S_fSTATE: // fSTATE
      case symbol_kind::S_fSETSUM: // fSETSUM
      case symbol_kind::S_fRESUTIL: // fRESUTIL
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_fENTATRANK: // fENTATRANK
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_fNUMGR: // fNUMGR
      case symbol_kind::S_fATRGR: // fATRGR
      case symbol_kind::S_input: // input
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_number: // number
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_logical: // logical
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_command: // command
      case symbol_kind::S_commandIF: // commandIF
      case symbol_kind::S_commandFOR: // commandFOR
      case symbol_kind::S_function: // function
      case symbol_kind::S_kernelFunction: // kernelFunction
      case symbol_kind::S_elementFunction: // elementFunction
      case symbol_kind::S_trigonFunction: // trigonFunction
      case symbol_kind::S_mathFunction: // mathFunction
      case symbol_kind::S_probFunction: // probFunction
      case symbol_kind::S_userFunction: // userFunction
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_attribute: // attribute
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_assigment: // assigment
      case symbol_kind::S_pluginFunction: // pluginFunction
        value.YY_MOVE_OR_COPY< obj_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  genesyspp_parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMD: // NUMD
      case symbol_kind::S_NUMH: // NUMH
      case symbol_kind::S_CTEZERO: // CTEZERO
      case symbol_kind::S_oLE: // oLE
      case symbol_kind::S_oGE: // oGE
      case symbol_kind::S_oEQ: // oEQ
      case symbol_kind::S_oNE: // oNE
      case symbol_kind::S_oAND: // oAND
      case symbol_kind::S_oOR: // oOR
      case symbol_kind::S_oNAND: // oNAND
      case symbol_kind::S_oXOR: // oXOR
      case symbol_kind::S_oNOT: // oNOT
      case symbol_kind::S_fSIN: // fSIN
      case symbol_kind::S_fCOS: // fCOS
      case symbol_kind::S_fROUND: // fROUND
      case symbol_kind::S_fMOD: // fMOD
      case symbol_kind::S_fTRUNC: // fTRUNC
      case symbol_kind::S_fFRAC: // fFRAC
      case symbol_kind::S_fEXP: // fEXP
      case symbol_kind::S_fSQRT: // fSQRT
      case symbol_kind::S_fLOG: // fLOG
      case symbol_kind::S_fLN: // fLN
      case symbol_kind::S_mathMIN: // mathMIN
      case symbol_kind::S_mathMAX: // mathMAX
      case symbol_kind::S_fVAL: // fVAL
      case symbol_kind::S_fEVAL: // fEVAL
      case symbol_kind::S_fLENG: // fLENG
      case symbol_kind::S_fRND1: // fRND1
      case symbol_kind::S_fEXPO: // fEXPO
      case symbol_kind::S_fNORM: // fNORM
      case symbol_kind::S_fUNIF: // fUNIF
      case symbol_kind::S_fWEIB: // fWEIB
      case symbol_kind::S_fLOGN: // fLOGN
      case symbol_kind::S_fGAMM: // fGAMM
      case symbol_kind::S_fERLA: // fERLA
      case symbol_kind::S_fTRIA: // fTRIA
      case symbol_kind::S_fBETA: // fBETA
      case symbol_kind::S_fDISC: // fDISC
      case symbol_kind::S_fTNOW: // fTNOW
      case symbol_kind::S_fTFIN: // fTFIN
      case symbol_kind::S_fMAXREP: // fMAXREP
      case symbol_kind::S_fNUMREP: // fNUMREP
      case symbol_kind::S_fIDENT: // fIDENT
      case symbol_kind::S_simulEntitiesWIP: // simulEntitiesWIP
      case symbol_kind::S_cIF: // cIF
      case symbol_kind::S_cELSE: // cELSE
      case symbol_kind::S_cFOR: // cFOR
      case symbol_kind::S_cTO: // cTO
      case symbol_kind::S_cDO: // cDO
      case symbol_kind::S_ATRIB: // ATRIB
      case symbol_kind::S_CSTAT: // CSTAT
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_fCOUNT: // fCOUNT
      case symbol_kind::S_ILLEGAL: // ILLEGAL
      case symbol_kind::S_RESOURCE: // RESOURCE
      case symbol_kind::S_fNR: // fNR
      case symbol_kind::S_fMR: // fMR
      case symbol_kind::S_fIRF: // fIRF
      case symbol_kind::S_fRESSEIZES: // fRESSEIZES
      case symbol_kind::S_fSTATE: // fSTATE
      case symbol_kind::S_fSETSUM: // fSETSUM
      case symbol_kind::S_fRESUTIL: // fRESUTIL
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_fENTATRANK: // fENTATRANK
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_fNUMGR: // fNUMGR
      case symbol_kind::S_fATRGR: // fATRGR
      case symbol_kind::S_input: // input
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_number: // number
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_logical: // logical
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_command: // command
      case symbol_kind::S_commandIF: // commandIF
      case symbol_kind::S_commandFOR: // commandFOR
      case symbol_kind::S_function: // function
      case symbol_kind::S_kernelFunction: // kernelFunction
      case symbol_kind::S_elementFunction: // elementFunction
      case symbol_kind::S_trigonFunction: // trigonFunction
      case symbol_kind::S_mathFunction: // mathFunction
      case symbol_kind::S_probFunction: // probFunction
      case symbol_kind::S_userFunction: // userFunction
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_attribute: // attribute
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_assigment: // assigment
      case symbol_kind::S_pluginFunction: // pluginFunction
        value.move< obj_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  genesyspp_parser::stack_symbol_type&
  genesyspp_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMD: // NUMD
      case symbol_kind::S_NUMH: // NUMH
      case symbol_kind::S_CTEZERO: // CTEZERO
      case symbol_kind::S_oLE: // oLE
      case symbol_kind::S_oGE: // oGE
      case symbol_kind::S_oEQ: // oEQ
      case symbol_kind::S_oNE: // oNE
      case symbol_kind::S_oAND: // oAND
      case symbol_kind::S_oOR: // oOR
      case symbol_kind::S_oNAND: // oNAND
      case symbol_kind::S_oXOR: // oXOR
      case symbol_kind::S_oNOT: // oNOT
      case symbol_kind::S_fSIN: // fSIN
      case symbol_kind::S_fCOS: // fCOS
      case symbol_kind::S_fROUND: // fROUND
      case symbol_kind::S_fMOD: // fMOD
      case symbol_kind::S_fTRUNC: // fTRUNC
      case symbol_kind::S_fFRAC: // fFRAC
      case symbol_kind::S_fEXP: // fEXP
      case symbol_kind::S_fSQRT: // fSQRT
      case symbol_kind::S_fLOG: // fLOG
      case symbol_kind::S_fLN: // fLN
      case symbol_kind::S_mathMIN: // mathMIN
      case symbol_kind::S_mathMAX: // mathMAX
      case symbol_kind::S_fVAL: // fVAL
      case symbol_kind::S_fEVAL: // fEVAL
      case symbol_kind::S_fLENG: // fLENG
      case symbol_kind::S_fRND1: // fRND1
      case symbol_kind::S_fEXPO: // fEXPO
      case symbol_kind::S_fNORM: // fNORM
      case symbol_kind::S_fUNIF: // fUNIF
      case symbol_kind::S_fWEIB: // fWEIB
      case symbol_kind::S_fLOGN: // fLOGN
      case symbol_kind::S_fGAMM: // fGAMM
      case symbol_kind::S_fERLA: // fERLA
      case symbol_kind::S_fTRIA: // fTRIA
      case symbol_kind::S_fBETA: // fBETA
      case symbol_kind::S_fDISC: // fDISC
      case symbol_kind::S_fTNOW: // fTNOW
      case symbol_kind::S_fTFIN: // fTFIN
      case symbol_kind::S_fMAXREP: // fMAXREP
      case symbol_kind::S_fNUMREP: // fNUMREP
      case symbol_kind::S_fIDENT: // fIDENT
      case symbol_kind::S_simulEntitiesWIP: // simulEntitiesWIP
      case symbol_kind::S_cIF: // cIF
      case symbol_kind::S_cELSE: // cELSE
      case symbol_kind::S_cFOR: // cFOR
      case symbol_kind::S_cTO: // cTO
      case symbol_kind::S_cDO: // cDO
      case symbol_kind::S_ATRIB: // ATRIB
      case symbol_kind::S_CSTAT: // CSTAT
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_fCOUNT: // fCOUNT
      case symbol_kind::S_ILLEGAL: // ILLEGAL
      case symbol_kind::S_RESOURCE: // RESOURCE
      case symbol_kind::S_fNR: // fNR
      case symbol_kind::S_fMR: // fMR
      case symbol_kind::S_fIRF: // fIRF
      case symbol_kind::S_fRESSEIZES: // fRESSEIZES
      case symbol_kind::S_fSTATE: // fSTATE
      case symbol_kind::S_fSETSUM: // fSETSUM
      case symbol_kind::S_fRESUTIL: // fRESUTIL
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_fENTATRANK: // fENTATRANK
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_fNUMGR: // fNUMGR
      case symbol_kind::S_fATRGR: // fATRGR
      case symbol_kind::S_input: // input
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_number: // number
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_logical: // logical
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_command: // command
      case symbol_kind::S_commandIF: // commandIF
      case symbol_kind::S_commandFOR: // commandFOR
      case symbol_kind::S_function: // function
      case symbol_kind::S_kernelFunction: // kernelFunction
      case symbol_kind::S_elementFunction: // elementFunction
      case symbol_kind::S_trigonFunction: // trigonFunction
      case symbol_kind::S_mathFunction: // mathFunction
      case symbol_kind::S_probFunction: // probFunction
      case symbol_kind::S_userFunction: // userFunction
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_attribute: // attribute
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_assigment: // assigment
      case symbol_kind::S_pluginFunction: // pluginFunction
        value.copy< obj_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  genesyspp_parser::stack_symbol_type&
  genesyspp_parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMD: // NUMD
      case symbol_kind::S_NUMH: // NUMH
      case symbol_kind::S_CTEZERO: // CTEZERO
      case symbol_kind::S_oLE: // oLE
      case symbol_kind::S_oGE: // oGE
      case symbol_kind::S_oEQ: // oEQ
      case symbol_kind::S_oNE: // oNE
      case symbol_kind::S_oAND: // oAND
      case symbol_kind::S_oOR: // oOR
      case symbol_kind::S_oNAND: // oNAND
      case symbol_kind::S_oXOR: // oXOR
      case symbol_kind::S_oNOT: // oNOT
      case symbol_kind::S_fSIN: // fSIN
      case symbol_kind::S_fCOS: // fCOS
      case symbol_kind::S_fROUND: // fROUND
      case symbol_kind::S_fMOD: // fMOD
      case symbol_kind::S_fTRUNC: // fTRUNC
      case symbol_kind::S_fFRAC: // fFRAC
      case symbol_kind::S_fEXP: // fEXP
      case symbol_kind::S_fSQRT: // fSQRT
      case symbol_kind::S_fLOG: // fLOG
      case symbol_kind::S_fLN: // fLN
      case symbol_kind::S_mathMIN: // mathMIN
      case symbol_kind::S_mathMAX: // mathMAX
      case symbol_kind::S_fVAL: // fVAL
      case symbol_kind::S_fEVAL: // fEVAL
      case symbol_kind::S_fLENG: // fLENG
      case symbol_kind::S_fRND1: // fRND1
      case symbol_kind::S_fEXPO: // fEXPO
      case symbol_kind::S_fNORM: // fNORM
      case symbol_kind::S_fUNIF: // fUNIF
      case symbol_kind::S_fWEIB: // fWEIB
      case symbol_kind::S_fLOGN: // fLOGN
      case symbol_kind::S_fGAMM: // fGAMM
      case symbol_kind::S_fERLA: // fERLA
      case symbol_kind::S_fTRIA: // fTRIA
      case symbol_kind::S_fBETA: // fBETA
      case symbol_kind::S_fDISC: // fDISC
      case symbol_kind::S_fTNOW: // fTNOW
      case symbol_kind::S_fTFIN: // fTFIN
      case symbol_kind::S_fMAXREP: // fMAXREP
      case symbol_kind::S_fNUMREP: // fNUMREP
      case symbol_kind::S_fIDENT: // fIDENT
      case symbol_kind::S_simulEntitiesWIP: // simulEntitiesWIP
      case symbol_kind::S_cIF: // cIF
      case symbol_kind::S_cELSE: // cELSE
      case symbol_kind::S_cFOR: // cFOR
      case symbol_kind::S_cTO: // cTO
      case symbol_kind::S_cDO: // cDO
      case symbol_kind::S_ATRIB: // ATRIB
      case symbol_kind::S_CSTAT: // CSTAT
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_fCOUNT: // fCOUNT
      case symbol_kind::S_ILLEGAL: // ILLEGAL
      case symbol_kind::S_RESOURCE: // RESOURCE
      case symbol_kind::S_fNR: // fNR
      case symbol_kind::S_fMR: // fMR
      case symbol_kind::S_fIRF: // fIRF
      case symbol_kind::S_fRESSEIZES: // fRESSEIZES
      case symbol_kind::S_fSTATE: // fSTATE
      case symbol_kind::S_fSETSUM: // fSETSUM
      case symbol_kind::S_fRESUTIL: // fRESUTIL
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_fENTATRANK: // fENTATRANK
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_fNUMGR: // fNUMGR
      case symbol_kind::S_fATRGR: // fATRGR
      case symbol_kind::S_input: // input
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_number: // number
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_logical: // logical
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_command: // command
      case symbol_kind::S_commandIF: // commandIF
      case symbol_kind::S_commandFOR: // commandFOR
      case symbol_kind::S_function: // function
      case symbol_kind::S_kernelFunction: // kernelFunction
      case symbol_kind::S_elementFunction: // elementFunction
      case symbol_kind::S_trigonFunction: // trigonFunction
      case symbol_kind::S_mathFunction: // mathFunction
      case symbol_kind::S_probFunction: // probFunction
      case symbol_kind::S_userFunction: // userFunction
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_attribute: // attribute
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_assigment: // assigment
      case symbol_kind::S_pluginFunction: // pluginFunction
        value.move< obj_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  genesyspp_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  genesyspp_parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  genesyspp_parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  genesyspp_parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  genesyspp_parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  genesyspp_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  genesyspp_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  genesyspp_parser::debug_level_type
  genesyspp_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  genesyspp_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  genesyspp_parser::state_type
  genesyspp_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  genesyspp_parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  genesyspp_parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  genesyspp_parser::operator() ()
  {
    return parse ();
  }

  int
  genesyspp_parser::parse ()
  {
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

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 55 "bisonparser.yy"
{
  // Initialize the initial location.
  //@$.begin.filename = @$.end.filename = &driver.getFile();
}

#line 813 "../GenesysParser.cpp"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_NUMD: // NUMD
      case symbol_kind::S_NUMH: // NUMH
      case symbol_kind::S_CTEZERO: // CTEZERO
      case symbol_kind::S_oLE: // oLE
      case symbol_kind::S_oGE: // oGE
      case symbol_kind::S_oEQ: // oEQ
      case symbol_kind::S_oNE: // oNE
      case symbol_kind::S_oAND: // oAND
      case symbol_kind::S_oOR: // oOR
      case symbol_kind::S_oNAND: // oNAND
      case symbol_kind::S_oXOR: // oXOR
      case symbol_kind::S_oNOT: // oNOT
      case symbol_kind::S_fSIN: // fSIN
      case symbol_kind::S_fCOS: // fCOS
      case symbol_kind::S_fROUND: // fROUND
      case symbol_kind::S_fMOD: // fMOD
      case symbol_kind::S_fTRUNC: // fTRUNC
      case symbol_kind::S_fFRAC: // fFRAC
      case symbol_kind::S_fEXP: // fEXP
      case symbol_kind::S_fSQRT: // fSQRT
      case symbol_kind::S_fLOG: // fLOG
      case symbol_kind::S_fLN: // fLN
      case symbol_kind::S_mathMIN: // mathMIN
      case symbol_kind::S_mathMAX: // mathMAX
      case symbol_kind::S_fVAL: // fVAL
      case symbol_kind::S_fEVAL: // fEVAL
      case symbol_kind::S_fLENG: // fLENG
      case symbol_kind::S_fRND1: // fRND1
      case symbol_kind::S_fEXPO: // fEXPO
      case symbol_kind::S_fNORM: // fNORM
      case symbol_kind::S_fUNIF: // fUNIF
      case symbol_kind::S_fWEIB: // fWEIB
      case symbol_kind::S_fLOGN: // fLOGN
      case symbol_kind::S_fGAMM: // fGAMM
      case symbol_kind::S_fERLA: // fERLA
      case symbol_kind::S_fTRIA: // fTRIA
      case symbol_kind::S_fBETA: // fBETA
      case symbol_kind::S_fDISC: // fDISC
      case symbol_kind::S_fTNOW: // fTNOW
      case symbol_kind::S_fTFIN: // fTFIN
      case symbol_kind::S_fMAXREP: // fMAXREP
      case symbol_kind::S_fNUMREP: // fNUMREP
      case symbol_kind::S_fIDENT: // fIDENT
      case symbol_kind::S_simulEntitiesWIP: // simulEntitiesWIP
      case symbol_kind::S_cIF: // cIF
      case symbol_kind::S_cELSE: // cELSE
      case symbol_kind::S_cFOR: // cFOR
      case symbol_kind::S_cTO: // cTO
      case symbol_kind::S_cDO: // cDO
      case symbol_kind::S_ATRIB: // ATRIB
      case symbol_kind::S_CSTAT: // CSTAT
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_fCOUNT: // fCOUNT
      case symbol_kind::S_ILLEGAL: // ILLEGAL
      case symbol_kind::S_RESOURCE: // RESOURCE
      case symbol_kind::S_fNR: // fNR
      case symbol_kind::S_fMR: // fMR
      case symbol_kind::S_fIRF: // fIRF
      case symbol_kind::S_fRESSEIZES: // fRESSEIZES
      case symbol_kind::S_fSTATE: // fSTATE
      case symbol_kind::S_fSETSUM: // fSETSUM
      case symbol_kind::S_fRESUTIL: // fRESUTIL
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_fENTATRANK: // fENTATRANK
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_fNUMGR: // fNUMGR
      case symbol_kind::S_fATRGR: // fATRGR
      case symbol_kind::S_input: // input
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_number: // number
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_logical: // logical
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_command: // command
      case symbol_kind::S_commandIF: // commandIF
      case symbol_kind::S_commandFOR: // commandFOR
      case symbol_kind::S_function: // function
      case symbol_kind::S_kernelFunction: // kernelFunction
      case symbol_kind::S_elementFunction: // elementFunction
      case symbol_kind::S_trigonFunction: // trigonFunction
      case symbol_kind::S_mathFunction: // mathFunction
      case symbol_kind::S_probFunction: // probFunction
      case symbol_kind::S_userFunction: // userFunction
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_attribute: // attribute
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_assigment: // assigment
      case symbol_kind::S_pluginFunction: // pluginFunction
        yylhs.value.emplace< obj_t > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // input: expression
#line 250 "bisonparser.yy"
                    { driver.setResult(yystack_[0].value.as < obj_t > ().valor);}
#line 1052 "../GenesysParser.cpp"
    break;

  case 3: // expression: number
#line 255 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1058 "../GenesysParser.cpp"
    break;

  case 4: // expression: function
#line 256 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1064 "../GenesysParser.cpp"
    break;

  case 5: // expression: command
#line 257 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1070 "../GenesysParser.cpp"
    break;

  case 6: // expression: assigment
#line 258 "bisonparser.yy"
                                      {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1076 "../GenesysParser.cpp"
    break;

  case 7: // expression: arithmetic
#line 259 "bisonparser.yy"
                                           {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1082 "../GenesysParser.cpp"
    break;

  case 8: // expression: logical
#line 260 "bisonparser.yy"
                                        {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1088 "../GenesysParser.cpp"
    break;

  case 9: // expression: relacional
#line 261 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1094 "../GenesysParser.cpp"
    break;

  case 10: // expression: "(" expression ")"
#line 262 "bisonparser.yy"
                                            {yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor;}
#line 1100 "../GenesysParser.cpp"
    break;

  case 11: // expression: attribute
#line 263 "bisonparser.yy"
                                        {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1106 "../GenesysParser.cpp"
    break;

  case 12: // expression: variable
#line 268 "bisonparser.yy"
                                                   {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1112 "../GenesysParser.cpp"
    break;

  case 13: // expression: formula
#line 272 "bisonparser.yy"
                                                   {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1118 "../GenesysParser.cpp"
    break;

  case 14: // number: NUMD
#line 279 "bisonparser.yy"
              { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1124 "../GenesysParser.cpp"
    break;

  case 15: // number: NUMH
#line 280 "bisonparser.yy"
              { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1130 "../GenesysParser.cpp"
    break;

  case 16: // arithmetic: expression "+" expression
#line 284 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor + yystack_[0].value.as < obj_t > ().valor;}
#line 1136 "../GenesysParser.cpp"
    break;

  case 17: // arithmetic: expression "-" expression
#line 285 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor - yystack_[0].value.as < obj_t > ().valor;}
#line 1142 "../GenesysParser.cpp"
    break;

  case 18: // arithmetic: expression "/" expression
#line 286 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor / yystack_[0].value.as < obj_t > ().valor;}
#line 1148 "../GenesysParser.cpp"
    break;

  case 19: // arithmetic: expression "*" expression
#line 287 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor * yystack_[0].value.as < obj_t > ().valor;}
#line 1154 "../GenesysParser.cpp"
    break;

  case 20: // arithmetic: expression "^" expression
#line 288 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = pow(yystack_[2].value.as < obj_t > ().valor,yystack_[0].value.as < obj_t > ().valor);}
#line 1160 "../GenesysParser.cpp"
    break;

  case 21: // arithmetic: "-" expression
#line 289 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = -yystack_[0].value.as < obj_t > ().valor;}
#line 1166 "../GenesysParser.cpp"
    break;

  case 22: // arithmetic: mathMIN "(" expression "," expression ")"
#line 292 "bisonparser.yy"
                                                            {std::cout <<"MIN(" << yystack_[3].value.as < obj_t > ().valor << "," << yystack_[1].value.as < obj_t > ().valor <<")"<< std::endl;
														 yylhs.value.as < obj_t > ().valor = std::min(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1173 "../GenesysParser.cpp"
    break;

  case 23: // arithmetic: mathMAX "(" expression "," expression ")"
#line 294 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = std::max(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1179 "../GenesysParser.cpp"
    break;

  case 24: // logical: expression oAND expression
#line 298 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1185 "../GenesysParser.cpp"
    break;

  case 25: // logical: expression oOR expression
#line 299 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor || (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1191 "../GenesysParser.cpp"
    break;

  case 26: // logical: expression oNAND expression
#line 300 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = !((int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor);}
#line 1197 "../GenesysParser.cpp"
    break;

  case 27: // logical: expression oXOR expression
#line 301 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = (!(int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor) || ((int) yystack_[2].value.as < obj_t > ().valor && !(int) yystack_[0].value.as < obj_t > ().valor);}
#line 1203 "../GenesysParser.cpp"
    break;

  case 28: // logical: oNOT expression
#line 302 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = !(int) yystack_[0].value.as < obj_t > ().valor;}
#line 1209 "../GenesysParser.cpp"
    break;

  case 29: // relacional: expression "<" expression
#line 306 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor < yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1215 "../GenesysParser.cpp"
    break;

  case 30: // relacional: expression ">" expression
#line 307 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor > yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1221 "../GenesysParser.cpp"
    break;

  case 31: // relacional: expression oLE expression
#line 308 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor <= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1227 "../GenesysParser.cpp"
    break;

  case 32: // relacional: expression oGE expression
#line 309 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor >= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1233 "../GenesysParser.cpp"
    break;

  case 33: // relacional: expression oEQ expression
#line 310 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor == yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1239 "../GenesysParser.cpp"
    break;

  case 34: // relacional: expression oNE expression
#line 311 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor != yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1245 "../GenesysParser.cpp"
    break;

  case 35: // command: commandIF
#line 315 "bisonparser.yy"
                    { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1251 "../GenesysParser.cpp"
    break;

  case 36: // command: commandFOR
#line 316 "bisonparser.yy"
                    { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1257 "../GenesysParser.cpp"
    break;

  case 37: // commandIF: cIF expression expression cELSE expression
#line 320 "bisonparser.yy"
                                                   { yylhs.value.as < obj_t > ().valor = yystack_[3].value.as < obj_t > ().valor != 0 ? yystack_[2].value.as < obj_t > ().valor : yystack_[0].value.as < obj_t > ().valor; }
#line 1263 "../GenesysParser.cpp"
    break;

  case 38: // commandIF: cIF expression expression
#line 321 "bisonparser.yy"
                                                  { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor != 0 ? yystack_[0].value.as < obj_t > ().valor : 0;}
#line 1269 "../GenesysParser.cpp"
    break;

  case 39: // commandFOR: cFOR variable "=" expression cTO expression cDO assigment
#line 326 "bisonparser.yy"
                                                                {yylhs.value.as < obj_t > ().valor = 0; }
#line 1275 "../GenesysParser.cpp"
    break;

  case 40: // commandFOR: cFOR attribute "=" expression cTO expression cDO assigment
#line 327 "bisonparser.yy"
                                                                  {yylhs.value.as < obj_t > ().valor = 0; }
#line 1281 "../GenesysParser.cpp"
    break;

  case 41: // function: mathFunction
#line 331 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1287 "../GenesysParser.cpp"
    break;

  case 42: // function: trigonFunction
#line 332 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1293 "../GenesysParser.cpp"
    break;

  case 43: // function: probFunction
#line 333 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1299 "../GenesysParser.cpp"
    break;

  case 44: // function: kernelFunction
#line 334 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1305 "../GenesysParser.cpp"
    break;

  case 45: // function: elementFunction
#line 335 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1311 "../GenesysParser.cpp"
    break;

  case 46: // function: pluginFunction
#line 336 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1317 "../GenesysParser.cpp"
    break;

  case 47: // function: userFunction
#line 337 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1323 "../GenesysParser.cpp"
    break;

  case 48: // kernelFunction: fTNOW
#line 341 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getSimulatedTime();}
#line 1329 "../GenesysParser.cpp"
    break;

  case 49: // kernelFunction: fTFIN
#line 342 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getReplicationLength();}
#line 1335 "../GenesysParser.cpp"
    break;

  case 50: // kernelFunction: fMAXREP
#line 343 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getNumberOfReplications();}
#line 1341 "../GenesysParser.cpp"
    break;

  case 51: // kernelFunction: fNUMREP
#line 344 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getCurrentReplicationNumber();}
#line 1347 "../GenesysParser.cpp"
    break;

  case 52: // kernelFunction: fIDENT
#line 345 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->getId();}
#line 1353 "../GenesysParser.cpp"
    break;

  case 53: // kernelFunction: simulEntitiesWIP
#line 346 "bisonparser.yy"
                            { yylhs.value.as < obj_t > ().valor = driver.getModel()->getDataManager()->getNumberOfDataDefinitions(Util::TypeOf<Entity>());}
#line 1359 "../GenesysParser.cpp"
    break;

  case 55: // elementFunction: fTAVG "(" CSTAT ")"
#line 351 "bisonparser.yy"
                               {
                    StatisticsCollector* cstat = ((StatisticsCollector*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<StatisticsCollector>(), yystack_[1].value.as < obj_t > ().id)));
                    double value = cstat->getStatistics()->average();
                    yylhs.value.as < obj_t > ().valor = value; }
#line 1368 "../GenesysParser.cpp"
    break;

  case 56: // elementFunction: fCOUNT "(" COUNTER ")"
#line 355 "bisonparser.yy"
                                 {
					Counter* counter = ((Counter*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Counter>(), yystack_[1].value.as < obj_t > ().id)));
                    double value = counter->getCountValue();
                    yylhs.value.as < obj_t > ().valor = value; }
#line 1377 "../GenesysParser.cpp"
    break;

  case 57: // trigonFunction: fSIN "(" expression ")"
#line 362 "bisonparser.yy"
                                  { yylhs.value.as < obj_t > ().valor = sin(yystack_[1].value.as < obj_t > ().valor); }
#line 1383 "../GenesysParser.cpp"
    break;

  case 58: // trigonFunction: fCOS "(" expression ")"
#line 363 "bisonparser.yy"
                                  { yylhs.value.as < obj_t > ().valor = cos(yystack_[1].value.as < obj_t > ().valor); }
#line 1389 "../GenesysParser.cpp"
    break;

  case 59: // mathFunction: fROUND "(" expression ")"
#line 367 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = round(yystack_[1].value.as < obj_t > ().valor);}
#line 1395 "../GenesysParser.cpp"
    break;

  case 60: // mathFunction: fFRAC "(" expression ")"
#line 368 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor - (int) yystack_[1].value.as < obj_t > ().valor;}
#line 1401 "../GenesysParser.cpp"
    break;

  case 61: // mathFunction: fTRUNC "(" expression ")"
#line 369 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = trunc(yystack_[1].value.as < obj_t > ().valor);}
#line 1407 "../GenesysParser.cpp"
    break;

  case 62: // mathFunction: fEXP "(" expression ")"
#line 370 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = exp(yystack_[1].value.as < obj_t > ().valor);}
#line 1413 "../GenesysParser.cpp"
    break;

  case 63: // mathFunction: fSQRT "(" expression ")"
#line 371 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = sqrt(yystack_[1].value.as < obj_t > ().valor);}
#line 1419 "../GenesysParser.cpp"
    break;

  case 64: // mathFunction: fLOG "(" expression ")"
#line 372 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = log10(yystack_[1].value.as < obj_t > ().valor);}
#line 1425 "../GenesysParser.cpp"
    break;

  case 65: // mathFunction: fLN "(" expression ")"
#line 373 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = log(yystack_[1].value.as < obj_t > ().valor);}
#line 1431 "../GenesysParser.cpp"
    break;

  case 66: // mathFunction: fMOD "(" expression "," expression ")"
#line 374 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = (int) yystack_[3].value.as < obj_t > ().valor % (int) yystack_[1].value.as < obj_t > ().valor; }
#line 1437 "../GenesysParser.cpp"
    break;

  case 67: // probFunction: fRND1
#line 378 "bisonparser.yy"
                                                     { yylhs.value.as < obj_t > ().valor = driver.getSampler()->sampleUniform(0.0,1.0);}
#line 1443 "../GenesysParser.cpp"
    break;

  case 68: // probFunction: fEXPO "(" expression ")"
#line 379 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = driver.getSampler()->sampleExponential(yystack_[1].value.as < obj_t > ().valor);}
#line 1449 "../GenesysParser.cpp"
    break;

  case 69: // probFunction: fNORM "(" expression "," expression ")"
#line 380 "bisonparser.yy"
                                                    { yylhs.value.as < obj_t > ().valor = driver.getSampler()->sampleNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1455 "../GenesysParser.cpp"
    break;

  case 70: // probFunction: fUNIF "(" expression "," expression ")"
#line 381 "bisonparser.yy"
                                                    { yylhs.value.as < obj_t > ().valor = driver.getSampler()->sampleUniform(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1461 "../GenesysParser.cpp"
    break;

  case 71: // probFunction: fWEIB "(" expression "," expression ")"
#line 382 "bisonparser.yy"
                                                    { yylhs.value.as < obj_t > ().valor = driver.getSampler()->sampleWeibull(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1467 "../GenesysParser.cpp"
    break;

  case 72: // probFunction: fLOGN "(" expression "," expression ")"
#line 383 "bisonparser.yy"
                                                    { yylhs.value.as < obj_t > ().valor = driver.getSampler()->sampleLogNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1473 "../GenesysParser.cpp"
    break;

  case 73: // probFunction: fGAMM "(" expression "," expression ")"
#line 384 "bisonparser.yy"
                                                    { yylhs.value.as < obj_t > ().valor = driver.getSampler()->sampleGamma(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1479 "../GenesysParser.cpp"
    break;

  case 74: // probFunction: fERLA "(" expression "," expression ")"
#line 385 "bisonparser.yy"
                                                    { yylhs.value.as < obj_t > ().valor = driver.getSampler()->sampleErlang(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1485 "../GenesysParser.cpp"
    break;

  case 75: // probFunction: fTRIA "(" expression "," expression "," expression ")"
#line 386 "bisonparser.yy"
                                                                    { yylhs.value.as < obj_t > ().valor = driver.getSampler()->sampleTriangular(yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1491 "../GenesysParser.cpp"
    break;

  case 76: // probFunction: fBETA "(" expression "," expression "," expression "," expression ")"
#line 387 "bisonparser.yy"
                                                                                  { yylhs.value.as < obj_t > ().valor = driver.getSampler()->sampleBeta(yystack_[7].value.as < obj_t > ().valor,yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1497 "../GenesysParser.cpp"
    break;

  case 77: // probFunction: fDISC "(" listaparm ")"
#line 388 "bisonparser.yy"
                                                    { yylhs.value.as < obj_t > ().valor = driver.getSampler()->sampleDiscrete(0,0); /*@TODO: NOT IMPLEMENTED YET*/ }
#line 1503 "../GenesysParser.cpp"
    break;

  case 78: // userFunction: "USER" "(" expression ")"
#line 394 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor; }
#line 1509 "../GenesysParser.cpp"
    break;

  case 79: // listaparm: listaparm "," expression "," expression
#line 399 "bisonparser.yy"
                                                 {/*@TODO: NOT IMPLEMENTED YET*/}
#line 1515 "../GenesysParser.cpp"
    break;

  case 80: // listaparm: expression "," expression
#line 400 "bisonparser.yy"
                                                 {/*@TODO: NOT IMPLEMENTED YET*/}
#line 1521 "../GenesysParser.cpp"
    break;

  case 81: // attribute: ATRIB
#line 426 "bisonparser.yy"
                   {  
		double attributeValue = 0.0;
		//std::cout << "Tentando..." << std::endl;
		if (driver.getModel()->getSimulation()->getCurrentEvent() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->getAttributeValue(yystack_[0].value.as < obj_t > ().id);
		}
		//std::cout << "Passei" << std::endl;
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1536 "../GenesysParser.cpp"
    break;

  case 82: // attribute: ATRIB "[" expression "]"
#line 436 "bisonparser.yy"
                                              {  
		double attributeValue = 0.0;
		std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		if (driver.getModel()->getSimulation()->getCurrentEvent() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->getAttributeValue(yystack_[3].value.as < obj_t > ().id, index);
		}
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1550 "../GenesysParser.cpp"
    break;

  case 83: // attribute: ATRIB "[" expression "," expression "]"
#line 445 "bisonparser.yy"
                                                             {  
		double attributeValue = 0.0;
		std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		if (driver.getModel()->getSimulation()->getCurrentEvent() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->getAttributeValue(yystack_[5].value.as < obj_t > ().id, index);
		}
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1564 "../GenesysParser.cpp"
    break;

  case 84: // attribute: ATRIB "[" expression "," expression "," expression "]"
#line 454 "bisonparser.yy"
                                                                            {  
		double attributeValue = 0.0;
		std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		if (driver.getModel()->getSimulation()->getCurrentEvent() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->getAttributeValue(yystack_[7].value.as < obj_t > ().id, index);
		}
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1578 "../GenesysParser.cpp"
    break;

  case 85: // variable: VARI
#line 468 "bisonparser.yy"
                            {yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[0].value.as < obj_t > ().id)))->getValue();}
#line 1584 "../GenesysParser.cpp"
    break;

  case 86: // variable: VARI "[" expression "]"
#line 469 "bisonparser.yy"
                                                                            { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[3].value.as < obj_t > ().id)))->getValue(index); }
#line 1592 "../GenesysParser.cpp"
    break;

  case 87: // variable: VARI "[" expression "," expression "]"
#line 472 "bisonparser.yy"
                                                                                            { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor)); 
					yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[5].value.as < obj_t > ().id)))->getValue(index);}
#line 1600 "../GenesysParser.cpp"
    break;

  case 88: // variable: VARI "[" expression "," expression "," expression "]"
#line 475 "bisonparser.yy"
                                                                                                     { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[7].value.as < obj_t > ().id)))->getValue(index);}
#line 1608 "../GenesysParser.cpp"
    break;

  case 89: // formula: FORM
#line 483 "bisonparser.yy"
                                    { 
					std::string index = "";
					Formula* formula = dynamic_cast<Formula*>(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[0].value.as < obj_t > ().id));
					std::string expression = formula->getExpression(index);
					//std::cout << "Formula["<< index <<"]="<< expression << std::endl;
					double value = 0.0; //@TODO: Can't parse the epression!  //formula->getValue(index);
					yylhs.value.as < obj_t > ().valor = value;}
#line 1620 "../GenesysParser.cpp"
    break;

  case 90: // formula: FORM "[" expression "]"
#line 490 "bisonparser.yy"
                                                                    {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					Formula* formula = dynamic_cast<Formula*>(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[3].value.as < obj_t > ().id));
					std::string expression = formula->getExpression(index);
					//std::cout << "Formula["<< index <<"]="<< expression << std::endl;
					double value = 0.0; //@TODO: Can't parse the epression!  //formula->getValue(index);
					yylhs.value.as < obj_t > ().valor = value;}
#line 1632 "../GenesysParser.cpp"
    break;

  case 91: // formula: FORM "[" expression "," expression "]"
#line 497 "bisonparser.yy"
                                                                                   {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					Formula* formula = dynamic_cast<Formula*>(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[5].value.as < obj_t > ().id));
					std::string expression = formula->getExpression(index);
					//std::cout << "Formula["<< index <<"]="<< expression << std::endl;
					double value = 0.0; //@TODO: Can't parse the epression!  //formula->getValue(index);
					yylhs.value.as < obj_t > ().valor = value;}
#line 1644 "../GenesysParser.cpp"
    break;

  case 92: // formula: FORM "[" expression "," expression "," expression "]"
#line 504 "bisonparser.yy"
                                                                                                  {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					Formula* formula = dynamic_cast<Formula*>(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[7].value.as < obj_t > ().id));
					std::string expression = formula->getExpression(index);
					//std::cout << "Formula["<< index <<"]="<< expression << std::endl;
					double value = 0.0; //@TODO: Can't parse the epression!  //formula->getValue(index);
					yylhs.value.as < obj_t > ().valor = value;}
#line 1656 "../GenesysParser.cpp"
    break;

  case 93: // assigment: ATRIB "=" expression
#line 516 "bisonparser.yy"
                                                { 
					// @TODO: getCurrentEvent()->getEntity() may be nullptr if simulation hasn't started yet
					driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->setAttributeValue(yystack_[2].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1665 "../GenesysParser.cpp"
    break;

  case 94: // assigment: ATRIB "[" expression "]" "=" expression
#line 520 "bisonparser.yy"
                                                                                          { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->setAttributeValue(yystack_[5].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor, index);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1674 "../GenesysParser.cpp"
    break;

  case 95: // assigment: ATRIB "[" expression "," expression "]" "=" expression
#line 524 "bisonparser.yy"
                                                                                                        {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)); 
					driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->setAttributeValue(yystack_[7].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor, index);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1683 "../GenesysParser.cpp"
    break;

  case 96: // assigment: ATRIB "[" expression "," expression "," expression "]" "=" expression
#line 528 "bisonparser.yy"
                                                                                                                          {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->setAttributeValue(yystack_[9].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor, index);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1692 "../GenesysParser.cpp"
    break;

  case 97: // assigment: VARI "=" expression
#line 534 "bisonparser.yy"
                                                                {
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[2].value.as < obj_t > ().id)))->setValue(yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; 
					}
#line 1701 "../GenesysParser.cpp"
    break;

  case 98: // assigment: VARI "[" expression "]" "=" expression
#line 538 "bisonparser.yy"
                                                                                         { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[5].value.as < obj_t > ().id)))->setValue(yystack_[0].value.as < obj_t > ().valor, index);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1710 "../GenesysParser.cpp"
    break;

  case 99: // assigment: VARI "[" expression "," expression "]" "=" expression
#line 542 "bisonparser.yy"
                                                                                                       {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)); 
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[7].value.as < obj_t > ().id)))->setValue(yystack_[0].value.as < obj_t > ().valor, index);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1719 "../GenesysParser.cpp"
    break;

  case 100: // assigment: VARI "[" expression "," expression "," expression "]" "=" expression
#line 546 "bisonparser.yy"
                                                                                                                         {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[9].value.as < obj_t > ().id)))->setValue(yystack_[0].value.as < obj_t > ().valor, index);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1728 "../GenesysParser.cpp"
    break;

  case 101: // pluginFunction: CTEZERO
#line 557 "bisonparser.yy"
                                                     { yylhs.value.as < obj_t > ().valor = 0; }
#line 1734 "../GenesysParser.cpp"
    break;

  case 102: // pluginFunction: fNQ "(" QUEUE ")"
#line 560 "bisonparser.yy"
                                    {   //std::cout << "Queue ID: " << $3.id << ", Size: " << ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), $3.id)))->size() << std::endl; 
                                        yylhs.value.as < obj_t > ().valor = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->size();}
#line 1741 "../GenesysParser.cpp"
    break;

  case 103: // pluginFunction: fLASTINQ "(" QUEUE ")"
#line 562 "bisonparser.yy"
                                    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1747 "../GenesysParser.cpp"
    break;

  case 104: // pluginFunction: fFIRSTINQ "(" QUEUE ")"
#line 563 "bisonparser.yy"
                                    { 
                if (((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->size() > 0){
                    //id da 1a entidade da fila, talvez pegar nome
                    yylhs.value.as < obj_t > ().valor = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->first()->getEntity()->getId();
                }else{
                    yylhs.value.as < obj_t > ().valor = 0;
                } }
#line 1759 "../GenesysParser.cpp"
    break;

  case 105: // pluginFunction: fSAQUE "(" QUEUE "," ATRIB ")"
#line 570 "bisonparser.yy"
                                       {   
                //Util::identification queueID = $3.id;
                Util::identification attrID = yystack_[1].value.as < obj_t > ().id;
                double sum = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[3].value.as < obj_t > ().id)))->sumAttributesFromWaiting(attrID);
                yylhs.value.as < obj_t > ().valor = sum; }
#line 1769 "../GenesysParser.cpp"
    break;

  case 106: // pluginFunction: fAQUE "(" QUEUE "," NUMD "," ATRIB ")"
#line 575 "bisonparser.yy"
                                             {
                //Util::identification queueID = $3.id;
                Util::identification attrID = yystack_[1].value.as < obj_t > ().id;
                double value = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[5].value.as < obj_t > ().id)))->getAttributeFromWaitingRank(yystack_[3].value.as < obj_t > ().valor-1, attrID); // rank starts on 0 in genesys
                yylhs.value.as < obj_t > ().valor = value; }
#line 1779 "../GenesysParser.cpp"
    break;

  case 107: // pluginFunction: fMR "(" RESOURCE ")"
#line 583 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getCapacity();}
#line 1785 "../GenesysParser.cpp"
    break;

  case 108: // pluginFunction: fNR "(" RESOURCE ")"
#line 584 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getNumberBusy();}
#line 1791 "../GenesysParser.cpp"
    break;

  case 109: // pluginFunction: fRESSEIZES "(" RESOURCE ")"
#line 585 "bisonparser.yy"
                                         { /*\TODO: For now does nothing because needs get Seizes, check with teacher*/}
#line 1797 "../GenesysParser.cpp"
    break;

  case 110: // pluginFunction: fSTATE "(" RESOURCE ")"
#line 586 "bisonparser.yy"
                                         {  yylhs.value.as < obj_t > ().valor = static_cast<int>(((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getResourceState()); }
#line 1803 "../GenesysParser.cpp"
    break;

  case 111: // pluginFunction: fIRF "(" RESOURCE ")"
#line 587 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1809 "../GenesysParser.cpp"
    break;

  case 112: // pluginFunction: fSETSUM "(" SET ")"
#line 588 "bisonparser.yy"
                              {
                unsigned int count=0;
                Resource* res;
                List<ModelDataDefinition*>* setList = ((Set*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Set>(),yystack_[1].value.as < obj_t > ().id))->getElementSet(); 
                for (std::list<ModelDataDefinition*>::iterator it = setList->list()->begin(); it!=setList->list()->end(); it++) {
                    res = dynamic_cast<Resource*>(*it);
                    if (res != nullptr) {
                        if (res->getResourceState()==Resource::ResourceState::BUSY) {
                            count++;
                        }
                    }
                }
                yylhs.value.as < obj_t > ().valor = count; }
#line 1827 "../GenesysParser.cpp"
    break;

  case 113: // pluginFunction: fNUMSET "(" SET ")"
#line 604 "bisonparser.yy"
                                { yylhs.value.as < obj_t > ().valor = ((Set*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Set>(),yystack_[1].value.as < obj_t > ().id))->getElementSet()->size(); }
#line 1833 "../GenesysParser.cpp"
    break;


#line 1837 "../GenesysParser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  genesyspp_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  genesyspp_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  genesyspp_parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // genesyspp_parser::context.
  genesyspp_parser::context::context (const genesyspp_parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  genesyspp_parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  genesyspp_parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  genesyspp_parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short genesyspp_parser::yypact_ninf_ = -311;

  const signed char genesyspp_parser::yytable_ninf_ = -22;

  const short
  genesyspp_parser::yypact_[] =
  {
     443,  -311,  -311,  -311,   443,   -68,   -67,   -61,   -60,   -59,
     -58,   -57,   -56,   -50,   -40,   -39,   -38,  -311,   -37,   -36,
     -35,   -34,   -33,   -32,   -31,   -28,   -27,   -26,  -311,  -311,
    -311,  -311,  -311,  -311,   443,   -51,   -76,   -25,   -24,   -23,
     -22,   -21,   -20,   -19,   -18,   -17,    -8,    -7,    -6,    21,
      24,   -75,   -53,   443,   443,    26,     3,  1715,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,   197,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     356,    23,    34,    16,    33,   443,   443,    94,    95,    92,
      93,    96,    97,    98,    79,    87,   107,   109,   110,   111,
      86,   443,   443,   443,  1006,    13,   443,  -311,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,  1016,  1026,  1036,   707,  1120,  1130,  1140,
    1150,  1160,  1170,   716,   725,  1180,   734,   820,   829,   838,
     847,   856,   865,   874,   883,   -78,   443,  1264,   443,   443,
     443,   443,    25,  1715,    80,    81,    83,   106,   112,   116,
     117,   118,   119,   120,   121,    99,   100,   122,    57,  1715,
     172,  -311,  1274,    85,    85,    85,    85,   197,   197,  1715,
    1715,   108,   108,    13,  1715,    13,    85,    85,  -311,  -311,
    -311,   443,  -311,  -311,  -311,  -311,  -311,  -311,   443,   443,
    -311,   443,   443,   443,   443,   443,   443,   443,   443,   443,
    -311,   443,   145,   443,   522,   532,  1282,  1290,    84,   443,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
    -311,   135,   185,  -311,   123,   443,  -311,   443,  -311,  1307,
    1317,  1401,  1411,  1421,  1431,  1441,  1451,  1461,   969,   978,
    1715,   987,    85,  -311,   443,  -311,   443,   443,   443,   443,
     542,   128,   125,   443,   552,   562,  -311,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,   443,   443,   443,   572,   582,
    1545,  1553,  1715,   136,   443,  -311,   137,  1715,   138,   443,
    -311,   443,  1563,   996,  1715,  -311,   443,  -311,   443,   -48,
     -48,   443,  1571,   131,   443,  1579,  1599,  -311,   443,  1607,
    1663,   -74,   -73,  -311,  -311,  1715,   143,  -311,  1715,   144,
    -311,  1691,  -311,  -311,   443,   443,   443,   443,  -311,   668,
     678,  1715,  1715,    84,   443,   123,   443,   688,   698,   136,
     443,   138,   443,  1699,  1707,   143,   144
  };

  const signed char
  genesyspp_parser::yydefact_[] =
  {
      54,    14,    15,   101,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    54,     0,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    89,    54,    54,     0,     0,     2,     3,     7,
       8,     9,     5,    35,    36,     4,    44,    45,    42,    41,
      43,    47,    11,    12,    13,     6,    46,    28,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    81,    85,     0,     0,    54,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    54,    54,     0,    21,    54,     1,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    38,    54,    54,
      54,    54,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,    10,     0,    31,    32,    33,    34,    24,    25,    26,
      27,    16,    17,    19,    20,    18,    29,    30,    57,    58,
      59,    54,    61,    60,    62,    63,    64,    65,    54,    54,
      68,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      77,    54,    17,    54,     0,     0,     0,     0,    82,    54,
      55,    56,   108,   107,   111,   109,   110,   112,   102,   104,
     103,     0,     0,   113,    86,    54,    90,    54,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,    37,    82,    54,    86,    54,    54,    54,    54,
       0,     0,     0,    54,     0,     0,    66,    22,    23,    69,
      70,    71,    72,    73,    74,    54,    54,    54,     0,     0,
       0,     0,    94,    83,    54,   105,     0,    98,    87,    54,
      91,    54,     0,     0,    79,    83,    54,    87,    54,     0,
       0,    54,     0,     0,    54,     0,     0,    75,    54,     0,
       0,     0,     0,    40,    39,    95,    84,   106,    99,    88,
      92,     0,    84,    88,    54,    54,    54,    54,    76,     0,
       0,    96,   100,     0,    54,     0,    54,     0,     0,     0,
      54,     0,    54,     0,     0,     0,     0
  };

  const short
  genesyspp_parser::yypgoto_[] =
  {
    -311,  -311,    -4,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,   177,   201,
    -311,  -310,  -311
  };

  const unsigned char
  genesyspp_parser::yydefgoto_[] =
  {
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,   165,    72,    73,
      74,    75,    76
  };

  const short
  genesyspp_parser::yytable_[] =
  {
      77,   101,   230,   127,   331,   105,   121,   344,   345,   333,
     334,    78,    79,   231,   106,   122,   106,   122,    80,    81,
      82,    83,    84,    85,   102,   134,   135,   332,   123,    86,
     100,   128,   129,   130,   131,   132,   133,   134,   135,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,   124,
     125,    97,    98,    99,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   128,   129,   130,   131,   132,   133,   134,
     135,   116,   117,   118,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   167,   134,   135,   139,
     119,   172,   173,   120,   168,   126,   170,   238,   136,   137,
     138,   139,   140,   141,   142,   169,   239,   188,   189,   190,
     134,   135,   192,   171,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   254,
     136,   137,   138,   139,   140,   141,   142,   174,   255,   175,
     176,   177,   181,   182,   178,   179,   180,   134,   135,   187,
     240,   241,   232,   242,   234,   235,   236,   237,   136,   137,
     138,   139,   140,   183,   279,   184,   185,   186,   128,   129,
     130,   131,   132,   133,   134,   135,   243,   281,   282,   323,
     251,   252,   244,   138,   139,   140,   245,   246,   247,   248,
     249,   250,   253,   128,   129,   130,   131,   259,   305,   134,
     135,   337,   103,   283,   260,   261,   306,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   321,   271,   324,   272,
     -21,   139,   -21,   346,   347,   280,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,     0,   285,   256,   136,   137,   138,   139,   140,
     141,   142,     0,   257,     0,     0,     0,     0,     0,     0,
     298,     0,   299,   300,   301,   302,     0,     0,     0,   307,
     136,   137,   138,   139,   140,   141,   142,     0,     0,     0,
       0,   312,   313,   314,     0,     0,     0,     0,     0,     0,
     322,     0,     0,     0,     0,   325,     0,   326,     0,     0,
       0,     0,   329,     0,   330,     0,     0,   335,     0,     0,
     338,     0,     0,     0,   341,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     349,   350,   351,   352,     0,     0,     0,     0,     0,     0,
     357,     0,   358,     0,     0,     0,   363,     0,   364,     1,
       2,     3,   128,   129,   130,   131,   132,   133,   134,   135,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,    35,     0,     0,    36,     0,
       0,    37,    38,     0,     0,    39,    40,    41,    42,    43,
      44,     0,     0,    45,    46,    47,    48,    49,     0,     0,
      50,    51,    52,     0,     0,    53,     0,     0,     0,   136,
     166,   138,   139,   140,   141,   142,     1,     2,     3,    55,
       0,     0,     0,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,     0,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,    35,     0,     0,    36,     0,     0,    37,    38,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
      45,    46,    47,    48,    49,     0,     0,    50,    51,    52,
       0,     0,    53,     0,     0,     0,     0,    54,   128,   129,
     130,   131,   132,   133,   134,   135,    55,     0,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   136,   137,   138,   139,   140,
     141,   142,     0,   274,   275,   136,   137,   138,   139,   140,
     141,   142,     0,   276,   303,   136,   137,   138,   139,   140,
     141,   142,     0,   304,   308,   136,   137,   138,   139,   140,
     141,   142,     0,   309,   310,   136,   137,   138,   139,   140,
     141,   142,     0,   311,   315,   136,   137,   138,   139,   140,
     141,   142,     0,   316,   317,   136,   137,   138,   139,   140,
     141,   142,     0,   318,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,   128,   129,   130,   131,   132,   133,
     134,   135,     0,   128,   129,   130,   131,   132,   133,   134,
     135,     0,   128,   129,   130,   131,   132,   133,   134,   135,
       0,   128,   129,   130,   131,   132,   133,   134,   135,     0,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
     353,   136,   137,   138,   139,   140,   141,   142,     0,   354,
     355,   136,   137,   138,   139,   140,   141,   142,     0,   356,
     359,   136,   137,   138,   139,   140,   141,   142,     0,   360,
     361,   136,   137,   138,   139,   140,   141,   142,     0,   362,
     136,   137,   138,   139,   140,   141,   142,     0,   211,   136,
     137,   138,   139,   140,   141,   142,     0,   218,   136,   137,
     138,   139,   140,   141,   142,     0,   219,   136,   137,   138,
     139,   140,   141,   142,     0,   221,   128,   129,   130,   131,
     132,   133,   134,   135,     0,   128,   129,   130,   131,   132,
     133,   134,   135,     0,   128,   129,   130,   131,   132,   133,
     134,   135,     0,   128,   129,   130,   131,   132,   133,   134,
     135,     0,   128,   129,   130,   131,   132,   133,   134,   135,
       0,   128,   129,   130,   131,   132,   133,   134,   135,     0,
     128,   129,   130,   131,   132,   133,   134,   135,     0,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,     0,   136,   137,   138,   139,   140,   141,   142,
       0,   222,   136,   137,   138,   139,   140,   141,   142,     0,
     223,   136,   137,   138,   139,   140,   141,   142,     0,   224,
     136,   137,   138,   139,   140,   141,   142,     0,   225,   136,
     137,   138,   139,   140,   141,   142,     0,   226,   136,   137,
     138,   139,   140,   141,   142,     0,   227,   136,   137,   138,
     139,   140,   141,   142,     0,   228,   136,   137,   138,   139,
     140,   141,   142,     0,   229,   128,   129,   130,   131,   132,
     133,   134,   135,     0,   128,   129,   130,   131,   132,   133,
     134,   135,     0,   128,   129,   130,   131,   132,   133,   134,
     135,     0,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,   136,   137,   138,   139,   140,   141,   142,     0,
     295,   136,   137,   138,   139,   140,   141,   142,     0,   296,
     136,   137,   138,   139,   140,   141,   142,     0,   297,   136,
     137,   138,   139,   140,   141,   142,   191,   328,     0,   136,
     137,   138,   139,   140,   141,   142,   208,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   209,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   210,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,     0,
     212,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     213,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     214,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     215,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     216,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     217,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     220,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
     128,   129,   130,   131,   132,   133,   134,   135,   128,   129,
     130,   131,   132,   133,   134,   135,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,   128,   129,   130,   131,   132,   133,   134,
     135,     0,   277,     0,     0,     0,     0,     0,     0,     0,
     278,     0,     0,     0,     0,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   258,     0,     0,   136,   137,   138,
     139,   140,   141,   142,     0,   136,   137,   138,   139,   140,
     141,   142,     0,   136,   137,   138,   139,   140,   141,   142,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   287,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,     0,     0,     0,
       0,   288,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   289,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   290,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   291,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   292,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   293,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   294,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   128,   129,   130,   131,   132,   133,   134,   135,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,   128,
     129,   130,   131,   132,   133,   134,   135,   128,   129,   130,
     131,   132,   133,   134,   135,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,   319,     0,     0,     0,
       0,     0,     0,     0,   320,   128,   129,   130,   131,   132,
     133,   134,   135,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,     0,   136,   137,   138,   139,
     140,   141,   142,   327,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   336,   136,   137,   138,   139,   140,   141,
     142,   339,   136,   137,   138,   139,   140,   141,   142,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,   340,   136,   137,   138,   139,   140,   141,   142,   342,
     136,   137,   138,   139,   140,   141,   142,   128,   129,   130,
     131,   132,   133,   134,   135,   128,   129,   130,   131,   132,
     133,   134,   135,   128,   129,   130,   131,   132,   133,   134,
     135,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   343,   136,   137,   138,   139,
     140,   141,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   365,   136,   137,   138,   139,   140,   141,   142,   366,
     136,   137,   138,   139,   140,   141,   142,     0,   136,   137,
     138,   139,   140,   141,   142
  };

  const short
  genesyspp_parser::yycheck_[] =
  {
       4,    52,    80,     0,    52,    81,    81,    81,    81,   319,
     320,    79,    79,    91,    90,    90,    90,    90,    79,    79,
      79,    79,    79,    79,    75,    12,    13,    75,    81,    79,
      34,     6,     7,     8,     9,    10,    11,    12,    13,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    53,
      54,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,     6,     7,     8,     9,    10,    11,    12,
      13,    79,    79,    79,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    12,    13,    86,
      79,   105,   106,    79,    81,    79,    90,    82,    83,    84,
      85,    86,    87,    88,    89,    81,    91,   121,   122,   123,
      12,    13,   126,    90,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    82,
      83,    84,    85,    86,    87,    88,    89,    53,    91,    54,
      58,    58,    73,    66,    58,    58,    58,    12,    13,    73,
      80,    80,   166,    80,   168,   169,   170,   171,    83,    84,
      85,    86,    87,    66,    90,    66,    66,    66,     6,     7,
       8,     9,    10,    11,    12,    13,    80,    52,     3,    52,
      91,    91,    80,    85,    86,    87,    80,    80,    80,    80,
      80,    80,    80,     6,     7,     8,     9,   211,    80,    12,
      13,    80,    35,    90,   218,   219,    91,   221,   222,   223,
     224,   225,   226,   227,   228,   229,    90,   231,    90,   233,
      85,    86,    87,    90,    90,   239,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   255,    -1,   257,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
     274,    -1,   276,   277,   278,   279,    -1,    -1,    -1,   283,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,   295,   296,   297,    -1,    -1,    -1,    -1,    -1,    -1,
     304,    -1,    -1,    -1,    -1,   309,    -1,   311,    -1,    -1,
      -1,    -1,   316,    -1,   318,    -1,    -1,   321,    -1,    -1,
     324,    -1,    -1,    -1,   328,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     344,   345,   346,   347,    -1,    -1,    -1,    -1,    -1,    -1,
     354,    -1,   356,    -1,    -1,    -1,   360,    -1,   362,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    52,    -1,
      -1,    55,    56,    -1,    -1,    59,    60,    61,    62,    63,
      64,    -1,    -1,    67,    68,    69,    70,    71,    -1,    -1,
      74,    75,    76,    -1,    -1,    79,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,     3,     4,     5,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    52,    -1,    -1,    55,    56,
      -1,    -1,    59,    60,    61,    62,    63,    64,    -1,    -1,
      67,    68,    69,    70,    71,    -1,    -1,    74,    75,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    84,     6,     7,
       8,     9,    10,    11,    12,    13,    93,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      -1,    91,    83,    84,    85,    86,    87,    88,    89,    -1,
      91,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,    83,    84,
      85,    86,    87,    88,    89,    -1,    91,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,    83,    84,    85,    86,
      87,    88,    89,    -1,    91,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    83,    84,    85,    86,    87,    88,    89,    -1,
      91,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      83,    84,    85,    86,    87,    88,    89,    -1,    91,    83,
      84,    85,    86,    87,    88,    89,    80,    91,    -1,    83,
      84,    85,    86,    87,    88,    89,    80,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,    80,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,    80,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      80,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      80,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      80,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      80,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      80,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      80,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,     6,     7,
       8,     9,    10,    11,    12,    13,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    88,    89,    80,    -1,    -1,    83,    84,    85,
      86,    87,    88,    89,    -1,    83,    84,    85,    86,    87,
      88,    89,    -1,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      83,    84,    85,    86,    87,    88,    89,    80,    -1,    -1,
      83,    84,    85,    86,    87,    88,    89,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    83,    84,    85,    86,    87,    88,
      89,    80,    -1,    -1,    83,    84,    85,    86,    87,    88,
      89,    80,    -1,    -1,    83,    84,    85,    86,    87,    88,
      89,    80,    -1,    -1,    83,    84,    85,    86,    87,    88,
      89,    80,    -1,    -1,    83,    84,    85,    86,    87,    88,
      89,    80,    -1,    -1,    83,    84,    85,    86,    87,    88,
      89,    80,    -1,    -1,    83,    84,    85,    86,    87,    88,
      89,     6,     7,     8,     9,    10,    11,    12,    13,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,     6,     7,     8,
       9,    10,    11,    12,    13,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,     6,     7,     8,     9,    10,
      11,    12,    13,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    88,    89,    -1,    83,    84,    85,    86,
      87,    88,    89,    80,    -1,    -1,    83,    84,    85,    86,
      87,    88,    89,    82,    83,    84,    85,    86,    87,    88,
      89,    82,    83,    84,    85,    86,    87,    88,    89,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    82,
      83,    84,    85,    86,    87,    88,    89,     6,     7,     8,
       9,    10,    11,    12,    13,     6,     7,     8,     9,    10,
      11,    12,    13,     6,     7,     8,     9,    10,    11,    12,
      13,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    83,    84,    85,    86,    87,    88,
      89,    82,    83,    84,    85,    86,    87,    88,    89,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    83,    84,
      85,    86,    87,    88,    89
  };

  const signed char
  genesyspp_parser::yystos_[] =
  {
       0,     3,     4,     5,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    49,    52,    55,    56,    59,
      60,    61,    62,    63,    64,    67,    68,    69,    70,    71,
      74,    75,    76,    79,    84,    93,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   112,   113,   114,   115,   116,    96,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      96,    52,    75,   112,   113,    81,    90,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    81,    90,    81,    96,    96,    79,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    83,    84,    85,    86,
      87,    88,    89,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,   111,    84,    96,    81,    81,
      90,    90,    96,    96,    53,    54,    58,    58,    58,    58,
      58,    73,    66,    66,    66,    66,    66,    73,    96,    96,
      96,    80,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    80,    80,
      80,    91,    80,    80,    80,    80,    80,    80,    91,    91,
      80,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      80,    91,    96,    48,    96,    96,    96,    96,    82,    91,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    91,    91,    80,    82,    91,    82,    91,    80,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    82,    91,    82,    91,    50,    50,    90,
      96,    52,     3,    90,    96,    96,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    91,    91,    91,    96,    96,
      96,    96,    96,    82,    91,    80,    91,    96,    82,    91,
      82,    91,    96,    96,    96,    82,    91,    82,    91,    51,
      51,    90,    96,    52,    90,    96,    96,    80,    91,    96,
      96,    52,    75,   115,   115,    96,    82,    80,    96,    82,
      82,    96,    82,    82,    81,    81,    90,    90,    80,    96,
      96,    96,    96,    82,    91,    82,    91,    96,    96,    82,
      91,    82,    91,    96,    96,    82,    82
  };

  const signed char
  genesyspp_parser::yyr1_[] =
  {
       0,    94,    95,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,    99,    99,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   105,   105,
     105,   105,   105,   105,   106,   106,   106,   107,   107,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   110,   111,
     111,   112,   112,   112,   112,   113,   113,   113,   113,   114,
     114,   114,   114,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116
  };

  const signed char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     2,     6,     6,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     1,     1,     5,     3,     8,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     1,     4,     6,
       6,     6,     6,     6,     6,     8,    10,     4,     4,     5,
       3,     1,     4,     6,     8,     1,     4,     6,     8,     1,
       4,     6,     8,     3,     6,     8,    10,     3,     6,     8,
      10,     1,     4,     4,     4,     6,     8,     4,     4,     4,
       4,     4,     4,     4
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const genesyspp_parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NUMD", "NUMH",
  "CTEZERO", "oLE", "oGE", "oEQ", "oNE", "oAND", "oOR", "oNAND", "oXOR",
  "oNOT", "fSIN", "fCOS", "fROUND", "fMOD", "fTRUNC", "fFRAC", "fEXP",
  "fSQRT", "fLOG", "fLN", "mathMIN", "mathMAX", "fVAL", "fEVAL", "fLENG",
  "fRND1", "fEXPO", "fNORM", "fUNIF", "fWEIB", "fLOGN", "fGAMM", "fERLA",
  "fTRIA", "fBETA", "fDISC", "fTNOW", "fTFIN", "fMAXREP", "fNUMREP",
  "fIDENT", "simulEntitiesWIP", "cIF", "cELSE", "cFOR", "cTO", "cDO",
  "ATRIB", "CSTAT", "COUNTER", "fTAVG", "fCOUNT", "ILLEGAL", "RESOURCE",
  "fNR", "fMR", "fIRF", "fRESSEIZES", "fSTATE", "fSETSUM", "fRESUTIL",
  "QUEUE", "fNQ", "fFIRSTINQ", "fLASTINQ", "fSAQUE", "fAQUE", "fENTATRANK",
  "SET", "fNUMSET", "VARI", "FORM", "fNUMGR", "fATRGR", "\"(\"", "\")\"",
  "\"[\"", "\"]\"", "\"+\"", "\"-\"", "\"*\"", "\"^\"", "\"/\"", "\"<\"",
  "\">\"", "\"=\"", "\",\"", "NEG", "\"USER\"", "$accept", "input",
  "expression", "number", "arithmetic", "logical", "relacional", "command",
  "commandIF", "commandFOR", "function", "kernelFunction",
  "elementFunction", "trigonFunction", "mathFunction", "probFunction",
  "userFunction", "listaparm", "attribute", "variable", "formula",
  "assigment", "pluginFunction", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  genesyspp_parser::yyrline_[] =
  {
       0,   250,   250,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   268,   272,   279,   280,   284,   285,   286,   287,
     288,   289,   292,   294,   298,   299,   300,   301,   302,   306,
     307,   308,   309,   310,   311,   315,   316,   320,   321,   326,
     327,   331,   332,   333,   334,   335,   336,   337,   341,   342,
     343,   344,   345,   346,   349,   351,   355,   362,   363,   367,
     368,   369,   370,   371,   372,   373,   374,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   394,   399,
     400,   426,   436,   445,   454,   468,   469,   472,   475,   483,
     490,   497,   504,   516,   520,   524,   528,   534,   538,   542,
     546,   557,   560,   562,   563,   570,   575,   583,   584,   585,
     586,   587,   588,   604
  };

  void
  genesyspp_parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  genesyspp_parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2817 "../GenesysParser.cpp"

#line 611 "bisonparser.yy"

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
