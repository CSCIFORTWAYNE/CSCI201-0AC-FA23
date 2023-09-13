#ifndef INTLIST_H
#define INTLIST_H
#include <iostream>

class intList
{
public:
    intList(const intList &);
    intList(int = 10);
    friend std::ostream &operator<<(std::ostream &, const intList &);
    intList &operator+(int);
    ~intList();
    const intList &operator=(const intList &);

private:
    int *list;
    int numInts;
    int maxInts;
    void copyList(const intList &);
};

#endif