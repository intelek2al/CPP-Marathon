#pragma once

#include <iostream>

struct Wallet
{
    int septims;
};

Wallet *createWallet(const int count);
void destroyWallet(Wallet *wallet);

Wallet *createWallets(size_t size);
void destroyWallets(Wallet *wallet);
