#include "inventory.h"

void Inventory::CheckItem(const string &item)
{
    if (items.count(item) == 0)
        throw invalid_argument("Invalid item.");
}

void Inventory::Insert(const string &item)
{

    CheckItem(item);
    if (size < 12)
    {
        inventory[size] = item;
        size++;
    }
    else
        throw invalid_argument("Inventory is full.");
}
void Inventory::Remove(const string &item)
{
    CheckItem(item);
    auto it = find(inventory.begin(), inventory.end(), item);
    if (it == inventory.end())
    {
        throw invalid_argument("Invalid item.");
    }
    inventory.erase(it);
    inventory.push_back("-");
    size--;
}
void Inventory::Show()
{
    cout << "Inventory { ";
    for (const auto &it : inventory)
        cout << it << " ";
    cout << "}" << endl;
}
