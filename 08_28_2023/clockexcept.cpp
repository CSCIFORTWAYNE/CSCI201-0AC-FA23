#include "clockexcept.h"

hourException::hourException()
{
    msg = "The hour is invalid. Valid values are between 0 and 23.";
}

std::string hourException::what()
{
    return msg;
}