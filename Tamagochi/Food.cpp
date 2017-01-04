#include "Food.h"

Food::Food()
{
	//ctor
}

Food::~Food()
{
	//dtor
}

void Food::use(Need &need)
{

	need.change_need_lvl(satisfyValue);
	//wywolaj funkcje change_amount

	//znisz posiady item
}