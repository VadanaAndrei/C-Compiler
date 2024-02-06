%{
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
%}

%union {
    char* string;
}

%token START FINISH ASSIGN 
%token<string> NUME TYPE CLASS TYPE_F IF WHILE FOR FALS ADV INC DEC RETURN CLASS_INIT EVAL TYPEOF NR CONST NR_FL ARRAY PLUS MINUS MUL DIV E G GE L LE NE AND OR
%type<string> expr

%left PLUS MINUS
%left MUL DIV
%left E G GE L LE NE AND OR

%start program

%%
program: clase antet functii corp 
        { cout << "The program is correct!" << endl; names.printVars(); names.printFuncs(); typeofPrint(); evalPrint();}
    ;

clase: decl_class
    | /*empty*/
    ;

antet: {currentDomain="global";} decl_var 
    | /*empty*/
    ;

functii: decl_func
    | /*empty*/
    ;

decl_class: CLASS NUME '{' 
        { 
            if(names.existsClass($2)==true)
            {
                yyerror("This class already exists");
                YYABORT;
            }
            else 
            {
                names.addClass($2);
            }
            ok_class=1; 
            currentDomain=concatValue("class ",$2);
        } decl_var decl_func '}' ';' {ok_class=0;}
    | decl_class CLASS NUME '{' 
        {
            if(names.existsClass($3)==true)
            {
                yyerror("This class already exists");
                YYABORT;
            }
            else 
            {
                names.addClass($3);
            }
            ok_class=1; 
            currentDomain=concatValue("class ",$3);
        } decl_var decl_func '}' ';' {ok_class=0;}
    ;

decl_func: TYPE_F NUME '(' 
        {   
            if(names.existsFunc($2)==false)
            {
                nume_functie=$2;
                if(ok_class==1)
                {
                    NumeFunc f($2,$1,currentDomain);
                    names.addFunc(f);
                }
                else 
                { 
                    NumeFunc f($2,$1,"global");
                    names.addFunc(f);
                }
            }
            else 
            {
                yyerror("This function already exists");
                YYABORT;
            }
            currentDomain=concatValue("function ",$2);
        } 
        var_func ')' 
        '{' decl_var RETURN expr 
                    { 
                        string tip_functie=$1; 
                        string tip_func_lower;
                        for(char c : tip_functie)
                            tip_func_lower += tolower(c);

                        if(typeExpr!=tip_func_lower) 
                        {   
                            yyerror("The return value is not the same type as the function");
                            YYABORT;
                        }  
                    } ';' '}'
    | decl_func TYPE_F NUME '('  
        {   
            if(names.existsFunc($3)==false)
            {
                nume_functie=$3;
                if(ok_class==1)
                {
                    NumeFunc f($3,$2,currentDomain);
                    names.addFunc(f);
                }
                else 
                {
                    NumeFunc f($3,$2,"global");
                    names.addFunc(f);
                }
            }
            else
            {
                yyerror("This function already exists");
                YYABORT;
            }
            currentDomain=concatValue("function ",$3);
            
        }  var_func ')' '{' decl_var RETURN expr 
                    { 
                        string tip_functie=$2; 
                        string tip_func_lower;
                        for(char c : tip_functie)
                            tip_func_lower += tolower(c);

                        if(typeExpr!=tip_func_lower) 
                        {   
                            yyerror("The return value is not the same type as the function");
                            YYABORT;
                        }  
                    } ';' '}'
    ;

var_func: TYPE NUME 
        {
            for(auto& f: names.funcs){
                if(f.name == nume_functie)
                    f.addParam($1);
              
            }
        }
    | TYPE NUME 
        {
            for(auto& f: names.funcs){
                if(f.name == nume_functie)
                    f.addParam($1);
            }
        } var_func
    | ',' var_func
    ;

corp: START { currentDomain = "main"; } main FINISH
    ;

main: decl_var 
    | instr
    | decl_var '@' main
    | instr '@' main
    | /*empty*/
    ;

decl_var: var ';'
    | decl_var var ';'
    ;

var: TYPE NUME 
        {
            if(existDecl($1, $2, "null", currentDomain,false,1)==true) 
            {
                yyerror("Variable already declared");
                YYABORT;
            } 
            currentType = $1; 
            ok_type=true;
        } 
        asg {ok_type=false;}
    | TYPE NUME dim_array 
        {   
            int arrayDimInt=atoi(arrayDim);    
            for(int i=0;i<arrayDimInt-1;i++)
                insertInArray($2,arrayDim,"null");
            valuesArray+="null";
            if(existDecl($1, $2, valuesArray.c_str() , currentDomain,false,currentDim)==true) 
            {
                yyerror("Variable already declared");
                YYABORT;
            }  
            valuesArray.clear();
            currentType = $1;
            ok_type=true;
        } 
        asg {ok_type=false;}
    | TYPE NUME dim_array ASSIGN '{' {currentType=$1; restOfDim=atoi(arrayDim);} val_array '}'  
        {
            if(restOfDim>0)
            {
                valuesArray+=",";
                for(int i=0;i<restOfDim-1;i++)
                    valuesArray+="null,";
                valuesArray+="null";
            }
            if(existDecl($1,$2,valuesArray.c_str(),currentDomain,false,currentDim)==true)
            {
                yyerror("Variable already declared");
                YYABORT;
            }  
            currentType = $1;
            currentNume = $2;
            ok_type=true;
            valuesArray.clear();
        }  asg {ok_type=false;}
   
    | TYPE NUME ASSIGN expr 
        {
           
            
            if(typeExpr!=$1)
            {
                yyerror("Types don't match");
                YYABORT;
            }
            else
            {
                if(existDecl($1, $2, currentValue, currentDomain,false,1)==true) 
                {
                    yyerror("Variable already declared"); //aici
                    YYABORT;
                } 
                currentType = $1;
                ok_type=true;
                typeExpr.clear();
            }
        } asg {ok_type=false;}
    | TYPE NUME ASSIGN apel_func 
        {
        
            ok_type=true;
            string tip_functie=names.getTypeFunc(currentNume); 
            string tip_func_lower;
                for(char c : tip_functie)
                    tip_func_lower += tolower(c);
            
            if($1==tip_func_lower)
            {
                if(existDecl($1, $2, "null", currentDomain,false,1)==true) 
                {
                    yyerror("Variable already declared");
                    YYABORT; currentType = $1;
                }
            }
            else
            {
                yyerror("Types don't match");
                YYABORT;
            } 
            currentType=$1;
        } asg {ok_type=false;}
    | TYPE NUME ASSIGN NUME '.' apel_func 
    {
        ok_type=1;
        if(names.existsClass($4)==0)
        {
            yyerror("The class doesn't exist");
            YYABORT;
        }
        string tip_functie=names.getTypeFunc(currentNume); 
        string tip_func_lower;
        for(char c : tip_functie)
            tip_func_lower += tolower(c);
       
        if($1==tip_func_lower)
        {
             if(existDecl($1, $2, "null", currentDomain,false,1)==true) 
            {
                yyerror("Variable already declared");
                YYABORT; currentType = $1;
            }
        }
        else
        {
            yyerror("Types don't match");
            YYABORT;
        } 
        currentType=$1;
    } asg {ok_type=false;}

    | CONST TYPE NUME ASSIGN expr  
        {
            if(typeExpr!=$2)
            {
                yyerror("Types don't match");
                YYABORT;
            }
            else
            {
                if(existDecl($2, $3, currentValue, currentDomain,true,1)) 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                }
            }  
            currentType = $2;
            typeExpr.clear();
        } asg_const

    | CLASS_INIT NUME NUME 
        {
            if(names.existsClass($2)==false)
            {
                yyerror("This class doesn't exist");
                YYABORT;
            }
            else
                if(existDecl($2,$3 , "null", currentDomain,false,1)) 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                } 
            currentType = $2;
        }
    | EVAL {ok_eval=1;} '(' expr ')' 
        {
            if(ok_func==1)
            {
                yyerror("Eval doesn't support functions");
                YYABORT;
            }
            if(isdigit($4[0])!=0)
                EvalExpressions.push_back(pair<string, int>(string($4), yylineno));
            else
                EvalExpressions.push_back(pair<string, int>(string(names.getValue($4)), yylineno));
            ok_eval=0;
            ok_func=0;
        }
    | TYPEOF {ok_typeof=1;} '(' expr ')' 
        {            
            if(ok_func==1)
            {
                yyerror("TypeOf doesn't support functions");
                YYABORT;
            }
            if(isdigit($4[0])!=0)
                TypeOfExpressions.push_back(pair<string, int>(string(finalType), yylineno));
            else 
                TypeOfExpressions.push_back(pair<string, int>(string(names.getTypeVar(currentVar)), yylineno));
            ok_typeof=0;
            ok_func=0;
        }
    | asg
    ;

val_array : expr 
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
    |   expr 
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
        } ',' val_array 
    ;

dim_array : ARRAY {arrayDim=getArrayDim($1); currentDim=atoi(arrayDim); } dim_array
        | ARRAY {arrayDim=getArrayDim($1); currentDim=atoi(arrayDim);}
        ;

asg_const : NUME ASSIGN expr 
            {
                if(existDecl(currentType, $1, currentValue, currentDomain,true,1)) 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                } 
            } asg_const
    | ',' asg_const
    | /*empty*/ 
    ;

asg: NUME ASSIGN expr 
        {
            if(names.isConst($1)==true) 
            {
                yyerror("This variable is a constant");
                YYABORT;
            } 
    
            if(ok_type==true)
            {
                if(verifExist($1)==false) 
                    names.addVar(currentType,$1,currentValue,currentDomain,false,currentDim); 
                else 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                } 
            }
            else 
            {
              
                if(verifExist($1)==true)
                {     
                    names.updateValue($1,currentValue);   
                    if(typeExpr!=names.getTypeVar($1))
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
        } asg 
    | NUME 
        {
            if(ok_type==true)
            {
                if(verifExist($1)==false) 
                    names.addVar(currentType,$1,"null",currentDomain,false,currentDim); 
                else 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                }
            }
            else 
            { 
                if(verifExist($1)==true)
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
        } asg 
    | NUME dim_array
        {
            if(ok_type==true)
            {
                int arrayDimInt=atoi(arrayDim);
                for(int i=0;i<arrayDimInt-1;i++)
                    valuesArray+="null,";
                valuesArray+="null";
                if(verifExist($1)==false) 
                    names.addVar(currentType,$1,valuesArray.c_str(),currentDomain,false,currentDim); 
                else 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                }
                valuesArray.clear();
            }
            else 
            { 
                if(verifExist($1)==true)
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
        } asg 
    | NUME dim_array ASSIGN '{' {restOfDim=atoi(arrayDim);} val_array '}'
        {

            if(ok_type==false)
            {
                if(verifExist($1)==true)
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

            if(existDecl(currentType,$1,valuesArray.c_str(),currentDomain,false,currentDim)==true)
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
            names.updateValue($1,valuesArray.c_str());
            valuesArray.clear();
        }  asg 
    | NUME dim_array ASSIGN expr
        {
            int arrayDimInt=currentDim;
            if(arrayDimInt>names.getDim($1))
            {
                yyerror("Wrong dimension of array");
                YYABORT;
            }
            updateValuesArray(arrayDim, $1, currentValue);
            if(ok_type==true)
            {
                if(verifExist($1)==false) 
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
                if(verifExist($1)==true)
                    names.updateValue($1,valuesArray.c_str());
                else 
                {
                    yyerror("Variable wasn't declared");
                    YYABORT;
                }
            }
            valuesArray.clear();
            if(names.getTypeVar($1)!=typeExpr)
            {
                yyerror("Types don't match");
                YYABORT;
            }
        } asg

    | NUME ASSIGN apel_func     
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
                if(verifExist($1)==false) 
                    names.addVar(currentType,$1,"null",currentDomain,false,currentDim); 
                else 
                {
                    yyerror("Variable already declared");
                    YYABORT;
                } 
            }
            else 
            {
                if(verifExist($1)==true)
                    names.updateValue($1,"null");
                else 
                {
                    yyerror("Variable wasn't declared");
                    YYABORT;
                }
            }
            if(tip_func_lower!=names.getTypeVar($1))
            {
                yyerror("Types don't match");
                YYABORT;
            }
        } asg
    | ',' asg 
    |/*empty*/
    ;

instr: IF '(' expr ')' '{' main '}'
    | instr IF '(' expr ')' '{' main '}'
    | WHILE '(' expr ')' '{' main '}'
    | instr WHILE '(' expr ')' '{' main '}'
    | FOR '(' NUME ASSIGN expr ';' expr ';' unar ')' '{' main '}'
    | instr FOR '(' NUME ASSIGN expr ';' expr ';' unar ')' '{' main '}'
    ;

unar: NUME INC
    | NUME DEC
    ;

expr: expr  PLUS
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
            
           
        } expr 
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
                        $$=(char*)(to_string(atoi($1)+atoi($4))).c_str();
                    else if(typeExprRight=="float")
                        $$=(char*)(to_string(atof($1)+atof(currentValue))).c_str();
                       
                }
                else
                {
                    if(typeExprRight=="int")
                        $$=(char*)(to_string(atoi(leftValue)+atoi(currentValue))).c_str();
                    else if(typeExprRight=="float")
                        $$=(char*)(to_string(atof(leftValue)+atof(currentValue))).c_str();
                }
                currentValue=$$;
            }
        }
    | expr MINUS 
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
            
        } expr 
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
                        $$=(char*)(to_string(atoi($1)-atoi($4))).c_str();
                    else if(typeExprRight=="float")
                        $$=(char*)(to_string(atof($1)-atof(currentValue))).c_str();
                }
                else
                {
                    if(typeExprRight=="int")
                        $$=(char*)(to_string(atoi(leftValue)-atoi($4))).c_str();
                    else if(typeExprRight=="float")
                        $$=(char*)(to_string(atof(leftValue)-atof(currentValue))).c_str();
                }
                currentValue=$$;
            }
        }
    | expr MUL
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
        } expr
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
                        $$=(char*)(to_string(atoi($1)*atoi(currentValue))).c_str();
                    else if(typeExprRight=="float")
                        $$=(char*)(to_string(atof($1)*atof(currentValue))).c_str();
                }
                else
                {  
                    if(typeExprRight=="int")
                        $$=(char*)(to_string(atoi(leftValue)*atoi(currentValue))).c_str();
                    else if(typeExprRight=="float")
                        $$=(char*)(to_string(atof(leftValue)*atof(currentValue))).c_str();
                }
                currentValue=$$;
            }
        }
    | expr DIV  
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
        } expr
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
                        $$=(char*)(to_string(atoi($1)/atoi($4))).c_str();
                    else if(typeExprRight=="float")
                        $$=(char*)(to_string(atof($1)/atof(currentValue))).c_str();
                }
                else
                {
                    if(typeExprRight=="int")
                        $$=(char*)(to_string(atoi(leftValue)/atoi(currentValue))).c_str();
                    else if(typeExprRight=="float")
                        $$=(char*)(to_string(atof(leftValue)/atof(currentValue))).c_str();
                }
                currentValue=$$;
            }
        }  
    | '(' {ok_paranteze = 1;} expr ')' {ok_paranteze=0; $<string>$=$3; }
    | '(' MINUS expr ')'
    
        {         
            
            string neg_val;
            neg_val.clear(); 
            neg_val+="-";
            neg_val+=$3;
            $$ = (char*)neg_val.c_str();
            currentValue=$$;
            ok_paranteze=1;
        }
    | expr L 
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=$1;
        }  expr 
        {   
            if(atoi(currentValueSt)<atoi($4))
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
    | expr LE  
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=$1;
        } expr 
        {   
            ok=0;
            if(atoi(currentValueSt)<=atoi($4))
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
    | expr G  
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=$1;
        } expr 
        {   

            if(atoi(currentValueSt)>atoi($4))
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
    | expr GE  
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=$1;
        } expr
        {   
            if(atoi(currentValueSt)>=atoi($4))
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
    | expr E  
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=$1;
        } expr
        {   
            if(atoi(currentValueSt)==atoi($4))
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
    | expr NE  
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=$1;

        } expr
        {   

            if(atoi(currentValueSt)!=atoi($4))
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
    | expr AND 
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=$1;
        } expr 
        {
            if(atoi(currentValueSt) && atoi($4))
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
    | expr OR  
        {
            ok_bool=1;
            if(ok==0)
                currentValueSt=$1;
        } 
        expr 
        {
            if(atoi(currentValueSt) || atoi($4))
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
    | '@' { ok_tipuri=1;} apel_func { ok_func=1;}
    | NR NR_FL 
        {
            typeExpr.clear(); 
            if(ok_bool==true) 
                typeExpr="bool"; 
            else {finalType="float";typeExpr+="float";} 
            ok_bool=0;
            currentValue=concatValue($1,$2); 
        }
    | NR 
        {  typeExpr.clear();
            if(ok_bool==true) 
                typeExpr="bool"; 
            else  {finalType="int";typeExpr+="int";} 
            ok_bool=0; 
            currentValue = $1; 
        }
    | NUME  
        { 
            currentVar=$1;
            if(ok_tipuri!=1)  
            {
                if(verifExist($1)==false) 
                {
                    yyerror("Variable wasn't declared");
                    YYABORT;
                }
                else
                {
                     if(ok_bool==true) 
                        typeExpr="bool"; 
                    else  typeExpr=names.getTypeVar($1);
                    ok_bool=0; 
                    currentValue = names.getValue($1).c_str();
                }
            }
           ok_tipuri=0;
        }
    | NUME ARRAY
        {
            if(verifExist($1)==false) 
            {
                yyerror("Variable wasn't declared");
                YYABORT;
            }
            else
            {   int arrayDimInt=atoi(getArrayDim($2));
                if(arrayDimInt>names.getDim($1))
                {
                    yyerror("Wrong dimension of array");
                    YYABORT;
                }
                else
                {

                    if(ok_bool==true) 
                        typeExpr="bool"; 
                    else  typeExpr=names.getTypeVar($1);
                    ok_bool=0; 
                    currentValue = getArrayValue($1,getArrayDim($2)).c_str();
                }
            }
        }
        | ADV 
            {
                typeExpr="bool";
                currentValue="true";
            }
        | FALS
            {
                typeExpr="bool";
                currentValue="false";
            }
        | '\'' NUME '\'' 
            {    
                lungime_char=strlen($2);
                if(lungime_char!=1)
                {
                    yyerror("Char supports only one character");
                    YYABORT;
                } 
                typeExpr="char"; 
                finalType="char";
                currentValue=$2;
            }
        | '\'' NR '\'' { typeExpr="char"; currentValue=$2; finalType="char";}
        | '\"' NUME '\"' { typeExpr="string"; currentValue=$2; finalType="string";}
        | '\"' NR '\"' { typeExpr="string"; currentValue=$2; finalType="string";} 
    ;

apel_func: NUME {currentNume=$1;} '(' param 
        {
            numeFunc=$1;
            if(names.existsFunc(currentNume)==false)
            {
                yyerror("Function doesn't exist");
                YYABORT;
            }

            contor_param++;
            if(contor_param!=names.getNrParamFunc($1))
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
        } ')' 
    ;

param: expr 
        {   
            types_param.push_back(typeExpr);
        } param
    | ',' param {contor_param++;} 
    | /* empty */
    ;

%%

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