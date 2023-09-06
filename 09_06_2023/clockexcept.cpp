#include "clockexcept.h"

hourException::hourException(int hours)
{
    if (hours == 12)
    {
        msg = "The hour is invalid. Valid values are between 1 and 12.";
    }
    else
    {
        msg = "The hour is invalid. Valid values are between 0 and 23.";
    }
}

std::string hourException::what()
{
    return msg;
}