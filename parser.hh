/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    ID = 259,
    TYPE = 260,
    BINARYOP = 261,
    UNARYOP = 262,
    SEMI = 263,
    COMMA = 264,
    LP = 265,
    RP = 266,
    LB = 267,
    RB = 268,
    LC = 269,
    RC = 270,
    STRUCT = 271,
    RETURN = 272,
    IF = 273,
    ELSE = 274,
    BREAK = 275,
    CONT = 276,
    FOR = 277
  };
#endif
/* Tokens.  */
#define INT 258
#define ID 259
#define TYPE 260
#define BINARYOP 261
#define UNARYOP 262
#define SEMI 263
#define COMMA 264
#define LP 265
#define RP 266
#define LB 267
#define RB 268
#define LC 269
#define RC 270
#define STRUCT 271
#define RETURN 272
#define IF 273
#define ELSE 274
#define BREAK 275
#define CONT 276
#define FOR 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "smallc.y" /* yacc.c:1915  */

    int ival;
    std::string* sval;

#line 103 "parser.hh" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HH_INCLUDED  */
