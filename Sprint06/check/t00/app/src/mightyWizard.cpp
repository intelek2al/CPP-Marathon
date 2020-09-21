#include <string>
#include "mightyWizard.h"

/********************  FoodItem  ********************/

FoodType FoodItem::getType()
{
    return type;
}

ApplePie::ApplePie()
{
    type = FoodType::ApplePie;
}


HoneyNut::HoneyNut()
{
    type = FoodType::HoneyNut;
}


Sweetroll::Sweetroll()
{
    type = FoodType::Sweetroll;
}


PoisonedFood::PoisonedFood()
{
    type = FoodType::PoisonedFood;
}


/******************** MightyWizard ********************/

MightyWizard::MightyWizard(std::string _name)
{
    name = _name;
}
FoodType MightyWizard::deductFoodItem(FoodItem &item)
{
    return item.getType();
}
void MightyWizard::checkFood(FoodItem &item)
{
    switch (deductFoodItem(item))
    {
    case FoodType::ApplePie:
        std::cout << "Apple Pie. Ugh, not again!" << std::endl;
        break;
    case FoodType::Sweetroll:
        std::cout << "Sweetroll. Mmm, tasty!" << std::endl;
        break;
    case FoodType::HoneyNut:
        std::cout << "Honey nut. Mmm, tasty!" << std::endl;
        break;
    case FoodType::PoisonedFood:
        std::cout << "Poison. Ugh, not again!" << std::endl;
        break;
    case FoodType::Invalid:
        std::cout << "Poison. Ugh, not again!" << std::endl;
        break;
    }
}
void MightyWizard::checkFood(FoodItem *item)
{

    if (item)
        switch (deductFoodItem(*item))
        {
        case FoodType::ApplePie:
            std::cout << "Apple Pie. Ugh, not again!" << std::endl;
            break;
        case FoodType::Sweetroll:
            std::cout << "Sweetroll. Mmm, tasty!" << std::endl;
            break;
        case FoodType::HoneyNut:
            std::cout << "Honey nut. Mmm, tasty!" << std::endl;
            break;
        case FoodType::PoisonedFood:
            std::cout << "Poison. Ugh, not again!" << std::endl;
            break;
        default:
            std::cout << "<wtf>. Ugh, not again!" << std::endl;
            break;
        }
    else
        std::cout << "<wtf>. Ugh, not again!" << std::endl;
}
