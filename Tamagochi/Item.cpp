#include "Item.h"
#include <string>

Item::Item(std::string _name, double _satisfyValue, int _price, std::string _needSatisfied)
{
	name = _name;
	satisfyValue = _satisfyValue;
	price = _price;
	needToSatisfy = _needSatisfied;
}

Item::Item()
{

}

Item::~Item()
{
	//dtor
}


void Item::use(Need &need)
{
	need.change_need_lvl(satisfyValue);
}

std::string Item::getName()
{
	return name;
}

int Item::getPrice()
{
	return price;
}

std::string Item::getNeedToSatisfy()
{
	return needToSatisfy;
}

double Item::getSatisfyValue()
{
	return satisfyValue;
}