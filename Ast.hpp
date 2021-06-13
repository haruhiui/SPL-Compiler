#ifndef AST_H 
#define AST_H 

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
class Stirng;
class ConstValue;
class Identifier;
class ConstDeclaration;
class TypeDeclaration;
class VarDeclaration;
class AstType;
class EnumType;
class AstArrayType;
class RecordType;
class ConstRangeType;
class VarRangeType;
class FieldDeclaration;
class FuncDeclaration;
class Parameter;
class Routine;
class Program;
class UserDefinedType;
class AssignStatement;
class BinaryExpression;
class ArrayReference;
class RecordReference;
class FunctionCall;
class SysFunctionCall;
class ProcedureCall;
class SysProcedureCall;
class IfStatement;
class RepeatStatement;
class WhileStatement;
class ForStatement;
class CaseStatement;
class CaseExpression;
class GotoStatement;
class CompoundStatement;

using ExpressionList = vector<Expression *>;
using StatementList = vector<Statement *>;
using ConstDeclList = vector<ConstDeclaration *>;
using VarDeclList = vector<VarDeclaration *>;
using TypeDeclList = vector<TypeDeclaration *>;
using NameList = vector<Identifier *>;
using FieldList = vector<FieldDeclaration *>;
using ParaList = vector<Parameter *>;
using RoutineList = vector<FuncDeclaration *>;
using StatementList = vector<Statement *>;
using ArgsList = vector<Expression *>;
using CaseExprList = vector<CaseExpression *>;

// base node
class Node{
public:
    // generate intermediate code for llvm
    virtual llvm::Value *codeGen(Generator & generator) = 0;

    // generate json data for visualization
    virtual string jsonGen(){return "";};

    virtual ~Node() { }
};


// expression: doesn't support goto
class Expression : public Node {};

// identifier
class Identifier : public Expression{
public:
    string *name;

    Identifier(string *name) : name(name) { }

    string getName() {
        return *name;
    }
    
    virtual string jsonGen() override;
    
    virtual llvm::Value *codeGen(Generator & generator) override;
};

// const value
class ConstValue : public Expression{
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

class Integer : public ConstValue{
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

class Real : public ConstValue{
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

class Char : public ConstValue{
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

class String : public ConstValue{
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

class Boolean : public ConstValue{
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
class Statement : public Node {
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
class ConstDeclaration : public Statement{
public:
    Identifier *name;
    ConstValue *value;
    AstType *type;
    bool isGlobal;
    ConstDeclaration(Identifier *ip, ConstValue *cp) : name(ip), value(cp), isGlobal(false) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;

    void setGlobal() {
        this->isGlobal = true;
    }
};

class EnumType : public Statement {
public:
    NameList *enumList;

    EnumType(NameList *i) : enumList(i) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
};

class ConstRangeType : public Statement {
public:
    ConstValue *lowerBound, *upperBound;
    llvm::Value *lowerValue, *upperValue;
    
    ConstRangeType(ConstValue *lowerBound, ConstValue *upperBound) : lowerBound(lowerBound), upperBound(upperBound) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;

    size_t size();

    llvm::Value *mapIndex(llvm::Value* indexValue, Generator& generator);
};

class VarRangeType : public Statement {
public:
    Identifier *lowerBound , *upperBound;
    llvm::Value *lowerValue, *upperValue, *lowerValueAddr, *upperValueAddr;

    VarRangeType(Identifier *lowerBound, Identifier *upperBound) : lowerBound(lowerBound), upperBound(upperBound) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
    
    llvm::Value *mapIndex(llvm::Value *indexValue, Generator & generator);
    
    size_t size();
};

class FieldDeclaration : public Statement {
public:
    NameList *nameList;
    AstType *type;

    FieldDeclaration(NameList *nameList, AstType *td) : nameList(nameList), type(td) { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
};

class RecordType : public Statement 
{
public:
    FieldList *fieldList;
    
    RecordType(FieldList *fl) : fieldList(fl) { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
};

class UserDefinedType {
public:
    string name;
    bool isStruct;
    llvm::ArrayType *defArrayType;
    llvm::StructType *defRecordType;
    UserDefinedType(string name, llvm::ArrayType *defArrayType):
        name(name), defArrayType(defArrayType) {this->isStruct = false;}

    UserDefinedType(string name, llvm::StructType *defRecordType):
        name(name), defRecordType(defRecordType) {this->isStruct = true;}

};

// the concrete defined ways for array type : const..const or name..name
class AstArrayType : public Statement {
public:
    //eg: in:  array[1..3] of integer 
    //             *range*     *type*
    AstType *type, *range;

    AstArrayType(AstType *type, AstType *range) : type(type), range(range) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
};

// abstract type
class AstType : public Statement {
public:
    string type;
    string buildInType;
    AstArrayType *arrayType;
    RecordType *recordType;
    EnumType *enumType;
    ConstRangeType *constRangeType;
    VarRangeType *varRangeType;
    Identifier *userDefineType;
    

    AstType(AstArrayType *i) : arrayType(i), type("array") { }
    AstType(RecordType *i) : recordType(i), type("record") { }
    AstType(EnumType *i) : enumType(i), type("enum") { }
    AstType(ConstRangeType *i) : constRangeType(i), type("constRange") { }
    AstType(VarRangeType *i) : varRangeType(i), type("varRange") { }
    AstType(string buildIn) : buildInType(buildIn), type("builtin") { }
    AstType(Identifier *i) : userDefineType(i), type("userDefined") { }
    AstType() : type("void") { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
    
    llvm::Type* toLLVMType(Generator & generator);
    llvm::Constant* initValue(Generator & generator, ConstValue *v = nullptr);
};

class TypeDeclaration : public Statement {
public:
    Identifier *name;
    AstType *type;
    virtual llvm::Value *codeGen(Generator & generator) override;

    TypeDeclaration(Identifier *name, AstType *type) : name(name), type(type) { }
    
    virtual string jsonGen() override;
};

class VarDeclaration : public Statement {
public:
    NameList *nameList;
    AstType *type;
    bool isGlobal;
    VarDeclaration(NameList *nl, AstType *td) : nameList(nl), type(td), isGlobal(false) {}
    
    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string jsonGen() override;
    
    void setGlobal() {
        this->isGlobal = true;
    }
};

class FuncDeclaration : public Statement {
public: 
    Identifier *name;
    ParaList *paraList;
    AstType *returnType;
    Routine *subRoutine;

    FuncDeclaration(Identifier *name, ParaList *paraList, AstType *returnType) : 
        name(name), paraList(paraList), returnType(returnType) {

    }

    FuncDeclaration(Identifier *name, ParaList *paraList) : name(name), paraList(paraList) {
        returnType = new AstType();
    }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    void setRoutine(Routine *routine) {
        subRoutine = routine;
    }

    virtual string jsonGen() override;
};

class Parameter : public Statement {
public:
    bool isVar;
    NameList *nameList;
    AstType *type;
    Parameter(NameList *nl, bool isVar) : nameList(nl), isVar(isVar) { }
    
    void setType(AstType *type) {
        this->type = type;
    }

    AstType* getType() {
        return type;
    }

    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string jsonGen() override;
};

class Routine : public Node {
public:
    ConstDeclList *constDeclList;
    TypeDeclList *typeDeclList;
    VarDeclList *varDeclList;
    RoutineList *routineList;
    CompoundStatement *routineBody;

    Routine(ConstDeclList *cd, TypeDeclList *tp, VarDeclList *vd, RoutineList *rl) : 
        constDeclList(cd), varDeclList(vd), typeDeclList(tp), routineList(rl) {

    }

    void setRoutineBody(CompoundStatement *routineBody) { this->routineBody = routineBody; }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string jsonGen() override;
    
    void setGlobal() {
        for (auto & constDecl : *constDeclList) {
            constDecl->setGlobal();
        }
        for (auto & varDecl : *varDeclList) {
            varDecl->setGlobal();
        }
    }
};

class Program : public Node {
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
    enum AssignType {
        ID_ASSIGN,
        ARRAY_ASSIGN,
        RECORD_ASSIGN
    };
    Identifier *lhs;
    Expression *rhs;
    Expression *sub;
    Identifier *field;
    AssignType type;

    AssignStatement(Identifier *lhs, Expression *rhs) : lhs(lhs), rhs(rhs), type(ID_ASSIGN) { }
    AssignStatement(Identifier *lhs, Expression *sub, Expression *rhs) : lhs(lhs), sub(sub), rhs(rhs), type(ARRAY_ASSIGN) { }
    AssignStatement(Identifier *lhs, Identifier *field, Expression *rhs) : lhs(lhs), field(field), rhs(rhs), type(RECORD_ASSIGN) { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class BinaryExpression : public Expression {
private:

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
private:

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
private:

public:
    Identifier *record;
    Identifier *field;

    RecordReference(Identifier *record, Identifier *field) : record(record), field(field) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class FunctionCall : public Expression, public Statement
{
private:

public:
    Identifier *function;
    ArgsList *args;

    FunctionCall(Identifier *name) : function(name), args(new ArgsList()) { }
    FunctionCall(Identifier *name, ArgsList *args) : function(name), args(args) { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class ProcedureCall : public Statement 
{
private:

public:
    Identifier *funcName;
    ArgsList *args;

    ProcedureCall(Identifier *name) : funcName(name), args(new ArgsList()) { }
    ProcedureCall(Identifier *name, ArgsList *args) : funcName(name), args(args) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};

class SysFunctionCall : public Expression, public Statement
{
private:

public:
    ArgsList *args;
    string funcName;

    SysFunctionCall(string name) : funcName(name) {}
    SysFunctionCall(string name, ArgsList *args) : funcName(name), args(args) {  }

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

class SysProcedureCall : public Statement {
public:
    enum SysProcedure {
        SPL_WRITE,
        SPL_WRITELN,
        SPL_READ,
        SPL_ERROR_PROCEDURE
    };

    SysProcedure getProcedure(string *name) {
        string &sname = *name;
        if(sname == "write")
            return SPL_WRITE;
        else if(sname == "writeln")
            return SPL_WRITELN;
        else if(sname == "read")
            return SPL_READ;
        else
            return SPL_ERROR_PROCEDURE;
    }

    SysProcedure procedure;
    ArgsList *args;
    string *name;

    SysProcedureCall(string *name) : procedure(getProcedure(name)), name(name) { }
    SysProcedureCall(string *name, ArgsList *args) : procedure(getProcedure(name)), args(args), name(name) { }
    SysProcedureCall(string *name, Expression *expr) : procedure(getProcedure(name)), args(new ArgsList()), name(name) {
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
    StatementList *repeatStatement;

    RepeatStatement(Expression *condition, StatementList *stmtList) : condition(condition), repeatStatement(stmtList) {

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
    CaseExprList *caseExprList;

    CaseStatement(Expression *value, CaseExprList *caseExprList) : value(value), caseExprList(caseExprList) { }

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
    StatementList *stmtList;
    
    CompoundStatement(StatementList *stmtList) : stmtList(stmtList) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string jsonGen() override;
};


#endif 