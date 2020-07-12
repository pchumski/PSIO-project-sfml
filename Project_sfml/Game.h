#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include "Enemies.h"
#include "Player.h"
#include "Platform.h"
#include "Level.h"
#include "LevelView.h"
#include "Items.h"
#include "Coin.h"
#include "DangerousItems.h"
#include "NewBox.h"
#include "SpecialObjects.h"

class Game
{ 
public:
	Player *player;
	sf::RenderWindow *window;
	sf::View *view;
	Level *level;
	LevelView *levelView;
	Items* items;
	Coin* coin;
	DangerousItems* dangerousitems;
	NewBox* newbox;
	SpecialObjects* specialobjects;
	sf::Event evnt;
	sf::Clock clock;
	std::map<char, sf::Texture*> GroundTextures;
	std::map<char, sf::Texture*> ViewTextures;
	std::map<char, sf::Texture*> ItemsTextures;
	std::map<char, sf::Texture*> CoinTextures;
	std::map<char, sf::Texture*> DangerousTextures;
	std::map<char, sf::Texture*> NewBoxTextures;
	std::map<char, sf::Texture*> SpecialObjectsTextures;
	float VIEW_HEIGHT = 800.0f;
	sf::Vector2f direction;
	float deltaTime = 0.0f;
	sf::Texture playerTexture;
	sf::Texture enemyTexture1;
	sf::Texture enemyTexture2;
	std::vector<Platform> platforms;
	std::vector<Platform> platforms2;
	Collider col = player->GetCollider();
	sf::Texture background;
	sf::Sprite BackGround;
	sf::Texture* one = new sf::Texture;
	sf::Texture* two = new sf::Texture;
	sf::Texture* three = new sf::Texture;
	sf::Texture* four = new sf::Texture;
	sf::Texture* five = new sf::Texture;
	sf::Texture* six = new sf::Texture;
	sf::Text lblScore;
	std::ostringstream ssScore;
	int score = 0;
	sf::Font font;
	sf::Sprite hpfull;
	sf::Texture file;
	std::vector<sf::Sprite> hp;
	sf::Sprite hpnull;
	sf::Texture filenull;
	sf::Sprite gold_coin;
	sf::Texture coin_gold;
	std::vector<std::unique_ptr<Enemies>> Enemy;
	std::vector<std::vector<char>> Arrangement;
	sf::Music music;
	sf::Sound sound1;
	sf::SoundBuffer buffer1;
	sf::Sound sound2;
	sf::SoundBuffer buffer2;
	sf::Sound sound3;
	sf::SoundBuffer buffer3;
	sf::Sound sound4;
	sf::SoundBuffer buffer4;
	sf::Sound sound5;
	sf::SoundBuffer buffer5;
	sf::Sound sound6;
	sf::SoundBuffer buffer6;
	

	Game();
	~Game();
	void loadTextures();
	void loadData();
	bool Run();
	void Update();
	void Render();
	void ResizeView(const sf::RenderWindow& window, sf::View& view);
	void CheckCollision1(sf::Vector2f& direction, float p);
	void CheckCollision2(sf::Vector2f& direction, float p);
	void CheckCollision3(sf::Vector2f& direction, float p);
	void CheckCollision4(sf::Vector2f& direction, float p);
	void CheckCollision5(sf::Vector2f& direction, float p);
	void CheckCollision6(sf::Vector2f& direction, float p);
	void CheckCollision7(sf::Vector2f& direction, float p);
	void CheckCollision8(sf::Vector2f& direction, float p);
	void CheckCollision9(sf::Vector2f& direction, float p);
	void CheckCollision10(sf::Vector2f& direction, float p);
	void CheckCollision11(sf::Vector2f& direction, float p);
	void CheckCollision12(sf::Vector2f& direction, float p);
	void CheckCollision13(sf::Vector2f& direction, float p);
	void CheckCollision14(sf::Vector2f& direction, float p);
	
	void loadEnemies();
};

