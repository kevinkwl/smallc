%{
#include "def.h"
#include "parser.hh"
#include <cstdio>
#define YY_NO_UNPUT

int curline = 0;
extern YYSTYPE yylval;
extern FILE *fin;

#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");


void save_num()
{
    yylval.ival = stoi(string(yytext), 0, 0); // autodetect base
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
"."     |
"+"     |
"*"     |
"/"     |
"%"     |
"<<"    |
">>"    |
">"     |
">="    |
"<"     |
"<="    |
"=="    |
"!="    |
"&"     |
"^"     |
"|"     |
"&&"    |
"||"    |
"="     |
"+="    |
"-="    |
"*="    |
"/="    |
"&="    |
"^="    |
"|="    |
"<<="   |
">>="   { save_str(); return(BINARYOP); }

    /* Unary Op */
"!"     |
"++"    |
"--"    { save_str(); return(UNARYOP); }

    /* Minus(-) need to be processed in parser */
"-"     { return('-');}

\n  ++curline;
{ws}        ;
.      { std::cerr << "Error token: "<< yytext << " found at line: " << curline << endl; }

%%
