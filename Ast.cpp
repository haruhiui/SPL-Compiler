#include "Ast.hpp"
#include "Generator.hpp"

using namespace std;

void LOG_I(const string & msg)
{
    // cout << "[INFO] " << msg << endl;
}

void printType(llvm::Value* v)
{
    if (v->getType()->isIntegerTy())
    {
        cout << "int " << v->getType()->getIntegerBitWidth() << endl;
    }
    else if (v->getType()->isFloatTy())
    {
        cout << "float" << endl;
    }
    else if (v->getType()->isDoubleTy())
    {
        cout << "double" << endl;
    }
    else
    {
        cout << "unknown" << endl;
    }
}

template <typename T>
void printT(T* vt)
{
    string str;
    llvm::raw_string_ostream stream(str);
    vt->print(stream);
    cout << str << endl;
}

llvm::AllocaInst *CreateEntryBlockAlloca(llvm::Function *TheFunction, llvm::StringRef VarName, llvm::Type* type)
{
  llvm::IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
  return TmpB.CreateAlloca(type, nullptr, VarName);
}

llvm::Type* toLLVMPtrType(const BuildInType & type)
{
    switch (type)
    {
        case SPL_INTEGER: return llvm::Type::getInt32PtrTy(*TheContext);
        case SPL_REAL: return llvm::Type::getDoublePtrTy(*TheContext);
        case SPL_CHAR: return llvm::Type::getInt8PtrTy(*TheContext);
        case SPL_BOOLEAN: return llvm::Type::getInt1PtrTy(*TheContext);
        case SPL_STRING: return llvm::Type::getInt8PtrTy(*TheContext);
        default: throw logic_error("Not supported pointer type.");
    }
}

llvm::Type* AstType::toLLVMType()
{
    switch (this->type)
    {
        case SPL_ARRAY:
            if (this->arrayType->range->type == SPL_CONST_RANGE)
            {
                return llvm::ArrayType::get(this->arrayType->type->toLLVMType(), this->arrayType->range->constRangeType->size());
            }
            else
            {
                return llvm::ArrayType::get(this->arrayType->type->toLLVMType(), this->arrayType->range->enumRangeType->size());
            }
        case SPL_CONST_RANGE: return TheBuilder.getInt32Ty();
        case SPL_ENUM_RANGE: return TheBuilder.getInt32Ty();
        case SPL_BUILD_IN:
            switch (buildInType)
            {
                case SPL_INTEGER: return TheBuilder.getInt32Ty();
                case SPL_REAL: return TheBuilder.getDoubleTy();
                case SPL_CHAR: return TheBuilder.getInt8Ty();
                case SPL_BOOLEAN: return TheBuilder.getInt1Ty();
                // I want to beat cby up 
                // case SPL_STRING: return TheBuilder.getInt8Ty();
                case SPL_STRING: return TheBuilder.getInt8PtrTy(); 
            }
            break;
        case SPL_ENUM:
        case SPL_RECORD:
        case SPL_USER_DEFINE:
        case SPL_VOID: return TheBuilder.getVoidTy();
    }
}

llvm::Constant* AstType::initValue(ConstValue *v)
{
    vector<llvm::Constant*> element;
    llvm::ArrayType* arrayType;;
    size_t size = 0;
    if (v != nullptr)
    {
        switch (this->type)
        {
            case SPL_ARRAY:
                if (this->arrayType->range->type == SPL_CONST_RANGE)
                {
                    size = this->arrayType->range->constRangeType->size();
                }
                else
                {
                    size = this->arrayType->range->enumRangeType->size();
                }
                for (int i = 0; i < size; i++)
                {
                    element.push_back(this->arrayType->type->initValue(v));
                }
                arrayType = (llvm::ArrayType*)this->toLLVMType();
                return llvm::ConstantArray::get(arrayType, element);
            case SPL_CONST_RANGE:
            case SPL_ENUM_RANGE: return TheBuilder.getInt32(v->getValue().i);
            case SPL_BUILD_IN:
                switch (buildInType)
                {
                    case SPL_INTEGER: return TheBuilder.getInt32(v->getValue().i);
                    case SPL_REAL: return llvm::ConstantFP::get(TheBuilder.getDoubleTy(), v->getValue().r);
                    case SPL_CHAR: return TheBuilder.getInt8(v->getValue().c);
                    case SPL_BOOLEAN: return TheBuilder.getInt1(v->getValue().b);
                    case SPL_STRING: return TheBuilder.CreateGlobalStringPtr(llvm::StringRef((const char*)(v->getValue().s)));
                }
                break;
            case SPL_ENUM:
            case SPL_RECORD:
            case SPL_USER_DEFINE:
            case SPL_VOID: return nullptr;
        }
    }
    else
    {
        switch (this->type)
        {
            case SPL_ARRAY:
                if (this->arrayType->range->type == SPL_CONST_RANGE)
                {
                    size = this->arrayType->range->constRangeType->size();
                }
                else
                {
                    size = this->arrayType->range->enumRangeType->size();
                }
                for (int i = 0; i < size; i++)
                {
                    element.push_back(this->arrayType->type->initValue());
                }
                arrayType = (llvm::ArrayType*)this->toLLVMType();
                return llvm::ConstantArray::get(arrayType, element);
            case SPL_CONST_RANGE:
            case SPL_ENUM_RANGE: return TheBuilder.getInt32(0);
            case SPL_BUILD_IN:
                switch (buildInType)
                {
                    case SPL_INTEGER: return TheBuilder.getInt32(0);
                    case SPL_REAL: return llvm::ConstantFP::get(TheBuilder.getDoubleTy(), 0.0);
                    case SPL_CHAR: return TheBuilder.getInt8(0);
                    case SPL_BOOLEAN: return TheBuilder.getInt1(0);
                    case SPL_STRING: return TheBuilder.getInt8(0);
                }
                break;
            case SPL_ENUM:
            case SPL_RECORD:
            case SPL_USER_DEFINE:
            case SPL_VOID: return nullptr;
        }
    }
}

llvm::Value *BinaryOp(llvm::Value *L, string op, llvm::Value *R)
{
    bool flag = L->getType()->isDoubleTy() || R->getType()->isDoubleTy();
    if (op == "+") {
        return flag ? TheBuilder.CreateFAdd(L, R, "addtmpf") : TheBuilder.CreateAdd(L, R, "addtmpi");
    } else if (op == "-") {
        return flag ? TheBuilder.CreateFSub(L, R, "subtmpf") : TheBuilder.CreateSub(L, R, "subtmpi");
    } else if (op == "*") {
        return flag ? TheBuilder.CreateFMul(L, R, "multmpf") : TheBuilder.CreateMul(L, R, "multmpi");
    } else if (op == "/") {
        return TheBuilder.CreateSDiv(L, R, "tmpDiv");
    } else if (op == ">=") {
        return TheBuilder.CreateICmpSGE(L, R, "tmpSGE");
    } else if (op == ">") {
        return TheBuilder.CreateICmpSGT(L, R, "tmpSGT");
    } else if (op == "<") {
        return TheBuilder.CreateICmpSLT(L, R, "tmpSLT");
    } else if (op == "<=") {
        return TheBuilder.CreateICmpSLE(L, R, "tmpSLE");
    } else if (op == "=") {
        return TheBuilder.CreateICmpEQ(L, R, "tmpEQ");
    } else if (op == "<>") {
        return TheBuilder.CreateICmpNE(L, R, "tmpNE");
    } else if (op == "or") {
        return TheBuilder.CreateOr(L, R, "tmpOR");
    } else if (op == "mod") {
        return TheBuilder.CreateSRem(L, R, "tmpSREM");
    } else if (op == "and") {
        return TheBuilder.CreateAnd(L, R, "tmpAND");
    } else if (op == "xor") {
        return TheBuilder.CreateXor(L, R, "tmpXOR");
    } else {
        return nullptr;
    }
}

llvm::Value *Identifier::codeGen(Generator & generator) {
    LOG_I("Idnetifier");
//    return TheBuilder.CreateLoad(generator.findValue(*(this->name)), *(this->name));
    return new llvm::LoadInst(generator.findValue(*(this->name)), "tmp", false, TheBuilder.GetInsertBlock());
}

llvm::Value *Integer::codeGen(Generator & generator) {
    LOG_I("Integer");
    return TheBuilder.getInt32(this->value);
}

llvm::Value *Char::codeGen(Generator & generator) {
    LOG_I("Char");
    return TheBuilder.getInt8(this->value);
}

llvm::Value *String::codeGen(Generator & generator) {
    LOG_I("String");
    // Found on Stackoverflow
    return TheBuilder.CreateGlobalStringPtr(llvm::StringRef(this->value->c_str()));
}

llvm::Value *Real::codeGen(Generator & generator) {
    LOG_I("Real");
//    return llvm::ConstantFP::get(*TheContext, llvm::APFloat(this->value));
    return llvm::ConstantFP::get(TheBuilder.getDoubleTy(), this->value);
}

llvm::Value *Boolean::codeGen(Generator & generator) {
    LOG_I("Boolean");
    return TheBuilder.getInt1(this->value);
}

llvm::Value *ConstDeclaration::codeGen(Generator & generator) {
    LOG_I("Const Declaration");
    string name = this->name->getName();
    this->type = new AstType(this->value->getType());
    if (this->isGlobal()) {
         return new llvm::GlobalVariable(*generator.TheModule, this->type->toLLVMType(), true, llvm::GlobalValue::ExternalLinkage, this->type->initValue(this->value), name);
    } else {
        auto alloc = CreateEntryBlockAlloca(generator.getCurFunction(), name, this->type->toLLVMType());
        return TheBuilder.CreateStore(this->value->codeGen(generator), alloc);
    }
}

llvm::Value *TypeDeclaration::codeGen(Generator & generator) {
    LOG_I("Type Declaration");
    return nullptr;
}

llvm::Value *AstType::codeGen(Generator & generator) {
    LOG_I("Type");
    switch (this->type)
    {
        case SPL_ARRAY: 		this->arrayType->codeGen(generator); break;
        case SPL_CONST_RANGE: 	this->constRangeType->codeGen(generator); break;
        case SPL_ENUM_RANGE: 	this->enumRangeType->codeGen(generator); break;
        case SPL_RECORD: 		this->recordType->codeGen(generator); break;
        case SPL_ENUM: 			this->enumType->codeGen(generator); break;
        case SPL_USER_DEFINE: 	this->userDefineType->codeGen(generator); break;
        case SPL_BUILD_IN: 		break;
        case SPL_VOID: 			break;
    }
    return (llvm::Value*)this->toLLVMType();
}

llvm::Value *EnumType::codeGen(Generator & generator) {
    LOG_I("Enum Type");
    // TODO
    return nullptr;
}

llvm::Value *AstArrayType::codeGen(Generator & generator) {
    LOG_I("Array Type");
    return this->range->codeGen(generator);
}

llvm::Value *RecordType::codeGen(Generator & generator) {
    LOG_I("Record Type");
    return nullptr;
}

llvm::Value *ConstRangeType::mapIndex(llvm::Value *indexValue, Generator & generator) {
    return BinaryOp(indexValue, "-", this->lowBound->codeGen(generator));
}

llvm::Value *ConstRangeType::codeGen(Generator & generator) {
    LOG_I("Const Range Type");
    this->size();
    return nullptr;
}

llvm::Value *EnumRangeType::mapIndex(llvm::Value *indexValue, Generator & generator) {
    return BinaryOp(indexValue, "-", this->lowValue);
}

int64_t getActualValue(llvm::Value *v) {
    llvm::Constant *constValue = llvm::cast<llvm::GlobalVariable>(v)->getInitializer();
    llvm::ConstantInt *constInt = llvm::cast<llvm::ConstantInt>(constValue);
    return constInt->getSExtValue();
}

size_t EnumRangeType::size() {
    int64_t low = 1, up = 0;
    if (this->lowValue->getType() == this->upValue->getType()) {
        low = getActualValue(this->lowValueAddr);
        up = getActualValue(this->upValueAddr);
//        cout << "low: " << low << " up: " << up << endl;
        if (low > up) {
            throw std::range_error("[ERROR] low > up.");
        }
    } else {
        throw std::domain_error("[ERROR] Invalid range type.");
    }
    return up - low + 1;
}

llvm::Value *EnumRangeType::codeGen(Generator & generator) {
    LOG_I("Enum Range Type");
    this->upValue = this->upBound->codeGen(generator);
    this->lowValue = this->lowBound->codeGen(generator);
    this->upValueAddr = generator.findValue(this->upBound->getName());
    this->lowValueAddr = generator.findValue(this->lowBound->getName());
    this->size();
    return nullptr;
}

llvm::Value *FieldDeclaration::codeGen(Generator & generator) {
    LOG_I("Field Declaration");
    return nullptr;
}

llvm::Value *VarDeclaration::codeGen(Generator & generator) {
    LOG_I("Var Declaration");
    llvm::Value* alloc = nullptr;
    llvm::Type* varType;
    for (auto & id : *(this->nameList)) {
        if (this->type->type == AstType::SPL_ARRAY) {
            generator.arrayMap[id->getName()] = this->type->arrayType;
        }
        varType = (llvm::Type*)(this->type->codeGen(generator));
        if (this->isGlobal()) {
            alloc = new llvm::GlobalVariable(*generator.TheModule, varType, false, llvm::GlobalValue::ExternalLinkage, this->type->initValue(), id->getName());
        } else {
            alloc = CreateEntryBlockAlloca(generator.getCurFunction(), id->getName(), varType);
        }
    }
    return alloc;
}

llvm::Value *FuncDeclaration::codeGen(Generator & generator) {
    LOG_I("Function Declaration");
    //Prototype
    vector<llvm::Type*> argTypes;
    for (auto & argType : *(this->paraList)) {
        if (argType->isVar) {
            argTypes.insert(argTypes.end(), argType->nameList->size(), toLLVMPtrType(argType->getType()->buildInType));
        } else {
            argTypes.insert(argTypes.end(), argType->nameList->size(), argType->getType()->toLLVMType());
        }
    }
    llvm::FunctionType *funcType = llvm::FunctionType::get(this->returnType->toLLVMType(), argTypes, false);
    llvm::Function *function = llvm::Function::Create(funcType, llvm::GlobalValue::InternalLinkage, this->name->getName(), generator.TheModule.get());
    generator.pushFunction(function);
    
    // Block
    llvm::BasicBlock *newBlock = llvm::BasicBlock::Create(*TheContext, "entrypoint", function, nullptr);
    TheBuilder.SetInsertPoint(newBlock);
    
    // Parameters
    llvm::Function::arg_iterator argIt =  function->arg_begin();
    int index = 1;
    for (auto & args : *(this->paraList)) {
        for (auto & arg : *(args->nameList)) {
            llvm::Value *alloc = nullptr;
            if (args->isVar) {
                //Check value
//                alloc = generator.findValue(arg->getName());
                function->addAttribute(index, llvm::Attribute::NonNull);
                alloc = TheBuilder.CreateGEP(argIt++, TheBuilder.getInt32(0), arg->getName());
            } else {
                alloc = CreateEntryBlockAlloca(function, arg->getName(), args->type->toLLVMType());
                TheBuilder.CreateStore(argIt++, alloc);
            }
            index++;
        }
    }
    
    //Return
    llvm::Value *res = nullptr;
    if (this->returnType->type != AstType::SPL_VOID) {
        res = CreateEntryBlockAlloca(function, this->name->getName(), this->returnType->toLLVMType());
    }
    
    //Sub routine
    this->subRoutine->codeGen(generator);
    
    //Return value
    if (this->returnType->type != AstType::SPL_VOID) {
        auto returnInst = this->name->codeGen(generator);
        TheBuilder.CreateRet(returnInst);
    } else {
        TheBuilder.CreateRetVoid();
    }
    
    //Pop back
    generator.popFunction();
    TheBuilder.SetInsertPoint(&(generator.getCurFunction())->getBasicBlockList().back());
    return function;
}

llvm::Value *Parameter::codeGen(Generator & generator) {
    LOG_I("Parameter");
    //Not need
    return nullptr;
}

llvm::Value *Routine::codeGen(Generator & generator) {
    LOG_I("Routine");
    llvm::Value* res = nullptr;
    
    //Const declareation part
    for (auto & constDecl : *(this->constDeclList))
    {
        res = constDecl->codeGen(generator);
    }
    //Variable declareation part
    for (auto & varDecl : *(this->varDeclList))
    {
        res = varDecl->codeGen(generator);
    }
    //Type declareation part
    for (auto & typeDecl : *(this->typeDeclList))
    {
        res = typeDecl->codeGen(generator);
    }
    //Routine declareation part
    for (auto & routineDecl : *(this->routineList))
    {
        res = routineDecl->codeGen(generator);
    }
    
    //Routine body
    res = routineBody->codeGen(generator);
    return res;
}

llvm::Value *Program::codeGen(Generator & generator) {
    LOG_I("Program");
    //Main function prototype
    vector<llvm::Type*> argTypes;
    llvm::FunctionType * funcType = llvm::FunctionType::get(TheBuilder.getVoidTy(), makeArrayRef(argTypes), false);
    // generator.mainFunction = llvm::Function::Create(funcType, 
    //     llvm::GlobalValue::InternalLinkage, "main", generator.TheModule.get());
    generator.mainFunction = llvm::Function::Create(funcType, 
        llvm::GlobalValue::ExternalLinkage, "main", generator.TheModule.get());
    llvm::BasicBlock * basicBlock = llvm::BasicBlock::Create(*TheContext, "entrypoint", generator.mainFunction, 0);
    
    generator.pushFunction(generator.mainFunction);
    TheBuilder.SetInsertPoint(basicBlock);
    //Create System functions
    generator.printf = generator.createPrintf();
    generator.scanf = generator.createScanf();
    //Code generate
    this->routine->setGlobal();
    this->routine->codeGen(generator);
    TheBuilder.CreateRetVoid();
    generator.popFunction();
    
    return nullptr;
}

llvm::Value *AssignStatement::codeGen(Generator & generator) {
    LOG_I("Assign Statement");
    llvm::Value *res = nullptr;
    this->forward(generator);
    switch (this->type)
    {
        case ID_ASSIGN: res = TheBuilder.CreateStore(this->rhs->codeGen(generator), generator.findValue(this->lhs->getName())); break;
        case ARRAY_ASSIGN: res = TheBuilder.CreateStore(this->rhs->codeGen(generator), (new ArrayReference(this->lhs, this->sub))->getReference(generator)); break;
        case RECORD_ASSIGN: res = nullptr; 
    }
    this->backward(generator);
    return res;
}

llvm::Value *BinaryExpression::codeGen(Generator & generator) {
    LOG_I("Binary Expression");
    llvm::Value* L = this->lhs->codeGen(generator);
    llvm::Value* R = this->rhs->codeGen(generator);
    if (!L || !R) return nullptr;

    return BinaryOp(L, this->op, R);
}

llvm::Value *ArrayReference::codeGen(Generator & generator) {
    LOG_I("Array Reference");
    return TheBuilder.CreateLoad(this->getReference(generator), "arrRef");
}

llvm::Value *ArrayReference::getReference(Generator & generator)
{
    string name = this->array->getName();
    llvm::Value* arrayValue = generator.findValue(name), *indexValue;
    if (generator.arrayMap[name]->range->type == AstType::SPL_CONST_RANGE)
    {
        indexValue = generator.arrayMap[name]->range->constRangeType->mapIndex(this->index->codeGen(generator), generator);
    }
    else
    {
        indexValue = generator.arrayMap[name]->range->enumRangeType->mapIndex(this->index->codeGen(generator), generator);
    }
    vector<llvm::Value*> indexList;
    indexList.push_back(TheBuilder.getInt32(0));
    indexList.push_back(indexValue);
    return TheBuilder.CreateInBoundsGEP(arrayValue, llvm::ArrayRef<llvm::Value*>(indexList));
}

llvm::Value *RecordReference::codeGen(Generator & generator) {
    LOG_I("Record Reference");
    return nullptr;
}

llvm::Value *FunctionCall::codeGen(Generator & generator) {
    LOG_I("Function Call");
    this->forward(generator);
    llvm::Function *function = generator.TheModule->getFunction(this->function->getName());
    if (function == nullptr)
    {
        throw domain_error("[ERROR] Function not defined: " + this->function->getName());
    }
    vector<llvm::Value*> args;
    llvm::Function::arg_iterator argIt =  function->arg_begin();
    for (auto & arg : *(this->args))
    {
        if (argIt->hasNonNullAttr())
        {
//            cout << "Pass a pointer" << endl;
            llvm::Value * addr = generator.findValue(dynamic_cast<Identifier*>(arg)->getName());
            args.push_back(addr);
        }
        else
        {
//            cout << "Pass a value" << endl;
            args.push_back(arg->codeGen(generator));
        }
        argIt++;
    }
    llvm::Value *res = TheBuilder.CreateCall(function, args, "calltmp");
    this->backward(generator);
    return res;
}

llvm::Value *ProcedureCall::codeGen(Generator & generator) {
    LOG_I("Procedure Call");
    this->forward(generator);
    llvm::Function *function = generator.TheModule->getFunction(this->function->getName());
    if (function == nullptr)
    {
        throw domain_error("[ERROR] Function not defined: " + this->function->getName());
    }
    vector<llvm::Value*> args;
    llvm::Function::arg_iterator argIt =  function->arg_begin();
    for (auto & arg : *(this->args))
    {
        if (argIt->hasNonNullAttr())
        {
//            cout << "Pass a pointer" << endl;
            llvm::Value * addr = generator.findValue(dynamic_cast<Identifier*>(arg)->getName());
            args.push_back(addr);
        }
        else
        {
//            cout << "Pass a value" << endl;
            args.push_back(arg->codeGen(generator));
        }
        argIt++;
    }
    // llvm::Value* res = TheBuilder.CreateCall(function, args, "calltmp"); 
    // procedure must return a value if we use the last sentence, but procedure must not return anything in SPL. 
    llvm::Value* res = TheBuilder.CreateCall(function, args);
    this->backward(generator);
    return res;
}

llvm::Value *SysFunctionCall::codeGen(Generator & generator) {
    LOG_I("System Function Call");
    this->forward(generator);
    //TODO::Code gen
    this->backward(generator);
    return nullptr;
}

llvm::Value *SysProcedureCall::SysProcWrite(Generator & generator, bool isLineBreak)
{
    string formatStr = "";
    vector<llvm::Value*> params;
    for (auto & arg : *(this->args))
    {
        llvm::Value* argValue = arg->codeGen(generator);
        if (argValue->getType() == TheBuilder.getInt32Ty())
        {
            formatStr += "%d";
        }
        else if (argValue->getType() == TheBuilder.getInt8Ty())
        {
            formatStr += "%c"; 
        }
        else if (argValue->getType() == TheBuilder.getInt8PtrTy()) 
        { 
            formatStr += "%s"; 
        }
        else if (argValue->getType() == TheBuilder.getInt1Ty())
        {
            formatStr += "%d";
        }
        else if (argValue->getType()->isDoubleTy())
        {
            formatStr += "%lf";
        }
        else
        {
            // throw logic_error("[ERROR] Invalid type to write.");
        }
        params.push_back(argValue);
    }

    if (isLineBreak)
    {
        formatStr += "\n";
    }
    auto formatConst = llvm::ConstantDataArray::getString(*TheContext, formatStr.c_str());
    auto formatStrVar = new llvm::GlobalVariable(*(generator.TheModule), llvm::ArrayType::get(TheBuilder.getInt8Ty(), formatStr.size() + 1), true, llvm::GlobalValue::ExternalLinkage, formatConst, ".str");
    auto zero = llvm::Constant::getNullValue(TheBuilder.getInt32Ty());
    llvm::Constant* indices[] = {zero, zero};
    auto varRef = llvm::ConstantExpr::getGetElementPtr(formatStrVar->getType()->getElementType(), formatStrVar, indices);
//    auto varRef
    params.insert(params.begin(), varRef);
    return TheBuilder.CreateCall(generator.printf, llvm::makeArrayRef(params), "printf");
}

llvm::Value *SysProcedureCall::SysProcRead(Generator & generator)
{
    string formatStr = "";
    vector<llvm::Value*> params;
    auto arg = this->args->front();
    llvm::Value *argAddr, *argValue;
    //Just common variable
    argAddr = generator.findValue(dynamic_cast<Identifier*>(arg)->getName());
    argValue = arg->codeGen(generator);
    if (argValue->getType() == TheBuilder.getInt32Ty())
    {
        formatStr += "%d";
    }
    else if (argValue->getType() == TheBuilder.getInt8Ty())
    {
        formatStr += "%c"; 
    }
    // better not support 
    // else if (argValue->getType() == TheBuilder.getInt8PtrTy()) 
    // {
    //     formatStr += "%s"; 
    // }
    else if (argValue->getType() == TheBuilder.getInt1Ty())
    {
        formatStr += "%d";
    }
    else if (argValue->getType()->isDoubleTy())
    {
        formatStr += "%lf";
    }
    else
    {
        throw logic_error("[ERROR] Invalid type to read.");
    }
    params.push_back(argAddr);
    params.insert(params.begin(), TheBuilder.CreateGlobalStringPtr(formatStr));
    return TheBuilder.CreateCall(generator.scanf, params, "scanf");
}

llvm::Value *SysProcedureCall::codeGen(Generator & generator) {
    LOG_I("System Procedure Call");
    llvm::Value *res = nullptr;
    this->forward(generator);
    switch (this->procedure) {
        case SPL_READ: res = this->SysProcRead(generator); break;
        case SPL_WRITE: res = this->SysProcWrite(generator, false); break;
        case SPL_WRITELN: res = this->SysProcWrite(generator, true); break;
        case SPL_ERROR_PROCEDURE: throw domain_error("[ERROR] Unknown System Procedure");
    }
    this->backward(generator);
    return res;
}

llvm::Value *IfStatement::codeGen(Generator & generator) {
    LOG_I("If Statement");
    this->forward(generator);
    
    llvm::Value *condValue = this->condition->codeGen(generator), *thenValue = nullptr, *elseValue = nullptr;
    condValue = TheBuilder.CreateICmpNE(condValue, llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 0, true), "ifCond");

    llvm::Function *TheFunction = generator.getCurFunction();
    llvm::BasicBlock *thenBB = llvm::BasicBlock::Create(*TheContext, "then", TheFunction);
    llvm::BasicBlock *elseBB = llvm::BasicBlock::Create(*TheContext, "else", TheFunction);
    llvm::BasicBlock *mergeBB = llvm::BasicBlock::Create(*TheContext, "merge", TheFunction);

    //Then
    auto branch = TheBuilder.CreateCondBr(condValue, thenBB, elseBB);
    TheBuilder.SetInsertPoint(thenBB);
    thenValue = this->thenStatement->codeGen(generator);
    TheBuilder.CreateBr(mergeBB);
    thenBB = TheBuilder.GetInsertBlock();

    //Else
//    if (TheFunction != generator.mainFunction)
//    {
//        TheFunction->getBasicBlockList().push_back(elseBB);
//    }
    TheBuilder.SetInsertPoint(elseBB);
    if (this->elseStatement != nullptr)
    {
        elseValue = this->elseStatement->codeGen(generator);
    }
    TheBuilder.CreateBr(mergeBB);
    elseBB = TheBuilder.GetInsertBlock();

    //Merge
//    if (TheFunction != generator.mainFunction)
//    {
//        TheFunction->getBasicBlockList().push_back(mergeBB);
//    }
    TheBuilder.SetInsertPoint(mergeBB);
    
    this->backward(generator);
    return branch;
}

llvm::Value *RepeatStatement::codeGen(Generator & generator) {
    LOG_I("Repeate Statement");
    this->forward(generator);
    
    llvm::Function *TheFunction = generator.getCurFunction();
    llvm::BasicBlock *condBB = llvm::BasicBlock::Create(*TheContext, "cond", TheFunction);
    llvm::BasicBlock *loopBB = llvm::BasicBlock::Create(*TheContext, "loop", TheFunction);
    llvm::BasicBlock *afterBB = llvm::BasicBlock::Create(*TheContext, "afterLoop", TheFunction);
    
    //Loop
    TheBuilder.CreateBr(loopBB);
    TheBuilder.SetInsertPoint(loopBB);
    for (auto & stmt : *(this->repeatStatement))
    {
        stmt->codeGen(generator);
    }
    TheBuilder.CreateBr(condBB);
    loopBB = TheBuilder.GetInsertBlock();
    
    //Cond
    TheBuilder.SetInsertPoint(condBB);
    llvm::Value *condValue = this->condition->codeGen(generator);
    condValue = TheBuilder.CreateICmpNE(condValue, llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 0, true), "repeateCond");
    auto branch = TheBuilder.CreateCondBr(condValue, loopBB, afterBB);
    
    //After
    TheBuilder.SetInsertPoint(afterBB);
    this->backward(generator);
    return branch;
}

llvm::Value *WhileStatement::codeGen(Generator & generator) {
    LOG_I("While Statement");
    this->forward(generator);
    llvm::Function *TheFunction = generator.getCurFunction();
    llvm::BasicBlock *condBB = llvm::BasicBlock::Create(*TheContext, "cond", TheFunction);
    llvm::BasicBlock *loopBB = llvm::BasicBlock::Create(*TheContext, "loop", TheFunction);
    llvm::BasicBlock *afterBB = llvm::BasicBlock::Create(*TheContext, "afterLoop", TheFunction);
    
    //Cond
    TheBuilder.CreateBr(condBB);
    TheBuilder.SetInsertPoint(condBB);
    llvm::Value *condValue = this->condition->codeGen(generator);
    condValue = TheBuilder.CreateICmpNE(condValue, llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 0, true), "whileCond");
    auto branch = TheBuilder.CreateCondBr(condValue, loopBB, afterBB);
    condBB = TheBuilder.GetInsertBlock();
    
    //Loop
    TheBuilder.SetInsertPoint(loopBB);
    this->stmt->codeGen(generator);
    TheBuilder.CreateBr(condBB);
    
    //After
    TheBuilder.SetInsertPoint(afterBB);
    this->backward(generator);
    return branch;
}

llvm::Value *ForStatement::codeGen(Generator & generator) {
    LOG_I("For Statement");
    this->forward(generator);
    //Init
    llvm::Function *TheFunction = generator.getCurFunction();
    llvm::Value* startValue = this->value->codeGen(generator);
    llvm::Value* endValue = this->step->codeGen(generator);
    llvm::Value *condValue = nullptr, *curValue = nullptr, *varValue = generator.findValue(this->var->getName());
    TheBuilder.CreateStore(startValue, varValue);
    
    llvm::BasicBlock *condBB = llvm::BasicBlock::Create(*TheContext, "cond", TheFunction);
    llvm::BasicBlock *loopBB = llvm::BasicBlock::Create(*TheContext, "loop", TheFunction);
    llvm::BasicBlock *afterBB = llvm::BasicBlock::Create(*TheContext, "afterLoop", TheFunction);
    
    //Cond
    TheBuilder.CreateBr(condBB);
    TheBuilder.SetInsertPoint(condBB);
//    curValue = TheBuilder.CreateLoad(varValue, this->var->getName());
    curValue = this->var->codeGen(generator);
    if (this->isAdd)
    {
        condValue = TheBuilder.CreateICmpSLE(curValue, endValue);
    }
    else
    {
        condValue = TheBuilder.CreateICmpSGE(curValue, endValue);
    }
    condValue = TheBuilder.CreateICmpNE(condValue, llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 0, true), "forCond");
    auto branch = TheBuilder.CreateCondBr(condValue, loopBB, afterBB);
    condBB = TheBuilder.GetInsertBlock();
    
    //Loop
    TheBuilder.SetInsertPoint(loopBB);
    this->stmt->codeGen(generator);
    llvm::Value *tmpValue = TheBuilder.CreateAdd(curValue, TheBuilder.getInt32(this->isAdd ? 1 : -1));
    TheBuilder.CreateStore(tmpValue, varValue);
    TheBuilder.CreateBr(condBB);
    loopBB = TheBuilder.GetInsertBlock();
    
    //After
    TheBuilder.SetInsertPoint(afterBB);
    this->backward(generator);
    return branch;
}

llvm::Value *CaseStatement::codeGen(Generator & generator) {
    LOG_I("Case Statement");
    this->forward(generator);
    
    llvm::Value *cmpValue = this->value->codeGen(generator), *condValue = nullptr;
    llvm::Function *TheFunction = generator.getCurFunction();
    llvm::BasicBlock *afterBB = llvm::BasicBlock::Create(*TheContext, "afterCase", TheFunction);
    vector<llvm::BasicBlock*> switchBBs, caseBBs;
    for (int i = 1; i <= this->caseExprList->size(); i++){
        switchBBs.push_back(llvm::BasicBlock::Create(*TheContext, "switch", TheFunction));
        caseBBs.push_back(llvm::BasicBlock::Create(*TheContext, "case", TheFunction));
    }
    TheBuilder.CreateBr(switchBBs[0]);
    for (int i = 0; i < this->caseExprList->size(); i++){
        //Switch
        TheBuilder.SetInsertPoint(switchBBs[i]);
        condValue = BinaryOp(cmpValue, "=", (*caseExprList)[i]->value->codeGen(generator));
        if (i < this->caseExprList->size() - 1){
            TheBuilder.CreateCondBr(condValue, caseBBs[i], switchBBs[i + 1]);
        } else {
            TheBuilder.CreateCondBr(condValue, caseBBs[i], afterBB);
        }
        
        //Case
        TheBuilder.SetInsertPoint(caseBBs[i]);
        (*caseExprList)[i]->codeGen(generator);
        TheBuilder.CreateBr(afterBB);
    }
    
    //After
    TheBuilder.SetInsertPoint(afterBB);
    this->backward(generator);
    return nullptr;
}

llvm::Value *CaseExpression::codeGen(Generator & generator) {
    LOG_I("Case Expression");
    return this->stmt->codeGen(generator);
}

void Statement::forward(Generator & generator) {
    llvm::Function *TheFunction = generator.getCurFunction();
    if (this->label >= 0) {
        if (generator.labelBlock[this->label] == nullptr) {
            generator.labelBlock[this->label] = llvm::BasicBlock::Create(*TheContext, "Label_" + to_string(label), TheFunction);
        }
        if (this->afterBB == nullptr) {
            this->afterBB = llvm::BasicBlock::Create(*TheContext, "afterLabel_" + to_string(this->label), TheFunction);
        }
        TheBuilder.CreateBr(generator.labelBlock[this->label]);
        TheBuilder.SetInsertPoint(generator.labelBlock[this->label]);
    }
}

void Statement::backward(Generator & generator)
{
    if (this->label >= 0 && afterBB != nullptr)
    {
        TheBuilder.SetInsertPoint(generator.labelBlock[this->label]);
        TheBuilder.CreateBr(this->afterBB);
        TheBuilder.SetInsertPoint(this->afterBB);
    }
}

llvm::Value *GotoStatement::codeGen(Generator & generator) {
    LOG_I("Goto Statement");
    this->forward(generator);
    llvm::Value *res = nullptr;
    if (generator.labelBlock[this->toLabel] == nullptr) {
        generator.labelBlock[this->toLabel] = llvm::BasicBlock::Create(*TheContext, "Label_" + to_string(this->toLabel), generator.getCurFunction());
    }
    res = TheBuilder.CreateBr(generator.labelBlock[this->toLabel]);
//    if (this->afterBB == nullptr)
//    {
//        this->afterBB = llvm::BasicBlock::Create(*TheContext, "afterLabel_" + to_string(this->toLabel), generator.getCurFunction());
//    }
//    TheBuilder.SetInsertPoint(this->afterBB);
    this->backward(generator);
    return res;
}

llvm::Value *CompoundStatement::codeGen(Generator & generator) {
    LOG_I("CompoundStatement");
    this->forward(generator);
    llvm::Value *lastValue = nullptr;
    for (auto & stmt : *(this->stmtList)) {
        lastValue = stmt->codeGen(generator);
    }
    this->backward(generator);
    return lastValue;
}

string jsonfy(string name) {
    return "{ \"name\" : \"" + name + "\" }";
}

string jsonfy(string name, vector<string> children) {
    string result = "{ \"name\" : \"" + name + "\", \"children\" : [ ";
    int i = 0;
    for(auto &child : children) {
        if(i != children.size() - 1)
            result += child + ", ";
        else 
            result += child + " ";
        i++;
    }
    return result + " ] }";
}

string jsonfy(string name, string value) {
    return jsonfy(name, vector<string>{value});
}

string jsonfy(string name, string value, vector<string> children) {
    string result = "{ \"name\" : \"" + name + "\", \"value\" : \"" + value + "\", \"children\" : [ ";
    int i = 0;
    for(auto &child : children) {
        if(i != children.size() - 1)
            result += child + ", ";
        else 
            result += child + " ";
        i++;
    }
    return result + " ] }";
}

string Program::getJson() {
    return jsonfy("program", *programID, vector<string>{routine->getJson()});
}

string Identifier::getJson() {
    return jsonfy("Identifier", jsonfy(*name));
}

string Integer::getJson() {
    return jsonfy("Integer", jsonfy(to_string(value)));
}

string Real::getJson() {
    return jsonfy("Real", jsonfy(to_string(value)));
}

string Char::getJson() {
    return jsonfy("Char", jsonfy(string(1, value)));
}

string String::getJson() {
    return jsonfy("String", jsonfy(*value));
}
string Boolean::getJson() {
    return jsonfy("Boolean", jsonfy((value ? "true" : "false")));
}

string ConstDeclaration::getJson() {
    vector<string> children;
    children.push_back(name->getJson());
    children.push_back(value->getJson());
    return jsonfy("ConstDeclaration", children);
}

string EnumType::getJson() {
    vector<string> children;
    for(auto &name : *enumList) {
        children.push_back(name->getJson());
    }
    return jsonfy("EnumType", children);
}

string AstArrayType::getJson() {
    vector<string> children;
    children.push_back(jsonfy("range", range->getJson()));
    children.push_back(jsonfy("type", type->getJson()));
    return jsonfy("AstArrayType", children);
}

string ConstRangeType::getJson() {
    vector<string> children;
    children.push_back(jsonfy("lowBound", lowBound->getJson()));
    children.push_back(jsonfy("upBound", upBound->getJson()));
    return jsonfy("ConstRangeType", children);
}

string EnumRangeType::getJson() {
    vector<string> children;
    children.push_back(jsonfy("lowBound", lowBound->getJson()));
    children.push_back(jsonfy("upBound", upBound->getJson()));
    return jsonfy("EnumRangeType", children);
}

string FieldDeclaration::getJson() {
    vector<string> children;
    vector<string> nameListJson;
    for(auto &name : *nameList) {
        nameListJson.push_back(name->getJson());
    }
    children.push_back(jsonfy("nameList", nameListJson));
    children.push_back(jsonfy("type", type->getJson()));
    return jsonfy("FieldDeclaration", children);
}

string RecordType::getJson() {
    vector<string> children;
    for(auto &field : *fieldList) {
        children.push_back(field->getJson());
    }

    return jsonfy("RecordType", children);
}

string AstType::getJson() {
    switch (type)
    {
    case SPL_ARRAY:
        return arrayType->getJson();
        break;
    case SPL_RECORD:
        return recordType->getJson();
        break;
    case SPL_ENUM:
        return enumType->getJson();
        break;
    case SPL_CONST_RANGE:
        return constRangeType->getJson();
        break;
    case SPL_ENUM_RANGE:
        return enumRangeType->getJson();
        break;
    case SPL_BUILD_IN:
        switch (buildInType)
        {
        case SPL_INTEGER:
            return jsonfy("SYS_TYPE", jsonfy("Integer"));
            break;
        case SPL_REAL:
            return jsonfy("SYS_TYPE", jsonfy("Real"));
            break;
        case SPL_CHAR:
            return jsonfy("SYS_TYPE", jsonfy("Char"));
            break;
        case SPL_BOOLEAN:
            return jsonfy("SYS_TYPE", jsonfy("Boolean"));
            break;
        case SPL_STRING:
            return jsonfy("SYS_TYPE", jsonfy("String"));
            break;
        default:
            break;
        }
        break;
    case SPL_USER_DEFINE:
        return jsonfy("UserDefineType", jsonfy(userDefineType->getName()));
        break;
    default:
        return jsonfy("ErrorType");
        break;
    }
}

string TypeDeclaration::getJson() {
    vector<string> children;
    children.push_back(name->getJson());
    children.push_back(type->getJson());
    return jsonfy("TypeDeclaration", children);
}

string VarDeclaration::getJson() {
    vector<string> children;
    vector<string> nameListJson;
    for(auto &name : *nameList) {
        nameListJson.push_back(name->getJson());
    }
    children.push_back(jsonfy("Type", type->getJson()));
    children.push_back(jsonfy("NameList", nameListJson));
    return jsonfy("VarDeclaration", children);
}

string FuncDeclaration::getJson() {
    vector<string> children;
    children.push_back(name->getJson());
    vector<string> paraListJson;
    for(auto &para : *paraList)
        paraListJson.push_back(para->getJson());
    children.push_back(jsonfy("ParaList", paraListJson));
    children.push_back(returnType->getJson());
    children.push_back(subRoutine->getJson());

    return jsonfy("FuncDeclaration", children);
}

string Parameter::getJson() {
    vector<string> children;
    vector<string> nameListJson;
    for(auto &name : *nameList) {
        nameListJson.push_back(name->getJson());
    }
    children.push_back(jsonfy("Type", type->getJson()));
    children.push_back(jsonfy("NameList", nameListJson));
    children.push_back(jsonfy("isVar", jsonfy((isVar ? "true" : "false" ))));
    return jsonfy("Parameter", children);
}

string Routine::getJson() {
    vector<string> children;
    vector<string> constJson, varJson, typeJson, routineJson;
    for(auto constDecl : *constDeclList)
        constJson.push_back(constDecl->getJson());
    for(auto varDecl : *varDeclList)
        varJson.push_back(varDecl->getJson());
    for(auto typeDecl : *typeDeclList)
        typeJson.push_back(typeDecl->getJson());
    for(auto routineDecl : *routineList)
        routineJson.push_back(routineDecl->getJson());
    children.push_back(jsonfy("ConstDeclList", constJson));
    children.push_back(jsonfy("VarDeclList", varJson)); 
    children.push_back(jsonfy("TypeDeclList", typeJson));
    children.push_back(jsonfy("RoutineDeclList", routineJson));
    children.push_back(routineBody->getJson());
    return jsonfy("Routine", children);
}

string AssignStatement::getJson() {
    vector<string> children;
    switch (type)
    {
    case ID_ASSIGN:
        children.push_back(lhs->getJson());
        children.push_back(rhs->getJson());
        break;
    case ARRAY_ASSIGN:
        children.push_back(lhs->getJson());
        children.push_back(sub->getJson());
        children.push_back(rhs->getJson());
        break;
    case RECORD_ASSIGN:
        children.push_back(lhs->getJson());
        children.push_back(field->getJson());
        children.push_back(rhs->getJson());
        break;
    default:
        break;
    }    

    return jsonfy("AssignStatement", children);
}

string BinaryExpression::getJson() {
    vector<string> children;
    children.push_back(lhs->getJson());
    children.push_back(jsonfy(this->op));
    children.push_back(rhs->getJson());

    return jsonfy("BinaryExpression", children);
}

string ArrayReference::getJson() {
    vector<string> children;
    children.push_back(array->getJson());
    children.push_back(index->getJson());

    return jsonfy("ArrayReference", children);
}

string RecordReference::getJson() {
    vector<string> children;
    children.push_back(record->getJson());
    children.push_back(field->getJson());

    return jsonfy("RecordReference", children);
}

string FunctionCall::getJson() {
    vector<string> children;
    children.push_back(function->getJson());
    vector<string> argsJson;
    for(auto &arg : *args) {
        argsJson.push_back(arg->getJson());
    }
    children.push_back(jsonfy("ArgList", argsJson));
    return jsonfy("FunctionCall", children);
}

string ProcedureCall::getJson() {
    vector<string> children;
    children.push_back(function->getJson());
    vector<string> argsJson;
    for(auto &arg : *args) {
        argsJson.push_back(arg->getJson());
    }
    children.push_back(jsonfy("ArgList", argsJson));
    return jsonfy("ProcedureCall", children);
}

string SysFunctionCall::getJson() {
    vector<string> children;
    children.push_back(jsonfy("SysFunction", jsonfy(*name)));
    vector<string> argsJson;
    for(auto &arg : *args) {
        argsJson.push_back(arg->getJson());
    }
    children.push_back(jsonfy("ArgList", argsJson));
    return jsonfy("SysFunctionCall", children);
}

string SysProcedureCall::getJson() {
    vector<string> children;
    children.push_back(jsonfy("SysProcedure", jsonfy(*name)));
    vector<string> argsJson;
    for(auto &arg : *args) {
        argsJson.push_back(arg->getJson());
    }
    children.push_back(jsonfy("ArgList", argsJson));
    return jsonfy("SysProcedureCall", children);
}

string IfStatement::getJson() {
    vector<string> children;
    children.push_back(condition->getJson());
    children.push_back(thenStatement->getJson());
    if(elseStatement)
        children.push_back(elseStatement->getJson());

    return jsonfy("IfStatement", children);
}

string RepeatStatement::getJson() {
    vector<string> children;
    children.push_back(condition->getJson());
    vector<string> repeatStmtJson;
    for(auto &stmt : *repeatStatement)
        repeatStmtJson.push_back(stmt->getJson());
    children.push_back(jsonfy("RepeatStatement", repeatStmtJson));

    return jsonfy("RepeatStatement", children);
}

string WhileStatement::getJson() {
    vector<string> children;
    children.push_back(condition->getJson());
    children.push_back(stmt->getJson());

    return jsonfy("WhileStatement", children);
}

string ForStatement::getJson() {
    vector<string> children;
    children.push_back(var->getJson());
    children.push_back(value->getJson());
    children.push_back(jsonfy("isAdd", jsonfy((isAdd ? "true" : "false"))));
    children.push_back(step->getJson());
    children.push_back(stmt->getJson());

    return jsonfy("ForStatement", children);
}  

string CaseStatement::getJson() {
    vector<string> children;
    children.push_back(value->getJson());
    vector<string> caseExprJsonList;
    for(auto &caseExpr : *caseExprList) {
        caseExprJsonList.push_back(caseExpr->getJson());
    }
    children.push_back(jsonfy("CaseExprList", caseExprJsonList));

    return jsonfy("CaseStatement", children);
}    

string CaseExpression::getJson() {
    vector<string> children;
    children.push_back(value->getJson());
    children.push_back(stmt->getJson());

    return jsonfy("CaseExpression", children);
}

string GotoStatement::getJson() {
    return jsonfy("GotoStatement", jsonfy(to_string(toLabel)));
}    

string CompoundStatement::getJson() {
    vector<string> stmtJsonList;
    for(auto &stmt : *stmtList) {
        stmtJsonList.push_back(stmt->getJson());
    }
    return jsonfy("CompoundStatement", stmtJsonList);
}
