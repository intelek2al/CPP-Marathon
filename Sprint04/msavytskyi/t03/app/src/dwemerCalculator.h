#pragma once

#include <map>
#include <regex>
#include <algorithm>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define cerr std::cerr
#define string std::string
#define invalid_argument std::invalid_argument

enum class Operation
{
    Plus,
    Minus,
    Mult,
    Div
};

class Operate
{
public:
    Operate(int _a, Operation _o, int _b);
    Operate() = default;
    ~Operate() = default;
    void SetOperate(int _a, Operation _o, int _b);
    int Calculate();

private:
    int a;
    Operation op;
    int b;
};

class Calculator
{
public:
    Calculator() = default;
    ~Calculator() = default;
    void SetLine(const string &line);
    int GetResoult();

private:
    auto CheckOperand(const string &operand, int i);
    Operation GetOperator(const string &str);
    string Parser(const string &line, Operate &do_op);
    int resault;
    std::map<string, int> db;
};
