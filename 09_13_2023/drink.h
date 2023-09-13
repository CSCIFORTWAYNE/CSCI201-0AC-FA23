#pragma once
#include <string>
#include <algorithm>
#include <map>
enum baseType
{
	COFFEE,
	TEA,
	CREAM
};
enum tempType
{
	HOT,
	ICE,
	BLEND
};
enum sizeType
{
	SMALL,
	MED,
	LARGE
};

/* const std::string baseStr[] = {"Coffee", "Tea", "Cream"};
const std::string tempStr[] = {"Hot", "Iced", "Blended"};
const std::string sizeStr[] = {"Small", "Medium", "Large"};
const baseType bases[] = {COFFEE, TEA, CREAM};
const tempType temps[] = {HOT, ICE, BLEND};
const sizeType sizes[] = {SMALL, MED, LARGE}; */

const std::map<baseType, std::string> baseStr = {{COFFEE, "Coffee"}, {TEA, "Tea"}, {CREAM, "Cream"}};
const std::map<sizeType, std::string> sizeStr = {{SMALL, "Small"}, {MED, "Medium"}, {LARGE, "Large"}};
const std::map<tempType, std::string> tempStr = {{HOT, "Hot"}, {ICE, "Iced"}, {BLEND, "Blended"}};
const std::map<std::string, baseType> strBase = {{"COFFEE", COFFEE}, {"TEA", TEA}, {"CREAM", CREAM}};
const std::map<std::string, sizeType> strSize = {{"S", SMALL}, {"M", MED}, {"L", LARGE}};
const std::map<std::string, tempType> strTemp = {{"H", HOT}, {"I", ICE}, {"B", BLEND}};

class drink
{
public:
	drink(baseType, tempType, sizeType, std::string dairy, std::string flavor);
	std::string getBaseStr();
	std::string getTemperature();
	std::string getSize();
	std::string getDairy();
	std::string getFlavor();
	double getPrice();
	void setBase(baseType);
	void setTemperature(tempType);
	void setSize(sizeType);
	void setDairy(std::string);
	void setFlavor(std::string);

private:
	baseType base;
	tempType temperature;
	sizeType size;
	std::string dairy;
	std::string flavor;
};
