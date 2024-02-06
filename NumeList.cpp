#include "NumeList.h"
using namespace std;

ofstream fout("output.txt");


void NumeList::addVar(const char* type, const char*name, const char* value, const char* domain,bool constant,int dimension) {
    NumeInfo var = {string(type), string(name), string(value), string(domain),bool(constant),int(dimension)};
    vars.push_back(var);
}

void NumeList::addFunc(NumeFunc func)
{
    funcs.push_back(func);
}

void NumeList::addClass(const char* name)
{
    NumeClass clasa = {string(name)};
    classes.push_back(clasa);
}

void NumeList::printClass()
{
    for (const NumeClass& c : classes) {
        cout <<"class: " <<c.name<< endl; 
    }
}

bool NumeList::isConst(const char* name) {
    for (auto& v : vars)
        if (v.name == name && v.constant==true)
            return true;
    return false;
}

void NumeList :: updateValue(const char * name, const char* newValue)
{
    for (auto& v : vars)
        if (v.name == name)
            v.value = newValue;
}

bool NumeList::existsVar(const char* var) {
    string strvar = string(var);
     for (const NumeInfo& v : vars) {
        if (strvar == v.name) { 
            return true;
        }
    }
    return false;
}

bool NumeList::existsFunc(const char* name)
{
    string strvar = string(name);
    for (const NumeFunc& f : funcs) {
        if (strvar == f.name) { 
            return true;
        }
    }
    return false;
}

bool NumeList::existsClass(const char* name)
{
    string strvar = string(name);
    for (const NumeClass& c : classes) {
        if (strvar == c.name) { 
            return true;
        }
    }
    return false;
}


void NumeList::printVars() {
    fout<<"Symbol table for variables"<<endl;
    for (const NumeInfo& v : vars) {
        fout <<"const: " <<v.constant<<" | "<<"name: " << v.name<<" | "  << "type: " << v.type <<" | " << "value: " << v.value<<" | " << "domain: " << v.domain << endl; 
     }
}

void NumeList::printFuncs() {

    fout<<endl;
    fout<<"Symbol table for functions"<<endl;
    for (const NumeFunc& f : funcs) {
        fout <<"name: " <<f.name<<" | "  << "type: " << f.type<<" | " << "domain: " << f.domain << endl; 
        for(auto p: f.param){
            fout<<"param_type: "<<p<<endl;
        }
     }
}

string NumeList ::getTypeFunc(const char* name)
{
    for (auto& f : funcs)
        if (f.name == name)
            return f.type;
    return "nimic";
}

int NumeList::getNrParamFunc(const char* name)
{
    for (auto& f : funcs)
        if (f.name == name)
            return f.nr_param;
    return 0;
}


int NumeList :: getDim(const char* name)
{
     for (auto& v : vars)
        if (v.name == name)
            return v.dimension;
    return 0;
}

string NumeList :: getTypeVar(const char* name)
{
    for (auto& v : vars)
        if (v.name == name)
            return v.type;
    return "nimic";
}


string NumeList :: getValue (const char* name)
{
    for (auto& v : vars)
        if (v.name == name)
            return v.value;
    return "nimic";
}

NumeList::~NumeList() {
    vars.clear();
}










