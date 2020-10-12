#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h" 
class Sprite: public GameObject {
	public:
		sf::Sprite spriteObject;


		Sprite(std::string filePath);
		Sprite(float x, float y, std::string filePath);


		void Step() override;
		void Draw(sf::RenderWindow& window) const override;
};