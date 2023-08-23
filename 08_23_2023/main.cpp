#include <iostream>
#include <string>
#include "clock.h"

int main()
{
    clockType myClock(14, 32, 23);
    myClock.setHour(13);
    clockType yourClock;
    yourClock = myClock;

    return 0;
}