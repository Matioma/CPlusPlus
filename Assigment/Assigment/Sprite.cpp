#include "Sprite.h"

#include "Resources.h"
#include "InputManager.h"

Sprite::Sprite(std::string filePath)
{
	
	Resources* res = Resources::GetInstance();
	sf::Texture* texture = res->GetTexture(filePath);
	sf::Sprite sprite;
	if (texture != nullptr) {
		sprite.setTexture(*texture);
	}
	spriteObject = sprite;
}

Sprite::Sprite(float x, float y, std::string filePath) :Sprite(filePath)
{
	setPosition(x, y);
	spriteObject.setPosition(getPosition());
}

bool Sprite::IsMouseOver() const
{
	sf::Vector2i mousePos = InputManager::GetInstance()->GetMousePos();
	sf::FloatRect  spriteBounds = spriteObject.getGlobalBounds();

	return spriteBounds.contains(mousePos.x, mousePos.y);
}


/// <summary>
/// Set width of the sprite
/// </summary>
/// <param name="newWidth"></param>
void Sprite::SetSpriteWidth( float newWidth)
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
