#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Menu.h"

void Options()
{
	sf::RenderWindow* window;
	window = new sf::RenderWindow(sf::VideoMode(800, 800), "Options");
	sf::Texture texture;
	texture.loadFromFile("options.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sf::Event evnt;
	while (window->isOpen())
	{
		while (window->pollEvent(evnt)) {

			switch (evnt.type) {

			case sf::Event::Closed:
				window->close();
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window->close();
		}
		window->clear();
		window->draw(sprite);
		window->display();
	}
}

int main()
{
	sf::RenderWindow* wndw; 
	wndw = new sf::RenderWindow(sf::VideoMode(800, 800), "Not Tetris - Menu");
	
	Menu menu(wndw->getSize().x, wndw->getSize().y);

	sf::Texture texture;
	texture.loadFromFile("menu.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	sf::Sound sound1;
	sf::SoundBuffer buffer1;
	buffer1.loadFromFile("start.wav");
	sound1.setBuffer(buffer1);
	sound1.setMinDistance(4);

	sf::Sound sound2;
	sf::SoundBuffer buffer2;
	buffer2.loadFromFile("select.wav");
	sound2.setBuffer(buffer2);
	sound2.setMinDistance(1);

	while (wndw->isOpen())
	{
		sf::Event evnt;
		
		while (wndw->pollEvent(evnt))
		{
			/*if (evnt.type == sf::Event::MouseWheelScrolled)
			{
				if (evnt.mouseButton.button == sf::Mouse::VerticalWheel) {
					menu.MoveDown();
					//menu.MoveUp();
				}
			}*/

			if (evnt.type == sf::Event::MouseButtonPressed)
			{
				if (evnt.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i mouse_position = sf::Mouse::getPosition(*wndw);
					if (menu.menu[0].getGlobalBounds().contains(float(mouse_position.x), float(mouse_position.y)))
					{
						sound1.play();
						wndw->close();
						menu.music_menu.pause();
						Game* game = new Game;
						while (game->Run())
						{
							game->Update();
							game->Render();
						}
						delete game;
					}
					if (menu.menu[1].getGlobalBounds().contains(float(mouse_position.x), float(mouse_position.y)))
					{

						Options();
					}
					if (menu.menu[2].getGlobalBounds().contains(float(mouse_position.x), float(mouse_position.y)))
					{

						wndw->close();
					}
					//menu.MoveDown();
					//menu.MoveUp();
				}
			}

			switch (evnt.type)
			{
			case sf::Event::KeyReleased:
				switch (evnt.key.code)
				{
				case sf::Keyboard::Up:
				{
					sound2.play();
					menu.MoveUp();
					break;
				}
				case sf::Keyboard::Down:
				{
					sound2.play();
					menu.MoveDown();
					break;
				}
				case::sf::Keyboard::Return:
					switch (menu.GetPressItem())
					{
						case 0:
						{
							std::cout << "Play button has been pressed" << std::endl;
							sound1.play();
							wndw->close();
							menu.music_menu.pause();
							Game* game = new Game;
							while (game->Run())
							{
								game->Update();
								game->Render();
							}
							delete game;
							break;
						}
						case 1:
						{
							std::cout << "Option button has been pressed" << std::endl;
							Options();
							break;
						}
						case 2:
						{
							wndw->close();
							
							break;
						}
					}

					break;
				}
				break;
			case sf::Event::Closed:
				wndw->close();

				break;
			}
		}

		wndw->clear();
		wndw->draw(sprite);
		menu.draw(wndw);

		wndw->display();
	}


	delete wndw;
	
	return 0;
}