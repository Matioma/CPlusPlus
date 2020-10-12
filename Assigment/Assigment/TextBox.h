#pragma once
#include <string>
#include "GameObject.h"
class TextBox : public GameObject {
	sf::Font font;


	std::string Message;
	sf::Text textObject;

	TextBox(std::string filePath);
	TextBox(float x, float y, std::string filePath);


	void Step() override;
	void Draw(sf::RenderWindow& window) const override;

};