#pragma once
#include "Sprite.h"

#include "TextBox.h"

class Button : public Sprite
{
public:
	Button(std::string backgroundFilePath = "Background.png");


	void BuildElement();

	void SetText(std::string);
	//void SetSize(sf::Vector2f);
private:
	TextBox& textBox;


	std::string text;
	sf::Vector2f size;
};