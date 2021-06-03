.PHONY: clean 

target = spl
flex_file = spl.l 
flex_out = lex.yy.cpp 
bison_file = spl.y 
bison_out_h = y.tab.hpp  
bison_out_c = y.tab.cpp 
objs = main.o Ast.o Generator.o lex.yy.o y.tab.o 
cpps = main.cpp Ast.cpp Generator.cpp lex.yy.cpp y.tab.cpp 

# -fexceptions solves: error: cannot use 'throw' with exceptions disabled
# clang: warning: -lLLVM-10: 'linker' input unused [-Wunused-command-line-argument]
# clang: warning: argument unused during compilation: '-L/usr/lib/llvm-10/lib' [-Wunused-command-line-argument]
flags = `llvm-config --cxxflags --ldflags --system-libs --libs all` \
	-fexceptions \
	-Wno-unused-command-line-argument

all: $(flex_out) $(bison_out_c) $(target) 

$(flex_out): $(flex_file) 
	flex -o $@ $^ 

$(bison_out_c): $(bison_file) 
	bison -d -o $@ $^ 

%.o: %.cpp 
	clang++ -c $(flags) -o $@ $< 

$(target): $(objs)  
	clang++ $(flags) -g -O3 -o $@ $^ 

clean: 
	-rm -f $(flex_out) $(bison_out_h) $(bison_out_c) *.o 