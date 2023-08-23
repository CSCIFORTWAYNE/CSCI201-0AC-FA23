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