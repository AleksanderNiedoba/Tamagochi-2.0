#include "ArtLoader.h"



ArtLoader::ArtLoader()
{
}


ArtLoader::~ArtLoader()
{
}

std::vector <std::string> ArtLoader::loadArts()
{
	std::vector <std::string> asciiArts;
	for (int i = 0; i < fileNames.size(); i++)
	{
		std::string art = getAscii(fileNames[i]);
		asciiArts.push_back(art);
	}
	return asciiArts;
}


std::string ArtLoader::getAscii(std::string fileName)
{
	const std::string filePath = basePath + fileName;

	std::ifstream Reader(filePath);             //Open file


	std::string art = getFileContents(Reader);       //Get file
	Reader.close();
	return art;
}



std::string ArtLoader::getFileContents(std::ifstream& File)
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
