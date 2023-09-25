#include "animal.h"

void animal::id()
{
    std::cout << "animal";
}

void cat::id()
{
    animal::id();
    std::cout << std::endl;
    std::cout << "cat";
}

void cat::eat()
{
    std::cout << "eating a rat";
}

void cat::play()
{
    std::cout << "kicks Odie off the table";
}

void cat::animalSound(bool sound)
{
    if (sound)
    {
        std::cout << "miaow" << std::endl;
    }
    else
    {
        std::cout << "cat is quiet" << std::endl;
    }
}

void dog::id()
{
    std::cout << "dog";
}

void dog::eat()
{
    std::cout << "eating kibble";
}

void dog::play()
{
    std::cout << "chases his tail for hours";
}

void dog::animalSound(bool sound)
{
    if (sound)
    {
        std::cout << "woof" << std::endl;
    }
    else
    {
        std::cout << "dog is quiet" << std::endl;
    }
}

void gecko::id()
{
    std::cout << "gecko";
}

void gecko::eat()
{
    std::cout << "munches on grubs";
}

void gecko::play()
{
    std::cout << "stares at you";
}
void gecko::animalSound(bool sound)
{
    if (sound)
    {
        std::cout << "squeak" << std::endl;
    }
    else
    {
        std::cout << "gecko is quiet" << std::endl;
    }
}

void houseCat::id()
{
    std::cout << "snowball";
}

void houseCat::eat()
{
    std::cout << "eats a can of Fancy Feast";
}

void houseCat::play()
{
    std::cout << "carries a sock to their hiding space";
}

std::ostream &operator<<(std::ostream &out, animal &a)
{
    a.id();
    // out << ": " << a.name << " - " << a.age << " ";
    out << " ";
    a.play();
    out << " and ";
    a.eat();
    out << " ";
    return out;
}
