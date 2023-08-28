#include "clock.h"

void clockType::setHour(int h)
{
    if (h >= 0 && h <= 23)
    {
        hour = h;
    }
    else
    {
        /* std::cout << "The hour is invalid. Valid values are between 0 and 23." << std::endl;
        std::cout << "The hour will be set to 0." << std::endl;
        hour = 0; */
        throw hourException();
    }
}

clockType::clockType(int h, int m, int s, std::string t, amPmType tod)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
    type = TWENTYFOUR;
    timeOfDay = PM;
    std::transform(t.begin(), t.end(), t.begin(), ::tolower);
    bool set = false;
    for (int i = 0; i < 2; i++)
    {
        if (t == hourToString[i])
        {
            type = availableTypes[i];
            set = true;
        }
    }
    if (set == false)
    {
        type = TWENTYFOUR;
    }
    timeOfDay = tod;
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
        out << " " << amPmToString[timeOfDay];
    }
    else
    {
        out << std::endl;
        out << hourToString[type] << std::endl;
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
