#include "drink.h"
#include "intList.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <sstream>

void codeGradeLoopFix(std::string errLocation);
void resetStream();
void createDrink(drink *&);
baseType chooseBase();
sizeType chooseSize();
tempType chooseTemp();
void printObject(drink object);
template <class t>
std::string toString(t obj);
int main()
{
    drink **mydrinks;
    int numDrinks;
    int *x = NULL;
    x = new int[0];
    int *y = NULL;
    y = new int[1];
    x[0] = 7;
    y[0] = 14;
    if (x == y)
        std::cout << "true" << std::endl;
    // std::cout << x[0] << std::endl;
    std::cout << "How many drinks would you like? ";
    std::cin >> numDrinks;
    std::cout << std::endl;
    while (!std::cin || numDrinks <= 0)
    {
        codeGradeLoopFix("Num drinks");
        if (!std::cin)
            resetStream();
        std::cout << "You entered an invalid value. You should enter a number greater than 0." << std::endl;
        std::cout << "How many drinks would you like? ";
        std::cin >> numDrinks;
        std::cout << std::endl;
    }
    mydrinks = new drink *[numDrinks];
    for (int i = 0; i < numDrinks; i++)
    {
        createDrink(mydrinks[i]);
    }
    for (int i = 0; i < numDrinks; i++)
    {
        printObject(*mydrinks[i]);
        std::cout << std::endl;
    }
    drink newDrink(*(mydrinks[0]));
    printObject(newDrink);

    intList ints;
    ints = ints + 7;
    intList list2(ints);
    intList list3(20);
    for (int i = 0; i < 20; i++)
    {
        list3 + i;
    }
    intList *list4;
    list4 = new intList(list3);

    std::cout << ints << std::endl;
    std::cout << list2 << std::endl;
    std::cout << list3 << std::endl;
    std::cout << *list4 << std::endl;

    list3 + 18;
    std::cout << list3 << std::endl;

    std::cout << "Enter 9 numbers to add to the list: ";
    std::cin >> list2;
    std::cout << std::endl;
    std::cout << list2 << std::endl;
    ints + 10;
    ints + 18;
    ints + 27;
    // std::cout << toString(*(mydrinks[0]));
    std::cout << toString(7.8) << std::endl;
    std::cout << toString(ints) << std::endl;
    std::cout << toString("hello world");

    return 0;
}

void codeGradeLoopFix(std::string errLocation)
{
    if (std::cin.eof())
    {
        std::cout << "There was a problem and there is no more input! @" + errLocation << std::endl;
        throw std::invalid_argument(errLocation); // return or throw an exception here to force the program to end or return from the function.
    }
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void createDrink(drink *&d)
{
    baseType base = chooseBase();
    sizeType size = chooseSize();
    tempType temp = chooseTemp();
    std::string dairyStr, flavorStr;
    std::cout << "Enter your dairy choice: ";
    std::getline(std::cin >> std::ws, dairyStr);
    std::cout << std::endl;
    codeGradeLoopFix("dairy");
    std::cout << "What flavor would you like? ";
    std::getline(std::cin >> std::ws, flavorStr);
    std::cout << std::endl;
    d = new drink(base, temp, size, dairyStr, flavorStr);
}

baseType chooseBase()
{
    std::string b;
    std::cout << "Choose the drink base (Coffee, Tea, Cream): ";
    std::cin >> b;
    std::cout << std::endl;
    std::transform(b.begin(), b.end(), b.begin(), ::toupper);
    while (!strBase.count(b))
    {
        codeGradeLoopFix("base");
        std::cout << "Choose the drink base (Coffee, Tea, Cream): ";
        std::cin >> b;
        std::cout << std::endl;
        std::transform(b.begin(), b.end(), b.begin(), ::toupper);
    }

    return strBase.at(b);
}

sizeType chooseSize()
{
    std::string s;
    std::cout << "Choose the drink size (s, m, l): ";
    std::cin >> s;
    std::cout << std::endl;
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    while (!strSize.count(s))
    {
        codeGradeLoopFix("size");
        std::cout << "Choose the drink size (s, m, l): ";
        std::cin >> s;
        std::cout << std::endl;
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    }

    return strSize.at(s);
}

tempType chooseTemp()
{
    std::string t;
    std::cout << "Choose the drink temperature ((I)ced, (B)lend, (H)ot): ";
    std::cin >> t;
    std::cout << std::endl;
    std::transform(t.begin(), t.end(), t.begin(), ::toupper);
    while (!strTemp.count(t))
    {
        codeGradeLoopFix("temp");
        std::cout << "Enter I, B, or H for the dirnk temperature: ";
        std::cin >> t;
        std::cout << std::endl;
        std::transform(t.begin(), t.end(), t.begin(), ::toupper);
    }

    return strTemp.at(t);
}

void printObject(drink object)
{
    std::cout << "Size: " << object.getSize() << std::endl;
    std::cout << "Base: " << object.getBaseStr() << std::endl;
    std::cout << "Temperature: " << object.getTemperature() << std::endl;
    std::cout << "Flavor: " << object.getFlavor() << std::endl;
    std::cout << "Dairy: " << object.getDairy() << std::endl; // 1*
    std::cout << "Price: $" << std::fixed << std::setprecision(2) << object.getPrice() << std::endl;
}

template <class t>
std::string toString(t obj)
{
    std::ostringstream out;
    out << obj;
    return out.str();
}
