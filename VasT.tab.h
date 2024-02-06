/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_VAST_TAB_H_INCLUDED
# define YY_YY_VAST_TAB_H_INCLUDED
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
    START = 258,                   /* START  */
    FINISH = 259,                  /* FINISH  */
    ASSIGN = 260,                  /* ASSIGN  */
    NUME = 261,                    /* NUME  */
    TYPE = 262,                    /* TYPE  */
    CLASS = 263,                   /* CLASS  */
    TYPE_F = 264,                  /* TYPE_F  */
    IF = 265,                      /* IF  */
    WHILE = 266,                   /* WHILE  */
    FOR = 267,                     /* FOR  */
    FALS = 268,                    /* FALS  */
    ADV = 269,                     /* ADV  */
    INC = 270,                     /* INC  */
    DEC = 271,                     /* DEC  */
    RETURN = 272,                  /* RETURN  */
    CLASS_INIT = 273,              /* CLASS_INIT  */
    EVAL = 274,                    /* EVAL  */
    TYPEOF = 275,                  /* TYPEOF  */
    NR = 276,                      /* NR  */
    CONST = 277,                   /* CONST  */
    NR_FL = 278,                   /* NR_FL  */
    ARRAY = 279,                   /* ARRAY  */
    PLUS = 280,                    /* PLUS  */
    MINUS = 281,                   /* MINUS  */
    MUL = 282,                     /* MUL  */
    DIV = 283,                     /* DIV  */
    E = 284,                       /* E  */
    G = 285,                       /* G  */
    GE = 286,                      /* GE  */
    L = 287,                       /* L  */
    LE = 288,                      /* LE  */
    NE = 289,                      /* NE  */
    AND = 290,                     /* AND  */
    OR = 291                       /* OR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "VasT.y"

    char* string;

#line 104 "VasT.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_VAST_TAB_H_INCLUDED  */
