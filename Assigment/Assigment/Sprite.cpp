#include "Sprite.h"

#include "Resources.h"

Sprite::Sprite(std::string filePath)
{
	Resources* res = Resources::GetInstance();
	sf::Texture* texture = res->GetTexture(filePath);

	sf::Sprite sprite;
	sprite.setTexture(*texture);
	spriteObject = sprite;
}

Sprite::Sprite(float x, float y, std::string filePath) :Sprite(filePath)
{
	setPosition(x, y);
	spriteObject.setPosition(getPosition());
}

void Sprite::Step()
{
	spriteObject.setPosition(getPosition());
	GameObject::Step();
}

void Sprite::Draw(sf::RenderWindow& window) const
{
	window.draw(spriteObject);
	GameObject::Draw(window);
	
}
