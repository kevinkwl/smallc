#include <iostream>
#include "def.h"
#include "ast.h"

//
//  The lexer keeps this global variable up to date with the line number
//  of the current line read from the input.
//
int curr_lineno = 1;
bool genTAC = false;

FILE *fin;   // This is the file pointer from which the lexer reads its input.

extern int yylex();
extern int yyparse();

extern Program* ast_root;

void usage()
{
    cout << "Usage: ./scc input_file output_file [-tac]" << endl;
    cout << "       specify -tac to generate three address code to output_file" << endl;
}

void parseCmdline(int argc, char** argv)
{
    if (argc < 3) {
        usage();
        exit(-1);
    }

    if ((fin = fopen(argv[1], "r")) == NULL) {
        cerr << "Cannot open file " << argv[1] << endl;
        exit(-1);
    }

    if ((freopen(argv[2], "w", stdout)) == NULL) {
        cerr << "Cannot open file " << argv[2] << endl;
        exit(-1);
    }

    if (argc > 3 && !strcmp("-tac", argv[3]))
        genTAC = true;
}

int main(int argc, char** argv)
{
    parseCmdline(argc, argv);
//    fin = fopen("tests/queen.sc", "r");
    // parse through the input until there is no more:
    do {
        yyparse();
    } while (!feof(fin));
//    ast_root->dump(cerr, 0);
    ast_root->semant(cerr);
    ast_root->emit();
    fclose(fin);
    fclose(stdout);
    return 0;
}



