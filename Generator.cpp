#include "Ast.hpp"
#include "Generator.hpp"

using namespace std;

void Generator::generate(Program& parseTreeRoot)
{
    // parseTreeRoot has been set up during previous procedures
    // Now codeGen will recursively generate intermediate code
    parseTreeRoot.codeGen(*this);

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

    auto filename = "output.o";
    std::error_code ec;
    llvm::raw_fd_ostream dest(filename, ec, llvm::sys::fs::OF_None);
    if (ec) {
        llvm::errs() << "Could not open file: " << ec.message();
        return ;
    }
    llvm::legacy::PassManager pass;
    auto FileType = llvm::CGFT_ObjectFile;
    if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
        llvm::errs() << "TheTargetMachine can't emit a file of this type";
        return ;
    }
    // pass.run(*TheModule);
    // dest.flush();

    auto filename2 = "output.ll"; 
    std::error_code ec2; 
    llvm::raw_fd_ostream dest2(filename2, ec2, llvm::sys::fs::OF_None); 
    if (ec2) {
        llvm::errs() << "Could not open file: " << ec2.message(); 
        return ; 
    }
    TheModule->print(dest2, nullptr); 
    dest2.flush(); 

    llvm::outs() << "[+] Wrote llvm IR file: output.ll" << "\n"; 
    llvm::outs() << "[*] You can run by 'lli output.ll' directly." << "\n"; 
    // stackoverflow is a good thing. 
}
