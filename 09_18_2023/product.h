#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <iomanip>

class product
{
public:
    product(double, std::string description, std::string prodNum);
    std::string getProdNum() const;
    std::string getDescription() const;
    double getPrice() const;
    void purchase();
    void setPrice(double);
    void setDescription(std::string);
    friend std::ostream &operator<<(std::ostream &, const product &);

protected:
    double price;
    std::string description;
    std::string prodNum;
    bool isPurchased;
    std::string tostring() const;
};

enum icingType
{
    CHOCOLATEICING,
    CARAMELICING,
    MAPLE,
    VANILLA,
    GLAZE,
    SPECIALICE,
    NOICE
};
enum toppingType
{
    RAINBOWSPR,
    CHOCOLATESPR,
    PEANUTS,
    COCONUT,
    OREO,
    BACON,
    GRAHAM,
    FRUITYPEBBLES,
    REESESPIECES,
    MMS,
    CANDYBAR,
    CHOCOLATECHIPS,
    SEASALT,
    CINSUGAR,
    POWDSUGAR,
    NOTOP
};
enum drizzleType
{
    CARAMELDRIZZLE,
    CHOCOLATEDRIZZLE,
    PEANUTBUTTER,
    RASPBERRY,
    SPECIALDRIZZLE,
    NODRIZZLE
};

class donut : public product
{
public:
    donut();
    donut(std::string icing, std::string topping, std::string drizzle);
    icingType getIcing();
    toppingType getTopping();
    drizzleType getDrizzle();
    void setIcing(std::string);
    void setTopping(std::string);
    void setDrizzle(std::string);
    friend std::ostream &operator<<(std::ostream &, const donut &);

private:
    icingType icing;
    toppingType topping;
    drizzleType drizzle;
    static int nextProdNum;
    std::string tostring() const;
};

enum flavorType
{
    VANILLAICECREAM,
    CHOCOLATEICECREAM,
    STRAWBERRY,
    MINT_CHOCOLATE_CHIP,
    COOKIE_DOUGH,
    COOKIES_AND_CREAM,
    BUTTER_PECAN,
    ROCKY_ROAD,
    CHOCOLATE_CHIP,
    MOOSE_TRACKS,
    COFFEE,
    CHOCOLATE_FUDGE_BROWNIE,
    PISTACHIO,
    RUM_RAISIN,
    NEAPOLITAN,
    FRENCH_VANILLA,
    PEANUT_BUTTER_CUP,
    BLACK_RASPBERRY,
    BIRTHDAY_CAKE,
    CARAMEL_SWIRL,
    MAPLE_WALNUT,
    BANANA_SPLIT,
    TUTTI_FRUTTI,
    ORANGE_SHERBET,
    COCONUTICECREAM

};

class iceCream : public product
{
public:
    iceCream(flavorType = VANILLAICECREAM, int = 1);
    // lecture activity add getters and setters
    void setFlavor(flavorType);
    void setScoopAmount(int);
    friend std::ostream &operator<<(std::ostream &, iceCream &);
    static double scoopPricing(int);

private:
    flavorType flavor;
    int scoopAmount;
    std::string tostring();
    static int prodNum;
};

#endif