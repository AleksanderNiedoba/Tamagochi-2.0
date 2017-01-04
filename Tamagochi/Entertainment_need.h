#pragma once


#include "Need.h"


class Entertainment_need : public Need
{
public:
	Entertainment_need();
	virtual ~Entertainment_need();
	std::string get_type();
protected:

private:
	std::string type = "entertainment";
};

