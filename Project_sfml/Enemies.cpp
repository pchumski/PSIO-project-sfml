#include <iostream>
#include <fstream>
#include <string>
#include "Enemies.h"

Enemies::Enemies(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, float positionX, float positionY) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(128.0f, 128.0f));
	//body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(positionX, positionY);
}

Enemies::~Enemies()
{
}

void Enemies::Update(float deltaTime)
{
	/*int direction = rand() % 2;
	if (direction == 0)
	{
		speed = -1 * abs(speed);
	}*/
	
	velocity.x = speed;
	if (velocity.x > 0.0f)
	{
		faceRight = true;
	}
	else
	{
		faceRight = false;
	}
	velocity.y += 981.0f * deltaTime;

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);

}

void Enemies::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Enemies::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collison on the right
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collsion on the bottom
		velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.y = 0.0f;
	}
}

void Enemies::rotation1()
{
	speed = -100.0f;
}

void Enemies::rotation2()
{
	speed = 100.0f;
}
