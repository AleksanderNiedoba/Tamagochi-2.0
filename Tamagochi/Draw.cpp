#include "Draw.h"



Draw::Draw()
{
	std::vector <std::string> fileNames = {"gameOver.txt","sad.txt" ,"normal.txt" ,"good.txt" };
	for (int i=0; i < fileNames.size(); i++)
	{
		std::string art = getAscii(fileNames[i]);
		asciiArts.push_back(art);
	}
	//ctor
}

Draw::~Draw()
{
	//dtor
}

std::string Draw::getAscii(std::string fileName)
{
	const std::string filePath = basePath + fileName;

	std::ifstream Reader(filePath);             //Open file
	

	std::string art = getFileContents(Reader);       //Get file
	Reader.close();
	return art;
}

void Draw::drawTamagochi(Tamagochi& tamagochi)
{
	const std::string mood = tamagochi.get_mood();
	TamagochiDrawTypes tdt;
	int asciiNr = tdt.getArtNumber(mood);
	cout << asciiArts[asciiNr];
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


