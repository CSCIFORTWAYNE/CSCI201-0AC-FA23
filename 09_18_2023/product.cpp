#include "product.h"

product::product(double price, std::string description, std::string prodNum)
{
    setPrice(price);
    setDescription(description);
    if (prodNum.size() > 0)
        this->prodNum = prodNum;
    else
        throw std::invalid_argument("Product number cannot be empty.");
    isPurchased = false;
}

std::string product::getProdNum() const
{
    return prodNum;
}

std::string product::getDescription() const
{
    return description;
}

double product::getPrice() const
{
    return price;
}

void product::purchase()
{
    isPurchased = true;
}

void product::setPrice(double price)
{
    if (price > 0)
        this->price = price;
    else
        throw std::invalid_argument("Price must be greater than 0.");
}

void product::setDescription(std::string description)
{
    this->description = description;
}

std::ostream &operator<<(std::ostream &out, const product &p)
{
    out << p.tostring();
    return out;
}

std::ostream &operator<<(std::ostream &out, const donut &d)
{
    out << d.tostring();
    return out;
}

std::ostream &operator<<(std::ostream &out, iceCream &i)
{
    out << i.tostring();
    return out;
}

std::string product::tostring() const
{
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    std::string purch = isPurchased ? "Not Available" : "Available";
    out << prodNum << " - " << description << " - $" << price << " - " << purch;
    return out.str();
}
int donut::nextProdNum = 1;

donut::donut() : product(1.65, "Donut", "DO" + std::to_string(nextProdNum++))
{
    icing = NOICE;
    drizzle = NODRIZZLE;
    topping = NOTOP;
}

donut::donut(std::string icing, std::string topping, std::string drizzle) : product(1.65, "Donut", "DO" + std::to_string(nextProdNum++))
{
}

std::string donut::tostring() const
{
    std::ostringstream out;
    out << "Icing: None, Topping: None, Drizzle: None - ";
    out << product::tostring();
    return out.str();
}
int iceCream::prodNum = 1;
iceCream::iceCream(flavorType flavor, int scoopAmount) : product(scoopPricing(scoopAmount), "Ice Cream", "I" + std::to_string(prodNum++))
{
    // setFlavor(flavor);
    // setScoopAmount(scoopAmount);
    purchase();
}

double iceCream::scoopPricing(int scoops)
{
    switch (scoops)
    {
    case 1:
        return 3.0;
    case 2:
        return 4.0;
    case 3:
        return 5.0;
    default:
        return scoops * 1.65;
    }
    return 0.0;
}

std::string iceCream::tostring()
{
    std::ostringstream out;
    out << scoopAmount << " scoops of "
        << "Flavor string"
        << " - " << product::tostring();
    return out.str();
}
