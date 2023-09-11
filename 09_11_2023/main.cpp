#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "clock.h"

void setClock(clockType &);
void resetStream();
hourType getClockType();
amPmType getTOD();
int getHour();
int getMinute();
int getSecond();

int main()
{
    std::vector<clockType *> clocks;
    clockType *c = nullptr;
    for (int i = 0; i < 2; i++)
    {
        int typeOfClock;
        hourType numHours;
        amPmType tod;
        bool hour = false, min = false, sec = false;
        int h, m, s;
        numHours = getClockType();
        if (numHours == TWELVE)
        {
            tod = getTOD();
        }

        bool set = false;

        while (c == nullptr)
        {
            if (!hour)
            {
                h = getHour();
                hour = true;
            }
            if (!min)
            {
                m = getMinute();
                min = true;
            }
            if (!sec)
            {
                s = getSecond();
                sec = true;
            }

            try
            {

                clockType cc(h, m, s, numHours);
                if (numHours == TWENTYFOUR)
                    c = new clockType(h, m, s, numHours);
                else
                    c = new clockType(h, m, s, numHours, tod);
                set = true;
                clocks.push_back(c);
            }
            catch (hourException e)
            {
                std::cout << e.what() << '\n';
                hour = false;
            }
            catch (minuteException e)
            {
                std::cout << e.what() << '\n';
                min = false;
            }
            catch (secondException e)
            {
                std::cout << e.what() << '\n';
                sec = false;
            }
        }

        c = NULL;
    }

    std::cout << clocks[0]->print() << std::endl;

    /* for (int i = 0; i < 10; i++)
    {
        c->incrementSecond();
    } */
    std::cout << clocks[1]->print() << std::endl;
    int diff = *(clocks[0]) - *(clocks[1]);
    std::cout << "The difference between the two clocks is " << diff << " hours" << std::endl;
    ;

    /* std::vector<int> myList(10);
    for (int i = 0; i < 10; i++)
    {
        myList[i] = 0;
    }
    myList.push_back(89);
    myList.push_back(100);
    myList.push_back(281);
    for (int i = 0; i < myList.size(); i++)
    {
        std::cout << myList[i] << std::endl;
    }
    myList[2] = 672;
    myList.at(2) = 543;

    clockType myClock(14, 32, 23);
    myClock.setHour(13);
    clockType yourClock;
    yourClock = myClock;
    bool set = false;
    while (!set)
    {
        try
        {
            setClock(yourClock);
            set = true;
        }
        catch (...)
        {
            continue;
        }
    }
    std::cout << yourClock.print() << std::endl; */

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

hourType getClockType()
{
    int typeOfClock;
    std::cout << "How many hours are on the clock" << std::endl;
    std::cin >> typeOfClock;
    while (!std::cin || !clockType::intToHourType.count(typeOfClock))
    {
        if (std::cin.eof())
        {
            std::cout << "There was a problem and there is no more input! Input validation for hours on clock!" << std::endl;
            return TWELVE;
        }
        if (!std::cin)
        {
            resetStream();
            std::cout << "You entered something that is not a number." << std::endl;
        }
        else
        {
            std::cout << "The number of hours is invalid. Clocks can have 12 or 24 hours." << std::endl;
        }
        std::cout << "How many hours are on the clock" << std::endl;
        std::cin >> typeOfClock;
    }
    hourType numHours = clockType::intToHourType.at(typeOfClock);
    return numHours;
}

amPmType getTOD()
{
    std::string tod;
    std::cout << "Enter the time of day (";
    std::map<amPmType, std::string>::const_iterator it = clockType::amPmToStr.begin();
    std::cout << it->second;
    for (++it; it != clockType::amPmToStr.end(); ++it)
    {
        std::cout << ", " << it->second;
    }
    std::cout << "): ";
    std::cin >> tod;
    std::transform(tod.begin(), tod.end(), tod.begin(), ::toupper);
    while (!clockType::strToAmPm.count(tod))
    {
        if (std::cin.eof())
        {
            std::cout << "There was a problem and there is no more input! Input validation for AM/PM!" << std::endl;
            return AM;
        }
        std::cout << "You have entered an invalid value!" << std::endl;
        std::cout << "Enter the time of day (";
        std::map<amPmType, std::string>::const_iterator it = clockType::amPmToStr.begin();
        std::cout << it->second;
        for (++it; it != clockType::amPmToStr.end(); ++it)
        {
            std::cout << ", " << it->second;
        }
        std::cout << "): ";
        std::cin >> tod;
        std::transform(tod.begin(), tod.end(), tod.begin(), ::toupper);
    }
    return clockType::strToAmPm.at(tod);
}

int getHour()
{
    int h;
    std::cout << "Enter the hour on the clock: ";
    std::cin >> h;
    while (!std::cin /*|| h < 0 || h > 23*/)
    {
        if (std::cin.eof())
        {
            std::cout << "There was a problem and there is no more input! Input validation for hours" << std::endl;
            return 0;
        }
        try
        {
            if (!std::cin)
            {
                throw "Input failure";
            }
            /*else
            {
                std::cout << "You entered an invalid value for the hour. Hours are between 0 and 23." << std::endl;
            }*/
        }
        catch (char const *err)
        {
            std::cerr << "Error Code " << err << std::endl;
            std::cout << "You entered something that is not a number." << std::endl;
            resetStream();
        }
        std::cout << "Enter the hour on the clock: ";
        std::cin >> h;
    }

    return h;
}

int getMinute()
{
    int m;
    std::cout << "Enter the minutes on the clock: ";
    std::cin >> m;
    while (!std::cin /*|| h < 0 || h > 23*/)
    {
        if (std::cin.eof())
        {
            std::cout << "There was a problem and there is no more input! Input validation for min" << std::endl;
            return 0;
        }
        try
        {
            if (!std::cin)
            {
                throw "Input failure";
            }
            /*else
            {
                std::cout << "You entered an invalid value for the hour. Hours are between 0 and 23." << std::endl;
            }*/
        }
        catch (char const *err)
        {
            std::cerr << "Error Code " << err << std::endl;
            std::cout << "You entered something that is not a number." << std::endl;
            resetStream();
        }
        std::cout << "Enter the minutes on the clock: ";
        std::cin >> m;
    }
    return m;
}

int getSecond()
{
    int s;
    std::cout << "Enter the seconds on the clock: ";
    std::cin >> s;
    // final input validation goes here
    while (!std::cin /*|| h < 0 || h > 23*/)
    {
        if (std::cin.eof())
        {
            std::cout << "There was a problem and there is no more input! Input validation for sec" << std::endl;
            return 0;
        }
        try
        {
            if (!std::cin)
            {
                throw "Input failure";
            }
            /*else
            {
                std::cout << "You entered an invalid value for the hour. Hours are between 0 and 23." << std::endl;
            }*/
        }
        catch (char const *err)
        {
            std::cerr << "Error Code " << err << std::endl;
            std::cout << "You entered something that is not a number." << std::endl;
            resetStream();
        }
        std::cout << "Enter the seconds on the clock: ";
        std::cin >> s;
    }
    return s;
}
