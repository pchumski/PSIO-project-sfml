#include <iostream>
#include <fstream>
#include <string>
#include "Items.h"

Items::Items()
{
}

Items::Items(std::map<char, sf::Texture*> ItemsTextures)
{
	loadItems();
	createItems(ItemsTextures);
}

Items::~Items()
{
}

void Items::loadItems()
{
	std::ifstream file("items.txt");
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
			ArrangementItems.push_back(textureLine);
			textureLine.clear();
			charLine.clear();
		}
	}
}

void Items::createItems(std::map<char, sf::Texture*> ItemsTextures)
{
	std::vector<sf::Sprite> spritesLine;
	sf::Sprite chunk;


	for (int i = 0; i < ArrangementItems.size(); i++)
	{
		for (int j = 0; j < ArrangementItems[i].size(); j++)
		{
			if (ArrangementItems[i][j] != '0')
			{
				//chunk.setRepeated(true);
				chunk.setTexture(*ItemsTextures[ArrangementItems[i][j]]);
				chunk.setScale(1.66f, 1.66f);
				chunk.setPosition(float(j * 128), float(i * 128));
				spritesLine.push_back(chunk);
			}
		}
		MatrixItems.push_back(spritesLine);
		spritesLine.clear();
	}
}

void Items::OnCollision1(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collison on the right
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collsion on the bottom
		velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.y = 0.0f;
	}
}

