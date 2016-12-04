//
// Created by Kevin Ling on 18/11/2016.
//

#ifndef SMALLC_AST_H
#define SMALLC_AST_H

#include "def.h"



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
class StSpec;
class StDef;
typedef std::list<StDef*> StDefList;

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
class Exp;
typedef std::list<Exp*> Args;
typedef std::list<Exp*> Arrs;// array access

// <Type, Id>
typedef string Para;
typedef std::list<Para> Paras;

class Program : public AstNode {
protected:
    ExtDefList *extdefs;
public:
    Program(ExtDefList *defs);

    virtual void dump(ostream &os, int n) override;
};

class ExtDef : public AstNode {};

/**
 * Variable defs;
 */
class VarExtDef : public ExtDef {
private:
    ExtVarList *extvars;
public:
    VarExtDef(ExtVarList *extvars);

    virtual void dump(ostream &os, int n) override;
};

/**
 * Struct defs
 */
class StExtDef : public ExtDef {
private:
    StSpec *stspec;
    SExtVarList *sextvars;
public:
    StExtDef(StSpec *st, SExtVarList *slist);

    virtual void dump(ostream &os, int n) override;
};

/**
 * Function defs
 */
class FuncExtDef : public ExtDef {
private:
    string id;
    Paras *params;
    StmtBlock *stmtBlock;
public:
    FuncExtDef(string id, Paras *p, StmtBlock *stmtBlock);

    virtual void dump(ostream &os, int n) override;
};


/**
 * ExtVar
 */
class ExtVar : public AstNode {
protected:
    Var *var;
public:
    ExtVar(Var *var);

    virtual void dump(ostream &os, int n) override;
};
class InitExtVar : public ExtVar {
private:
    Init *init;
public:
    InitExtVar(Var *pvar, Init *pinit);

    virtual void dump(ostream &os, int n) override;
};

/**
 * StSpec
 */
class StSpec : public AstNode {
private:
    string id;
    StDefList *sdefs;
public:
    StSpec(string id);
    StSpec(string id, StDefList *sl);
    StSpec(StDefList *sl);

    virtual void dump(ostream &os, int n) override;
};

/**
 * Statement block
 */
class StmtBlock : public AstNode {
private:
    DefList *defs;
    StmtList *stmts;
public:
    StmtBlock(DefList *dl, StmtList *sl);

    virtual void dump(ostream &os, int n) override;
};

/**
 * Statements
 */
class Stmt : public AstNode {};
class ExpStmt : public Stmt {
private:
    Exp *exp;
public:
    ExpStmt(Exp *exp);

    virtual void dump(ostream &os, int n) override;
};

class BlockStmt : public Stmt {
private:
    StmtBlock *stmtBlock;
public:
    BlockStmt(StmtBlock *sb);

    virtual void dump(ostream &os, int n) override;
};

class ReturnStmt : public Stmt {
private:
    Exp *exp;
public:
    ReturnStmt(Exp *exp);

    virtual void dump(ostream &os, int n) override;
};

class IfStmt : public Stmt {
private:
    Exp *cond;
    Stmt *thenStmt;
    Stmt *elseStmt;
public:
    IfStmt(Exp *cond, Stmt *ts, Stmt *es = nullptr);

    virtual void dump(ostream &os, int n) override;
};

class ForStmt : public Stmt {
private:
    Exp *init;
    Exp *cond;
    Exp *update;
    Stmt *stmt;
public:
    ForStmt(Exp *e1, Exp *e2, Exp *e3, Stmt *stmt);

    virtual void dump(ostream &os, int n) override;
};

class ContStmt : public Stmt {
public:
    virtual void dump(ostream &os, int n) override;
};
class BreakStmt : public Stmt {
public:
    virtual void dump(ostream &os, int n) override;
};

/**
 * Def
 */
class Def : public AstNode {};
class VarDef : public Def {
private:
    DecList *decs;
public:
    VarDef(DecList *dl);

    virtual void dump(ostream &os, int n) override;
};

class SDef : public Def {
private:
    StSpec *stspec;
    SDecList *sdecs;
public:
    SDef(StSpec *sts, SDecList *sdl);

    virtual void dump(ostream &os, int n) override;
};


class Dec : public AstNode {
private:
    Var *var;
    Init *init;
public:
    Dec(Var *v, Init *in = nullptr);

    virtual void dump(ostream &os, int n) override;
};

class StDef : public AstNode {
private:
    SDecList *sdecs;
public:
    StDef(SDecList *sdl);

    virtual void dump(ostream &os, int n) override;
};

/**
 * Var
 */
class Var : public AstNode {};
class IdVar : public Var {
private:
    string id;
public:
    IdVar(string id);

    virtual void dump(ostream &os, int n) override;
};
class ArrayVar : public Var {
private:
    Var *var;
    int dim;
public:
    ArrayVar(Var *var, int dim);

    virtual void dump(ostream &os, int n) override;
};

/**
 * Init
 */
class Init : public AstNode {};
class IntInit : public Init {
private:
    Exp *exp;
public:
    IntInit(Exp *exp);

    virtual void dump(ostream &os, int n) override;
};
class ArrayInit : public Init {
private:
    Args *args;
public:
    ArrayInit(Args *args);

    virtual void dump(ostream &os, int n) override;
};

/**
 * Exp
 */
class Exp : public AstNode {};
class NoExp : public Exp {
public:
    virtual void dump(ostream &os, int n) override;
};
class BopExp : public Exp {
private:
    string op;
    Exp *lexp;
    Exp *rexp;
public:
    BopExp(string op, Exp *lexp, Exp *rexp);

    virtual void dump(ostream &os, int n) override;
};
class UopExp : public Exp {
private:
    string op;
    Exp *exp;
public:
    UopExp(string op, Exp *exp);

    virtual void dump(ostream &os, int n) override;
};
class CallExp : public Exp {
private:
    string id;
    Args *args;
public:
    CallExp(string id, Args *args);

    virtual void dump(ostream &os, int n) override;
};
class ArrsExp : public Exp {
private:
    string id;
    Arrs *arrs;
public:
    ArrsExp(string id, Arrs *arrs);

    virtual void dump(ostream &os, int n) override;
};
class AccessExp : public Exp {
private:
    string id;
    string member;
public:
    AccessExp(string id, string member);

    virtual void dump(ostream &os, int n) override;
};
class IntExp : public Exp {
private:
    int n;
public:
    IntExp(int n);

    virtual void dump(ostream &os, int n) override;
};
#endif //SMALLC_AST_H
