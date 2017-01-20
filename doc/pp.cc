/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "smallc.y" /* yacc.c:339  */

#include <iostream>
#include "ast.h"

extern int yylex();
extern int curr_lineno;


void yyerror(const char *s);

#define YYLTYPE int   // the type of locations
//#define yylloc curr_lineno  // use the curr_lineno from the lexer
extern int node_lineno;         // set before constructing a tree node to whatever you want the line number for the tree node to be


#define YYLLOC_DEFAULT(Current, Rhs, N)         \
        Current = Rhs[1];                             \
        node_lineno = Current;


#define SET_NODELOC(Current)  \
node_lineno = Current;

Program* ast_root;
Expr* test;

#line 93 "doc/pp.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "pp.hh".  */
#ifndef YY_YY_DOC_PP_HH_INCLUDED
# define YY_YY_DOC_PP_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 27 "smallc.y" /* yacc.c:355  */

#include "ast.h"

#line 127 "doc/pp.cc" /* yacc.c:355  */

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

union YYSTYPE
{
#line 30 "smallc.y" /* yacc.c:355  */

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

#line 279 "doc/pp.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
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

#endif /* !YY_YY_DOC_PP_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 310 "doc/pp.cc" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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
#if ! defined lint || defined __GNUC__
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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   116,   116,   119,   120,   123,   124,   125,   128,   129,
     130,   132,   133,   134,   136,   137,   139,   140,   141,   143,
     144,   145,   148,   151,   152,   155,   156,   157,   158,   159,
     160,   161,   162,   165,   166,   169,   170,   173,   174,   177,
     180,   181,   183,   184,   187,   188,   191,   192,   195,   196,
     199,   200,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   233,   234,   235,   236,   238,   239,   240,   241,   242,
     245,   246,   248,   249
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "ID", "TYPE", "DOT", "SUB",
  "L_NOT", "P_ADD", "P_SUB", "B_NOT", "MUL", "DIV", "MOD", "ADD", "SHL",
  "SHR", "GT", "GTE", "LT", "LTE", "EQ", "NEQ", "B_AND", "B_XOR", "B_OR",
  "L_AND", "L_OR", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "SHL_ASSIGN",
  "SHR_ASSIGN", "SEMI", "COMMA", "LP", "RP", "LB", "RB", "LC", "RC",
  "STRUCT", "RETURN", "IF", "ELSE", "BREAK", "CONT", "FOR", "UMINUS",
  "THEN", "$accept", "PROGRAM", "EXTDEFS", "EXTDEF", "SEXTVARS", "EXTVARS",
  "EXTVAR", "STSPEC", "PARAS", "STMTBLOCK", "STMTS", "STMT", "DEF", "DEFS",
  "SDEFS", "SDEF", "SDECS", "DECS", "DEC", "VAR", "INIT", "EXP", "EXPS",
  "ARRS", "ARGS", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -135

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-135)))

#define YYTABLE_NINF -94

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,    -1,    92,     7,  -135,    83,    34,   -33,    56,    57,
     -23,    -6,    94,  -135,  -135,    60,    63,   101,  -135,   109,
      82,   102,    94,   111,    70,    94,    34,  -135,   115,    86,
    -135,  -135,  -135,   137,   166,   166,   166,   166,   166,   166,
      33,  -135,   228,    85,    87,    91,    95,  -135,  -135,  -135,
      99,   103,   140,   100,   166,  -135,  -135,  -135,  -135,  -135,
    -135,   196,   119,   228,   116,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,  -135,  -135,   111,  -135,   101,    89,  -135,
    -135,   113,   127,  -135,   157,  -135,   144,  -135,  -135,  -135,
     144,    -2,    -2,   355,   355,   355,   355,    14,    14,   338,
     320,   301,   281,   260,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,  -135,  -135,   109,   111,    89,    73,
    -135,   120,  -135,   133,   141,    58,   146,  -135,   166,   145,
     150,   151,   152,  -135,   136,    73,   160,  -135,  -135,   109,
      82,  -135,   161,   166,  -135,  -135,   166,  -135,  -135,  -135,
    -135,  -135,  -135,   159,   163,   143,   166,   154,   167,   143,
     166,  -135,   194,   143,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    13,     0,     0,     2,     4,    10,    46,     0,    12,
      14,    18,    38,     1,     3,     8,     0,    21,     5,    13,
       0,     0,    38,     0,     0,    38,    10,     6,     0,     0,
      46,    11,    56,    91,     0,     0,     0,     0,     0,     0,
      51,    15,    48,     0,     0,    41,     0,    17,    37,     9,
      20,     0,     0,    51,    51,    54,    85,    86,    87,    88,
      89,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    16,     0,    39,    21,    36,     7,
      55,     0,     0,    52,    93,    49,    81,    82,    83,    84,
      80,    78,    79,    74,    75,    76,    77,    72,    73,    71,
      70,    69,    68,    67,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    40,    19,     0,     0,    36,    24,
      53,    91,    92,     0,    43,    44,     0,    35,    51,     0,
       0,     0,     0,    26,     0,    24,     0,    90,    33,     0,
       0,    34,     0,    51,    32,    31,    51,    22,    23,    25,
      42,    45,    27,     0,     0,    51,    51,    28,     0,    51,
      51,    29,     0,    51,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,   200,  -135,   211,   220,  -135,     0,   171,   218,
     134,     4,  -135,   132,   -21,  -135,   -17,   112,  -135,  -134,
     130,   -31,   -20,   168,   -29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    16,     8,     9,     6,    29,   153,
     154,   155,   138,   139,    24,    25,    46,   143,   144,    10,
      41,   156,    63,    55,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    44,   145,     7,    48,    65,    20,    13,    17,    62,
      66,    67,    68,    69,    56,    57,    58,    59,    60,    61,
      21,    65,    62,   102,   101,   145,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    32,    33,    15,    22,
      34,    35,    36,    37,    38,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    62,    39,   142,    32,    33,   134,   -93,
      34,    35,    36,    37,    38,    32,    33,   160,     1,    34,
      35,    36,    37,    38,   136,    18,    11,    19,   137,    23,
      26,    21,    27,    32,    33,    43,    28,    34,    35,    36,
      37,    38,   -51,    30,    39,    45,    47,   162,    98,    50,
     146,   148,   149,    39,   150,   151,   152,    40,    51,    93,
       2,    95,   173,    94,    96,   174,     2,    12,   137,    97,
      42,    39,   -93,    52,   100,   178,    32,    33,    98,   182,
      34,    35,    36,    37,    38,   140,    66,    67,    68,   104,
      32,    33,   105,    54,    34,    35,    36,    37,    38,    32,
      33,   141,   158,    34,    35,    36,    37,    38,    53,   177,
      54,   159,   167,   181,    39,   161,   163,   184,    98,   164,
     165,   148,   149,   166,   150,   151,   152,   -51,    39,   169,
     172,   175,   176,    65,   179,    14,   180,    39,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    65,   183,    49,   103,    31,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    65,   135,    99,
     147,   170,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    65,   168,
     171,     0,     0,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    65,   157,
       0,     0,     0,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    65,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    65,     0,     0,     0,     0,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    65,     0,     0,     0,     0,    66,    67,    68,
      69,    70,    71
};

static const yytype_int16 yycheck[] =
{
      20,    22,   136,     4,    25,     7,    29,     0,    41,    40,
      12,    13,    14,    15,    34,    35,    36,    37,    38,    39,
      43,     7,    53,    54,    53,   159,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     3,     4,     4,    45,
       7,     8,     9,    10,    11,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   104,    41,   104,     3,     4,    95,    46,
       7,     8,     9,    10,    11,     3,     4,    29,     5,     7,
       8,     9,    10,    11,     5,    39,     4,    40,    98,     5,
      40,    43,    39,     3,     4,     3,     5,     7,     8,     9,
      10,    11,    39,     4,    41,     4,    46,   148,    45,     4,
     137,    48,    49,    41,    51,    52,    53,    45,    42,    44,
      47,    40,   163,    46,    39,   166,    47,    45,   138,    40,
     160,    41,    42,     6,     4,   176,     3,     4,    45,   180,
       7,     8,     9,    10,    11,    42,    12,    13,    14,    40,
       3,     4,    46,    43,     7,     8,     9,    10,    11,     3,
       4,    44,    39,     7,     8,     9,    10,    11,    41,   175,
      43,    40,    46,   179,    41,    39,    41,   183,    45,    39,
      39,    48,    49,    41,    51,    52,    53,    40,    41,    39,
      39,    42,    39,     7,    50,     5,    39,    41,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,     7,    42,    26,    42,    19,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,     7,    97,    51,
     138,   159,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     7,   155,
     160,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     7,   141,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    47,    57,    58,    59,    63,     4,    61,    62,
      75,     4,    45,     0,    58,     4,    60,    41,    39,    40,
      29,    43,    45,     5,    70,    71,    40,    39,     5,    64,
       4,    61,     3,     4,     7,     8,     9,    10,    11,    41,
      45,    76,    78,     3,    70,     4,    72,    46,    70,    60,
       4,    42,     6,    41,    43,    79,    78,    78,    78,    78,
      78,    78,    77,    78,    80,     7,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    44,    46,    40,    39,    40,    45,    65,
       4,    80,    77,    42,    40,    46,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    72,    64,     5,    63,    68,    69,
      42,    44,    80,    73,    74,    75,    72,    69,    48,    49,
      51,    52,    53,    65,    66,    67,    77,    79,    39,    40,
      29,    39,    77,    41,    39,    39,    41,    46,    66,    39,
      73,    76,    39,    77,    77,    42,    39,    67,    77,    50,
      39,    67,    77,    42,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    60,    60,
      60,    61,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    64,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     6,     1,     3,
       0,     3,     1,     0,     1,     3,     5,     4,     2,     4,
       2,     0,     4,     2,     0,     2,     1,     3,     5,     7,
       9,     2,     2,     3,     3,     2,     0,     2,     0,     3,
       3,     1,     3,     1,     1,     3,     1,     4,     1,     3,
       1,     0,     3,     4,     2,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       4,     0,     3,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 116 "smallc.y" /* yacc.c:1661  */
    { (yyloc) = (yylsp[0]); (yyval.program) = new Program((yyvsp[0].extdefs)); ast_root = (yyval.program); }
#line 1649 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 3:
#line 119 "smallc.y" /* yacc.c:1661  */
    { (yyvsp[0].extdefs)->push_front((yyvsp[-1].extdef)); (yyval.extdefs) = (yyvsp[0].extdefs); }
#line 1655 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 4:
#line 120 "smallc.y" /* yacc.c:1661  */
    { (yyval.extdefs) = new ExtDefList; }
#line 1661 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 5:
#line 123 "smallc.y" /* yacc.c:1661  */
    { (yyval.extdef) = new VarExtDef((yyvsp[-1].extvars)); }
#line 1667 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 6:
#line 124 "smallc.y" /* yacc.c:1661  */
    { (yyval.extdef) = new StructExtDef((yyvsp[-2].stspec), (yyvsp[-1].sextvars)); }
#line 1673 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 7:
#line 125 "smallc.y" /* yacc.c:1661  */
    { (yyval.extdef) = new FuncExtDef(*(yyvsp[-4].sval), (yyvsp[-2].paras), (yyvsp[0].stmtblock)); }
#line 1679 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 8:
#line 128 "smallc.y" /* yacc.c:1661  */
    { (yyval.sextvars) = new SExtVarList{*(yyvsp[0].sval)}; }
#line 1685 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 9:
#line 129 "smallc.y" /* yacc.c:1661  */
    { (yyvsp[0].sextvars)->push_front(*(yyvsp[-2].sval)); (yyval.sextvars) = (yyvsp[0].sextvars); }
#line 1691 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 10:
#line 130 "smallc.y" /* yacc.c:1661  */
    { (yyval.sextvars) = new SExtVarList; }
#line 1697 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 11:
#line 132 "smallc.y" /* yacc.c:1661  */
    { (yyvsp[0].extvars)->push_front((yyvsp[-2].extvar)); (yyval.extvars) = (yyvsp[0].extvars); }
#line 1703 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 12:
#line 133 "smallc.y" /* yacc.c:1661  */
    { (yyval.extvars) = new ExtVarList; (yyval.extvars)->push_front((yyvsp[0].extvar)); }
#line 1709 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 13:
#line 134 "smallc.y" /* yacc.c:1661  */
    { (yyval.extvars) = new ExtVarList; }
#line 1715 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 14:
#line 136 "smallc.y" /* yacc.c:1661  */
    { (yyval.extvar) = new ExtVar((yyvsp[0].var)); }
#line 1721 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 15:
#line 137 "smallc.y" /* yacc.c:1661  */
    { (yyval.extvar) = new InitExtVar((yyvsp[-2].var), (yyvsp[0].init)); }
#line 1727 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 16:
#line 139 "smallc.y" /* yacc.c:1661  */
    { (yyval.stspec) = new StructSpec(*(yyvsp[-3].sval), (yyvsp[-1].stdefs)); }
#line 1733 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 17:
#line 140 "smallc.y" /* yacc.c:1661  */
    { (yyval.stspec) = new StructSpec((yyvsp[-1].stdefs)); }
#line 1739 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 18:
#line 141 "smallc.y" /* yacc.c:1661  */
    { (yyval.stspec) = new StructSpec(*(yyvsp[0].sval)); }
#line 1745 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 19:
#line 143 "smallc.y" /* yacc.c:1661  */
    { (yyvsp[0].paras)->push_front(*(yyvsp[-2].sval)); (yyval.paras) = (yyvsp[0].paras); }
#line 1751 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 20:
#line 144 "smallc.y" /* yacc.c:1661  */
    { (yyval.paras) = new Paras{*(yyvsp[0].sval)}; }
#line 1757 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 21:
#line 145 "smallc.y" /* yacc.c:1661  */
    { (yyval.paras) = new Paras;}
#line 1763 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 22:
#line 148 "smallc.y" /* yacc.c:1661  */
    { (yyval.stmtblock) = new StmtBlock((yyvsp[-2].defs), (yyvsp[-1].stmts)); }
#line 1769 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 23:
#line 151 "smallc.y" /* yacc.c:1661  */
    { (yyvsp[0].stmts)->push_front((yyvsp[-1].stmt)); (yyval.stmts) = (yyvsp[0].stmts); }
#line 1775 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 24:
#line 152 "smallc.y" /* yacc.c:1661  */
    { (yyval.stmts) = new StmtList;}
#line 1781 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 25:
#line 155 "smallc.y" /* yacc.c:1661  */
    { (yyval.stmt) = new ExprStmt((yyvsp[-1].exp)); }
#line 1787 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 26:
#line 156 "smallc.y" /* yacc.c:1661  */
    { (yyval.stmt) = new BlockStmt((yyvsp[0].stmtblock)); }
#line 1793 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 27:
#line 157 "smallc.y" /* yacc.c:1661  */
    { (yyval.stmt) = new ReturnStmt((yyvsp[-1].exp)); }
#line 1799 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 28:
#line 158 "smallc.y" /* yacc.c:1661  */
    { (yyval.stmt) = new IfStmt((yyvsp[-2].exp), (yyvsp[0].stmt)); }
#line 1805 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 29:
#line 159 "smallc.y" /* yacc.c:1661  */
    { (yyval.stmt) = new IfStmt((yyvsp[-4].exp), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 1811 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 30:
#line 160 "smallc.y" /* yacc.c:1661  */
    { (yyval.stmt) = new ForStmt((yyvsp[-6].exp), (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].stmt)); }
#line 1817 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 31:
#line 161 "smallc.y" /* yacc.c:1661  */
    { (yyval.stmt) = new ContStmt; }
#line 1823 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 32:
#line 162 "smallc.y" /* yacc.c:1661  */
    { (yyval.stmt) = new BreakStmt; }
#line 1829 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 33:
#line 165 "smallc.y" /* yacc.c:1661  */
    { (yyval.def) = new VarDef((yyvsp[-1].decs)); }
#line 1835 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 34:
#line 166 "smallc.y" /* yacc.c:1661  */
    { (yyval.def) = new SDef((yyvsp[-2].stspec), (yyvsp[-1].sdecs)); }
#line 1841 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 35:
#line 169 "smallc.y" /* yacc.c:1661  */
    { (yyvsp[0].defs)->push_front((yyvsp[-1].def)); (yyval.defs) = (yyvsp[0].defs); }
#line 1847 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 36:
#line 170 "smallc.y" /* yacc.c:1661  */
    { (yyval.defs) = new DefList; }
#line 1853 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 37:
#line 173 "smallc.y" /* yacc.c:1661  */
    { (yyvsp[0].stdefs)->push_front((yyvsp[-1].stdef)); (yyval.stdefs) = (yyvsp[0].stdefs); }
#line 1859 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 38:
#line 174 "smallc.y" /* yacc.c:1661  */
    { (yyval.stdefs) = new StructDefList; }
#line 1865 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 39:
#line 177 "smallc.y" /* yacc.c:1661  */
    { (yyval.stdef) = new StructDef((yyvsp[-1].sdecs)); }
#line 1871 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 40:
#line 180 "smallc.y" /* yacc.c:1661  */
    { (yyvsp[0].sdecs)->push_front(*(yyvsp[-2].sval)); (yyval.sdecs) = (yyvsp[0].sdecs); }
#line 1877 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 41:
#line 181 "smallc.y" /* yacc.c:1661  */
    { (yyval.sdecs) = new SDecList{*(yyvsp[0].sval)}; }
#line 1883 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 42:
#line 183 "smallc.y" /* yacc.c:1661  */
    { (yyvsp[0].decs)->push_front((yyvsp[-2].dec)); (yyval.decs) = (yyvsp[0].decs); }
#line 1889 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 43:
#line 184 "smallc.y" /* yacc.c:1661  */
    { (yyval.decs) = new DecList{(yyvsp[0].dec)}; }
#line 1895 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 44:
#line 187 "smallc.y" /* yacc.c:1661  */
    { (yyval.dec) = new Dec((yyvsp[0].var)); }
#line 1901 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 45:
#line 188 "smallc.y" /* yacc.c:1661  */
    { (yyval.dec) = new Dec((yyvsp[-2].var), (yyvsp[0].init)); }
#line 1907 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 46:
#line 191 "smallc.y" /* yacc.c:1661  */
    { (yyval.var) = new IdVar(*(yyvsp[0].sval)); }
#line 1913 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 47:
#line 192 "smallc.y" /* yacc.c:1661  */
    { (yyval.var) = new ArrayVar((yyvsp[-3].var), (yyvsp[-1].ival)); }
#line 1919 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 48:
#line 195 "smallc.y" /* yacc.c:1661  */
    { (yyval.init) = new IntInit((yyvsp[0].exp)); }
#line 1925 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 49:
#line 196 "smallc.y" /* yacc.c:1661  */
    { (yyval.init) = new ArrayInit((yyvsp[-1].args)); }
#line 1931 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 50:
#line 199 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = (yyvsp[0].exp); }
#line 1937 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 51:
#line 200 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new NoExpr;}
#line 1943 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 52:
#line 203 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = (yyvsp[-1].exp); }
#line 1949 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 53:
#line 204 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new CallExpr(*(yyvsp[-3].sval), (yyvsp[-1].args)); }
#line 1955 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 54:
#line 205 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new ArrsExpr(*(yyvsp[-1].sval), (yyvsp[0].arrs)); }
#line 1961 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 55:
#line 206 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new AccessExpr(*(yyvsp[-2].sval), *(yyvsp[0].sval)); }
#line 1967 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 56:
#line 207 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new IntExpr((yyvsp[0].ival));}
#line 1973 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 57:
#line 208 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1979 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 58:
#line 209 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1985 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 59:
#line 210 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1991 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 60:
#line 211 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1997 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 61:
#line 212 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2003 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 62:
#line 213 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2009 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 63:
#line 214 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2015 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 64:
#line 215 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2021 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 65:
#line 216 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2027 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 66:
#line 217 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2033 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 67:
#line 218 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2039 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 68:
#line 219 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2045 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 69:
#line 220 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2051 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 70:
#line 221 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2057 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 71:
#line 222 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2063 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 72:
#line 223 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2069 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 73:
#line 224 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2075 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 74:
#line 225 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2081 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 75:
#line 226 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2087 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 76:
#line 227 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2093 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 77:
#line 228 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2099 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 78:
#line 229 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2105 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 79:
#line 230 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2111 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 80:
#line 231 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2117 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 81:
#line 233 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2123 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 82:
#line 234 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2129 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 83:
#line 235 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2135 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 84:
#line 236 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new BopExpr(*(yyvsp[-1].sval), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2141 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 85:
#line 238 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new UopExpr(*(yyvsp[-1].sval), (yyvsp[0].exp)); }
#line 2147 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 86:
#line 239 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new UopExpr(*(yyvsp[-1].sval), (yyvsp[0].exp)); }
#line 2153 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 87:
#line 240 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new UopExpr(*(yyvsp[-1].sval), (yyvsp[0].exp)); }
#line 2159 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 88:
#line 241 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new UopExpr(*(yyvsp[-1].sval), (yyvsp[0].exp)); }
#line 2165 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 89:
#line 242 "smallc.y" /* yacc.c:1661  */
    { (yyval.exp) = new UopExpr(*(yyvsp[-1].sval), (yyvsp[0].exp)); }
#line 2171 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 90:
#line 245 "smallc.y" /* yacc.c:1661  */
    { (yyvsp[0].arrs)->push_front((yyvsp[-2].exp)); (yyval.arrs) = (yyvsp[0].arrs); }
#line 2177 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 91:
#line 246 "smallc.y" /* yacc.c:1661  */
    { (yyval.arrs) = new Arrs; }
#line 2183 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 92:
#line 248 "smallc.y" /* yacc.c:1661  */
    { (yyvsp[0].args)->push_front((yyvsp[-2].exp)); (yyval.args) = (yyvsp[0].args); }
#line 2189 "doc/pp.cc" /* yacc.c:1661  */
    break;

  case 93:
#line 249 "smallc.y" /* yacc.c:1661  */
    { (yyval.args) = new Args; }
#line 2195 "doc/pp.cc" /* yacc.c:1661  */
    break;


#line 2199 "doc/pp.cc" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 251 "smallc.y" /* yacc.c:1906  */


    void yyerror(const char *s)
    {
      extern int curr_lineno;

      cerr << "line " << curr_lineno << ": " \
      << s << " at or near " << token_to_string(yychar);
      cerr << endl;
    }
