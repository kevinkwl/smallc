%{
#include <iostream>
#include "ast.h"

extern int yylex();


void yyerror(const char *s);

#define YYLTYPE int   // the type of locations
#define yylloc curr_lineno  // use the curr_lineno from the lexer
extern int node_lineno;         // set before constructing a tree node to whatever you want the line number for the tree node to be


#define YYLLOC_DEFAULT(Current, Rhs, N)         \
        Current = Rhs[1];                             \
        node_lineno = Current;


#define SET_NODELOC(Current)  \
node_lineno = Current;

Program* ast_root;
Expr* test;
%}
%code requires {
#include "ast.h"
}
%union {
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
	StDefList* stdefs;
	SDec* sdec;
	SDecList* sdecs;
	Dec* dec;
	DecList* decs;
	Var* var;
	Init* init;
	Arrs* arrs;
	Args* args;
    Expr* exp;

}
%token <ival> INT
%token <sval> ID TYPE
%token <sval> DOT SUB L_NOT P_ADD P_SUB B_NOT
%token <sval> MUL DIV MOD
%token <sval> ADD
%token <sval> SHL SHR
%token <sval> GT GTE LT LTE
%token <sval> EQ NEQ
%token <sval> B_AND B_XOR B_OR L_AND L_OR
%token <sval> ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN SHL_ASSIGN SHR_ASSIGN
%token SEMI COMMA LP RP LB RB LC RC STRUCT RETURN IF ELSE BREAK CONT FOR

%type <program> PROGRAM
%type <extdefs> EXTDEFS
%type <extdef> EXTDEF
%type <extvar> EXTVAR
%type <extvars> EXTVARS

%type <sextvars> SEXTVARS
%type <stspec> STSPEC
%type <paras> PARAS
%type <stmtblock> STMTBLOCK
%type <stmts> STMTS
%type <stmt> STMT
%type <defs> DEFS
%type <def> DEF
%type <stdef> SDEF
%type <stdefs> SDEFS
%type <sdecs> SDECS
%type <dec> DEC
%type <decs> DECS
%type <var> VAR
%type <init> INIT
%type <arrs> ARRS
%type <args> ARGS
%type <exp> EXP
%type <exp> EXPS


%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN SHL_ASSIGN SHR_ASSIGN
%left L_OR
%left L_AND
%left B_OR
%left B_XOR
%left B_AND
%left EQ NEQ
%left GT GTE LT LTE
%left SHL SHR
%left ADD SUB
%left MUL DIV MOD
%right UMINUS L_NOT P_ADD P_SUB B_NOT
%left DOT LP RP LB RB

%right THEN ELSE


%%
PROGRAM : EXTDEFS	{ $$ = new Program($1); ast_root = $$; }
	;

EXTDEFS : EXTDEF EXTDEFS { $2->push_front($1); $$ = $2; }
	| %empty			 { $$ = new ExtDefList; }
	;

EXTDEF : TYPE EXTVARS SEMI { $$ = new VarExtDef($2); }
	| STSPEC SEXTVARS SEMI { $$ = new StructExtDef($1, $2); }
	| TYPE ID LP PARAS RP STMTBLOCK  { $$ = new FuncExtDef(*$2, $4, $6); }
	;

SEXTVARS : ID	{ $$ = new SExtVarList{*$1}; }
	| ID COMMA SEXTVARS { $3->push_front(*$1); $$ = $3; }
	| %empty    { $$ = new SExtVarList; }
	;
EXTVARS : EXTVAR EXTVARS  { $2->push_front($1); $$ = $2; }
	| %empty		{ $$ = new ExtVarList; }
	;
EXTVAR : VAR		{ $$ = new ExtVar($1); }
	| VAR ASSIGN INIT { $$ = new InitExtVar($1, $3); }
	;
STSPEC : STRUCT ID LC SDEFS RC { $$ = new StructSpec(*$2, $4); }
	| STRUCT LC SDEFS RC { $$ = new StructSpec($3); }
	| STRUCT ID { $$ = new StructSpec(*$2); }
	;
PARAS : TYPE ID	COMMA PARAS { $4->push_front(*$2); $$ = $4; }
	| TYPE ID	{ $$ = new Paras{*$2}; }
	| %empty	{ $$ = new Paras;}
	;

STMTBLOCK : LC DEFS STMTS RC  { $$ = new StmtBlock($2, $3); }
	;

STMTS : STMT STMTS { $2->push_front($1); $$ = $2; }
	| %empty	{ $$ = new StmtList;}
	;

STMT : EXP SEMI	{ $$ = new ExprStmt($1); }
	| STMTBLOCK { $$ = new BlockStmt($1); }
	| RETURN EXP SEMI { $$ = new ReturnStmt($2); }
	| IF LP EXP RP STMT %prec THEN { $$ = new IfStmt($3, $5); }
	| IF LP EXP RP STMT ELSE STMT { $$ = new IfStmt($3, $5, $7); }
	| FOR LP EXP SEMI EXP SEMI EXP RP STMT { $$ = new ForStmt($3, $5, $7, $9); }
	| CONT SEMI { $$ = new ContStmt; }
	| BREAK SEMI { $$ = new BreakStmt; }
	;

DEF : TYPE DECS SEMI  { $$ = new VarDef($2); }
	| STSPEC SDECS SEMI  { $$ = new SDef($1, $2); }
	;

DEFS : DEF DEFS { $2->push_front($1); $$ = $2; }
	| %empty	{ $$ = new DefList; }
	;

SDEFS : SDEF SDEFS	{ $2->push_front($1); $$ = $2; }
	| %empty	{ $$ = new StDefList; }
	;

SDEF : TYPE SDECS SEMI	{ $$ = new StructDef($2); }
	;

SDECS : ID COMMA SDECS	{ $3->push_front(*$1); $$ = $3; }
	| ID				{ $$ = new SDecList{*$1}; }

DECS : DEC COMMA DECS	{ $3->push_front($1); $$ = $3; }
	| DEC				{ $$ = new DecList{$1}; }
	;

DEC : VAR			{ $$ = new Dec($1); }
	| VAR ASSIGN INIT { $$ = new Dec($1, $3); }
	;

VAR : ID		{ $$ = new IdVar(*$1); }
	| VAR LB INT RB	{ $$ = new ArrayVar($1, $3); }
	;

INIT : EXPS		{ $$ = new IntInit($1); }
	| LC ARGS RC { $$ = new ArrayInit($2); }
	;

EXP	: EXPS	{ $$ = $1; }
	| %empty	{ $$ = new NoExpr;}


EXPS : LP EXPS RP	{ $$ = $2; }
	| ID LP ARGS RP	{ $$ = new CallExpr(*$1, $3); }
	| ID ARRS		{ $$ = new ArrsExpr(*$1, $2); }
	| ID DOT ID		{ $$ = new AccessExpr(*$1, *$3); }
	| INT		{ $$ = new IntExpr($1);}
	| EXPS ASSIGN EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS ADD_ASSIGN EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS SUB_ASSIGN EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS MUL_ASSIGN EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS DIV_ASSIGN EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS AND_ASSIGN EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS XOR_ASSIGN EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS OR_ASSIGN EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS SHL_ASSIGN EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS SHR_ASSIGN EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS L_OR EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS L_AND EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS B_OR EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS B_XOR EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS B_AND EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS EQ EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS NEQ EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS GT EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS GTE EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS LT EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS LTE EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS SHL EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS SHR EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS ADD EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
		// binary minus
	| EXPS SUB EXPS 	{ $$ = new BopExpr(*$2, $1, $3); }
	| EXPS MUL EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS DIV EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
	| EXPS MOD EXPS	 { $$ = new BopExpr(*$2, $1, $3); }
		// unary minus
	| SUB   EXPS	%prec UMINUS 		{ $$ = new UopExpr(*$1, $2); }
	| L_NOT EXPS	 { $$ = new UopExpr(*$1, $2); }
	| P_ADD EXPS	 { $$ = new UopExpr(*$1, $2); }
	| P_SUB EXPS	 { $$ = new UopExpr(*$1, $2); }
	| B_NOT EXPS	 { $$ = new UopExpr(*$1, $2); }
	;

ARRS : LB EXP RB ARRS	{ $4->push_front($2); $$ = $4; }
	| %empty	{ $$ = new Arrs; }

ARGS : EXP COMMA ARGS	{ $3->push_front($1); $$ = $3; }
	| %empty	{ $$ = new Args; }

%%

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}