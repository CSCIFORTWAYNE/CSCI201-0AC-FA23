#include <iostream>
#include <string>

int getInt(std::string);

int main()
{
    int i;
    i = getInt("Enter the number of apples you would like.");
    std::cout << "You got " << i << " apples." << std::endl;
    return 0;
}

int getInt(std::string prompt)
{
    int input;
    std::cout << prompt << std::endl;
    std::cin >> input;
    std::cout << input << std::endl;
    while (!std::cin)
    {
        if (!std::cin)
        {
            std::cout << "You need to enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        std::cout << prompt << std::endl;
        std::cin >> input;
        std::cout << input << std::endl;
    }
    return input;
}