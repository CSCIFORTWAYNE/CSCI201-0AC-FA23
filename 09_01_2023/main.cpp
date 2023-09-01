#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "clock.h"

void setClock(clockType &);
void resetStream();

int main()
{
    std::vector<int> myList(10);
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
    std::cout << yourClock.print() << std::endl;

    return 0;
}

void setClock(clockType &c)
{
    int typeOfClock;
    hourType numHours;
    std::string tod;
    bool hour = false, min = false, sec = false;
    int h, m, s;
    std::cout << "How many hours are on the clock" << std::endl;
    std::cin >> typeOfClock;
    while (!std::cin || !intToHourType.count(typeOfClock))
    {
        if (std::cin.eof())
        {
            std::cout << "There was a problem and there is no more input! Input validation for hours on clock!" << std::endl;
            return;
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
    numHours = intToHourType.at(typeOfClock);
    if (numHours == TWELVE)
    {
        std::cout << "Enter the time of day (";
        std::map<amPmType, std::string>::const_iterator it = amPmToStr.begin();
        std::cout << it->second;
        for (++it; it != amPmToStr.end(); ++it)
        {
            std::cout << ", " << it->second;
        }
        std::cout << "): ";
        std::cin >> tod;
        std::transform(tod.begin(), tod.end(), tod.begin(), ::toupper);
        while (!strToAmPm.count(tod))
        {
            if (std::cin.eof())
            {
                std::cout << "There was a problem and there is no more input! Input validation for AM/PM!" << std::endl;
                return;
            }
            std::cout << "You have entered an invalid value!" << std::endl;
            std::cout << "Enter the time of day (";
            std::map<amPmType, std::string>::const_iterator it = amPmToStr.begin();
            std::cout << it->second;
            for (++it; it != amPmToStr.end(); ++it)
            {
                std::cout << ", " << it->second;
            }
            std::cout << "): ";
            std::cin >> tod;
            std::transform(tod.begin(), tod.end(), tod.begin(), ::toupper);
        }
    }

    bool set = false;

    while (!set)
    {
        if (!hour)
        {
            std::cout << "Enter the hour on the clock: ";
            std::cin >> h;
            while (!std::cin /*|| h < 0 || h > 23*/)
            {
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
            hour = true;
        }
        if (!min)
        {
            std::cout << "Enter the minutes on the clock: ";
            std::cin >> m;
            while (!std::cin /*|| h < 0 || h > 23*/)
            {
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
            min = true;
        }
        if (!sec)
        {
            std::cout << "Enter the seconds on the clock: ";
            std::cin >> s;
            // final input validation goes here
            while (!std::cin /*|| h < 0 || h > 23*/)
            {
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
            sec = true;
        }

        // c.setHour(h);
        // c.setMinute(m);
        //  c.setSecond(s);
        try
        {
            c.setClockType(numHours);
            c.setAmPm(strToAmPm.at(tod));
            c.setHour(h);
            c.setMinute(m);
            c.setSecond(s);

            set = true;
        }
        catch (hourException e)
        {
            std::cout << e.what() << std::endl;
            hour = false;
            // throw;
        }
    }
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
