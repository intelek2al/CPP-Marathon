#pragma once

#include <iostream>
#include <vector>

namespace UniversalReferenceDeterminant
{

    static std::string get_type(const char *c)
    {
        switch (*c)
        {
        case 'i':
            return "int";
        case 'f':
            return "float";
        case 'd':
            return "double";
        case 'c':
            return "char";
        case 'l':
            return "long";
        case 'j':
            return "unsigned int";
        case 's':
            return "short";
        }
        return "";
    }

    template <typename T>
    void determineReference(T &&obj)
    {
        if (std::is_lvalue_reference<T>())
        {
            std::cout << get_type(typeid(obj).name()) << " is l-value reference" << std::endl;
        }
        else if (!std::is_rvalue_reference<T>())
        {
            std::cout << get_type(typeid(obj).name()) << " is r-value reference" << std::endl;
        }
    }
} // namespace UniversalReferenceDeterminant
