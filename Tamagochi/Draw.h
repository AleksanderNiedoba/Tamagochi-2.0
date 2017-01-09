#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TamagochiDrawTypes.h"



class Draw
{
public:
	Draw();
	virtual ~Draw();
	std::string getAscii(std::string fileName);
	void drawTamagochi(Tamagochi& tamagochi);
	std::string getFileContents(std::ifstream& File);

protected:

private:
	std::vector <std::string> asciiArts;

	const std::string basePath = "TamagotchiAscii/";

};