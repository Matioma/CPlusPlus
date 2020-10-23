#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h" 
class Sprite: public GameObject {
	public:
		sf::Sprite spriteObject;

		Sprite();
		Sprite(std::string filePath);
		Sprite(float x, float y, std::string filePath);

		virtual bool IsMouseOver() const override;

		void SetSprite(std::string filePath);

		void SpriteSetTexture(std::string fileName);

		void SetSpriteWidth(float width);
		void SetSpriteSize(float width, float heigth);


		void Step() override;
		void Draw(sf::RenderWindow& window) const override;
};