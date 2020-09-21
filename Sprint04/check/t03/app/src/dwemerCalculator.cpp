#include "dwemerCalculator.h"

// class Calculaor

void Calculator::SetLine(const string &line)
{
    Operate do_op;
    string new_value = Parser(line, do_op);
    resault = do_op.Calculate();
    if (new_value != "")
        db[new_value] = resault;
}
int Calculator::GetResoult()
{
    return resault;
}

auto Calculator::CheckOperand(const string &operand, int i)
{
    int a = 0;
    if (db.count(operand) == 0)
    {
        try
        {
            a = std::stoi(operand);
        }
        catch (const invalid_argument &e)
        {
            throw invalid_argument("invalid operand" + std::to_string(i));
        }
        catch (const std::out_of_range &e)
        {
            throw invalid_argument("operand" + std::to_string(i) + " is out of range");
        }
    }
    else
    {
        return db[operand];
    }
    return a;
}

Operation Calculator::GetOperator(const string &str)
{
    switch (str[0])
    {
    case '+':
        return Operation::Plus;
        break;
    case '-':
        return Operation::Minus;
        break;
    case '*':
        return Operation::Mult;
        break;
    case '/':
        return Operation::Div;
        break;
    default:
    {
        throw invalid_argument("invalid operation");
    }
    }
    return Operation::Plus;
}

string Calculator::Parser(const string &line, Operate &do_op)
{
    std::cmatch resault;
    std::regex regular("\\s*([a-zA-Z]+|[\\-\\+]?[\\d]+)\\s*([\\+\\-\\*\\/])\\s*([a-zA-Z]+|[\\-\\+]?[\\d]+)\\s*(?:=\\s*([a-zA-Z]+))?\\s*");
    if (!std::regex_match(line.c_str(), resault, regular))
    {
        throw invalid_argument("invalid input");
    }
    auto oper1 = CheckOperand(string(resault[1]), 1);
    auto oper2 = CheckOperand(string(resault[3]), 2);
    Operation op = GetOperator(string(resault[2]));
    do_op.SetOperate(oper1, op, oper2);
    if (resault.size() > 4)
    {
        return string(resault[4]);
    }
    return "";
}

// Class Operate

Operate::Operate(int _a, Operation _o, int _b) : a(_a), op(_o), b(_b) {}

void Operate::SetOperate(int _a, Operation _o, int _b)
{
    a = _a;
    op = _o;
    b = _b;
}
int Operate::Calculate()
{
    switch (op)
    {
    case Operation::Plus:
        return a + b;
    case Operation::Minus:
        return a - b;
    case Operation::Mult:
    {
        auto mult = a * b;
        if (mult > INT_MAX || mult < INT_MIN)
            throw invalid_argument("resauld is not int range");
        return mult;
    }
    case Operation::Div:
    {
        if (b == 0)
            throw invalid_argument("division by zero");
        return a / b;
    }
    }
}
