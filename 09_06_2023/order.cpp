#include "order.h"

order::order(const donut *const donuts, int numDonuts, drink **const drinks, int numDrinks)
{
    this->numDonuts = numDonuts;
    this->donuts = new donut[numDonuts];
    for (int i = 0; i < numDonuts; i++)
    {
        this->donuts[i] = donuts[i];
    }
    this->numDrinks = numDrinks;
    this->drinks = new drink *[numDrinks];
    for (int i = 0; i < numDrinks; i++)
    {
        this->drinks[i] = new drink(*(drinks[i]));
    }
}

order::order(const order &otherOrder)
{
    this->numDonuts = otherOrder.numDonuts;
    this->donuts = new donut[this->numDonuts];
    for (int i = 0; i < this->numDonuts; i++)
    {
        this->donuts[i] = otherOrder.donuts[i];
    }
    this->numDrinks = otherOrder.numDrinks;
    this->drinks = new drink *[this->numDrinks];
    for (int i = 0; i < this->numDrinks; i++)
    {
        this->drinks[i] = new drink(*(otherOrder.drinks[i]));
    }
}

std::string order::tostring()
{
    return std::string();
}

order::~order()
{
    for (int i = 0; i < numDrinks; i++)
    {
        delete drinks[i];
        drinks[i] = nullptr;
    }
    delete[] drinks;
    drinks = nullptr;

    delete[] donuts;
    donuts = nullptr;
}
