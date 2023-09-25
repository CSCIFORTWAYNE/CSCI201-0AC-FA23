#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>

// lecture activity add 1 pure virtual function to animal and implement it for each derived class.

class animal
{
public:
    virtual void id();
    virtual void eat() = 0;
    virtual void play() = 0;
    friend std::ostream &operator<<(std::ostream &, animal &);
    virtual void animalSound(bool sound) = 0;

protected:
    std::string name;
    int age;
};

class cat : public animal
{
public:
    virtual void id();
    void eat();
    void play();
    void animalSound(bool);
};

class dog : public animal
{
public:
    void id();
    void eat();
    void play();
    void animalSound(bool);
};

class gecko : public animal
{
public:
    void id();
    void eat();
    void play();
    void animalSound(bool);
};

class houseCat : public cat
{
public:
    void id();
    void eat();
    void play();
};

#endif