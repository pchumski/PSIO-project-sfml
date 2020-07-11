#include <iostream>
#include <fstream>
#include <string>
#include "SpecialObjects.h"

SpecialObjects::SpecialObjects()
{
}

SpecialObjects::SpecialObjects(std::map<char, sf::Texture*> SpecialObjectsTextures)
{
	loadSpecialObjects();
	createSpecialObjects(SpecialObjectsTextures);
}

SpecialObjects::~SpecialObjects()
{
}

void SpecialObjects::loadSpecialObjects()
{
	std::ifstream file("specialobjects.txt");
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
			ArrangementSpecialObjects.push_back(textureLine);
			textureLine.clear();
			charLine.clear();
		}
	}
}

void SpecialObjects::createSpecialObjects(std::map<char, sf::Texture*> SpecialObjectsTextures)
{
	std::vector<sf::Sprite> spritesLine;
	sf::Sprite chunk;


	for (int i = 0; i < ArrangementSpecialObjects.size(); i++)
	{
		for (int j = 0; j < ArrangementSpecialObjects[i].size(); j++)
		{
			if (ArrangementSpecialObjects[i][j] != '0')
			{
				//chunk.setRepeated(true);
				chunk.setTexture(*SpecialObjectsTextures[ArrangementSpecialObjects[i][j]]);
				chunk.setScale(0.5f, 0.5f);
				chunk.setPosition(float(j * 128), float(i * 130));
				spritesLine.push_back(chunk);
			}
		}
		MatrixSpecialObjects.push_back(spritesLine);
		spritesLine.clear();
	}
}

