#pragma once
#include <fstream>
#include <string>
#include <vector>


class ArtLoader
{
public:
	ArtLoader();
	~ArtLoader();

	std::vector <std::string> loadArts();



private:
	std::string getAscii(std::string fileName);
	std::string getFileContents(std::ifstream& File);

	const std::string basePath = "TamagotchiAscii/";
	std::vector <std::string> fileNames = { "gameOver.txt","sad.txt" ,"normal.txt" ,"good.txt", "menu.txt" }; //arts to load
};

