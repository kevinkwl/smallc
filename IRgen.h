/**
 * This file contains declarations of IRGenerator for IR generation
 */

#ifndef SMALLC_IRGEN_H
#define SMALLC_IRGEN_H

#include "def.h"
#include <stdlib.h>
#include "tac.h"
#include "symtab.h"



// These codes are used to identify the built-in functions
typedef enum { ReadInteger, PrintInt, NumBuiltIns } BuiltIn;

class IRGenerator {
private:
    std::list<Instruction*> *code;
    std::list<Instruction*> *data;

public:
    // Here are some class constants to remind you of the offsets
    // used for globals, locals, and parameters. You will be
    // responsible for using these when assigning Locations.
    // In a MIPS stack frame, first local is at fp-8, subsequent locals
    // are at fp-12, fp-16, and so on. The first param is at fp+4,
    // subsequent ones as fp+8, fp+12, etc. (Because methods have secret
    // "this" passed in first param slot at fp+4, all normal params
    // are shifted up by 4.)  First global is at offset 0 from global
    // pointer, all subsequent at +4, +8, etc.
    // Conveniently, all vars are 4 bytes in size for code generation
    static const int OffsetToFirstLocal = -8,
            OffsetToFirstParam = 4,
            OffsetToFirstGlobal = 0;
    static const int VarSize = 4;
    int currentStackSize;

    SymbolTable<Location*>* varLocs;

    void InsertLocation(string name, Location* l) { this->varLocs->put(name, l); }
    Location* GetLocation(string name) { return this->varLocs->lookup(name); }
    void NewScope() { this->varLocs->enterscope(); }
    void RemoveScope() { this->varLocs->exitscope(); }



    IRGenerator();

    // Assigns a new unique label name and returns it. Does not
    // generate any Tac instructions (see GenLabel below if needed)
    string NewLabel();

    // Returns a location for a global variable
    Location *GenGlobalVar(const string name, unsigned int size, vector<int> *init);
    //Location *GenGlobalArrayVar(const string name, int size, vector<int> *init);

    // Gets a new location on the stack
    Location *GetNewLocationOnStack(const string name);
    Location *GetNewBulkLocationOnStack(const string name, unsigned int size);

    // Creates and returns a Location for a new uniquely named
    // temp variable. Does not generate any Tac instructions
    Location *GenTempVar();

    // Generates Tac instructions to load a constant value. Creates
    // a new temp var to hold the result. The constant
    // value is passed as an integer, it can be 0 for integer zero,
    // false for bool, NULL for null object, etc. All are just 4-byte
    // zero in the code generation world.
    // The second overloaded version is used for string constants.
    // The LoadLabel method loads a label into a temporary.
    // Each of the methods returns a Location for the temp var
    // where the constant was loaded.
    Location *GenLoadConstant(int value);
    Location *GenLoadLabel(const string label);
    Location *GenLoadAddress(Location *ref);

    // Tries to Optimize Intermediate Representation (Turn on with make opt=1)
    void OptimizeIR();
//    void Optimize_CSER(List<Instruction*>* bb);
//    void Optimize_CP(List<Instruction*>* bb);
 //   void Optimize_LA(List<Instruction*>* bb);

    // Generates Tac instructions to copy value from one location to another
    void GenAssign(Location *dst, Location *src);

    // Generates Tac instructions to dereference addr and store value
    // into that memory location. addr should hold a valid memory address
    // (most likely computed from an array or field offset calculation).
    // The optional offset argument can be used to offset the addr by a
    // positive/negative number of bytes. If not given, 0 is assumed.
    void GenStore(Location *addr, Location *val, int offset = 0);

    // Generates Tac instructions to dereference addr and load contents
    // from a memory location into a new temp var. addr should hold a
    // valid memory address (most likely computed from an array or
    // field offset calculation). Returns the Location for the new
    // temporary variable where the result was stored. The optional
    // offset argument can be used to offset the addr by a positive or
    // negative number of bytes. If not given, 0 is assumed.
    Location *GenLoad(Location *addr, int offset = 0);


    // Generates Tac instructions to perform one of the binary ops
    // identified by string name, such as "+" or "==".  Returns a
    // Location object for the new temporary where the result
    // was stored.
    Location *GenBinaryOp(string opName, Location *op1, Location *op2);


    // Generates the Tac instruction for pushing a single
    // parameter. Used to set up for ACall and LCall instructions.
    // The Decaf convention is that parameters are pushed right
    // to left (so the first argument is pushed last)
    void GenPushParam(Location *param);

    // Generates the Tac instruction for popping parameters to
    // clean up after an ACall or LCall instruction. All parameters
    // are removed with one adjustment of the stack pointer.
    void GenPopParams(int numBytesOfParams);

    // Generates the Tac instructions for a LCall, a jump to
    // a compile-time label. The params to the target routine
    // should already have been pushed. If hasReturnValue is
    // true,  a new temp var is created, the fn result is stored
    // there and that Location is returned. If false, no temp is
    // created and NULL is returned
    Location *GenLCall(const string label);

    Location *GenWrite(Location *src);
    Location *GenRead(Location *dst);

    // These methods generate the Tac instructions for various
    // control flow (branches, jumps, returns, labels)
    // One minor detail to mention is that you can pass NULL
    // (or omit arg) to GenReturn for a return that does not
    // return a value
    void GenIfZ(Location *test, const string label);
    void GenGoto(const string label);
    void GenReturn(Location *val = NULL);
    void GenLabel(const string label);



    // These methods generate the Tac instructions that mark the start
    // and end of a function/method definition.
    BeginFunc *GenBeginFunc();
    void GenEndFunc();


    // Emits the final "object code" for the program by
    // translating the sequence of Tac instructions into their mips
    // equivalent and printing them out to stdout. If the debug
    // flag tac is on (-d tac), it will not translate to MIPS,
    // but instead just print the untranslated Tac. It may be
    // useful in debugging to first make sure your Tac is correct.
    void DoFinalCodeGen();
};
#endif //SMALLC_IRGEN_H
