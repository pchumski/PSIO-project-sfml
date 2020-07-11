#include <iostream>
#include <fstream>
#include <string>
#include "NewBox.h"

NewBox::NewBox()
{
}

NewBox::NewBox(std::map<char, sf::Texture*> NewBoxTextures)
{
	loadNewBox();
	createNewBox(NewBoxTextures);
}

NewBox::~NewBox()
{
}

void NewBox::loadNewBox()
{
	std::ifstream file("newbox.txt");
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
			ArrangementNewBox.push_back(textureLine);
			textureLine.clear();
			charLine.clear();
		}
	}
}

void NewBox::createNewBox(std::map<char, sf::Texture*> NewBoxTextures)
{
	std::vector<sf::Sprite> spritesLine;
	sf::Sprite chunk;


	for (int i = 0; i < ArrangementNewBox.size(); i++)
	{
		for (int j = 0; j < ArrangementNewBox[i].size(); j++)
		{
			if (ArrangementNewBox[i][j] != '0')
			{
				//chunk.setRepeated(true);
				chunk.setTexture(*NewBoxTextures[ArrangementNewBox[i][j]]);
				chunk.setScale(0.5f, 0.5f);
				chunk.setPosition(float(j * 128), float(i * 128));
				//chunk.setOrigin(chunk.getGlobalBounds().left, chunk.getGlobalBounds().height);
				//chunk.setOrigin(chunk.getOrigin().x, chunk.getOrigin().y - chunk.getGlobalBounds().height/8);
				spritesLine.push_back(chunk);
			}
		}
		MatrixNewBox.push_back(spritesLine);
		spritesLine.clear();
	}
}

void NewBox::OnCollision1(sf::Vector2f& direction, const size_t& i, const size_t& j)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		this->MatrixNewBox[i][j].move(0.0f, 0.0f);
		//vx=0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the rigth
		//vx=0.0f;
		this->MatrixNewBox[i][j].move(0.0f, 0.0f);
	}

	if (direction.y < 0.0f)
	{
		//Collision on the bottom
		//vy=0.0f;
		this->MatrixNewBox[i][j].move(0.0f, 0.0f);

	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		//vy=0.0f;
		this->MatrixNewBox[i][j].move(0.0f, 0.0f);
	}
}

