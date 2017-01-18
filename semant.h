//
// Created by Kevin Ling on 07/01/2017.
//

#ifndef SMALLC_SEMANT_H
#define SMALLC_SEMANT_H
#include "def.h"
class AstNode;


/**
 * make all tables enter a new scope
 */
void enterScope();

/**
 * make all tables exit a scope
 */
void exitScope();

/**
 * put error into log
 * @param id
 * @param node
 */
void IdentifierNotDeclaredError(string id, AstNode *node);
void IdentifierRedeclaredError(string id, AstNode *node);
void TypeMismatchError(ExprType::type need, ExprType::type provided, AstNode *node);

void FunctionRedeclaredError(string id, AstNode *node);

void DuplicateParameterError(string id, AstNode *node);

void InitilizeError(string msg, AstNode *node);

void StructRedefined(string id, AstNode *node);
void StructFieldRedefinedError(string id, AstNode *node);

void StructNotDefined(string id, AstNode *node);

void ReturnTypeError(ExprType::type ,AstNode *node);

void CondTypeError(ExprType::type, AstNode *node);

void NotInLoop(AstNode *node);

void ArrayDimensionExceedError(AstNode *node);

void InitilizerNotCompileTimeConstantError(AstNode *node);

void FunctionNotDefined(string id, AstNode *node);

void WrongNumberOfArgument(AstNode *node);

void ArrayDimensionNotMatched(AstNode *node);

void ExpNotInt(AstNode *node);

void StructAccessFieldNonExist(string sid, string fid, AstNode *node);
#endif //SMALLC_SEMANT_H
