#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include "Player.h"
#include "Platform.h"
#include "Level.h"

static const float VIEW_HEIGHT = 800.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Not Tetris", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	std::map<char, sf::Texture*> GroundTextures;

	sf::Texture *one = new sf::Texture;
	one->loadFromFile("1.png");
	GroundTextures['a'] = one;

	one = new sf::Texture;
	one->loadFromFile("2.png");
	GroundTextures['b'] = one;

	one = new sf::Texture;
	one->loadFromFile("3.png");
	GroundTextures['c'] = one;

	Level level(GroundTextures);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("rogue2.png");

	sf::Texture background;
	background.loadFromFile("BG.png");
	sf::Sprite BackGround;
	BackGround.setTexture(background);
	
	Player player(&playerTexture, sf::Vector2u(6, 3), 0.3f, 100.0f, 200.0f);

	std::vector<Platform> platforms;
	std::vector<Platform> platforms2;

	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(300.0f, 370.0f)));
	
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {

		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;

		sf::Event evnt;
		while (window.pollEvent(evnt)) {

			switch (evnt.type) {

			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			/*case sf::Event::Resized:  
				std::cout << "New window width: "<<  evnt.size.width << " New window height: " << evnt.size.height << std::endl;
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {

					printf("%c", evnt.text.unicode);
				}*/
			}			
		}

		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
		}*/

		player.Update(deltaTime);
		window.setFramerateLimit(30);
		
		Collider col = player.GetCollider();

		sf::Vector2f direction;
		sf::Vector2f direction2;

		for(Platform& platform : platforms)
			if(platform.GetCollider().CheckCollision(col, direction, 1.0f))
				player.OnCollision(direction);

		for (Platform& platform : platforms2)
			if (platform.GetCollider().CheckCollision(col, direction2, 0.3f))
				player.OnCollision(direction2);

		view.setCenter(player.GetPosition());
		BackGround.setPosition(view.getCenter().x - 400, view.getCenter().y - 400);

		window.clear();
		window.draw(BackGround);
		window.setView(view);

		for (Platform& platform : platforms)
			platform.Draw(window);

		for (Platform& platform : platforms2)
			platform.Draw(window);

		for (int i = 0; i < level.Matrix.size(); i++)
		{
			for (int j = 0; j < level.Matrix[i].size(); j++)
			{
				window.draw(level.Matrix[i][j]);
			}
		}
		player.Draw(window);

		window.display();
	}
	delete one;
	return 0;
}