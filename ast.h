//
// Created by Kevin Ling on 18/11/2016.
// This file contains definitions of abstract syntax tree classes
//

#ifndef SMALLC_AST_H
#define SMALLC_AST_H

#include "def.h"
#include "IRgen.h"



class AstNode {
protected:
    int line_number;

public:
    AstNode();
    //virtual AstNode* clone()=0;
    virtual ~AstNode() { }
    virtual void dump(ostream& os, int n) = 0;
    int get_line_number();
};

/**
 * Forward declaration
 */
class ExtDef;
typedef std::list<ExtDef*> ExtDefList;
class ExtVar;
typedef std::list<ExtVar*> ExtVarList;
typedef string SExtVar;
typedef std::list<SExtVar> SExtVarList;
class StructSpec;
class StructDef;
typedef std::list<StructDef*> StructDefList;

class Stmt;
class StmtBlock;
typedef std::list<Stmt*> StmtList;
class Def;
typedef std::list<Def*> DefList;
class Dec;
typedef std::list<Dec*> DecList;
typedef string SDec;
typedef std::list<SDec> SDecList;
class Var;
class Init;
class Expr;
typedef std::list<Expr*> Args;
typedef std::list<Expr*> Arrs;// array access

// <Type, Id>
typedef string Para;
typedef std::list<Para> Paras;


/**
 * PROGRAM -> EXTDEFS
 */
class Program : public AstNode {
protected:
    ExtDefList *extdefs;
public:
    Program(ExtDefList *defs);
    void semant(ostream &out);
    void emit();

    virtual void dump(ostream &os, int n) override;
};

/**
 * EXTDEF -> TYPE EXTVARS SEMI                      ~ VarExtDef
 *         | STSPEC SEXTVARS SEMI                   ~ StructExtDef
 *         | TYPE ID LP PARAS RP STMTBLOCK          ~ FuncExtDef
 */
class ExtDef : public AstNode {
public:
    virtual void check() = 0;
    virtual void emit(IRGenerator *IRg) = 0;
};


/**
 * Variable defs;
 *
 * EXTDEF -> TYPE EXTVARS SEMI
 */
class VarExtDef : public ExtDef {
private:
    ExtVarList *extvars;
public:
    VarExtDef(ExtVarList *extvars);

    virtual void dump(ostream &os, int n) override;

    void check() override;

    void emit(IRGenerator *irg) override;
};


/**
 * Struct defs
 *
 * EXTDEF -> STSPEC SEXTVARS SEMI
 */
class StructExtDef : public ExtDef {
private:
    StructSpec *stspec;
    SExtVarList *sextvars;
public:
    StructExtDef(StructSpec *st, SExtVarList *slist);

    virtual void dump(ostream &os, int n) override;

    void check() override;
    void emit(IRGenerator *irg) override;
};

/**
 * Function defs
 *
 * EXTDEF -> TYPE ID LP PARAS RP STMTBLOCK
 */
class FuncExtDef : public ExtDef {
public:
    string id;
    Paras *params;
    StmtBlock *stmtBlock;
public:
    FuncExtDef(string id, Paras *p, StmtBlock *stmtBlock);

    virtual void dump(ostream &os, int n) override;

    void check() override;
    int getParamCount() const { return params->size(); }

    void emit(IRGenerator *irg) override;
};


/**
 * ExtVar
 *
 * EXTVAR -> VAR                ~ ExtVar
 *         | VAR ASSIGN INIT    ~ InitExtVar
 */
class ExtVar : public AstNode {
public:
    Var *var;

    ExtVar(Var *var);

    virtual void dump(ostream &os, int n) override;

    virtual void check();

    virtual void emit(IRGenerator *irg);

};

/**
 * EXTVAR -> VAR ASSIGN INIT
 */
class InitExtVar : public ExtVar {
public:
    Init *init;
    vector<int> *init_value;

    InitExtVar(Var *pvar, Init *pinit);

    virtual void dump(ostream &os, int n) override;

    void check() override;
    void emit(IRGenerator *irg) override;
};

/**
 * StructSpec
 *
 * STSPEC -> STRUCT ID LC SDEFS RC
 *         | STRUCT LC SDEFS RC
 *         | STRUCT ID;
 */
class StructSpec : public AstNode {
private:
    string id;
    StructDefList *sdefs;
public:
    vector<string> fields;

    StructSpec(string id);
    StructSpec(string id, StructDefList *sl);
    StructSpec(StructDefList *sl);

    virtual void dump(ostream &os, int n) override;
    StructSpec * check();

    bool hasField(string fld) const;
    unsigned int getOffset(string fld) const;
    unsigned int numOfEntries() const { return fields.size();}
};

/**
 * Statement block
 *
 * STMTBLOCK -> LC DEFS STMTS RC
 */
class StmtBlock : public AstNode {
private:
    DefList *defs;
    StmtList *stmts;
public:
    StmtBlock(DefList *dl, StmtList *sl);

    virtual void dump(ostream &os, int n) override;
    void check(bool fromFunc = false);

    Location* emit(IRGenerator *irg);
};

/**
 * Statements
 *
 * STMT -> EXP SEMI                                 ~ ExprStmt
 *       | STMTBLOCK                                ~ StmtBlock
 *       | RETURN EXP SEMI                          ~ ReturnStmt
 *       | IF LP EXP RP STMT                        ~ IfStmt
 *       | IF LP EXP RP STMT ELSE STMT              ~ IfStmt
 *       | FOR LP EXP SEMI EXP SEMI EXP RP STMT     ~ ForStmt
 *       | CONT SEMI                                ~ ContStmt
 *       | BREAK SEMI                               ~ BreakStmt
 */
class Stmt : public AstNode {
public:
    virtual void check() = 0;
    virtual Location* emit(IRGenerator *irg) = 0;
};
class ExprStmt : public Stmt {
private:
    Expr *exp;
public:
    ExprStmt(Expr *exp);

    virtual void dump(ostream &os, int n) override;

    void check() override;

    Location* emit(IRGenerator *irg) override;
};

class BlockStmt : public Stmt {
private:
    StmtBlock *stmtBlock;
public:
    BlockStmt(StmtBlock *sb);

    virtual void dump(ostream &os, int n) override;
    void check() override;

    Location* emit(IRGenerator *irg) override;
};

class ReturnStmt : public Stmt {
private:
    Expr *exp;
public:
    ReturnStmt(Expr *exp);

    virtual void dump(ostream &os, int n) override;
    void check() override;

    Location* emit(IRGenerator *irg) override;
};

class IfStmt : public Stmt {
private:
    Expr *cond;
    Stmt *thenStmt;
    Stmt *elseStmt;
public:
    IfStmt(Expr *cond, Stmt *ts, Stmt *es = nullptr);

    virtual void dump(ostream &os, int n) override;
    void check() override;

    Location* emit(IRGenerator *irg) override;
};

class ForStmt : public Stmt {
private:
    Expr *init;
    Expr *cond;
    Expr *update;
    Stmt *stmt;
public:
    ForStmt(Expr *e1, Expr *e2, Expr *e3, Stmt *stmt);

    virtual void dump(ostream &os, int n) override;
    void check() override;

    Location* emit(IRGenerator *irg) override;
};

class ContStmt : public Stmt {
public:
    virtual void dump(ostream &os, int n) override;
    void check() override;

    Location* emit(IRGenerator *irg) override;
};
class BreakStmt : public Stmt {
public:
    virtual void dump(ostream &os, int n) override;
    void check() override;

    Location* emit(IRGenerator *irg) override;
};

/**
 * Def
 *
 * DEF  -> TYPE DECS SEMI           ~ VarDef
 *       | STSPEC SDECS SEMI        ~ SDef
 */
class Def : public AstNode {
public:
    virtual void check() = 0;
    virtual void emit(IRGenerator *irg) = 0;
};
class VarDef : public Def {
private:
    DecList *decs;
public:
    VarDef(DecList *dl);

    virtual void dump(ostream &os, int n) override;
    void check() override;

    void emit(IRGenerator *irg) override;
};

class SDef : public Def {
private:
    StructSpec *stspec;
    SDecList *sdecs;
public:
    SDef(StructSpec *sts, SDecList *sdl);

    virtual void dump(ostream &os, int n) override;
    void check() override;

    void emit(IRGenerator *irg) override;
};

/**
 * DEC -> VAR
 *      | VAR ASSIGN INIT
 */
class Dec : public AstNode {
public:
    Var *var;
    Init *init;
public:
    Dec(Var *v, Init *in = nullptr);

    virtual void dump(ostream &os, int n) override;
    void check();
};

/**
 * SDEF -> TYPE SDECS SEMI
 *
 * only INT is supported as TYPE.
 */
class StructDef : public AstNode {
public:
    SDecList *sdecs;
public:
    StructDef(SDecList *sdl);

    virtual void dump(ostream &os, int n) override;
    void check();

    bool hasName(string id) const {
        auto it = std::find(sdecs->begin(), sdecs->end(), id);
        if (it != sdecs->end())
            return true;
        return false;
    }
};

/**
 * Var
 *
 * VAR -> ID                ~ IdVar
 *      | VAR LB INIT RB    ~ ArrayVar
 */
class Var : public AstNode {
public:
    virtual ExprType::type getType() const = 0;
    virtual void check(bool enter=true) = 0;
    virtual int getDim() = 0;
    virtual string getId() const = 0;
    virtual int getSize() const = 0;

    virtual int numOfEntries() const = 0;
};
class IdVar : public Var {
private:
    string id;
public:
    int value;
    IdVar(string id);

    virtual void dump(ostream &os, int n) override;

    ExprType::type getType() const override { return ExprType::INTEGER; }
    int getDim() override {
        return 0;
    }
    void check(bool enter=true) override;
    string getId() const override { return id; }
    int getSize() const override { return 0; }

    int numOfEntries() const override { return 1;}

};
class ArrayVar : public Var {
private:
    Var *var;
    int size;
public:
    ArrayVar(Var *var, int dim);

    virtual void dump(ostream &os, int n) override;
    ExprType::type getType() const override { return ExprType::ARRAY; }
    int getDim() override {
        return var->getDim() + 1;
    }
    void check(bool enter=true) override;
    string getId() const override { return var->getId(); }
    int getSize() const override { return this->size; }

    int numOfEntries() const override {
        return var->numOfEntries() * size;
    }
};

/**
 * Init
 *
 * INIT -> EXP              ~ IntInit
 *       | LC ARGS RC       ~ ArrayInit
 */
class Init : public AstNode {
public:
    vector<int> *value;
    virtual ExprType::type getType() const = 0;
    virtual void check() = 0;
    virtual int getSize() const = 0;
    virtual bool isConstant() const = 0;

    virtual void eval() = 0;
};
class IntInit : public Init {
public:
    Expr *exp;
    IntInit(Expr *exp);

    virtual void dump(ostream &os, int n) override;

    ExprType::type getType() const override {
        return ExprType::INTEGER;
    }

    void check() override;
    int getSize() const override { return 0; }
    bool isConstant() const override;

    virtual void eval() override;

};
class ArrayInit : public Init {
public:
    Args *args;
public:
    ArrayInit(Args *args);

    virtual void dump(ostream &os, int n) override;

    ExprType::type getType() const override {
        return ExprType::ARRAY;
    }

    void check() override;
    int getSize() const override { return this->args->size(); }

    bool isConstant() const override;
    virtual void eval() override;
};

/**
 * Expr
 *
 */
class Expr : public AstNode {
public:
    virtual ExprType::type check() = 0;
    virtual bool isConstant() const = 0;
    virtual bool isLval() const { return false; }

    virtual int eval() = 0;

    virtual Location* emit(IRGenerator *irg) = 0;
};
class NoExpr : public Expr {
public:
    virtual void dump(ostream &os, int n) override;
    ExprType::type check() override;

    bool isConstant() const override {
        return true;
    }

    int eval() override { return 0; }

    Location* emit(IRGenerator *irg) override { return NULL; }
};
class BopExpr : public Expr {
private:
    string op;
    Expr *lexp;
    Expr *rexp;
public:
    BopExpr(string op, Expr *lexp, Expr *rexp);

    virtual void dump(ostream &os, int n) override;
    ExprType::type check() override;

    bool isConstant() const override {
        return lexp->isConstant() && rexp->isConstant();
    }

    int eval() override;

    Location* emit(IRGenerator *irg) override;
};
class UopExpr : public Expr {
private:
    string op;
    Expr *exp;
public:
    UopExpr(string op, Expr *exp);

    virtual void dump(ostream &os, int n) override;
    ExprType::type check() override;

    bool isConstant() const override {
        return op == "-" && exp->isConstant();
    }

    int eval() override;

    Location* emit(IRGenerator *irg) override;
};
class CallExpr : public Expr {
private:
    string id;
    Args *args;
public:

    FuncExtDef* func;
    CallExpr(string id, Args *args);

    virtual void dump(ostream &os, int n) override;
    ExprType::type check() override;

    bool isConstant() const override {
        return false;
    }
    // not compile time
    int eval() override { return 0;}

    Location* emit(IRGenerator *irg) override;

};
class ArrsExpr : public Expr {
private:
    string id;
    Arrs *arrs;
public:
    Var* var;
    ArrsExpr(string id, Arrs *arrs);

    virtual void dump(ostream &os, int n) override;
    ExprType::type check() override;

    bool isConstant() const override {
        return false;
    }
    bool isLval() const override {
        return true;
    }

    // not compile time if actually an array access
    int eval() override {
        if (arrs->empty())
            return (dynamic_cast<IdVar*>(var))->value;
        return 0;
    }

    Location* emit(IRGenerator *irg) override;
    Location* emitMemoryLocation(IRGenerator *irg);
};
class AccessExpr : public Expr {
private:
    string id;
    string field;

public:
    StructSpec* spec;

    AccessExpr(string id, string member);

    virtual void dump(ostream &os, int n) override;
    ExprType::type check() override;

    bool isConstant() const override {
        return false;
    }
    bool isLval() const override {
        return true;
    }

    // not compile time
    int eval() override { return 0;}

    Location* emit(IRGenerator *irg) override;
    Location* emitMemoryLocation(IRGenerator *irg);
};
class IntExpr : public Expr {
private:
    int n;
public:
    IntExpr(int n);

    virtual void dump(ostream &os, int n) override;
    ExprType::type check() override;

    bool isConstant() const override {
        return true;
    }

    int eval() override { return n;}

    Location* emit(IRGenerator *irg) override;
};
#endif //SMALLC_AST_H
