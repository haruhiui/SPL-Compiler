/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

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

void yyerror(const char *s) { 
	std::printf("Error: %s\n", s);
	std::exit(1); 
}

int yylex(void);

Program *root;

#line 87 "y.tab.cpp"

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
    UNEQUAL = 266,
    NOT = 267,
    PLUS = 268,
    MINUS = 269,
    GE = 270,
    GT = 271,
    LE = 272,
    LT = 273,
    EQUAL = 274,
    ASSIGN = 275,
    MOD = 276,
    DOTDOT = 277,
    SEMI = 278,
    AND = 279,
    ARRAY = 280,
    TOKEN_BEGIN = 281,
    CASE = 282,
    CONST = 283,
    DIV = 284,
    DO = 285,
    DOWNTO = 286,
    ELSE = 287,
    END = 288,
    FOR = 289,
    FUNCTION = 290,
    GOTO = 291,
    IF = 292,
    OF = 293,
    OR = 294,
    PROCEDURE = 295,
    PROGRAM = 296,
    RECORD = 297,
    REPEAT = 298,
    THEN = 299,
    TO = 300,
    TYPE = 301,
    UNTIL = 302,
    VAR = 303,
    WHILE = 304,
    INTEGER = 305,
    IDENTIFIER = 306,
    SYS_CON = 307,
    SYS_FUNCT = 308,
    SYS_PROC = 309,
    SYS_TYPE = 310,
    READ = 311,
    STRING = 312,
    REAL = 313,
    CHAR = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "spl.y"

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
	CompoundStatement *compoundStatement;

#line 258 "y.tab.cpp"

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
#define YYLAST   414

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260

#define YYUNDEFTOK  2
#define YYMAXUTOK   314


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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   141,   149,   156,   164,   171,   176,   182,
     187,   195,   199,   203,   207,   219,   224,   230,   235,   243,
     250,   254,   258,   265,   278,   282,   286,   290,   294,   298,
     305,   312,   319,   323,   330,   337,   341,   348,   353,   359,
     363,   370,   377,   381,   386,   391,   397,   403,   410,   417,
     424,   431,   436,   442,   446,   454,   458,   465,   472,   479,
     487,   494,   501,   506,   512,   517,   524,   528,   532,   536,
     540,   544,   548,   552,   556,   563,   567,   571,   578,   582,
     586,   590,   594,   601,   606,   613,   617,   621,   625,   629,
     633,   637,   644,   648,   652,   656,   663,   667,   671,   675,
     679,   686,   690,   694,   698,   702,   706,   710,   714,   718,
     722,   729,   733,   740,   747,   752,   758,   765,   772,   779,
     783,   790,   797,   801,   808,   812,   819
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LP", "RP", "LB", "RB", "DOT", "COMMA",
  "COLON", "MUL", "UNEQUAL", "NOT", "PLUS", "MINUS", "GE", "GT", "LE",
  "LT", "EQUAL", "ASSIGN", "MOD", "DOTDOT", "SEMI", "AND", "ARRAY",
  "TOKEN_BEGIN", "CASE", "CONST", "DIV", "DO", "DOWNTO", "ELSE", "END",
  "FOR", "FUNCTION", "GOTO", "IF", "OF", "OR", "PROCEDURE", "PROGRAM",
  "RECORD", "REPEAT", "THEN", "TO", "TYPE", "UNTIL", "VAR", "WHILE",
  "INTEGER", "IDENTIFIER", "SYS_CON", "SYS_FUNCT", "SYS_PROC", "SYS_TYPE",
  "READ", "STRING", "REAL", "CHAR", "$accept", "name", "program",
  "program_head", "routine", "routine_head", "const_part",
  "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_definition", "type_decl", "simple_type_decl", "array_type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "name_list",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "sub_routine", "routine_body", "compound_stmt", "stmt_list", "stmt",
  "non_label_stmt", "assign_stmt", "proc_stmt", "expression_list",
  "expression", "expr", "term", "factor", "args_list", "if_stmt",
  "else_clause", "repeat_stmt", "while_stmt", "for_stmt", "direction",
  "case_stmt", "case_expr_list", "case_expr", "goto_stmt", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
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
       3,   -19,    53,    35,    72,  -149,    45,    91,    77,    59,
    -149,  -149,    87,    45,  -149,  -149,  -149,  -149,    45,    69,
     134,    99,   236,   110,    45,  -149,    45,     6,  -149,  -149,
    -149,  -149,   109,   134,    31,  -149,    45,    80,    31,  -149,
      31,   142,   141,   158,   133,  -149,   140,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,   187,  -149,  -149,    14,
      45,  -149,    45,    45,     6,  -149,   144,  -149,   146,  -149,
     151,    31,    31,    31,   178,   221,  -149,    54,    48,   131,
    -149,   162,  -149,    20,   257,   333,   304,    31,    31,    31,
      31,    45,    31,  -149,    45,   134,   189,    45,  -149,   174,
     175,   176,  -149,  -149,  -149,    45,   187,  -149,   197,   197,
    -149,  -149,    35,    35,  -149,   160,  -149,  -149,    31,    31,
      31,    45,    31,    31,    31,    31,    31,    31,   159,    31,
      31,    31,    31,    31,    31,    31,    31,   283,    31,   283,
    -149,    25,   389,   199,   389,    51,   366,   184,   389,   116,
     185,   107,   -25,  -149,    67,    45,   134,  -149,  -149,   183,
     -38,   204,  -149,    77,   198,   200,  -149,   135,   164,   380,
    -149,    48,    48,    48,    48,    48,    48,   211,   218,    76,
    -149,   131,   131,   131,  -149,  -149,  -149,  -149,   237,   208,
     389,  -149,  -149,    31,  -149,  -149,    31,   210,    31,  -149,
     -10,   225,  -149,  -149,   187,  -149,  -149,  -149,    45,   235,
       5,  -149,   238,   240,   107,  -149,  -149,  -149,  -149,  -149,
    -149,   283,   283,  -149,  -149,  -149,  -149,    31,   283,  -149,
     389,   389,    31,   389,   134,  -149,   212,   234,   235,  -149,
     -38,   107,   107,  -149,   241,   242,   350,  -149,   389,  -149,
     187,  -149,  -149,  -149,  -149,  -149,  -149,   283,  -149,  -149
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     8,     0,     1,     0,     0,     0,    16,
       4,     2,     0,     7,     3,    63,     5,    60,     0,    38,
       0,     0,     0,     0,    15,    18,     0,    46,    11,    14,
      12,    13,     0,     0,     0,    61,     0,     0,     0,    63,
       0,     0,    80,     0,    78,    68,     0,    65,    66,    67,
      69,    70,    71,    72,    73,    74,     0,    17,    36,     0,
      37,    40,     0,     0,     6,    44,     0,    45,     0,    10,
       0,     0,     0,     0,   103,   101,   105,     0,    91,    95,
     100,     0,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,    23,    24,
       0,     0,    20,    21,    22,     0,     0,    39,    52,    52,
      42,    43,     8,     8,     9,     0,   107,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    84,     0,   112,     0,     0,     0,    75,     0,
       0,     0,     0,    33,     0,     0,     0,    19,    35,     0,
       0,     0,    50,     0,     0,     0,   106,     0,     0,     0,
     110,    90,    85,    86,    87,    88,    89,     0,     0,     0,
     123,    92,    93,    94,    96,    98,    99,    97,     0,   115,
     116,   117,    81,     0,    82,    79,     0,     0,     0,    25,
       0,     0,    31,    32,     0,    29,    26,    41,     0,    58,
       0,    54,     0,     0,     0,    59,    47,    49,   104,   102,
     109,     0,     0,   121,   122,   120,   119,     0,     0,   113,
      83,   111,     0,    77,     0,    27,     0,     0,    57,    51,
       0,     0,     0,    48,     0,     0,     0,   114,    76,    28,
       0,    34,    53,    55,    56,   125,   124,     0,    30,   118
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,    -6,  -149,  -149,  -149,   255,  -149,  -149,    -9,  -149,
    -149,   243,  -100,  -148,  -149,  -149,  -149,   108,   -92,  -149,
    -149,   201,  -149,   195,  -149,   202,  -149,   165,  -149,    36,
    -149,  -149,   167,   112,    -7,   232,  -120,   191,  -149,  -149,
    -149,   -13,   287,    58,   -21,  -104,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,   102,  -149
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    75,     2,     3,     7,   163,     9,    13,    76,    19,
      24,    25,   101,   102,   103,   104,   152,   153,    59,    27,
      60,    61,    64,    65,    66,    67,    68,   161,   210,   211,
     212,   213,   164,    16,    45,    22,    46,    47,    48,    49,
     141,   144,    78,    79,    80,   145,    50,   229,    51,    52,
      53,   227,    54,   179,   180,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    17,   149,   201,   234,   154,   159,    21,   202,   239,
     208,    32,    23,    11,   167,   168,    44,   189,    23,   191,
      58,    77,   105,   106,    70,    83,    11,    85,   240,   192,
      81,   122,     4,   193,    71,   123,   124,   125,   126,   127,
      28,    62,    29,    72,     1,    73,    63,   100,    30,    31,
      99,   116,   117,     5,    58,   195,   108,   109,   115,   196,
     154,   129,   130,     6,   137,   122,   243,   143,   209,   123,
     124,   125,   126,   127,   142,   105,   204,   146,    44,   148,
      44,    28,    11,    29,    74,   147,   150,   131,    58,    30,
      31,    58,   128,   253,   254,    10,    11,   100,    14,   158,
      99,   244,   245,    15,   237,    18,    20,   169,   247,   223,
      94,   184,   185,   186,   187,   170,   238,    26,    33,   178,
     199,    95,   177,   188,   105,   190,    28,    11,    29,    56,
      82,    44,    69,    44,    30,    31,    89,   259,    90,   218,
      91,   132,   100,   196,    87,    99,    58,   206,   209,   205,
     258,    86,   133,    92,    58,   134,    17,    28,    11,    29,
     135,    88,    98,    93,   166,    30,    31,   112,   219,   113,
     178,   122,   196,   177,   114,   123,   124,   125,   126,   127,
     230,   118,   136,   231,    28,   233,    29,   181,   182,   183,
      94,   235,    30,    31,   151,   100,   155,   156,    99,   157,
     160,    95,    58,   194,   198,   100,   207,   200,    99,    28,
      11,    29,    96,   214,   246,    44,    44,    30,    31,   248,
     221,   216,    44,   217,   119,   249,   120,   222,   121,    97,
     232,   236,   100,   100,    58,    99,    99,    28,    11,    29,
     228,   100,    98,   105,    99,    30,    31,   241,   122,   242,
     250,    44,   123,   124,   125,   126,   127,   251,     8,   110,
     203,   107,    15,    34,   255,   256,   111,    57,   225,    35,
      36,    84,    37,    38,   162,   215,   252,   140,     0,    39,
     165,   224,   226,    15,    34,    40,    41,    11,     0,     0,
      42,    36,    43,    37,    38,     0,     0,     0,     0,     0,
      39,     0,     0,     0,   138,     0,    40,    41,    11,    15,
      34,    42,     0,    43,     0,     0,     0,    36,     0,    37,
      38,     0,     0,     0,     0,     0,    39,     0,     0,     0,
      15,    34,    40,    41,    11,     0,     0,    42,    36,    43,
      37,    38,     0,     0,   122,     0,     0,    39,   123,   124,
     125,   126,   127,    40,     0,    11,     0,     0,    42,     0,
      43,   122,     0,   139,     0,   123,   124,   125,   126,   127,
       0,     0,   197,     0,     0,     0,     0,   122,     0,     0,
     257,   123,   124,   125,   126,   127,   220,     0,     0,     0,
       0,   122,     0,     0,     0,   123,   124,   125,   126,   127,
     122,     0,     0,     0,   123,   124,   125,   126,   127,   171,
     172,   173,   174,   175,   176
};

static const yytype_int16 yycheck[] =
{
       6,     8,    94,   151,    14,    97,   106,    13,    33,     4,
      48,    20,    18,    51,   118,   119,    22,   137,    24,   139,
      26,    34,     8,     9,    33,    38,    51,    40,    23,     4,
      36,    11,    51,     8,     3,    15,    16,    17,    18,    19,
      50,    35,    52,    12,    41,    14,    40,    56,    58,    59,
      56,    72,    73,     0,    60,     4,    62,    63,    71,     8,
     152,    13,    14,    28,    44,    11,   214,    88,   160,    15,
      16,    17,    18,    19,    87,     8,     9,    90,    84,    92,
      86,    50,    51,    52,    53,    91,    95,    39,    94,    58,
      59,    97,    38,   241,   242,    23,    51,   106,     7,   105,
     106,   221,   222,    26,   204,    46,    19,   120,   228,    33,
       3,   132,   133,   134,   135,   121,   208,    48,    19,   128,
       4,    14,   128,   136,     8,   138,    50,    51,    52,    19,
      50,   137,    23,   139,    58,    59,     3,   257,     5,     4,
       7,    10,   151,     8,     3,   151,   152,   156,   240,   155,
     250,     9,    21,    20,   160,    24,   163,    50,    51,    52,
      29,     3,    55,    23,     4,    58,    59,    23,     4,    23,
     179,    11,     8,   179,    23,    15,    16,    17,    18,    19,
     193,     3,    20,   196,    50,   198,    52,   129,   130,   131,
       3,   200,    58,    59,     5,   204,    22,    22,   204,    23,
       3,    14,   208,     4,    20,   214,    23,    22,   214,    50,
      51,    52,    25,     9,   227,   221,   222,    58,    59,   232,
       9,    23,   228,    23,     3,   234,     5,     9,     7,    42,
      20,     6,   241,   242,   240,   241,   242,    50,    51,    52,
      32,   250,    55,     8,   250,    58,    59,     9,    11,     9,
      38,   257,    15,    16,    17,    18,    19,    23,     3,    64,
     152,    60,    26,    27,    23,    23,    64,    24,    31,    33,
      34,    39,    36,    37,   109,   163,   240,    86,    -1,    43,
     113,   179,    45,    26,    27,    49,    50,    51,    -1,    -1,
      54,    34,    56,    36,    37,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,    -1,    49,    50,    51,    26,
      27,    54,    -1,    56,    -1,    -1,    -1,    34,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      26,    27,    49,    50,    51,    -1,    -1,    54,    34,    56,
      36,    37,    -1,    -1,    11,    -1,    -1,    43,    15,    16,
      17,    18,    19,    49,    -1,    51,    -1,    -1,    54,    -1,
      56,    11,    -1,    30,    -1,    15,    16,    17,    18,    19,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      30,    15,    16,    17,    18,    19,     6,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,   122,
     123,   124,   125,   126,   127
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    62,    63,    51,     0,    28,    64,    65,    66,
      23,    51,    61,    67,     7,    26,    93,    94,    46,    69,
      19,    61,    95,    61,    70,    71,    48,    79,    50,    52,
      58,    59,    68,    19,    27,    33,    34,    36,    37,    43,
      49,    50,    54,    56,    61,    94,    96,    97,    98,    99,
     106,   108,   109,   110,   112,   115,    19,    71,    61,    78,
      80,    81,    35,    40,    82,    83,    84,    85,    86,    23,
      68,     3,    12,    14,    53,    61,    68,   101,   102,   103,
     104,    61,    50,   101,    95,   101,     9,     3,     3,     3,
       5,     7,    20,    23,     3,    14,    25,    42,    55,    61,
      68,    72,    73,    74,    75,     8,     9,    81,    61,    61,
      83,    85,    23,    23,    23,   101,   104,   104,     3,     3,
       5,     7,    11,    15,    16,    17,    18,    19,    38,    13,
      14,    39,    10,    21,    24,    29,    20,    44,    47,    30,
      97,   100,   101,   104,   101,   105,   101,    61,   101,    78,
      68,     5,    76,    77,    78,    22,    22,    23,    61,    72,
       3,    87,    87,    65,    92,    92,     4,   105,   105,   101,
      61,   102,   102,   102,   102,   102,   102,    61,    68,   113,
     114,   103,   103,   103,   104,   104,   104,   104,   101,    96,
     101,    96,     4,     8,     4,     4,     8,     6,    20,     4,
      22,    73,    33,    77,     9,    61,    68,    23,    48,    78,
      88,    89,    90,    91,     9,    93,    23,    23,     4,     4,
       6,     9,     9,    33,   114,    31,    45,   111,    32,   107,
     101,   101,    20,   101,    14,    68,     6,    72,    78,     4,
      23,     9,     9,    73,    96,    96,   101,    96,   101,    68,
      38,    23,    89,    73,    73,    23,    23,    30,    72,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    65,    66,    66,    67,
      67,    68,    68,    68,    68,    69,    69,    70,    70,    71,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      74,    75,    76,    76,    77,    78,    78,    79,    79,    80,
      80,    81,    82,    82,    82,    82,    82,    83,    84,    85,
      86,    87,    87,    88,    88,    89,    89,    90,    91,    92,
      93,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
      99,    99,    99,   100,   100,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   103,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   105,   105,   106,   107,   107,   108,   109,   110,   111,
     111,   112,   113,   113,   114,   114,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     4,     2,     0,     5,
       4,     1,     1,     1,     1,     2,     0,     2,     1,     4,
       1,     1,     1,     1,     1,     3,     3,     4,     5,     3,
       6,     3,     2,     1,     4,     3,     1,     2,     0,     2,
       1,     4,     2,     2,     1,     1,     0,     4,     5,     4,
       3,     3,     0,     3,     1,     3,     3,     2,     1,     2,
       1,     3,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     6,     5,     1,     4,
       1,     4,     4,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     1,     4,     1,     4,     1,     3,     2,     2,     4,
       3,     3,     1,     5,     2,     0,     4,     4,     8,     1,
       1,     5,     2,     1,     4,     4,     2
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
      int yyn = yypact[+*yyssp];
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
#line 135 "spl.y"
        { 
		(yyval.identifier) = new Identifier((yyvsp[0].sVal)); 
	}
#line 1654 "y.tab.cpp"
    break;

  case 3:
#line 142 "spl.y"
        { 
		(yyval.program) = new Program((yyvsp[-2].sVal), (yyvsp[-1].routine)); 
		root = (yyval.program); 
	}
#line 1663 "y.tab.cpp"
    break;

  case 4:
#line 150 "spl.y"
        { 
		(yyval.sVal) = (yyvsp[-1].sVal); 
	}
#line 1671 "y.tab.cpp"
    break;

  case 5:
#line 157 "spl.y"
        { 
		(yyval.routine) = (yyvsp[-1].routine); 
		(yyval.routine)->setRoutineBody((yyvsp[0].compoundStatement)); 
	}
#line 1680 "y.tab.cpp"
    break;

  case 6:
#line 165 "spl.y"
        { 
		(yyval.routine) = new Routine((yyvsp[-3].constDeclList), (yyvsp[-2].typeDeclList), (yyvsp[-1].varDeclList), (yyvsp[0].routineList)); 
	}
#line 1688 "y.tab.cpp"
    break;

  case 7:
#line 172 "spl.y"
        { 
		(yyval.constDeclList) = (yyvsp[0].constDeclList); 
	}
#line 1696 "y.tab.cpp"
    break;

  case 8:
#line 176 "spl.y"
        { 
		(yyval.constDeclList) = new ConstDeclList(); 
	}
#line 1704 "y.tab.cpp"
    break;

  case 9:
#line 183 "spl.y"
        { 
		(yyval.constDeclList) = (yyvsp[-4].constDeclList); 
		(yyval.constDeclList)->push_back(new ConstDeclaration((yyvsp[-3].identifier), (yyvsp[-1].constValue))); 
	}
#line 1713 "y.tab.cpp"
    break;

  case 10:
#line 188 "spl.y"
        { 
		(yyval.constDeclList) = new ConstDeclList(); 
		(yyval.constDeclList)->push_back(new ConstDeclaration((yyvsp[-3].identifier), (yyvsp[-1].constValue))); 
	}
#line 1722 "y.tab.cpp"
    break;

  case 11:
#line 196 "spl.y"
        { 
		(yyval.constValue) = new Integer((yyvsp[0].iVal)); 
	}
#line 1730 "y.tab.cpp"
    break;

  case 12:
#line 200 "spl.y"
        { 
		(yyval.constValue) = new Real((yyvsp[0].dVal)); 
	}
#line 1738 "y.tab.cpp"
    break;

  case 13:
#line 204 "spl.y"
        { 
		(yyval.constValue) = new Char((yyvsp[0].cVal)); 
	}
#line 1746 "y.tab.cpp"
    break;

  case 14:
#line 208 "spl.y"
        {
		if (*(yyvsp[0].sVal) == "true")
			(yyval.constValue) = new Boolean(true);
		else if(*(yyvsp[0].sVal) == "false")
			(yyval.constValue) = new Boolean(false);
		else
			(yyval.constValue) = new Integer(0x7FFFFFFF);
	}
#line 1759 "y.tab.cpp"
    break;

  case 15:
#line 220 "spl.y"
        { 
		(yyval.typeDeclList) = (yyvsp[0].typeDeclList); 
	}
#line 1767 "y.tab.cpp"
    break;

  case 16:
#line 224 "spl.y"
        { 
		(yyval.typeDeclList) = new TypeDeclList(); 
	}
#line 1775 "y.tab.cpp"
    break;

  case 17:
#line 231 "spl.y"
        { 
		(yyval.typeDeclList) = (yyvsp[-1].typeDeclList); 
		(yyval.typeDeclList)->push_back((yyvsp[0].typeDeclaration)); 
	}
#line 1784 "y.tab.cpp"
    break;

  case 18:
#line 236 "spl.y"
        { 
		(yyval.typeDeclList) = new TypeDeclList(); 
		(yyval.typeDeclList)->push_back((yyvsp[0].typeDeclaration)); 
	}
#line 1793 "y.tab.cpp"
    break;

  case 19:
#line 244 "spl.y"
        { 
		(yyval.typeDeclaration) = new TypeDeclaration((yyvsp[-3].identifier), (yyvsp[-1].type)); 
	}
#line 1801 "y.tab.cpp"
    break;

  case 20:
#line 251 "spl.y"
        { 
		(yyval.type) = (yyvsp[0].type); 
	}
#line 1809 "y.tab.cpp"
    break;

  case 21:
#line 255 "spl.y"
        { 
		(yyval.type) = (yyvsp[0].type); 
	}
#line 1817 "y.tab.cpp"
    break;

  case 22:
#line 259 "spl.y"
        { 
		(yyval.type) = (yyvsp[0].type); 
	}
#line 1825 "y.tab.cpp"
    break;

  case 23:
#line 266 "spl.y"
        {
		if(*(yyvsp[0].sVal) == "integer")
			(yyval.type) = new AstType(SPL_INTEGER);
		else if(*(yyvsp[0].sVal) == "boolean")
			(yyval.type) = new AstType(SPL_BOOLEAN);
		else if(*(yyvsp[0].sVal) == "real")
			(yyval.type) = new AstType(SPL_REAL);
		else if(*(yyvsp[0].sVal) == "char")
			(yyval.type) = new AstType(SPL_CHAR);
		else
			cout << "UNKNOWN SYS_TYPE" << endl;
	}
#line 1842 "y.tab.cpp"
    break;

  case 24:
#line 279 "spl.y"
        { 
		(yyval.type) = new AstType((yyvsp[0].identifier)); 
	}
#line 1850 "y.tab.cpp"
    break;

  case 25:
#line 283 "spl.y"
        { 
		(yyval.type) = new AstType(new EnumType((yyvsp[-1].nameList))); 
	}
#line 1858 "y.tab.cpp"
    break;

  case 26:
#line 287 "spl.y"
        { 
		(yyval.type) = new AstType(new ConstRangeType((yyvsp[-2].constValue), (yyvsp[0].constValue))); 
	}
#line 1866 "y.tab.cpp"
    break;

  case 27:
#line 291 "spl.y"
        { 
		(yyval.type) = new AstType(new ConstRangeType(-*(yyvsp[-2].constValue), (yyvsp[0].constValue))); 
	}
#line 1874 "y.tab.cpp"
    break;

  case 28:
#line 295 "spl.y"
        { 
		(yyval.type) = new AstType(new ConstRangeType(-*(yyvsp[-3].constValue), -*(yyvsp[0].constValue))); 
	}
#line 1882 "y.tab.cpp"
    break;

  case 29:
#line 299 "spl.y"
        { 
		(yyval.type) = new AstType(new EnumRangeType((yyvsp[-2].identifier), (yyvsp[0].identifier))); 
	}
#line 1890 "y.tab.cpp"
    break;

  case 30:
#line 306 "spl.y"
        { 
		(yyval.type) = new AstType(new AstArrayType((yyvsp[0].type), (yyvsp[-3].type))); 
	}
#line 1898 "y.tab.cpp"
    break;

  case 31:
#line 313 "spl.y"
        { 
		(yyval.type) = new AstType(new RecordType((yyvsp[-1].fieldList))); 
	}
#line 1906 "y.tab.cpp"
    break;

  case 32:
#line 320 "spl.y"
        { 
		(yyval.fieldList) = (yyvsp[-1].fieldList); (yyval.fieldList)->push_back((yyvsp[0].fieldDeclaration)); 
	}
#line 1914 "y.tab.cpp"
    break;

  case 33:
#line 324 "spl.y"
        { 
		(yyval.fieldList) = new FieldList(); (yyval.fieldList)->push_back((yyvsp[0].fieldDeclaration)); 
	}
#line 1922 "y.tab.cpp"
    break;

  case 34:
#line 331 "spl.y"
        { 
		(yyval.fieldDeclaration) = new FieldDeclaration((yyvsp[-3].nameList), (yyvsp[-1].type)); 
	}
#line 1930 "y.tab.cpp"
    break;

  case 35:
#line 338 "spl.y"
        { 
		(yyval.nameList) = (yyvsp[-2].nameList); (yyval.nameList)->push_back((yyvsp[0].identifier)); 
	}
#line 1938 "y.tab.cpp"
    break;

  case 36:
#line 342 "spl.y"
        { 
		(yyval.nameList) = new NameList(); (yyval.nameList)->push_back((yyvsp[0].identifier)); 
	}
#line 1946 "y.tab.cpp"
    break;

  case 37:
#line 349 "spl.y"
        { 
		(yyval.varDeclList) = (yyvsp[0].varDeclList); 
	}
#line 1954 "y.tab.cpp"
    break;

  case 38:
#line 353 "spl.y"
        { 
		(yyval.varDeclList) = new VarDeclList(); 
	}
#line 1962 "y.tab.cpp"
    break;

  case 39:
#line 360 "spl.y"
        { 
		(yyval.varDeclList) = (yyvsp[-1].varDeclList); (yyval.varDeclList)->push_back((yyvsp[0].varDeclaration)); 
	}
#line 1970 "y.tab.cpp"
    break;

  case 40:
#line 364 "spl.y"
        { 
		(yyval.varDeclList) = new VarDeclList(); (yyval.varDeclList)->push_back((yyvsp[0].varDeclaration)); 
	}
#line 1978 "y.tab.cpp"
    break;

  case 41:
#line 371 "spl.y"
        { 
		(yyval.varDeclaration) = new VarDeclaration((yyvsp[-3].nameList), (yyvsp[-1].type)); 
	}
#line 1986 "y.tab.cpp"
    break;

  case 42:
#line 378 "spl.y"
        { 
		(yyval.routineList) = (yyvsp[-1].routineList); (yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 1994 "y.tab.cpp"
    break;

  case 43:
#line 382 "spl.y"
        { 
		(yyval.routineList) = (yyvsp[-1].routineList); 
		(yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 2003 "y.tab.cpp"
    break;

  case 44:
#line 387 "spl.y"
        { 
		(yyval.routineList) = new RoutineList(); 
		(yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 2012 "y.tab.cpp"
    break;

  case 45:
#line 392 "spl.y"
        { 
		(yyval.routineList) = new RoutineList(); 
		(yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 2021 "y.tab.cpp"
    break;

  case 46:
#line 397 "spl.y"
        { 
		(yyval.routineList) = new RoutineList(); 
	}
#line 2029 "y.tab.cpp"
    break;

  case 47:
#line 404 "spl.y"
        { 
		(yyval.funcDeclaration) = (yyvsp[-3].funcDeclaration); (yyval.funcDeclaration)->setRoutine((yyvsp[-1].routine)); 
	}
#line 2037 "y.tab.cpp"
    break;

  case 48:
#line 411 "spl.y"
        { 
		(yyval.funcDeclaration) = new FuncDeclaration((yyvsp[-3].identifier), (yyvsp[-2].paraList), (yyvsp[0].type)); 
	}
#line 2045 "y.tab.cpp"
    break;

  case 49:
#line 418 "spl.y"
        { 
		(yyval.funcDeclaration) = (yyvsp[-3].funcDeclaration); (yyval.funcDeclaration)->setRoutine((yyvsp[-1].routine)); 
	}
#line 2053 "y.tab.cpp"
    break;

  case 50:
#line 425 "spl.y"
        { 
		(yyval.funcDeclaration) = new FuncDeclaration((yyvsp[-1].identifier), (yyvsp[0].paraList)); 
	}
#line 2061 "y.tab.cpp"
    break;

  case 51:
#line 432 "spl.y"
        { 
		(yyval.paraList) = (yyvsp[-1].paraList); 
	}
#line 2069 "y.tab.cpp"
    break;

  case 52:
#line 436 "spl.y"
        { 
		(yyval.paraList) = new ParaList(); 
	}
#line 2077 "y.tab.cpp"
    break;

  case 53:
#line 443 "spl.y"
        { 
		(yyval.paraList) = (yyvsp[-2].paraList); (yyval.paraList)->push_back((yyvsp[0].parameter)); 
	}
#line 2085 "y.tab.cpp"
    break;

  case 54:
#line 447 "spl.y"
        { 
		(yyval.paraList) = new ParaList(); 
		(yyval.paraList)->push_back((yyvsp[0].parameter)); 
	}
#line 2094 "y.tab.cpp"
    break;

  case 55:
#line 455 "spl.y"
        { 
		(yyval.parameter) = (yyvsp[-2].parameter), (yyval.parameter)->setType((yyvsp[0].type));   // ? 
	}
#line 2102 "y.tab.cpp"
    break;

  case 56:
#line 459 "spl.y"
        { 
		(yyval.parameter) = (yyvsp[-2].parameter), (yyval.parameter)->setType((yyvsp[0].type));   // ? 
	}
#line 2110 "y.tab.cpp"
    break;

  case 57:
#line 466 "spl.y"
        { 
		(yyval.parameter) = new Parameter((yyvsp[0].nameList), true); 
	}
#line 2118 "y.tab.cpp"
    break;

  case 58:
#line 473 "spl.y"
        { 
		(yyval.parameter) = new Parameter((yyvsp[0].nameList), false); 
	}
#line 2126 "y.tab.cpp"
    break;

  case 59:
#line 480 "spl.y"
        { 
		(yyval.routine) = (yyvsp[-1].routine); 
		(yyval.routine)->setRoutineBody((yyvsp[0].compoundStatement)); 
	}
#line 2135 "y.tab.cpp"
    break;

  case 60:
#line 488 "spl.y"
        { 
		(yyval.compoundStatement) = (yyvsp[0].compoundStatement); 
	}
#line 2143 "y.tab.cpp"
    break;

  case 61:
#line 495 "spl.y"
        { 
		(yyval.compoundStatement) = new CompoundStatement((yyvsp[-1].statementList)); 
	}
#line 2151 "y.tab.cpp"
    break;

  case 62:
#line 502 "spl.y"
        { 
		(yyval.statementList) = (yyvsp[-2].statementList); (yyval.statementList)->push_back((yyvsp[-1].statement)); 
	}
#line 2159 "y.tab.cpp"
    break;

  case 63:
#line 506 "spl.y"
        { 
		(yyval.statementList) = new StatementList(); 
	}
#line 2167 "y.tab.cpp"
    break;

  case 64:
#line 513 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
		(yyval.statement)->setLabel((yyvsp[-2].iVal)); 
	}
#line 2176 "y.tab.cpp"
    break;

  case 65:
#line 518 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
	}
#line 2184 "y.tab.cpp"
    break;

  case 66:
#line 525 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].assignStatement); 
	}
#line 2192 "y.tab.cpp"
    break;

  case 67:
#line 529 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
	}
#line 2200 "y.tab.cpp"
    break;

  case 68:
#line 533 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].compoundStatement); 
	}
#line 2208 "y.tab.cpp"
    break;

  case 69:
#line 537 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].ifStatement); 
	}
#line 2216 "y.tab.cpp"
    break;

  case 70:
#line 541 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].repeatStatement); 
	}
#line 2224 "y.tab.cpp"
    break;

  case 71:
#line 545 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].whileStatement); 
	}
#line 2232 "y.tab.cpp"
    break;

  case 72:
#line 549 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].forStatement); 
	}
#line 2240 "y.tab.cpp"
    break;

  case 73:
#line 553 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].caseStatement); 
	}
#line 2248 "y.tab.cpp"
    break;

  case 74:
#line 557 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].gotoStatement); 
	}
#line 2256 "y.tab.cpp"
    break;

  case 75:
#line 564 "spl.y"
        { 
		(yyval.assignStatement) = new AssignStatement((yyvsp[-2].identifier), (yyvsp[0].expression)); 
	}
#line 2264 "y.tab.cpp"
    break;

  case 76:
#line 568 "spl.y"
        { 
		(yyval.assignStatement) = new AssignStatement((yyvsp[-5].identifier), (yyvsp[-3].expression), (yyvsp[0].expression)); 
	}
#line 2272 "y.tab.cpp"
    break;

  case 77:
#line 572 "spl.y"
        { 
		(yyval.assignStatement) = new AssignStatement((yyvsp[-4].identifier), (yyvsp[-2].identifier), (yyvsp[0].expression)); 
	}
#line 2280 "y.tab.cpp"
    break;

  case 78:
#line 579 "spl.y"
        { 
		(yyval.statement) = new ProcedureCall((yyvsp[0].identifier)); 
	}
#line 2288 "y.tab.cpp"
    break;

  case 79:
#line 583 "spl.y"
        { 
		(yyval.statement) = new ProcedureCall((yyvsp[-3].identifier), (yyvsp[-1].argsList)); 
	}
#line 2296 "y.tab.cpp"
    break;

  case 80:
#line 587 "spl.y"
        { 
		(yyval.statement) = new SysProcedureCall((yyvsp[0].sVal)); 
	}
#line 2304 "y.tab.cpp"
    break;

  case 81:
#line 591 "spl.y"
        { 
		(yyval.statement) = new SysProcedureCall((yyvsp[-3].sVal), (yyvsp[-1].expressionList)); 
	}
#line 2312 "y.tab.cpp"
    break;

  case 82:
#line 595 "spl.y"
        { 
		(yyval.statement) = new SysProcedureCall((yyvsp[-3].sVal), (yyvsp[-1].expression)); 
	}
#line 2320 "y.tab.cpp"
    break;

  case 83:
#line 602 "spl.y"
        { 
		(yyval.expressionList) = (yyvsp[-2].expressionList); 
		(yyval.expressionList)->push_back((yyvsp[0].expression)); 
	}
#line 2329 "y.tab.cpp"
    break;

  case 84:
#line 607 "spl.y"
        { 
		(yyval.expressionList) = new ExpressionList(); (yyval.expressionList)->push_back((yyvsp[0].expression)); 
	}
#line 2337 "y.tab.cpp"
    break;

  case 85:
#line 614 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_GE, (yyvsp[0].expression)); 
	}
#line 2345 "y.tab.cpp"
    break;

  case 86:
#line 618 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_GT, (yyvsp[0].expression)); 
	}
#line 2353 "y.tab.cpp"
    break;

  case 87:
#line 622 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_LE, (yyvsp[0].expression)); 
	}
#line 2361 "y.tab.cpp"
    break;

  case 88:
#line 626 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_LT, (yyvsp[0].expression)); 
	}
#line 2369 "y.tab.cpp"
    break;

  case 89:
#line 630 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_EQUAL, (yyvsp[0].expression)); 
	}
#line 2377 "y.tab.cpp"
    break;

  case 90:
#line 634 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_UNEQUAL, (yyvsp[0].expression)); 
	}
#line 2385 "y.tab.cpp"
    break;

  case 91:
#line 638 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].expression); 
	}
#line 2393 "y.tab.cpp"
    break;

  case 92:
#line 645 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_PLUS, (yyvsp[0].expression)); 
	}
#line 2401 "y.tab.cpp"
    break;

  case 93:
#line 649 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_MINUS, (yyvsp[0].expression)); 
	}
#line 2409 "y.tab.cpp"
    break;

  case 94:
#line 653 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_OR, (yyvsp[0].expression)); 
	}
#line 2417 "y.tab.cpp"
    break;

  case 95:
#line 657 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].expression); 
	}
#line 2425 "y.tab.cpp"
    break;

  case 96:
#line 664 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_MUL, (yyvsp[0].expression)); 
	}
#line 2433 "y.tab.cpp"
    break;

  case 97:
#line 668 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_DIV, (yyvsp[0].expression)); 
	}
#line 2441 "y.tab.cpp"
    break;

  case 98:
#line 672 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_MOD, (yyvsp[0].expression)); 
	}
#line 2449 "y.tab.cpp"
    break;

  case 99:
#line 676 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), BinaryExpression::BinaryOperator::SPL_AND, (yyvsp[0].expression)); 
	}
#line 2457 "y.tab.cpp"
    break;

  case 100:
#line 680 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].expression); 
	}
#line 2465 "y.tab.cpp"
    break;

  case 101:
#line 687 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].identifier); 
	}
#line 2473 "y.tab.cpp"
    break;

  case 102:
#line 691 "spl.y"
        { 
		(yyval.expression) = new FunctionCall((yyvsp[-3].identifier), (yyvsp[-1].argsList)); 
	}
#line 2481 "y.tab.cpp"
    break;

  case 103:
#line 695 "spl.y"
        { 
		(yyval.expression) = new SysFunctionCall((yyvsp[0].sVal)); 
	}
#line 2489 "y.tab.cpp"
    break;

  case 104:
#line 699 "spl.y"
        { 
		(yyval.expression) = new SysFunctionCall((yyvsp[-3].sVal), (yyvsp[-1].argsList)); 
	}
#line 2497 "y.tab.cpp"
    break;

  case 105:
#line 703 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].constValue); 
	}
#line 2505 "y.tab.cpp"
    break;

  case 106:
#line 707 "spl.y"
        { 
		(yyval.expression) = (yyvsp[-1].expression); 
	}
#line 2513 "y.tab.cpp"
    break;

  case 107:
#line 711 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression(new Boolean(true), BinaryExpression::BinaryOperator::SPL_XOR, (yyvsp[0].expression)); 
	}
#line 2521 "y.tab.cpp"
    break;

  case 108:
#line 715 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression(new Integer(0), BinaryExpression::BinaryOperator::SPL_MINUS, (yyvsp[0].expression)); 
	}
#line 2529 "y.tab.cpp"
    break;

  case 109:
#line 719 "spl.y"
        { 
		(yyval.expression) = new ArrayReference((yyvsp[-3].identifier), (yyvsp[-1].expression)); 
	}
#line 2537 "y.tab.cpp"
    break;

  case 110:
#line 723 "spl.y"
        { 
		(yyval.expression) = new RecordReference((yyvsp[-2].identifier), (yyvsp[0].identifier)); 
	}
#line 2545 "y.tab.cpp"
    break;

  case 111:
#line 730 "spl.y"
        { 
		(yyval.argsList) = (yyvsp[-2].argsList); (yyval.argsList)->push_back((yyvsp[0].expression)); 
	}
#line 2553 "y.tab.cpp"
    break;

  case 112:
#line 734 "spl.y"
        { 
		(yyval.argsList) = new ArgsList(); (yyval.argsList)->push_back((yyvsp[0].expression)); 
	}
#line 2561 "y.tab.cpp"
    break;

  case 113:
#line 741 "spl.y"
        { 
		(yyval.ifStatement) = new IfStatement((yyvsp[-3].expression), (yyvsp[-1].statement), (yyvsp[0].statement)); 
	}
#line 2569 "y.tab.cpp"
    break;

  case 114:
#line 748 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
	}
#line 2577 "y.tab.cpp"
    break;

  case 115:
#line 752 "spl.y"
        { 
		(yyval.statement) = nullptr; 
	}
#line 2585 "y.tab.cpp"
    break;

  case 116:
#line 759 "spl.y"
        { 
		(yyval.repeatStatement) = new RepeatStatement((yyvsp[0].expression), (yyvsp[-2].statementList)); 
	}
#line 2593 "y.tab.cpp"
    break;

  case 117:
#line 766 "spl.y"
        { 
		(yyval.whileStatement) = new WhileStatement((yyvsp[-2].expression), (yyvsp[0].statement)); 
	}
#line 2601 "y.tab.cpp"
    break;

  case 118:
#line 773 "spl.y"
        { 
		(yyval.forStatement) = new ForStatement((yyvsp[-6].identifier), (yyvsp[-4].expression), (yyvsp[-3].bVal), (yyvsp[-2].expression), (yyvsp[0].statement)); 
	}
#line 2609 "y.tab.cpp"
    break;

  case 119:
#line 780 "spl.y"
        { 
		(yyval.bVal) = true; 
	}
#line 2617 "y.tab.cpp"
    break;

  case 120:
#line 784 "spl.y"
        { 
		(yyval.bVal) = false; 
	}
#line 2625 "y.tab.cpp"
    break;

  case 121:
#line 791 "spl.y"
        { 
		(yyval.caseStatement) = new CaseStatement((yyvsp[-3].expression), (yyvsp[-1].caseExprList));
	}
#line 2633 "y.tab.cpp"
    break;

  case 122:
#line 798 "spl.y"
        { 
		(yyval.caseExprList) = (yyvsp[-1].caseExprList); (yyval.caseExprList)->push_back((yyvsp[0].caseExpression)); 
	}
#line 2641 "y.tab.cpp"
    break;

  case 123:
#line 802 "spl.y"
        { 
		(yyval.caseExprList) = new CaseExprList(); (yyval.caseExprList)->push_back((yyvsp[0].caseExpression)); 
	}
#line 2649 "y.tab.cpp"
    break;

  case 124:
#line 809 "spl.y"
        { 
		(yyval.caseExpression) = new CaseExpression((yyvsp[-3].constValue), (yyvsp[-1].statement)); 
	}
#line 2657 "y.tab.cpp"
    break;

  case 125:
#line 813 "spl.y"
        { 
		(yyval.caseExpression) = new CaseExpression((yyvsp[-3].identifier), (yyvsp[-1].statement)); 
	}
#line 2665 "y.tab.cpp"
    break;

  case 126:
#line 820 "spl.y"
        { 
		(yyval.gotoStatement) = new GotoStatement((yyvsp[0].iVal)); 
	}
#line 2673 "y.tab.cpp"
    break;


#line 2677 "y.tab.cpp"

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
                  yystos[+*yyssp], yyvsp);
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
#line 825 "spl.y"

