#pragma once

#include <iostream>

enum class FoodType
{
    ApplePie,
    HoneyNut,
    Sweetroll,
    PoisonedFood,
    Invalid
};

/********************  FoodItem  ********************/

class FoodItem
{
public:
    FoodItem() = default;
    virtual ~FoodItem() = default;
    FoodType getType();

protected:
    FoodType type = FoodType::Invalid;
};

class ApplePie : public FoodItem
{
public:
    ApplePie();
};

class HoneyNut : public FoodItem
{
public:
    HoneyNut();
};

class Sweetroll : public FoodItem
{
public:
    Sweetroll();
};

class PoisonedFood : public FoodItem
{
public:
    PoisonedFood();
};

/******************** AbstractWizard ********************/

class AbstractWizard
{
public:
    AbstractWizard() = default;

protected:
    virtual FoodType deductFoodItem(FoodItem &item) = 0;
};

/******************** MightyWizard ********************/

class MightyWizard : public AbstractWizard
{
public:
    MightyWizard(std::string _name);
    ~MightyWizard() = default;
    void checkFood(FoodItem &item);
    void checkFood(FoodItem *item);
    FoodType deductFoodItem(FoodItem &item) override;

private:
    std::string name;
};
