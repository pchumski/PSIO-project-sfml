#include "Menu.h"

Menu::Menu(float width, float height)
{
	music_menu.openFromFile("menu.ogg");
	music_menu.setVolume(25);
	music_menu.setLoop(true);
	music_menu.play();
	if(!font.loadFromFile("font.ttf"))
	{

	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Black);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2.24, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2.45, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2.21, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow *window)
{
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window->draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if(selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
	}
}
