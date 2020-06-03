#include <iostream>
#include <fstream>
#include <string>
#include "Level.h"

Level::Level(std::map<char, sf::Texture*> groundTextures)
{
	loadMap();
	createMap(groundTextures);
}

Level::~Level()
{
}

void Level::loadMap()
{
	std::ifstream file("location.txt");
	std::string charLine;
	std::vector<char> mapLine;
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, charLine);
			for (int i = 0; i < charLine.length(); i++)
			{
				mapLine.push_back(charLine[i]);
			}
			Arrangement.push_back(mapLine);
			mapLine.clear();
			charLine.clear();
		}
	}
}

void Level::createMap(std::map<char, sf::Texture*> groundTextures)
{
	std::vector<sf::Sprite> spritesLine;
	sf::Sprite chunk;


	for (int i = 0; i < Arrangement.size(); i++)
	{
		for (int j = 0; j < Arrangement[i].size(); j++)
		{
			if (Arrangement[i][j] != '0')
			{
				chunk.setTexture(*groundTextures[Arrangement[i][j]]);
				chunk.setScale(1.0f, 1.0f);
				chunk.setPosition(float(j * 128), float(i * 128));
				spritesLine.push_back(chunk);
			}
		}
		Matrix.push_back(spritesLine);
		spritesLine.clear();
	}
}
