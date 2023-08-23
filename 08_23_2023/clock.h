#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

enum hourType
{
    TWELVE,
    TWENTYFOUR
};
enum amPmType
{
    AM,
    PM
};

const std::string hourToString[] = {"12 hour clock", "24 hour clock"};
const std::string amPmToString[] = {"AM", "PM"};

class clockType
{
public:
    // clockType();
    clockType(int h = 0, int m = 0, int s = 0); // first parameter is hour, second is minute, third is second.
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);
    int getHour() const;
    int getMinute() const; // fill in for lecture activity
    int getSecond() const; // fill in for lecture activity

    std::string print() const;

private:
    int hour;
    int minute;
    int second;
    hourType type;
    amPmType timeOfDay;
};

#endif