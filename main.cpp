#include <fstream>
#include "Ast.hpp" 
#include "Generator.hpp"
#include "y.tab.hpp"

extern int yyparse();

// Defined in spl.y
extern Program *root;

int main(int argc, char **argv) 
{
    yyparse();
    std::ofstream os("tree.json");
    os << root->getJson() << std::endl;

    Generator generator;
    generator.generate(*root);
    // generator.run();
    
    return 0;
}
