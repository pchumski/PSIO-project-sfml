#include <iostream>
#include <fstream>
#include <string>
#include "DangerousItems.h"

DangerousItems::DangerousItems()
{
}

DangerousItems::DangerousItems(std::map<char, sf::Texture*> ItemsTextures)
{
	loadDangerousItems();
	createDangerousItems(ItemsTextures);
}

DangerousItems::~DangerousItems()
{	
}

void DangerousItems::loadDangerousItems()
{
	std::ifstream file("dangerousitems.txt");
	std::string charLine;
	std::vector<char> textureLine;
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, charLine);
			for (int i = 0; i < charLine.length(); i++)
			{
				textureLine.push_back(charLine[i]);
			}
			ArrangementDangerousItems.push_back(textureLine);
			textureLine.clear();
			charLine.clear();
		}
	}
}

void DangerousItems::createDangerousItems(std::map<char, sf::Texture*> ItemsTextures)
{
	std::vector<sf::Sprite> spritesLine;
	sf::Sprite chunk;


	for (int i = 0; i < ArrangementDangerousItems.size(); i++)
	{
		for (int j = 0; j < ArrangementDangerousItems[i].size(); j++)
		{
			if (ArrangementDangerousItems[i][j] != '0')
			{
				//chunk.setRepeated(true);
				chunk.setTexture(*ItemsTextures[ArrangementDangerousItems[i][j]]);
				chunk.setScale(1.0f, 1.0f);
				chunk.setPosition(float(j * 128), float(i * 128));
				spritesLine.push_back(chunk);
			}
		}
		MatrixDangerousItems.push_back(spritesLine);
		spritesLine.clear();
	}
}
