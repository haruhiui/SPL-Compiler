#ifndef GENERATOR_HPP 
#define GENERATOR_HPP

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/IR/ValueSymbolTable.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/Optional.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h> 
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Target/TargetOptions.h>

static std::unique_ptr<llvm::LLVMContext> TheContext = std::make_unique<llvm::LLVMContext>();
static llvm::IRBuilder<> TheBuilder(*TheContext);

class Generator 
{
public:
    std::unique_ptr<llvm::Module> TheModule;
    unsigned int TheAddrSpace;
    llvm::Function *mainFunction, *printf, *scanf,
                   *abs, *chr, *odd, *ord, *pred, 
                   *sqr, *sqrt, *succ, *sqrReal;
    std::vector<llvm::Function*> funcStack;
    std::vector<UserDefinedType*> typeStack;
    llvm::BasicBlock *labelBlocks[3000];
    std::map<std::string, AstArrayType *> arrayMap;

    Generator() {
        TheModule = std::unique_ptr<llvm::Module>(new llvm::Module("main", *TheContext));
        TheAddrSpace = TheModule->getDataLayout().getAllocaAddrSpace();
    }
    
    void generate(Program& parseTreeRoot);
    
    llvm::Value* getValueByName(const std::string & name) {
        llvm::Value *value = nullptr; 
        // search in the most recently used ones
        for (auto it = funcStack.rbegin(); it != funcStack.rend(); it++) {
            value = (*it)->getValueSymbolTable()->lookup(name); 
            if (value != nullptr) {
                return value; 
            } 
        }
        // search in the global values
        value = TheModule->getGlobalVariable(name); 
        if (value == nullptr) {
            throw std::logic_error("[ERROR] Undeclared variable: " + name); 
        }

        return value; 
    }

    UserDefinedType* getUserDefinedTypeByName(const std::string & name){
        for (auto ud = typeStack.rbegin(); ud != typeStack.rend(); ud++){
            if ((*ud)->name == name) {
                return (*ud);
            }
        }
        return nullptr;
    }

    void pushFunction(llvm::Function* func) {
        funcStack.push_back(func);
    }
    
    void popFunction() {
        funcStack.pop_back();
    }
    
    // call printf : from c lib
    llvm::Function* createPrintf() {
        std::vector<llvm::Type*> arg_types;
        arg_types.push_back(TheBuilder.getInt8PtrTy());
        auto funcType = llvm::FunctionType::get(TheBuilder.getInt32Ty(), llvm::makeArrayRef(arg_types), true);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "printf", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);
        return func;
    }
    
    // call scanf : from c lib
    llvm::Function* createScanf() {
        // auto scanfType = llvm::FunctionType::get(TheBuilder.getInt32Ty(), true);
        // auto func = llvm::Function::Create(scanfType, llvm::Function::ExternalLinkage, "scanf", TheModule.get());
        auto returnType = TheBuilder.getInt32Ty();
        auto funcType = llvm::FunctionType::get(returnType, true);
        auto func = llvm::Function::Create(funcType,llvm::Function::ExternalLinkage, "scanf", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);
        return func;
    }

    llvm::Function* createAbs() {
        auto returnType = TheBuilder.getInt32Ty();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getInt32Ty());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "abs", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);
        return func;
    }
    // convert integer to char: truncate the integer to 8 bits
    llvm::Function* createChr() {
        auto returnType = TheBuilder.getInt8Ty();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getInt32Ty());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "chr", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);
        
        auto argsIter = func->arg_begin();
        llvm::Value *arg1 = argsIter++;
        arg1->setName("tmpa");
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(*TheContext, "entrypoint", func);
        llvm::IRBuilder<> builder(entry);
        llvm::Value *result = builder.CreateTrunc(arg1, builder.getInt8Ty(), "l8bits");

        builder.CreateRet(result);

        return func;
    }

    // judge if an INTEGER is odd or not.
    // It works uncertainly on real numbers
    llvm::Function* createOdd() {
        auto returnType = TheBuilder.getInt1Ty();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getInt32Ty());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "odd", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);

        auto argsIter = func->arg_begin();
        llvm::Value *arg1 = argsIter++;
        arg1->setName("tmpa");
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(*TheContext, "entrypoint", func);
        llvm::IRBuilder<> builder(entry);
        llvm::Value* result = builder.CreateAnd(arg1,builder.getInt32(1),"odd");
        result = builder.CreateICmpEQ(result, builder.getInt32(1), "isodd");
        builder.CreateRet(result);

        return func;
    }

    // convert char to integer : zero-extend it to 32bits
    llvm::Function* createOrd() {
        auto returnType = TheBuilder.getInt32Ty();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getInt8Ty());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "ord", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);

        auto argsIter = func->arg_begin();
        llvm::Value *arg1 = argsIter++;
        arg1->setName("tmpa");
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(*TheContext, "entrypoint", func);
        llvm::IRBuilder<> builder(entry);
        llvm::Value *result = builder.CreateZExt(arg1, builder.getInt32Ty(), "to32bits");
        builder.CreateRet(result);
        
        return func;
    }

    // get a-1 (int)
    llvm::Function* createPred() {
        auto returnType = TheBuilder.getInt32Ty();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getInt32Ty());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "pred", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);

        auto argsIter = func->arg_begin();
        llvm::Value *arg1 = argsIter++;
        arg1->setName("tmpa");
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(*TheContext, "entrypoint", func);
        llvm::IRBuilder<> builder(entry);
        llvm::Value* result = builder.CreateSub(arg1,builder.getInt32(1),"succ");
        builder.CreateRet(result);

        return func;
    }

    llvm::Function* createSqr() {
        auto returnType = TheBuilder.getInt32Ty();  
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getInt32Ty());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "sqr", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);

        auto argsIter = func->arg_begin();
        llvm::Value *arg1 = argsIter++;
        arg1->setName("tmpa");
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(*TheContext, "entrypoint", func);
        llvm::IRBuilder<> builder(entry);
        llvm::Value* result = builder.CreateMul(arg1,arg1,"multmpi");
        builder.CreateRet(result);
        return func;
    }

    llvm::Function* createSqrReal() {
        auto returnType = TheBuilder.getDoubleTy(); 
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getDoubleTy()); 
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "sqrr", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);

        auto argsIter = func->arg_begin();
        llvm::Value *arg1 = argsIter++;
        arg1->setName("tmpa");
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(*TheContext, "entrypoint", func);
        llvm::IRBuilder<> builder(entry);
        llvm::Value* result = builder.CreateFMul(arg1,arg1,"multmpr");
        builder.CreateRet(result);
        return func;
    }

    llvm::Function* createSqrt() {
        auto returnType = TheBuilder.getDoubleTy();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getDoubleTy());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "sqrt", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);
        auto argsIter = func->arg_begin();
        llvm::Value *result = argsIter++;
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(*TheContext, "startSqrt", func);
        llvm::IRBuilder<> builder(entry);


        auto resAddr = builder.CreateAlloca(builder.getDoubleTy());
        builder.CreateStore(result, resAddr);
        auto epsilon = llvm::ConstantFP::get(builder.getDoubleTy(), 0.0000000000001);
        auto c = builder.CreateLoad(resAddr);
        auto *condBB = llvm::BasicBlock::Create(*TheContext, "condSqrt", func);
        auto *loopBB = llvm::BasicBlock::Create(*TheContext, "loopSqrt", func);
        auto *afterBB = llvm::BasicBlock::Create(*TheContext, "afterLoopSqrt", func);
        
        //Cond
        builder.CreateBr(condBB);
        builder.SetInsertPoint(condBB);
        result = builder.CreateLoad(resAddr);
        auto delta = builder.CreateFMul(result, epsilon);

        auto div = builder.CreateFDiv(c, result);
        auto diff1 = builder.CreateFSub(result,div);
        auto diff2 = builder.CreateFSub(div, result);
        auto cmp1 = builder.CreateFCmpOGT(diff1, delta);
        auto cmp2 = builder.CreateFCmpOGT(diff2, delta);
        auto cmp = builder.CreateOr(cmp1, cmp2);
        builder.CreateCondBr(cmp, loopBB, afterBB);
        condBB = builder.GetInsertBlock();

        //Loop
        builder.SetInsertPoint(loopBB);
        auto add = builder.CreateFAdd(div, result);
        result = builder.CreateFDiv(add, llvm::ConstantFP::get(builder.getDoubleTy(), 2.0));
        builder.CreateStore(result, resAddr);
        builder.CreateBr(condBB);

        //After
        builder.SetInsertPoint(afterBB);
        result = builder.CreateLoad(resAddr);
        builder.CreateRet(result);
        return func;
    }

    // get a + 1 (int)
    llvm::Function* createSucc() {
        auto returnType = TheBuilder.getInt32Ty();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getInt32Ty());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "succ", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);

        auto argsIter = func->arg_begin();
        llvm::Value *arg1 = argsIter++;
        arg1->setName("tmpa");
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(*TheContext, "entrypoint", func);
        llvm::IRBuilder<> builder(entry);
        llvm::Value* result = builder.CreateAdd(arg1,builder.getInt32(1),"succ");
        builder.CreateRet(result);

        return func;
    }
};

#endif
