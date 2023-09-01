#include "clock.h"

void clockType::setHour(int h)
{
    if (type == TWENTYFOUR)
    {
        if (h >= 0 && h <= 23)
        {
            hour = h;
        }
        else
        {
            /* std::cout << "The hour is invalid. Valid values are between 0 and 23." << std::endl;
            std::cout << "The hour will be set to 0." << std::endl;*/
            hour = 0;
            throw hourException(24);
        }
    }
    else
    {
        if (h >= 1 && h <= 12)
        {
            hour = h;
        }
        else
        {
            hour = 1;
            throw hourException(12);
        }
    }
}

clockType::clockType(int h, int m, int s, hourType t, amPmType tod)
{
    type = t;
    timeOfDay = tod;
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

void clockType::setClockType(hourType h)
{
    type = h;
}

void clockType::setAmPm(amPmType a)
{
    timeOfDay = a;
}

int clockType::getHour() const
{
    return hour;
}

std::string clockType::print() const
{
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hour << ":";
    out << std::setw(2) << minute << ":";
    out << std::setw(2) << second;
    if (type == TWELVE)
    {
        out << " " << amPmToStr.at(timeOfDay);
    }
    else
    {
        out << std::endl;
        out << hourTypeToStr.at(type) << std::endl;
    }
    return out.str();
}

/*
clockType::clockType()
{
    hour = 0;
    minute = 0;
    second = 0;
}
*/
