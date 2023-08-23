#include "clock.h"

void clockType::setHour(int h)
{
    if (h >= 0 && h <= 23)
    {
        hour = h;
    }
    else
    {
        std::cout << "The hour is invalid. Valid values are between 0 and 23." << std::endl;
        std::cout << "The hour will be set to 0." << std::endl;
        hour = 0;
    }
}

clockType::clockType(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void clockType::setMinute(int m)
{
    if (m >= 0 && m <= 59)
    {
        minute = m;
    }
    else
    {
        std::cout << "The minute is invalid. Valid values are between 0 and 59." << std::endl;
        std::cout << "The minute will be set to 0." << std::endl;
        minute = 0;
    }
}

void clockType::setSecond(int s)
{
    if (s >= 0 && s <= 59)
    {
        second = s;
    }
    else
    {
        std::cout << "The second is invalid. Valid values are between 0 and 59." << std::endl;
        std::cout << "The second will be set to 0." << std::endl;
        second = 0;
    }
}

/*
clockType::clockType()
{
    hour = 0;
    minute = 0;
    second = 0;
}
*/
