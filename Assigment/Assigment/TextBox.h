#pragma once
#include <string>
#include "GameObject.h"
class TextBox : public GameObject {
	public:
		sf::Font font;
		sf::Text textObject;
		std::string Message;
	

		TextBox(std::string filePath);
		TextBox(float x, float y, std::string filePath);


		void Step() override;
		void Draw(sf::RenderWindow& window) const override;
};