#pragma once

#include "Item.h"


class Food : public Item
{
public:
	Food();
	virtual ~Food();
	void use(Need &need);
	void buy();

protected:

private:
};