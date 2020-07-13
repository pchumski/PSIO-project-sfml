#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Enemies
{
public:
	Enemies(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float positionX, float positionY);
	~Enemies();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow *window);
	void OnCollision(sf::Vector2f direction);

	void rotation1();
	void rotation2();

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

	sf::RectangleShape body;

	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

	sf::Vector2f velocity;

};

