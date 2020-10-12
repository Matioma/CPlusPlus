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
	spriteObject.setPosition(x, y);
}

void Sprite::Step()
{
	GameObject::Step();

	spriteObject.move(1, 0);
	//printf_s("Sprite Step");
}

void Sprite::Draw(sf::RenderWindow& window)
{
	window.draw(spriteObject);
}
