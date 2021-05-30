#include "Ast.hpp"
#include "Generator.hpp"

using namespace std;

void Generator::generate(Program& astRoot)
{
    astRoot.codeGen(*this);

    // Initialize the target registry etc.
    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    auto TargetTriple = llvm::sys::getDefaultTargetTriple();
    TheModule->setTargetTriple(TargetTriple);

    std::string Error;
    auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, Error);

    // Print an error and exit if we couldn't find the requested target.
    // This generally occurs if we've forgotten to initialise the
    // TargetRegistry or we have a bogus target triple.
    if (!Target) {
        llvm::errs() << Error;
        return ;
    }

    auto CPU = "generic";
    auto Features = "";

    llvm::TargetOptions opt;
    auto RM = llvm::Optional<llvm::Reloc::Model>();
    auto TheTargetMachine =
        Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    TheModule->setDataLayout(TheTargetMachine->createDataLayout());

    auto Filename = "output.o";
    std::error_code EC;
    llvm::raw_fd_ostream dest(Filename, EC, llvm::sys::fs::OF_None);

    if (EC) {
        llvm::errs() << "Could not open file: " << EC.message();
        return ;
    }

    llvm::legacy::PassManager pass;
    auto FileType = llvm::CGFT_ObjectFile;

    if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
        llvm::errs() << "TheTargetMachine can't emit a file of this type";
        return ;
    }

    pass.run(*TheModule);
    dest.flush();

    // llvm::outs() << "Wrote " << Filename << "\n";

    auto filename2 = "output.ll"; 
    std::error_code ec2; 
    llvm::raw_fd_ostream dest2(filename2, ec2, llvm::sys::fs::OF_None); 
    if (ec2) {
        llvm::errs() << "Could not open file: " << ec2.message(); 
        return ; 
    }
    TheModule->print(dest2, nullptr); 
    dest2.flush(); 

    // llvm::outs() << "Wrote llvm IR to " << filename2 << " and you can run it by: lli " << filename2 << "\n"; 

    llvm::outs() << "Wrote object file: output.o, and llvm IR file: output.ll" << "\n"; 
    llvm::outs() << "You can run by 'lli output.ll' directly." << "\n"; 
    llvm::outs() << "Or you can get the executable file by 'clang output.o' and then './a.out' to execute it." << "\n"; 
    // stackoverflow kezhenshi ge haodongxi !!! 
    // stackoverflow is a good thing. 
}

llvm::GenericValue Generator::run()
{
    cout << "[INFO] " << "IR running begin..." << endl;
    llvm::ExecutionEngine* ee = genExeEngine();
    vector<llvm::GenericValue> args;
    llvm::GenericValue res = ee->runFunction(mainFunction, args);
    cout << "[INFO] " << "IR running finished." << endl;
    return res;
}

llvm::ExecutionEngine* Generator::genExeEngine()
{
    std::string errStr;
    auto RTDyldMM = unique_ptr<llvm::SectionMemoryManager>(new llvm::SectionMemoryManager());
    llvm::ExecutionEngine* ee = llvm::EngineBuilder(std::move(TheModule))
//        .setEngineKind(llvm::EngineKind::Interpreter)
        .setEngineKind(llvm::EngineKind::JIT)
        .setErrorStr(&errStr)
        .setVerifyModules(true)
        .setMCJITMemoryManager(move(RTDyldMM))
        .setOptLevel(llvm::CodeGenOpt::Default)
        .create();
    if (!ee)
    {
        throw std::logic_error("[ERROR] Create Engine Error: " + errStr);
    }
    ee->addModule(std::move(TheModule));
    ee->finalizeObject();
    return ee;
}
