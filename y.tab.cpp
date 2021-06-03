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
    REAL = 316,
    CHAR = 317
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
	

#line 262 "y.tab.cpp"

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
#define YYLAST   409

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260

#define YYUNDEFTOK  2
#define YYMAXUTOK   317


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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   141,   149,   156,   165,   172,   177,   183,
     188,   196,   200,   204,   208,   220,   225,   231,   236,   244,
     251,   255,   259,   266,   279,   283,   287,   291,   295,   299,
     306,   313,   320,   324,   331,   338,   342,   349,   354,   360,
     364,   371,   378,   382,   387,   392,   398,   404,   411,   418,
     425,   432,   437,   443,   447,   455,   459,   466,   473,   480,
     488,   495,   502,   507,   513,   518,   525,   529,   533,   537,
     541,   545,   549,   553,   557,   564,   568,   572,   579,   583,
     587,   591,   595,   602,   607,   614,   618,   622,   626,   630,
     634,   638,   645,   649,   653,   657,   664,   668,   672,   676,
     680,   687,   691,   695,   699,   703,   707,   711,   715,   719,
     723,   730,   734,   741,   748,   753,   759,   766,   773,   780,
     784,   791,   798,   802,   809,   813,   820
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
  "SYS_PROC", "SYS_TYPE", "READ", "REAL", "CHAR", "$accept", "name",
  "program", "program_head", "routine", "routine_head", "const_part",
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
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
     -11,     0,    44,    52,    49,  -149,    40,    91,    76,    69,
    -149,  -149,    85,    40,  -149,  -149,  -149,  -149,    40,    66,
     -16,   100,   212,   131,    40,  -149,    40,   -20,  -149,  -149,
    -149,  -149,   133,   -16,   156,  -149,    40,    98,   156,  -149,
     156,   146,   158,   160,   155,  -149,   141,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,   138,  -149,  -149,     1,
      40,  -149,    40,    40,   -20,  -149,   142,  -149,   143,  -149,
     144,   156,   156,   156,   169,    56,  -149,   312,    -1,    99,
    -149,   153,  -149,   211,   226,   322,   267,   156,   156,   156,
     156,    40,   156,  -149,    40,   -16,   170,    40,  -149,   154,
     161,   157,  -149,  -149,  -149,    40,   138,  -149,   175,   175,
    -149,  -149,    52,    52,  -149,   346,  -149,  -149,   156,   156,
     156,    40,   156,   156,   156,   156,   156,   156,   347,   156,
     156,   156,   156,   156,   156,   156,   156,   255,   156,   255,
    -149,    45,   380,   182,   380,    67,   362,   166,   380,    68,
     165,    28,   -29,  -149,    33,    40,   -16,  -149,  -149,   172,
      41,   180,  -149,    76,   177,   179,  -149,   122,   128,   371,
    -149,    -1,    -1,    -1,    -1,    -1,    -1,   181,   195,    73,
    -149,    99,    99,    99,  -149,  -149,  -149,  -149,    17,   147,
     380,  -149,  -149,   156,  -149,  -149,   156,   185,   156,  -149,
       8,   201,  -149,  -149,   138,  -149,  -149,  -149,    40,   213,
       4,  -149,   200,   215,    28,  -149,  -149,  -149,  -149,  -149,
    -149,   255,   255,  -149,  -149,  -149,  -149,   156,   255,  -149,
     380,   380,   156,   380,   -16,  -149,   187,   196,   213,  -149,
      41,    28,    28,  -149,   214,   218,   337,  -149,   380,  -149,
     138,  -149,  -149,  -149,  -149,  -149,  -149,   255,  -149,  -149
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
     123,    92,    93,    94,    96,    97,    98,    99,     0,   115,
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
    -149,    -6,  -149,  -149,  -149,   234,  -149,  -149,    -9,  -149,
    -149,   219,  -100,  -148,  -149,  -149,  -149,    95,   -92,  -149,
    -149,   190,  -149,   188,  -149,   191,  -149,   150,  -149,    16,
    -149,  -149,   148,   102,    -7,   229,  -120,   183,  -149,  -149,
    -149,   -13,   221,     9,   -21,    25,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,    94,  -149
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
      12,    17,   149,   201,   202,   154,   159,    21,   239,   105,
     106,    32,    23,   129,   130,    62,    44,   189,    23,   191,
      58,    77,    63,   234,    70,    83,    11,    85,   240,   122,
      81,    94,     1,   123,   124,   125,   126,   127,    28,   131,
      29,   105,   204,    95,     5,    30,    31,   100,   225,   192,
      99,   116,   117,   193,    58,     4,   108,   109,   115,   119,
     154,   120,    28,   121,    29,   226,   243,   143,   209,    30,
      31,   195,   199,    10,   142,   196,   105,   146,    44,   148,
      44,     6,    28,    11,    29,   147,   150,    98,    58,    30,
      31,    58,   208,   253,   254,    11,    11,   100,    14,   158,
      99,   244,   245,    15,   237,    20,   223,   169,   247,   132,
     133,   184,   185,   186,   187,   170,   238,    26,    18,   178,
      33,   134,   177,   188,   135,   190,   218,    28,    11,    29,
     196,    44,   219,    44,    30,    31,   196,   259,   181,   182,
     183,    94,   100,   167,   168,    99,    58,   206,   209,   205,
     258,    56,    82,    95,    58,    86,    17,    69,    89,    71,
      90,    87,    91,    88,    96,    93,   112,   113,   114,    72,
     178,    73,   118,   177,   136,   151,    92,   155,   160,   228,
     230,   157,    97,   231,   156,   233,   194,   198,   200,   214,
     221,   235,    28,    11,    29,   100,   207,    98,    99,    30,
      31,   216,    58,   217,   222,   100,   232,   236,    99,   241,
      28,    11,    29,    74,   246,    44,    44,    30,    31,   248,
     251,   105,    44,   122,   242,   249,   250,   123,   124,   125,
     126,   127,   100,   100,    58,    99,    99,     8,   255,    15,
      34,   100,   256,    57,    99,    35,    36,   203,    37,    38,
     107,    44,   110,    15,    34,   111,   252,    39,   137,   162,
      36,   165,    37,    38,    40,   215,    41,    11,    84,   140,
      42,    39,    43,   224,     0,     0,   138,     0,    40,     0,
      41,    11,    15,    34,    42,     0,    43,     0,     0,    36,
       0,    37,    38,     0,    15,    34,     0,     0,     0,     0,
      39,    36,     0,    37,    38,     0,     0,    40,     0,    41,
      11,     0,    39,    42,     0,    43,     0,     0,     0,    40,
       0,     0,    11,     0,   122,    42,     0,    43,   123,   124,
     125,   126,   127,     0,   122,     0,     0,     0,   123,   124,
     125,   126,   127,   171,   172,   173,   174,   175,   176,   122,
     166,   128,   139,   123,   124,   125,   126,   127,   122,     0,
       0,     0,   123,   124,   125,   126,   127,   257,   197,     0,
       0,     0,     0,     0,   122,     0,     0,   220,   123,   124,
     125,   126,   127,   122,     0,     0,     0,   123,   124,   125,
     126,   127,   122,     0,     0,     0,   123,   124,   125,   126,
     127,    28,    11,    29,     0,     0,     0,     0,    30,    31
};

static const yytype_int16 yycheck[] =
{
       6,     8,    94,   151,    33,    97,   106,    13,     4,     8,
       9,    20,    18,    14,    15,    35,    22,   137,    24,   139,
      26,    34,    42,    15,    33,    38,    55,    40,    24,    12,
      36,     3,    43,    16,    17,    18,    19,    20,    54,    40,
      56,     8,     9,    15,     0,    61,    62,    56,    31,     4,
      56,    72,    73,     8,    60,    55,    62,    63,    71,     3,
     152,     5,    54,     7,    56,    48,   214,    88,   160,    61,
      62,     4,     4,    24,    87,     8,     8,    90,    84,    92,
      86,    29,    54,    55,    56,    91,    95,    59,    94,    61,
      62,    97,    51,   241,   242,    55,    55,   106,     7,   105,
     106,   221,   222,    27,   204,    20,    33,   120,   228,    10,
      11,   132,   133,   134,   135,   121,   208,    51,    49,   128,
      20,    22,   128,   136,    25,   138,     4,    54,    55,    56,
       8,   137,     4,   139,    61,    62,     8,   257,   129,   130,
     131,     3,   151,   118,   119,   151,   152,   156,   240,   155,
     250,    20,    54,    15,   160,     9,   163,    24,     3,     3,
       5,     3,     7,     3,    26,    24,    24,    24,    24,    13,
     179,    15,     3,   179,    21,     5,    21,    23,     3,    32,
     193,    24,    44,   196,    23,   198,     4,    21,    23,     9,
       9,   200,    54,    55,    56,   204,    24,    59,   204,    61,
      62,    24,   208,    24,     9,   214,    21,     6,   214,     9,
      54,    55,    56,    57,   227,   221,   222,    61,    62,   232,
      24,     8,   228,    12,     9,   234,    39,    16,    17,    18,
      19,    20,   241,   242,   240,   241,   242,     3,    24,    27,
      28,   250,    24,    24,   250,    33,    34,   152,    36,    37,
      60,   257,    64,    27,    28,    64,   240,    45,    47,   109,
      34,   113,    36,    37,    52,   163,    54,    55,    39,    86,
      58,    45,    60,   179,    -1,    -1,    50,    -1,    52,    -1,
      54,    55,    27,    28,    58,    -1,    60,    -1,    -1,    34,
      -1,    36,    37,    -1,    27,    28,    -1,    -1,    -1,    -1,
      45,    34,    -1,    36,    37,    -1,    -1,    52,    -1,    54,
      55,    -1,    45,    58,    -1,    60,    -1,    -1,    -1,    52,
      -1,    -1,    55,    -1,    12,    58,    -1,    60,    16,    17,
      18,    19,    20,    -1,    12,    -1,    -1,    -1,    16,    17,
      18,    19,    20,   122,   123,   124,   125,   126,   127,    12,
       4,    39,    30,    16,    17,    18,    19,    20,    12,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    30,     6,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,     6,    16,    17,
      18,    19,    20,    12,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    12,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    54,    55,    56,    -1,    -1,    -1,    -1,    61,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    65,    66,    55,     0,    29,    67,    68,    69,
      24,    55,    64,    70,     7,    27,    96,    97,    49,    72,
      20,    64,    98,    64,    73,    74,    51,    82,    54,    56,
      61,    62,    71,    20,    28,    33,    34,    36,    37,    45,
      52,    54,    58,    60,    64,    97,    99,   100,   101,   102,
     109,   111,   112,   113,   115,   118,    20,    74,    64,    81,
      83,    84,    35,    42,    85,    86,    87,    88,    89,    24,
      71,     3,    13,    15,    57,    64,    71,   104,   105,   106,
     107,    64,    54,   104,    98,   104,     9,     3,     3,     3,
       5,     7,    21,    24,     3,    15,    26,    44,    59,    64,
      71,    75,    76,    77,    78,     8,     9,    84,    64,    64,
      86,    88,    24,    24,    24,   104,   107,   107,     3,     3,
       5,     7,    12,    16,    17,    18,    19,    20,    39,    14,
      15,    40,    10,    11,    22,    25,    21,    47,    50,    30,
     100,   103,   104,   107,   104,   108,   104,    64,   104,    81,
      71,     5,    79,    80,    81,    23,    23,    24,    64,    75,
       3,    90,    90,    68,    95,    95,     4,   108,   108,   104,
      64,   105,   105,   105,   105,   105,   105,    64,    71,   116,
     117,   106,   106,   106,   107,   107,   107,   107,   104,    99,
     104,    99,     4,     8,     4,     4,     8,     6,    21,     4,
      23,    76,    33,    80,     9,    64,    71,    24,    51,    81,
      91,    92,    93,    94,     9,    96,    24,    24,     4,     4,
       6,     9,     9,    33,   117,    31,    48,   114,    32,   110,
     104,   104,    21,   104,    15,    71,     6,    75,    81,     4,
      24,     9,     9,    76,    99,    99,   104,    99,   104,    71,
      39,    24,    92,    76,    76,    24,    24,    30,    75,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    66,    67,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      77,    78,    79,    79,    80,    81,    81,    82,    82,    83,
      83,    84,    85,    85,    85,    85,    85,    86,    87,    88,
      89,    90,    90,    91,    91,    92,    92,    93,    94,    95,
      96,    97,    98,    98,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   101,   101,   102,   102,
     102,   102,   102,   103,   103,   104,   104,   104,   104,   104,
     104,   104,   105,   105,   105,   105,   106,   106,   106,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   110,   110,   111,   112,   113,   114,
     114,   115,   116,   116,   117,   117,   118
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
#line 1657 "y.tab.cpp"
    break;

  case 3:
#line 142 "spl.y"
        { 
		(yyval.program) = new Program((yyvsp[-2].sVal), (yyvsp[-1].routine)); 
		root = (yyval.program); 
	}
#line 1666 "y.tab.cpp"
    break;

  case 4:
#line 150 "spl.y"
        { 
		(yyval.sVal) = (yyvsp[-1].sVal); 
	}
#line 1674 "y.tab.cpp"
    break;

  case 5:
#line 157 "spl.y"
        { 
		(yyval.routine) = (yyvsp[-1].routine); 
		(yyval.routine)->setRoutineBody((yyvsp[0].compoundStatement)); 
	}
#line 1683 "y.tab.cpp"
    break;

  case 6:
#line 166 "spl.y"
        { 
		(yyval.routine) = new Routine((yyvsp[-3].constDeclList), (yyvsp[-2].typeDeclList), (yyvsp[-1].varDeclList), (yyvsp[0].routineList)); 
	}
#line 1691 "y.tab.cpp"
    break;

  case 7:
#line 173 "spl.y"
        { 
		(yyval.constDeclList) = (yyvsp[0].constDeclList); 
	}
#line 1699 "y.tab.cpp"
    break;

  case 8:
#line 177 "spl.y"
        { 
		(yyval.constDeclList) = new ConstDeclList(); 
	}
#line 1707 "y.tab.cpp"
    break;

  case 9:
#line 184 "spl.y"
        { 
		(yyval.constDeclList) = (yyvsp[-4].constDeclList); 
		(yyval.constDeclList)->push_back(new ConstDeclaration((yyvsp[-3].identifier), (yyvsp[-1].constValue))); 
	}
#line 1716 "y.tab.cpp"
    break;

  case 10:
#line 189 "spl.y"
        { 
		(yyval.constDeclList) = new ConstDeclList(); 
		(yyval.constDeclList)->push_back(new ConstDeclaration((yyvsp[-3].identifier), (yyvsp[-1].constValue))); 
	}
#line 1725 "y.tab.cpp"
    break;

  case 11:
#line 197 "spl.y"
        { 
		(yyval.constValue) = new Integer((yyvsp[0].iVal)); 
	}
#line 1733 "y.tab.cpp"
    break;

  case 12:
#line 201 "spl.y"
        { 
		(yyval.constValue) = new Real((yyvsp[0].dVal)); 
	}
#line 1741 "y.tab.cpp"
    break;

  case 13:
#line 205 "spl.y"
        { 
		(yyval.constValue) = new Char((yyvsp[0].cVal)); 
	}
#line 1749 "y.tab.cpp"
    break;

  case 14:
#line 209 "spl.y"
        {
		if (*(yyvsp[0].sVal) == "true")
			(yyval.constValue) = new Boolean(true);
		else if(*(yyvsp[0].sVal) == "false")
			(yyval.constValue) = new Boolean(false);
		else
			(yyval.constValue) = new Integer(0x7FFFFFFF);
	}
#line 1762 "y.tab.cpp"
    break;

  case 15:
#line 221 "spl.y"
        { 
		(yyval.typeDeclList) = (yyvsp[0].typeDeclList); 
	}
#line 1770 "y.tab.cpp"
    break;

  case 16:
#line 225 "spl.y"
        { 
		(yyval.typeDeclList) = new TypeDeclList(); 
	}
#line 1778 "y.tab.cpp"
    break;

  case 17:
#line 232 "spl.y"
        { 
		(yyval.typeDeclList) = (yyvsp[-1].typeDeclList); 
		(yyval.typeDeclList)->push_back((yyvsp[0].typeDeclaration)); 
	}
#line 1787 "y.tab.cpp"
    break;

  case 18:
#line 237 "spl.y"
        { 
		(yyval.typeDeclList) = new TypeDeclList(); 
		(yyval.typeDeclList)->push_back((yyvsp[0].typeDeclaration)); 
	}
#line 1796 "y.tab.cpp"
    break;

  case 19:
#line 245 "spl.y"
        { 
		(yyval.typeDeclaration) = new TypeDeclaration((yyvsp[-3].identifier), (yyvsp[-1].type)); 
	}
#line 1804 "y.tab.cpp"
    break;

  case 20:
#line 252 "spl.y"
        { 
		(yyval.type) = (yyvsp[0].type); 
	}
#line 1812 "y.tab.cpp"
    break;

  case 21:
#line 256 "spl.y"
        { 
		(yyval.type) = (yyvsp[0].type); 
	}
#line 1820 "y.tab.cpp"
    break;

  case 22:
#line 260 "spl.y"
        { 
		(yyval.type) = (yyvsp[0].type); 
	}
#line 1828 "y.tab.cpp"
    break;

  case 23:
#line 267 "spl.y"
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
#line 1845 "y.tab.cpp"
    break;

  case 24:
#line 280 "spl.y"
        { 
		(yyval.type) = new AstType((yyvsp[0].identifier)); 
	}
#line 1853 "y.tab.cpp"
    break;

  case 25:
#line 284 "spl.y"
        { 
		(yyval.type) = new AstType(new EnumType((yyvsp[-1].nameList))); 
	}
#line 1861 "y.tab.cpp"
    break;

  case 26:
#line 288 "spl.y"
        { 
		(yyval.type) = new AstType(new ConstRangeType((yyvsp[-2].constValue), (yyvsp[0].constValue))); 
	}
#line 1869 "y.tab.cpp"
    break;

  case 27:
#line 292 "spl.y"
        { 
		(yyval.type) = new AstType(new ConstRangeType(-*(yyvsp[-2].constValue), (yyvsp[0].constValue))); 
	}
#line 1877 "y.tab.cpp"
    break;

  case 28:
#line 296 "spl.y"
        { 
		(yyval.type) = new AstType(new ConstRangeType(-*(yyvsp[-3].constValue), -*(yyvsp[0].constValue))); 
	}
#line 1885 "y.tab.cpp"
    break;

  case 29:
#line 300 "spl.y"
        { 
		(yyval.type) = new AstType(new EnumRangeType((yyvsp[-2].identifier), (yyvsp[0].identifier))); 
	}
#line 1893 "y.tab.cpp"
    break;

  case 30:
#line 307 "spl.y"
        { 
		(yyval.type) = new AstType(new AstArrayType((yyvsp[0].type), (yyvsp[-3].type))); 
	}
#line 1901 "y.tab.cpp"
    break;

  case 31:
#line 314 "spl.y"
        { 
		(yyval.type) = new AstType(new RecordType((yyvsp[-1].fieldList))); 
	}
#line 1909 "y.tab.cpp"
    break;

  case 32:
#line 321 "spl.y"
        { 
		(yyval.fieldList) = (yyvsp[-1].fieldList); (yyval.fieldList)->push_back((yyvsp[0].fieldDeclaration)); 
	}
#line 1917 "y.tab.cpp"
    break;

  case 33:
#line 325 "spl.y"
        { 
		(yyval.fieldList) = new FieldList(); (yyval.fieldList)->push_back((yyvsp[0].fieldDeclaration)); 
	}
#line 1925 "y.tab.cpp"
    break;

  case 34:
#line 332 "spl.y"
        { 
		(yyval.fieldDeclaration) = new FieldDeclaration((yyvsp[-3].nameList), (yyvsp[-1].type)); 
	}
#line 1933 "y.tab.cpp"
    break;

  case 35:
#line 339 "spl.y"
        { 
		(yyval.nameList) = (yyvsp[-2].nameList); (yyval.nameList)->push_back((yyvsp[0].identifier)); 
	}
#line 1941 "y.tab.cpp"
    break;

  case 36:
#line 343 "spl.y"
        { 
		(yyval.nameList) = new NameList(); (yyval.nameList)->push_back((yyvsp[0].identifier)); 
	}
#line 1949 "y.tab.cpp"
    break;

  case 37:
#line 350 "spl.y"
        { 
		(yyval.varDeclList) = (yyvsp[0].varDeclList); 
	}
#line 1957 "y.tab.cpp"
    break;

  case 38:
#line 354 "spl.y"
        { 
		(yyval.varDeclList) = new VarDeclList(); 
	}
#line 1965 "y.tab.cpp"
    break;

  case 39:
#line 361 "spl.y"
        { 
		(yyval.varDeclList) = (yyvsp[-1].varDeclList); (yyval.varDeclList)->push_back((yyvsp[0].varDeclaration)); 
	}
#line 1973 "y.tab.cpp"
    break;

  case 40:
#line 365 "spl.y"
        { 
		(yyval.varDeclList) = new VarDeclList(); (yyval.varDeclList)->push_back((yyvsp[0].varDeclaration)); 
	}
#line 1981 "y.tab.cpp"
    break;

  case 41:
#line 372 "spl.y"
        { 
		(yyval.varDeclaration) = new VarDeclaration((yyvsp[-3].nameList), (yyvsp[-1].type)); 
	}
#line 1989 "y.tab.cpp"
    break;

  case 42:
#line 379 "spl.y"
        { 
		(yyval.routineList) = (yyvsp[-1].routineList); (yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 1997 "y.tab.cpp"
    break;

  case 43:
#line 383 "spl.y"
        { 
		(yyval.routineList) = (yyvsp[-1].routineList); 
		(yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 2006 "y.tab.cpp"
    break;

  case 44:
#line 388 "spl.y"
        { 
		(yyval.routineList) = new RoutineList(); 
		(yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 2015 "y.tab.cpp"
    break;

  case 45:
#line 393 "spl.y"
        { 
		(yyval.routineList) = new RoutineList(); 
		(yyval.routineList)->push_back((yyvsp[0].funcDeclaration)); 
	}
#line 2024 "y.tab.cpp"
    break;

  case 46:
#line 398 "spl.y"
        { 
		(yyval.routineList) = new RoutineList(); 
	}
#line 2032 "y.tab.cpp"
    break;

  case 47:
#line 405 "spl.y"
        { 
		(yyval.funcDeclaration) = (yyvsp[-3].funcDeclaration); (yyval.funcDeclaration)->setRoutine((yyvsp[-1].routine)); 
	}
#line 2040 "y.tab.cpp"
    break;

  case 48:
#line 412 "spl.y"
        { 
		(yyval.funcDeclaration) = new FuncDeclaration((yyvsp[-3].identifier), (yyvsp[-2].paraList), (yyvsp[0].type)); 
	}
#line 2048 "y.tab.cpp"
    break;

  case 49:
#line 419 "spl.y"
        { 
		(yyval.funcDeclaration) = (yyvsp[-3].funcDeclaration); (yyval.funcDeclaration)->setRoutine((yyvsp[-1].routine)); 
	}
#line 2056 "y.tab.cpp"
    break;

  case 50:
#line 426 "spl.y"
        { 
		(yyval.funcDeclaration) = new FuncDeclaration((yyvsp[-1].identifier), (yyvsp[0].paraList)); 
	}
#line 2064 "y.tab.cpp"
    break;

  case 51:
#line 433 "spl.y"
        { 
		(yyval.paraList) = (yyvsp[-1].paraList); 
	}
#line 2072 "y.tab.cpp"
    break;

  case 52:
#line 437 "spl.y"
        { 
		(yyval.paraList) = new ParaList(); 
	}
#line 2080 "y.tab.cpp"
    break;

  case 53:
#line 444 "spl.y"
        { 
		(yyval.paraList) = (yyvsp[-2].paraList); (yyval.paraList)->push_back((yyvsp[0].parameter)); 
	}
#line 2088 "y.tab.cpp"
    break;

  case 54:
#line 448 "spl.y"
        { 
		(yyval.paraList) = new ParaList(); 
		(yyval.paraList)->push_back((yyvsp[0].parameter)); 
	}
#line 2097 "y.tab.cpp"
    break;

  case 55:
#line 456 "spl.y"
        { 
		(yyval.parameter) = (yyvsp[-2].parameter), (yyval.parameter)->setType((yyvsp[0].type));   // ? 
	}
#line 2105 "y.tab.cpp"
    break;

  case 56:
#line 460 "spl.y"
        { 
		(yyval.parameter) = (yyvsp[-2].parameter), (yyval.parameter)->setType((yyvsp[0].type));   // ? 
	}
#line 2113 "y.tab.cpp"
    break;

  case 57:
#line 467 "spl.y"
        { 
		(yyval.parameter) = new Parameter((yyvsp[0].nameList), true); 
	}
#line 2121 "y.tab.cpp"
    break;

  case 58:
#line 474 "spl.y"
        { 
		(yyval.parameter) = new Parameter((yyvsp[0].nameList), false); 
	}
#line 2129 "y.tab.cpp"
    break;

  case 59:
#line 481 "spl.y"
        { 
		(yyval.routine) = (yyvsp[-1].routine); 
		(yyval.routine)->setRoutineBody((yyvsp[0].compoundStatement)); 
	}
#line 2138 "y.tab.cpp"
    break;

  case 60:
#line 489 "spl.y"
        { 
		(yyval.compoundStatement) = (yyvsp[0].compoundStatement); 
	}
#line 2146 "y.tab.cpp"
    break;

  case 61:
#line 496 "spl.y"
        { 
		(yyval.compoundStatement) = new CompoundStatement((yyvsp[-1].statementList)); 
	}
#line 2154 "y.tab.cpp"
    break;

  case 62:
#line 503 "spl.y"
        { 
		(yyval.statementList) = (yyvsp[-2].statementList); (yyval.statementList)->push_back((yyvsp[-1].statement)); 
	}
#line 2162 "y.tab.cpp"
    break;

  case 63:
#line 507 "spl.y"
        { 
		(yyval.statementList) = new StatementList(); 
	}
#line 2170 "y.tab.cpp"
    break;

  case 64:
#line 514 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
		(yyval.statement)->setLabel((yyvsp[-2].iVal)); 
	}
#line 2179 "y.tab.cpp"
    break;

  case 65:
#line 519 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
	}
#line 2187 "y.tab.cpp"
    break;

  case 66:
#line 526 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].assignStatement); 
	}
#line 2195 "y.tab.cpp"
    break;

  case 67:
#line 530 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
	}
#line 2203 "y.tab.cpp"
    break;

  case 68:
#line 534 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].compoundStatement); 
	}
#line 2211 "y.tab.cpp"
    break;

  case 69:
#line 538 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].ifStatement); 
	}
#line 2219 "y.tab.cpp"
    break;

  case 70:
#line 542 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].repeatStatement); 
	}
#line 2227 "y.tab.cpp"
    break;

  case 71:
#line 546 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].whileStatement); 
	}
#line 2235 "y.tab.cpp"
    break;

  case 72:
#line 550 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].forStatement); 
	}
#line 2243 "y.tab.cpp"
    break;

  case 73:
#line 554 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].caseStatement); 
	}
#line 2251 "y.tab.cpp"
    break;

  case 74:
#line 558 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].gotoStatement); 
	}
#line 2259 "y.tab.cpp"
    break;

  case 75:
#line 565 "spl.y"
        { 
		(yyval.assignStatement) = new AssignStatement((yyvsp[-2].identifier), (yyvsp[0].expression)); 
	}
#line 2267 "y.tab.cpp"
    break;

  case 76:
#line 569 "spl.y"
        { 
		(yyval.assignStatement) = new AssignStatement((yyvsp[-5].identifier), (yyvsp[-3].expression), (yyvsp[0].expression)); 
	}
#line 2275 "y.tab.cpp"
    break;

  case 77:
#line 573 "spl.y"
        { 
		(yyval.assignStatement) = new AssignStatement((yyvsp[-4].identifier), (yyvsp[-2].identifier), (yyvsp[0].expression)); 
	}
#line 2283 "y.tab.cpp"
    break;

  case 78:
#line 580 "spl.y"
        { 
		(yyval.statement) = new ProcedureCall((yyvsp[0].identifier)); 
	}
#line 2291 "y.tab.cpp"
    break;

  case 79:
#line 584 "spl.y"
        { 
		(yyval.statement) = new ProcedureCall((yyvsp[-3].identifier), (yyvsp[-1].argsList)); 
	}
#line 2299 "y.tab.cpp"
    break;

  case 80:
#line 588 "spl.y"
        { 
		(yyval.statement) = new SysProcedureCall((yyvsp[0].sVal)); 
	}
#line 2307 "y.tab.cpp"
    break;

  case 81:
#line 592 "spl.y"
        { 
		(yyval.statement) = new SysProcedureCall((yyvsp[-3].sVal), (yyvsp[-1].expressionList)); 
	}
#line 2315 "y.tab.cpp"
    break;

  case 82:
#line 596 "spl.y"
        { 
		(yyval.statement) = new SysProcedureCall((yyvsp[-3].sVal), (yyvsp[-1].expression)); 
	}
#line 2323 "y.tab.cpp"
    break;

  case 83:
#line 603 "spl.y"
        { 
		(yyval.expressionList) = (yyvsp[-2].expressionList); 
		(yyval.expressionList)->push_back((yyvsp[0].expression)); 
	}
#line 2332 "y.tab.cpp"
    break;

  case 84:
#line 608 "spl.y"
        { 
		(yyval.expressionList) = new ExpressionList(); (yyval.expressionList)->push_back((yyvsp[0].expression)); 
	}
#line 2340 "y.tab.cpp"
    break;

  case 85:
#line 615 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), ">=", (yyvsp[0].expression)); 
	}
#line 2348 "y.tab.cpp"
    break;

  case 86:
#line 619 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), ">", (yyvsp[0].expression)); 
	}
#line 2356 "y.tab.cpp"
    break;

  case 87:
#line 623 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "<=", (yyvsp[0].expression)); 
	}
#line 2364 "y.tab.cpp"
    break;

  case 88:
#line 627 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "<", (yyvsp[0].expression)); 
	}
#line 2372 "y.tab.cpp"
    break;

  case 89:
#line 631 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "=", (yyvsp[0].expression)); 
	}
#line 2380 "y.tab.cpp"
    break;

  case 90:
#line 635 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "<>", (yyvsp[0].expression)); 
	}
#line 2388 "y.tab.cpp"
    break;

  case 91:
#line 639 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].expression); 
	}
#line 2396 "y.tab.cpp"
    break;

  case 92:
#line 646 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "+", (yyvsp[0].expression)); 
	}
#line 2404 "y.tab.cpp"
    break;

  case 93:
#line 650 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "-", (yyvsp[0].expression)); 
	}
#line 2412 "y.tab.cpp"
    break;

  case 94:
#line 654 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "or", (yyvsp[0].expression)); 
	}
#line 2420 "y.tab.cpp"
    break;

  case 95:
#line 658 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].expression); 
	}
#line 2428 "y.tab.cpp"
    break;

  case 96:
#line 665 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "*", (yyvsp[0].expression)); 
	}
#line 2436 "y.tab.cpp"
    break;

  case 97:
#line 669 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "/", (yyvsp[0].expression)); 
	}
#line 2444 "y.tab.cpp"
    break;

  case 98:
#line 673 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "mod", (yyvsp[0].expression)); 
	}
#line 2452 "y.tab.cpp"
    break;

  case 99:
#line 677 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression((yyvsp[-2].expression), "and", (yyvsp[0].expression)); 
	}
#line 2460 "y.tab.cpp"
    break;

  case 100:
#line 681 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].expression); 
	}
#line 2468 "y.tab.cpp"
    break;

  case 101:
#line 688 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].identifier); 
	}
#line 2476 "y.tab.cpp"
    break;

  case 102:
#line 692 "spl.y"
        { 
		(yyval.expression) = new FunctionCall((yyvsp[-3].identifier), (yyvsp[-1].argsList)); 
	}
#line 2484 "y.tab.cpp"
    break;

  case 103:
#line 696 "spl.y"
        { 
		(yyval.expression) = new SysFunctionCall((yyvsp[0].sVal)); 
	}
#line 2492 "y.tab.cpp"
    break;

  case 104:
#line 700 "spl.y"
        { 
		(yyval.expression) = new SysFunctionCall((yyvsp[-3].sVal), (yyvsp[-1].argsList)); 
	}
#line 2500 "y.tab.cpp"
    break;

  case 105:
#line 704 "spl.y"
        { 
		(yyval.expression) = (yyvsp[0].constValue); 
	}
#line 2508 "y.tab.cpp"
    break;

  case 106:
#line 708 "spl.y"
        { 
		(yyval.expression) = (yyvsp[-1].expression); 
	}
#line 2516 "y.tab.cpp"
    break;

  case 107:
#line 712 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression(new Boolean(true), "xor", (yyvsp[0].expression)); 
	}
#line 2524 "y.tab.cpp"
    break;

  case 108:
#line 716 "spl.y"
        { 
		(yyval.expression) = new BinaryExpression(new Integer(0), "-", (yyvsp[0].expression)); 
	}
#line 2532 "y.tab.cpp"
    break;

  case 109:
#line 720 "spl.y"
        { 
		(yyval.expression) = new ArrayReference((yyvsp[-3].identifier), (yyvsp[-1].expression)); 
	}
#line 2540 "y.tab.cpp"
    break;

  case 110:
#line 724 "spl.y"
        { 
		(yyval.expression) = new RecordReference((yyvsp[-2].identifier), (yyvsp[0].identifier)); 
	}
#line 2548 "y.tab.cpp"
    break;

  case 111:
#line 731 "spl.y"
        { 
		(yyval.argsList) = (yyvsp[-2].argsList); (yyval.argsList)->push_back((yyvsp[0].expression)); 
	}
#line 2556 "y.tab.cpp"
    break;

  case 112:
#line 735 "spl.y"
        { 
		(yyval.argsList) = new ArgsList(); (yyval.argsList)->push_back((yyvsp[0].expression)); 
	}
#line 2564 "y.tab.cpp"
    break;

  case 113:
#line 742 "spl.y"
        { 
		(yyval.ifStatement) = new IfStatement((yyvsp[-3].expression), (yyvsp[-1].statement), (yyvsp[0].statement)); 
	}
#line 2572 "y.tab.cpp"
    break;

  case 114:
#line 749 "spl.y"
        { 
		(yyval.statement) = (yyvsp[0].statement); 
	}
#line 2580 "y.tab.cpp"
    break;

  case 115:
#line 753 "spl.y"
        { 
		(yyval.statement) = nullptr; 
	}
#line 2588 "y.tab.cpp"
    break;

  case 116:
#line 760 "spl.y"
        { 
		(yyval.repeatStatement) = new RepeatStatement((yyvsp[0].expression), (yyvsp[-2].statementList)); 
	}
#line 2596 "y.tab.cpp"
    break;

  case 117:
#line 767 "spl.y"
        { 
		(yyval.whileStatement) = new WhileStatement((yyvsp[-2].expression), (yyvsp[0].statement)); 
	}
#line 2604 "y.tab.cpp"
    break;

  case 118:
#line 774 "spl.y"
        { 
		(yyval.forStatement) = new ForStatement((yyvsp[-6].identifier), (yyvsp[-4].expression), (yyvsp[-3].bVal), (yyvsp[-2].expression), (yyvsp[0].statement)); 
	}
#line 2612 "y.tab.cpp"
    break;

  case 119:
#line 781 "spl.y"
        { 
		(yyval.bVal) = true; 
	}
#line 2620 "y.tab.cpp"
    break;

  case 120:
#line 785 "spl.y"
        { 
		(yyval.bVal) = false; 
	}
#line 2628 "y.tab.cpp"
    break;

  case 121:
#line 792 "spl.y"
        { 
		(yyval.caseStatement) = new CaseStatement((yyvsp[-3].expression), (yyvsp[-1].caseExprList));
	}
#line 2636 "y.tab.cpp"
    break;

  case 122:
#line 799 "spl.y"
        { 
		(yyval.caseExprList) = (yyvsp[-1].caseExprList); (yyval.caseExprList)->push_back((yyvsp[0].caseExpression)); 
	}
#line 2644 "y.tab.cpp"
    break;

  case 123:
#line 803 "spl.y"
        { 
		(yyval.caseExprList) = new CaseExprList(); (yyval.caseExprList)->push_back((yyvsp[0].caseExpression)); 
	}
#line 2652 "y.tab.cpp"
    break;

  case 124:
#line 810 "spl.y"
        { 
		(yyval.caseExpression) = new CaseExpression((yyvsp[-3].constValue), (yyvsp[-1].statement)); 
	}
#line 2660 "y.tab.cpp"
    break;

  case 125:
#line 814 "spl.y"
        { 
		(yyval.caseExpression) = new CaseExpression((yyvsp[-3].identifier), (yyvsp[-1].statement)); 
	}
#line 2668 "y.tab.cpp"
    break;

  case 126:
#line 821 "spl.y"
        { 
		(yyval.gotoStatement) = new GotoStatement((yyvsp[0].iVal)); 
	}
#line 2676 "y.tab.cpp"
    break;


#line 2680 "y.tab.cpp"

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
#line 826 "spl.y"

