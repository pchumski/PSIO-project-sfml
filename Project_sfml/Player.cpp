#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) : 
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(128.0f, 128.0f));
	//body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(3500.0f, 2300.0f);
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	velocity.x = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			velocity.x -= speed*2.5f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			velocity.x += speed*2.5f;
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			velocity.x -= speed*1.5f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			velocity.x += speed*1.5f;
	}
	
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(3.0f * 981.0f * jumpHeight);
	}

	/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);                     ze starego maina
			player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
		}*/

	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	/*else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		row = 2;
		
		if (velocity.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}
	}*/
	else if ( canJump == true)
	{
		row = 1;
		if (velocity.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}
	}
	else
	{
		row = 2;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
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
