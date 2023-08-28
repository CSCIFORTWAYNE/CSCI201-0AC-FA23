#ifndef CLOCKEXCEPT_H
#define CLOCKEXCEPT_H
#include <string>

class hourException
{
public:
    hourException();
    std::string what();

private:
    std::string msg;
};

#endif