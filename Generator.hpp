#ifndef GENERATOR_H
#define GENERATOR_H

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
    llvm::Function *mainFunction;
    std::vector<llvm::Function*> funcStack;
    llvm::BasicBlock* labelBlock[10000];
    std::map<std::string, AstArrayType*> arrayMap;
    llvm::Function *printf, *scanf;
    llvm::Function *abs, *chr, *odd, *ord, *pred, 
                   *sqr, *sqrt, *succ, *sqrReal;
  

    Generator() {
        TheModule = std::unique_ptr<llvm::Module>(new llvm::Module("main", *TheContext));
        TheAddrSpace = TheModule->getDataLayout().getAllocaAddrSpace();
    }
    
    void generate(Program& parseTreeRoot);
    
    llvm::Value* findValue(const std::string & name) {
        llvm::Value *value = nullptr; 

        for (auto it = funcStack.rbegin(); it != funcStack.rend(); it++) {
            value = (*it)->getValueSymbolTable()->lookup(name); 
            if (value != nullptr) {
                return value; 
            } 
        }
        
        value = TheModule->getGlobalVariable(name); 
        if (value == nullptr) {
            throw std::logic_error("[ERROR] Undeclared variable: " + name); 
        }

        return value; 
    }
    
    llvm::Function* getCurFunction() {
        return funcStack.back();
    }
    
    void pushFunction(llvm::Function* func) {
        funcStack.push_back(func);
    }
    
    void popFunction() {
        funcStack.pop_back();
    }
    
    llvm::Function* createPrintf() {
        std::vector<llvm::Type*> arg_types;
        arg_types.push_back(TheBuilder.getInt8PtrTy());
        auto printf_type = llvm::FunctionType::get(TheBuilder.getInt32Ty(), llvm::makeArrayRef(arg_types), true);
        auto func = llvm::Function::Create(printf_type, llvm::Function::ExternalLinkage, llvm::Twine("printf"), TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);
        return func;
    }
    
    llvm::Function* createScanf() {
        auto scanfType = llvm::FunctionType::get(TheBuilder.getInt32Ty(), true);
        auto func = llvm::Function::Create(scanfType, llvm::Function::ExternalLinkage, llvm::Twine("scanf"), TheModule.get());
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

    llvm::Function* createChr() {
        auto returnType = TheBuilder.getInt8Ty();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getInt32Ty());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "chr", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);
        return func;
    }

    llvm::Function* createOdd() {
        auto returnType = TheBuilder.getInt32Ty();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getInt32Ty());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "odd", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);
        return func;
    }

    llvm::Function* createOrd() {
        auto returnType = TheBuilder.getInt32Ty();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getInt32Ty());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "ord", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);
        return func;
    }

    llvm::Function* createPred() {
        auto returnType = TheBuilder.getInt32Ty();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getInt32Ty());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "pred", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);
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
        llvm::BasicBlock *entrySqr = llvm::BasicBlock::Create(*TheContext, "entrypoint", func);
        llvm::IRBuilder<> builderSqr(entrySqr);
        llvm::Value* result = builderSqr.CreateMul(arg1,arg1,"multmpi");
        builderSqr.CreateRet(result);
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
        llvm::BasicBlock *entrySqrr = llvm::BasicBlock::Create(*TheContext, "entrypoint", func);
        llvm::IRBuilder<> builderSqrr(entrySqrr);
        llvm::Value* result = builderSqrr.CreateFMul(arg1,arg1,"multmpr");
        builderSqrr.CreateRet(result);
        return func;
    }

    llvm::Function* createSqrt() {
        auto returnType = TheBuilder.getDoubleTy();
        llvm::SmallVector<llvm::Type *, 1> funcArgs;
        funcArgs.push_back(TheBuilder.getDoubleTy());
        auto funcType = llvm::FunctionType::get(returnType, funcArgs, false);
        auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "sqrt", TheModule.get());
        func->setCallingConv(llvm::CallingConv::C);
        return func;
    }

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
        llvm::BasicBlock *entrySqr = llvm::BasicBlock::Create(*TheContext, "entrypoint", func);
        llvm::IRBuilder<> builderSucc(entrySqr);
        llvm::Value* result = builderSucc.CreateAdd(arg1,builderSucc.getInt32(1),"succ");
        builderSucc.CreateRet(result);

        return func;
    }
};

#endif
