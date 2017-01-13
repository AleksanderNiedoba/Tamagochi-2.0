#pragma once
#include <string>
#include "Need.h"


class Item
{
public:
	Item(std::string _name, double _satisfyValue, int _price, std::string);
	Item();
	virtual ~Item();
	void use(Need &need);
	std::string getName();
	int getPrice();
	std::string getNeedToSatisfy();
	double getSatisfyValue();

protected:
	double satisfyValue;
private:
	
	std::string name;
	int price;
	std::string needToSatisfy;
};
