/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_HH_INCLUDED
# define YY_YY_PARSER_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 29 "smallc.y" /* yacc.c:1909  */

#include "ast.h"

#define YYLTYPE int

#line 50 "parser.hh" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    ID = 259,
    TYPE = 260,
    DOT = 261,
    SUB = 262,
    L_NOT = 263,
    P_ADD = 264,
    P_SUB = 265,
    B_NOT = 266,
    MUL = 267,
    DIV = 268,
    MOD = 269,
    ADD = 270,
    SHL = 271,
    SHR = 272,
    GT = 273,
    GTE = 274,
    LT = 275,
    LTE = 276,
    EQ = 277,
    NEQ = 278,
    B_AND = 279,
    B_XOR = 280,
    B_OR = 281,
    L_AND = 282,
    L_OR = 283,
    ASSIGN = 284,
    ADD_ASSIGN = 285,
    SUB_ASSIGN = 286,
    MUL_ASSIGN = 287,
    DIV_ASSIGN = 288,
    AND_ASSIGN = 289,
    XOR_ASSIGN = 290,
    OR_ASSIGN = 291,
    SHL_ASSIGN = 292,
    SHR_ASSIGN = 293,
    SEMI = 294,
    COMMA = 295,
    LP = 296,
    RP = 297,
    LB = 298,
    RB = 299,
    LC = 300,
    RC = 301,
    STRUCT = 302,
    RETURN = 303,
    IF = 304,
    ELSE = 305,
    BREAK = 306,
    CONT = 307,
    FOR = 308,
    UMINUS = 309,
    THEN = 310
  };
#endif
/* Tokens.  */
#define INT 258
#define ID 259
#define TYPE 260
#define DOT 261
#define SUB 262
#define L_NOT 263
#define P_ADD 264
#define P_SUB 265
#define B_NOT 266
#define MUL 267
#define DIV 268
#define MOD 269
#define ADD 270
#define SHL 271
#define SHR 272
#define GT 273
#define GTE 274
#define LT 275
#define LTE 276
#define EQ 277
#define NEQ 278
#define B_AND 279
#define B_XOR 280
#define B_OR 281
#define L_AND 282
#define L_OR 283
#define ASSIGN 284
#define ADD_ASSIGN 285
#define SUB_ASSIGN 286
#define MUL_ASSIGN 287
#define DIV_ASSIGN 288
#define AND_ASSIGN 289
#define XOR_ASSIGN 290
#define OR_ASSIGN 291
#define SHL_ASSIGN 292
#define SHR_ASSIGN 293
#define SEMI 294
#define COMMA 295
#define LP 296
#define RP 297
#define LB 298
#define RB 299
#define LC 300
#define RC 301
#define STRUCT 302
#define RETURN 303
#define IF 304
#define ELSE 305
#define BREAK 306
#define CONT 307
#define FOR 308
#define UMINUS 309
#define THEN 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 34 "smallc.y" /* yacc.c:1909  */

    int ival;
    std::string* sval;
    Program* program;
	ExtDefList* extdefs;
	ExtDef* extdef;
	ExtVar* extvar;
	ExtVarList* extvars;
	SExtVar* sextvar;
	SExtVarList* sextvars;
	StructSpec* stspec;
	Paras* paras;
	StmtBlock* stmtblock;
	StmtList* stmts;
	Stmt* stmt;
	DefList* defs;
	Def* def;
	StructDef* stdef;
	StructDefList* stdefs;
	SDec* sdec;
	SDecList* sdecs;
	Dec* dec;
	DecList* decs;
	Var* var;
	Init* init;
	Arrs* arrs;
	Args* args;
    Expr* exp;

#line 202 "parser.hh" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_HH_INCLUDED  */
