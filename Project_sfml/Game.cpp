#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 800), "Not Tetris", sf::Style::Close | sf::Style::Resize);
	loadData();
	player = new Player(&playerTexture, sf::Vector2u(6, 3), 0.3f, 200.0f, 200.0f);
	level = new Level(GroundTextures);
	levelView = new LevelView(ViewTextures);
	items = new Items(ItemsTextures);
	coin = new Coin(CoinTextures);
	view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	dangerousitems = new DangerousItems(DangerousTextures);
}

Game::~Game()
{
	delete one;
	delete two;
	delete three;
	delete four;
	delete five;
	delete window;
	delete player;
	delete level;
	delete levelView;
	delete items;
	delete coin;
	delete view;
}

void Game::loadTextures()
{
	playerTexture.loadFromFile("rogue5.png");
	enemyTexture.loadFromFile("enemy.png");

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

	/*one = new sf::Texture;
	one->loadFromFile("17.png");
	GroundTextures['r'] = one;

	one = new sf::Texture;
	one->loadFromFile("18.png");
	GroundTextures['s'] = one;*/

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

	four = new sf::Texture;
	four->loadFromFile("coin.png");
	CoinTextures['1'] = four;

	five = new sf::Texture;
	five->loadFromFile("17.png");
	DangerousTextures['r'] = five;

	five = new sf::Texture;
	five->loadFromFile("18.png");
	DangerousTextures['s'] = five;

	
	file.loadFromFile("hpfull.png");
	hpfull.setTexture(file);
	hpfull.setScale(0.7f, 0.7f);

	filenull.loadFromFile("hpnull.png");
	hpnull.setTexture(filenull);
	hpnull.setScale(0.7f, 0.7f);

	hp.push_back(hpfull);
	hp.push_back(hpfull);
	hp.push_back(hpfull);

	hp.push_back(hpnull);
	hp.push_back(hpnull);
	hp.push_back(hpnull);

	coin_gold.loadFromFile("coin_gold.png");
	gold_coin.setTexture(coin_gold);
	gold_coin.setScale(0.5f, 0.5f);
}

void Game::loadData()
{
	loadTextures();
	loadEnemies();
}

bool Game::Run()
{
	return window->isOpen();
}

void Game::Update()
{
	window->setFramerateLimit(60);
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

	for (size_t i = 0; i < Enemy.size(); i++)
	{
		Enemy[i]->Update(deltaTime);
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
	CheckCollision4(direction4, 1.0f);
	CheckCollision5(direction5, 1.0f);
	CheckCollision6(direction6, 1.0f);
	
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
	lblScore.setPosition(view->getCenter().x + 730, view->getCenter().y - 397);
	gold_coin.setPosition(view->getCenter().x + 690, view->getCenter().y - 400);

	hp[0].setPosition(view->getCenter().x - 765, view->getCenter().y - 400);
	hp[1].setPosition(view->getCenter().x - 725, view->getCenter().y - 400);
	hp[2].setPosition(view->getCenter().x - 685, view->getCenter().y - 400);

	hp[3].setPosition(view->getCenter().x - 765, view->getCenter().y - 400);
	hp[4].setPosition(view->getCenter().x - 725, view->getCenter().y - 400);
	hp[5].setPosition(view->getCenter().x - 685, view->getCenter().y - 400);
	

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

	for (int i = 0; i < dangerousitems->MatrixDangerousItems.size(); i++)
	{
		for (int j = 0; j < dangerousitems->MatrixDangerousItems[i].size(); j++)
		{
			window->draw(dangerousitems->MatrixDangerousItems[i][j]);
		}
	}

	for (int i = 0; i < coin->MatrixCoin.size(); i++)
	{
		for (int j = 0; j < coin->MatrixCoin[i].size(); j++)
		{
			window->draw(coin->MatrixCoin[i][j]);
		}
	}

	font.loadFromFile("font.ttf");
	lblScore.setCharacterSize(20);
	lblScore.setFillColor(sf::Color::Black);
	lblScore.setFont(font);
	lblScore.setString(ssScore.str());

	for (size_t i = 0; i < Enemy.size(); i++)
	{
		Enemy[i]->Draw(*window);
	}

	player->Draw(*window);
	window->draw(lblScore);
	window->draw(gold_coin);
	if (player->hp == 3)
	{
		window->draw(hp[0]);
		window->draw(hp[1]);
		window->draw(hp[2]);
	}
	if (player->hp == 2)
	{
		window->draw(hp[0]);
		window->draw(hp[1]);
		window->draw(hp[5]);
	}
	if (player->hp == 1)
	{
		window->draw(hp[0]);
		window->draw(hp[4]);
		window->draw(hp[5]);
	}
	if (player->hp <= 0)
	{
		window->draw(hp[3]);
		window->draw(hp[4]);
		window->draw(hp[5]);
	}
	
	window->display();
}

void Game::ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
	if (score == 0)
	{
		ssScore << score;
	}
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
	float deltax;
	float deltay;
	float intersectX;
	float intersectY;


	for (size_t i = 0; i < this->coin->MatrixCoin.size(); i++)
	{
		for (size_t j = 0; j < this->coin->MatrixCoin[i].size(); j++)
		{


			sf::Vector2f thisposition = this->coin->MatrixCoin[i][j].getPosition();
			sf::Vector2f otherposition = this->player->GetPosition();
			sf::Vector2f thishalfsize(this->coin->MatrixCoin[i][j].getGlobalBounds().width / 2.0f, coin->MatrixCoin[i][j].getGlobalBounds().height / 2.0f);
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
						this->coin->MatrixCoin[i][j].move(intersectX * (1.0f - p), 0.0f);
						this->player->body.move(-intersectX * p, 0.0f);

						direction.x = 1.0f;
						direction.y = 0.0f;
					}
					else
					{
						this->coin->MatrixCoin[i][j].move(-intersectX * (1.0f - p), 0.0f);
						this->player->body.move(intersectX * p, 0.0f);

						direction.x = -1.0f;
						direction.y = 0.0f;
					}
				}
				else
				{
					if (deltay > 0.0f)
					{
						this->coin->MatrixCoin[i][j].move(0.0f, intersectY * (1.0f - p));
						this->player->body.move(0.0f, -intersectY * p);

						direction.x = 0.0f;
						direction.y = 1.0f;
					}
					else
					{
						this->coin->MatrixCoin[i][j].move(0.0f, -intersectY * (1.0f - p));
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
				score++;
				ssScore.str("");
				ssScore << score;
				lblScore.setString(ssScore.str());
				
				coin->MatrixCoin[i].erase(coin->MatrixCoin[i].begin()+j, coin->MatrixCoin[i].begin() +j+1);
				
				
			}
		}

	}
}

void Game::CheckCollision4(sf::Vector2f& direction, float p)
{


	for (size_t i = 0; i < this->level->Matrix.size(); i++)
	{
		for (size_t j = 0; j < this->level->Matrix[i].size(); j++)
		{

			for (size_t a = 0; a < this->items->MatrixItems.size(); a++) {
				for (size_t b = 0; b < this->items->MatrixItems[a].size(); b++)
				{
					
						sf::Vector2f thisposition = this->level->Matrix[i][j].getPosition();
						sf::Vector2f thishalfsize(this->level->Matrix[i][j].getGlobalBounds().width / 2.0f, this->level->Matrix[i][j].getGlobalBounds().height / 2.0f);
						sf::Vector2f otherposition = this->items->MatrixItems[a][b].getPosition();
						sf::Vector2f otherhalfsize(this->items->MatrixItems[a][b].getGlobalBounds().width / 2.0f, this->items->MatrixItems[a][b].getGlobalBounds().height / 2.0f);
						bool t;

						float deltax;
						float deltay;
						float intersectX;
						float intersectY; 

						deltax = otherposition.x - thisposition.x;
						deltay = otherposition.y - thisposition.y;

						intersectX = std::abs(deltax) - (otherhalfsize.x + thishalfsize.x);
						intersectY = std::abs(deltay) - (otherhalfsize.y + thishalfsize.y);

						if (intersectX < 1.0f && intersectY < 1.0f)
						{
							p = std::min(std::max(p, 0.0f), 1.0f);

							if (intersectX > intersectY)
							{
								if (deltax > 0.0f)
								{
									this->level->Matrix[i][j].move(intersectX * (1.0f - p), 0.0f); 
									this->items->MatrixItems[a][b].move(-intersectX * p, 0.0f);

									direction.x = 1.0f;
									direction.y = 0.0f;
								}
								else
								{
									this->level->Matrix[i][j].move(-intersectX * (1.0f - p), 0.0f);
									this->items->MatrixItems[a][b].move(intersectX * p, 0.0f);

									direction.x = -1.0f;
									direction.y = 0.0f;
								}
							}
							else
							{
								if (deltay > 0.0f)
								{
									this->level->Matrix[i][j].move(0.0f, intersectY * (1.0f - p));
									this->items->MatrixItems[a][b].move(0.0f, -intersectY * p);

									direction.x = 0.0f;
									direction.y = 1.0f;
								}
								else
								{
									this->level->Matrix[i][j].move(0.0f, -intersectY * (1.0f - p));
									this->items->MatrixItems[a][b].move(0.0f, intersectY * p);

									direction.x = 0.0f;
									direction.y = -1.0f;
								}
							}

							t = true;

						}
						else {
							t = false;
						}

						if (t == true)
						{
							this->items->OnCollision1(direction, a, b);
						}
						else
						{
							this->items->MatrixItems[a][b].move(0.0f, 0.03f);
						}
				}
			}
		}
	}

}

void Game::CheckCollision5(sf::Vector2f& direction, float p)
{
	/*float deltax;
	float deltay;
	float intersectX;
	float intersectY;*/


	for (size_t i = 0; i < this->dangerousitems->MatrixDangerousItems.size(); i++)
	{
		for (size_t j = 0; j < this->dangerousitems->MatrixDangerousItems[i].size(); j++)
		{

			if (this->player->body.getGlobalBounds().intersects(this->dangerousitems->MatrixDangerousItems[i][j].getGlobalBounds()))
			{
				player->hp -= 1;
				player->body.setPosition(3500.0f, 2300.0f);
			}

			/*sf::Vector2f thisposition = this->dangerousitems->MatrixDangerousItems[i][j].getPosition();
			sf::Vector2f otherposition = this->player->GetPosition();
			sf::Vector2f thishalfsize(this->dangerousitems->MatrixDangerousItems[i][j].getGlobalBounds().width / 2.0f, this->dangerousitems->MatrixDangerousItems[i][j].getGlobalBounds().height / 2.0f);
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
						this->dangerousitems->MatrixDangerousItems[i][j].move(intersectX * (1.0f - p), 0.0f);
						this->player->body.move(-intersectX * p, 0.0f);

						direction.x = 1.0f;
						direction.y = 0.0f;
					}
					else
					{
						this->dangerousitems->MatrixDangerousItems[i][j].move(-intersectX * (1.0f - p), 0.0f);
						this->player->body.move(intersectX * p, 0.0f);

						direction.x = -1.0f;
						direction.y = 0.0f;
					}
				}
				else
				{
					if (deltay > 0.0f)
					{
						this->dangerousitems->MatrixDangerousItems[i][j].move(0.0f, intersectY * (1.0f - p));
						this->player->body.move(0.0f, -intersectY * p);

						direction.x = 0.0f;
						direction.y = 1.0f;
					}
					else
					{
						this->dangerousitems->MatrixDangerousItems[i][j].move(0.0f, -intersectY * (1.0f - p));
						this->player->body.move(0.0f, intersectY * p);

						direction.x = 0.0f;
						direction.y = -1.0f;
					}
				}
				
				t = true;

			}
			else {
				t = false;
			}
			if (t == true)
			{
				player->hp -= 1;
				player->body.setPosition(3500.0f, 2300.0f);
				if(player->hp == 2)
				{
					hp.erase(hp.begin()+2, hp.end());
					hp.push_back(hpfull);
				}
				else if(player->hp == 1)
				{
					hp.erase(hp.begin() +1, hp.end());
					hp.push_back(hpfull);
				}
				else if (player->hp == 0)
				{
					hp.erase(hp.begin() , hp.end());
					hp.push_back(hpfull);
				}

				
			}*/
		}

	}
}

void Game::CheckCollision6(sf::Vector2f& direction, float p)
{
	float deltax;
	float deltay;
	float intersectX;
	float intersectY;

	for (size_t x = 0; x < Enemy.size(); x++)
	{

		for (size_t i = 0; i < this->level->Matrix.size(); i++)
		{
			for (size_t j = 0; j < this->level->Matrix[i].size(); j++)
			{
				sf::Vector2f thisposition = this->level->Matrix[i][j].getPosition();
				sf::Vector2f otherposition = this->Enemy[x]->GetPosition();
				sf::Vector2f thishalfsize(this->level->Matrix[i][j].getGlobalBounds().width / 2.0f, (level->Matrix[i][j].getGlobalBounds().height) / 2.0f);
				sf::Vector2f otherhalfsize = this->Enemy[x]->body.getSize() / 2.0f;

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
							this->Enemy[x]->body.move(-intersectX * p, 0.0f);
							Enemy[x]->rotation2();
							direction.x = 1.0f;
							direction.y = 0.0f;
						}
						else
						{
							this->level->Matrix[i][j].move(-intersectX * (1.0f - p), 0.0f);
							this->Enemy[x]->body.move(intersectX * p, 0.0f);
							Enemy[x]->rotation1();
							direction.x = -1.0f;
							direction.y = 0.0f;
						}
					}
					else
					{
						if (deltay > 0.0f)
						{
							this->level->Matrix[i][j].move(0.0f, intersectY * (1.0f - p));
							this->Enemy[x]->body.move(0.0f, -intersectY * p);

							direction.x = 0.0f;
							direction.y = 1.0f;
						}
						else
						{
							this->level->Matrix[i][j].move(0.0f, -intersectY * (1.0f - p));
							this->Enemy[x]->body.move(0.0f, intersectY * p);

							direction.x = 0.0f;
							direction.y = -1.0f;
						}
					}

					t = true;

				}
				else {
					t = false;
				}
				if (t == true)
				{
					this->Enemy[x]->OnCollision(direction);
				}
			}

		}
	}
}

void Game::loadEnemies()
{
	std::ifstream file("enemies.txt");
	std::string charLine;
	std::vector<char> mapLine;
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, charLine);
			for (int i = 0; i < charLine.length(); i++)
			{
				mapLine.push_back(charLine[i]);
			}
			Arrangement.push_back(mapLine);
			mapLine.clear();
			charLine.clear();
		}
	}

	for (int i = 0; i < Arrangement.size(); i++)
	{
		for (int j = 0; j < Arrangement[i].size(); j++)
		{
			if (Arrangement[i][j] == '1')
			{
				Enemy.emplace_back(std::make_unique<Enemies>(&enemyTexture, sf::Vector2u(18, 1), 0.3f, 200.0f, 200.0f, (j * 128), (i * 128)));
			}
		}
	}
}