#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TamagochiDrawTypes.h"
#include "Needs_container.h"
#include "RenderBars.h"
#include "ArtLoader.h"



class Draw
{
public:
	Draw();
	virtual ~Draw();

	void drawTamagochi(Tamagochi& tamagochi);
	void drawMenu();
	void drawBars(Needs_container& needs_container);


protected:

private:
	std::vector <std::string> _asciiArts;


};