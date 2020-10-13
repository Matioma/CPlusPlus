#include "Sprite.h"

#include "Resources.h"
#include "InputManager.h"

Sprite::Sprite(std::string filePath)
{
	std::string path = "../Resources/Textures/" + filePath;
	
	Resources* res = Resources::GetInstance();
	sf::Texture* texture = res->GetTexture(path);

	sf::Sprite sprite;
	sprite.setTexture(*texture);
	spriteObject = sprite;

}

Sprite::Sprite(float x, float y, std::string filePath) :Sprite(filePath)
{
	setPosition(x, y);
	spriteObject.setPosition(getPosition());
}

bool Sprite::IsMouseOver() const
{
	sf::Vector2i mousePos = InputManager::getInstance()->GetMousePos();
	sf::FloatRect  spriteBounds = spriteObject.getGlobalBounds();

	return spriteBounds.contains(mousePos.x, mousePos.y);
}

void Sprite::SetWidth( float newWidth)
{
	sf::FloatRect rect = spriteObject.getLocalBounds();
	float scaleX = newWidth / rect.width;
	spriteObject.scale(scaleX, scaleX);
}

void Sprite::SetSpriteSize(float width, float heigth)
{
	sf::FloatRect rect = spriteObject.getLocalBounds();
	float scaleX = width / rect.width;
	float scaleY = heigth / rect.height;
	spriteObject.setScale(scaleX, scaleY);
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
