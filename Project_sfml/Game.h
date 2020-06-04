#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include "Player.h"
#include "Platform.h"
#include "Level.h"

class Game
{ 
public:
	Player *player;
	sf::RenderWindow *window;
	sf::View *view;
	Level* level;
	sf::Event evnt;
	sf::Clock clock;
	std::map<char, sf::Texture*> GroundTextures;
	float VIEW_HEIGHT = 800.0f;
	sf::Vector2f direction;
	sf::Vector2f direction2;
	float deltaTime = 0.0f;
	sf::Texture playerTexture;
	std::vector<Platform> platforms;
	std::vector<Platform> platforms2;
	Collider col = player->GetCollider();
	sf::Texture background;
	sf::Sprite BackGround;
	sf::Texture* one = new sf::Texture;

	Game();
	~Game();
	void loadTextures();
	void loadData();
	bool Run();
	void Update();
	void Render();
	void ResizeView(const sf::RenderWindow& window, sf::View& view);
	void CheckCollision1(sf::Vector2f& direction, float p);
};

