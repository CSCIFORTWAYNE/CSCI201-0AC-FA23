#include "product.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<product> inventory;
    inventory.push_back(product(9.91, "product 1", "P1"));
    inventory.push_back(product(5.94, "product 2", "P2"));
    inventory.push_back(product(7.97, "product 3", "P3"));

    for (int i = 0; i < inventory.size(); i++)
    {
        std::cout << inventory[i] << std::endl;
    }

    std::vector<donut> donutInventory;
    donutInventory.push_back(donut());
    donutInventory.push_back(donut());
    donutInventory.push_back(donut());
    for (int i = 0; i < donutInventory.size(); i++)
    {
        std::cout << donutInventory[i] << std::endl;
    }

    return 0;
}