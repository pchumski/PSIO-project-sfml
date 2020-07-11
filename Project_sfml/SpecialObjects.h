#pragma once
#include <vector>
#include <map>
#include <SFML\Graphics\Sprite.hpp>
#include "Collider.h"

class SpecialObjects
{
public:
	SpecialObjects();
	SpecialObjects(std::map<char, sf::Texture*> SpecialObjectsTextures);
	~SpecialObjects();

	std::vector<std::vector<sf::Sprite>> MatrixSpecialObjects;
	std::vector<std::vector<char>> ArrangementSpecialObjects;

	void loadSpecialObjects();
	void createSpecialObjects(std::map<char, sf::Texture*> SpecialObjectsTextures);

};
