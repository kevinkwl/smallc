/**
 *
 * Implementations of ast classes
 */

#include "ast.h"

int node_lineno = 1;
AstNode::AstNode() { line_number = node_lineno;}

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



StructExtDef::StructExtDef(StructSpec *st, SExtVarList *slist)
: stspec(st), sextvars(slist){}

void StructExtDef::dump(ostream &os, int n) {
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
    os << ")" << endl;
    stmtBlock->dump(os, n);
}


ExtVar::ExtVar(Var *var) : var(var) {}

void ExtVar::dump(ostream &os, int n) {
    var->dump(os, 0);
}

InitExtVar::InitExtVar(Var *pvar, Init *pinit)
: ExtVar(pvar), init(pinit) {
    init_value = new vector<int>();
}

void InitExtVar::dump(ostream &os, int n) {
    ExtVar::dump(os, n);
    os << "=";
    init->dump(os, n);
}



StructSpec::StructSpec(string id) : id(id), sdefs(NULL){}

StructSpec::StructSpec(string id, StructDefList *sl) : id(id), sdefs(sl){}

StructSpec::StructSpec(StructDefList *sl) : id(""), sdefs(sl){}

void StructSpec::dump(ostream &os, int n) {
    os << pad(n) << "struct " << id ;
    if (!sdefs->empty()) {
        os << " {" << endl;
        for (StructDef* sd : *sdefs) {
            sd->dump(os, n + 4);
        }
        os << "}";
    }
}

bool StructSpec::hasField(string fld) const {
    for (StructDef* def: *this->sdefs) {
        if (def->hasName(fld))
            return true;
    }
    return false;
}

unsigned int StructSpec::getOffset(string fld) const {
    int offset = 0;
    if (fields.size() > 0) {
        auto it = std::find(fields.begin(), fields.end(), fld);

        if (it != fields.end())
            offset = it - fields.begin();
    }
    return offset;
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

ExprStmt::ExprStmt(Expr *exp) : exp(exp){}

void ExprStmt::dump(ostream &os, int n) {
    exp->dump(os, n);
    os << ";" << endl;
}

BlockStmt::BlockStmt(StmtBlock *sb) : stmtBlock(sb){}

void BlockStmt::dump(ostream &os, int n) {
    stmtBlock->dump(os, n);
}

ReturnStmt::ReturnStmt(Expr *exp) : exp(exp){}

void ReturnStmt::dump(ostream &os, int n) {
    os << pad(n) << "return ";
    exp->dump(os, 0);
    os << ";" << endl;
}

IfStmt::IfStmt(Expr *cond, Stmt *ts, Stmt *es)
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

ForStmt::ForStmt(Expr *e1, Expr *e2, Expr *e3, Stmt *stmt)
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

SDef::SDef(StructSpec *sts, SDecList *sdl) : stspec(sts), sdecs(sdl){}

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

StructDef::StructDef(SDecList *sdl) : sdecs(sdl){}

void StructDef::dump(ostream &os, int n) {
    os << pad(n) << "int ";
    for (auto iter = sdecs->cbegin(); iter != sdecs->cend(); ++iter) {
        if (iter != sdecs->cbegin())
            os << ", ";
        os << *iter;
    }
    os << ";" << endl;
}


IdVar::IdVar(string id) : id(id){}

void IdVar::dump(ostream &os, int n) {
    os << pad(n) << id;
}

ArrayVar::ArrayVar(Var *var, int index) : var(var), size(index){}

void ArrayVar::dump(ostream &os, int n) {
    os << pad(n);
    var->dump(os, 0);
    os << '[' << size << ']';
}


IntInit::IntInit(Expr *exp) : exp(exp){
    value = new vector<int>();
}

void IntInit::dump(ostream &os, int n) {
    exp->dump(os, n);
}

bool IntInit::isConstant() const
{
    return this->exp->isConstant();
}

void IntInit::eval() {
    int v = this->exp->eval();
    //cout << "# compute: " << v << endl;
    value->push_back(v);
}
ArrayInit::ArrayInit(Args *args) : args(args){
    value = new vector<int>();
}

void ArrayInit::dump(ostream &os, int n) {
    os << pad(n) << '{';
    for (auto iter = args->cbegin(); iter != args->cend(); ++iter) {
        if (iter != args->cbegin())
            os << ", ";
        (*iter)->dump(os, 0);
    }
    os << '}';
}

bool ArrayInit::isConstant() const
{
    for (Expr* exp: *this->args) {
        if (!exp->isConstant())
            return false;
    }
    return true;
}

void ArrayInit::eval() {
    for (Expr* exp: *this->args) {
        int v = exp->eval();
        //cout << "# compute: " << v << endl;
        value->push_back(v);
    }
}

BopExpr::BopExpr(string op, Expr *lexp, Expr *rexp)
: op(op), lexp(lexp), rexp(rexp) {}

void BopExpr::dump(ostream &os, int n) {
    os << pad(n);
    os << '(';
    lexp->dump(os, 0);
    os << ')';
    os << op << '(';
    rexp->dump(os, 0);
    os << ')';
}

int BopExpr::eval() {
    int i1 = lexp->eval();
    int i2 = rexp->eval();
    if (op == "+")
        return i1 + i2;
    else if (op == "-")
        return i1 - i2;
    else if (op == "*")
        return i1 * i2;
    else if (op == "/") {
        if (i2 == 0) {
            cerr << "zero divisor initializer" << endl;
            exit(1);
        }
        return i1 / i2;
    }
    else if (op == "%") {
        if (i2 == 0) {
            cerr << "zero divisor (modulo) initializer" << endl;
            exit(1);
        }
        return i1 % i2;
    }
    else if (op == "<<")
        return i1 << i2;
    else if (op == ">>")
        return i1 >> i2;
    else if (op == ">")
        return i1 > i2;
    else if (op == ">=")
        return i1 >= i2;
    else if (op == "<")
        return i1 < i2;
    else if (op == "<=")
        return i1 <= i2;
    else if (op == "==")
        return i1 == i2;
    else if (op == "!=")
        return i1 != i2;
    else if (op == "&")
        return i1 & i2;
    else if (op == "^")
        return i1 ^ i2;
    else if (op == "|")
        return i1 | i2;
    else if (op == "&&")
        return i1 && i2;
    else if (op == "||")
        return i1 || i2;
    else
        return i1 + i2;
}

UopExpr::UopExpr(string op, Expr *exp) : op(op), exp(exp) {}

void UopExpr::dump(ostream &os, int n) {
    os << pad(n) << op;
    exp->dump(os, 0);
}

int UopExpr::eval() {
    int i = exp->eval();

    // only "-"
    if (op == "-")
        return -i;

    // others are not compile time constant
    return i;
}

CallExpr::CallExpr(string id, Args *args) : id(id), args(args){}

void CallExpr::dump(ostream &os, int n) {
    os << pad(n) << id << '(';
    for (auto iter = args->cbegin(); iter != args->cend(); ++iter) {
        if (iter != args->cbegin())
            os << ", ";
        (*iter)->dump(os, 0);
    }
    os << ')';
}

ArrsExpr::ArrsExpr(string id, Arrs *arrs) : id(id), arrs(arrs){}

void ArrsExpr::dump(ostream &os, int n) {
    os << pad(n) << id;
    for (auto iter = arrs->cbegin(); iter != arrs->cend(); ++iter) {
        if (iter != arrs->cbegin())
            os << ", ";
        os << '[';
        (*iter)->dump(os, 0);
        os << ']';
    }

}

AccessExpr::AccessExpr(string id, string member) : id(id), field(member){}

void AccessExpr::dump(ostream &os, int n) {
    os << pad(n) << id << '.' << field;
}

IntExpr::IntExpr(int n) : n(n){}

void IntExpr::dump(ostream &os, int n) {
    os << pad(n) << this->n;
}


void NoExpr::dump(ostream &os, int n) {
}


