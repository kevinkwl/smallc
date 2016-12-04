#include <iostream>
#include <unistd.h>     // for getopt
#include "def.h"
#include "ast.h"
//
//  The lexer keeps this global variable up to date with the line number
//  of the current line read from the input.
//
extern int curline;

FILE *fin;   // This is the file pointer from which the lexer reads its input.

extern int yylex();
extern int yyparse();

extern Program* ast_root;

int main(int argc, char** argv) {

    fin = fopen("tests/exp.c", "r");
    if (fin == NULL) {
        std::cerr << "Could not open input file " << argv[optind] << std::endl;
        exit(1);
    }

    // parse through the input until there is no more:
    do {
        yyparse();
    } while (!feof(fin));
    ast_root->dump(cout, 4);
    fclose(fin);
    exit(0);
}



