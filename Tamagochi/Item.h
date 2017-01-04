#pragma once
#include <string>
#include "Need.h"


class Item
{
public:

	
	Item(std::string _name, double _satisfyValue, int _price);
	Item();
	virtual ~Item();
	void use(Need &need);
	void buy();
	std::string getName();

protected:
	double satisfyValue;
private:
	
	std::string name;
	int price;
};
