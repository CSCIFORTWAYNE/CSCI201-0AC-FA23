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
    yourClock;

    return 0;
}

void setClock(clockType &c)
{
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

    c.setHour(h);
    c.setMinute(m);
    c.setSecond(s);
}