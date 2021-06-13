/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "spl.y"

#include "Ast.hpp"
#include <string>
#include <iostream>

using namespace std;

int yylex(void);

void yyerror(const char *s); 

Program *root;

#line 84 "y.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 16 "spl.y"

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
	VarRangeType *VarRangeType;
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
	

#line 260 "y.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   428

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  261

#define YYUNDEFTOK  2
#define YYMAXUTOK   318


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   133,   133,   140,   148,   155,   164,   171,   176,   182,
     187,   195,   199,   203,   207,   211,   225,   230,   236,   241,
     249,   256,   260,   264,   271,   275,   279,   283,   287,   291,
     295,   302,   309,   316,   320,   327,   334,   338,   345,   350,
     356,   360,   367,   374,   379,   384,   389,   395,   401,   409,
     416,   423,   430,   435,   441,   445,   453,   458,   466,   473,
     480,   488,   495,   502,   507,   513,   518,   525,   529,   533,
     537,   541,   545,   549,   553,   557,   564,   568,   572,   579,
     583,   587,   591,   595,   602,   607,   615,   619,   623,   627,
     631,   635,   639,   646,   650,   654,   658,   665,   669,   673,
     677,   681,   688,   692,   696,   700,   704,   708,   712,   716,
     720,   724,   731,   735,   742,   749,   754,   760,   767,   774,
     781,   785,   792,   799,   804,   812,   816,   823
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LP", "RP", "LB", "RB", "DOT", "COMMA",
  "COLON", "MUL", "DIV", "UNEQUAL", "NOT", "PLUS", "MINUS", "GE", "GT",
  "LE", "LT", "EQUAL", "ASSIGN", "MOD", "DOTDOT", "SEMI", "AND", "ARRAY",
  "TOKEN_BEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE", "END", "FOR",
  "FUNCTION", "GOTO", "IF", "IN", "OF", "OR", "PACKED", "PROCEDURE",
  "PROGRAM", "RECORD", "REPEAT", "SET", "THEN", "TO", "TYPE", "UNTIL",
  "VAR", "WHILE", "WITH", "INTEGER", "ID", "SYS_CON", "SYS_FUNCT",
  "SYS_PROC", "SYS_TYPE", "READ", "STRING", "REAL", "CHAR", "$accept",
  "name", "program", "program_head", "routine", "routine_head",
  "const_part", "const_expr_list", "const_value", "type_part",
  "type_decl_list", "type_definition", "type_decl", "simple_type_decl",
  "array_type_decl", "record_type_decl", "field_decl_list", "field_decl",
  "name_list", "var_part", "var_decl_list", "var_decl", "routine_part",
  "function_decl", "function_head", "procedure_decl", "procedure_head",
  "parameters", "para_decl_list", "para_type_list", "var_para_list",
  "val_para_list", "sub_routine", "routine_body", "compound_stmt",
  "stmt_list", "stmt", "non_label_stmt", "assign_stmt", "proc_stmt",
  "expression_list", "expression", "expr", "term", "factor", "args_list",
  "if_stmt", "else_clause", "repeat_stmt", "while_stmt", "for_stmt",
  "direction", "case_stmt", "case_expr_list", "case_expr", "goto_stmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

#define YYPACT_NINF (-149)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,   -15,    62,    34,    41,  -149,    13,    69,    56,    36,
    -149,  -149,    68,    13,  -149,  -149,  -149,  -149,    13,    39,
     356,    71,   242,    76,    13,  -149,    13,    11,  -149,  -149,
    -149,  -149,  -149,    73,   356,   192,  -149,    13,    45,   192,
    -149,   192,    93,   101,   108,   121,  -149,    94,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,   107,  -149,  -149,
       1,    13,  -149,    13,    13,    11,  -149,   105,  -149,   106,
    -149,   111,   192,   192,   192,   122,    77,  -149,   212,    -1,
      49,  -149,   115,  -149,    25,   254,   168,   295,   192,   192,
     192,   192,    13,   192,  -149,    13,   356,   148,    13,  -149,
     136,   141,   143,  -149,  -149,  -149,    13,   107,  -149,   162,
     162,  -149,  -149,    34,    34,  -149,   368,  -149,  -149,   192,
     192,   192,    13,   192,   192,   192,   192,   192,   192,   353,
     192,   192,   192,   192,   192,   192,   192,   192,   283,   192,
     283,  -149,    48,   408,   169,   408,   123,   377,   151,   408,
     137,   154,   205,   -28,  -149,    21,    13,   356,  -149,  -149,
     158,   -36,   166,  -149,    56,   159,   170,  -149,   150,   152,
     386,  -149,    -1,    -1,    -1,    -1,    -1,    -1,   184,   188,
     303,  -149,    49,    49,    49,  -149,  -149,  -149,  -149,    16,
     146,   408,  -149,  -149,   192,  -149,  -149,   192,   179,   192,
    -149,    51,   195,  -149,  -149,   107,  -149,  -149,  -149,    13,
     194,    -2,  -149,   202,   203,   205,  -149,  -149,  -149,  -149,
    -149,  -149,   283,   283,  -149,  -149,  -149,  -149,   192,   283,
    -149,   408,   408,   192,   408,   356,  -149,   165,   189,   194,
    -149,   -36,   205,   205,  -149,   190,   197,   351,  -149,   408,
    -149,   107,  -149,  -149,  -149,  -149,  -149,  -149,   283,  -149,
    -149
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     8,     0,     1,     0,     0,     0,    17,
       4,     2,     0,     7,     3,    64,     5,    61,     0,    39,
       0,     0,     0,     0,    16,    19,     0,    47,    11,    15,
      14,    12,    13,     0,     0,     0,    62,     0,     0,     0,
      64,     0,     0,    81,     0,    79,    69,     0,    66,    67,
      68,    70,    71,    72,    73,    74,    75,     0,    18,    37,
       0,    38,    41,     0,     0,     6,    45,     0,    46,     0,
      10,     0,     0,     0,     0,   104,   102,   106,     0,    92,
      96,   101,     0,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,     0,     0,     0,    24,
      25,     0,     0,    21,    22,    23,     0,     0,    40,    53,
      53,    43,    44,     8,     8,     9,     0,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,    85,     0,   113,     0,     0,     0,    76,
       0,     0,     0,     0,    34,     0,     0,     0,    20,    36,
       0,     0,     0,    51,     0,     0,     0,   107,     0,     0,
       0,   111,    91,    86,    87,    88,    89,    90,     0,     0,
       0,   124,    93,    94,    95,    97,    98,    99,   100,     0,
     116,   117,   118,    82,     0,    83,    80,     0,     0,     0,
      26,     0,     0,    32,    33,     0,    30,    27,    42,     0,
      59,     0,    55,     0,     0,     0,    60,    48,    50,   105,
     103,   110,     0,     0,   122,   123,   121,   120,     0,     0,
     114,    84,   112,     0,    78,     0,    28,     0,     0,    58,
      52,     0,     0,     0,    49,     0,     0,     0,   115,    77,
      29,     0,    35,    54,    56,    57,   126,   125,     0,    31,
     119
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,    -6,  -149,  -149,  -149,   215,  -149,  -149,    -9,  -149,
    -149,   198,   -99,  -148,  -149,  -149,  -149,    66,   -92,  -149,
    -149,   164,  -149,   173,  -149,   174,  -149,   117,  -149,     0,
    -149,  -149,   126,    79,    -7,   204,  -114,   163,  -149,  -149,
    -149,   -18,   250,    59,     4,   -70,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,    78,  -149
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    76,     2,     3,     7,   164,     9,    13,    77,    19,
      24,    25,   102,   103,   104,   105,   153,   154,    60,    27,
      61,    62,    65,    66,    67,    68,    69,   162,   211,   212,
     213,   214,   165,    16,    46,    22,    47,    48,    49,    50,
     142,   145,    79,    80,    81,   146,    51,   230,    52,    53,
      54,   228,    55,   180,   181,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    17,   240,   150,   202,   203,   155,    21,   160,   106,
     107,    33,    23,   130,   131,   209,    45,    78,    23,    11,
      59,    84,   241,    86,   190,    71,   192,    11,   123,   106,
     205,    82,   124,   125,   126,   127,   128,   123,     1,   132,
       4,   124,   125,   126,   127,   128,    63,   226,   101,   168,
     169,   100,   193,    64,   116,    59,   194,   109,   110,   133,
     134,   155,     5,     6,   227,    10,   235,   244,    11,   210,
     143,   135,   138,   147,   136,   149,    14,   117,   118,    45,
     120,    45,   121,    15,   122,    18,   148,   151,    20,    59,
      26,    34,    59,   144,   254,   255,    57,    70,   101,    83,
     159,   100,    87,   170,    88,    28,   238,    29,   245,   246,
      95,    89,    30,    31,    32,   248,   171,   239,    94,   189,
     179,   191,    96,   178,    90,   119,    91,   196,    92,   113,
     114,   197,    45,    97,    45,   115,   137,   185,   186,   187,
     188,   200,    93,   101,   260,   106,   100,    59,   207,   210,
     206,    98,   259,   152,   219,    59,   220,    17,   197,   156,
     197,    28,    11,    29,   157,   161,    99,   158,    30,    31,
      32,   179,   199,   195,   178,   215,   231,   201,   229,   232,
     123,   234,   208,   217,   124,   125,   126,   127,   128,   182,
     183,   184,   236,   222,   218,    72,   101,   223,   140,   100,
     233,   237,   106,    59,   251,    73,   101,    74,    95,   100,
     247,   242,   243,   252,   256,   249,    45,    45,     8,   204,
      96,   257,    58,    45,   123,   108,   250,   163,   124,   125,
     126,   127,   128,   101,   101,    59,   100,   100,   111,   112,
     166,   253,   101,   216,    85,   100,    28,    11,    29,    75,
     141,   129,    45,    30,    31,    32,     0,     0,   225,    28,
      11,    29,     0,     0,    99,     0,    30,    31,    32,    15,
      35,     0,     0,     0,     0,    36,    37,     0,    38,    39,
       0,    15,    35,     0,     0,     0,     0,    40,    37,     0,
      38,    39,     0,     0,    41,     0,    42,    11,     0,    40,
      43,     0,    44,     0,   139,     0,    41,     0,    42,    11,
      15,    35,    43,     0,    44,     0,     0,    37,     0,    38,
      39,     0,    15,    35,     0,     0,     0,     0,    40,    37,
       0,    38,    39,     0,     0,    41,   224,    42,    11,     0,
      40,    43,     0,    44,     0,     0,     0,    41,     0,     0,
      11,     0,     0,    43,     0,    44,     0,    28,    11,    29,
       0,     0,     0,   123,    30,    31,    32,   124,   125,   126,
     127,   128,   167,   172,   173,   174,   175,   176,   177,     0,
     123,   258,     0,   198,   124,   125,   126,   127,   128,   123,
       0,     0,   221,   124,   125,   126,   127,   128,   123,     0,
       0,     0,   124,   125,   126,   127,   128,    28,    11,    29,
      28,     0,    29,     0,    30,    31,    32,    30,    31,    32,
     123,     0,     0,     0,   124,   125,   126,   127,   128
};

static const yytype_int16 yycheck[] =
{
       6,     8,     4,    95,   152,    33,    98,    13,   107,     8,
       9,    20,    18,    14,    15,    51,    22,    35,    24,    55,
      26,    39,    24,    41,   138,    34,   140,    55,    12,     8,
       9,    37,    16,    17,    18,    19,    20,    12,    43,    40,
      55,    16,    17,    18,    19,    20,    35,    31,    57,   119,
     120,    57,     4,    42,    72,    61,     8,    63,    64,    10,
      11,   153,     0,    29,    48,    24,    15,   215,    55,   161,
      88,    22,    47,    91,    25,    93,     7,    73,    74,    85,
       3,    87,     5,    27,     7,    49,    92,    96,    20,    95,
      51,    20,    98,    89,   242,   243,    20,    24,   107,    54,
     106,   107,     9,   121,     3,    54,   205,    56,   222,   223,
       3,     3,    61,    62,    63,   229,   122,   209,    24,   137,
     129,   139,    15,   129,     3,     3,     5,     4,     7,    24,
      24,     8,   138,    26,   140,    24,    21,   133,   134,   135,
     136,     4,    21,   152,   258,     8,   152,   153,   157,   241,
     156,    44,   251,     5,     4,   161,     4,   164,     8,    23,
       8,    54,    55,    56,    23,     3,    59,    24,    61,    62,
      63,   180,    21,     4,   180,     9,   194,    23,    32,   197,
      12,   199,    24,    24,    16,    17,    18,    19,    20,   130,
     131,   132,   201,     9,    24,     3,   205,     9,    30,   205,
      21,     6,     8,   209,    39,    13,   215,    15,     3,   215,
     228,     9,     9,    24,    24,   233,   222,   223,     3,   153,
      15,    24,    24,   229,    12,    61,   235,   110,    16,    17,
      18,    19,    20,   242,   243,   241,   242,   243,    65,    65,
     114,   241,   251,   164,    40,   251,    54,    55,    56,    57,
      87,    39,   258,    61,    62,    63,    -1,    -1,   180,    54,
      55,    56,    -1,    -1,    59,    -1,    61,    62,    63,    27,
      28,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      -1,    27,    28,    -1,    -1,    -1,    -1,    45,    34,    -1,
      36,    37,    -1,    -1,    52,    -1,    54,    55,    -1,    45,
      58,    -1,    60,    -1,    50,    -1,    52,    -1,    54,    55,
      27,    28,    58,    -1,    60,    -1,    -1,    34,    -1,    36,
      37,    -1,    27,    28,    -1,    -1,    -1,    -1,    45,    34,
      -1,    36,    37,    -1,    -1,    52,    33,    54,    55,    -1,
      45,    58,    -1,    60,    -1,    -1,    -1,    52,    -1,    -1,
      55,    -1,    -1,    58,    -1,    60,    -1,    54,    55,    56,
      -1,    -1,    -1,    12,    61,    62,    63,    16,    17,    18,
      19,    20,     4,   123,   124,   125,   126,   127,   128,    -1,
      12,    30,    -1,     6,    16,    17,    18,    19,    20,    12,
      -1,    -1,     6,    16,    17,    18,    19,    20,    12,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    54,    55,    56,
      54,    -1,    56,    -1,    61,    62,    63,    61,    62,    63,
      12,    -1,    -1,    -1,    16,    17,    18,    19,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    66,    67,    55,     0,    29,    68,    69,    70,
      24,    55,    65,    71,     7,    27,    97,    98,    49,    73,
      20,    65,    99,    65,    74,    75,    51,    83,    54,    56,
      61,    62,    63,    72,    20,    28,    33,    34,    36,    37,
      45,    52,    54,    58,    60,    65,    98,   100,   101,   102,
     103,   110,   112,   113,   114,   116,   119,    20,    75,    65,
      82,    84,    85,    35,    42,    86,    87,    88,    89,    90,
      24,    72,     3,    13,    15,    57,    65,    72,   105,   106,
     107,   108,    65,    54,   105,    99,   105,     9,     3,     3,
       3,     5,     7,    21,    24,     3,    15,    26,    44,    59,
      65,    72,    76,    77,    78,    79,     8,     9,    85,    65,
      65,    87,    89,    24,    24,    24,   105,   108,   108,     3,
       3,     5,     7,    12,    16,    17,    18,    19,    20,    39,
      14,    15,    40,    10,    11,    22,    25,    21,    47,    50,
      30,   101,   104,   105,   108,   105,   109,   105,    65,   105,
      82,    72,     5,    80,    81,    82,    23,    23,    24,    65,
      76,     3,    91,    91,    69,    96,    96,     4,   109,   109,
     105,    65,   106,   106,   106,   106,   106,   106,    65,    72,
     117,   118,   107,   107,   107,   108,   108,   108,   108,   105,
     100,   105,   100,     4,     8,     4,     4,     8,     6,    21,
       4,    23,    77,    33,    81,     9,    65,    72,    24,    51,
      82,    92,    93,    94,    95,     9,    97,    24,    24,     4,
       4,     6,     9,     9,    33,   118,    31,    48,   115,    32,
     111,   105,   105,    21,   105,    15,    72,     6,    76,    82,
       4,    24,     9,     9,    77,   100,   100,   105,   100,   105,
      72,    39,    24,    93,    77,    77,    24,    24,    30,    76,
     100
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    67,    68,    69,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    73,    73,    74,    74,
      75,    76,    76,    76,    77,    77,    77,    77,    77,    77,
      77,    78,    79,    80,    80,    81,    82,    82,    83,    83,
      84,    84,    85,    86,    86,    86,    86,    86,    87,    88,
      89,    90,    91,    91,    92,    92,    93,    93,    94,    95,
      96,    97,    98,    99,    99,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   103,
     103,   103,   103,   103,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   106,   106,   106,   106,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   109,   109,   110,   111,   111,   112,   113,   114,
     115,   115,   116,   117,   117,   118,   118,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     4,     2,     0,     5,
       4,     1,     1,     1,     1,     1,     2,     0,     2,     1,
       4,     1,     1,     1,     1,     1,     3,     3,     4,     5,
       3,     6,     3,     2,     1,     4,     3,     1,     2,     0,
       2,     1,     4,     2,     2,     1,     1,     0,     4,     5,
       4,     3,     3,     0,     3,     1,     3,     3,     2,     1,
       2,     1,     3,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     6,     5,     1,
       4,     1,     4,     4,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     1,     4,     1,     4,     1,     3,     2,     2,
       4,     3,     3,     1,     5,     2,     0,     4,     4,     8,
       1,     1,     5,     2,     1,     4,     4,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 134 "spl.y"
        { 
		(yyval.identifier) = new Identifier((yyvsp[0].sVal)); 
	}
#line 1662 "y.tab.cpp"
    break;

  case 3:
#line 141 "spl.y"
        { 
		(yyval.program) = new Program((yyvsp[-2].sVal), (yyvsp[-1].routine)); 
		root = (yyval.program); 
	}
#line 1671 "y.tab.cpp"
    break;

  case 4:
#line 149 "spl.y"
        { 
		(yyval.sVal) = (yyvsp[-1].sVal); 
	}
#line 1679 "y.tab.cpp"
    break;

  case 5:
#line 156 "spl.y"
        { 
		(yyval.routine) = (yyvsp[-1].routine); 
		(yyval.routine)->setRoutineBody((yyvsp[0].compoundStatement)); 
	}
#line 1688 "y.tab.cpp"
    break;

  case 6:
#line 165 "spl.y"
        { 
		(yyval.routine) = new Routine((yyvsp[-3].constDeclList), (yyvsp[-2].typeDeclList), (yyvsp[-1].varDeclList), (yyvsp[0].routineList)); 
	}
#line 1696 "y.tab.cpp"
    break;

  case 7:
#line 172 "spl.y"
        { 
		(yyval.constDeclList) = (yyvsp[0].constDeclList); 
	}
#line 1704 "y.tab.cpp"
    break;

  case 8:
#line 176 "spl.y"
        { 
		(yyval.constDeclList) = new ConstDeclList(); 
	}
#line 1712 "y.tab.cpp"
    break;

  case 9:
#line 183 "spl.y"
        { 
		(yyval.constDeclList) = (yyvsp[-4].constDeclList); 
		(yyval.constDeclList)->push_back(new ConstDeclaration((yyvsp[-3].identifier), (yyvsp[-1].constValue))); 
	}
#line 1721 "y.tab.cpp"
    break;

  case 10:
#line 188 "spl.y"
        { 
		(yyval.constDeclList) = new ConstDeclList(); 
		(yyval.constDeclList)->push_back(new ConstDeclaration((yyvsp[-3].identifier), (yyvsp[-1].constValue))); 
	}
#line 1730 "y.tab.cpp"
    break;

  case 11:
#line 196 "spl.y"
        { 
		(yyval.constValue) = new Integer((yyvsp[0].iVal)); 
	}
#line 1738 "y.tab.cpp"
    break;

  case 12:
#line 200 "spl.y"
        { 
		(yyval.constValue) = new Real((yyvsp[0].dVal)); 
	}
#line 1746 "y.tab.cpp"
    break;

  case 13:
#line 204 "spl.y"
        { 
		(yyval.constValue) = new Char((yyvsp[0].cVal)); 
	}
#line 1754 "y.tab.cpp"
    break;

  case 14:
#line 208 "spl.y"
        {
		(yyval.constValue) = new String((yyvsp[0].sVal));
	}
#line 1762 "y.tab.cpp"
    break;

  case 15:
#line 212 "spl.y"
        {
		if (*(yyvsp[0].sVal) == "true") {
			(yyval.constValue) = new Boolean(true);
		} else if(*(yyvsp[0].sVal) == "false") {
			(yyval.constValue) = new Boolean(false);
		} else {
			// "maxint"
			(yyval.constValue) = new Integer(0x7FFFFFFF);	
		}
	}
#line 1777 "y.tab.cpp"
    break;

  case 16:
#line 226 "spl.y"
        { 
		(yyval.typeDeclList) = (yyvsp[0].typeDeclList); 
	}
#line 1785 "y.tab.cpp"
    break;

  case 17:
#line 230 "spl.y"
        { 
		(yyval.typeDeclList) = new TypeDeclList(); 
	}
#line 1793 "y.tab.cpp"
    break;

  case 18:
#line 237 "spl.y"
        { 
		(yyval.typeDeclList) = (yyvsp[-1].typeDeclList); 
		(yyval.typeDeclList)->push_back((yyvsp[0].typeDeclaration)); 
	}
#line 1802 "y.tab.cpp"
    break;

  case 19:
#line 242 "spl.y"
        { 
		(yyval.typeDeclList) = new TypeDeclList(); 
		(yyval.typeDeclList)->push_back((yyvsp[0].typeDeclaration)); 
	}
#line 1811 "y.tab.cpp"
    break;

  case 20:
#line 250 "spl.y"
        { 
		(yyval.typeDeclaration) = new TypeDeclaration((yyvsp[-3].identifier), (yyvsp[-1].type)); 
	}
#line 1819 "y.tab.cpp"
    break;

  case 21:
#line 257 "spl.y"
        { 
		(yyval.type) = (yyvsp[0].type); 
	}
#line 1827 "y.tab.cpp"
    break;

  case 22:
#line 261 "spl.y"
        { 
		(yyval.type) = (yyvsp[0].type); 
	}
#line 1835 "y.tab.cpp"
    break;

  case 23:
#line 265 "spl.y"
        { 
		(yyval.type) = (yyvsp[0].type); 
	}
#line 1843 "y.tab.cpp"
    break;

  case 24:
#line 272 "spl.y"
        {
		(yyval.type) = new AstType(*(yyvsp[0].sVal));
	}
#line 1851 "y.tab.cpp"
    break;

  case 25:
#line 276 "spl.y"
        { 
		(yyval.type) = new AstType((yyvsp[0].identifier)); 
	}
#line 1859 "y.tab.cpp"
    break;

  case 26:
#line 280 "spl.y"
        { 
		(yyval.type) = new AstType(new EnumType((yyvsp[-1].nameList))); 
	}
#line 1867 "y.tab.cpp"
    break;

  case 27:
#line 284 "spl.y"
        { 
		(yyval.type) = new AstType(new ConstRangeType((yyvsp[-2].constValue), (yyvsp[0].constValue))); 
	}
#line 1875 "y.tab.cpp"
    break;

  case 28:
#line 288 "spl.y"
        { 
		(yyval.type) = new AstType(new ConstRangeType(-*(yyvsp[-2].constValue), (yyvsp[0].constValue))); 
	}
#line 1883 "y.tab.cpp"
    break;

  case 29:
#line 292 "spl.y"
        { 
		(yyval.type) = new AstType(new ConstRangeType(-*(yyvsp[-3].constValue), -*(yyvsp[0].constValue))); 
	}
#line 1891 "y.tab.cpp"
    break;

  case 30:
#line 296 "spl.y"
        { 
		(yyval.type) = new AstType(new VarRangeType((yyvsp[-2].identifier), (yyvsp[0].identifier))); 
	}
#line 1899 "y.tab.cpp"
    break;

  case 31:
#line 303 "spl.y"
        { 
		(yyval.type) = new AstType(new AstArrayType((yyvsp[0].type), (yyvsp[-3].type))); 
	}
#line 1907 "y.tab.cpp"
    break;

  case 32:
#line 310 "spl.y"
        { 
		(yyval.type) = new AstType(new RecordType((yyvsp[-1].fieldList))); 
	}
#line 1915 "y.tab.cpp"
    break;

  case 33:
#line 317 "spl.y"
        { 
		(yyval.fieldList) = (yyvsp[-1].fieldList); (yyval.fieldList)->push_back((yyvsp[0].fieldDeclaration)); 
	}
#line 1923 "y.tab.cpp"
    break;

  case 34:
#line 321 "spl.y"
        { 
		(yyval.fieldList) = new FieldList(); (yyval.fieldList)->push_back((yyvsp[0].fieldDeclaration)); 
	}
#line 1931 "y.tab.cpp"
    break;

  case 35:
#line 328 "spl.y"
        { 
		(yyval.fieldDeclaration) = new FieldDeclaration((yyvsp[-3].nameList), (yyvsp[-1].type)); 
	}
#line 1939 "y.tab.cpp"
    break;

  case 36:
#line 335 "spl.y"
        { 
		(yyval.nameList) = (yyvsp[-2].nameList); (yyval.nameList)->push_back((yyvsp[0].identifier)); 
	}
#line 1947 "y.tab.cpp"
    break;

  case 37:
#line 339 "spl.y"
        { 
		(yyval.nameList) = new NameList(); (yyval.nameList)->push_back((yyvsp[0].identifier)); 
	}
#line 1955 "y.tab.cpp"
    break;

  case 38:
#line 346 "spl.y"
        { 
		(yyval.varDeclList) = (yyvsp[0].varDeclList); 
	}
#line 1963 "y.tab.cpp"
    break;

  case 39:
#line 350 "spl.y"
        { 
		(yyval.varDeclList) = new VarDeclList(); 
	}
#line 1971 "y.tab.cpp"
    break;

  case 40:
#line 357 "spl.y"
        { 
		(yyval.varDeclList) = (yyvsp[-1].varDeclList); (yyval.varDeclList)->push_back((yyvsp[0].varDeclaration)); 
	}
#line 1979 "y.tab.cpp"
    break;

  case 41:
#line 361 "spl.y"
        { 
		(yyval.varDeclList) = new VarDeclList(); (yyval.varDeclList)->push_back((yyvsp[0].varDeclaration)); 
	}
#line 1987 "y.tab.cpp"
    break;

  case 42:
#line 368 "spl.y"
        { 
		(yyval.varDeclaration) = new VarDeclaration((yyvsp[-3].nameList), (yyvsp[-1].type)); 
	}
#line 1995 "y.tab.cpp"
    break;

  case 43:
#line 375 "spl.y"
        { 
		(yyval.routineList) = (yyvsp[-1].routineList); 
		(yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 2004 "y.tab.cpp"
    break;

  case 44:
#line 380 "spl.y"
        { 
		(yyval.routineList) = (yyvsp[-1].routineList); 
		(yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 2013 "y.tab.cpp"
    break;

  case 45:
#line 385 "spl.y"
        { 
		(yyval.routineList) = new RoutineList(); 
		(yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 2022 "y.tab.cpp"
    break;

  case 46:
#line 390 "spl.y"
        { 
		(yyval.routineList) = new RoutineList(); 
		(yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 2031 "y.tab.cpp"
    break;

  case 47:
#line 395 "spl.y"
        { 
		(yyval.routineList) = new RoutineList(); 
	}
#line 2039 "y.tab.cpp"
    break;

  case 48:
#line 402 "spl.y"
        { 
		(yyval.funcDeclaration) = (yyvsp[-3].funcDeclaration); 
		(yyval.funcDeclaration)->setRoutine((yyvsp[-1].routine)); 
	}
#line 2048 "y.tab.cpp"
    break;

  case 49:
#line 410 "spl.y"
        { 
		(yyval.funcDeclaration) = new FuncDeclaration((yyvsp[-3].identifier), (yyvsp[-2].paraList), (yyvsp[0].type)); 
	}
#line 2056 "y.tab.cpp"
    break;

  case 50:
#line 417 "spl.y"
        { 
		(yyval.funcDeclaration) = (yyvsp[-3].funcDeclaration); (yyval.funcDeclaration)->setRoutine((yyvsp[-1].routine)); 
	}
#line 2064 "y.tab.cpp"
    break;

  case 51:
#line 424 "spl.y"
        { 
		(yyval.funcDeclaration) = new FuncDeclaration((yyvsp[-1].identifier), (yyvsp[0].paraList)); 
	}
#line 2072 "y.tab.cpp"
    break;

  case 52:
#line 431 "spl.y"
        { 
		(yyval.paraList) = (yyvsp[-1].paraList); 
	}
#line 2080 "y.tab.cpp"
    break;

  case 53:
#line 435 "spl.y"
        { 
		(yyval.paraList) = new ParaList(); 
	}
#line 2088 "y.tab.cpp"
    break;

  case 54:
#line 442 "spl.y"
        { 
		(yyval.paraList) = (yyvsp[-2].paraList); (yyval.paraList)->push_back((yyvsp[0].parameter)); 
	}
#line 2096 "y.tab.cpp"
    break;

  case 55:
#line 446 "spl.y"
        { 
		(yyval.paraList) = new ParaList(); 
		(yyval.paraList)->push_back((yyvsp[0].parameter)); 
	}
#line 2105 "y.tab.cpp"
    break;

  case 56:
#line 454 "spl.y"
        { 
		(yyval.parameter) = (yyvsp[-2].parameter);
		(yyval.parameter)->setType((yyvsp[0].type));   // ? 
	}
#line 2114 "y.tab.cpp"
    break;

  case 57:
#line 459 "spl.y"
        { 
		(yyval.parameter) = (yyvsp[-2].parameter);
		(yyval.parameter)->setType((yyvsp[0].type));   // ? 
	}
#line 2123 "y.tab.cpp"
    break;

  case 58:
#line 467 "spl.y"
        { 
		(yyval.parameter) = new Parameter((yyvsp[0].nameList), true); 
	}
#line 2131 "y.tab.cpp"
    break;

  case 59:
#line 474 "spl.y"
        { 
		(yyval.parameter) = new Parameter((yyvsp[0].nameList), false); 
	}
#line 2139 "y.tab.cpp"
    break;

  case 60:
#line 481 "spl.y"
        { 
		(yyval.routine) = (yyvsp[-1].routine); 
		(yyval.routine)->setRoutineBody((yyvsp[0].compoundStatement)); 
	}
#line 2148 "y.tab.cpp"
    break;

  case 61:
#line 489 "spl.y"
        { 
		(yyval.compoundStatement) = (yyvsp[0].compoundStatement); 
	}
#line 2156 "y.tab.cpp"
    break;

  case 62:
#line 496 "spl.y"
        { 
		(yyval.compoundStatement) = new CompoundStatement((yyvsp[-1].statementList)); 
	}
#line 2164 "y.tab.cpp"
    break;

  case 63:
#line 503 "spl.y"
        { 
		(yyval.statementList) = (yyvsp[-2].statementList); (yyval.statementList)->push_back((yyvsp[-1].statement)); 
	}
#line 2172 "y.tab.cpp"
    break;

  case 64:
#line 507 "spl.y"
        { 
		(yyval.statementList) = new StatementList(); 
	}
#line 2180 "y.tab.cpp"
    break;

  case 65:
#line 514 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
		(yyval.statement)->setLabel((yyvsp[-2].iVal)); 
	}
#line 2189 "y.tab.cpp"
    break;

  case 66:
#line 519 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
	}
#line 2197 "y.tab.cpp"
    break;

  case 67:
#line 526 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].assignStatement); 
	}
#line 2205 "y.tab.cpp"
    break;

  case 68:
#line 530 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
	}
#line 2213 "y.tab.cpp"
    break;

  case 69:
#line 534 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].compoundStatement); 
	}
#line 2221 "y.tab.cpp"
    break;

  case 70:
#line 538 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].ifStatement); 
	}
#line 2229 "y.tab.cpp"
    break;

  case 71:
#line 542 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].repeatStatement); 
	}
#line 2237 "y.tab.cpp"
    break;

  case 72:
#line 546 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].whileStatement); 
	}
#line 2245 "y.tab.cpp"
    break;

  case 73:
#line 550 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].forStatement); 
	}
#line 2253 "y.tab.cpp"
    break;

  case 74:
#line 554 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].caseStatement); 
	}
#line 2261 "y.tab.cpp"
    break;

  case 75:
#line 558 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].gotoStatement); 
	}
#line 2269 "y.tab.cpp"
    break;

  case 76:
#line 565 "spl.y"
        { 
		(yyval.assignStatement) = new AssignStatement((yyvsp[-2].identifier), (yyvsp[0].expression)); 
	}
#line 2277 "y.tab.cpp"
    break;

  case 77:
#line 569 "spl.y"
        { 
		(yyval.assignStatement) = new AssignStatement((yyvsp[-5].identifier), (yyvsp[-3].expression), (yyvsp[0].expression)); 
	}
#line 2285 "y.tab.cpp"
    break;

  case 78:
#line 573 "spl.y"
        { 
		(yyval.assignStatement) = new AssignStatement((yyvsp[-4].identifier), (yyvsp[-2].identifier), (yyvsp[0].expression)); 
	}
#line 2293 "y.tab.cpp"
    break;

  case 79:
#line 580 "spl.y"
        { 
		(yyval.statement) = new ProcedureCall((yyvsp[0].identifier)); 
	}
#line 2301 "y.tab.cpp"
    break;

  case 80:
#line 584 "spl.y"
        { 
		(yyval.statement) = new ProcedureCall((yyvsp[-3].identifier), (yyvsp[-1].argsList)); 
	}
#line 2309 "y.tab.cpp"
    break;

  case 81:
#line 588 "spl.y"
        { 
		(yyval.statement) = new SysProcedureCall((yyvsp[0].sVal)); 
	}
#line 2317 "y.tab.cpp"
    break;

  case 82:
#line 592 "spl.y"
        { 
		(yyval.statement) = new SysProcedureCall((yyvsp[-3].sVal), (yyvsp[-1].expressionList)); 
	}
#line 2325 "y.tab.cpp"
    break;

  case 83:
#line 596 "spl.y"
        { 
		(yyval.statement) = new SysProcedureCall((yyvsp[-3].sVal), (yyvsp[-1].expression)); 
	}
#line 2333 "y.tab.cpp"
    break;

  case 84:
#line 603 "spl.y"
        { 
		(yyval.expressionList) = (yyvsp[-2].expressionList); 
		(yyval.expressionList)->push_back((yyvsp[0].expression)); 
	}
#line 2342 "y.tab.cpp"
    break;

  case 85:
#line 608 "spl.y"
        { 
		(yyval.expressionList) = new ExpressionList(); 
		(yyval.expressionList)->push_back((yyvsp[0].expression)); 
	}
#line 2351 "y.tab.cpp"
    break;

  case 86:
#line 616 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), ">=", (yyvsp[0].expression)); 
	}
#line 2359 "y.tab.cpp"
    break;

  case 87:
#line 620 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), ">", (yyvsp[0].expression)); 
	}
#line 2367 "y.tab.cpp"
    break;

  case 88:
#line 624 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "<=", (yyvsp[0].expression)); 
	}
#line 2375 "y.tab.cpp"
    break;

  case 89:
#line 628 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "<", (yyvsp[0].expression)); 
	}
#line 2383 "y.tab.cpp"
    break;

  case 90:
#line 632 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "=", (yyvsp[0].expression)); 
	}
#line 2391 "y.tab.cpp"
    break;

  case 91:
#line 636 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "<>", (yyvsp[0].expression)); 
	}
#line 2399 "y.tab.cpp"
    break;

  case 92:
#line 640 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].expression); 
	}
#line 2407 "y.tab.cpp"
    break;

  case 93:
#line 647 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "+", (yyvsp[0].expression)); 
	}
#line 2415 "y.tab.cpp"
    break;

  case 94:
#line 651 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "-", (yyvsp[0].expression)); 
	}
#line 2423 "y.tab.cpp"
    break;

  case 95:
#line 655 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "or", (yyvsp[0].expression)); 
	}
#line 2431 "y.tab.cpp"
    break;

  case 96:
#line 659 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].expression); 
	}
#line 2439 "y.tab.cpp"
    break;

  case 97:
#line 666 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "*", (yyvsp[0].expression)); 
	}
#line 2447 "y.tab.cpp"
    break;

  case 98:
#line 670 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "/", (yyvsp[0].expression)); 
	}
#line 2455 "y.tab.cpp"
    break;

  case 99:
#line 674 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "mod", (yyvsp[0].expression)); 
	}
#line 2463 "y.tab.cpp"
    break;

  case 100:
#line 678 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "and", (yyvsp[0].expression)); 
	}
#line 2471 "y.tab.cpp"
    break;

  case 101:
#line 682 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].expression); 
	}
#line 2479 "y.tab.cpp"
    break;

  case 102:
#line 689 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].identifier); 
	}
#line 2487 "y.tab.cpp"
    break;

  case 103:
#line 693 "spl.y"
        { 
		(yyval.expression) = new FunctionCall((yyvsp[-3].identifier), (yyvsp[-1].argsList)); 
	}
#line 2495 "y.tab.cpp"
    break;

  case 104:
#line 697 "spl.y"
        { 
		(yyval.expression) = new SysFunctionCall(*(yyvsp[0].sVal)); 
	}
#line 2503 "y.tab.cpp"
    break;

  case 105:
#line 701 "spl.y"
        { 
		(yyval.expression) = new SysFunctionCall(*(yyvsp[-3].sVal), (yyvsp[-1].argsList)); 
	}
#line 2511 "y.tab.cpp"
    break;

  case 106:
#line 705 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].constValue); 
	}
#line 2519 "y.tab.cpp"
    break;

  case 107:
#line 709 "spl.y"
        { 
		(yyval.expression) = (yyvsp[-1].expression); 
	}
#line 2527 "y.tab.cpp"
    break;

  case 108:
#line 713 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression(new Boolean(true), "xor", (yyvsp[0].expression)); 
	}
#line 2535 "y.tab.cpp"
    break;

  case 109:
#line 717 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression(new Integer(0), "-", (yyvsp[0].expression)); 
	}
#line 2543 "y.tab.cpp"
    break;

  case 110:
#line 721 "spl.y"
        { 
		(yyval.expression) = new ArrayReference((yyvsp[-3].identifier), (yyvsp[-1].expression)); 
	}
#line 2551 "y.tab.cpp"
    break;

  case 111:
#line 725 "spl.y"
        { 
		(yyval.expression) = new RecordReference((yyvsp[-2].identifier), (yyvsp[0].identifier)); 
	}
#line 2559 "y.tab.cpp"
    break;

  case 112:
#line 732 "spl.y"
        { 
		(yyval.argsList) = (yyvsp[-2].argsList); (yyval.argsList)->push_back((yyvsp[0].expression)); 
	}
#line 2567 "y.tab.cpp"
    break;

  case 113:
#line 736 "spl.y"
        { 
		(yyval.argsList) = new ArgsList(); (yyval.argsList)->push_back((yyvsp[0].expression)); 
	}
#line 2575 "y.tab.cpp"
    break;

  case 114:
#line 743 "spl.y"
        { 
		(yyval.ifStatement) = new IfStatement((yyvsp[-3].expression), (yyvsp[-1].statement), (yyvsp[0].statement)); 
	}
#line 2583 "y.tab.cpp"
    break;

  case 115:
#line 750 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
	}
#line 2591 "y.tab.cpp"
    break;

  case 116:
#line 754 "spl.y"
        { 
		(yyval.statement) = nullptr; 
	}
#line 2599 "y.tab.cpp"
    break;

  case 117:
#line 761 "spl.y"
        { 
		(yyval.repeatStatement) = new RepeatStatement((yyvsp[0].expression), (yyvsp[-2].statementList)); 
	}
#line 2607 "y.tab.cpp"
    break;

  case 118:
#line 768 "spl.y"
        { 
		(yyval.whileStatement) = new WhileStatement((yyvsp[-2].expression), (yyvsp[0].statement)); 
	}
#line 2615 "y.tab.cpp"
    break;

  case 119:
#line 775 "spl.y"
        { 
		(yyval.forStatement) = new ForStatement((yyvsp[-6].identifier), (yyvsp[-4].expression), (yyvsp[-3].bVal), (yyvsp[-2].expression), (yyvsp[0].statement)); 
	}
#line 2623 "y.tab.cpp"
    break;

  case 120:
#line 782 "spl.y"
        { 
		(yyval.bVal) = true; 
	}
#line 2631 "y.tab.cpp"
    break;

  case 121:
#line 786 "spl.y"
        { 
		(yyval.bVal) = false; 
	}
#line 2639 "y.tab.cpp"
    break;

  case 122:
#line 793 "spl.y"
        { 
		(yyval.caseStatement) = new CaseStatement((yyvsp[-3].expression), (yyvsp[-1].caseExprList));
	}
#line 2647 "y.tab.cpp"
    break;

  case 123:
#line 800 "spl.y"
        { 
		(yyval.caseExprList) = (yyvsp[-1].caseExprList); 
		(yyval.caseExprList)->push_back((yyvsp[0].caseExpression)); 
	}
#line 2656 "y.tab.cpp"
    break;

  case 124:
#line 805 "spl.y"
        { 
		(yyval.caseExprList) = new CaseExprList(); 
		(yyval.caseExprList)->push_back((yyvsp[0].caseExpression)); 
	}
#line 2665 "y.tab.cpp"
    break;

  case 125:
#line 813 "spl.y"
        { 
		(yyval.caseExpression) = new CaseExpression((yyvsp[-3].constValue), (yyvsp[-1].statement)); 
	}
#line 2673 "y.tab.cpp"
    break;

  case 126:
#line 817 "spl.y"
        { 
		(yyval.caseExpression) = new CaseExpression((yyvsp[-3].identifier), (yyvsp[-1].statement)); 
	}
#line 2681 "y.tab.cpp"
    break;

  case 127:
#line 824 "spl.y"
        { 
		(yyval.gotoStatement) = new GotoStatement((yyvsp[0].iVal)); 
	}
#line 2689 "y.tab.cpp"
    break;


#line 2693 "y.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 829 "spl.y"

