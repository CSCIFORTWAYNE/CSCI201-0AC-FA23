#include "clock.h"

std::map<hourType, std::string> clockType::hourTypeToStr = {{TWELVE, "12 hour clock"}, {TWENTYFOUR, "24 hour clock"}};
std::map<amPmType, std::string> clockType::amPmToStr = {{AM, "AM"}, {PM, "PM"}};
std::map<int, hourType> clockType::intToHourType = {{12, TWELVE}, {24, TWENTYFOUR}};
std::map<std::string, amPmType> clockType::strToAmPm = {{"AM", AM}, {"PM", PM}};

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
        throw minuteException();
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
        throw secondException();
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

int clockType::getMinute() const
{
    return minute;
}

int clockType::getSecond() const
{
    return second;
}

void clockType::incrementSecond()
{
    second++;
    if (second > 59)
    {
        second = 0;
        incrementMinute();
    }
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

bool clockType::operator>(const clockType &otherClock) const
{
    int cH = this->hour;       // corrected version for 12 hour clocks
    int ocH = otherClock.hour; // corrected otherclock for 12 hour clocks
    if (this->type == TWELVE && this->timeOfDay == PM && this->hour < 12)
    {
        cH = this->hour + 12;
    }
    else if (this->type == TWELVE && this->timeOfDay == AM && this->hour == 12)
    {
        cH = 0;
    }
    if (otherClock.type == TWELVE && otherClock.timeOfDay == PM && otherClock.hour < 12)
    {
        ocH = otherClock.hour + 12;
    }
    else if (otherClock.type == TWELVE && otherClock.timeOfDay == AM && otherClock.hour == 12)
    {
        ocH = 0;
    }

    if (cH == ocH)
    {
        if (this->minute == otherClock.minute)
        {
            if (this->second > otherClock.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (this->minute > otherClock.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (cH > ocH)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool clockType::operator>=(const clockType &otherClock) const
{
    return *this > otherClock || *this == otherClock;
}

void clockType::incrementMinute()
{
    minute++;
    if (minute > 59)
    {
        minute = 0;
        incrementHour();
    }
}

void clockType::incrementHour()
{
    hour++;
    if (type == TWELVE)
    {
        if (hour == 12)
        {
            timeOfDay == PM ? timeOfDay = AM : timeOfDay = PM; // if timeofday is pm set to am otherwise set to pm.
        }
        if (hour > 12)
        {
            hour = 1;
            // timeOfDay == PM ? timeOfDay = AM : timeOfDay = PM; // if timeofday is pm set to am otherwise set to pm.
        }
    }
    else
    {
        if (hour > 23)
            hour = 0;
    }
}

int clockType::operator-(const clockType &otherClock) const
{
    int diffH;
    int cH = this->hour;       // corrected version for 12 hour clocks
    int ocH = otherClock.hour; // corrected otherclock for 12 hour clocks
    if (this->type == TWELVE && this->timeOfDay == PM && this->hour < 12)
    {
        cH = this->hour + 12;
    }
    else if (this->type == TWELVE && this->timeOfDay == AM && this->hour == 12)
    {
        cH = 0;
    }
    if (otherClock.type == TWELVE && otherClock.timeOfDay == PM && otherClock.hour < 12)
    {
        ocH = otherClock.hour + 12;
    }
    else if (otherClock.type == TWELVE && otherClock.timeOfDay == AM && otherClock.hour == 12)
    {
        ocH = 0;
    }

    return abs(cH - ocH);
}

clockType clockType::operator+(int hours) const
{
    int newHour = this->hour;
    amPmType tod = this->timeOfDay;
    for (int i = 0; i < hours; i++)
    {
        newHour++;
        if (type == TWELVE)
        {
            if (newHour == 12)
            {
                tod == PM ? tod = AM : tod = PM; // if timeofday is pm set to am otherwise set to pm.
            }
            if (newHour > 12)
            {
                newHour = 1;
                // timeOfDay == PM ? timeOfDay = AM : timeOfDay = PM; // if timeofday is pm set to am otherwise set to pm.
            }
        }
        else
        {
            if (newHour > 23)
                newHour = 0;
        }
    }

    return clockType(newHour, this->minute, this->second, this->type, tod);
}

std::ostream &operator<<(std::ostream &out, const clockType &c)
{
    out << c.print();
    return out;
}

clockType clockType::operator++()
{
    incrementSecond();
    return *this;
}
clockType clockType::operator++(int)
{
    clockType temp = *this;
    incrementSecond();
    return temp;
}
/*
clockType::clockType()
{
    hour = 0;
    minute = 0;
    second = 0;
}
*/
