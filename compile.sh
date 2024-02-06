#!/bin/bash

echo "compiling $1"
rm -f lex.yy.c
rm -f $1.tab.c
rm -f $1
rm -f $1.tab.h
bison -Wcounterexamples -d $1.y
lex $1.l
g++ NumeList.cpp lex.yy.c  $1.tab.c -std=c++11 -o $1
