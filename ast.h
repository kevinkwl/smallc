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
class StructSpec;
class StructDef;
typedef std::list<StructDef*> StDefList;

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

    virtual void dump(ostream &os, int n) override;
};

/**
 * EXTDEF -> TYPE EXTVARS SEMI                      ~ VarExtDef
 *         | STSPEC SEXTVARS SEMI                   ~ StructExtDef
 *         | TYPE ID LP PARAS RP STMTBLOCK          ~ FuncExtDef
 */
class ExtDef : public AstNode {};


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
};

/**
 * Function defs
 *
 * EXTDEF -> TYPE ID LP PARAS RP STMTBLOCK
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
 *
 * EXTVAR -> VAR                ~ ExtVar
 *         | VAR ASSIGN INIT    ~ InitExtVar
 */
class ExtVar : public AstNode {
protected:
    Var *var;
public:
    ExtVar(Var *var);

    virtual void dump(ostream &os, int n) override;
};

/**
 * EXTVAR -> VAR ASSIGN INIT
 */
class InitExtVar : public ExtVar {
private:
    Init *init;
public:
    InitExtVar(Var *pvar, Init *pinit);

    virtual void dump(ostream &os, int n) override;
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
    StDefList *sdefs;
public:
    StructSpec(string id);
    StructSpec(string id, StDefList *sl);
    StructSpec(StDefList *sl);

    virtual void dump(ostream &os, int n) override;
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
class Stmt : public AstNode {};
class ExprStmt : public Stmt {
private:
    Expr *exp;
public:
    ExprStmt(Expr *exp);

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
    Expr *exp;
public:
    ReturnStmt(Expr *exp);

    virtual void dump(ostream &os, int n) override;
};

class IfStmt : public Stmt {
private:
    Expr *cond;
    Stmt *thenStmt;
    Stmt *elseStmt;
public:
    IfStmt(Expr *cond, Stmt *ts, Stmt *es = nullptr);

    virtual void dump(ostream &os, int n) override;
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
 *
 * DEF  -> TYPE DECS SEMI           ~ VarDef
 *       | STSPEC SDECS SEMI        ~ SDef
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
    StructSpec *stspec;
    SDecList *sdecs;
public:
    SDef(StructSpec *sts, SDecList *sdl);

    virtual void dump(ostream &os, int n) override;
};

/**
 * DEC -> VAR
 *      | VAR ASSIGN INIT
 */
class Dec : public AstNode {
private:
    Var *var;
    Init *init;
public:
    Dec(Var *v, Init *in = nullptr);

    virtual void dump(ostream &os, int n) override;
};

/**
 * SDEF -> TYPE SDECS SEMI
 *
 * only INT is supported as TYPE.
 */
class StructDef : public AstNode {
private:
    SDecList *sdecs;
public:
    StructDef(SDecList *sdl);

    virtual void dump(ostream &os, int n) override;
};

/**
 * Var
 *
 * VAR -> ID                ~ IdVar
 *      | VAR LB INIT RB    ~ ArrayVar
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
    int idx;
public:
    ArrayVar(Var *var, int dim);

    virtual void dump(ostream &os, int n) override;
};

/**
 * Init
 *
 * INIT -> EXP              ~ IntInit
 *       | LC ARGS RC       ~ ArrayInit
 */
class Init : public AstNode {};
class IntInit : public Init {
private:
    Expr *exp;
public:
    IntInit(Expr *exp);

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
 * Expr
 *
 */
class Expr : public AstNode {};
class NoExpr : public Expr {
public:
    virtual void dump(ostream &os, int n) override;
};
class BopExpr : public Expr {
private:
    string op;
    Expr *lexp;
    Expr *rexp;
public:
    BopExpr(string op, Expr *lexp, Expr *rexp);

    virtual void dump(ostream &os, int n) override;
};
class UopExpr : public Expr {
private:
    string op;
    Expr *exp;
public:
    UopExpr(string op, Expr *exp);

    virtual void dump(ostream &os, int n) override;
};
class CallExpr : public Expr {
private:
    string id;
    Args *args;
public:
    CallExpr(string id, Args *args);

    virtual void dump(ostream &os, int n) override;
};
class ArrsExpr : public Expr {
private:
    string id;
    Arrs *arrs;
public:
    ArrsExpr(string id, Arrs *arrs);

    virtual void dump(ostream &os, int n) override;
};
class AccessExpr : public Expr {
private:
    string id;
    string member;
public:
    AccessExpr(string id, string member);

    virtual void dump(ostream &os, int n) override;
};
class IntExpr : public Expr {
private:
    int n;
public:
    IntExpr(int n);

    virtual void dump(ostream &os, int n) override;
};
#endif //SMALLC_AST_H
