#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h" 
class Sprite: public GameObject {
	public:
		sf::Sprite spriteObject;


		Sprite(std::string filePath);
		Sprite(float x, float y, std::string filePath);

		virtual bool IsMouseOver() const override;

		void SetWidth(float width);


		void Step() override;
		void Draw(sf::RenderWindow& window) const override;
};