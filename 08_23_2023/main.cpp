#include <iostream>
#include <string>
#include "clock.h"

void setClock(clockType &); // fill in input validation for lecture activity

int main()
{
    clockType myClock(14, 32, 23);
    myClock.setHour(13);
    clockType yourClock;
    yourClock = myClock;
    setClock(yourClock);
    std::cout << yourClock.print();

    return 0;
}

void setClock(clockType &c)
{
    std::string typeOfClock;
    int tod;
    std::cout << "What kind of clock is it?" << std::endl;
    std::cout << "Enter ";
    for (int i = 0; i < 2; i++)
    {
        std::cout << hourToString[i] << " or ";
    }
    std::cout << ": ";
    std::getline(std::cin >> std::ws, typeOfClock);
    std::cout << "Choose the time of day:" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout << i + 1 << ": " << amPmToString[i] << std::endl;
    }
    std::cin >> tod;

    int h, m, s;
    std::cout << "Enter the hour on the clock: ";
    std::cin >> h;
    // input validation goes here
    std::cout << "Enter the minute on the clock: ";
    std::cin >> m;
    // more input validation goes here

    std::cout << "Enter the second on the clock: ";
    std::cin >> s;
    // final input validation goes here

    // c.setHour(h);
    // c.setMinute(m);
    //  c.setSecond(s);
    clockType newClock(h, m, s, typeOfClock, timesOfDay[tod - 1]);
    c = newClock;
}