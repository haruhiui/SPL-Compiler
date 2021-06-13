#include "Ast.hpp"
#include "Generator.hpp"

using namespace std;

void echoInfo( const char* file,int line, const string & msg)
{
    cout << "[FILE] "<< file << " [LINE NUM] " << line << " [INFO] " << msg  << endl;
}

llvm::AllocaInst *CreateEntryBlockAlloca(llvm::Function *TheFunction, llvm::StringRef VarName, llvm::Type* type)
{
  llvm::IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
  return TmpB.CreateAlloca(type, nullptr, VarName);
}

llvm::Type* toLLVMPtrType(string type)
{
    if (type == "integer"){
        return llvm::Type::getInt32PtrTy(*TheContext);
    } else if (type == "real") {
        return llvm::Type::getDoublePtrTy(*TheContext);
    } else if (type == "char") {
        return llvm::Type::getInt8PtrTy(*TheContext);
    } else if (type == "boolean") {
        return llvm::Type::getInt1PtrTy(*TheContext);
    } else if (type == "string") {
        return llvm::Type::getInt8PtrTy(*TheContext);
    }
    throw logic_error("Undefined type!");
}

llvm::Type* AstType::toLLVMType(){
    if (this->type == "array"){
        if (this->arrayType->range->type == "constRange"){
            return llvm::ArrayType::get(this->arrayType->type->toLLVMType(),
             this->arrayType->range->constRangeType->size());
        } else {
            return llvm::ArrayType::get(this->arrayType->type->toLLVMType(), 
            this->arrayType->range->enumRangeType->size());
        }
    } else if (this->type == "constRange") {
        return TheBuilder.getInt32Ty();
    } else if (this->type == "enumRange") {
        return TheBuilder.getInt32Ty();
    } else if (this->type == "builtin") {
        if (buildInType == "integer") {
            return TheBuilder.getInt32Ty();
        } else if (buildInType == "real") {
            return TheBuilder.getDoubleTy();
        } else if (buildInType == "char") {
            return TheBuilder.getInt8Ty();
        } else if (buildInType == "boolean") {
            return TheBuilder.getInt1Ty();
        } else if (buildInType == "string") { 
            return TheBuilder.getInt8PtrTy();
        }
    } else {
        return TheBuilder.getVoidTy();
    }
    return nullptr;
}

llvm::Constant* AstType::initValue(ConstValue *v)
{
    vector<llvm::Constant*> element;
    llvm::ArrayType* arrayType;;
    size_t size = 0;
    if (v != nullptr){
        if (this->type == "array") {
            if (this->arrayType->range->type == "constRange") {
                size = this->arrayType->range->constRangeType->size();
            } else {
                size = this->arrayType->range->enumRangeType->size();
            }
            for (int i = 0; i < size; i++) {
                element.push_back(this->arrayType->type->initValue(v));
            }
            arrayType = (llvm::ArrayType*)this->toLLVMType();
            return llvm::ConstantArray::get(arrayType, element);
        } else if (this->type == "constRange" || this->type == "enumRange") {
                return TheBuilder.getInt32(v->getValue().i);
        } else if (this->type == "builtin") {
            if (buildInType == "integer"){
                return TheBuilder.getInt32(v->getValue().i);
            } else if (buildInType == "real") {
                return llvm::ConstantFP::get(TheBuilder.getDoubleTy(), v->getValue().r);
            } else if (buildInType == "char") {
                return TheBuilder.getInt8(v->getValue().c);
            } else if (buildInType == "boolean") {
                return TheBuilder.getInt1(v->getValue().b);
            } else if (buildInType == "string") {
                return TheBuilder.CreateGlobalStringPtr(llvm::StringRef((const char*)(v->getValue().s)));
            } else {
                return nullptr;
            }
        } else {
            return nullptr;
        }
    } else {
        if (this->type == "array") {
            if (this->arrayType->range->type == "constRange") {
                size = this->arrayType->range->constRangeType->size();
            } else {
                size = this->arrayType->range->enumRangeType->size();
            }
            for (int i = 0; i < size; i++) {
                element.push_back(this->arrayType->type->initValue());
            }
            arrayType = (llvm::ArrayType*)this->toLLVMType();
            return llvm::ConstantArray::get(arrayType, element);
        } else if (this->type == "constRange" || this->type == "enumRange") {
            return TheBuilder.getInt32(0);
        } else if (this->type == "builtin") {
            if (buildInType == "integer") {
                return TheBuilder.getInt32(0);
            } else if (buildInType == "real") {
                return llvm::ConstantFP::get(TheBuilder.getDoubleTy(), 0.0);
            } else if (buildInType == "char") {
                return TheBuilder.getInt8(0);
            } else if (buildInType == "boolean") {
                return TheBuilder.getInt1(0);
            } else if (buildInType == "string") {
                return TheBuilder.getInt8(0);
            }
        } else {
            return nullptr;
        }
    }
    return nullptr;
}

llvm::Value *BinaryOp(llvm::Value *L, string op, llvm::Value *R)
{
    // ori: multi tmps 
    bool flag = L->getType()->isDoubleTy() || R->getType()->isDoubleTy();
    if (op == "+") {
        return flag ? TheBuilder.CreateFAdd(L, R) : TheBuilder.CreateAdd(L, R);
    } else if (op == "-") {
        return flag ? TheBuilder.CreateFSub(L, R) : TheBuilder.CreateSub(L, R);
    } else if (op == "*") {
        return flag ? TheBuilder.CreateFMul(L, R) : TheBuilder.CreateMul(L, R);
    } else if (op == "/") {
        if (!flag) {
            return TheBuilder.CreateSDiv(L, R); 
        } else {
            if (L->getType()->isIntegerTy()) {
                if (llvm::ConstantInt* CI = llvm::dyn_cast<llvm::ConstantInt>(L)) {
                    int constIntValue = CI->getSExtValue(); 
                    L = llvm::ConstantFP::get(TheBuilder.getDoubleTy(), (double)constIntValue); 
                    return TheBuilder.CreateFDiv(L, R);  
                }
            } else if (R->getType()->isIntegerTy()) {
                if (llvm::ConstantInt* CI = llvm::dyn_cast<llvm::ConstantInt>(R)) {
                    int constIntValue = CI->getSExtValue(); 
                    R = llvm::ConstantFP::get(TheBuilder.getDoubleTy(), (double)constIntValue); 
                    return TheBuilder.CreateFDiv(L, R); 
                }
            } 
        }
        return TheBuilder.CreateFDiv(L, R); 
    } else if (op == ">=") {
        return TheBuilder.CreateICmpSGE(L, R);
    } else if (op == ">") {
        return TheBuilder.CreateICmpSGT(L, R);
    } else if (op == "<") {
        return TheBuilder.CreateICmpSLT(L, R);
    } else if (op == "<=") {
        return TheBuilder.CreateICmpSLE(L, R);
    } else if (op == "=") {
        return TheBuilder.CreateICmpEQ(L, R);
    } else if (op == "<>") {
        return TheBuilder.CreateICmpNE(L, R);
    } else if (op == "or") {
        return TheBuilder.CreateOr(L, R);
    } else if (op == "mod") {
        return TheBuilder.CreateSRem(L, R);
    } else if (op == "and") {
        return TheBuilder.CreateAnd(L, R);
    } else if (op == "xor") {
        return TheBuilder.CreateXor(L, R);
    } else {
        return nullptr;
    }
}

llvm::Value *Identifier::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Identifier");
//    return TheBuilder.CreateLoad(generator.getValueByName(*(this->name)), *(this->name));
    return new llvm::LoadInst(generator.getValueByName(*(this->name)), "tmp", false, TheBuilder.GetInsertBlock());
}

llvm::Value *Integer::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Integer");
    return TheBuilder.getInt32(this->value);
}

llvm::Value *Char::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Char");
    return TheBuilder.getInt8(this->value);
}

llvm::Value *String::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"String");
    // Found on Stackoverflow
    return TheBuilder.CreateGlobalStringPtr(llvm::StringRef(this->value->c_str()));
}

llvm::Value *Real::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Real");
//    return llvm::ConstantFP::get(*TheContext, llvm::APFloat(this->value));
    return llvm::ConstantFP::get(TheBuilder.getDoubleTy(), this->value);
}

llvm::Value *Boolean::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Boolean");
    return TheBuilder.getInt1(this->value);
}

llvm::Value *ConstDeclaration::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Const Declaration");
    string name = this->name->getName();
    this->type = new AstType(this->value->valueType);
    if (this->isGlobal) {
         return new llvm::GlobalVariable(*generator.TheModule, this->type->toLLVMType(), true, llvm::GlobalValue::ExternalLinkage, this->type->initValue(this->value), name);
    } else {
        auto alloc = CreateEntryBlockAlloca(generator.funcStack.back(), name, this->type->toLLVMType());
        return TheBuilder.CreateStore(this->value->codeGen(generator), alloc);
    }
}

llvm::Value *TypeDeclaration::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Type Declaration");
    return nullptr;
}

llvm::Value *AstType::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Type");
    if (this->type == "array") {
        this->arrayType->codeGen(generator);
    } else if (this->type == "constRange") {
        this->constRangeType->codeGen(generator);
    } else if (this->type == "enumRange") {
        this->enumRangeType->codeGen(generator);
    } else if (this->type == "record") {
        this->recordType->codeGen(generator);
    } else if (this->type == "enum") {
        this->enumType->codeGen(generator);
    } else if (this->type == "userDefined") {
        this->userDefineType->codeGen(generator);
    }
    return (llvm::Value*)this->toLLVMType();
}

llvm::Value *EnumType::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Enum Type");
    // TODO
    return nullptr;
}

llvm::Value *AstArrayType::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Array Type");
    return this->range->codeGen(generator);
}

llvm::Value *RecordType::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Record Type");
    return nullptr;
}

llvm::Value *ConstRangeType::mapIndex(llvm::Value *indexValue, Generator & generator) {
    return BinaryOp(indexValue, "-", this->lowBound->codeGen(generator));
}

llvm::Value *ConstRangeType::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Const Range Type");
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
    echoInfo(__FILE__,__LINE__,"Enum Range Type");
    this->upValue = this->upBound->codeGen(generator);
    this->lowValue = this->lowBound->codeGen(generator);
    this->upValueAddr = generator.getValueByName(this->upBound->getName());
    this->lowValueAddr = generator.getValueByName(this->lowBound->getName());
    this->size();
    return nullptr;
}

llvm::Value *FieldDeclaration::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Field Declaration");
    return nullptr;
}

llvm::Value *VarDeclaration::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Var Declaration");
    llvm::Value* alloc = nullptr;
    llvm::Type* varType;
    for (auto & id : *(this->nameList)) {
        if (this->type->type == "array") {
            generator.arrayMap[id->getName()] = this->type->arrayType;
        }
        varType = (llvm::Type*)(this->type->codeGen(generator));
        if (this->isGlobal) {
            alloc = new llvm::GlobalVariable(*generator.TheModule, varType, false, llvm::GlobalValue::ExternalLinkage, this->type->initValue(), id->getName());
        } else {
            alloc = CreateEntryBlockAlloca(generator.funcStack.back(), id->getName(), varType);
        }
    }
    return alloc;
}

llvm::Value *FuncDeclaration::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Function Declaration");
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
//                alloc = generator.getValueByName(arg->getName());
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
    if (this->returnType->type != "void") {
        res = CreateEntryBlockAlloca(function, this->name->getName(), this->returnType->toLLVMType());
    }
    
    //Sub routine
    this->subRoutine->codeGen(generator);
    
    //Return value
    if (this->returnType->type != "void") {
        auto returnInst = this->name->codeGen(generator);
        TheBuilder.CreateRet(returnInst);
    } else {
        TheBuilder.CreateRetVoid();
    }
    
    //Pop back
    generator.popFunction();
    TheBuilder.SetInsertPoint(&(generator.funcStack.back())->getBasicBlockList().back());
    return function;
}

llvm::Value *Parameter::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Parameter");
    //Not need
    return nullptr;
}

llvm::Value *Routine::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Routine");
    llvm::Value* res = nullptr;
    
    //Const declareation part
    for (auto & constDecl : *(this->constDeclList)){
        res = constDecl->codeGen(generator);
    }
    //Type declareation part
    for (auto & typeDecl : *(this->typeDeclList)){
        res = typeDecl->codeGen(generator);
    }
    //Variable declareation part
    for (auto & varDecl : *(this->varDeclList)){
        res = varDecl->codeGen(generator);
    }

    //Routine declareation part
    for (auto & routineDecl : *(this->routineList)){
        res = routineDecl->codeGen(generator);
    }
    
    //Routine body
    res = routineBody->codeGen(generator);
    return res;
}

llvm::Value *Program::codeGen(Generator & generator) {

    echoInfo(__FILE__,__LINE__,"Program");
    //Main function prototype
    vector<llvm::Type*> argTypes;
    llvm::FunctionType * funcType = llvm::FunctionType::get(TheBuilder.getVoidTy(), makeArrayRef(argTypes), false);
    generator.mainFunction = llvm::Function::Create(funcType, 
        llvm::GlobalValue::ExternalLinkage, "main", generator.TheModule.get());
    llvm::BasicBlock * mainEntry = llvm::BasicBlock::Create(*TheContext, "entrypoint", generator.mainFunction, 0);
    
    generator.pushFunction(generator.mainFunction);
    TheBuilder.SetInsertPoint(mainEntry);

    //Create System functions
    generator.printf = generator.createPrintf();
    generator.scanf = generator.createScanf();
    generator.abs = generator.createAbs();
    generator.chr = generator.createChr();
    generator.odd = generator.createOdd();
    generator.ord = generator.createOrd();
    generator.pred = generator.createPred();
    generator.sqr = generator.createSqr();
    generator.sqrt = generator.createSqrt();
    generator.succ = generator.createSucc();
    generator.sqrReal = generator.createSqrReal(); 

    //Code generate
    this->routine->setGlobal();
    this->routine->codeGen(generator);
    TheBuilder.CreateRetVoid();
    generator.popFunction();
    
    return nullptr;
}

llvm::Value *AssignStatement::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Assign Statement");
    llvm::Value *res = nullptr;
    this->generatePrologue(generator);
    switch (this->type)
    {
        case ID_ASSIGN: {
            llvm::Value *rhsValue = this->rhs->codeGen(generator); 
            llvm::Value *lhsValue = generator.getValueByName(this->lhs->getName()); 
            res = TheBuilder.CreateStore(rhsValue, lhsValue); 
            break;
        }
        case ARRAY_ASSIGN: 
            res = TheBuilder.CreateStore(this->rhs->codeGen(generator), (new ArrayReference(this->lhs, this->sub))->getReference(generator)); 
            break;
        case RECORD_ASSIGN: 
            res = nullptr; 
            break; 
    }
    this->generateEpilogue(generator);
    return res;
}

llvm::Value *BinaryExpression::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Binary Expression");
    llvm::Value* L = this->lhs->codeGen(generator);
    llvm::Value* R = this->rhs->codeGen(generator);
    if (!L || !R) return nullptr;

    return BinaryOp(L, this->op, R);
}

llvm::Value *ArrayReference::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Array Reference");
    return TheBuilder.CreateLoad(this->getReference(generator), "arrRef");
}

llvm::Value *ArrayReference::getReference(Generator & generator) {
    string name = this->array->getName();
    llvm::Value* arrayValue = generator.getValueByName(name), *indexValue;
    if (generator.arrayMap[name]->range->type == "cosntRange")
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
    echoInfo(__FILE__,__LINE__,"Record Reference");
    return nullptr;
}

llvm::Value *FunctionCall::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Function Call");
    this->generatePrologue(generator);
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
            llvm::Value * addr = generator.getValueByName(dynamic_cast<Identifier*>(arg)->getName());
            args.push_back(addr);
        }
        else
        {
//            cout << "Pass a value" << endl;
            args.push_back(arg->codeGen(generator));
        }
        argIt++;
    }
    llvm::Value *res = TheBuilder.CreateCall(function, args);   // ori: "calltmp"
    this->generateEpilogue(generator);
    return res;
}

llvm::Value *ProcedureCall::codeGen(Generator & generator) {
    echoInfo(__FILE__, __LINE__, "Procedure Call");
    this->generatePrologue(generator);
    llvm::Function *function = generator.TheModule->getFunction(this->funcName->getName());
    if (function == nullptr)
    {
        throw domain_error("[ERROR] Function not defined: " + this->funcName->getName());
    }
    vector<llvm::Value*> args;
    llvm::Function::arg_iterator argIt =  function->arg_begin();
    for (auto & arg : *(this->args))
    {
        if (argIt->hasNonNullAttr())
        {
//            cout << "Pass a pointer" << endl;
            llvm::Value * addr = generator.getValueByName(dynamic_cast<Identifier*>(arg)->getName());
            args.push_back(addr);
        }
        else
        {
//            cout << "Pass a value" << endl;
            args.push_back(arg->codeGen(generator));
        }
        argIt++;
    }
    // procedure must return a value if we use the last sentence, but procedure must not return anything in SPL. 
    llvm::Value* res = TheBuilder.CreateCall(function, args);
    this->generateEpilogue(generator); 
    return res;
}

llvm::Value *SysFunctionCall::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"System Function Call");

    llvm::Value *res = nullptr;
    this->generatePrologue(generator);
    if (this->funcName == "abs") {
        res = this->SysFuncAbs(generator);
    } else if (this->funcName == "chr") {
        res = this->SysFuncChr(generator);
    } else if (this->funcName == "odd") {
        res = this->SysFuncOdd(generator);
    } else if (this->funcName == "ord") {
        res = this->SysFuncOrd(generator);
    } else if (this->funcName == "pred") {
        res = this->SysFuncPred(generator);
    } else if (this->funcName == "sqr") {
        res = this->SysFuncSqr(generator);
    } else if (this->funcName == "sqrt") {
        res = this->SysFuncSqrt(generator);
    } else if (this->funcName == "succ") {
        res = this->SysFuncSucc(generator);
    } else {
        throw domain_error("[ERROR] Unknown System Function");
    }
    this->generateEpilogue(generator);
    return res;
}

llvm::Value *SysFunctionCall::SysFuncAbs(Generator & generator) {
    vector<llvm::Value*> params;
    auto arg = this->args->front();
    llvm::Value *argValue;
    argValue = arg->codeGen(generator);
    params.push_back(argValue);
    return TheBuilder.CreateCall(generator.abs, params, "abs");
}

llvm::Value *SysFunctionCall::SysFuncChr(Generator & generator) {
    vector<llvm::Value*> params;
    auto arg = this->args->front();
    llvm::Value *argValue;
    argValue = arg->codeGen(generator);
    params.push_back(argValue);
    return TheBuilder.CreateCall(generator.chr, params, "chr");
}

llvm::Value *SysFunctionCall::SysFuncOdd(Generator & generator) {
    vector<llvm::Value*> params;
    auto arg = this->args->front();
    llvm::Value *argValue;
    //Just common variable
    argValue = arg->codeGen(generator);
    params.push_back(argValue);
    return TheBuilder.CreateCall(generator.odd, params, "odd");
}

llvm::Value *SysFunctionCall::SysFuncOrd(Generator & generator) {
    vector<llvm::Value*> params;
    auto arg = this->args->front();
    llvm::Value *argValue;
    //Just common variable
    argValue = arg->codeGen(generator);
    params.push_back(argValue);
    return TheBuilder.CreateCall(generator.ord, params, "ord");
}

llvm::Value *SysFunctionCall::SysFuncPred(Generator & generator) {
    vector<llvm::Value*> params;
    auto arg = this->args->front();
    llvm::Value *argValue;
    argValue = arg->codeGen(generator);
    params.push_back(argValue);
    return TheBuilder.CreateCall(generator.pred, params, "pred");
}

llvm::Value *SysFunctionCall::SysFuncSqr(Generator & generator) {
    vector<llvm::Value*> params;
    auto arg = this->args->front();
    llvm::Value *argValue;
    argValue = arg->codeGen(generator);
    params.push_back(argValue);
    if (argValue->getType() == TheBuilder.getDoubleTy()){
        return TheBuilder.CreateCall(generator.sqrReal, params, "sqrr");
    } else {
        return TheBuilder.CreateCall(generator.sqr, params, "sqr");
    }
    
}


llvm::Value *SysFunctionCall::SysFuncSqrt(Generator & generator) {
    vector<llvm::Value*> params;
    auto arg = this->args->front();
    llvm::Value  *argValue;
    //Just common variable
    argValue = arg->codeGen(generator);
    params.push_back(argValue);
    return TheBuilder.CreateCall(generator.sqrt, params, "sqrt");
}

llvm::Value *SysFunctionCall::SysFuncSucc(Generator & generator) {
    vector<llvm::Value*> params;
    auto arg = this->args->front();
    llvm::Value *argValue;
    argValue = arg->codeGen(generator);
    params.push_back(argValue);
    return TheBuilder.CreateCall(generator.succ, params, "succ");
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
    params.insert(params.begin(), varRef);
    return TheBuilder.CreateCall(generator.printf, llvm::makeArrayRef(params), "printf");
}

llvm::Value *SysProcedureCall::SysProcRead(Generator & generator)
{
    string formatStr = "";
    vector<llvm::Value*> params;
    auto arg = this->args->front();
    llvm::Value *argAddr, *argValue;
    argAddr = generator.getValueByName(dynamic_cast<Identifier*>(arg)->getName());
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
    echoInfo(__FILE__,__LINE__,"System Procedure Call");
    llvm::Value *res = nullptr;
    this->generatePrologue(generator);
    switch (this->procedure) {
        case SPL_READ: res = this->SysProcRead(generator); break;
        case SPL_WRITE: res = this->SysProcWrite(generator, false); break;
        case SPL_WRITELN: res = this->SysProcWrite(generator, true); break;
        case SPL_ERROR_PROCEDURE: throw domain_error("[ERROR] Unknown System Procedure");
    }
    this->generateEpilogue(generator);
    return res;
}

llvm::Value *IfStatement::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"If Statement");
    this->generatePrologue(generator);
    
    llvm::Value *condValue = this->condition->codeGen(generator), *thenValue = nullptr, *elseValue = nullptr;
    condValue = TheBuilder.CreateICmpNE(condValue, llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 0, true), "ifCond");

    llvm::Function *TheFunction = generator.funcStack.back();
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
    TheBuilder.SetInsertPoint(elseBB);
    if (this->elseStatement != nullptr)
    {
        elseValue = this->elseStatement->codeGen(generator);
    }
    TheBuilder.CreateBr(mergeBB);
    elseBB = TheBuilder.GetInsertBlock();

    //Merge
    TheBuilder.SetInsertPoint(mergeBB);
    
    this->generateEpilogue(generator);
    return branch;
}

llvm::Value *RepeatStatement::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Repeate Statement");
    this->generatePrologue(generator);
    
    llvm::Function *TheFunction = generator.funcStack.back();
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
    this->generateEpilogue(generator);
    return branch;
}

llvm::Value *WhileStatement::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"While Statement");
    this->generatePrologue(generator);
    auto *TheFunction = generator.funcStack.back();
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
    this->generateEpilogue(generator);
    return branch;
}

llvm::Value *ForStatement::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"For Statement");
    this->generatePrologue(generator);
    //Init
    llvm::Function *TheFunction = generator.funcStack.back();
    llvm::Value* startValue = this->value->codeGen(generator);
    llvm::Value* endValue = this->step->codeGen(generator);
    llvm::Value *condValue = nullptr, *curValue = nullptr, *varValue = generator.getValueByName(this->var->getName());
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
    this->generateEpilogue(generator);
    return branch;
}

llvm::Value *CaseStatement::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Case Statement");
    this->generatePrologue(generator);
    
    llvm::Value *cmpValue = this->value->codeGen(generator), *condValue = nullptr;
    llvm::Function *TheFunction = generator.funcStack.back();
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
    this->generateEpilogue(generator);
    return nullptr;
}

llvm::Value *CaseExpression::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Case Expression");
    return this->stmt->codeGen(generator);
}

void Statement::generatePrologue(Generator & generator) {
    llvm::Function *TheFunction = generator.funcStack.back();
    // cout << "generatePrologue: curlabel = " << this->label << endl;
    if (this->label >= 0)
    {
        if (generator.labelBlocks[this->label] == nullptr) {
            generator.labelBlocks[this->label] = llvm::BasicBlock::Create(*TheContext, "startLabel" + to_string(this->label), TheFunction);
        }
        if (this->nextBlock == nullptr) {
            this->nextBlock = llvm::BasicBlock::Create(*TheContext, "endLabel" + to_string(this->label), TheFunction);
        }
        TheBuilder.CreateBr(generator.labelBlocks[this->label]);
        TheBuilder.SetInsertPoint(generator.labelBlocks[this->label]);
    }
}

void Statement::generateEpilogue(Generator & generator)
{
    // cout << "generateEpilogue: curlabel = " << this->label << endl;
    // return;
    if (this->label >= 0 && this->nextBlock != nullptr)
    {
        TheBuilder.SetInsertPoint(generator.labelBlocks[this->label]);
        TheBuilder.CreateBr(this->nextBlock);
        TheBuilder.SetInsertPoint(this->nextBlock);
    }
}

llvm::Value *GotoStatement::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"Goto Statement");
    this->generatePrologue(generator);
    llvm::Value *res = nullptr;
    if (generator.labelBlocks[this->targetLabel] == nullptr) {
        generator.labelBlocks[this->targetLabel] = 
        llvm::BasicBlock::Create(*TheContext, 
        "startLabel" + to_string(this->targetLabel), 
        generator.funcStack.back());
    }
    res = TheBuilder.CreateBr(generator.labelBlocks[this->targetLabel]);
    this->generateEpilogue(generator);
    return res;
}

llvm::Value *CompoundStatement::codeGen(Generator & generator) {
    echoInfo(__FILE__,__LINE__,"CompoundStatement");
    this->generatePrologue(generator);
    llvm::Value *lastValue = nullptr;
    for (auto & stmt : *(this->stmtList)) {
        lastValue = stmt->codeGen(generator);
    }
    this->generateEpilogue(generator);
    return lastValue;
}

string jsonfy(string name) {
    return "{\"name\":\"" + name + "\"}";
}

string jsonfy(string name, vector<string> children) {
    string result = "{\"name\":\"" + name + "\", \"children\":[";
    int i;
    for (i = 0; i < children.size() - 1;i++){
        result += children[i] + ",";
    }
    result += children[i] + "]}";
    return result;
}

string jsonfy(string name, string value) {
    return jsonfy(name, vector<string>{value});
}

string jsonfy(string name, string value, vector<string> children) {
    string result = "{\"name\":\"" + name + "\",\"value\":\"" + value + "\",\"children\":[";
    int i;
    for (i = 0; i < children.size() - 1;i++){
        result += children[i] + ",";
    }
    result += children[i] + "]}";
    return result;
}

string Program::jsonGen() {
    return jsonfy("program", *programID, vector<string>{routine->jsonGen()});
}

string Identifier::jsonGen() {
    return jsonfy("Identifier", jsonfy(*name));
}

string Integer::jsonGen() {
    return jsonfy("Integer", jsonfy(to_string(value)));
}

string Real::jsonGen() {
    return jsonfy("Real", jsonfy(to_string(value)));
}

string Char::jsonGen() {
    return jsonfy("Char", jsonfy(string(1, value)));
}

string String::jsonGen() {
    return jsonfy("String", jsonfy(*value));
}
string Boolean::jsonGen() {
    return jsonfy("Boolean", jsonfy((value ? "true" : "false")));
}

string ConstDeclaration::jsonGen() {
    vector<string> children;
    children.push_back(name->jsonGen());
    children.push_back(value->jsonGen());
    return jsonfy("ConstDeclaration", children);
}

string EnumType::jsonGen() {
    vector<string> children;
    for(auto &name : *enumList) {
        children.push_back(name->jsonGen());
    }
    return jsonfy("EnumType", children);
}

string AstArrayType::jsonGen() {
    vector<string> children;
    children.push_back(jsonfy("range", range->jsonGen()));
    children.push_back(jsonfy("type", type->jsonGen()));
    return jsonfy("AstArrayType", children);
}

string ConstRangeType::jsonGen() {
    vector<string> children;
    children.push_back(jsonfy("lowBound", lowBound->jsonGen()));
    children.push_back(jsonfy("upBound", upBound->jsonGen()));
    return jsonfy("ConstRangeType", children);
}

string EnumRangeType::jsonGen() {
    vector<string> children;
    children.push_back(jsonfy("lowBound", lowBound->jsonGen()));
    children.push_back(jsonfy("upBound", upBound->jsonGen()));
    return jsonfy("EnumRangeType", children);
}

string FieldDeclaration::jsonGen() {
    vector<string> children;
    vector<string> nameListJson;
    for(auto &name : *nameList) {
        nameListJson.push_back(name->jsonGen());
    }
    children.push_back(jsonfy("nameList", nameListJson));
    children.push_back(jsonfy("type", type->jsonGen()));
    return jsonfy("FieldDeclaration", children);
}

string RecordType::jsonGen() {
    vector<string> children;
    for(auto &field : *fieldList) {
        children.push_back(field->jsonGen());
    }

    return jsonfy("RecordType", children);
}

string AstType::jsonGen() {
    if (this->type == "array") {
        return arrayType->jsonGen();
    } else if (this->type == "record") {
        return recordType->jsonGen();
    } else if (this->type == "enum") {
        return enumType->jsonGen();
    } else if (this->type == "constRange") {
        return constRangeType->jsonGen();
    } else if (this->type == "enumRange") {
        return enumRangeType->jsonGen();
    } else if (this->type == "builtin") {
        if (buildInType == "integer"){
            return jsonfy("SYS_TYPE", jsonfy("Integer"));
        } else if (buildInType == "real") {
            return jsonfy("SYS_TYPE", jsonfy("Real"));
        } else if (buildInType == "char") {
            return jsonfy("SYS_TYPE", jsonfy("Char"));
        } else if (buildInType == "boolean") {
            return jsonfy("SYS_TYPE", jsonfy("Boolean"));
        } else if (buildInType == "string") {
            return jsonfy("SYS_TYPE", jsonfy("String"));
        }
    } else if (this->type == "userDefined") {
        return jsonfy("UserDefineType", jsonfy(userDefineType->getName()));
    } else {
        return jsonfy("Unknown Type");
    }
    return nullptr;
}

string TypeDeclaration::jsonGen() {
    vector<string> children;
    children.push_back(name->jsonGen());
    children.push_back(type->jsonGen());
    return jsonfy("TypeDeclaration", children);
}

string VarDeclaration::jsonGen() {
    vector<string> children;
    vector<string> nameListJson;
    for(auto &name : *nameList) {
        nameListJson.push_back(name->jsonGen());
    }
    children.push_back(jsonfy("Type", type->jsonGen()));
    children.push_back(jsonfy("NameList", nameListJson));
    return jsonfy("VarDeclaration", children);
}

string FuncDeclaration::jsonGen() {
    vector<string> children;
    children.push_back(name->jsonGen());
    vector<string> paraListJson;
    for(auto &para : *paraList)
        paraListJson.push_back(para->jsonGen());
    children.push_back(jsonfy("ParaList", paraListJson));
    children.push_back(returnType->jsonGen());
    children.push_back(subRoutine->jsonGen());

    return jsonfy("FuncDeclaration", children);
}

string Parameter::jsonGen() {
    vector<string> children, jsonVec;
    for(auto &i : *nameList) {
        jsonVec.push_back(i->jsonGen());
    }
    children.push_back(jsonfy("Type", type->jsonGen()));
    children.push_back(jsonfy("NameList", jsonVec));
    children.push_back(jsonfy("isVar", jsonfy((isVar ? "true" : "false" ))));
    return jsonfy("Parameter", children);
}

string Routine::jsonGen() {
    vector<string> children, jsonVec;
    bool realInsert = false; // empty node will not be added into parse tree
    for (auto i : *constDeclList){
        realInsert = true;
        jsonVec.push_back(i->jsonGen());
    }
    if (realInsert) {
        realInsert = false;
        children.push_back(jsonfy("ConstDeclList", jsonVec));
        jsonVec.clear();
    }
    
    for (auto i : *varDeclList){
        realInsert = true;
        jsonVec.push_back(i->jsonGen());
    }
    if (realInsert) {
        realInsert = false;
        children.push_back(jsonfy("VarDeclList", jsonVec));
        jsonVec.clear();
    }

    for (auto i : *typeDeclList){
        realInsert = true;
        jsonVec.push_back(i->jsonGen());
    }
    if (realInsert) {
        realInsert = false;
        children.push_back(jsonfy("TypeDeclList", jsonVec));
        jsonVec.clear();
    }
    
    for (auto i : *routineList){
        realInsert = true;
        jsonVec.push_back(i->jsonGen());
    }
    if (realInsert) {
        realInsert = false;
        children.push_back(jsonfy("RoutineDeclList", jsonVec));
        jsonVec.clear();
    }
    children.push_back(routineBody->jsonGen());
    return jsonfy("Routine", children);
}

string AssignStatement::jsonGen() {
    vector<string> children;
    switch (type)
    {
    case ID_ASSIGN:
        children.push_back(lhs->jsonGen());
        children.push_back(rhs->jsonGen());
        break;
    case ARRAY_ASSIGN:
        children.push_back(lhs->jsonGen());
        children.push_back(sub->jsonGen());
        children.push_back(rhs->jsonGen());
        break;
    case RECORD_ASSIGN:
        children.push_back(lhs->jsonGen());
        children.push_back(field->jsonGen());
        children.push_back(rhs->jsonGen());
        break;
    default:
        break;
    }    

    return jsonfy("AssignStatement", children);
}

string BinaryExpression::jsonGen() {
    vector<string> children;
    children.push_back(lhs->jsonGen());
    children.push_back(jsonfy(this->op));
    children.push_back(rhs->jsonGen());

    return jsonfy("BinaryExpression", children);
}

string ArrayReference::jsonGen() {
    vector<string> children;
    children.push_back(array->jsonGen());
    children.push_back(index->jsonGen());

    return jsonfy("ArrayReference", children);
}

string RecordReference::jsonGen() {
    vector<string> children;
    children.push_back(record->jsonGen());
    children.push_back(field->jsonGen());

    return jsonfy("RecordReference", children);
}

string FunctionCall::jsonGen() {
    vector<string> children;
    children.push_back(function->jsonGen());
    vector<string> argsJson;
    for(auto &arg : *args) {
        argsJson.push_back(arg->jsonGen());
    }
    children.push_back(jsonfy("ArgList", argsJson));
    return jsonfy("FunctionCall", children);
}

string ProcedureCall::jsonGen() {
    vector<string> children;
    children.push_back(funcName->jsonGen());
    vector<string> argsJson;
    for(auto &arg : *args) {
        argsJson.push_back(arg->jsonGen());
    }
    children.push_back(jsonfy("ArgList", argsJson));
    return jsonfy("ProcedureCall", children);
}

string SysFunctionCall::jsonGen() {
    // cout << (this->funcName) << endl;
    vector<string> children;
    children.push_back(jsonfy("SysFunction", jsonfy(this->funcName)));
    vector<string> argsJson;
    for(auto &arg : *args) {
        argsJson.push_back(arg->jsonGen());
    }
    children.push_back(jsonfy("ArgList", argsJson));
    return jsonfy("SysFunctionCall", children);
}

string SysProcedureCall::jsonGen() {
    vector<string> children;
    children.push_back(jsonfy("SysProcedure", jsonfy(*name)));
    vector<string> argsJson;
    for(auto &arg : *args) {
        argsJson.push_back(arg->jsonGen());
    }
    children.push_back(jsonfy("ArgList", argsJson));
    return jsonfy("SysProcedureCall", children);
}

string IfStatement::jsonGen() {
    vector<string> children;
    children.push_back(condition->jsonGen());
    children.push_back(thenStatement->jsonGen());
    if(elseStatement)
        children.push_back(elseStatement->jsonGen());

    return jsonfy("IfStatement", children);
}

string RepeatStatement::jsonGen() {
    vector<string> children;
    children.push_back(condition->jsonGen());
    vector<string> repeatStmtJson;
    for(auto &stmt : *repeatStatement)
        repeatStmtJson.push_back(stmt->jsonGen());
    children.push_back(jsonfy("RepeatStatement", repeatStmtJson));

    return jsonfy("RepeatStatement", children);
}

string WhileStatement::jsonGen() {
    vector<string> children;
    children.push_back(condition->jsonGen());
    children.push_back(stmt->jsonGen());

    return jsonfy("WhileStatement", children);
}

string ForStatement::jsonGen() {
    vector<string> children;
    children.push_back(var->jsonGen());
    children.push_back(value->jsonGen());
    children.push_back(jsonfy("isAdd", jsonfy((isAdd ? "true" : "false"))));
    children.push_back(step->jsonGen());
    children.push_back(stmt->jsonGen());

    return jsonfy("ForStatement", children);
}  

string CaseStatement::jsonGen() {
    vector<string> children;
    children.push_back(value->jsonGen());
    vector<string> caseExprJsonList;
    for(auto &caseExpr : *caseExprList) {
        caseExprJsonList.push_back(caseExpr->jsonGen());
    }
    children.push_back(jsonfy("CaseExprList", caseExprJsonList));

    return jsonfy("CaseStatement", children);
}    

string CaseExpression::jsonGen() {
    vector<string> children;
    children.push_back(value->jsonGen());
    children.push_back(stmt->jsonGen());

    return jsonfy("CaseExpression", children);
}

string GotoStatement::jsonGen() {
    return jsonfy("GotoStatement", jsonfy(to_string(targetLabel)));
}    

string CompoundStatement::jsonGen() {
    vector<string> stmtJsonList;
    for(auto &stmt : *stmtList) {
        stmtJsonList.push_back(stmt->jsonGen());
    }
    return jsonfy("CompoundStatement", stmtJsonList);
}
