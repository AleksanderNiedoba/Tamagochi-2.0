#pragma once
#include <map>
#include <string>
#include "Tamagochi.h"



class TamagochiDrawTypes
{
public:
	TamagochiDrawTypes();
	virtual ~TamagochiDrawTypes();
	int getArtNumber(std::string);


protected:

private:
	std::map<std::string, int> moodToAsciiArtNr;
};
