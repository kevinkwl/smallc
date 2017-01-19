//
// implementations of ast emit method (emit tac)
//

#include "ast.h"
#include <string>

std::list<string> exitLabel;
std::list<string> updateLabel;

void Program::emit()
{
    IRGenerator* irg = new IRGenerator();

    // emit global variables
    for (auto pdef: *extdefs)
        if (dynamic_cast<VarExtDef*>(pdef) != NULL ||
                dynamic_cast<StructExtDef*>(pdef) != NULL)
            pdef->emit(irg);

    // emit functions
    for (auto pdef: *extdefs)
        if (dynamic_cast<FuncExtDef*>(pdef) != NULL)
            pdef->emit(irg);

    irg->DoFinalCodeGen();
}

/**
 *
 * Global Definitions
 *
 */

void FuncExtDef::emit(IRGenerator *irg)
{
    irg->NewScope();

    string tmp = "f_" + this->id;
    irg->GenLabel(tmp);

    if (this->id == "main")
        irg->GenLabel("main");

    BeginFunc* bf = irg->GenBeginFunc();

    // gen stack space for parameter
    int onStackParam = 0;
    for (const string &p : *params) {
        irg->InsertLocation(p, new Location(fpRelative, 4 + onStackParam * 4, p));
        ++onStackParam;
    }

    this->stmtBlock->emit(irg);

    bf->SetFrameSize(irg->currentStackSize * 4);
    irg->GenEndFunc();

    irg->RemoveScope();
}

void StructExtDef::emit(IRGenerator *irg)
{
    if (!this->sextvars->empty()) {
        for (string &v: *sextvars) {
            Location *l;
            string name = "_" + v;
            l = irg->GenGlobalVar(name, this->stspec->numOfEntries(), NULL);
            irg->InsertLocation(v, l);
        }
    }
}

void VarExtDef::emit(IRGenerator *irg)
{
    for (ExtVar* var: *(this->extvars))
        var->emit(irg);
}

void ExtVar::emit(IRGenerator *irg)
{
    string name = "_" + var->getId();
    Location *l;
    l = irg->GenGlobalVar(name, var->numOfEntries() ,NULL);
    irg->InsertLocation(var->getId(), l);
}

void InitExtVar::emit(IRGenerator *irg)
{
    string name = "_" + var->getId();
    Location *l;
    l = irg->GenGlobalVar(name, var->numOfEntries(), this->init_value);
    irg->InsertLocation(var->getId(), l);
}


/**
 *
 *  Statements
 *
 */

Location* StmtBlock::emit(IRGenerator *irg)
{
    irg->NewScope();
    for (Def *def: *defs)
        def->emit(irg);

    for (Stmt *stmt: *stmts)
        stmt->emit(irg);

    irg->RemoveScope();

    return NULL;
}


Location* ExprStmt::emit(IRGenerator *irg) 
{
    return this->exp->emit(irg);
}

Location* BlockStmt::emit(IRGenerator *irg) 
{
    return this->stmtBlock->emit(irg);
}

Location* ReturnStmt::emit(IRGenerator *irg) 
{
    Location* l = this->exp->emit(irg);
    irg->GenReturn(l);
    
    return NULL;
}

Location* IfStmt::emit(IRGenerator *irg) 
{
    Location* testL = this->cond->emit(irg);
    string nextLabel = irg->NewLabel();
    
    if (elseStmt != nullptr) {
        string elseLabel = irg->NewLabel();
        irg->GenIfZ(testL, elseLabel);
        this->thenStmt->emit(irg);
        irg->GenGoto(nextLabel);
        irg->GenLabel(elseLabel);
        this->elseStmt->emit(irg);
    } else {
        irg->GenIfZ(testL, nextLabel);
        this->thenStmt->emit(irg);
    }

    irg->GenLabel(nextLabel);
    return NULL;    
    
}

Location* ForStmt::emit(IRGenerator *irg)
{
    this->init->emit(irg);
    string loopStartL = irg->NewLabel();
    string loopEndL = irg->NewLabel();
    string loopUpdateL = irg->NewLabel();

    // label for inner break , continue
    exitLabel.push_front(loopEndL);
    updateLabel.push_front(loopUpdateL);

    irg->GenLabel(loopStartL);
    Location* testL = cond->emit(irg);
    irg->GenIfZ(testL, loopEndL);

    stmt->emit(irg);
    irg->GenLabel(loopUpdateL);
    update->emit(irg);
    irg->GenGoto(loopStartL);

    irg->GenLabel(loopEndL);

    exitLabel.pop_front();
    updateLabel.pop_front();
    return NULL;

}

Location* ContStmt::emit(IRGenerator *irg)
{
    irg->GenGoto(updateLabel.front());
    return NULL;
}

Location* BreakStmt::emit(IRGenerator *irg)
{
    irg->GenGoto(exitLabel.front());
    return NULL;
}



/**
 *
 * Def
 *
 */
void VarDef::emit(IRGenerator *irg)
{
    for (Dec* dec: *decs) {
        unsigned entries = dec->var->numOfEntries();

        Location* l = irg->GetNewBulkLocationOnStack(dec->var->getId(), entries);
        irg->InsertLocation(dec->var->getId(), l);

        // initializing
        if (dec->init != nullptr) {
            IntInit *init;
            if ((init = dynamic_cast<IntInit*>(init)) != NULL) {
                Location *initLoc = init->exp->emit(irg);
                irg->GenAssign(l, initLoc);
            }
            ArrayInit *ainit;
            if ((ainit = dynamic_cast<ArrayInit*>(init)) != NULL) {
                int arg_count = 0;
                for (Expr *exp: *(ainit->args)) {
                    Location *res = exp->emit(irg);
                    irg->GenAssign(new Location(fpRelative, l->GetOffset() + 4 * arg_count,
                                                dec->var->getId() + "[" + std::to_string(arg_count) + "]"),
                                    res);
                    ++arg_count;
                }
            }
        }
    }
}

void SDef::emit(IRGenerator *irg) 
{
    unsigned entries = this->stspec->numOfEntries();
    for (string &s : *sdecs) {
        Location *l = irg->GetNewBulkLocationOnStack(s, entries);
        irg->InsertLocation(s, l);
    }
}


/**
 *
 *  Expressions
 *
 */


Location* BopExpr::emit(IRGenerator *irg)
{
    Location* lres = lexp->emit(irg);
    Location* rres = rexp->emit(irg);

    if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%"
            || op == "<<" || op == ">>" || op == ">"  || op == ">="
            || op == "<" || op == "<=" || op == "==" || op == "!="
            || op == "&" || op == "^" || op == "|") {
        return irg->GenBinaryOp(op, lres, rres);
    } else if (op == "&&") {
        Location* zero = irg->GenLoadConstant(0);

        Location* llres = irg->GenBinaryOp("!=", zero, lres);
        Location* rrres = irg->GenBinaryOp("!=", zero, rres);
        return irg->GenBinaryOp("&", llres, rrres);
    } else if (op == "||") {
        Location* zero = irg->GenLoadConstant(0);

        Location* llres = irg->GenBinaryOp("!=", zero, lres);
        Location* rrres = irg->GenBinaryOp("!=", zero, rres);
        return irg->GenBinaryOp("|", llres, rrres);
    } else if (op == "=" || op == "+=" || op == "-=" || op == "*="
                || op == "/=" || op == "&=" || op == "^=" || op == "|="
                || op == "<<=" || op == ">>=") {
        Location* res = rres;
        if (op == "+=" || op == "-=" || op == "*=" || op == "/="
                || op == "&=" || op == "^=" || op == "|=") {
            res = irg->GenBinaryOp(op.substr(0, 1), lres, rres);
        } else if (op != "=") {
            res = irg->GenBinaryOp(op.substr(0,2), lres, rres);
        }

        if (dynamic_cast<ArrsExpr*>(lexp) != NULL) {
            Location *l_ref = dynamic_cast<ArrsExpr*>(lexp)->emitMemoryLocation(irg);
            //if (dynamic_cast<ArrsExpr*>(lexp)->var->getDim() == 0)
            //    irg->GenAssign(l_ref, res);
            //else
                irg->GenStore(l_ref, res);
        } else if (dynamic_cast<AccessExpr*>(lexp)!= NULL) {
            Location *l_ref = dynamic_cast<AccessExpr*>(lexp)->emitMemoryLocation(irg);
            irg->GenStore(l_ref, res);
        } else {
            // should never reach here
        }
        return res;
    }
    return lres;
}

Location* UopExpr::emit(IRGenerator *irg)
{
    Location* l = exp->emit(irg);
    Location* zero = irg->GenLoadConstant(0);
    Location* one = irg->GenLoadConstant(1);
    if (op == "-") {
        return irg->GenBinaryOp("-", zero, l);
    } else if (op == "!") {
        return irg->GenBinaryOp("==", zero, l);
    } else if (op == "++" || op == "--") {
        Location* res;
        if (op == "++") {
            res = irg->GenBinaryOp("+", l, one);
        } else {
            res = irg->GenBinaryOp("-", l, one);
        }

        if (dynamic_cast<ArrsExpr*>(exp) != NULL) {
            Location *l_ref = dynamic_cast<ArrsExpr*>(exp)->emitMemoryLocation(irg);
            irg->GenStore(l_ref, res);
        } else if (dynamic_cast<AccessExpr*>(exp) != NULL) {
            Location *l_ref = dynamic_cast<AccessExpr*>(exp)->emitMemoryLocation(irg);
            irg->GenStore(l_ref, res);
        } else {
            // should never reach here
        }
        return res;
    } else if (op == "~") {
        Location* neg_one = irg->GenLoadConstant(-1);
        return irg->GenBinaryOp("^", l, neg_one);
    } else {
        // should never reach here
    }
}
Location* CallExpr::emit(IRGenerator *irg)
{
    if (func->id != "write" && func->id != "read") {
        int callCounter = 0;
        Location *rtn = NULL;

        std::list<Expr *>::iterator it = args->end();
        it--;
        for (int i = this->func->getParamCount() - 1; i >= 0; i--) {
            Location *tmp = (*it)->emit(irg);
            irg->GenPushParam(tmp);
            callCounter++;
            --it;
        }

        rtn = irg->GenLCall("f_" + func->id);
        irg->GenPopParams(callCounter * 4);

        return rtn;
    } else if (func->id == "write") {
        //TODO: write call
        Location* tmp = args->front()->emit(irg);
        irg->GenWrite(tmp);
        return NULL;

    } else {
        // read
        Expr* arg = args->front();
        Location* ref;
        Location* res;
        if (dynamic_cast<ArrsExpr*>(arg) != NULL) {
            ref = (dynamic_cast<ArrsExpr*>(arg))->emitMemoryLocation(irg);
            res = irg->GenRead(ref);
            //irg->GenStore(ref, res);
        } else if (dynamic_cast<AccessExpr*>(arg) != NULL) {
            ref = (dynamic_cast<AccessExpr*>(arg))->emitMemoryLocation(irg);
            res = irg->GenRead(ref);
            //irg->GenStore(ref, res);
        } else {
            // should never reach here
        }
        return res;
    }
}
Location* ArrsExpr::emit(IRGenerator *irg)
{
    if (var->getDim() == 0) {
        Location* l = irg->GetLocation(var->getId());
        l->locationRef = true;
        return l;
    }
    return irg->GenLoad(this->emitMemoryLocation(irg));
}

Location* ArrsExpr::emitMemoryLocation(IRGenerator *irg)
{
    Location* base = irg->GetLocation(var->getId());
    Location* baseLoc = irg->GenLoadAddress(base);
    int dim = var->getDim();
    if (dim == 0) {
        baseLoc->locationRef = true;
        return baseLoc;
    } else {
        Location* fourL = irg->GenLoadConstant(4);
        Location* arg0 = arrs->front()->emit(irg);
        Location* baseLoc = irg->GenLoadAddress(base);

        if (dim == 1) {
            Location* fl = irg->GenBinaryOp("+", baseLoc, irg->GenBinaryOp("*", arg0, fourL));
            fl->locationRef = true;
            return fl;
        } else {
            // two dimension
            int numInRow = var->getSize();
            Location* col = irg->GenLoadConstant(numInRow);
            Location* arg1 = arrs->back()->emit(irg);
            Location* tmp = irg->GenBinaryOp("+", irg->GenBinaryOp("*", arg0, col), arg1);

            Location* fl = irg->GenBinaryOp("+", baseLoc, irg->GenBinaryOp("*", tmp, fourL));
            fl->locationRef = true;
            return fl;
        }
    }
}

Location* AccessExpr::emit(IRGenerator *irg)
{
    return irg->GenLoad(this->emitMemoryLocation(irg));
}

Location* AccessExpr::emitMemoryLocation(IRGenerator *irg)
{
    Location* base = irg->GetLocation(id);
    Location* baseLoc = irg->GenLoadAddress(base);
    baseLoc->locationRef = true;
    int offset = spec->getOffset(field);
    if (offset == 0) {
        return baseLoc;
    } else {
        Location* tmp = irg->GenLoadConstant(offset);
        Location* fourL = irg->GenLoadConstant(4);
        Location* fl = irg->GenBinaryOp("+", baseLoc, irg->GenBinaryOp("*", tmp, fourL));
        fl->locationRef = true;
        return fl;
    }
}

Location* IntExpr::emit(IRGenerator *irg)
{
    return irg->GenLoadConstant(n);
}
