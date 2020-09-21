#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define cout std::cout
#define cerr std::cerr
#define endl std::endl
#define cin std::cin
#define invalid_argument std::invalid_argument

using string = std::string;

struct Inventory
{
    std::vector<string> inventory;
    size_t size = 0;
    std::set<string> items = {"a", "f", "p", "w"};

    Inventory() : inventory(12, "-") {}
    void CheckItem(const string &item);

    void Insert(const string &item);
    void Remove(const string &item);
    void Show();
};