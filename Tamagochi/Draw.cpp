#include "Draw.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <assert.h>


Draw::Draw()
{
	//ctor
}

Draw::~Draw()
{
	//dtor
}


void Draw::drawTamagochi(std::string fileName)
{

	const std::string filePath = basePath + fileName;

	std::ifstream Reader(filePath);             //Open file
	assert(Reader.good());

	std::string Art = getFileContents(Reader);       //Get file

	std::cout << Art << std::endl;               //Print it to the screen

	Reader.close();                           //Close file
}

std::string Draw::getFileContents(std::ifstream& File)
{
	std::string Lines = "";        //All lines

	if (File)
	{
		while (File.good())
		{
			std::string TempLine;                  //Temp line
			std::getline(File, TempLine);         //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
		}
		return Lines;
	}
	else
	{
		return "ERROR cannot load tamagotchi art";
	}
}


