//
// Created by Kevin Ling on 18/11/2016.
//

#include "ast.h"

int node_lineno = 1;
AstNode::AstNode() { line_number = node_lineno; }

int AstNode::get_line_number()
{
    return line_number;
}

Program::Program(ExtDefList *defs): {

}

AstNode *VarExtDef::clone() {
    return nullptr;
}

void VarExtDef::dump(ostream *os, int n) {

}
