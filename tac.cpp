//
// Created by Kevin Ling on 17/01/2017.
//
/* File: tac.cc
 * ------------
 * Implementation of Location class and Instruction class/subclasses.
 */

#include "tac.h"
#include "mips.h"
#include <cstdio>
#include <string.h>
#include <string>

Location::Location(Segment s, int o, const string name) :
        variableName(name), segment(s), offset(o){
    locationRef = false;
}


void Instruction::Print() {
    printf("\t%s ;\n", printed);
}

void Instruction::Emit(Mips *mips) {
    if (*printed)
        mips->Emit("# %s", printed);   // emit TAC as comment into assembly
    EmitSpecific(mips);
}

GlobalData::GlobalData(const string label, int size, vector<int> *init)
: label(label), size(size), initializer(init) {
    // scalar
    sprintf(printed, "%s", label.c_str());
}

void GlobalData::EmitSpecific(Mips *mips) {
    mips->EmitLabel(label.c_str());
    string data;
    unsigned initialized = 0;
    if (initializer != NULL) {
        initialized = initializer->size();
        data = "    .word";
    }
    for (int i = 0; i < initialized; ++i) {
        data += " " + std::to_string((*initializer)[i]);
    }
    if (initialized < size) {
        data += "\t .word 0:" + std::to_string(size - initialized);
    }
    mips->Emit(data.c_str());
}

ReadInt::ReadInt(Location *dst)
: dst(dst) {
    sprintf(printed, "read(%s)", dst->GetName().c_str());
}

void ReadInt::EmitSpecific(Mips *mips)
{
    mips->EmitRead(this->dst);
}

WriteInt::WriteInt(Location *src)
: src(src) {
    sprintf(printed, "write(%s)", src->GetName().c_str());
}

void WriteInt::EmitSpecific(Mips *mips)
{
    mips->EmitWrite(this->src);
}

LoadConstant::LoadConstant(Location *d, int v)
        : dst(d), val(v) {

    sprintf(printed, "%s = %d", dst->GetName().c_str(), val);
}
void LoadConstant::EmitSpecific(Mips *mips) {
    mips->EmitLoadConstant(dst, val);
}



LoadLabel::LoadLabel(Location *d, const string l)
        : dst(d), label(l) {

    sprintf(printed, "%s = %s", dst->GetName().c_str(), label.c_str());
}
void LoadLabel::EmitSpecific(Mips *mips) {
    mips->EmitLoadLabel(dst, label.c_str());
}

LoadAddress::LoadAddress(Location *dst, Location *re)
: ref(re), dst(dst) {
    sprintf(printed, "%s = addressof(%s)", dst->GetName().c_str(), ref->GetName().c_str());
}

void LoadAddress::EmitSpecific(Mips *mips)
{
    mips->EmitLoadAddress(dst, ref);
}


Assign::Assign(Location *d, Location *s)
        : dst(d), src(s) {

    sprintf(printed, "%s = %s", dst->GetName().c_str(), src->GetName().c_str());
}
void Assign::EmitSpecific(Mips *mips) {
    mips->EmitCopy(dst, src);
}


Load::Load(Location *d, Location *s, int off)
        : dst(d), src(s), offset(off) {

    if (offset)
        sprintf(printed, "%s = *(%s + %d)", dst->GetName().c_str(), src->GetName().c_str(), offset);
    else
        sprintf(printed, "%s = *(%s)", dst->GetName().c_str(), src->GetName().c_str());
}
void Load::EmitSpecific(Mips *mips) {
    mips->EmitLoad(dst, src, offset);
}

Store::Store(Location *d, Location *s, int off)
        : dst(d), src(s), offset(off) {

    if (offset)
        sprintf(printed, "*(%s + %d) = %s", dst->GetName().c_str(), offset, src->GetName().c_str());
    else
        sprintf(printed, "*(%s) = %s", dst->GetName().c_str(), src->GetName().c_str());
}
void Store::EmitSpecific(Mips *mips) {
    mips->EmitStore(dst, src, offset);
}

const string BinaryOp::opName[BinaryOp::NumOps] = {"*", "/", "%", "+", "-", "<<", ">>", ">", ">=", "<", "<=",
                                                   "==", "!=", "&", "^", "|", "INVL"};

BinaryOp::OpCode BinaryOp::OpCodeForName(const string name) {
    for (int i = 0; i < NumOps; i++)
        if (opName[i] == name)
            return (OpCode)i;

    return Add; // can't get here, but compiler doesn't know that
}

BinaryOp::BinaryOp(OpCode c, Location *d, Location *o1, Location *o2)
        : code(c), dst(d), op1(o1), op2(o2) {


    sprintf(printed, "%s = %s %s %s", dst->GetName().c_str(), op1->GetName().c_str(), opName[code].c_str(), op2->GetName().c_str());
}
void BinaryOp::EmitSpecific(Mips *mips) {
    mips->EmitBinaryOp(code, dst, op1, op2);
}


Label::Label(const string l) : label(l) {

    *printed = '\0';
}
void Label::Print() {
    printf("%s:\n", label.c_str());
}
void Label::EmitSpecific(Mips *mips) {
    mips->EmitLabel(label.c_str());
}


Goto::Goto(const string l) : label(l) {

    sprintf(printed, "Goto %s", label.c_str());
}
void Goto::EmitSpecific(Mips *mips) {
    mips->EmitGoto(label.c_str());
}

IfZ::IfZ(Location *te, const string l)
        : test(te), label(l) {

    sprintf(printed, "IfZ %s Goto %s", test->GetName().c_str(), label.c_str());
}
void IfZ::EmitSpecific(Mips *mips) {
    mips->EmitIfZ(test, label.c_str());
}


BeginFunc::BeginFunc() {
    sprintf(printed,"BeginFunc (unassigned)");
    frameSize = -555; // used as sentinel to recognized unassigned value
}
void BeginFunc::SetFrameSize(int numBytesForAllLocalsAndTemps) {
    frameSize = numBytesForAllLocalsAndTemps;
    sprintf(printed,"BeginFunc %d", frameSize);
}
void BeginFunc::EmitSpecific(Mips *mips) {
    mips->EmitBeginFunction(frameSize);
}

EndFunc::EndFunc() : Instruction() {
    sprintf(printed, "EndFunc");
}
void EndFunc::EmitSpecific(Mips *mips) {
    mips->EmitEndFunction();
}


Return::Return(Location *v) : val(v) {
    sprintf(printed, "Return %s", val? val->GetName().c_str() : "");
}
void Return::EmitSpecific(Mips *mips) {
    mips->EmitReturn(val);
}


PushParam::PushParam(Location *p)
        :  param(p) {

    sprintf(printed, "PushParam %s", param->GetName().c_str());
}
void PushParam::EmitSpecific(Mips *mips) {
    mips->EmitParam(param);
}

PopParams::PopParams(int nb)
        :  numBytes(nb) {
    sprintf(printed, "PopParams %d", numBytes);
}
void PopParams::EmitSpecific(Mips *mips) {
    mips->EmitPopParams(numBytes);
}



LCall::LCall(const string l, Location *d)
        :  label(l), dst(d) {
    sprintf(printed, "%s%sLCall %s", dst? dst->GetName().c_str(): "", dst?" = ":"", label.c_str());
}
void LCall::EmitSpecific(Mips *mips) {
    mips->EmitLCall(dst, label.c_str());
}

ACall::ACall(Location *ma, Location *d)
        : dst(d), methodAddr(ma) {

    sprintf(printed, "%s%sACall %s", dst? dst->GetName().c_str(): "", dst?" = ":"",
            methodAddr->GetName().c_str());
}
void ACall::EmitSpecific(Mips *mips) {
    mips->EmitACall(dst, methodAddr);
}


