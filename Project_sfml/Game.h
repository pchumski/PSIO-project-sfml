#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include "Player.h"
#include "Platform.h"
#include "Level.h"
#include "LevelView.h"
#include "Items.h"

class Game
{ 
public:
	Player *player;
	sf::RenderWindow *window;
	sf::View *view;
	Level *level;
	LevelView *levelView;
	Items* items;
	sf::Event evnt;
	sf::Clock clock;
	std::map<char, sf::Texture*> GroundTextures;
	std::map<char, sf::Texture*> ViewTextures;
	std::map<char, sf::Texture*> ItemsTextures;
	float VIEW_HEIGHT = 800.0f;
	sf::Vector2f direction;
	sf::Vector2f direction2;
	sf::Vector2f direction3;
	float deltaTime = 0.0f;
	sf::Texture playerTexture;
	std::vector<Platform> platforms;
	std::vector<Platform> platforms2;
	Collider col = player->GetCollider();
	sf::Texture background;
	sf::Sprite BackGround;
	sf::Texture* one = new sf::Texture;
	sf::Texture* two = new sf::Texture;
	sf::Texture* three = new sf::Texture;

	Game();
	~Game();
	void loadTextures();
	void loadData();
	bool Run();
	void Update();
	void Render();
	void ResizeView(const sf::RenderWindow& window, sf::View& view);
	void CheckCollision1(sf::Vector2f& direction, float p);
	void CheckCollision2(sf::Vector2f& direction2, float p);
	void CheckCollision3(sf::Vector2f& direction3, float p);
};

