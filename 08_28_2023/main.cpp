#include <iostream>
#include <string>
#include <limits>
#include "clock.h"

void setClock(clockType &);
void resetStream();

// lecture activity create two more exception classes in clockexcept.h and cpp
// one for minutes and one for seconds.
// add the code to throw the exception in clock.cpp
// add the catch blocks to handle the exceptions in setClock

int main()
{
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
    std::cout << yourClock.print();

    return 0;
}

void setClock(clockType &c)
{
    std::string typeOfClock;
    int tod;
    bool hour = false, min = false, sec = false;
    int h, m, s;
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
            clockType newClock(h, m, s, typeOfClock, timesOfDay[tod - 1]);
            c = newClock;
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
