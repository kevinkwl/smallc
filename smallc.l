%{
#include "def.h"
#include "parser.hh"
#include <cstdio>
#include <stdexcept>
#define YY_NO_UNPUT

extern int curr_lineno;
extern YYSTYPE yylval;
extern FILE *fin;

#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

#define YY_USER_ACTION \
	yylloc = curr_lineno;


void save_num()
{
    try {
 	    yylval.ival = stoi(string(yytext), 0, 0); // autodetect base
    } catch (std::invalid_argument& e) {
    	std::cerr << "Error token: "<< yytext << " found at line: " << curr_lineno
    			  << ": invalid number."<< endl;
	  	yylval.ival = 0;
    } catch (std::out_of_range& e) {
		std::cerr << "Error token: "<< yytext << " found at line: " << curr_lineno
				  << ": out of range( -2^(31), 2^(31) )."<< endl;
		yylval.ival = 0;
    }
}
void save_str()
{
    yylval.sval = new string(yytext);
}
%}

integer ([0-9]+|0[xX][0-9a-f]+)
id     [_a-zA-Z][_a-zA-Z0-9]*
ws     [ \t]
%%

"int"         return(TYPE);
";"         return(SEMI);
","         return(COMMA);
"("         return(LP);
")"         return(RP);
"["         return(LB);
"]"         return(RB);
"{"         return(LC);
"}"         return(RC);
"struct"      return(STRUCT);
"return"      return(RETURN);
"if"          return(IF);
"else"        return(ELSE);
"break"       return(BREAK);
"continue"    return(CONT);
"for"         return(FOR);

{integer}       { save_num(); return(INT); }
{id}        { save_str(); return(ID);  }

    /* Binary Op */
"."    { save_str(); return(DOT); }
"+"    { save_str(); return(ADD); }
"*"    { save_str(); return(MUL); }
"/"    { save_str(); return(DIV); }
"%"    { save_str(); return(MOD); }
"<<"   { save_str(); return(SHL); }
">>"   { save_str(); return(SHR); }
">"    { save_str(); return(GT); }
">="   { save_str(); return(GTE); }
"<"    { save_str(); return(LT); }
"<="   { save_str(); return(LTE); }
"=="   { save_str(); return(EQ); }
"!="   { save_str(); return(NEQ); }
"&"    { save_str(); return(B_AND); }
"^"    { save_str(); return(B_XOR); }
"|"    { save_str(); return(B_OR); }
"&&"   { save_str(); return(L_AND); }
"||"   { save_str(); return(L_OR); }
"="    { save_str(); return(ASSIGN); }
"+="   { save_str(); return(ADD_ASSIGN); }
"-="   { save_str(); return(SUB_ASSIGN); }
"*="   { save_str(); return(MUL_ASSIGN); }
"/="   { save_str(); return(DIV_ASSIGN); }
"&="   { save_str(); return(AND_ASSIGN); }
"^="   { save_str(); return(XOR_ASSIGN); }
"|="   { save_str(); return(OR_ASSIGN); }
"<<="  { save_str(); return(SHL_ASSIGN); }
">>="   { save_str(); return(SHR_ASSIGN); }

    /* Unary Op */
"!"     { save_str(); return(L_NOT); }
"++"    { save_str(); return(P_ADD); }
"--"    { save_str(); return(P_SUB); }

    /* Minus(-) need to be processed in parser */
"-"     { return(SUB);}

\n  ++curr_lineno;
{ws}        ;
.      { std::cerr << "Error token: "<< yytext << " found at line: " << curr_lineno << endl; }

%%
