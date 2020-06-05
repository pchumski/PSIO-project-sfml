#pragma once
#include <vector>
#include <map>
#include <SFML\Graphics\Sprite.hpp>
#include "Collider.h"

class LevelView
{
public:
	LevelView();
	LevelView(std::map<char, sf::Texture*> viewTextures);
	~LevelView();

	std::vector<std::vector<sf::Sprite>> MatrixView;
	std::vector<std::vector<char>> ArrangementView;

	void loadTextures();
	void createTextures(std::map<char, sf::Texture*> viewTextures);
};

