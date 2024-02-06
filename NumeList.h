#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
struct NumeInfo {
    string type;
    string name;
    string value;
    string domain;
    bool constant;
    int dimension;
};

struct NumeFunc
{
    string name;
    string type;
    vector<string> param;
    string domain;
    int nr_param=0;

    NumeFunc(string name,string type,string domain)
    {
        this->name=name;
        this->type=type;
        this->domain=domain;
    }
    void addParam(string param)
    {
        this->param.push_back(param);
        this->nr_param++;
    }
};

struct NumeClass
{
    string name;
};

struct NumeList {
    vector<NumeInfo> vars;
    vector<NumeFunc> funcs;
    vector<NumeClass> classes;

    public:
    bool existsVar(const char* s);
    bool isConst(const char* name);
    bool existsClass(const char* name);
    bool existsFunc(const char* name);

    string getTypeFunc(const char* name);
    string getTypeVar(const char* name);
    string getValue(const char* name);
    int getNrParamFunc(const char* name);

    void addVar(const char* type, const char* name, const char* value, const char* domain,bool constant,int dimension);
    void addFunc(NumeFunc func);
    void addClass(const char* name);
    void updateValue(const char * name, const char* newValue);
    void printVars();
    void printFuncs();
    void printClass();

    int getDim(const char* name);
    ~NumeList();
};
