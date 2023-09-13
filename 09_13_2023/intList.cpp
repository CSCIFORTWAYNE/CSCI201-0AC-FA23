#include "intList.h"

intList::intList(const intList &othList)
{
    // this->numInts = 0;
    this->list = nullptr;
    copyList(othList);
}

intList::intList(int maxInts)
{
    if (maxInts > 0)
    {
        this->maxInts = maxInts;
        this->numInts = 0;
        this->list = new int[this->maxInts];
    }
    else
        throw maxInts;
}

intList &intList::operator+(int numToAdd)
{
    if (numInts + 1 >= maxInts)
    {
        int *newList;
        newList = new int[++maxInts];     // make a new list that is 1 bigger than the old list
        for (int i = 0; i < numInts; i++) // copy elements to new list
        {
            newList[i] = list[i];
        }
        delete[] list;  // delete the old list
        list = newList; // set the class list to be the new list
    }
    list[numInts++] = numToAdd;
    // numInts++;
    return *this;
}

intList::~intList()
{
    delete[] list;
    list = nullptr;
}

const intList &intList::operator=(const intList &othList)
{
    if (&othList != this) // avoid self copy
    {
        copyList(othList);
    }
    return *this;
}

void intList::copyList(const intList &othList)
{
    if (this->list == nullptr)
    {
        delete[] list;
        list = nullptr;
    }
    this->maxInts = othList.maxInts;
    this->numInts = othList.numInts;
    this->list = new int[this->maxInts];
    // this->list = othList.list; //shallow copy only copies the location of the other list
    for (int i = 0; i < this->numInts; i++)
    {
        this->list[i] = othList.list[i]; // deep copy copies all of the list elements
    }
}

std::ostream &operator<<(std::ostream &out, const intList &l)
{
    for (int i = 0; i < l.numInts; i++)
    {
        std::cout << l.list[i] << std::endl;
        // std::cout << l.list[i] << " ";
    }
    return out;
}
