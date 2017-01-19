//
// Created by Kevin Ling on 12/11/2016.
// This file contains some includes and declaration of utility types and functions.
//

#ifndef SMALLC_DEF_H
#define SMALLC_DEF_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cerrno>

using std::ostringstream;
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;
using std::list;
using std::pair;
using std::set;
using std::cerr;

string pad(int);
string token_to_string(int tok);

// types for analysis
namespace ExprType {
    enum type {
        STRUCT_VAR, INTEGER, FUNC, ARRAY, ERROR, BLANK
    };

    string toString(type t);
}

//enum BopType {
//    ASSIGN, ADD_ASSIGN, SUB_ASSIGN, MUL_ASSIGN, DIV_ASSIGN, AND_ASSIGN, XOR_ASSIGN, OR_ASSIGN, SHL_ASSIGN, SHR_ASSIGN,
//    L_OR,
//    L_AND,
//    B_OR,
//    B_XOR,
//    B_AND,
//    EQ, NEQ,
//    GT, GTE, LT, LTE,
//    SHL, SHR,
//    ADD, SUB,
//    MUL, DIV, MOD,
//     };
//enum UopType {UMINUS, L_NOT, P_ADD, P_SUB, B_NOT};
void mapinit();
//BopType bop_string2type(const string op);
//UopType uop_string2type(const string op);


//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#endif //SMALLC_DEF_H
