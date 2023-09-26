/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y"

    #include<stdio.h>
    #include<stdarg.h>
    #include<stdlib.h>
    #include"Node.h"

    int yyerror(char*);
    int yylex(void);

    Node* allocNode();
    Node* createConstant(int value);
    Node* createIdentifier(int index);
    Node* createOperation(int operator, int no_of_operands, ...);
    int exec(Node* node);
    
    int sym[26];

#line 89 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    WHILE = 259,                   /* WHILE  */
    PRINT = 260,                   /* PRINT  */
    SWITCH = 261,                  /* SWITCH  */
    CASE = 262,                    /* CASE  */
    CONSTANT = 263,                /* CONSTANT  */
    IDENTIFIER = 264,              /* IDENTIFIER  */
    IFX = 265,                     /* IFX  */
    ELSE = 266,                    /* ELSE  */
    OR = 267,                      /* OR  */
    AND = 268,                     /* AND  */
    EQ = 269,                      /* EQ  */
    NE = 270,                      /* NE  */
    LE = 271,                      /* LE  */
    GE = 272,                      /* GE  */
    UMINUS = 273                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define WHILE 259
#define PRINT 260
#define SWITCH 261
#define CASE 262
#define CONSTANT 263
#define IDENTIFIER 264
#define IFX 265
#define ELSE 266
#define OR 267
#define AND 268
#define EQ 269
#define NE 270
#define LE 271
#define GE 272
#define UMINUS 273

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "yacc.y"

    int iValue;
    int sIndex;
    Node* nodePtr;

#line 184 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_WHILE = 4,                      /* WHILE  */
  YYSYMBOL_PRINT = 5,                      /* PRINT  */
  YYSYMBOL_SWITCH = 6,                     /* SWITCH  */
  YYSYMBOL_CASE = 7,                       /* CASE  */
  YYSYMBOL_CONSTANT = 8,                   /* CONSTANT  */
  YYSYMBOL_IDENTIFIER = 9,                 /* IDENTIFIER  */
  YYSYMBOL_IFX = 10,                       /* IFX  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_12_ = 12,                       /* '='  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_15_ = 15,                       /* '!'  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_NE = 17,                        /* NE  */
  YYSYMBOL_18_ = 18,                       /* '<'  */
  YYSYMBOL_LE = 19,                        /* LE  */
  YYSYMBOL_20_ = 20,                       /* '>'  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_22_ = 22,                       /* '+'  */
  YYSYMBOL_23_ = 23,                       /* '-'  */
  YYSYMBOL_24_ = 24,                       /* '*'  */
  YYSYMBOL_25_ = 25,                       /* '/'  */
  YYSYMBOL_UMINUS = 26,                    /* UMINUS  */
  YYSYMBOL_27_ = 27,                       /* ';'  */
  YYSYMBOL_28_ = 28,                       /* '{'  */
  YYSYMBOL_29_ = 29,                       /* '}'  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_program = 34,                   /* program  */
  YYSYMBOL_statement = 35,                 /* statement  */
  YYSYMBOL_switch = 36,                    /* switch  */
  YYSYMBOL_cases = 37,                     /* cases  */
  YYSYMBOL_statements = 38,                /* statements  */
  YYSYMBOL_loop = 39,                      /* loop  */
  YYSYMBOL_conditional = 40,               /* conditional  */
  YYSYMBOL_expr = 41                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  36
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  80

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    15,     2,     2,     2,     2,     2,     2,
      30,    31,    24,    22,     2,    23,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    27,
      18,    12,    20,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    13,    14,    16,
      17,    19,    21,    26
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    50,    50,    51,    55,    56,    57,    58,    59,    60,
      61,    65,    68,    69,    73,    74,    78,    82,    83,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "WHILE", "PRINT",
  "SWITCH", "CASE", "CONSTANT", "IDENTIFIER", "IFX", "ELSE", "'='", "OR",
  "AND", "'!'", "EQ", "NE", "'<'", "LE", "'>'", "GE", "'+'", "'-'", "'*'",
  "'/'", "UMINUS", "';'", "'{'", "'}'", "'('", "')'", "':'", "$accept",
  "program", "statement", "switch", "cases", "statements", "loop",
  "conditional", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-26)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -26,    49,   -26,   -25,   -22,    52,    -9,   -26,     6,    52,
      52,   -26,    81,    52,   -26,   -26,   -26,   -26,   163,    52,
      52,   178,    52,    52,    22,   -26,   -26,    65,    99,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,   -26,   115,   131,   -26,   147,   193,   -26,   -26,   -26,
     205,    22,   -11,   -11,   -11,   -11,   -11,   -11,   -21,   -21,
     -26,   -26,    81,    81,   -19,    11,   -26,    17,    81,    40,
      -6,   -26,    -7,    51,   -26,    81,    30,   -26,    81,   -26
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,     0,    35,    34,     0,
       0,     4,     0,     0,     2,    10,     9,     8,     0,     0,
       0,     0,     0,     0,    22,    33,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     6,     0,    19,     7,    15,    36,
      20,    21,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,     0,     0,    17,    16,     0,     0,     0,
       0,    18,     0,     0,    11,     0,     0,    12,     0,    13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,   -12,   -26,   -26,   -26,   -26,   -26,    -3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    14,    15,    70,    27,    16,    17,    18
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      26,    73,    21,    39,    40,    19,    24,    25,    20,    67,
      28,    37,    38,    39,    40,    48,    42,    43,    23,    45,
      46,    22,    68,    74,    69,    75,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    72,     2,
      65,    66,     3,     4,     5,     6,    71,     7,     8,    76,
       7,     8,    78,    77,     9,     0,    79,     9,     3,     4,
       5,     6,    10,     7,     8,    10,    11,    12,     0,    13,
       9,     0,    13,     0,     3,     4,     5,     6,    10,     7,
       8,     0,    11,    12,    47,    13,     9,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,    11,    12,
       0,    13,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,     0,     0,    29,    30,
      49,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,     0,     0,    29,    30,    62,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,     0,     0,
      29,    30,    63,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,     0,    29,    30,    64,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    44,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40
};

static const yytype_int8 yycheck[] =
{
      12,     7,     5,    24,    25,    30,     9,    10,    30,    28,
      13,    22,    23,    24,    25,    27,    19,    20,    12,    22,
      23,    30,    11,    29,     7,    32,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     8,     0,
      62,    63,     3,     4,     5,     6,    68,     8,     9,     8,
       8,     9,    32,    75,    15,    -1,    78,    15,     3,     4,
       5,     6,    23,     8,     9,    23,    27,    28,    -1,    30,
      15,    -1,    30,    -1,     3,     4,     5,     6,    23,     8,
       9,    -1,    27,    28,    29,    30,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    27,    28,
      -1,    30,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    13,    14,
      31,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    13,    14,    31,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      13,    14,    31,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    13,    14,    31,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,     0,     3,     4,     5,     6,     8,     9,    15,
      23,    27,    28,    30,    35,    36,    39,    40,    41,    30,
      30,    41,    30,    12,    41,    41,    35,    38,    41,    13,
      14,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    27,    41,    41,    27,    41,    41,    29,    35,    31,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    31,    31,    31,    35,    35,    28,    11,     7,
      37,    35,     8,     7,    29,    32,     8,    35,    32,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    35,    35,    35,    35,
      35,    36,    37,    37,    38,    38,    39,    40,    40,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     2,     3,     3,     1,     1,
       1,     7,     4,     5,     1,     2,     5,     5,     7,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: program statement  */
#line 50 "yacc.y"
                      { exec((yyvsp[0].nodePtr)); }
#line 1272 "y.tab.c"
    break;

  case 4: /* statement: ';'  */
#line 55 "yacc.y"
        { (yyval.nodePtr) = NULL; }
#line 1278 "y.tab.c"
    break;

  case 6: /* statement: PRINT expr ';'  */
#line 57 "yacc.y"
                     { (yyval.nodePtr) = createOperation(PRINT, 1, (yyvsp[-1].nodePtr)); }
#line 1284 "y.tab.c"
    break;

  case 7: /* statement: '{' statements '}'  */
#line 58 "yacc.y"
                         { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 1290 "y.tab.c"
    break;

  case 11: /* switch: SWITCH '(' expr ')' '{' cases '}'  */
#line 65 "yacc.y"
                                      { (yyval.nodePtr) = createOperation(SWITCH, 2, (yyvsp[-4].nodePtr), (yyvsp[-1].nodePtr)); }
#line 1296 "y.tab.c"
    break;

  case 12: /* cases: CASE CONSTANT ':' statement  */
#line 68 "yacc.y"
                                { (yyval.nodePtr) = createOperation(CASE, 2, createConstant((yyvsp[-2].iValue)), (yyvsp[0].nodePtr)); }
#line 1302 "y.tab.c"
    break;

  case 13: /* cases: cases CASE CONSTANT ':' statement  */
#line 69 "yacc.y"
                                        { (yyval.nodePtr) = createOperation(CASE, 3, createConstant((yyvsp[-2].iValue)), (yyvsp[0].nodePtr), (yyvsp[-4].nodePtr)); }
#line 1308 "y.tab.c"
    break;

  case 15: /* statements: statements statement  */
#line 74 "yacc.y"
                           { (yyval.nodePtr) = createOperation(';', 2, (yyvsp[-1].nodePtr), (yyvsp[0].nodePtr)); }
#line 1314 "y.tab.c"
    break;

  case 16: /* loop: WHILE '(' expr ')' statement  */
#line 78 "yacc.y"
                                 { (yyval.nodePtr) = createOperation(WHILE, 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1320 "y.tab.c"
    break;

  case 17: /* conditional: IF '(' expr ')' statement  */
#line 82 "yacc.y"
                                        { (yyval.nodePtr) = createOperation(IF, 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1326 "y.tab.c"
    break;

  case 18: /* conditional: IF '(' expr ')' statement ELSE statement  */
#line 83 "yacc.y"
                                               { (yyval.nodePtr) = createOperation(IF, 3, (yyvsp[-4].nodePtr), (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1332 "y.tab.c"
    break;

  case 19: /* expr: IDENTIFIER '=' expr  */
#line 86 "yacc.y"
                        { (yyval.nodePtr) = createOperation('=', 2, createIdentifier((yyvsp[-2].sIndex)), (yyvsp[0].nodePtr)); }
#line 1338 "y.tab.c"
    break;

  case 20: /* expr: expr OR expr  */
#line 87 "yacc.y"
                   { (yyval.nodePtr) = createOperation(OR, 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1344 "y.tab.c"
    break;

  case 21: /* expr: expr AND expr  */
#line 88 "yacc.y"
                    { (yyval.nodePtr) = createOperation(AND, 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1350 "y.tab.c"
    break;

  case 22: /* expr: '!' expr  */
#line 89 "yacc.y"
               { (yyval.nodePtr) = createOperation('!', 1, (yyvsp[0].nodePtr)); }
#line 1356 "y.tab.c"
    break;

  case 23: /* expr: expr EQ expr  */
#line 90 "yacc.y"
                   { (yyval.nodePtr) = createOperation(EQ, 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1362 "y.tab.c"
    break;

  case 24: /* expr: expr NE expr  */
#line 91 "yacc.y"
                   { (yyval.nodePtr) = createOperation(NE, 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1368 "y.tab.c"
    break;

  case 25: /* expr: expr '<' expr  */
#line 92 "yacc.y"
                    { (yyval.nodePtr) = createOperation('<', 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1374 "y.tab.c"
    break;

  case 26: /* expr: expr LE expr  */
#line 93 "yacc.y"
                   { (yyval.nodePtr) = createOperation(LE, 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1380 "y.tab.c"
    break;

  case 27: /* expr: expr '>' expr  */
#line 94 "yacc.y"
                    { (yyval.nodePtr) = createOperation('>', 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1386 "y.tab.c"
    break;

  case 28: /* expr: expr GE expr  */
#line 95 "yacc.y"
                   { (yyval.nodePtr) = createOperation(GE, 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1392 "y.tab.c"
    break;

  case 29: /* expr: expr '+' expr  */
#line 96 "yacc.y"
                    { (yyval.nodePtr) = createOperation('+', 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1398 "y.tab.c"
    break;

  case 30: /* expr: expr '-' expr  */
#line 97 "yacc.y"
                    { (yyval.nodePtr) = createOperation('-', 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1404 "y.tab.c"
    break;

  case 31: /* expr: expr '*' expr  */
#line 98 "yacc.y"
                    { (yyval.nodePtr) = createOperation('*', 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1410 "y.tab.c"
    break;

  case 32: /* expr: expr '/' expr  */
#line 99 "yacc.y"
                    { (yyval.nodePtr) = createOperation('/', 2, (yyvsp[-2].nodePtr), (yyvsp[0].nodePtr)); }
#line 1416 "y.tab.c"
    break;

  case 33: /* expr: '-' expr  */
#line 100 "yacc.y"
                            { (yyval.nodePtr) = createOperation(UMINUS, 1, (yyvsp[0].nodePtr)); }
#line 1422 "y.tab.c"
    break;

  case 34: /* expr: IDENTIFIER  */
#line 101 "yacc.y"
                 { (yyval.nodePtr) = createIdentifier((yyvsp[0].sIndex)); }
#line 1428 "y.tab.c"
    break;

  case 35: /* expr: CONSTANT  */
#line 102 "yacc.y"
               { (yyval.nodePtr) = createConstant((yyvsp[0].iValue)); }
#line 1434 "y.tab.c"
    break;

  case 36: /* expr: '(' expr ')'  */
#line 103 "yacc.y"
                   { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 1440 "y.tab.c"
    break;


#line 1444 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 105 "yacc.y"


int yyerror(char* s) {
    fprintf(stderr, "%s\n", s);
    return 1;
}

int main() {
    yyparse();
    return 0;
}

Node* allocNode() {
    Node* node;
    if ((node = malloc(sizeof(Node))) == NULL)
        yyerror("No space");
    return node;
}

Node* createConstant(int value) {
    Node* node = allocNode();
    node->type = T_CONSTANT;
    node->constant.value = value;
    return node;
}

Node* createIdentifier(int index) {
    Node* node = allocNode();
    node->type = T_IDENTIFIER;
    node->identifier.index = index;
    return node;
}

Node* createOperation(int operator, int no_of_operands, ...) {
    Node* node= allocNode();
    node->type = T_OPERATION;
    
    node->operation.operator = operator;
    node->operation.no_of_operands = no_of_operands;
    va_list args;
    va_start(args, no_of_operands);
    for (int i=0; i<no_of_operands; i++)
        node->operation.operands[i] = va_arg(args, Node*);
    va_end(args);

    return node;
}

int execCases(Node* node, int target) {
    OperationNode operation = node->operation;
    printf("%d", operation.operands[0]->constant.value);
    if (operation.no_of_operands == 2 && operation.operands[0]->constant.value == target) {
        exec(operation.operands[1]);
        return 1;
    }
    
    else if (operation.no_of_operands == 3 && execCases(operation.operands[2], target) == 0 && operation.operands[0]->constant.value == target) {
        exec(operation.operands[1]);
        return 1;
    }
    return 0;

}

int exec(Node* node) {
    if (!node)
        return 0;
    switch (node->type) {
        case T_CONSTANT:
            return node->constant.value;

        case T_IDENTIFIER:
            return sym[node->identifier.index];

        case T_OPERATION:
            Node** operands = node->operation.operands;
            switch (node->operation.operator) {
                case SWITCH:
                    execCases(operands[1], exec(operands[0]));
                    return 0;

                case WHILE:
                    while (exec(operands[0]))
                        exec(operands[1]);
                    return 0;

                case IF:
                    if (exec(operands[0]))
                        return exec(operands[1]);
                    else if (node->operation.no_of_operands > 2)
                        return exec(operands[2]);
                    return 0;

                case ';':
                    exec(operands[0]);
                    return exec(operands[1]);

                case PRINT:
                    printf("%d\n", exec(operands[0]));
                    return 0;

                case '=':
                    return sym[operands[0]->identifier.index] = exec(operands[1]);
                
                case OR:
                    return exec(operands[0]) || exec(operands[1]);

                case AND:
                    return exec(operands[0]) && exec(operands[1]);

                case '!':
                    return !exec(operands[0]);

                case EQ:
                    return exec(operands[0]) == exec(operands[1]);

                case NE:
                    return exec(operands[0]) != exec(operands[1]);

                case '<':
                    return exec(operands[0]) < exec(operands[1]);

                case LE:
                    return exec(operands[0]) <= exec(operands[1]);

                case '>':
                    return exec(operands[0]) > exec(operands[1]);

                case GE:
                    return exec(operands[0]) >= exec(operands[1]);

                case '+':
                    return exec(operands[0]) + exec(operands[1]);

                case '*':
                    return exec(operands[0]) * exec(operands[1]);

                case '/':
                    return exec(operands[0]) / exec(operands[1]);

                case UMINUS:
                    return -exec(operands[0]);

            }
    }
    return 0;
}

