#include "NewCharacter.h"


NewCharacter::NewCharacter(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(130.0f, 130.0f));
	//body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(3650.0f, 2300.0f);
	body.setTexture(texture);
}

NewCharacter::~NewCharacter()
{
}

void NewCharacter::Update(float deltaTime)
{
	velocity.x = 0.0f;
	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	//body.move(velocity * deltaTime);

}

void NewCharacter::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void NewCharacter::OnCollision(sf::Vector2f direction)
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
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.y = 0.0f;
	}
}
