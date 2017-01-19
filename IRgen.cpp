/* 
 * Implementation for the IRGenerator class. The methods don't do anything
 * too fancy, mostly just create objects of the various Tac instruction
 * classes and push_back them to the list.
 */

#include "IRgen.h"

#include <string.h>
#include "tac.h"
#include "mips.h"

IRGenerator::IRGenerator()
{
    code = new std::list<Instruction*>();
    data = new std::list<Instruction*>();
    varLocs = new SymbolTable<Location*>();
    varLocs->enterscope();
}



typedef struct AssignStmt {
    Location* dst;
    Location* src;
} AssignStmt;


string IRGenerator::NewLabel()
{
    static int nextLabelNum = 0;
    char temp[10];
    sprintf(temp, "_L%d", nextLabelNum++);
    return strdup(temp);
}

Location *IRGenerator::GenGlobalVar(const string name, unsigned int size, vector<int> *init) {
    // gp is at the middle of 64KB static area
    static int nextGlobalOffset = -32768;
    Location *result = new Location(gpRelative, nextGlobalOffset, name);
    nextGlobalOffset += 4 * size;

    data->push_back(new GlobalData(name, size, init));
    return result;
}

Location *IRGenerator::GenTempVar()
{
    static int nextTempNum;
    char temp[10];
    sprintf(temp, "_tmp%d", nextTempNum++);
    Location *result = GetNewLocationOnStack(temp);
    return result;
}

Location *IRGenerator::GetNewLocationOnStack(const string name) {
    Location* result = new Location(fpRelative, (this->currentStackSize) * (-4) + OffsetToFirstLocal, name);
    this->currentStackSize++;
    return result;
}

Location *IRGenerator::GetNewBulkLocationOnStack(const string name, unsigned int size)
{
    Location* result = new Location(fpRelative, (this->currentStackSize) * (-4) + OffsetToFirstLocal, name);
    this->currentStackSize += size;
    return result;
}



Location *IRGenerator::GenLoadConstant(int value)
{
    Location *result = GenTempVar();
    code->push_back(new LoadConstant(result, value));
    return result;
}


Location *IRGenerator::GenLoadLabel(const string label)
{
    Location *result = GenTempVar();
    code->push_back(new LoadLabel(result, label));
    return result;
}


void IRGenerator::GenAssign(Location *dst, Location *src)
{
    code->push_back(new Assign(dst, src));
}


Location *IRGenerator::GenLoad(Location *ref, int offset)
{
    Location *result = GenTempVar();
    code->push_back(new Load(result, ref, offset));
    return result;
}

void IRGenerator::GenStore(Location *dst, Location *src, int offset)
{
    code->push_back(new Store(dst, src, offset));
}


Location *IRGenerator::GenBinaryOp(const string opName, Location *op1, Location *op2)
{
    Location *result = GenTempVar();
    code->push_back(new BinaryOp(BinaryOp::OpCodeForName(opName), result, op1, op2));
    return result;
}


void IRGenerator::GenLabel(const string label)
{
    code->push_back(new Label(label));
}

void IRGenerator::GenIfZ(Location *test, const string label)
{
    code->push_back(new IfZ(test, label));
}

void IRGenerator::GenGoto(const string label)
{
    code->push_back(new Goto(label));
}

void IRGenerator::GenReturn(Location *val)
{
    code->push_back(new Return(val));
}


BeginFunc *IRGenerator::GenBeginFunc()
{
    BeginFunc *result = new BeginFunc;
    this->currentStackSize = 0;
    code->push_back(result);
    return result;
}

void IRGenerator::GenEndFunc()
{
    code->push_back(new EndFunc());
}

void IRGenerator::GenPushParam(Location *param)
{
    code->push_back(new PushParam(param));
}

void IRGenerator::GenPopParams(int numBytesOfParams)
{
    if (numBytesOfParams > 0)
        code->push_back(new PopParams(numBytesOfParams));
}

Location *IRGenerator::GenLCall(const string label)
{
    Location *result =  GenTempVar();
    code->push_back(new LCall(label, result));
    return result;
}




extern bool genTAC;


void IRGenerator::DoFinalCodeGen()
{
    if (genTAC) { // if debug don't translate to mips, just print Tac
        for (Instruction* ins: *this->data)
            ins->Print();
        for (Instruction* ins: *this->code)
            ins->Print();
    }  else {
        Mips mips;
        if (!data->empty())
            mips.Emit("\t.data");
        for (Instruction* ins: *data)
            ins->Emit(&mips);
        mips.EmitPreamble();
        for (Instruction* ins: *code)
            ins->Emit(&mips);
    }
}

Location *IRGenerator::GenWrite(Location *src) {
    code->push_back(new WriteInt(src));
    return NULL;
}

Location *IRGenerator::GenRead(Location *dst) {
    code->push_back(new ReadInt(dst));
    return GenLoad(dst);
}

Location *IRGenerator::GenLoadAddress(Location *ref) {
    Location* tmp = GenTempVar();
    code->push_back(new LoadAddress(tmp, ref));
    return tmp;
}

