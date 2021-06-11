%{
#include "Ast.hpp"
#include "y.tab.hpp"
#include <stdio.h>
#include <string>
extern "C" int yywrap() {return 1;}
int lineno = 0; 
%}

%%
\/\/.*			{ ; }
[ \t]			{ ; }
\n				{ lineno++; }
\'.\' { 
	yylval.cVal = yytext[1];
	return CHAR; 
}
 /* TODO: not support "asd\"asd"*/
\".*\" {
	yylval.sVal = new std::string(yytext+1, yyleng-2);
	return STRING;
}
	/* operator and delimeter*/
"("				{ return LP; }
")"				{ return RP; }
"["				{ return LB; }
"]"				{ return RB; }
".."			{ return DOTDOT; }   /* DOTDOT has higher privilege than DOT*/
"."				{ return DOT; }
","				{ return COMMA; }
":"				{ return COLON; }
"*"				{ return MUL; }
"/"				{ return DIV; }
"%"				{ return MOD; }
"<>"			{ return UNEQUAL; }
"+"				{ return PLUS; }
"-"				{ return MINUS; }
">="			{ return GE; }
">"				{ return GT; }
"<="			{ return LE; }
"<"				{ return LT; }
"="				{ return EQUAL; }
":="			{ return ASSIGN; }
";"				{ return SEMI; }

	/* keyword list*/
"and"			{ return AND; }
"array"			{ return ARRAY; }
"begin"			{ return TOKEN_BEGIN; }
"case"			{ return CASE; }
"const"			{ return CONST; }
"div"			{ return DIV; }
"do"			{ return DO; }
"downto"		{ return DOWNTO; }
"else"			{ return ELSE; }
"end"			{ return END; }
"for"			{ return FOR; }
"function"		{ return FUNCTION; }
"goto"			{ return GOTO; }
"if"			{ return IF; }
"in"			{ return IN; }
"mod"			{ return MOD; }
"not"			{ return NOT; }
"of"			{ return OF; }
"or"			{ return OR; }
"packed"		{ return PACKED; }
"procedure"		{ return PROCEDURE; }
"program"		{ return PROGRAM; }
"record"		{ return RECORD; }
"repeat"		{ return REPEAT; }
"set"			{ return SET; }
"then"			{ return THEN; }
"to"			{ return TO; }
"type"			{ return TYPE; }
"until"			{ return UNTIL; }
"var"			{ return VAR; }
"while"			{ return WHILE; }
"with"			{ return WITH; }

"false"|"maxint"|"true" {
	yylval.sVal = new std::string(yytext, yyleng); 
	return SYS_CON; 
}

"abs"|"chr"|"odd"|"ord"|"pred"|"sqr"|"sqrt"|"succ" {
	yylval.sVal = new std::string(yytext, yyleng); 
	return SYS_FUNCT; 
}

"write"|"writeln" { 
	yylval.sVal = new std::string(yytext, yyleng);
	return SYS_PROC; 
}

"boolean"|"char"|"integer"|"real"|"string" {
	yylval.sVal = new std::string(yytext, yyleng); 
	return SYS_TYPE; 
}

"read" { 
	yylval.sVal = new std::string(yytext, yyleng);
	return READ; 
}

[a-zA-Z_][a-zA-Z0-9_]* { 
	yylval.sVal = new std::string(yytext, yyleng);
	return ID; 
} 
[0-9]+\.[0-9]+ { 
	double dtmp;
	sscanf(yytext, "%lf", &dtmp);
	yylval.dVal = dtmp;
	return REAL; 
}
[0-9]+ {
	int itmp;  
	sscanf(yytext, "%d", &itmp);
	yylval.iVal = itmp; 
	return INTEGER; 
}

%%

void yyerror(const char *s) { 
	std::printf("Error: %s (line: %d)\n", s, lineno);
	std::exit(1); 
}