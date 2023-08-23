#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>

class clockType
{
public:
    void setHour(int h);

private:
    int hour;
    int minute;
    int second;
};

#endif