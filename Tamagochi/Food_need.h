#pragma once

#include "Need.h"


class Food_need : public Need
{
public:
	Food_need();
	virtual ~Food_need();
	std::string get_type();
protected:

private:
	std::string type = "food";
};


