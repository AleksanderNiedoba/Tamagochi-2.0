#include "Item.h"
#include <string>

Item::Item(std::string _name, double _satisfyValue, int _price)
{
	name = _name;
	satisfyValue = _satisfyValue;
	price = _price;
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
