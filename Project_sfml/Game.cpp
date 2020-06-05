#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 800), "Not Tetris", sf::Style::Close | sf::Style::Resize);
	loadData();
	player = new Player(&playerTexture, sf::Vector2u(6, 3), 0.3f, 200.0f, 200.0f);
	level = new Level(GroundTextures);
	levelView = new LevelView(ViewTextures);
	items = new Items(ItemsTextures);
	view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
}

Game::~Game()
{
	delete one;
	delete two;
	delete three;
}

void Game::loadTextures()
{
	playerTexture.loadFromFile("rogue5.png");
	background.loadFromFile("BG.png");

	one = new sf::Texture;
	one->loadFromFile("x.png");
	GroundTextures['x'] = one;

	one = new sf::Texture;
	one->loadFromFile("1.png");
	GroundTextures['a'] = one;

	one = new sf::Texture;
	one->loadFromFile("2.png");
	GroundTextures['b'] = one;

	one = new sf::Texture;
	one->loadFromFile("3.png");
	GroundTextures['c'] = one;

	one = new sf::Texture;
	one->loadFromFile("4.png");
	GroundTextures['d'] = one;

	one = new sf::Texture;
	one->loadFromFile("5.png");
	GroundTextures['e'] = one;

	one = new sf::Texture;
	one->loadFromFile("6.png");
	GroundTextures['f'] = one;

	one = new sf::Texture;
	one->loadFromFile("7.png");
	GroundTextures['g'] = one;

	one = new sf::Texture;
	one->loadFromFile("8.png");
	GroundTextures['h'] = one;

	one = new sf::Texture;
	one->loadFromFile("9.png");
	GroundTextures['i'] = one;

	one = new sf::Texture;
	one->loadFromFile("10.png");
	GroundTextures['j'] = one;

	one = new sf::Texture;
	one->loadFromFile("11.png");
	GroundTextures['k'] = one;

	one = new sf::Texture;
	one->loadFromFile("12.png");
	GroundTextures['l'] = one;

	one = new sf::Texture;
	one->loadFromFile("13.png");
	GroundTextures['m'] = one;

	one = new sf::Texture;
	one->loadFromFile("14.png");
	GroundTextures['n'] = one;

	one = new sf::Texture;
	one->loadFromFile("15.png");
	GroundTextures['o'] = one;

	one = new sf::Texture;
	one->loadFromFile("16.png");
	GroundTextures['p'] = one;

	one = new sf::Texture;
	one->loadFromFile("17.png");
	GroundTextures['r'] = one;

	one = new sf::Texture;
	one->loadFromFile("18.png");
	GroundTextures['s'] = one;

	two = new sf::Texture;
	two->loadFromFile("Bush1.png");
	ViewTextures['1'] = two;

	two = new sf::Texture;
	two->loadFromFile("Bush2.png");
	ViewTextures['2'] = two;

	two = new sf::Texture;
	two->loadFromFile("Bush3.png");
	ViewTextures['3'] = two;

	two = new sf::Texture;
	two->loadFromFile("Bush4.png");
	ViewTextures['4'] = two;

	two = new sf::Texture;
	two->loadFromFile("Sign1.png");
	ViewTextures['5'] = two;

	two = new sf::Texture;
	two->loadFromFile("Sign2.png");
	ViewTextures['6'] = two;

	two = new sf::Texture;
	two->loadFromFile("Sign3.png");
	ViewTextures['7'] = two;

	two = new sf::Texture;
	two->loadFromFile("Stone.png");
	ViewTextures['8'] = two;

	two = new sf::Texture;
	two->loadFromFile("Tree1.png");
	ViewTextures['9'] = two;

	two = new sf::Texture;
	two->loadFromFile("Mushroom1.png");
	ViewTextures['m'] = two;

	two = new sf::Texture;
	two->loadFromFile("Mushroom2.png");
	ViewTextures['n'] = two;

	three = new sf::Texture;
	three->loadFromFile("Crate.png");
	ItemsTextures['1'] = three;
}

void Game::loadData()
{
	loadTextures();
}

bool Game::Run()
{
	return window->isOpen();
}

void Game::Update()
{
	window->setFramerateLimit(30);
	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0f / 20.0f)
		deltaTime = 1.0f / 20.0f;
	while (window->pollEvent(evnt)) {

		switch (evnt.type) {

		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::Resized:
			ResizeView(*window, *view);
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

	player->Update(deltaTime);

	/*for(Platform& platform : platforms)
			if(platform.GetCollider().CheckCollision(col, direction, 1.0f))
				player->OnCollision(direction);

		for (Platform& platform : platforms2)
			if (platform.GetCollider().CheckCollision(col, direction2, 0.3f))
				player->OnCollision(direction2);*/

	CheckCollision1(direction, 1.0f);
	CheckCollision2(direction2, 0.5f);
	CheckCollision3(direction3, 1.0f);
}

void Game::Render()
{
	BackGround.setTexture(background);
	BackGround.setScale(1.8f, 1.6f);
	view->setCenter(player->GetPosition());
	BackGround.setPosition(view->getCenter().x - 800, view->getCenter().y - 600);
	window->clear();
	window->draw(BackGround);
	window->setView(*view);

	/*platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));
	platforms2.push_back(Platform(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(300.0f, 370.0f)));

	for (Platform& platform : platforms)
			platform.Draw(*window);

	for (Platform& platform : platforms2)
			platform.Draw(*window);*/

	for (int i = 0; i < level->Matrix.size(); i++)
	{
		for (int j = 0; j < level->Matrix[i].size(); j++)
		{
			window->draw(level->Matrix[i][j]);
		}
	}

	for (int i = 0; i < levelView->MatrixView.size(); i++)
	{
		for (int j = 0; j < levelView->MatrixView[i].size(); j++)
		{
			window->draw(levelView->MatrixView[i][j]);
		}
	}

	for (int i = 0; i < items->MatrixItems.size(); i++)
	{
		for (int j = 0; j < items->MatrixItems[i].size(); j++)
		{
			window->draw(items->MatrixItems[i][j]);
		}
	}

	player->Draw(*window);
	window->display();
}

void Game::ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void Game::CheckCollision1(sf::Vector2f& direction, float p)
{
	float deltax;
	float deltay;
	float intersectX;
	float intersectY;


	for (size_t i = 0; i < this->level->Matrix.size(); i++)
	{
		for (size_t j = 0; j < this->level->Matrix[i].size(); j++)
		{


			sf::Vector2f thisposition = this ->level->Matrix[i][j].getPosition();
			sf::Vector2f otherposition = this->player->GetPosition();
			sf::Vector2f thishalfsize(this->level->Matrix[i][j].getGlobalBounds().width / 2.0f, level->Matrix[i][j].getGlobalBounds().height / 2.0f);
			sf::Vector2f otherhalfsize = this->player->body.getSize() / 2.0f;
			bool t;

			deltax = otherposition.x - thisposition.x;
			deltay = otherposition.y - thisposition.y;

			intersectX = std::abs(deltax) - (otherhalfsize.x + thishalfsize.x);
			intersectY = std::abs(deltay) - (otherhalfsize.y + thishalfsize.y);

			if (intersectX < 0.0f && intersectY < 0.0f)
			{
				p = std::min(std::max(p, 0.0f), 1.0f);

				if (intersectX > intersectY)
				{
					if (deltax > 0.0f)
					{
						this->level->Matrix[i][j].move(intersectX * (1.0f - p), 0.0f);
						this->player->body.move(-intersectX * p, 0.0f);

						direction.x = 1.0f;
						direction.y = 0.0f;
					}
					else
					{
						this->level->Matrix[i][j].move(-intersectX * (1.0f - p), 0.0f);
						this->player->body.move(intersectX * p, 0.0f);

						direction.x = -1.0f;
						direction.y = 0.0f;
					}
				}
				else
				{
					if (deltay > 0.0f)
					{
						this->level->Matrix[i][j].move(0.0f, intersectY * (1.0f - p));
						this->player->body.move(0.0f, -intersectY * p);

						direction.x = 0.0f;
						direction.y = 1.0f;
					}
					else
					{
						this->level->Matrix[i][j].move(0.0f, -intersectY * (1.0f - p));
						this->player->body.move(0.0f, intersectY * p);

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
				this->player->OnCollision(direction);
			}
		}

	}
}

void Game::CheckCollision2(sf::Vector2f& direction, float p)
{
	float deltax;
	float deltay;
	float intersectX;
	float intersectY;


	for (size_t i = 0; i < this->items->MatrixItems.size(); i++)
	{
		for (size_t j = 0; j < this->items->MatrixItems[i].size(); j++)
		{


			sf::Vector2f thisposition = this->items->MatrixItems[i][j].getPosition();
			sf::Vector2f otherposition = this->player->GetPosition();
			sf::Vector2f thishalfsize(this->items->MatrixItems[i][j].getGlobalBounds().width / 2.0f, items->MatrixItems[i][j].getGlobalBounds().height / 2.0f);
			sf::Vector2f otherhalfsize = this->player->body.getSize() / 2.0f;
			bool t;

			deltax = otherposition.x - thisposition.x;
			deltay = otherposition.y - thisposition.y;

			intersectX = std::abs(deltax) - (otherhalfsize.x + thishalfsize.x);
			intersectY = std::abs(deltay) - (otherhalfsize.y + thishalfsize.y);

			if (intersectX < 0.0f && intersectY < 0.0f)
			{
				p = std::min(std::max(p, 0.0f), 1.0f);

				if (intersectX > intersectY)
				{
					if (deltax > 0.0f)
					{
						this->items->MatrixItems[i][j].move(intersectX * (1.0f - p), 0.0f);
						this->player->body.move(-intersectX * p, 0.0f);

						direction.x = 1.0f;
						direction.y = 0.0f;
					}
					else
					{
						this->items->MatrixItems[i][j].move(-intersectX * (1.0f - p), 0.0f);
						this->player->body.move(intersectX * p, 0.0f);

						direction.x = -1.0f;
						direction.y = 0.0f;
					}
				}
				else
				{
					if (deltay > 0.0f)
					{
						this->items->MatrixItems[i][j].move(0.0f, intersectY * (1.0f - p));
						this->player->body.move(0.0f, -intersectY * p);

						direction.x = 0.0f;
						direction.y = 1.0f;
					}
					else
					{
						this->items->MatrixItems[i][j].move(0.0f, -intersectY * (1.0f - p));
						this->player->body.move(0.0f, intersectY * p);

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
				this->player->OnCollision(direction);
			}
		}

	}
}

void Game::CheckCollision3(sf::Vector2f& direction, float p)
{
	
}
