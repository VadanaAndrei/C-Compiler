%{
#include <iostream>
#include <cstring>
#include "VasT.tab.h"
using namespace std;
%}

%option noyywrap

%%
"int"|"float"|"char"|"bool"|"string" {yylval.string = strdup(yytext); return TYPE;}
"INT"|"FLOAT"|"CHAR"|"BOOL"|"STRING" {yylval.string = strdup(yytext); return TYPE_F;}
"return" {yylval.string = strdup(yytext); return RETURN;}
"Eval" {yylval.string = strdup(yytext); return EVAL;}
"TypeOf" {yylval.string = strdup(yytext); return TYPEOF;}
"start" {yylval.string = strdup(yytext); return START;} 
"finish" {yylval.string = strdup(yytext); return FINISH;}
"const" {yylval.string = strdup(yytext); return CONST;}
"class" {yylval.string = strdup(yytext); return CLASS_INIT;}
"CLASS" {yylval.string = strdup(yytext); return CLASS;}
"if" {yylval.string = strdup(yytext); return IF;}
"while" {yylval.string = strdup(yytext); return WHILE;}
"for" {yylval.string = strdup(yytext); return FOR;}
"true" {yylval.string = strdup(yytext); return ADV;}
"false" {yylval.string = strdup(yytext); return FALS;}
"==" {yylval.string = strdup(yytext); return E;}
">" {yylval.string = strdup(yytext); return G;}
"<" {yylval.string = strdup(yytext); return L;}
"<=" {yylval.string = strdup(yytext); return LE;}
">=" {yylval.string = strdup(yytext); return GE;}
"!=" {yylval.string = strdup(yytext); return NE;}
"&&" {yylval.string = strdup(yytext); return AND;}
"||" {yylval.string = strdup(yytext); return OR;}
"++" {yylval.string = strdup(yytext); return INC;}
"--" {yylval.string = strdup(yytext); return DEC;}
"+" {yylval.string = strdup(yytext); return PLUS;}
"*" {yylval.string = strdup(yytext); return MUL;}
"/" {yylval.string = strdup(yytext); return DIV;}
[a-zA-Z][a-zA-Z0-9]* { yylval.string = strdup(yytext); return NUME; }
\[[1-9][0-9]*\] {yylval.string = strdup(yytext); return ARRAY;}
"=" {return ASSIGN;}
(0|[-]?([1-9][0-9]*)) {yylval.string = strdup(yytext); return NR;}
"-" {yylval.string = strdup(yytext); return MINUS;}
\.[0-9]+ {yylval.string = strdup(yytext); return NR_FL;}
[ \t] ;
\n {yylineno++;}
"??"(.*)
. {return yytext[0];}
%%
//[-]?
