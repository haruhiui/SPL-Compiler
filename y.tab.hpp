/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LP = 258,
    RP = 259,
    LB = 260,
    RB = 261,
    DOT = 262,
    COMMA = 263,
    COLON = 264,
    MUL = 265,
    DIV = 266,
    UNEQUAL = 267,
    NOT = 268,
    PLUS = 269,
    MINUS = 270,
    GE = 271,
    GT = 272,
    LE = 273,
    LT = 274,
    EQUAL = 275,
    ASSIGN = 276,
    MOD = 277,
    DOTDOT = 278,
    SEMI = 279,
    AND = 280,
    ARRAY = 281,
    TOKEN_BEGIN = 282,
    CASE = 283,
    CONST = 284,
    DO = 285,
    DOWNTO = 286,
    ELSE = 287,
    END = 288,
    FOR = 289,
    FUNCTION = 290,
    GOTO = 291,
    IF = 292,
    IN = 293,
    OF = 294,
    OR = 295,
    PACKED = 296,
    PROCEDURE = 297,
    PROGRAM = 298,
    RECORD = 299,
    REPEAT = 300,
    SET = 301,
    THEN = 302,
    TO = 303,
    TYPE = 304,
    UNTIL = 305,
    VAR = 306,
    WHILE = 307,
    WITH = 308,
    INTEGER = 309,
    ID = 310,
    SYS_CON = 311,
    SYS_FUNCT = 312,
    SYS_PROC = 313,
    SYS_TYPE = 314,
    READ = 315,
    STRING = 316,
    REAL = 317,
    CHAR = 318
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "spl.y"

	int iVal;
	string *sVal;
	double dVal;
	bool bVal;
	char cVal;
	Node *node;
	Expression *expression;
	Statement *statement;
	Integer *integer;
	Real *real;
	Char *astChar;
	Boolean *boolean;
	ConstValue *constValue;
	Identifier *identifier;
	ConstDeclaration *constDeclaration;
	TypeDeclaration *typeDeclaration;
	VarDeclaration *varDeclaration;
	AstType *type;
	EnumType *enumType;
	AstArrayType *AstArrayType;
	RecordType  *recordType;
	ConstRangeType *constRangeType;
	EnumRangeType *enumRangeType;
	FieldDeclaration *fieldDeclaration;
	FuncDeclaration *funcDeclaration;
	Parameter *parameter;
	Routine *routine;
	Program *program;
	AssignStatement *assignStatement;
	BinaryExpression *binaryExpression;
	ArrayReference *arrayReference;
	RecordReference *recordReference;
	FunctionCall *functionCall;
	SysFunctionCall *sysFunctionCall;
	ProcedureCall *procedureCall;
	SysProcedureCall *sysProcedureCall;
	IfStatement *ifStatement;
	RepeatStatement *repeatStatement;
	WhileStatement *whileStatement;
	ForStatement *forStatement;
	CaseStatement *caseStatement;
	CaseExpression *caseExpression;
	GotoStatement *gotoStatement;
	CompoundStatement *compoundStatement;

	ExpressionList *expressionList;
	StatementList *statementList;
	ConstDeclList *constDeclList;
	VarDeclList *varDeclList;
	TypeDeclList *typeDeclList;
	NameList *nameList;
	FieldList *fieldList;
	ParaList *paraList;
	RoutineList *routineList;
	ArgsList *argsList;
	CaseExprList *caseExprList;
	

#line 181 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
