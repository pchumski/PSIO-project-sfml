#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Not Tetris", sf::Style::Close | sf::Style::Resize);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("tux_from_linux.png");
	
	Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;


	while (window.isOpen()) {

		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt)) {

			switch (evnt.type) {

			case sf::Event::Closed:
				window.close();
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

		window.clear(sf::Color(150, 150, 150));
		player.Draw(window);
		window.display();
	}

	return 0;
}