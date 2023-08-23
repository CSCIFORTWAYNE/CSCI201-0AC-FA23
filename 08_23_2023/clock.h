#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>

class clockType
{
public:
    void setHour(int h);
    clockType(int h = 0, int m = 0, int s = 0); // first parameter is hour, second is minute, third is second.
    void setMinute(int m);
    void setSecond(int s);
    // clockType();

private:
    int hour;
    int minute;
    int second;
};

#endif