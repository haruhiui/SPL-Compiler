#ifndef AST_HPP
#define AST_HPP  

#include <llvm/IR/Value.h> 
#include <llvm/IR/DerivedTypes.h>
#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <ostream> 

using namespace std; 

class Generator;

class Node;
class Expression;
class Statement;
class Integer;
class Real;
class Char;
class Boolean;
class String;
class ConstValue;
class Identifier;
class ConstDeclaration;
class TypeDeclaration;
class VarDeclaration;
class AbstractType;
class EnumType;
class AbstractArray;
class RecordType;
class ConstRangeType;
class VarRangeType;
class FieldDeclaration;
class FuncDeclaration;
class Params;
class Routine;
class Program;
class UserDefinedType;
class AssignStatement;
class BinaryExpression;
class ArrayReference;
class RecordReference;
class UserFunction;
class SystemFunction;
class UserProcedure;
class SystemProcedure;
class IfStatement;
class RepeatStatement;
class WhileStatement;
class ForStatement;
class CaseStatement;
class CaseExpression;
class GotoStatement;
class CompoundStatement;

using ExpressionVector = vector<Expression *>;
using StatementVector = vector<Statement *>;
using ConstDeclVector = vector<ConstDeclaration *>;
using VarDeclVector = vector<VarDeclaration *>;
using TypeDeclVector = vector<TypeDeclaration *>;
using NameVector = vector<Identifier *>;
using FieldVector = vector<FieldDeclaration *>;
using ParaVector = vector<Params *>;
using RoutineVector = vector<FuncDeclaration *>;
using StatementVector = vector<Statement *>;
using ParamsVector = vector<Expression *>;
using CaseExprVector = vector<CaseExpression *>;

// base node
class Node
{
public:
    // generate intermediate code for llvm
    virtual llvm::Value *codeGen(Generator & generator) = 0;

    // generate json data for visualization
    virtual string jsonGen(){return "";};

    virtual ~Node() { }
};


// expression: doesn't support goto
class Expression : public Node 
{

};

// identifier
class Identifier : public Expression
{
public:
    string *name;

    Identifier(string *name) : name(name) { }
    
    virtual string jsonGen() override;
    
    virtual llvm::Value *codeGen(Generator & generator) override;
};

// const value
class ConstValue : public Expression
{
public:
    union Value {
        int i;
        double r;
        bool b;
        char c;
        string* s;
    };
    string valueType; 
    
    virtual ConstValue::Value getValue() = 0;
    
    virtual ConstValue *operator-() = 0;
    
    virtual bool isValidConstRangeType() {
        return this->valueType == "integer" || this->valueType == "char";
    }
};

class Integer : public ConstValue
{
public:
    int value;
    Integer(int value) : value(value) {
        this->valueType = "integer"; 
    }

    virtual ConstValue::Value getValue() override {
        Value v;
        v.i = value;
        return v;
    }

    virtual ConstValue *operator-() override {
        return new Integer(-value);
    }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
};

class Real : public ConstValue
{
public:
    double value;
    Real(double value) : value(value) {
        this->valueType = "real"; 
    }

    virtual ConstValue::Value getValue() override {
        Value v;
        v.r = value;
        return v;
    }

    virtual ConstValue *operator-() override {
        return new Real(-value);
    }

    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string jsonGen() override;
};

class Char : public ConstValue
{
public:
    char value;
    Char(char value) : value(value) { 
        this->valueType = "char"; 
    }

    virtual ConstValue::Value getValue() override {
        Value v;
        v.c = value;
        return v;
    }
    
    virtual ConstValue *operator-() override {
        return new Char(-value);
    }

    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string jsonGen() override;
};

class String : public ConstValue
{
public:
    string* value;
    String(string* value) : value(value) { 
        this->valueType = "string"; 
    }

    virtual ConstValue::Value getValue() override {
        Value v;
        v.s = value;
        return v;
    }
    
    virtual ConstValue *operator-() override {
        return nullptr;
    }

    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string jsonGen() override;
};

class Boolean : public ConstValue
{
public:
    bool value;
    Boolean(bool value) : value(value) { 
        this->valueType = "boolean"; 
    }

    virtual ConstValue::Value getValue() override {
        Value v;
        v.b = value;
        return v;
    }

    virtual ConstValue *operator-() override {
        return new Boolean(!value);
    }

    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string jsonGen() override;
};

// statement: support goto
class Statement : public Node 
{
public:
    llvm::BasicBlock *nextBlock;
    int label = -1; // default, not set by user

    // set label for goto.
    // Note that label is set only when user defined.
    void setLabel(int label) { this->label = label;}

    // only labelled statement will actually do these
    // Prologue will generate br label %xx and %xx:
    void generatePrologue(Generator &generator);

    // Epilogue will generate %nextxx and br %nextxx
    void generateEpilogue(Generator &generator);
};

// declare const value
class ConstDeclaration : public Statement
{
public:
    Identifier *name;
    ConstValue *value;
    AbstractType *type;
    bool isGlobal;
    ConstDeclaration(Identifier *ip, ConstValue *cp) : name(ip), value(cp), isGlobal(false) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;

    void setGlobal() {
        this->isGlobal = true;
    }
};

class EnumType : public Statement 
{
public:
    NameVector *enumVector;

    EnumType(NameVector *i) : enumVector(i) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
};

class ConstRangeType : public Statement 
{
public:
    ConstValue *lowerBound, *upperBound;
    llvm::Value *lowerValue, *upperValue;
    
    ConstRangeType(ConstValue *lowerBound, ConstValue *upperBound) : lowerBound(lowerBound), upperBound(upperBound) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;

    size_t size();

    llvm::Value *mapIndex(llvm::Value* indexValue, Generator& generator);
};

class VarRangeType : public Statement 
{
public:
    Identifier *lowerBound , *upperBound;
    llvm::Value *lowerValue, *upperValue, *lowerValueAddr, *upperValueAddr;

    VarRangeType(Identifier *lowerBound, Identifier *upperBound) : lowerBound(lowerBound), upperBound(upperBound) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
    
    llvm::Value *mapIndex(llvm::Value *indexValue, Generator & generator);
    
    size_t size();
};

class FieldDeclaration : public Statement 
{
public:
    NameVector *nameVector;
    AbstractType *type;

    FieldDeclaration(NameVector *nameVector, AbstractType *td) : nameVector(nameVector), type(td) { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
};

class RecordType : public Statement 
{
public:
    FieldVector *fieldVector;
    
    RecordType(FieldVector *fl) : fieldVector(fl) { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
};

// the concrete defined ways for array type : const..const or name..name
class AbstractArray : public Statement {
public:
    //eg: in:  array[1..3] of integer 
    //             *range*     *type*
    AbstractType *type, *range;

    AbstractArray(AbstractType *type, AbstractType *range) : type(type), range(range) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
};

// abstract type
class AbstractType : public Statement 
{
public:
    string type;
    string buildInType;
    AbstractArray *arrayType;
    RecordType *recordType;
    EnumType *enumType;
    ConstRangeType *constRangeType;
    VarRangeType *varRangeType;
    Identifier *userDefineType;
    

    AbstractType(AbstractArray *i) : arrayType(i), type("array") { }
    AbstractType(RecordType *i) : recordType(i), type("record") { }
    AbstractType(EnumType *i) : enumType(i), type("enum") { }
    AbstractType(ConstRangeType *i) : constRangeType(i), type("constRange") { }
    AbstractType(VarRangeType *i) : varRangeType(i), type("varRange") { }
    AbstractType(string buildIn) : buildInType(buildIn), type("builtin") { }
    AbstractType(Identifier *i) : userDefineType(i), type("userDefined") { }
    AbstractType() : type("void") { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
    
    llvm::Type* toLLVMType(Generator & generator);
    llvm::Type* getLLVMTypeByString(string& name);
    llvm::Constant *initValue(Generator &generator, ConstValue *v = nullptr);
};

class TypeDeclaration : public Statement 
{
public:
    Identifier *name;
    AbstractType *type;
    virtual llvm::Value *codeGen(Generator & generator) override;

    TypeDeclaration(Identifier *name, AbstractType *type) : name(name), type(type) { }
    
    virtual string jsonGen() override;
};

class VarDeclaration : public Statement 
{
public:
    NameVector *nameVector;
    AbstractType *type;
    bool isGlobal;
    VarDeclaration(NameVector *nl, AbstractType *td) : nameVector(nl), type(td), isGlobal(false) {}
    
    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string jsonGen() override;
    
    void setGlobal() {
        this->isGlobal = true;
    }
};



class UserDefinedType 
{
public:
    string name;
    bool isStruct;
    size_t size;
    vector<string> typeVec;
    llvm::ArrayType *defArrayType;
    llvm::StructType *defRecordType;
    AbstractType *range;
    UserDefinedType(string name, llvm::ArrayType *defArrayType, vector<string> typeVec, AbstractArray *ast)
     : name(name), defArrayType(defArrayType), typeVec(typeVec)
        {
            this->isStruct = false;
            this->size = typeVec.size();
            this->range = ast->range;
        }

    UserDefinedType(string name, llvm::StructType *defRecordType, vector<string> typeVec, AbstractArray *ast ):
        name(name), defRecordType(defRecordType), typeVec(typeVec) 
        {
            this->isStruct = true;
            this->size = typeVec.size();
            this->range = ast->range;
        }
};


class FuncDeclaration : public Statement 
{
public: 
    Identifier *name;
    ParaVector *paraVector;
    AbstractType *returnType;
    Routine *subRoutine;

    FuncDeclaration(Identifier *name, ParaVector *paraVector, AbstractType *returnType) : 
        name(name), paraVector(paraVector), returnType(returnType) {

    }

    FuncDeclaration(Identifier *name, ParaVector *paraVector) : name(name), paraVector(paraVector) {
        returnType = new AbstractType();
    }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    void setRoutine(Routine *routine) {
        subRoutine = routine;
    }

    virtual string jsonGen() override;
};

class Params : public Statement 
{
public:
    bool isVar;
    NameVector *nameVector;
    AbstractType *type;
    Params(NameVector *nl, bool isVar) : nameVector(nl), isVar(isVar) { }
    
    void setType(AbstractType *type) {
        this->type = type;
    }

    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string jsonGen() override;
};

class Routine : public Node 
{
public:
    ConstDeclVector *constDeclVector;
    TypeDeclVector *typeDeclVector;
    VarDeclVector *varDeclVector;
    RoutineVector *routineVector;
    CompoundStatement *routineBody;

    Routine(ConstDeclVector *cd, TypeDeclVector *tp, VarDeclVector *vd, RoutineVector *rl) : 
        constDeclVector(cd), varDeclVector(vd), typeDeclVector(tp), routineVector(rl) {

    }

    void setRoutineBody(CompoundStatement *routineBody) { this->routineBody = routineBody; }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
    
    void setGlobal() {
        for (auto & constDecl : *constDeclVector) {
            constDecl->setGlobal();
        }
        for (auto & varDecl : *varDeclVector) {
            varDecl->setGlobal();
        }
    }
};

class Program : public Node 
{
public:
    string *programID;
    Routine *routine;

    Program(string *programID, Routine *routine) : programID(programID), routine(routine) { }
    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class AssignStatement : public Statement 
{
public:
    Identifier *targetVar;
    Expression *targetValue;
    Expression *index;
    Identifier *field;
    string assignType;

    AssignStatement(Identifier *targetVar, Expression *targetValue) : targetVar(targetVar), targetValue(targetValue), assignType("identifier") { }
    AssignStatement(Identifier *targetVar, Expression *index, Expression *targetValue) : targetVar(targetVar), index(index), targetValue(targetValue), assignType("array") { }
    AssignStatement(Identifier *targetVar, Identifier *field, Expression *targetValue) : targetVar(targetVar), field(field), targetValue(targetValue), assignType("record") { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class BinaryExpression : public Expression 
{
public: 
    Expression *lhs;
    Expression *rhs;
    string op;

    BinaryExpression(Expression *lhs, string op, Expression *rhs) : lhs(lhs), op(op), rhs(rhs) {     }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class ArrayReference : public Expression 
{
public:
    Identifier *array;
    Expression *index;

    ArrayReference(Identifier *array, Expression *index) : array(array), index(index) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
    
    llvm::Value *getReference(Generator & generator);
    llvm::Type *getElementType(Generator & generator);
};

class RecordReference : public Expression 
{
public:
    Identifier *record;
    Identifier *field;

    RecordReference(Identifier *record, Identifier *field) : record(record), field(field) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class UserFunction : public Expression, public Statement
{
public:
    Identifier *function;
    ParamsVector *args;

    UserFunction(Identifier *name) : function(name), args(new ParamsVector()) { }
    UserFunction(Identifier *name, ParamsVector *args) : function(name), args(args) { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class UserProcedure : public Statement 
{
public:
    Identifier *funcName;
    ParamsVector *args;

    UserProcedure(Identifier *name) : funcName(name), args(new ParamsVector()) { }
    UserProcedure(Identifier *name, ParamsVector *args) : funcName(name), args(args) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class SystemFunction : public Expression, public Statement
{
public:
    ParamsVector *args;
    string funcName;

    SystemFunction(string name) : funcName(name) {}
    SystemFunction(string name, ParamsVector *args) : funcName(name), args(args) {  }

    virtual string jsonGen() override;
    virtual llvm::Value *codeGen(Generator & generator) override;

    llvm::Value *SysFuncAbs(Generator & generator);
    llvm::Value *SysFuncChr(Generator & generator);
    llvm::Value *SysFuncOdd(Generator & generator);
    llvm::Value *SysFuncOrd(Generator & generator);
    llvm::Value *SysFuncPred(Generator & generator);
    llvm::Value *SysFuncSqr(Generator & generator);
    llvm::Value *SysFuncSqrt(Generator & generator);
    llvm::Value *SysFuncSucc(Generator & generator);
    llvm::Value *SysFuncSqrReal(Generator & generator); 

};

class SystemProcedure : public Statement 
{
public:
    ParamsVector *args;
    string *name;

    SystemProcedure(string *name) : name(name) {
        args = new ParamsVector(); 
    }
    SystemProcedure(string *name, ParamsVector *args) : args(args), name(name) { }
    SystemProcedure(string *name, Expression *expr) : args(new ParamsVector()), name(name) {
        args->push_back(expr);
    }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
    
    llvm::Value *SysProcWrite(Generator & generator, bool isLineBreak);
    llvm::Value *SysProcRead(Generator & generator);
};

class IfStatement : public Statement {
public:
    Expression *condition;
    Statement *thenStatement;
    Statement *elseStatement;

    IfStatement(Expression *condition, Statement *thenStatement, Statement *elseStatement) : 
        condition(condition), thenStatement(thenStatement), elseStatement(elseStatement) {

    }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class RepeatStatement : public Statement {
public:
    Expression *condition;
    StatementVector *repeatStatement;

    RepeatStatement(Expression *condition, StatementVector *stmtVector) : condition(condition), repeatStatement(stmtVector) {

    }

    virtual llvm::Value *codeGen(Generator & generator) override;    
    virtual string jsonGen() override;
};

class WhileStatement : public Statement {
public:
    Expression *condition;
    Statement *stmt;

    WhileStatement(Expression *condition, Statement *stmt) : condition(condition), stmt(stmt) {

    }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
    
};

class ForStatement : public Statement 
{
public:
    Identifier *var;
    Expression *value;
    // increase:true decrease:false
    bool isAdd;
    Expression *step;
    Statement *stmt;

    ForStatement(Identifier *var, Expression *value, bool isAdd, Expression *step, Statement *stmt) :
        var(var), value(value), isAdd(isAdd), step(step), stmt(stmt) {

    }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;   
};

class CaseStatement : public Statement 
{
public:
    Expression *value;
    CaseExprVector *caseExprVector;

    CaseStatement(Expression *value, CaseExprVector *caseExprVector) : value(value), caseExprVector(caseExprVector) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;   
};

class CaseExpression : public Statement 
{
public:
    Statement *stmt;

    CaseExpression(Expression *value, Statement *stmt) : value(value), stmt(stmt) { }
    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string jsonGen() override;
    Expression *value;
};

class GotoStatement : public Statement 
{
public:
    int targetLabel;
    GotoStatement(int label) : targetLabel(label) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class CompoundStatement : public Statement 
{
public:
    StatementVector *stmtVector;
    
    CompoundStatement(StatementVector *stmtVector) : stmtVector(stmtVector) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};


#endif 