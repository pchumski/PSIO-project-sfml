#include <iostream>
#include <fstream>
#include <string>
#include "Coin.h"

Coin::Coin()
{
}

Coin::Coin(std::map<char, sf::Texture*> CoinTextures)
{
	loadCoin();
	createCoin(CoinTextures);
}

Coin::~Coin()
{
}

void Coin::loadCoin()
{
	std::ifstream file("coins.txt");
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
			ArrangementCoin.push_back(textureLine);
			textureLine.clear();
			charLine.clear();
		}
	}
}

void Coin::createCoin(std::map<char, sf::Texture*> CoinTextures)
{
	std::vector<sf::Sprite> spritesLine;
	sf::Sprite chunk;


	for (int i = 0; i < ArrangementCoin.size(); i++)
	{
		for (int j = 0; j < ArrangementCoin[i].size(); j++)
		{
			if (ArrangementCoin[i][j] != '0')
			{
				//chunk.setRepeated(true);
				chunk.setTexture(*CoinTextures[ArrangementCoin[i][j]]);
				chunk.setScale(0.9f, 0.9f);
				chunk.setPosition(float(j * 130), float(i * 130));
				spritesLine.push_back(chunk);
			}
		}
		MatrixCoin.push_back(spritesLine);
		spritesLine.clear();
	}
}

