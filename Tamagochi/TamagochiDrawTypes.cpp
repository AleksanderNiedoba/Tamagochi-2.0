#include "TamagochiDrawTypes.h"


TamagochiDrawTypes::TamagochiDrawTypes()
{
	moodToAsciiArtNr["Wonderful"] = 3;
	moodToAsciiArtNr["life is beautiful"] = 3;
	moodToAsciiArtNr["I'm happy"] = 2;
	moodToAsciiArtNr["life sucks"] = 2;
	moodToAsciiArtNr["Don't forget about me"] = 1;
	moodToAsciiArtNr["I'm dying"] = 1;
	moodToAsciiArtNr["dead"] = 0;
}

TamagochiDrawTypes::~TamagochiDrawTypes()
{
	//dtor
}

int TamagochiDrawTypes::getArtNumber(std::string mood)
{
	return moodToAsciiArtNr[mood];
}

