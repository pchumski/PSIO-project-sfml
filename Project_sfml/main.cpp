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

	one = new sf::Texture;
	one->loadFromFile("13.png");
	GroundTextures['d'] = one;

	one = new sf::Texture;
	one->loadFromFile("14.png");
	GroundTextures['e'] = one;

	one = new sf::Texture;
	one->loadFromFile("15.png");
	GroundTextures['f'] = one;

	one = new sf::Texture;
	one->loadFromFile("17.png");
	GroundTextures['g'] = one;

	one = new sf::Texture;
	one->loadFromFile("18.png");
	GroundTextures['h'] = one;

	Level level(GroundTextures);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("rogue2.png");

	sf::Texture background;
	background.loadFromFile("BG.png");
	sf::Sprite BackGround;
	BackGround.setTexture(background);
	BackGround.setScale(1.8f, 1.6f);
	
	Player player(&playerTexture, sf::Vector2u(6, 3), 0.3f, 200.0f, 200.0f);

	std::vector<Platform> platforms;
	std::vector<Platform> platforms2;

	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(300.0f, 370.0f)));
	
	float deltaTime = 0.0f;
	sf::Clock clock;
	sf::Vector2f direction;
	sf::Vector2f direction2;

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

		/*for(Platform& platform : platforms)
			if(platform.GetCollider().CheckCollision(col, direction, 1.0f))
				player.OnCollision(direction);

		for (Platform& platform : platforms2)
			if (platform.GetCollider().CheckCollision(col, direction2, 0.3f))
				player.OnCollision(direction2);*/

		view.setCenter(player.GetPosition());
		BackGround.setPosition(view.getCenter().x - 800, view.getCenter().y - 600);

		window.clear();
		window.draw(BackGround);
		window.setView(view);

		/*for (Platform& platform : platforms)
			platform.Draw(window);

		for (Platform& platform : platforms2)
			platform.Draw(window);*/

		for (int i = 0; i < level.Matrix.size(); i++)
		{
			for (int j = 0; j < level.Matrix[i].size(); j++)
			{
				window.draw(level.Matrix[i][j]);
			}
		}
		
		player.Draw(window);
		float deltax; //zmienna odleglosc miedzy pozycja x bohatera i pozycja x innych obiektow
		float deltay; //zmienna odleglosc miedzy pozycja y bohatera i pozycja y innych obiektow
		float intersectX; //przeciecie w osi X obiektu z bohaterem
		float intersectY; //przeciecie w osi Y obiektu z bohaterem

		//sprawdzamy kolizje naszego bohatera z kazdym obiektem na naszej mapie
		for (size_t i = 0; i < level.Matrix.size(); i++)
		{
			for (size_t j = 0; j < level.Matrix[i].size(); j++)
			{


				sf::Vector2f thisposition = level.Matrix[i][j].getPosition(); //pozycja bohatera
				sf::Vector2f otherposition = player.GetPosition(); //pozycja aktualnego obiektu
				sf::Vector2f thishalfsize(level.Matrix[i][j].getGlobalBounds().width / 2.0f, level.Matrix[i][j].getGlobalBounds().height / 2.0f);
				sf::Vector2f otherhalfsize = player.body.getSize() / 2.0f;
				bool t;
				
				deltax = otherposition.x - thisposition.x;
				deltay = otherposition.y - thisposition.y;

				intersectX = std::abs(deltax) - (otherhalfsize.x + thishalfsize.x);
				intersectY = std::abs(deltay) - (otherhalfsize.y + thishalfsize.y);

				if (intersectX < 0.0f && intersectY < 0.0f) //jesli obie osie przeciecia obiektu sa mniejsze od 0 to znaczy ze obiekty na siebie nachodza i nastepuje zderzenie
				{
					float p = 1.0f;

					if (intersectX > intersectY)
					{
						if (deltax > 0.0f)
						{
							level.Matrix[i][j].move(intersectX * (1.0f - p), 0.0f); //odbicia podczas zderzen kazdy w innym kierunku
							player.body.move(-intersectX * p, 0.0f);

							direction.x = 1.0f;
							direction.y = 0.0f;
						}
						else
						{
							level.Matrix[i][j].move(-intersectX * (1.0f - p), 0.0f);
							player.body.move(intersectX * p, 0.0f);

							direction.x = -1.0f;
							direction.y = 0.0f;
						}
					}
					else
					{
						if (deltay > 0.0f)
						{
							level.Matrix[i][j].move(0.0f, intersectY * (1.0f - p));
							player.body.move(0.0f, -intersectY * p);

							direction.x = 0.0f;
							direction.y = 1.0f;
						}
						else
						{
							level.Matrix[i][j].move(0.0f, -intersectY * (1.0f - p));
							player.body.move(0.0f, intersectY * p);

							direction.x = 0.0f;
							direction.y = -1.0f;
						}
					}
					//return true;
					t = true;

				}
				else {
					t = false;
				}
				if (t == true)
				{
					player.OnCollision(direction);
				}
			}

		}

		window.display();
	}
	delete one;
	return 0;
}