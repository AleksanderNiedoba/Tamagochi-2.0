#pragma once
#include <iostream>
#include <fstream>
#include <string>




class Draw
{
public:
	Draw();
	virtual ~Draw();
	void drawTamagochi(std::string fileName);
	std::string getFileContents(std::ifstream& File);

protected:

private:

	const std::string basePath = "TamagotchiAscii/";

};