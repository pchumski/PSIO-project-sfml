#pragma once
#include <vector>
#include <map>
#include <SFML\Graphics\Sprite.hpp>
#include "Collider.h"

class NewBox
{
public:
	NewBox();
	NewBox(std::map<char, sf::Texture*> NewBoxTextures);
	~NewBox();

	std::vector<std::vector<sf::Sprite>> MatrixNewBox;
	std::vector<std::vector<char>> ArrangementNewBox;
	sf::Vector2f velocity;

	void loadNewBox();
	void createNewBox(std::map<char, sf::Texture*> NewBoxTextures);
	void OnCollision1(sf::Vector2f& direction, const size_t& i, const size_t& j);

};

