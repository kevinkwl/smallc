%{
#include <iostream>
using namespace std;

extern int yylex();


void yyerror(const char *s);
%}

%union {
    int ival;
    std::string* sval;
}
%token <ival> INT <sval> ID <sval> TYPE <sval> BINARYOP <sval> UNARYOP
%token SEMI COMMA LP RP LB RB LC RC STRUCT RETURN IF ELSE BREAK CONT FOR

%%
Test : '='
%%

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}