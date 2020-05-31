#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Not Tetris", sf::Style::Close | sf::Style::Resize);

	sf::Event evnt;

	while (window.isOpen()) {

		while (window.pollEvent(evnt)) {

			switch (evnt.type) {

			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:  
				std::cout << "New window width: "<<  evnt.size.width << " New window height: " << evnt.size.height << std::endl;
				break;
			}


			/*if (evnt.type == sf::Event::Closed) {

				window.close();
			}*/
		}
	}

	return 0;
}