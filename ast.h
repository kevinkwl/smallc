//
// Created by Kevin Ling on 18/11/2016.
//

#ifndef SMALLC_AST_H
#define SMALLC_AST_H

#include "def.h"

/**
 * Only need Int
 */
enum Type { INT };
enum BopType { ADD, MINUS, MUL, DIV };
enum UopType {};

class AstNode {
protected:
    int line_number;
public:
    AstNode();
    virtual AstNode* clone()=0;
    virtual ~AstNode() { }
    virtual void dump(ostream* os, int n) = 0;
    int get_line_number();
};

/**
 * Forward declaration
 */
class ExtDef;
using ExtDefList = std::list<ExtDef*>;
class ExtVar;
using ExtVarList = std::list<ExtVar*>;
class SExtVar;
using SExtVarList = std::list<SExtVar*>;
class StSpec;
class StDef;
using StDefList = std::list<StDef*>;
class Func;
class Stmt;
class StmtBlock;
using StmtList = std::list<Stmt*>;
class Def;
using DefList = std::list<Def*>;
class Dec;
using DecList = std::list<Dec*>;
using SDecList = std::list<string>;
class Var;
class Init;
class Exp;
using Args = std::list<Exp*>;
using Arrs = std::list<Exp*>; // array access

// <Type, Id>
using Para = pair<string, string>;
using Paras = std::list<Para*>;

class Program : public AstNode {
protected:
    ExtDefList *extdefs;
public:
    Program(ExtDefList *defs);
};

class ExtDef : public AstNode {};

/**
 * Variable defs;
 */
class VarExtDef : public ExtDef {
private:
    Type type;
    ExtVarList *extvars;
public:
    VarExtDef(Type type, ExtVarList *extvars);

    virtual AstNode *clone() override;

    virtual void dump(ostream *os, int n) override;
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
};

/**
 * Function defs
 */
class FuncExtDef : public ExtDef {
private:
    Type ret_type;
    string id;
    Paras *params;

};

/**
 * ExtVar
 */
class ExtVar : public AstNode {
private:
    Var *var;
public:
    ExtVar(Var *pvar);
};
class InitExtVar : public ExtVar {
private:
    Init *init;
public:
    InitExtVar(Var *pvar, Init *pinit);
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
};

class BlockStmt : public Stmt {
private:
    StmtBlock *stmtBlock;
public:
    BlockStmt(StmtBlock *sb);
};

class ReturnStmt : public Stmt {
private:
    Exp *exp;
public:
    ReturnStmt(Exp *exp);
};

class IfStmt : public Stmt {
private:
    Exp *cond;
    Stmt *thenStmt;
    Stmt *elseStmt;
public:
    IfStmt(Exp *cond, Stmt *ts, Stmt *es = nullptr);
};

class ForStmt : public Stmt {
private:
    Exp *init;
    Exp *cond;
    Exp *update;
    Stmt *stmt;
public:
    ForStmt(Exp *e1, Exp *e2, Exp *e3, Stmt *stmt);
};

class ContStmt : public Stmt {};
class BreakStmt : public Stmt {};

/**
 * Def
 */
class Def : public AstNode {};
class VarDef : public Def {
private:
    Type type;
    DecList *decs;
public:
    VarDef(Type type, DecList *dl);
};

class SDef : public Def {
private:
    StSpec *stspec;
    SDecList *sdecs;
public:
    SDef(StSpec *sts, SDecList *sdl);
};


class Dec : public AstNode {
private:
    Var *var;
    Init *init;
public:
    Dec(Var *v, Init *in = nullptr);
};

class StDef : public AstNode {
private:
    Type type;
    SDecList *sdecs;
public:
    StDef(Type type, SDecList *sdl);
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
};
class ArrayVar : public Var {
private:
    Var *var;
    int dim;
public:
    ArrayVar(Var *var, int dim);
};

/**
 * Init
 */
class Init : public AstNode {};
class VarInit : public Init {
private:
    Exp *exp;
public:
    VarInit(Exp *exp);
};
class StInit : public Init {
private:
    Args *args;
public:
    StInit(Args *args);
};

/**
 * Exp
 */
class Exp : public AstNode {};
class BopExp : public Exp {
private:
    BopType type;
    Exp *lexp;
    Exp *rexp;
public:
    BopExp(string op, Exp *lexp, Exp *rexp);
};
class UopExp : public Exp {
private:
    UopType type;
    Exp *exp;
public:
    UopExp(string op, Exp *exp);
};
class CallExp : public Exp {
private:
    string id;
    Args *args;
public:
    CallExp(string id, Args *args);
};
class ArrsExp : public Exp {
private:
    string id;
    Arrs *arrs;
public:
    ArrsExp(string id, Arrs *arrs);
};
class AccessExp : public Exp {
private:
    string id;
    string member;
public:
    AccessExp(string id, string member);
};
class IntExp : public Exp {
private:
    int n;
public:
    IntExp(int n);
};
#endif //SMALLC_AST_H
