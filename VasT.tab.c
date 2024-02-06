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
#line 1 "VasT.y"

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include "NumeList.h"
using namespace std;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
int yyval;
void yyerror(const char * s);
void typeofPrint();
void evalPrint();
bool verifExist(const char* name);
bool existDecl(const char* type,const char* name, const char* value, const char* domain,bool constant,int dimension);
const char* concatValue(const char* a,const char* b);
const char* getArrayDim(const string& array);
void insertInArray(const char* name,const char* arrayDim,const char* value);
void updateValuesArray(const char* dimArray, const char* name, const char* value);
string getArrayValue(const char* nume,const char* dimArray);
class NumeList names;
vector<string> types_param; 
int contor=0,restOfDim,currentDim,contor_param,lungime_char;
bool ok_type,ok_class,ok_paranteze,ok_bool,ok,ok_func,ok_tipuri,ok_eval,ok_typeof;
string valuesArray;
string typeExpr,typeExprLeft,typeExprRight,finalType;
string nume_functie;
const char* currentType = "";
const char* currentDomain = "";
const char* currentValue = "";
const char* currentNume = "";
const char* currentVar="";
const char* arrayDim = "";
const char* currentValueSt="";
const char* numeFunc="";
float currentValueStFloat;
int currentValueStInt;
char leftValue[20];
vector <pair<string, int>> TypeOfExpressions;
vector <pair<string, int>> EvalExpressions;

#line 115 "VasT.tab.c"

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

#include "VasT.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_START = 3,                      /* START  */
  YYSYMBOL_FINISH = 4,                     /* FINISH  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_NUME = 6,                       /* NUME  */
  YYSYMBOL_TYPE = 7,                       /* TYPE  */
  YYSYMBOL_CLASS = 8,                      /* CLASS  */
  YYSYMBOL_TYPE_F = 9,                     /* TYPE_F  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_FALS = 13,                      /* FALS  */
  YYSYMBOL_ADV = 14,                       /* ADV  */
  YYSYMBOL_INC = 15,                       /* INC  */
  YYSYMBOL_DEC = 16,                       /* DEC  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_CLASS_INIT = 18,                /* CLASS_INIT  */
  YYSYMBOL_EVAL = 19,                      /* EVAL  */
  YYSYMBOL_TYPEOF = 20,                    /* TYPEOF  */
  YYSYMBOL_NR = 21,                        /* NR  */
  YYSYMBOL_CONST = 22,                     /* CONST  */
  YYSYMBOL_NR_FL = 23,                     /* NR_FL  */
  YYSYMBOL_ARRAY = 24,                     /* ARRAY  */
  YYSYMBOL_PLUS = 25,                      /* PLUS  */
  YYSYMBOL_MINUS = 26,                     /* MINUS  */
  YYSYMBOL_MUL = 27,                       /* MUL  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_E = 29,                         /* E  */
  YYSYMBOL_G = 30,                         /* G  */
  YYSYMBOL_GE = 31,                        /* GE  */
  YYSYMBOL_L = 32,                         /* L  */
  YYSYMBOL_LE = 33,                        /* LE  */
  YYSYMBOL_NE = 34,                        /* NE  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '@'  */
  YYSYMBOL_44_ = 44,                       /* '.'  */
  YYSYMBOL_45_ = 45,                       /* '\''  */
  YYSYMBOL_46_ = 46,                       /* '"'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_clase = 49,                     /* clase  */
  YYSYMBOL_antet = 50,                     /* antet  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_functii = 52,                   /* functii  */
  YYSYMBOL_decl_class = 53,                /* decl_class  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_55_3 = 55,                      /* $@3  */
  YYSYMBOL_decl_func = 56,                 /* decl_func  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_59_6 = 59,                      /* $@6  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_var_func = 61,                  /* var_func  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_corp = 63,                      /* corp  */
  YYSYMBOL_64_9 = 64,                      /* $@9  */
  YYSYMBOL_main = 65,                      /* main  */
  YYSYMBOL_decl_var = 66,                  /* decl_var  */
  YYSYMBOL_var = 67,                       /* var  */
  YYSYMBOL_68_10 = 68,                     /* $@10  */
  YYSYMBOL_69_11 = 69,                     /* $@11  */
  YYSYMBOL_70_12 = 70,                     /* $@12  */
  YYSYMBOL_71_13 = 71,                     /* $@13  */
  YYSYMBOL_72_14 = 72,                     /* $@14  */
  YYSYMBOL_73_15 = 73,                     /* $@15  */
  YYSYMBOL_74_16 = 74,                     /* $@16  */
  YYSYMBOL_75_17 = 75,                     /* $@17  */
  YYSYMBOL_76_18 = 76,                     /* $@18  */
  YYSYMBOL_77_19 = 77,                     /* $@19  */
  YYSYMBOL_val_array = 78,                 /* val_array  */
  YYSYMBOL_79_20 = 79,                     /* $@20  */
  YYSYMBOL_dim_array = 80,                 /* dim_array  */
  YYSYMBOL_81_21 = 81,                     /* $@21  */
  YYSYMBOL_asg_const = 82,                 /* asg_const  */
  YYSYMBOL_83_22 = 83,                     /* $@22  */
  YYSYMBOL_asg = 84,                       /* asg  */
  YYSYMBOL_85_23 = 85,                     /* $@23  */
  YYSYMBOL_86_24 = 86,                     /* $@24  */
  YYSYMBOL_87_25 = 87,                     /* $@25  */
  YYSYMBOL_88_26 = 88,                     /* $@26  */
  YYSYMBOL_89_27 = 89,                     /* $@27  */
  YYSYMBOL_90_28 = 90,                     /* $@28  */
  YYSYMBOL_91_29 = 91,                     /* $@29  */
  YYSYMBOL_instr = 92,                     /* instr  */
  YYSYMBOL_unar = 93,                      /* unar  */
  YYSYMBOL_expr = 94,                      /* expr  */
  YYSYMBOL_95_30 = 95,                     /* $@30  */
  YYSYMBOL_96_31 = 96,                     /* $@31  */
  YYSYMBOL_97_32 = 97,                     /* $@32  */
  YYSYMBOL_98_33 = 98,                     /* $@33  */
  YYSYMBOL_99_34 = 99,                     /* $@34  */
  YYSYMBOL_100_35 = 100,                   /* $@35  */
  YYSYMBOL_101_36 = 101,                   /* $@36  */
  YYSYMBOL_102_37 = 102,                   /* $@37  */
  YYSYMBOL_103_38 = 103,                   /* $@38  */
  YYSYMBOL_104_39 = 104,                   /* $@39  */
  YYSYMBOL_105_40 = 105,                   /* $@40  */
  YYSYMBOL_106_41 = 106,                   /* $@41  */
  YYSYMBOL_107_42 = 107,                   /* $@42  */
  YYSYMBOL_108_43 = 108,                   /* $@43  */
  YYSYMBOL_apel_func = 109,                /* apel_func  */
  YYSYMBOL_110_44 = 110,                   /* $@44  */
  YYSYMBOL_111_45 = 111,                   /* $@45  */
  YYSYMBOL_param = 112,                    /* param  */
  YYSYMBOL_113_46 = 113                    /* $@46  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   543

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
       2,     2,     2,     2,    46,     2,     2,     2,     2,    45,
      40,    41,     2,     2,    42,     2,    44,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    64,    65,    68,    68,    69,    72,    73,
      77,    76,    91,    90,   107,   131,   106,   144,   167,   143,
     181,   190,   189,   196,   199,   199,   202,   203,   204,   205,
     206,   209,   210,   214,   213,   225,   224,   240,   241,   240,
     261,   260,   282,   281,   306,   305,   335,   334,   353,   368,
     368,   382,   382,   396,   399,   423,   422,   439,   439,   440,
     444,   443,   451,   452,   456,   455,   494,   493,   520,   519,
     550,   551,   550,   584,   583,   624,   623,   662,   663,   666,
     667,   668,   669,   670,   671,   674,   675,   679,   678,   763,
     762,   844,   843,   911,   910,   978,   978,   979,   992,   991,
    1015,  1014,  1039,  1038,  1063,  1062,  1086,  1085,  1109,  1108,
    1134,  1133,  1157,  1156,  1180,  1180,  1181,  1190,  1198,  1219,
    1244,  1249,  1254,  1266,  1267,  1268,  1271,  1272,  1271,  1312,
    1311,  1315,  1316
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
  "\"end of file\"", "error", "\"invalid token\"", "START", "FINISH",
  "ASSIGN", "NUME", "TYPE", "CLASS", "TYPE_F", "IF", "WHILE", "FOR",
  "FALS", "ADV", "INC", "DEC", "RETURN", "CLASS_INIT", "EVAL", "TYPEOF",
  "NR", "CONST", "NR_FL", "ARRAY", "PLUS", "MINUS", "MUL", "DIV", "E", "G",
  "GE", "L", "LE", "NE", "AND", "OR", "'{'", "'}'", "';'", "'('", "')'",
  "','", "'@'", "'.'", "'\\''", "'\"'", "$accept", "program", "clase",
  "antet", "$@1", "functii", "decl_class", "$@2", "$@3", "decl_func",
  "$@4", "$@5", "$@6", "$@7", "var_func", "$@8", "corp", "$@9", "main",
  "decl_var", "var", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "$@16", "$@17", "$@18", "$@19", "val_array", "$@20", "dim_array", "$@21",
  "asg_const", "$@22", "asg", "$@23", "$@24", "$@25", "$@26", "$@27",
  "$@28", "$@29", "instr", "unar", "expr", "$@30", "$@31", "$@32", "$@33",
  "$@34", "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "$@41", "$@42",
  "$@43", "apel_func", "$@44", "$@45", "param", "$@46", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-216)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-127)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,    54,    77,    18,    82,    57,  -216,    86,   282,    94,
    -216,    95,   100,    97,    38,   106,   107,  -216,  -216,   108,
       4,   137,    75,  -216,    98,   282,    91,  -216,  -216,   126,
     127,   110,   132,     4,    81,   136,   105,   111,   141,  -216,
     113,  -216,  -216,   238,  -216,   231,   118,    28,  -216,  -216,
     139,   134,  -216,    11,    14,   497,  -216,   142,    10,     4,
    -216,   140,     4,   158,  -216,   183,   183,   160,  -216,   282,
      13,     2,   129,   131,   135,   170,    65,    68,  -216,  -216,
     138,  -216,   183,   183,   175,   143,   145,   146,   147,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,     4,     4,  -216,   163,  -216,   497,  -216,    52,   497,
    -216,  -216,   154,     4,   301,   318,   183,   238,   155,   176,
       2,   157,   183,   183,   189,  -216,   231,   161,   162,   165,
     231,     2,    24,   335,   352,  -216,  -216,  -216,  -216,  -216,
    -216,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,  -216,  -216,   183,     4,   175,     4,     4,
    -216,  -216,  -216,  -216,   497,    50,  -216,   167,  -216,   166,
     369,   386,   201,  -216,   183,   183,   203,  -216,   169,    24,
     497,  -216,  -216,  -216,   507,   507,   261,   261,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,   180,   283,  -216,  -216,
    -216,  -216,   183,    12,   174,     2,   282,   177,   182,   183,
     403,   420,   216,   185,  -216,    24,   184,  -216,   188,     4,
     186,   226,    12,  -216,  -216,  -216,   257,   231,   231,   437,
     196,   202,   183,   282,  -216,  -216,     4,   183,  -216,  -216,
     183,  -216,   183,   208,   210,   183,   231,   231,   452,   265,
    -216,  -216,     4,   497,   497,  -216,  -216,   467,   214,   217,
     183,   183,  -216,    12,   215,   234,  -216,  -216,   482,   497,
    -216,   221,    58,   220,   234,   223,  -216,  -216,  -216,   228,
     225,   229,   231,   232,  -216,   230,   231,  -216,   240,  -216
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     5,     3,     0,     1,     9,    78,     0,
      10,     0,     0,     8,    66,     0,     0,    49,    51,     0,
      78,     6,     0,    53,     0,    78,     0,    24,     2,     0,
       0,    59,    68,    78,    33,     0,     0,     0,     0,    77,
       0,    31,    12,    78,    14,    30,     0,   118,   121,   120,
     117,    95,   114,     0,     0,    64,    75,     0,     0,    78,
      67,     0,    78,    35,    48,     0,     0,     0,    32,    78,
       0,     0,     0,     0,     0,     0,    26,    27,    17,   119,
       0,   116,     0,     0,     0,     0,     0,     0,     0,    87,
      89,    91,    93,   106,   102,   104,    98,   100,   108,   110,
     112,    78,    78,    58,   118,    70,    73,    69,   118,    40,
      42,    34,     0,    78,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,    25,    30,     0,     0,     0,
      30,     0,   132,     0,     0,   126,   115,   122,   123,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    76,     0,    78,     0,    78,    78,
      37,    36,    50,    52,    46,     0,    11,    21,    23,     0,
       0,     0,     0,    28,     0,     0,     0,    29,     0,   132,
     129,   127,    97,    96,    88,    90,    92,    94,   107,   103,
     105,    99,   101,   109,   111,   113,     0,    54,    74,    44,
      41,    43,     0,    63,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,   131,   132,     0,    71,     0,    78,
       0,     0,    63,    47,    13,    22,    78,    30,    30,     0,
       0,     0,     0,    78,   130,   128,    78,     0,    45,    38,
       0,    62,     0,     0,     0,     0,    30,    30,     0,    78,
      72,    56,    78,    60,    15,    79,    81,     0,     0,     0,
       0,     0,    39,    63,     0,     0,    80,    82,     0,    18,
      61,     0,     0,     0,     0,     0,    16,    85,    86,     0,
       0,     0,    30,     0,    19,     0,    30,    83,     0,    84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,   -42,
    -216,  -216,  -216,  -216,  -116,  -216,  -216,  -216,  -118,    -6,
     -15,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -188,  -216,   -23,  -216,  -215,  -216,   -20,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,     7,   -25,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,   -58,  -216,  -216,  -150,  -216
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     7,     8,    12,     4,    25,    69,    13,
      71,   264,   131,   275,   121,   205,    28,    45,    75,    76,
      22,    62,   113,   202,   252,   158,   159,   219,   203,    36,
      37,   196,   218,    32,    57,   223,   263,    23,   101,    33,
      59,   155,   236,   156,   102,    77,   273,   180,   141,   142,
     143,   144,    83,   148,   149,   146,   147,   145,   150,   151,
     152,    84,    56,    80,   216,   181,   215
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    70,    21,   110,   168,    55,    40,   241,   173,   119,
      14,    63,   177,    60,   220,   178,   104,    85,   221,    43,
      87,    -7,    29,    48,    49,     1,   136,    -7,    40,   214,
     104,    50,    86,   106,   103,    88,   109,    48,    49,   107,
     114,   115,   111,    30,   120,    50,    20,   105,   270,   251,
      51,   118,    79,    52,   222,    53,    54,   133,   134,    29,
       5,    40,    31,   117,    51,   234,   179,    52,  -126,    53,
      54,    14,    15,   277,   278,   165,    79,     6,   127,   128,
     129,   153,   154,    16,    17,    18,    61,    19,   204,   225,
       9,   164,  -126,   161,    10,    11,   157,   170,   171,   199,
      24,    26,    40,    27,   -78,    31,    29,    20,   126,   243,
     244,   130,    34,    35,    41,    38,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   258,   259,
     197,    44,    46,    47,   -57,    42,   198,    58,   200,   201,
      48,    49,    64,    14,    15,    65,   108,    67,    50,   210,
     211,    66,    68,    48,    49,    16,    17,    18,    78,    19,
      82,    50,    81,   112,   285,   116,    31,    51,   288,   122,
      52,   123,    53,    54,   125,   124,   -78,   197,   132,    20,
      51,   135,   167,    52,   229,    53,    54,    79,   137,   104,
     138,   160,   139,   140,   166,   172,    48,    49,   169,   238,
     226,   174,   175,   206,    50,   176,   209,   248,   -20,   212,
     213,    40,   197,   224,   227,   253,   250,   254,   217,   228,
     257,   232,   233,    51,   239,   235,    52,   249,    53,    54,
     237,   240,   262,   246,    40,   268,   269,    14,    15,   247,
     272,    72,    73,    74,    14,    15,   255,    11,   256,    16,
      17,    18,   266,    19,   271,   267,    16,    17,    18,   276,
      19,   279,   281,    14,    15,   282,   283,   284,   287,   286,
     -78,    14,    15,    20,   242,    16,    17,    18,   289,    19,
      20,   280,   261,    16,    17,    18,     0,    19,    14,    15,
      93,    94,    95,    96,    97,    98,    99,   100,     0,    20,
      16,    17,    18,     0,    19,     0,     0,    20,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,    20,   -55,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,     0,     0,
       0,     0,   162,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,     0,     0,   163,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,   182,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
       0,     0,     0,   183,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,     0,
     207,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,     0,   208,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,   230,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
       0,   231,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     0,     0,   245,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
       0,   260,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     0,     0,   265,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
       0,   274,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100
};

static const yytype_int16 yycheck[] =
{
      20,    43,     8,    61,   120,    30,    21,   222,   126,     7,
       6,    34,   130,    33,   202,   131,     6,     6,     6,    25,
       6,     3,     9,    13,    14,     8,    84,     9,    43,   179,
       6,    21,    21,    58,    57,    21,    61,    13,    14,    59,
      65,    66,    62,     5,    42,    21,    42,    37,   263,   237,
      40,    38,    24,    43,    42,    45,    46,    82,    83,     9,
       6,    76,    24,    69,    40,   215,    42,    43,    40,    45,
      46,     6,     7,    15,    16,   117,    24,     0,    10,    11,
      12,   101,   102,    18,    19,    20,     5,    22,    38,   205,
       8,   116,    40,   113,    37,     9,    44,   122,   123,   157,
       6,     6,   117,     3,    39,    24,     9,    42,    43,   227,
     228,    43,     6,     6,    39,     7,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   246,   247,
     155,    40,     6,     6,    24,    37,   156,     5,   158,   159,
      13,    14,     6,     6,     7,    40,     6,     6,    21,   174,
     175,    40,    39,    13,    14,    18,    19,    20,    40,    22,
      26,    21,    23,     5,   282,     5,    24,    40,   286,    40,
      43,    40,    45,    46,     4,    40,    39,   202,    40,    42,
      40,     6,     6,    43,   209,    45,    46,    24,    45,     6,
      45,    37,    46,    46,    39,     6,    13,    14,    41,   219,
     206,    40,    40,    37,    21,    40,     5,   232,    41,     6,
      41,   226,   237,    39,    37,   240,   236,   242,    38,    37,
     245,     5,    37,    40,    38,    41,    43,   233,    45,    46,
      42,     5,   252,    37,   249,   260,   261,     6,     7,    37,
       6,    10,    11,    12,     6,     7,    38,     9,    38,    18,
      19,    20,    38,    22,    39,    38,    18,    19,    20,    38,
      22,    41,    39,     6,     7,    37,    41,    38,    38,    37,
      39,     6,     7,    42,    17,    18,    19,    20,    38,    22,
      42,   274,    17,    18,    19,    20,    -1,    22,     6,     7,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    42,
      18,    19,    20,    -1,    22,    -1,    -1,    42,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    42,    42,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    41,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    41,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    41,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    41,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    48,    49,    53,     6,     0,    50,    51,     8,
      37,     9,    52,    56,     6,     7,    18,    19,    20,    22,
      42,    66,    67,    84,     6,    54,     6,     3,    63,     9,
       5,    24,    80,    86,     6,     6,    76,    77,     7,    84,
      67,    39,    37,    66,    40,    64,     6,     6,    13,    14,
      21,    40,    43,    45,    46,    94,   109,    81,     5,    87,
      84,     5,    68,    80,     6,    40,    40,     6,    39,    55,
      56,    57,    10,    11,    12,    65,    66,    92,    40,    24,
     110,    23,    26,    99,   108,     6,    21,     6,    21,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    85,    91,    80,     6,    37,    94,    84,     6,    94,
     109,    84,     5,    69,    94,    94,     5,    66,    38,     7,
      42,    61,    40,    40,    40,     4,    43,    10,    11,    12,
      43,    59,    40,    94,    94,     6,   109,    45,    45,    46,
      46,    95,    96,    97,    98,   104,   102,   103,   100,   101,
     105,   106,   107,    84,    84,    88,    90,    44,    72,    73,
      37,    84,    41,    41,    94,    56,    39,     6,    61,    41,
      94,    94,     6,    65,    40,    40,    40,    65,    61,    42,
      94,   112,    41,    41,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    78,    94,    84,   109,
      84,    84,    70,    75,    38,    62,    37,    41,    41,     5,
      94,    94,     6,    41,   112,   113,   111,    38,    79,    74,
      78,     6,    42,    82,    39,    61,    66,    37,    37,    94,
      41,    41,     5,    37,   112,    41,    89,    42,    84,    38,
       5,    82,    17,    65,    65,    39,    37,    37,    94,    66,
      84,    78,    71,    94,    94,    38,    38,    94,    65,    65,
      39,    17,    84,    83,    58,    39,    38,    38,    94,    94,
      82,    39,     6,    93,    39,    60,    38,    15,    16,    41,
      93,    39,    37,    41,    38,    65,    37,    38,    65,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    51,    50,    50,    52,    52,
      54,    53,    55,    53,    57,    58,    56,    59,    60,    56,
      61,    62,    61,    61,    64,    63,    65,    65,    65,    65,
      65,    66,    66,    68,    67,    69,    67,    70,    71,    67,
      72,    67,    73,    67,    74,    67,    75,    67,    67,    76,
      67,    77,    67,    67,    78,    79,    78,    81,    80,    80,
      83,    82,    82,    82,    85,    84,    86,    84,    87,    84,
      88,    89,    84,    90,    84,    91,    84,    84,    84,    92,
      92,    92,    92,    92,    92,    93,    93,    95,    94,    96,
      94,    97,    94,    98,    94,    99,    94,    94,   100,    94,
     101,    94,   102,    94,   103,    94,   104,    94,   105,    94,
     106,    94,   107,    94,   108,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,   110,   111,   109,   113,
     112,   112,   112
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     0,     0,     2,     0,     1,     0,
       0,     8,     0,     9,     0,     0,    13,     0,     0,    14,
       2,     0,     4,     2,     0,     4,     1,     1,     3,     3,
       0,     2,     3,     0,     4,     0,     5,     0,     0,    10,
       0,     6,     0,     6,     0,     8,     0,     7,     3,     0,
       5,     0,     5,     1,     1,     0,     4,     0,     3,     1,
       0,     5,     2,     0,     0,     5,     0,     3,     0,     4,
       0,     0,     9,     0,     6,     0,     5,     2,     0,     7,
       8,     7,     8,    13,    14,     2,     2,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     3,     2,     1,     1,     2,
       1,     1,     3,     3,     3,     3,     0,     0,     6,     0,
       3,     2,     0
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
  case 2: /* program: clase antet functii corp  */
#line 61 "VasT.y"
        { cout << "The program is correct!" << endl; names.printVars(); names.printFuncs(); typeofPrint(); evalPrint();}
#line 1460 "VasT.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 68 "VasT.y"
       {currentDomain="global";}
#line 1466 "VasT.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 77 "VasT.y"
        { 
            if(names.existsClass((yyvsp[-1].string))==true)
            {
                yyerror("This class already exists");
                YYABORT;
            }
            else 
            {
                names.addClass((yyvsp[-1].string));
            }
            ok_class=1; 
            currentDomain=concatValue("class ",(yyvsp[-1].string));
        }
#line 1484 "VasT.tab.c"
    break;

  case 11: /* decl_class: CLASS NUME '{' $@2 decl_var decl_func '}' ';'  */
#line 89 "VasT.y"
                                     {ok_class=0;}
#line 1490 "VasT.tab.c"
    break;

  case 12: /* $@3: %empty  */
#line 91 "VasT.y"
        {
            if(names.existsClass((yyvsp[-1].string))==true)
            {
                yyerror("This class already exists");
                YYABORT;
            }
            else 
            {
                names.addClass((yyvsp[-1].string));
            }
            ok_class=1; 
            currentDomain=concatValue("class ",(yyvsp[-1].string));
        }
#line 1508 "VasT.tab.c"
    break;

  case 13: /* decl_class: decl_class CLASS NUME '{' $@3 decl_var decl_func '}' ';'  */
#line 103 "VasT.y"
                                     {ok_class=0;}
#line 1514 "VasT.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 107 "VasT.y"
        {   
            if(names.existsFunc((yyvsp[-1].string))==false)
            {
                nume_functie=(yyvsp[-1].string);
                if(ok_class==1)
                {
                    NumeFunc f((yyvsp[-1].string),(yyvsp[-2].string),currentDomain);
                    names.addFunc(f);
                }
                else 
                { 
                    NumeFunc f((yyvsp[-1].string),(yyvsp[-2].string),"global");
                    names.addFunc(f);
                }
            }
            else 
            {
                yyerror("This function already exists");
                YYABORT;
            }
            currentDomain=concatValue("function ",(yyvsp[-1].string));
        }
#line 1541 "VasT.tab.c"
    break;

  case 15: /* $@5: %empty  */
#line 131 "VasT.y"
                    { 
                        string tip_functie=(yyvsp[-9].string); 
                        string tip_func_lower;
                        for(char c : tip_functie)
                            tip_func_lower += tolower(c);

                        if(typeExpr!=tip_func_lower) 
                        {   
                            yyerror("The return value is not the same type as the function");
                            YYABORT;
                        }  
                    }
#line 1558 "VasT.tab.c"
    break;

  case 17: /* $@6: %empty  */
#line 144 "VasT.y"
        {   
            if(names.existsFunc((yyvsp[-1].string))==false)
            {
                nume_functie=(yyvsp[-1].string);
                if(ok_class==1)
                {
                    NumeFunc f((yyvsp[-1].string),(yyvsp[-2].string),currentDomain);
                    names.addFunc(f);
                }
                else 
                {
                    NumeFunc f((yyvsp[-1].string),(yyvsp[-2].string),"global");
                    names.addFunc(f);
                }
            }
            else
            {
                yyerror("This function already exists");
                YYABORT;
            }
            currentDomain=concatValue("function ",(yyvsp[-1].string));
            
        }
#line 1586 "VasT.tab.c"
    break;

  case 18: /* $@7: %empty  */
#line 167 "VasT.y"
                    { 
                        string tip_functie=(yyvsp[-9].string); 
                        string tip_func_lower;
                        for(char c : tip_functie)
                            tip_func_lower += tolower(c);

                        if(typeExpr!=tip_func_lower) 
                        {   
                            yyerror("The return value is not the same type as the function");
                            YYABORT;
                        }  
                    }
#line 1603 "VasT.tab.c"
    break;

  case 20: /* var_func: TYPE NUME  */
#line 182 "VasT.y"
        {
            for(auto& f: names.funcs){
                if(f.name == nume_functie)
                    f.addParam((yyvsp[-1].string));
              
            }
        }
#line 1615 "VasT.tab.c"
    break;

  case 21: /* $@8: %empty  */
#line 190 "VasT.y"
        {
            for(auto& f: names.funcs){
                if(f.name == nume_functie)
                    f.addParam((yyvsp[-1].string));
            }
        }
#line 1626 "VasT.tab.c"
    break;

  case 24: /* $@9: %empty  */
#line 199 "VasT.y"
            { currentDomain = "main"; }
#line 1632 "VasT.tab.c"
    break;

  case 33: /* $@10: %empty  */
#line 214 "VasT.y"
        {
            if(existDecl((yyvsp[-1].string), (yyvsp[0].string), "null", currentDomain,false,1)==true) 
            {
                yyerror("Variable already declared");
                YYABORT;
            } 
            currentType = (yyvsp[-1].string); 
            ok_type=true;
        }
#line 1646 "VasT.tab.c"
    break;

  case 34: /* var: TYPE NUME $@10 asg  */
#line 223 "VasT.y"
            {ok_type=false;}
#line 1652 "VasT.tab.c"
    break;

  case 35: /* $@11: %empty  */
#line 225 "VasT.y"
        {   
            int arrayDimInt=atoi(arrayDim);    
            for(int i=0;i<arrayDimInt-1;i++)
                insertInArray((yyvsp[-1].string),arrayDim,"null");
            valuesArray+="null";
            if(existDecl((yyvsp[-2].string), (yyvsp[-1].string), valuesArray.c_str() , currentDomain,false,currentDim)==true) 
            {
                yyerror("Variable already declared");
                YYABORT;
            }  
            valuesArray.clear();
            currentType = (yyvsp[-2].string);
            ok_type=true;
        }
#line 1671 "VasT.tab.c"
    break;

  case 36: /* var: TYPE NUME dim_array $@11 asg  */
#line 239 "VasT.y"
            {ok_type=false;}
#line 1677 "VasT.tab.c"
    break;

  case 37: /* $@12: %empty  */
#line 240 "VasT.y"
                                     {currentType=(yyvsp[-4].string); restOfDim=atoi(arrayDim);}
#line 1683 "VasT.tab.c"
    break;

  case 38: /* $@13: %empty  */
#line 241 "VasT.y"
        {
            if(restOfDim>0)
            {
                valuesArray+=",";
                for(int i=0;i<restOfDim-1;i++)
                    valuesArray+="null,";
                valuesArray+="null";
            }
            if(existDecl((yyvsp[-7].string),(yyvsp[-6].string),valuesArray.c_str(),currentDomain,false,currentDim)==true)
            {
                yyerror("Variable already declared");
                YYABORT;
            }  
            currentType = (yyvsp[-7].string);
            currentNume = (yyvsp[-6].string);
            ok_type=true;
            valuesArray.clear();
        }
#line 1706 "VasT.tab.c"
    break;

  case 39: /* var: TYPE NUME dim_array ASSIGN '{' $@12 val_array '}' $@13 asg  */
#line 258 "VasT.y"
               {ok_type=false;}
#line 1712 "VasT.tab.c"
    break;

  case 40: /* $@14: %empty  */
#line 261 "VasT.y"
        {
           
            
            if(typeExpr!=(yyvsp[-3].string))
            {
                yyerror("Types don't match");
                YYABORT;
            }
            else
            {
                if(existDecl((yyvsp[-3].string), (yyvsp[-2].string), currentValue, currentDomain,false,1)==true) 
                {
                    yyerror("Variable already declared"); //aici
                    YYABORT;
                } 
                currentType = (yyvsp[-3].string);
                ok_type=true;
                typeExpr.clear();
            }
        }
#line 1737 "VasT.tab.c"
    break;

  case 41: /* var: TYPE NUME ASSIGN expr $@14 asg  */
#line 280 "VasT.y"
              {ok_type=false;}
#line 1743 "VasT.tab.c"
    break;

  case 42: /* $@15: %empty  */
#line 282 "VasT.y"
        {
        
            ok_type=true;
            string tip_functie=names.getTypeFunc(currentNume); 
            string tip_func_lower;
                for(char c : tip_functie)
                    tip_func_lower += tolower(c);
            
            if((yyvsp[-3].string)==tip_func_lower)
            {
                if(existDecl((yyvsp[-3].string), (yyvsp[-2].string), "null", currentDomain,false,1)==true) 
                {
                    yyerror("Variable already declared");
                    YYABORT; currentType = (yyvsp[-3].string);
                }
            }
            else
            {
                yyerror("Types don't match");
                YYABORT;
            } 
            currentType=(yyvsp[-3].string);
        }
#line 1771 "VasT.tab.c"
    break;

  case 43: /* var: TYPE NUME ASSIGN apel_func $@15 asg  */
#line 304 "VasT.y"
              {ok_type=false;}
#line 1777 "VasT.tab.c"
    break;

  case 44: /* $@16: %empty  */
#line 306 "VasT.y"
    {
        ok_type=1;
        if(names.existsClass((yyvsp[-2].string))==0)
        {
            yyerror("The class doesn't exist");
            YYABORT;
        }
        string tip_functie=names.getTypeFunc(currentNume); 
        string tip_func_lower;
        for(char c : tip_functie)
            tip_func_lower += tolower(c);
       
        if((yyvsp[-5].string)==tip_func_lower)
        {
             if(existDecl((yyvsp[-5].string), (yyvsp[-4].string), "null", currentDomain,false,1)==true) 
            {
                yyerror("Variable already declared");
                YYABORT; currentType = (yyvsp[-5].string);
            }
        }
        else
        {
            yyerror("Types don't match");
            YYABORT;
        } 
        currentType=(yyvsp[-5].string);
    }
#line 1809 "VasT.tab.c"
    break;

  case 45: /* var: TYPE NUME ASSIGN NUME '.' apel_func $@16 asg  */
#line 332 "VasT.y"
          {ok_type=false;}
#line 1815 "VasT.tab.c"
    break;

  case 46: /* $@17: %empty  */
#line 335 "VasT.y"
        {
            if(typeExpr!=(yyvsp[-3].string))
            {
                yyerror("Types don't match");
                YYABORT;
            }
            else
            {
                if(existDecl((yyvsp[-3].string), (yyvsp[-2].string), currentValue, currentDomain,true,1)) 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                }
            }  
            currentType = (yyvsp[-3].string);
            typeExpr.clear();
        }
#line 1837 "VasT.tab.c"
    break;

  case 48: /* var: CLASS_INIT NUME NUME  */
#line 354 "VasT.y"
        {
            if(names.existsClass((yyvsp[-1].string))==false)
            {
                yyerror("This class doesn't exist");
                YYABORT;
            }
            else
                if(existDecl((yyvsp[-1].string),(yyvsp[0].string) , "null", currentDomain,false,1)) 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                } 
            currentType = (yyvsp[-1].string);
        }
#line 1856 "VasT.tab.c"
    break;

  case 49: /* $@18: %empty  */
#line 368 "VasT.y"
           {ok_eval=1;}
#line 1862 "VasT.tab.c"
    break;

  case 50: /* var: EVAL $@18 '(' expr ')'  */
#line 369 "VasT.y"
        {
            if(ok_func==1)
            {
                yyerror("Eval doesn't support functions");
                YYABORT;
            }
            if(isdigit((yyvsp[-1].string)[0])!=0)
                EvalExpressions.push_back(pair<string, int>(string((yyvsp[-1].string)), yylineno));
            else
                EvalExpressions.push_back(pair<string, int>(string(names.getValue((yyvsp[-1].string))), yylineno));
            ok_eval=0;
            ok_func=0;
        }
#line 1880 "VasT.tab.c"
    break;

  case 51: /* $@19: %empty  */
#line 382 "VasT.y"
             {ok_typeof=1;}
#line 1886 "VasT.tab.c"
    break;

  case 52: /* var: TYPEOF $@19 '(' expr ')'  */
#line 383 "VasT.y"
        {            
            if(ok_func==1)
            {
                yyerror("TypeOf doesn't support functions");
                YYABORT;
            }
            if(isdigit((yyvsp[-1].string)[0])!=0)
                TypeOfExpressions.push_back(pair<string, int>(string(finalType), yylineno));
            else 
                TypeOfExpressions.push_back(pair<string, int>(string(names.getTypeVar(currentVar)), yylineno));
            ok_typeof=0;
            ok_func=0;
        }
#line 1904 "VasT.tab.c"
    break;

  case 54: /* val_array: expr  */
#line 400 "VasT.y"
            {
                restOfDim--;
                contor++; 
               
                if(currentType!=typeExpr)
                {
                    yyerror("Types don't match");
                    YYABORT;
                }
                else
                {
                    valuesArray+=currentValue;
                    int arrayDimInt=atoi(arrayDim); 
                    if(contor>arrayDimInt)
                    {
                        yyerror("Limit of array exceeded"); 
                        YYABORT;
                    } 
                    contor=0;
                }
                typeExpr.clear();
            }
#line 1931 "VasT.tab.c"
    break;

  case 55: /* $@20: %empty  */
#line 423 "VasT.y"
        {   
            restOfDim--;
             if(currentType!=typeExpr)
                {
                    yyerror("Types don't match");
                    YYABORT;
                }
            else
            {
                insertInArray(currentNume,arrayDim,currentValue);
                contor++;
            } 
            typeExpr.clear();
        }
#line 1950 "VasT.tab.c"
    break;

  case 57: /* $@21: %empty  */
#line 439 "VasT.y"
                  {arrayDim=getArrayDim((yyvsp[0].string)); currentDim=atoi(arrayDim); }
#line 1956 "VasT.tab.c"
    break;

  case 59: /* dim_array: ARRAY  */
#line 440 "VasT.y"
                {arrayDim=getArrayDim((yyvsp[0].string)); currentDim=atoi(arrayDim);}
#line 1962 "VasT.tab.c"
    break;

  case 60: /* $@22: %empty  */
#line 444 "VasT.y"
            {
                if(existDecl(currentType, (yyvsp[-2].string), currentValue, currentDomain,true,1)) 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                } 
            }
#line 1974 "VasT.tab.c"
    break;

  case 64: /* $@23: %empty  */
#line 456 "VasT.y"
        {
            if(names.isConst((yyvsp[-2].string))==true) 
            {
                yyerror("This variable is a constant");
                YYABORT;
            } 
    
            if(ok_type==true)
            {
                if(verifExist((yyvsp[-2].string))==false) 
                    names.addVar(currentType,(yyvsp[-2].string),currentValue,currentDomain,false,currentDim); 
                else 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                } 
            }
            else 
            {
              
                if(verifExist((yyvsp[-2].string))==true)
                {     
                    names.updateValue((yyvsp[-2].string),currentValue);   
                    if(typeExpr!=names.getTypeVar((yyvsp[-2].string)))
                    {
                        yyerror("Types don't match");
                        YYABORT;
                    }
                      
                }
                else 
                {
                    yyerror("Variable wasn't declared");
                    YYABORT;
                }
            }
        }
#line 2016 "VasT.tab.c"
    break;

  case 66: /* $@24: %empty  */
#line 494 "VasT.y"
        {
            if(ok_type==true)
            {
                if(verifExist((yyvsp[0].string))==false) 
                    names.addVar(currentType,(yyvsp[0].string),"null",currentDomain,false,currentDim); 
                else 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                }
            }
            else 
            { 
                if(verifExist((yyvsp[0].string))==true)
                {
                    yyerror("Syntax error");
                    YYABORT;
                }
                else
                {
                    yyerror("Variable wasn't declared");
                    YYABORT;
                }
            }
        }
#line 2046 "VasT.tab.c"
    break;

  case 68: /* $@25: %empty  */
#line 520 "VasT.y"
        {
            if(ok_type==true)
            {
                int arrayDimInt=atoi(arrayDim);
                for(int i=0;i<arrayDimInt-1;i++)
                    valuesArray+="null,";
                valuesArray+="null";
                if(verifExist((yyvsp[-1].string))==false) 
                    names.addVar(currentType,(yyvsp[-1].string),valuesArray.c_str(),currentDomain,false,currentDim); 
                else 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                }
                valuesArray.clear();
            }
            else 
            { 
                if(verifExist((yyvsp[-1].string))==true)
                {
                    yyerror("Syntax error");
                    YYABORT;
                }
                else
                {
                    yyerror("Variable wasn't declared");
                    YYABORT;
                }
            }
        }
#line 2081 "VasT.tab.c"
    break;

  case 70: /* $@26: %empty  */
#line 550 "VasT.y"
                                {restOfDim=atoi(arrayDim);}
#line 2087 "VasT.tab.c"
    break;

  case 71: /* $@27: %empty  */
#line 551 "VasT.y"
        {

            if(ok_type==false)
            {
                if(verifExist((yyvsp[-6].string))==true)
                {
                    yyerror("Wrong assignation of array");
                    YYABORT;
                }
                else
                {
                    yyerror("Variable was not declared");
                    YYABORT;
                }
            }

            if(existDecl(currentType,(yyvsp[-6].string),valuesArray.c_str(),currentDomain,false,currentDim)==true)
            {
                yyerror("Variable already declared");
                YYABORT;
            }  
                    
            if(restOfDim>0)
            {
                valuesArray+=",";
                for(int i=0;i<restOfDim-1;i++)
                    valuesArray+="null,";
                valuesArray+="null";
            }
            names.updateValue((yyvsp[-6].string),valuesArray.c_str());
            valuesArray.clear();
        }
#line 2124 "VasT.tab.c"
    break;

  case 73: /* $@28: %empty  */
#line 584 "VasT.y"
        {
            int arrayDimInt=currentDim;
            if(arrayDimInt>names.getDim((yyvsp[-3].string)))
            {
                yyerror("Wrong dimension of array");
                YYABORT;
            }
            updateValuesArray(arrayDim, (yyvsp[-3].string), currentValue);
            if(ok_type==true)
            {
                if(verifExist((yyvsp[-3].string))==false) 
                {
                    yyerror("Wrong declaration of array");
                    YYABORT;
                }
                else 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                } 
            }
            else 
            {
                if(verifExist((yyvsp[-3].string))==true)
                    names.updateValue((yyvsp[-3].string),valuesArray.c_str());
                else 
                {
                    yyerror("Variable wasn't declared");
                    YYABORT;
                }
            }
            valuesArray.clear();
            if(names.getTypeVar((yyvsp[-3].string))!=typeExpr)
            {
                yyerror("Types don't match");
                YYABORT;
            }
        }
#line 2167 "VasT.tab.c"
    break;

  case 75: /* $@29: %empty  */
#line 624 "VasT.y"
        {   
            if(names.existsFunc(currentNume)==false)
            {
                yyerror("Function doesn't exist");
                YYABORT;
            }

            string tip_functie=names.getTypeFunc(currentNume); 
            string tip_func_lower;
                for(char c : tip_functie)
                    tip_func_lower += tolower(c);

            if(ok_type==true)
            {
                if(verifExist((yyvsp[-2].string))==false) 
                    names.addVar(currentType,(yyvsp[-2].string),"null",currentDomain,false,currentDim); 
                else 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                } 
            }
            else 
            {
                if(verifExist((yyvsp[-2].string))==true)
                    names.updateValue((yyvsp[-2].string),"null");
                else 
                {
                    yyerror("Variable wasn't declared");
                    YYABORT;
                }
            }
            if(tip_func_lower!=names.getTypeVar((yyvsp[-2].string)))
            {
                yyerror("Types don't match");
                YYABORT;
            }
        }
#line 2210 "VasT.tab.c"
    break;

  case 87: /* $@30: %empty  */
#line 679 "VasT.y"
        {          
            if(typeExpr=="char" || typeExpr=="string")
            {
                yyerror("Char/String don't support operations");
                YYABORT;
            }

            if(ok_func==1)
            {
                typeExprLeft=names.getTypeFunc(numeFunc);
                string tip_func_lower;
                for(int i=0;i<strlen(typeExprLeft.c_str());i++)
                typeExprLeft[i] = tolower(typeExprLeft[i]);
            }
            else
                typeExprLeft=typeExpr; 

            if(typeExprLeft=="int")
                {
                    currentValueStInt=atoi(currentValue);
                    if (!ok_paranteze)
                    {
                        sprintf(leftValue, "%d", currentValueStInt);
                    }
                }
            else if(typeExprLeft=="float")
                {
                    currentValueStFloat=atof(currentValue);
                    if (!ok_paranteze)
                    {
                        sprintf(leftValue, "%f", currentValueStFloat);
                    }
                }
            
           
        }
#line 2251 "VasT.tab.c"
    break;

  case 88: /* expr: expr PLUS $@30 expr  */
#line 715 "VasT.y"
        { 
            if(typeExpr=="char" || typeExpr=="string")
            {
                yyerror("Char/String don't support operations");
                YYABORT;
            }
                           
            if(ok_func==1)
            {
                typeExprRight=names.getTypeFunc(numeFunc);
                string tip_func_lower;
                for(int i=0;i<strlen(typeExprRight.c_str());i++)
                    typeExprRight[i] = tolower(typeExprRight[i]);
                if(typeExprLeft==typeExprRight)
                {
                    finalType=typeExprLeft;
                }
            }
            else 
                typeExprRight=typeExpr;
          

            if(typeExprLeft!=typeExprRight)
            {
                yyerror("Types of operands don't match");
                YYABORT;
            } 
            else 
            {
                if(ok_paranteze==true)
                {
                    if(typeExprRight=="int")               
                        (yyval.string)=(char*)(to_string(atoi((yyvsp[-3].string))+atoi((yyvsp[0].string)))).c_str();
                    else if(typeExprRight=="float")
                        (yyval.string)=(char*)(to_string(atof((yyvsp[-3].string))+atof(currentValue))).c_str();
                       
                }
                else
                {
                    if(typeExprRight=="int")
                        (yyval.string)=(char*)(to_string(atoi(leftValue)+atoi(currentValue))).c_str();
                    else if(typeExprRight=="float")
                        (yyval.string)=(char*)(to_string(atof(leftValue)+atof(currentValue))).c_str();
                }
                currentValue=(yyval.string);
            }
        }
#line 2303 "VasT.tab.c"
    break;

  case 89: /* $@31: %empty  */
#line 763 "VasT.y"
        { 
            if(typeExpr=="char" || typeExpr=="string")
            {
                yyerror("Char/String don't support operations");
                YYABORT;
            }

            if(ok_func==1)
            {
                typeExprLeft=names.getTypeFunc(numeFunc);
                string tip_func_lower;
                for(int i=0;i<strlen(typeExprLeft.c_str());i++)
                typeExprLeft[i] = tolower(typeExprLeft[i]);
            }
            else
                typeExprLeft=typeExpr; 

            if(typeExprLeft=="int")
                {
                    currentValueStInt=atoi(currentValue);
                    if (!ok_paranteze)
                    {
                        sprintf(leftValue, "%d", currentValueStInt);
                    }
                }
            else if(typeExprLeft=="float")
                {
                    currentValueStFloat=atof(currentValue);
                    if (!ok_paranteze)
                    {
                        sprintf(leftValue, "%f", currentValueStFloat);
                    }
                }
            
        }
#line 2343 "VasT.tab.c"
    break;

  case 90: /* expr: expr MINUS $@31 expr  */
#line 798 "VasT.y"
        {
            if(typeExpr=="char" || typeExpr=="string")
            {
                yyerror("Char/String don't support operations");
                YYABORT;
            }

            if(ok_func==1)
            {
                typeExprRight=names.getTypeFunc(numeFunc);
                string tip_func_lower;
                for(int i=0;i<strlen(typeExprRight.c_str());i++)
                    typeExprRight[i] = tolower(typeExprRight[i]);
                if(typeExprLeft==typeExprRight)
                {
                    finalType=typeExprLeft;
                }
            }
            else 
                typeExprRight=typeExpr;

            if(typeExprLeft!=typeExprRight)
            {
                yyerror("Types of operands don't match");
                YYABORT;
            } 
            else 
            {
                if(ok_paranteze==true)
                {
                    if(typeExprRight=="int")
                        (yyval.string)=(char*)(to_string(atoi((yyvsp[-3].string))-atoi((yyvsp[0].string)))).c_str();
                    else if(typeExprRight=="float")
                        (yyval.string)=(char*)(to_string(atof((yyvsp[-3].string))-atof(currentValue))).c_str();
                }
                else
                {
                    if(typeExprRight=="int")
                        (yyval.string)=(char*)(to_string(atoi(leftValue)-atoi((yyvsp[0].string)))).c_str();
                    else if(typeExprRight=="float")
                        (yyval.string)=(char*)(to_string(atof(leftValue)-atof(currentValue))).c_str();
                }
                currentValue=(yyval.string);
            }
        }
#line 2393 "VasT.tab.c"
    break;

  case 91: /* $@32: %empty  */
#line 844 "VasT.y"
        {   
            if(typeExpr=="char" || typeExpr=="string")
            {
                yyerror("Char/String don't support operations");
                YYABORT;
            }
            
            if(ok_func==1)
            {
                typeExprLeft=names.getTypeFunc(numeFunc);
                string tip_func_lower;
                for(int i=0;i<strlen(typeExprLeft.c_str());i++)
                typeExprLeft[i] = tolower(typeExprLeft[i]);
            }
            else
                typeExprLeft=typeExpr; 

            currentValueSt=currentValue;
            if (!ok_paranteze)
                sprintf(leftValue, "%s", currentValueSt);
        }
#line 2419 "VasT.tab.c"
    break;

  case 92: /* expr: expr MUL $@32 expr  */
#line 865 "VasT.y"
        {   
            if(typeExpr=="char" || typeExpr=="string")
            {
                yyerror("Char/String don't support operations");
                YYABORT;
            }

            if(ok_func==1)
            {
                typeExprRight=names.getTypeFunc(numeFunc);
                string tip_func_lower;
                for(int i=0;i<strlen(typeExprRight.c_str());i++)
                    typeExprRight[i] = tolower(typeExprRight[i]);
                if(typeExprLeft==typeExprRight)
                {
                    finalType=typeExprLeft;
                }
            }
            else 
                typeExprRight=typeExpr;

            if(typeExprLeft!=typeExprRight)
            {
                yyerror("Types of operands don't match");
                YYABORT;
            } 
            else 
            {
                if(ok_paranteze==true)
                {
                    if(typeExprRight=="int")
                        (yyval.string)=(char*)(to_string(atoi((yyvsp[-3].string))*atoi(currentValue))).c_str();
                    else if(typeExprRight=="float")
                        (yyval.string)=(char*)(to_string(atof((yyvsp[-3].string))*atof(currentValue))).c_str();
                }
                else
                {  
                    if(typeExprRight=="int")
                        (yyval.string)=(char*)(to_string(atoi(leftValue)*atoi(currentValue))).c_str();
                    else if(typeExprRight=="float")
                        (yyval.string)=(char*)(to_string(atof(leftValue)*atof(currentValue))).c_str();
                }
                currentValue=(yyval.string);
            }
        }
#line 2469 "VasT.tab.c"
    break;

  case 93: /* $@33: %empty  */
#line 911 "VasT.y"
        { 
            if(typeExpr=="char" || typeExpr=="string")
            {
                yyerror("Char/String don't support operations");
                YYABORT;
            }
            
            if(ok_func==1)
            {
                typeExprLeft=names.getTypeFunc(numeFunc);
                string tip_func_lower;
                for(int i=0;i<strlen(typeExprLeft.c_str());i++)
                typeExprLeft[i] = tolower(typeExprLeft[i]);
            }
            else
                typeExprLeft=typeExpr; 

            currentValueSt=currentValue;
            if (!ok_paranteze)
                sprintf(leftValue, "%s", currentValueSt);
        }
#line 2495 "VasT.tab.c"
    break;

  case 94: /* expr: expr DIV $@33 expr  */
#line 932 "VasT.y"
        {
            if(typeExpr=="char" || typeExpr=="string")
            {
                yyerror("Char/String don't support operations");
                YYABORT;
            }
            
            if(ok_func==1)
            {
                typeExprRight=names.getTypeFunc(numeFunc);
                string tip_func_lower;
                for(int i=0;i<strlen(typeExprRight.c_str());i++)
                    typeExprRight[i] = tolower(typeExprRight[i]);
                if(typeExprLeft==typeExprRight)
                {
                    finalType=typeExprLeft;
                }
            }
            else 
                typeExprRight=typeExpr;

            if(typeExprLeft!=typeExprRight)
            {
                yyerror("Types of operands don't match");
                YYABORT;
            } 
            else 
            {
                
                if(ok_paranteze==true)
                {
                    if(typeExprRight=="int")
                        (yyval.string)=(char*)(to_string(atoi((yyvsp[-3].string))/atoi((yyvsp[0].string)))).c_str();
                    else if(typeExprRight=="float")
                        (yyval.string)=(char*)(to_string(atof((yyvsp[-3].string))/atof(currentValue))).c_str();
                }
                else
                {
                    if(typeExprRight=="int")
                        (yyval.string)=(char*)(to_string(atoi(leftValue)/atoi(currentValue))).c_str();
                    else if(typeExprRight=="float")
                        (yyval.string)=(char*)(to_string(atof(leftValue)/atof(currentValue))).c_str();
                }
                currentValue=(yyval.string);
            }
        }
#line 2546 "VasT.tab.c"
    break;

  case 95: /* $@34: %empty  */
#line 978 "VasT.y"
          {ok_paranteze = 1;}
#line 2552 "VasT.tab.c"
    break;

  case 96: /* expr: '(' $@34 expr ')'  */
#line 978 "VasT.y"
                                       {ok_paranteze=0; (yyval.string)=(yyvsp[-1].string); }
#line 2558 "VasT.tab.c"
    break;

  case 97: /* expr: '(' MINUS expr ')'  */
#line 981 "VasT.y"
        {         
            
            string neg_val;
            neg_val.clear(); 
            neg_val+="-";
            neg_val+=(yyvsp[-1].string);
            (yyval.string) = (char*)neg_val.c_str();
            currentValue=(yyval.string);
            ok_paranteze=1;
        }
#line 2573 "VasT.tab.c"
    break;

  case 98: /* $@35: %empty  */
#line 992 "VasT.y"
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=(yyvsp[-1].string);
        }
#line 2583 "VasT.tab.c"
    break;

  case 99: /* expr: expr L $@35 expr  */
#line 997 "VasT.y"
        {   
            if(atoi(currentValueSt)<atoi((yyvsp[0].string)))
                currentValue="true";
            else
                currentValue="false";

            if(currentValue=="true")
            {
                currentValueSt = "1";
                ok=1;
            }
            else
            {
                currentValueSt = "0";
                ok=1;
            }
        }
#line 2605 "VasT.tab.c"
    break;

  case 100: /* $@36: %empty  */
#line 1015 "VasT.y"
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=(yyvsp[-1].string);
        }
#line 2615 "VasT.tab.c"
    break;

  case 101: /* expr: expr LE $@36 expr  */
#line 1020 "VasT.y"
        {   
            ok=0;
            if(atoi(currentValueSt)<=atoi((yyvsp[0].string)))
                currentValue="true";
            else
                currentValue="false";

            if(currentValue=="true")
            {
                currentValueSt = "1";
                ok=1;
            }
            else
            {
                currentValueSt = "0";
                ok=1;
            }
        }
#line 2638 "VasT.tab.c"
    break;

  case 102: /* $@37: %empty  */
#line 1039 "VasT.y"
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=(yyvsp[-1].string);
        }
#line 2648 "VasT.tab.c"
    break;

  case 103: /* expr: expr G $@37 expr  */
#line 1044 "VasT.y"
        {   

            if(atoi(currentValueSt)>atoi((yyvsp[0].string)))
                currentValue="true";
            else
                currentValue="false";

            if(currentValue=="true")
            {
                currentValueSt = "1";
                ok=1;
            }
            else
            {
                currentValueSt = "0";
                ok=1;
            }
        }
#line 2671 "VasT.tab.c"
    break;

  case 104: /* $@38: %empty  */
#line 1063 "VasT.y"
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=(yyvsp[-1].string);
        }
#line 2681 "VasT.tab.c"
    break;

  case 105: /* expr: expr GE $@38 expr  */
#line 1068 "VasT.y"
        {   
            if(atoi(currentValueSt)>=atoi((yyvsp[0].string)))
                currentValue="true";
            else
                currentValue="false";

            if(currentValue=="true")
            {
                currentValueSt = "1";
                ok=1;
            }
            else
            {
                currentValueSt = "0";
                ok=1;
            }
        }
#line 2703 "VasT.tab.c"
    break;

  case 106: /* $@39: %empty  */
#line 1086 "VasT.y"
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=(yyvsp[-1].string);
        }
#line 2713 "VasT.tab.c"
    break;

  case 107: /* expr: expr E $@39 expr  */
#line 1091 "VasT.y"
        {   
            if(atoi(currentValueSt)==atoi((yyvsp[0].string)))
                currentValue="true";
            else
                currentValue="false";

            if(currentValue=="true")
            {
                currentValueSt = "1";
                ok=1;
            }
            else
            {
                currentValueSt = "0";
                ok=1;
            }
        }
#line 2735 "VasT.tab.c"
    break;

  case 108: /* $@40: %empty  */
#line 1109 "VasT.y"
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=(yyvsp[-1].string);

        }
#line 2746 "VasT.tab.c"
    break;

  case 109: /* expr: expr NE $@40 expr  */
#line 1115 "VasT.y"
        {   

            if(atoi(currentValueSt)!=atoi((yyvsp[0].string)))
                currentValue="true";
            else
                currentValue="false";

            if(currentValue=="true")
            {
                currentValueSt = "1";
                ok=1;
            }
            else
            {
                currentValueSt = "0";
                ok=1;
            }
        }
#line 2769 "VasT.tab.c"
    break;

  case 110: /* $@41: %empty  */
#line 1134 "VasT.y"
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=(yyvsp[-1].string);
        }
#line 2779 "VasT.tab.c"
    break;

  case 111: /* expr: expr AND $@41 expr  */
#line 1139 "VasT.y"
        {
            if(atoi(currentValueSt) && atoi((yyvsp[0].string)))
                currentValue="true";
            else
                currentValue="false";

            if(currentValue=="true")
            {
                currentValueSt = "1";
                ok=1;
            }
            else
            {
                currentValueSt = "0";
                ok=1;
            }
        }
#line 2801 "VasT.tab.c"
    break;

  case 112: /* $@42: %empty  */
#line 1157 "VasT.y"
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=(yyvsp[-1].string);
        }
#line 2811 "VasT.tab.c"
    break;

  case 113: /* expr: expr OR $@42 expr  */
#line 1163 "VasT.y"
        {
            if(atoi(currentValueSt) || atoi((yyvsp[0].string)))
                currentValue="true";
            else
                currentValue="false";

            if(currentValue=="true")
            {
                currentValueSt = "1";
                ok=1;
            }
            else
            {
                currentValueSt = "0";
                ok=1;
            }
        }
#line 2833 "VasT.tab.c"
    break;

  case 114: /* $@43: %empty  */
#line 1180 "VasT.y"
          { ok_tipuri=1;}
#line 2839 "VasT.tab.c"
    break;

  case 115: /* expr: '@' $@43 apel_func  */
#line 1180 "VasT.y"
                                    { ok_func=1;}
#line 2845 "VasT.tab.c"
    break;

  case 116: /* expr: NR NR_FL  */
#line 1182 "VasT.y"
        {
            typeExpr.clear(); 
            if(ok_bool==true) 
                typeExpr="bool"; 
            else {finalType="float";typeExpr+="float";} 
            ok_bool=0;
            currentValue=concatValue((yyvsp[-1].string),(yyvsp[0].string)); 
        }
#line 2858 "VasT.tab.c"
    break;

  case 117: /* expr: NR  */
#line 1191 "VasT.y"
        {  typeExpr.clear();
            if(ok_bool==true) 
                typeExpr="bool"; 
            else  {finalType="int";typeExpr+="int";} 
            ok_bool=0; 
            currentValue = (yyvsp[0].string); 
        }
#line 2870 "VasT.tab.c"
    break;

  case 118: /* expr: NUME  */
#line 1199 "VasT.y"
        { 
            currentVar=(yyvsp[0].string);
            if(ok_tipuri!=1)  
            {
                if(verifExist((yyvsp[0].string))==false) 
                {
                    yyerror("Variable wasn't declared");
                    YYABORT;
                }
                else
                {
                     if(ok_bool==true) 
                        typeExpr="bool"; 
                    else  typeExpr=names.getTypeVar((yyvsp[0].string));
                    ok_bool=0; 
                    currentValue = names.getValue((yyvsp[0].string)).c_str();
                }
            }
           ok_tipuri=0;
        }
#line 2895 "VasT.tab.c"
    break;

  case 119: /* expr: NUME ARRAY  */
#line 1220 "VasT.y"
        {
            if(verifExist((yyvsp[-1].string))==false) 
            {
                yyerror("Variable wasn't declared");
                YYABORT;
            }
            else
            {   int arrayDimInt=atoi(getArrayDim((yyvsp[0].string)));
                if(arrayDimInt>names.getDim((yyvsp[-1].string)))
                {
                    yyerror("Wrong dimension of array");
                    YYABORT;
                }
                else
                {

                    if(ok_bool==true) 
                        typeExpr="bool"; 
                    else  typeExpr=names.getTypeVar((yyvsp[-1].string));
                    ok_bool=0; 
                    currentValue = getArrayValue((yyvsp[-1].string),getArrayDim((yyvsp[0].string))).c_str();
                }
            }
        }
#line 2924 "VasT.tab.c"
    break;

  case 120: /* expr: ADV  */
#line 1245 "VasT.y"
            {
                typeExpr="bool";
                currentValue="true";
            }
#line 2933 "VasT.tab.c"
    break;

  case 121: /* expr: FALS  */
#line 1250 "VasT.y"
            {
                typeExpr="bool";
                currentValue="false";
            }
#line 2942 "VasT.tab.c"
    break;

  case 122: /* expr: '\'' NUME '\''  */
#line 1255 "VasT.y"
            {    
                lungime_char=strlen((yyvsp[-1].string));
                if(lungime_char!=1)
                {
                    yyerror("Char supports only one character");
                    YYABORT;
                } 
                typeExpr="char"; 
                finalType="char";
                currentValue=(yyvsp[-1].string);
            }
#line 2958 "VasT.tab.c"
    break;

  case 123: /* expr: '\'' NR '\''  */
#line 1266 "VasT.y"
                       { typeExpr="char"; currentValue=(yyvsp[-1].string); finalType="char";}
#line 2964 "VasT.tab.c"
    break;

  case 124: /* expr: '"' NUME '"'  */
#line 1267 "VasT.y"
                         { typeExpr="string"; currentValue=(yyvsp[-1].string); finalType="string";}
#line 2970 "VasT.tab.c"
    break;

  case 125: /* expr: '"' NR '"'  */
#line 1268 "VasT.y"
                       { typeExpr="string"; currentValue=(yyvsp[-1].string); finalType="string";}
#line 2976 "VasT.tab.c"
    break;

  case 126: /* $@44: %empty  */
#line 1271 "VasT.y"
                {currentNume=(yyvsp[0].string);}
#line 2982 "VasT.tab.c"
    break;

  case 127: /* $@45: %empty  */
#line 1272 "VasT.y"
        {
            numeFunc=(yyvsp[-3].string);
            if(names.existsFunc(currentNume)==false)
            {
                yyerror("Function doesn't exist");
                YYABORT;
            }

            contor_param++;
            if(contor_param!=names.getNrParamFunc((yyvsp[-3].string)))
            {
                yyerror("Wrong number of parameters for the function");
                YYABORT;
            }
            else
            {
                if(ok_eval==0 && ok_typeof==0)
                    for(auto functie : names.funcs)
                    {
                        if(functie.name==currentNume)
                        {
                            for(int i=0;i<types_param.size();i++)
                            {
                                
                                if(types_param[i]!=functie.param[i])
                                {
                                    yyerror("Parameters types don't match");
                                    YYABORT;
                                }
                            }
                        }
                    }
                types_param.clear();
                
            }
            contor_param=0;
        }
#line 3024 "VasT.tab.c"
    break;

  case 129: /* $@46: %empty  */
#line 1312 "VasT.y"
        {   
            types_param.push_back(typeExpr);
        }
#line 3032 "VasT.tab.c"
    break;

  case 131: /* param: ',' param  */
#line 1315 "VasT.y"
                {contor_param++;}
#line 3038 "VasT.tab.c"
    break;


#line 3042 "VasT.tab.c"

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

#line 1319 "VasT.y"


void yyerror(const char * s){
    printf("error: %s at line:%d\n", s, yylineno);
}

void insertInArray(const char* name,const char* arrayDim,const char* value)
{
    int dim=atoi(arrayDim);
    
    valuesArray += value;
    valuesArray += ',';
   
}

const char* getArrayDim(const string& array)
{
    char* aux = (char*)malloc(array.length());  
    for (int i = 1; i < array.length() - 1; i++) 
    {
        aux[i - 1] = array[i];
    }
    aux[array.length() - 2] = '\0';

    return aux;
}

const char* concatValue(const char* a,const char* b)
{
    char* aux = (char*)malloc(strlen(a) + strlen(b) + 1);
    strcpy(aux,a);
    strcat(aux,b);
    return aux;
}

bool existDecl(const char* type,const char* name, const char* value, const char* domain,bool constant,int dimension)
{
    if(names.existsVar(name) == false) {
                        names.addVar(type, name, value, domain,constant,dimension);
                        return false;
                    }   

                else{
                    return true;
                    }
}

bool verifExist(const char* name)
{
    if(!names.existsVar(name)) {
                        return false;
                    }
    else 
        return true;
}

void updateValuesArray(const char* dimArray, const char* name, const char* value)
{
    int dimArrayInt = atoi(dimArray);
    string aux;
    int contor_virg = 0, contor_all_virg = 0;
    int poz_prim_virg, poz_sec_virg;
    valuesArray = names.getValue(name);

    for(int i = 0; i<valuesArray.length();i++)
            if(valuesArray[i] == ',')
                contor_all_virg++; 

    if(dimArrayInt == 1)
    {
        poz_prim_virg = -1;

        for(int i = poz_prim_virg+1; i<valuesArray.length(); i++)
            if(valuesArray[i] == ',')
            {   poz_sec_virg = i;
                break;
            }
    }

    else if(dimArrayInt == contor_all_virg+1)
    {
        for(int i = 0; i<valuesArray.length();i++)
        {
            if(valuesArray[i] == ',')
                contor_virg++;
            if(contor_virg == dimArrayInt-1)
            {   
                poz_prim_virg = i;
                break;
            }  
        }

        poz_sec_virg = valuesArray.length();
    }

    else
    {
        for(int i = 0; i<valuesArray.length();i++)
        {
            if(valuesArray[i] == ',')
                contor_virg++;
            if(contor_virg == dimArrayInt-1)
            {   
                poz_prim_virg = i;
                break;
            }  
        }

        for(int i = poz_prim_virg+1; i<valuesArray.length(); i++)
            if(valuesArray[i] == ',')
            {   poz_sec_virg = i;
                break;
            }
    }

    for(int i = poz_prim_virg+1; i<poz_sec_virg;i++)
        aux += valuesArray[i];

    if(aux.length()==strlen(value))
        for(int i = poz_prim_virg+1, k=0; i<poz_sec_virg;i++,k++)
            valuesArray[i]=value[k];
    
    else if(aux.length()<strlen(value))
    {
        int newLength = valuesArray.length()+(strlen(value)-aux.length());
        valuesArray.resize(newLength);
        for(int i=0;i<strlen(value)-aux.length();i++)
            for(int j=valuesArray.length()-1;j>=poz_sec_virg;j--)
                valuesArray[j+1]=valuesArray[j];

        for(int i = poz_prim_virg+1, k=0; i<poz_sec_virg+(strlen(value)-aux.length());i++,k++)
            valuesArray[i]=value[k];
    }

    else if(aux.length()>strlen(value))
    {
        int newLength = valuesArray.length()-(aux.length()-strlen(value));

        for(int i = poz_prim_virg+1, k=0; i<poz_sec_virg-(aux.length()-strlen(value));i++,k++)
            valuesArray[i]=value[k];

        for(int i=0;i<aux.length()-strlen(value);i++)
            for(int j=poz_sec_virg-(aux.length()-strlen(value));j<valuesArray.length();j++)
                valuesArray[j]=valuesArray[j+1];

        valuesArray.resize(newLength);
    }
    
}

string getArrayValue(const char* name,const char* dimArray)
{
    int dimArrayInt = atoi(dimArray);
    string aux;
    int poz_prim_virg, poz_sec_virg;
    int contor_virg = 0, contor_all_virg = 0;
    valuesArray = names.getValue(name);

    for(int i = 0; i<valuesArray.length();i++)
            if(valuesArray[i] == ',')
                contor_all_virg++; 

    if(dimArrayInt == 1)
    {
        poz_prim_virg = -1;
        for(int i = poz_prim_virg+1; i<valuesArray.length(); i++)
            if(valuesArray[i] == ',')
            {   poz_sec_virg = i;
                break;
            }
    }

    else if(dimArrayInt == contor_all_virg+1)
    {

        for(int i = 0; i<valuesArray.length();i++)
        {
            if(valuesArray[i] == ',')
                contor_virg++;
            if(contor_virg == dimArrayInt-1)
            {   
                poz_prim_virg = i;
                break;
            }  
        }

        poz_sec_virg = valuesArray.length();
    }

    else
    {
        for(int i = 0; i<valuesArray.length();i++)
        {
            if(valuesArray[i] == ',')
                contor_virg++;
            if(contor_virg == dimArrayInt-1)
            {   
                poz_prim_virg = i;
                break;
            }  
        }

        for(int i = poz_prim_virg+1; i<valuesArray.length(); i++)
            if(valuesArray[i] == ',')
            {   poz_sec_virg = i;
                break;
            }
    }

    for(int i = poz_prim_virg+1; i<poz_sec_virg;i++)
        aux += valuesArray[i];

    return aux;
}

void typeofPrint()
{
    for (auto e : TypeOfExpressions)
    {
        cout<<"TypeOf evaluated to "<<e.first<< " at line " <<e.second<<endl;
    }
}
void evalPrint()
{
    for (auto e : EvalExpressions)
    {
        cout<<"Eval evaluated to "<<e.first<< " at line " <<e.second<<endl;
    }
}

int main(int argc, char** argv) { 
    yyin=fopen(argv[1],"r");
    yyparse();
}
