#include "animal.h"
#include <vector>

void displayAnimal(animal *);
void displayCat(cat *);

int main()
{
    std::vector<animal *> zoo(3);
    // std::vector<animal> zoo2;
    zoo[0] = new houseCat();
    zoo[1] = new cat();
    zoo[2] = new dog();

    animal *a = new gecko();
    a->id();
    delete a;
    dog d;
    a = &d;
    /*  zoo2.push_back(d);
     zoo2[0].id(); */

    a->id();
    std::cout << std::endl;
    d.id();
    std::cout << std::endl;

    displayAnimal(a);
    displayAnimal(&d);

    zoo.push_back(new gecko());
    zoo.push_back(new houseCat());

    for (int i = 0; i < zoo.size(); i++)
    {
        displayAnimal(zoo[i]);
    }
    displayCat(static_cast<cat *>(zoo[zoo.size() - 1]));
    std::cout << d << std::endl;

    // delete a;
    for (int i = 0; i < zoo.size(); i++)
    {
        delete zoo[i];
    }
    return 0;
}

void displayAnimal(animal *a)
{

    std::cout << *a << std::endl;
}

void displayCat(cat *c)
{
    c->id();
    std::cout << std::endl;
}