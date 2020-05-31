#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Not Tetris", sf::Style::Close | sf::Style::Resize);

	sf::Event evnt;
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	/*player.setFillColor(sf::Color::Red);
	player.setOrigin(50.0f, 50.0f);*/

	player.setPosition(200.0f, 200.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("platformChar_idle.png");
	player.setTexture(&playerTexture);


	while (window.isOpen()) {

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
			/*if (evnt.type == sf::Event::Closed) {

				window.close();
			}*/			
		}

		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
		}*/

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			player.move(0.0f, 0.1f);
		}
		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}