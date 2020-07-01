#pragma once
#include <vector>
#include <map>
#include <SFML\Graphics\Sprite.hpp>
#include "Collider.h"

class DangerousItems
{
public:
	DangerousItems();
	DangerousItems(std::map<char, sf::Texture*> ItemsTextures);
	~DangerousItems();

	std::vector<std::vector<sf::Sprite>> MatrixDangerousItems;
	std::vector<std::vector<char>> ArrangementDangerousItems;
	sf::Vector2f velocity;

	void loadDangerousItems();
	void createDangerousItems(std::map<char, sf::Texture*> ItemsTextures);

};
