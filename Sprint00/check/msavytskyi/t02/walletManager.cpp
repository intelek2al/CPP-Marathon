#include <iostream>
#include "walletManager.h"

Wallet *createWallets(const size_t size)
{
    return new Wallet[size];
}

void destroyWallets(Wallet *wallet)
{
    delete[] wallet;
}

Wallet *createWallet(const int count)
{
    Wallet *tmp = new Wallet;
    tmp->septims = count;
    return tmp;
}

void destroyWallet(Wallet *wallet)
{
    delete wallet;
}
