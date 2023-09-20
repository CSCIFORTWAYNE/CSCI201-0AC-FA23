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
    intList &operator+(intList);
    friend intList &operator+(int, intList);
    ~intList();
    const intList &operator=(const intList &);
    friend std::istream &operator>>(std::istream &, intList &);

private:
    int *list;
    int numInts;
    int maxInts;
    void copyList(const intList &);
};

#endif