#pragma once
#include <string>
#include "GameObject.h"
class TextBox : public GameObject {
	public:
		sf::Font font;
		sf::Text textObject;
		std::string Message;
	

		TextBox( std::string message ="Default Text", std::string fontFile = "Roboto-Black.ttf");
		TextBox(float x, float y, std::string message = "Default Text", std::string filePath="Roboto-Black.ttf");

		void SetMessage(std::string newMessage);
		

		void Step() override;
		void Draw(sf::RenderWindow& window) const override;
};