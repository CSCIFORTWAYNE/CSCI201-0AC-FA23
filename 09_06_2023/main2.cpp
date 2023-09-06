#include "drink.h"
#include "order.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void resetStream();
void getDrinks(drink **&, int &);
donut *getDonuts(donut *, int &);

int main()
{
    // char more = 'Y';
    drink **drinks;
    donut *donuts;
    order **orders;
    int numDonuts;
    int numDrinks;
    int numOrders;
    std::cout << "How many orders are you placing? ";
    std::cin >> numOrders;
    std::cout << std::endl;

    while (numOrders < 0 || !std::cin)
    {
        if (std::cin.eof())
        {
            std::cout << "There was a problem and there is no more input! Input validation for num orders!" << std::endl;
            return 0;
        }
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "How many orders are you placing? ";
        std::cin >> numOrders;
        std::cout << std::endl;
    }
    orders = new order *[numOrders];
    int count = 0;
    while (count < numOrders)
    {
        getDrinks(drinks, numDrinks);
        donuts = getDonuts(donuts, numDonuts);
        orders[count++] = new order(donuts, numDonuts, drinks, numDrinks);
    }

    // loop through and use toString to print the orders.

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void getDrinks(drink **&drinks, int &numDrinks)
{
    numDrinks = 3;
    // ask the user for the number of drinks and validate
    drinks = new drink *[numDrinks];
    for (int i = 0; i < numDrinks; i++)
    {
        baseType b = static_cast<baseType>(rand() % 3);
        sizeType s = static_cast<sizeType>(rand() % 3);
        tempType t = static_cast<tempType>(rand() % 3);
        std::string dairy = "milk";
        std::string flavor = "raspberry";
        drinks[i] = new drink(b, t, s, dairy, flavor);
    }
}

donut *getDonuts(donut *donuts, int &numDonuts)
{
    numDonuts = rand() % 24 + 1;
    donuts = new donut[numDonuts];
    for (int i = 0; i < numDonuts; i++)
    {
        std::string ice = iceStr[rand() % 7];
        std::string top = topStr[rand() % 16];
        std::string driz = drizzleStr[rand() % 6];
        try
        {
            donuts[i].setIcing(ice);
            donuts[i].setTopping(top);
            donuts[i].setDrizzle(driz);
        }
        catch (...)
        {
            continue;
        }
    }

    return donuts;
}
