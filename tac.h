//
// This file contains declarations of Three Address Code classes
//

#ifndef SMALLC_TAC_H
#define SMALLC_TAC_H

#include <cstring>
#include "def.h"

class Mips;


// A Location object is used to identify the operands to the
// various TAC instructions. A Location is either fp or gp
// relative (depending on whether in stack or global segemnt)
// and has an offset relative to the base of that segment.
// For example, a declaration for integer num as the first local
// variable in a function would be assigned a Location object
// with name "num", segment fpRelative, and offset -8.

typedef enum {fpRelative, gpRelative} Segment;

class Location
{
protected:
    const string variableName;
    Segment segment;
    int offset;

public:
    Location(Segment seg, int offset, const string name);

    const string GetName() const     { return variableName; }
    Segment GetSegment() const      { return segment; }
    int GetOffset() const           { return offset; }

    bool locationRef;

    bool operator==(const Location& that) const {
        return this->GetName() == that.GetName() &&
       this->GetSegment() == that.GetSegment() &&
       this->GetOffset() == that.GetOffset();
    }
};



// base class from which all Tac instructions derived
// has the interface for the 2 polymorphic messages: Print & Emit

class Instruction {
protected:
    char printed[128];

public:
    virtual ~Instruction() {}
    virtual void Print();
    virtual void EmitSpecific(Mips *mips) = 0;
    virtual void Emit(Mips *mips);
};



// for convenience, the instruction classes are listed here.
// the interfaces for the classes follows below

class LoadConstant;
class LoadStringConstant;
class LoadLabel;
class Assign;
class Load;
class Store;
class BinaryOp;
class Label;
class Goto;
class IfZ;
class BeginFunc;
class EndFunc;
class Return;
class PushParam;
class RemoveParams;
class LCall;
class ACall;
class GlobalData;
class ReadInt;
class WriteInt;
class LoadAddress;

class ReadInt: public Instruction {
    Location *dst;
public:
    ReadInt(Location *dst);
    void EmitSpecific(Mips *mips);
};

class WriteInt: public Instruction {
    Location *src;
public:
    WriteInt(Location *src);
    void EmitSpecific(Mips *mips);
};


class GlobalData: public Instruction {
    const string label;
    int size;
    vector<int> *initializer;
public:
    GlobalData(const string label, int size, vector<int> *init);
    void EmitSpecific(Mips *mips);
};


class LoadConstant: public Instruction {
    Location *dst;
    int val;
public:
    LoadConstant(Location *dst, int val);
    void EmitSpecific(Mips *mips);
};

class LoadAddress: public Instruction {
    Location *ref;
    Location *dst;
public:
    LoadAddress(Location *dst, Location *re);
    void EmitSpecific(Mips *mips);
};

class LoadLabel: public Instruction {
    Location *dst;
    const string label;
public:
    LoadLabel(Location *dst, const string label);
    void EmitSpecific(Mips *mips);
};

class Assign: public Instruction {
public:
    Location *dst, *src;
    Assign(Location *dst, Location *src);
    void EmitSpecific(Mips *mips);
    Location* getDst() { return dst; }
    Location* getSrc() { return src; }
};

class Load: public Instruction {
    Location *dst, *src;
    int offset;
public:
    Load(Location *dst, Location *src, int offset = 0);
    void EmitSpecific(Mips *mips);
};

class Store: public Instruction {
    Location *dst, *src;
    int offset;
public:
    Store(Location *d, Location *s, int offset = 0);
    void EmitSpecific(Mips *mips);
};

class BinaryOp: public Instruction {

public:
    typedef enum {Mul, Div, Mod, Add, Sub, Shl, Shr, Gt, Ge, Lt, Le, Eq, Neq, And, Xor, Or, InvalidOpCode, NumOps} OpCode;
    static const string opName[NumOps];
    static OpCode OpCodeForName(const string name);

protected:
    OpCode code;
    Location *dst, *op1, *op2;
public:
    BinaryOp(OpCode c, Location *dst, Location *op1, Location *op2);
    void EmitSpecific(Mips *mips);
    Location* GetDst() { return dst; }
    Location* GetOp1() { return op1; }
    Location* GetOp2() { return op2; }
    OpCode GetOpCode() { return code; }
};

class Label: public Instruction {
    const string label;
public:
    Label(const string label);
    void Print();
    void EmitSpecific(Mips *mips);
};

class Goto: public Instruction {
    const string label;
public:
    Goto(const string label);
    void EmitSpecific(Mips *mips);
};

class IfZ: public Instruction {
    Location *test;
    const string label;
public:
    IfZ(Location *test, const string label);
    void EmitSpecific(Mips *mips);
};

class BeginFunc: public Instruction {
    int frameSize;
public:
    BeginFunc();
    // used to backpatch the instruction with frame size once known
    void SetFrameSize(int numBytesForAllLocalsAndTemps);
    void EmitSpecific(Mips *mips);
};

class EndFunc: public Instruction {
public:
    EndFunc();
    void EmitSpecific(Mips *mips);
};

class Return: public Instruction {
    Location *val;
public:
    Return(Location *val);
    void EmitSpecific(Mips *mips);
};

class PushParam: public Instruction {
    Location *param;
public:
    PushParam(Location *param);
    Location* GetParam() { return param; }
    void EmitSpecific(Mips *mips);
};

class PopParams: public Instruction {
    int numBytes;
public:
    PopParams(int numBytesOfParamsToRemove);
    void EmitSpecific(Mips *mips);
};

class LCall: public Instruction {
    const string label;
    Location *dst;
public:
    LCall(const string labe, Location *result);
    void EmitSpecific(Mips *mips);
};

class ACall: public Instruction {
    Location *dst, *methodAddr;
public:
    ACall(Location *meth, Location *result);
    void EmitSpecific(Mips *mips);
};

#endif //SMALLC_TAC_H
