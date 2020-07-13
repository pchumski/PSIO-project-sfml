#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float width, float height);
	~Menu();


	void draw(sf::RenderWindow *window);
	void MoveUp();
	void MoveDown();
	int GetPressItem() { return selectedItemIndex; }

	sf::Music music_menu;
//private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	
};

