#include "Draw.h"




Draw::Draw()
{
	ArtLoader al;
	_asciiArts = al.loadArts();
}

Draw::~Draw()
{
	//dtor
}

void Draw::drawMenu()
{
	const int menuAsciiArtNr = 4;
	cout << _asciiArts[menuAsciiArtNr];
}

void Draw::drawTamagochi(Tamagochi& tamagochi)
{
	const std::string mood = tamagochi.get_mood();
	TamagochiDrawTypes tdt;
	int asciiNr = tdt.getArtNumber(mood);
	cout << _asciiArts[asciiNr];
}

void Draw::drawBars(Needs_container& needs_container)
{
	RenderBars rb;
	std::vector<Need> needs = needs_container.get_needs();
	rb.renderAll(needs);
}

void Draw::drawMoney(Tamagochi& tamagochi)
{
	cout << "Money: " << tamagochi.getMoney() << "$" << endl;
}