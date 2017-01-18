//
// Created by Kevin Ling on 07/01/2017.
//

#include "semant.h"
#include "symtab.h"
#include "ast.h"


static ostringstream err;
static int semant_errors = 0;

SymbolTable<Var*> IntVarTbl;
SymbolTable<StructSpec*> StVarTbl;
SymbolTable<StructSpec*> StSpecTbl;
SymbolTable<FuncExtDef*> funcTbl;

int inLoop = 0;


void enterScope() {
    IntVarTbl.enterscope();
    StVarTbl.enterscope();
    StSpecTbl.enterscope();
}

void exitScope() {
    IntVarTbl.exitscope();
    StVarTbl.exitscope();
    StSpecTbl.exitscope();
}

void IdentifierNotDeclaredError(string id, AstNode *node) {
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "use of undeclared identifier " << '\'' << id << '\'' << endl;
}

void IdentifierRedeclaredError(string id, AstNode *node) {
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "identifier " << '\'' << id << '\'' << " redeclared" << endl;
}

void FunctionRedeclaredError(string id, AstNode *node) {
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "function " << '\'' << id << '\'' << " redeclared" << endl;
}

void TypeMismatchError(ExprType::type need, ExprType::type provided, AstNode *node) {
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "type " << ExprType::toString(need) << " is needed, where " << ExprType::toString(provided) << " is provided."
        << endl;
}


void DuplicateParameterError(string id, AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "duplicate parameter " << '\'' << id << '\'' << endl;
}

void InitilizeError(string msg, AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << msg << endl;
}

void StructRedefined(string id, AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "struct " << '\'' << id << '\'' << " redefined" << endl;
}
void StructFieldRedefinedError(string id, AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "field " << '\'' << id << '\'' << " redefined" << endl;
}

void StructNotDefined(string id, AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "struct " << '\'' << id << '\'' << " is not defined." << endl;
}

void ReturnTypeError(ExprType::type tp,AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "should return INT, but " << ExprType::toString(tp) << " given." << endl;
}

void CondTypeError(ExprType::type tp, AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "condition expression should be INT, but " << ExprType::toString(tp) << " given." << endl;
}

void NotInLoop(AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "break and continue can only be used in a for-loop." << endl;
}

void ArrayDimensionExceedError(AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "The dimension of arrays should be no more than 2" << endl;
}

void InitilizerNotCompileTimeConstantError(AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "Initializer is not a compile time constant." << endl;
}

void FunctionNotDefined(string id, AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "use of undeclared function " << '\'' << id << '\'' << endl;
}

void WrongNumberOfArgument(AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "wrong number of arguments given." << endl;
}

void ArrayDimensionNotMatched(AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "Array access dimension not matched" << endl;
}

void ExpNotInt(AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "This exp does not give an INT value" << endl;
}

void StructAccessFieldNonExist(string sid, string fid, AstNode *node)
{
    ++semant_errors;
    err << "line " << node->get_line_number() << " " << RED << "error: " << RESET
        << "struct " << sid << " has no field " << '\'' << fid << '\''  << endl;
}


/**
 * -------------------------------------------------------------------------------------------
 * Implementation of semant analysis
 * -------------------------------------------------------------------------------------------
 */


void Program::semant(ostream &out)
{
    enterScope();
    funcTbl.enterscope();

    Paras* pp = new Paras;
    pp->push_front("x");
    FuncExtDef* read = new FuncExtDef("read", pp, nullptr);
    FuncExtDef* write = new FuncExtDef("write", pp, nullptr);
    funcTbl.put("read", read);
    funcTbl.put("write", write);


    for (auto pdef : *extdefs) {
        pdef->check();
    }

    exitScope();

    FuncExtDef* MainFunc = funcTbl.lookup("main");
    if (MainFunc == NULL || MainFunc->getParamCount() != 0) {
        ++semant_errors;
        err << "Program must contain a function int main()!" << endl;
    }

    funcTbl.exitscope();

    if (semant_errors > 0) {
        out << err.str();
        out << semant_errors << " errors found." << endl;
        //TODO: output "ERROR" to output file
        exit(1);
    }
}

void VarExtDef::check()
{
    for (auto extvar : *extvars)
        extvar->check();
}

void StructExtDef::check()
{
    StructSpec* spec = this->stspec->check();

    // change spec link to spec
    this->stspec = spec;

    if (!this->sextvars->empty()) {
        for (string& s: *this->sextvars) {
            if (StVarTbl.lookup(s) == NULL) {
                StVarTbl.put(s, spec);
            } else {
                IdentifierRedeclaredError(s, this);
            }
        }
    }
}

void FuncExtDef::check()
{
    if (funcTbl.lookup(this->id) != NULL) {
        ++semant_errors;
        FunctionRedeclaredError(this->id, this);
    } else {
        funcTbl.put(this->id, this);
        enterScope();

        // check for duplicate parameters
        if (!this->params->empty()) {
            for (string &s : *this->params) {
                if (IntVarTbl.lookup(s) == NULL) {
                    IntVarTbl.put(s, new IdVar(this->id));
                } else {
                    DuplicateParameterError(this->id, this);
                }
            }
        }

        this->stmtBlock->check();

        exitScope();
    }
}

void ExtVar::check()
{
    this->var->check();
}

void InitExtVar::check()
{
    this->var->check();
    int dim = this->var->getDim();

    if (dim > 1) {
        InitilizeError("Can't initilized array with dimension > 1", this);
    }

    this->init->check();
    if (!this->init->isConstant())
        InitilizerNotCompileTimeConstantError(this->init);

    if (this->var->getType() != this->init->getType() || this->var->getSize() >= this->init->getSize()) {
        InitilizeError("Incompatible initializer", this);
    }

    // if the number of initializer is smaller, then pad with 0
    if (this->var->getSize() >= this->init->getSize()) {
        int s1 = this->var->getSize();
        int s2 = this->init->getSize();
        ArrayInit* arri = dynamic_cast<ArrayInit*>(this->init);
        for (int i = s1-s2; i > 0; --i) {
            arri->args->push_back(new IntExpr(0));
        }
    }
}

StructSpec* StructSpec::check()
{
    if (this->id != "" && this->sdefs != NULL) {

        // check if defined in current scope
        if (StSpecTbl.probe(this->id) != NULL) {
            StructRedefined(this->id, this);
        }

        StSpecTbl.put(this->id, this);

        enterScope();
        for (StructDef* structdef : *this->sdefs)
            structdef->check();
        exitScope();
        return this;
    } else if (this->id == "" && this->sdefs != NULL) {

        enterScope();
        for (StructDef* structdef : *this->sdefs)
            structdef->check();
        exitScope();

        return this;
    } else if (this->id != "" && this->sdefs == NULL){
        StructSpec* spec = StSpecTbl.lookup(this->id);
        if (spec == NULL)
            StructNotDefined(this->id, this);

        return spec;
    } else {
        // should never reach here
        return NULL;
    }
}

void StmtBlock::check()
{
    enterScope();

    // check defs
    for (Def* def : *this->defs)
        def->check();

    // check stmts
    for (Stmt* stmt: *this->stmts)
        stmt->check();
    exitScope();
}

void ExprStmt::check()
{
    this->exp->check();
}

void BlockStmt::check()
{
    this->stmtBlock->check();
}

void ReturnStmt::check()
{
    ExprType::type tp = this->exp->check();
    if (tp != ExprType::INTEGER)
        ReturnTypeError(tp, this);
}

void IfStmt::check()
{
    ExprType::type cond_tp = this->cond->check();
    if (cond_tp != ExprType::INTEGER)
        CondTypeError(cond_tp, this);

    this->thenStmt->check();

    if (this->elseStmt != nullptr)
        this->elseStmt->check();
}

void ForStmt::check()
{
    this->init->check();
    ExprType::type cond_tp = this->cond->check();
    if (cond_tp != ExprType::INTEGER && cond_tp != ExprType::BLANK)
        CondTypeError(cond_tp, this);
    this->update->check();

    ++inLoop;
    this->stmt->check();
    --inLoop;
}

void ContStmt::check()
{
    if (!inLoop)
        NotInLoop(this);
}

void BreakStmt::check()
{
    if (!inLoop)
        NotInLoop(this);
}

void VarDef::check()
{
    for (Dec* dec: *this->decs)
        dec->check();
}

void SDef::check()
{
    StructSpec* spec = this->stspec->check();

    // change spec
    this->stspec = spec;
    if (!this->sdecs->empty()) {
        for (string& s: *this->sdecs) {
            if (StVarTbl.probe(s) == NULL) {
                StVarTbl.put(s, spec);
            } else {
                IdentifierRedeclaredError(s, this);
            }
        }
    }
}

void Dec::check()
{
    this->var->check();

    if (this->init != nullptr) {
        int dim = this->var->getDim();

        if (dim > 1) {
            InitilizeError("Can't initilized array with dimension > 1", this);
        }

        this->init->check();

        if (this->var->getType() != this->init->getType() || this->var->getSize() != this->init->getSize()) {
            InitilizeError("Incompatible initializer", this);
        }

        // if the number of initializer is smaller, then pad with 0
        if (this->var->getSize() >= this->init->getSize()) {
            int s1 = this->var->getSize();
            int s2 = this->init->getSize();
            ArrayInit* arri = dynamic_cast<ArrayInit*>(this->init);
            for (int i = s1-s2; i > 0; --i) {
                arri->args->push_back(new IntExpr(0));
            }
        }
    }
}

void StructDef::check()
{
    for (string& s: *this->sdecs) {
        if (IntVarTbl.probe(s) != NULL)
            StructFieldRedefinedError(s, this);
        else
            IntVarTbl.put(s, new IdVar(s));
    }
}

void IdVar::check(bool enter)
{
    if (IntVarTbl.probe(this->id) != NULL)
        IdentifierRedeclaredError(this->id, this);
    else {
        if (enter)
            IntVarTbl.put(this->id, this);
    }
}

void ArrayVar::check(bool enter)
{
    this->var->check(false);
    // The dimension of arrays will be no more than 2
    if (this->var->getDim() >= 2)
        ArrayDimensionExceedError(this);
    else {
        if (enter)
            IntVarTbl.put(this->var->getId(), this);
    }

}

void IntInit::check()
{
    ExprType::type tp = this->exp->check();
}

void ArrayInit::check()
{
    for (Expr* exp: *this->args) {
        ExprType::type tp = exp->check();
        if (tp != ExprType::INTEGER)
            InitilizeError("Initilizer not int", exp);
    }
}

ExprType::type NoExpr::check()
{
    return ExprType::BLANK;
}

ExprType::type BopExpr::check()
{
    auto ltp = this->lexp->check();
    auto rtp = this->rexp->check();

    // check if lval
    if (this->op.find("=") != std::string::npos && this->op != "=="
            && this->op != ">=" && this->op != "<="
            && this->op != "!=") {
        if (!this->lexp->isLval()) {
            ++semant_errors;
            err << "line " << this->get_line_number() << " " << "error: "
                << "not an lvalue" << endl;
        }
    }

    if (ltp == ExprType::INTEGER && rtp == ExprType::INTEGER)
        return ExprType::INTEGER;
    else
        return ExprType::ERROR;
}

ExprType::type UopExpr::check()
{
    auto tp = this->exp->check();
    if (tp == ExprType::INTEGER)
        return ExprType::INTEGER;
    else
        return ExprType::ERROR;
}

ExprType::type CallExpr::check()
{
    FuncExtDef* func = funcTbl.lookup(this->id);

    // add information
    this->func = func;

    if (func == NULL) {
        FunctionNotDefined(this->id, this);
    } else {
        // check number of arguments
        int n_args_prov = this->args->size();
        int n_args_need = func->getParamCount();
        if (n_args_need != n_args_prov)
            WrongNumberOfArgument(this);

        // check arguments
        for (Expr* exp: *this->args) {
            ExprType::type tp = exp->check();
            if (tp != ExprType::INTEGER)
                ExpNotInt(exp);

            if (this->id == "read" && !exp->isLval()) {
                ++semant_errors;
                err << "line " << exp->get_line_number() << " " << "error: "
                    << "not an lvalue" << endl;
            }
        }


    }
    // goes on checking (should be int)
    return ExprType::INTEGER;
}

ExprType::type ArrsExpr::check()
{
    Var* v = IntVarTbl.lookup(this->id);

    // annotate
    this->var = v;
    if (v == NULL) {
        IdentifierNotDeclaredError(this->id, this);
    } else {
        int dim = v->getDim();
        int ac = this->arrs->size();
        if (dim != ac) {
            ArrayDimensionNotMatched(this);
        } else {
            // check arguments
            for (Expr* exp: *this->arrs) {
                ExprType::type tp = exp->check();
                if (tp != ExprType::INTEGER)
                    ExpNotInt(exp);
            }
        }
    }
    return ExprType::INTEGER;
}

ExprType::type AccessExpr::check()
{
    StructSpec* spec = StVarTbl.lookup(this->id);

    // annotate
    this->spec = spec;

    if (spec == NULL) {
        IdentifierNotDeclaredError(this->id, this);
    } else {
        if (!spec->hasField(this->field))
            StructAccessFieldNonExist(this->id, this->field, this);
    }
    return ExprType::INTEGER;
}

ExprType::type IntExpr::check()
{
    return ExprType::INTEGER;
}






