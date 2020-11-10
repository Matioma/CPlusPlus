#include "Sprite.h"

#include "Resources.h"
#include "InputManager.h"
#include <iostream>

Sprite::Sprite()
{
	SetSprite("/Characters/con1.png");
}

Sprite::Sprite(std::string filePath)
{
	SetSprite(filePath);
	/*Resources& res = Resources::GetInstance();
	sf::Texture* texture = res.GetTexture(filePath);
	if (texture != nullptr) {
		spriteObject.setTexture(*texture);
	}*/
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

void Sprite::SetSprite(std::string filePath) {
	Resources& res = Resources::GetInstance();
	sf::Texture* texture = res.GetTexture(filePath);
	
	if (texture != nullptr) {
		spriteObject.setTexture(*texture,true);
	}
}


void Sprite::SpriteSetTexture(std::string fileName) {
	Resources& res = Resources::GetInstance();
	sf::Texture* texture = res.GetTexture(fileName);
	if (texture != nullptr) {
		spriteObject.setTexture(*texture);
	}
}


/// <summary>
/// Set width of the sprite
/// </summary>
/// <param name="newWidth"></param>
void Sprite::SetSpriteWidth( float newWidth)
{
	sf::FloatRect rect = spriteObject.getGlobalBounds();
	float scaleX = newWidth / rect.width;
	spriteObject.scale(scaleX, scaleX);

	
}


void Sprite::SetSpriteSize(float width, float heigth)
{
	sf::FloatRect rect = spriteObject.getGlobalBounds();

	


	float scaleX = width / rect.width;
	float scaleY = heigth / rect.height;

	

	if (scaleX == 0) { scaleX += 0.001f; }


	spriteObject.scale(scaleX, scaleY);
	
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
