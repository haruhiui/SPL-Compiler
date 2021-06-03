#ifndef AST_H 
#define AST_H 

#include <llvm/IR/Value.h> 
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
class EnumRangeType;
class FieldDeclaration;
class FuncDeclaration;
class Parameter;
class Routine;
class Program;
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

// SPL 内置类型
enum BuildInType
{
    SPL_INTEGER,
    SPL_REAL,
    SPL_CHAR,
    SPL_BOOLEAN
};

// AST 节点
class Node
{
public:
    // generate intermediate code for llvm
    virtual llvm::Value *codeGen(Generator & generator) = 0;

    // generate json data for visualization
    virtual string getJson(){return "";};

    virtual ~Node() { }
};

// 表达式，特征是能返回值或能存储值
class Expression : public Node
{
};

// 语句，特征是能完成某些操作
class Statement : public Node
{
private:
    int label = -1;

public:
    llvm::BasicBlock *afterBB;

    // 用于Goto语句设置标号
    void setLabel(int label) {
        this->label = label;
    }

    // 用于得到Goto语句需要的标号，若不存在则返回-1
    int getLable() const {
        return label;
    }

    void forward(Generator & generator);
    
    void backward(Generator & generator);
};

// 标识符
class Identifier : public Expression
{
private:
    string *name;

public:
    Identifier(string *name) : name(name) { }

    string getName() {
        return *name;
    }
    
    virtual string getJson() override;
    
    virtual llvm::Value *codeGen(Generator & generator) override;
};

// 常量
class ConstValue : public Expression
{
public:
    union Value {
        int i;
        double r;
        bool b;
        char c;
    };
    
    virtual BuildInType getType() = 0;
    
    virtual ConstValue::Value getValue() = 0;
    
    virtual ConstValue *operator-() = 0;

    virtual bool isValidConstRangeType() {
        BuildInType t = getType();
        return t == SPL_INTEGER || t == SPL_CHAR;
    }
};

class Integer : public ConstValue
{
private:
    int value;

public:
    Integer(int value) : value(value) { }

    virtual BuildInType getType() override {
        return SPL_INTEGER;
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
    
    virtual string getJson() override;
};

class Real : public ConstValue
{
private:
    double value;

public:
    Real(double value) : value(value) { }

    virtual BuildInType getType() override {
        return SPL_REAL;
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

    virtual string getJson() override;
};

class Char : public ConstValue
{
private:
    char value;

public:
    Char(char value) : value(value) { }

    virtual BuildInType getType() override {
        return SPL_CHAR;
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

    virtual string getJson() override;
};

class Boolean : public ConstValue
{
private:
    bool value;

public:
    Boolean(bool value) : value(value) { }

    virtual BuildInType getType() override {
        return SPL_BOOLEAN;
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

    virtual string getJson() override;
};

// 常量声明语句
class ConstDeclaration : public Statement
{
private:
    Identifier *name;
    ConstValue *value;
    AstType *type;
    bool globalFlag;

public:
    ConstDeclaration(Identifier *ip, ConstValue *cp) : name(ip), value(cp), globalFlag(false) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string getJson() override;

    void setGlobal() {
        globalFlag = true;
    }
    
    bool isGlobal() {
        return globalFlag;
    }
};

class EnumType : public Statement 
{
private:
    NameList *enumList;

public:
    EnumType(NameList *nl) : enumList(nl) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string getJson() override;
};

class AstArrayType : public Statement 
{
public:
    AstType *range;
    AstType *type;

    AstArrayType(AstType *type, AstType *range) : type(type), range(range) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string getJson() override;
};

class ConstRangeType : public Statement 
{
private:
    ConstValue *lowBound;
    ConstValue *upBound;

public:
    ConstRangeType(ConstValue *lowBound, ConstValue *upBound) : lowBound(lowBound), upBound(upBound) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string getJson() override;
    
    size_t size() {
        int s;
        if (lowBound->getType() == upBound->getType() && lowBound->isValidConstRangeType()) {
            if (lowBound->getType() == SPL_INTEGER) {
            //    std::cout << lowBound->getValue().i << ".." << upBound->getValue().i << std::endl;
                s = upBound->getValue().i - lowBound->getValue().i + 1;
            } else {
            //    std::cout << lowBound->getValue().c << ".." << upBound->getValue().c << std::endl;
                s = upBound->getValue().c - lowBound->getValue().c + 1;
            }
            if (s <= 0) {
                throw range_error("[ERROR] low bound > up bound.");
            }
        } else {
            throw std::domain_error("[ERROR] Invalid range type.");
        }
        return s;
    }

    llvm::Value *mapIndex(llvm::Value* indexValue, Generator& generator);
};

class EnumRangeType : public Statement 
{
private:
    Identifier *lowBound;
    Identifier *upBound;

public:
    EnumRangeType(Identifier *lowBound, Identifier *upBound) : lowBound(lowBound), upBound(upBound) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string getJson() override;
    
    llvm::Value *lowValue, *upValue, *lowValueAddr, *upValueAddr;
    
    llvm::Value *mapIndex(llvm::Value *indexValue, Generator & generator);
    
    size_t size();
};

class FieldDeclaration : public Statement 
{
private:
    NameList *nameList;
    AstType *type;

public:
    FieldDeclaration(NameList *nameList, AstType *td) : nameList(nameList), type(td) { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string getJson() override;
};

class RecordType : public Statement 
{
private:
    FieldList *fieldList;

public:
    RecordType(FieldList *fl) : fieldList(fl) { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string getJson() override;
};

// 类型
class AstType : public Statement {
public:
    enum TypeOfType {
        SPL_ARRAY,
        SPL_RECORD,
        SPL_ENUM,
        SPL_CONST_RANGE,
        SPL_ENUM_RANGE,
        SPL_BUILD_IN,
        SPL_USER_DEFINE,
        SPL_VOID
    };

    AstArrayType *arrayType;
    RecordType *recordType;
    EnumType *enumType;
    ConstRangeType *constRangeType;
    EnumRangeType *enumRangeType;
    BuildInType buildInType;
    Identifier *userDefineType;
    TypeOfType type;

    AstType(AstArrayType *at) : arrayType(at), type(SPL_ARRAY) { }
    AstType(RecordType *rt) : recordType(rt), type(SPL_RECORD) { }
    AstType(EnumType *et) : enumType(et), type(SPL_ENUM) { }
    AstType(ConstRangeType *crt) : constRangeType(crt), type(SPL_CONST_RANGE) { }
    AstType(EnumRangeType *ert) : enumRangeType(ert), type(SPL_ENUM_RANGE) { }
    AstType(BuildInType bt) : buildInType(bt), type(SPL_BUILD_IN) { }
    AstType(Identifier *udt) : userDefineType(udt), type(SPL_USER_DEFINE) { }
    AstType() : type(SPL_VOID) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
    
    llvm::Type* toLLVMType();
    llvm::Constant* initValue(ConstValue *v = nullptr);
};

class TypeDeclaration : public Statement 
{
private:
    Identifier *name;
    AstType *type;

public:
    virtual llvm::Value *codeGen(Generator & generator) override;

    TypeDeclaration(Identifier *name, AstType *type) : name(name), type(type) { }
    
    virtual string getJson() override;
};

class VarDeclaration : public Statement 
{
private:
    NameList *nameList;
    AstType *type;
    bool globalFlag;

public:
    VarDeclaration(NameList *nl, AstType *td) : nameList(nl), type(td), globalFlag(false) {}
    
    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string getJson() override;
    
    void setGlobal() {
        globalFlag = true;
    }
    
    bool isGlobal() {
        return globalFlag;
    }
};

class FuncDeclaration : public Statement 
{
private:
    Identifier *name;
    ParaList *paraList;
    AstType *returnType;
    Routine *subRoutine;

public: 
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

    virtual string getJson() override;
};

class Parameter : public Statement 
{
public: 
    bool isVar;
    NameList *nameList;
    AstType *type;

public:
    Parameter(NameList *nl, bool isVar) : nameList(nl), isVar(isVar) { }
    
    void setType(AstType *type) {
        this->type = type;
    }

    AstType* getType() {
        return type;
    }

    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string getJson() override;
};

class Routine : public Node 
{
private:
    ConstDeclList *constDeclList;
    VarDeclList *varDeclList;
    TypeDeclList *typeDeclList;
    RoutineList *routineList;
    CompoundStatement *routineBody;

public:
    Routine(ConstDeclList *cd, TypeDeclList *tp, VarDeclList *vd, RoutineList *rl) : 
        constDeclList(cd), varDeclList(vd), typeDeclList(tp), routineList(rl) {

    }

    void setRoutineBody(CompoundStatement *routineBody) { this->routineBody = routineBody; }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    
    virtual string getJson() override;
    
    void setGlobal() {
        for (auto & constDecl : *constDeclList) {
            constDecl->setGlobal();
        }
        for (auto & varDecl : *varDeclList) {
            varDecl->setGlobal();
        }
    }
};

class Program : public Node 
{
private:
    string *programID;
    Routine *routine;

public:
    Program(string *programID, Routine *routine) : programID(programID), routine(routine) { }
    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
};

class AssignStatement : public Statement 
{
private:
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

public:
    AssignStatement(Identifier *lhs, Expression *rhs) : lhs(lhs), rhs(rhs), type(ID_ASSIGN) { }
    AssignStatement(Identifier *lhs, Expression *sub, Expression *rhs) : lhs(lhs), sub(sub), rhs(rhs), type(ARRAY_ASSIGN) { }
    AssignStatement(Identifier *lhs, Identifier *field, Expression *rhs) : lhs(lhs), field(field), rhs(rhs), type(RECORD_ASSIGN) { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
};

class BinaryExpression : public Expression 
{
private:
    Expression *lhs;
    Expression *rhs;
    string op;
public: 
    BinaryExpression(Expression *lhs, string op, Expression *rhs) : lhs(lhs), op(op), rhs(rhs) {     }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
};

class ArrayReference : public Expression 
{
private:
    Identifier *array;
    Expression *index;

public:
    ArrayReference(Identifier *array, Expression *index) : array(array), index(index) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
    
    llvm::Value *getReference(Generator & generator);
    llvm::Type *getElementType(Generator & generator);
};

class RecordReference : public Expression 
{
private:
    Identifier *record;
    Identifier *field;

public:
    RecordReference(Identifier *record, Identifier *field) : record(record), field(field) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
};

class FunctionCall : public Expression, public Statement
{
private:
    Identifier *function;
    ArgsList *args;

public:
    FunctionCall(Identifier *name) : function(name), args(new ArgsList()) { }
    FunctionCall(Identifier *name, ArgsList *args) : function(name), args(args) { }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
};

class ProcedureCall : public Statement 
{
private:
    Identifier *function;
    ArgsList *args;

public:
    ProcedureCall(Identifier *name) : function(name), args(new ArgsList()) { }
    ProcedureCall(Identifier *name, ArgsList *args) : function(name), args(args) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
};

class SysFunctionCall : public Expression, public Statement
{
private:
    enum SysFunction {
        SPL_ABS, 
        SPL_CHR, 
        SPL_ODD, 
        SPL_ORD, 
        SPL_PRED, 
        SPL_SQR, 
        SPL_SQRT, 
        SPL_SUCC,
        SPL_ERROR_FUCNTION
    };

    SysFunction getFunction(string *name) {
        string &sname = *name;
        if(sname == "abs")
            return SPL_ABS;
        else if(sname == "chr")
            return SPL_CHR;
        else if(sname == "odd")
            return SPL_ODD;
        else if(sname == "ord")
            return SPL_ORD;
        else if(sname == "pred")
            return SPL_PRED;
        else if(sname == "sqr")
            return SPL_SQR;
        else if(sname == "sqrt")
            return SPL_SQRT;
        else if(sname == "succ")
            return SPL_SUCC;
        else
            return SPL_ERROR_FUCNTION;
    }

    SysFunction function;
    ArgsList *args;
    string *name;

public:
    SysFunctionCall(string *name) : function(getFunction(name)), name(name) { }
    SysFunctionCall(string *name, ArgsList *args) : function(getFunction(name)), args(args), name(name) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
};

class SysProcedureCall : public Statement 
{
private:
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

public:
    SysProcedureCall(string *name) : procedure(getProcedure(name)), name(name) { }
    SysProcedureCall(string *name, ArgsList *args) : procedure(getProcedure(name)), args(args), name(name) { }
    SysProcedureCall(string *name, Expression *expr) : procedure(getProcedure(name)), args(new ArgsList()), name(name) {
        args->push_back(expr);
    }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
    
    llvm::Value *SysProcWrite(Generator & generator, bool isLineBreak);
    llvm::Value *SysProcRead(Generator & generator);
};

class IfStatement : public Statement 
{
private:
    Expression *condition;
    Statement *thenStatement;
    // elseStatement can be nullptr 你需要自己检测下是否是空指针
    Statement *elseStatement;

public:
    IfStatement(Expression *condition, Statement *thenStatement, Statement *elseStatement) : 
        condition(condition), thenStatement(thenStatement), elseStatement(elseStatement) {

    }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
};

class RepeatStatement : public Statement 
{
private:
    Expression *condition;
    StatementList *repeatStatement;

public:
    RepeatStatement(Expression *condition, StatementList *stmtList) : condition(condition), repeatStatement(stmtList) {

    }

    virtual llvm::Value *codeGen(Generator & generator) override;    
    virtual string getJson() override;
};

class WhileStatement : public Statement 
{
private:
    Expression *condition;
    Statement *stmt;

public:
    WhileStatement(Expression *condition, Statement *stmt) : condition(condition), stmt(stmt) {

    }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
    
};

class ForStatement : public Statement 
{
private:
    Identifier *var;
    Expression *value;
    // increase:true decrease:false
    bool isAdd;
    Expression *step;
    Statement *stmt;

public:
    ForStatement(Identifier *var, Expression *value, bool isAdd, Expression *step, Statement *stmt) :
        var(var), value(value), isAdd(isAdd), step(step), stmt(stmt) {

    }
    
    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;   
};

class CaseStatement : public Statement 
{
private:
    Expression *value;
    CaseExprList *caseExprList;

public:
    CaseStatement(Expression *value, CaseExprList *caseExprList) : value(value), caseExprList(caseExprList) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;   
};

class CaseExpression : public Statement 
{
private:
    // 可以与CaseStatement中的变量建立EQUAL的BinaryStatment进行条件判断
    Statement *stmt;

public:
    CaseExpression(Expression *value, Statement *stmt) : value(value), stmt(stmt) { }
    virtual llvm::Value *codeGen(Generator & generator) override;

    virtual string getJson() override;
    Expression *value;
};

class GotoStatement : public Statement 
{
private:
    int toLabel;

public:
    GotoStatement(int label) : toLabel(label) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
};

class CompoundStatement : public Statement 
{
private:
    StatementList *stmtList;

public:
    CompoundStatement(StatementList *stmtList) : stmtList(stmtList) { }

    virtual llvm::Value *codeGen(Generator & generator) override;
    virtual string getJson() override;
};


#endif 