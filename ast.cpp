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

Program::Program(ExtDefList *defs): extdefs(defs){}

void Program::dump(ostream &os, int n) {
    for (ExtDef *def : *extdefs) {
        def->dump(os, n);
    }
}


VarExtDef::VarExtDef(ExtVarList *extvars): extvars(extvars){}
void VarExtDef::dump(ostream &os, int n) {
    os << pad(n) << "int";
    for (ExtVar *extvar : *extvars) {
        os << " ";
        extvar->dump(os, n);
    }
    os << ";" << endl;
}


StExtDef::StExtDef(StSpec *st, SExtVarList *slist)
: stspec(st), sextvars(slist){}

void StExtDef::dump(ostream &os, int n) {
    stspec->dump(os, n);
    for (SExtVar sv : *sextvars) {
        os << " " << sv;
    }
    os << ";" << endl;
}


FuncExtDef::FuncExtDef(string id, Paras *p, StmtBlock *stmtBlock)
: id(id), params(p), stmtBlock(stmtBlock){}

void FuncExtDef::dump(ostream &os, int n) {
    os << pad(n) << "int";
    os << " " << id << "(";
    for (auto iter = params->cbegin(); iter != params->cend(); ++iter) {
        if (iter != params->cbegin())
            os << ", ";
        os << "int " << *iter;
    }
    os << endl << "{" << endl;
    stmtBlock->dump(os, n+4);
    os << "}" << endl;
}


ExtVar::ExtVar(Var *var) : var(var) {}

void ExtVar::dump(ostream &os, int n) {
    var->dump(os, 0);
}

InitExtVar::InitExtVar(Var *pvar, Init *pinit)
: ExtVar(pvar), init(pinit){}

void InitExtVar::dump(ostream &os, int n) {
    ExtVar::dump(os, n);
    os << "=";
    init->dump(os, n);
}


StSpec::StSpec(string id) : id(id), sdefs(new StDefList){}

StSpec::StSpec(string id, StDefList *sl) : id(id), sdefs(sl){}

StSpec::StSpec(StDefList *sl) : id(""), sdefs(sl){}

void StSpec::dump(ostream &os, int n) {
    os << pad(n) << "struct " << id;
    if (!sdefs->empty()) {
        for (StDef* sd : *sdefs) {
            sd->dump(os, n + 4);
        }
    }
}


StmtBlock::StmtBlock(DefList *dl, StmtList *sl) : defs(dl), stmts(sl){}

void StmtBlock::dump(ostream &os, int n) {
    os << pad(n) << "{" << endl;
    for (Def* df : *defs) {
        df->dump(os, n+4);
    }
    for (Stmt* st : *stmts) {
        st->dump(os, n+4);
    }
    os << pad(n) << "}" << endl;
}

ExpStmt::ExpStmt(Exp *exp) : exp(exp){}

void ExpStmt::dump(ostream &os, int n) {
    exp->dump(os, n);
}

BlockStmt::BlockStmt(StmtBlock *sb) : stmtBlock(sb){}

void BlockStmt::dump(ostream &os, int n) {
    stmtBlock->dump(os, n);
}

ReturnStmt::ReturnStmt(Exp *exp) : exp(exp){}

void ReturnStmt::dump(ostream &os, int n) {
    os << pad(n) << "return ";
    exp->dump(os, n);
    os << endl;
}

IfStmt::IfStmt(Exp *cond, Stmt *ts, Stmt *es)
: cond(cond), thenStmt(ts), elseStmt(es){}

void IfStmt::dump(ostream &os, int n) {
    os << pad(n) << "if (";
    cond->dump(os, 0);
    os << ")" << endl;
    thenStmt->dump(os, n+4);
    if (elseStmt != nullptr) {
        os << pad(n) << "else" << endl;
        elseStmt->dump(os, n+4);
    }
}

ForStmt::ForStmt(Exp *e1, Exp *e2, Exp *e3, Stmt *stmt)
: init(e1), cond(e2), update(e3), stmt(stmt){}

void ForStmt::dump(ostream &os, int n) {
    os << pad(n) << "for (";
    if (init != nullptr)
        init->dump(os, 0);
    os << ";" << endl;
    if (cond != nullptr)
        cond->dump(os, 0);
    if (stmt != nullptr) {
        os << pad(n) << "else" << endl;
        stmt->dump(os, n+4);
    }
}

void ContStmt::dump(ostream &os, int n) {
    os << pad(n) << "continue;" << endl;
}

void BreakStmt::dump(ostream &os, int n) {
    os << pad(n) << "break;" << endl;
}

VarDef::VarDef(DecList *dl) : decs(dl){}

void VarDef::dump(ostream &os, int n) {
    os << pad(n) << "int ";
    for (auto iter = decs->cbegin(); iter != decs->cend(); ++iter) {
        if (iter != decs->cbegin())
            os << ", ";
        (*iter)->dump(os, 0);
    }
    os << ";\n";
}

SDef::SDef(StSpec *sts, SDecList *sdl) : stspec(sts), sdecs(sdl){}

void SDef::dump(ostream &os, int n) {
    stspec->dump(os, n);
    for (auto iter = sdecs->cbegin(); iter != sdecs->cend(); ++iter) {
        if (iter != sdecs->cbegin())
            os << ", ";
        os << *iter;
    }
    os << ";\n";
}

Dec::Dec(Var *v, Init *in) : var(v), init(in){}

void Dec::dump(ostream &os, int n) {
    var->dump(os, 0);
    if (init != nullptr) {
        os << "=";
        init->dump(os, 0);
    }
}

StDef::StDef(SDecList *sdl) : sdecs(sdl){}

void StDef::dump(ostream &os, int n) {
    os << pad(n) << "int ";
    for (auto iter = sdecs->cbegin(); iter != sdecs->cend(); ++iter) {
        if (iter != sdecs->cbegin())
            os << ", ";
        os << *iter;
    }
}


IdVar::IdVar(string id) : id(id){}

void IdVar::dump(ostream &os, int n) {
    os << pad(n) << id;
}

ArrayVar::ArrayVar(Var *var, int dim) : var(var), dim(dim){}

void ArrayVar::dump(ostream &os, int n) {
    os << pad(n);
    var->dump(os, 0);
    os << '[' << dim << ']';
}


IntInit::IntInit(Exp *exp) : exp(exp){}

void IntInit::dump(ostream &os, int n) {
    exp->dump(os, n);
}

ArrayInit::ArrayInit(Args *args) : args(args){}

void ArrayInit::dump(ostream &os, int n) {
    os << pad(n) << '{';
    for (auto iter = args->cbegin(); iter != args->cend(); ++iter) {
        if (iter != args->cbegin())
            os << ", ";
        (*iter)->dump(os, 0);
    }
    os << '}';
}

BopExp::BopExp(string op, Exp *lexp, Exp *rexp)
: op(op), lexp(lexp), rexp(rexp) {}

void BopExp::dump(ostream &os, int n) {
    os << pad(n);
    os << '(';
    lexp->dump(os, 0);
    os << ')';
    os << op << '(';
    rexp->dump(os, 0);
    os << ')';
}

UopExp::UopExp(string op, Exp *exp) : op(op), exp(exp) {}

void UopExp::dump(ostream &os, int n) {
    os << pad(n) << op;
    exp->dump(os, 0);
}

CallExp::CallExp(string id, Args *args) : id(id), args(args){}

void CallExp::dump(ostream &os, int n) {
    os << pad(n) << id << '(';
    for (auto iter = args->cbegin(); iter != args->cend(); ++iter) {
        if (iter != args->cbegin())
            os << ", ";
        (*iter)->dump(os, 0);
    }
    os << ')';
}

ArrsExp::ArrsExp(string id, Arrs *arrs) : id(id), arrs(arrs){}

void ArrsExp::dump(ostream &os, int n) {
    os << pad(n) << id;
    for (auto iter = arrs->cbegin(); iter != arrs->cend(); ++iter) {
        if (iter != arrs->cbegin())
            os << ", ";
        os << '[';
        (*iter)->dump(os, 0);
        os << ']';
    }

}

AccessExp::AccessExp(string id, string member) : id(id), member(member){}

void AccessExp::dump(ostream &os, int n) {
    os << pad(n) << id << '.' << member;
}

IntExp::IntExp(int n) : n(n){}

void IntExp::dump(ostream &os, int n) {
    os << pad(n) << this->n;
}


void NoExp::dump(ostream &os, int n) {
}


