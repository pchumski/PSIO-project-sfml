#include <iostream>
#include <fstream>
#include <string>
#include "LevelView.h"

LevelView::LevelView()
{
}

LevelView::LevelView(std::map<char, sf::Texture*> viewTextures)
{
	loadTextures();
	createTextures(viewTextures);
}

LevelView::~LevelView()
{
}

void LevelView::loadTextures()
{
	std::ifstream file("textures.txt");
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
			ArrangementView.push_back(textureLine);
			textureLine.clear();
			charLine.clear();
		}
	}
}

void LevelView::createTextures(std::map<char, sf::Texture*> viewTextures)
{
	std::vector<sf::Sprite> spritesLine;
	sf::Sprite chunk;


	for (int i = 0; i < ArrangementView.size(); i++)
	{
		for (int j = 0; j < ArrangementView[i].size(); j++)
		{
			if (ArrangementView[i][j] != '0')
			{
				//chunk.setRepeated(true);
				chunk.setTexture(*viewTextures[ArrangementView[i][j]]);
				chunk.setScale(1.0f, 1.0f);
				chunk.setPosition(float(j * 128), float(i * 128));
				spritesLine.push_back(chunk);
			}
		}
		MatrixView.push_back(spritesLine);
		spritesLine.clear();
	}
}
