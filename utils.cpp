//
// Created by Kevin Ling on 12/11/2016.
//
// Some functions to help debug
//

#include "def.h"
#include "parser.hh"

string token_to_string(int tok)
{
    switch (tok) {
        case 0:            return("EOF");        break;
        case (ID):         return("ID");
        case (ELSE):       return("ELSE");       break;
        case (IF):         return("IF");         break;
        case (FOR):        return("FOR");       break;
        case (INT):        return("INT");       break;
        case (TYPE):       return("TYPE");     break;
        case (BINARYOP):   return("BOP");
        case (UNARYOP):    return("UOP");
        case '-':          return("MINUS");
        case (COMMA): return("','"); break;
        case (SEMI): return("';'"); break;
        case (LP): return("'('"); break;
        case (RP): return("')'"); break;
        case (LB): return("'['"); break;
        case (RB): return("']'"); break;
        case (LC): return("'{'"); break;
        case (RC): return("'}'"); break;
        case (RETURN):return("RETURN");
        case (STRUCT):return("STRUCT");
        case (BREAK):return("BREAK");
        case (CONT): return("CONT");
        default:  return("<Invalid Token>");
    }
}
void dump_token(ostream& os, int lineno, int token, YYSTYPE yylval)
{
    os << "#" << lineno << " " << token_to_string(token) << " ";
    switch (token) {
        case INT:
            os << yylval.ival << endl;
            break;
        case ID:
            os << *yylval.sval << endl;
            break;
        case UNARYOP:
        case BINARYOP:
            os << *yylval.sval << endl;
            break;
        case '-':
            os << '-' << endl;
            break;
        default:
            os << endl;
    }
}
