#pragma once
#include <vector>
#include <map>
#include <SFML\Graphics\Sprite.hpp>
#include "Collider.h"

class Coin
{
public:
	Coin();
	Coin(std::map<char, sf::Texture*> CoinTextures);
	~Coin();

	std::vector<std::vector<sf::Sprite>> MatrixCoin;
	std::vector<std::vector<char>> ArrangementCoin;

	void loadCoin();
	void createCoin(std::map<char, sf::Texture*> CoinTextures);

};
