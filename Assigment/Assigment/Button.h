#pragma once
#include "Sprite.h"



class Button : public Sprite
{
public:
	Button(std::string backgroundFilePath = "Background.png");

	void BuildElement();

	void AddText(std::string);
	void SetSize(sf::Vector2f);
private:
	std::string text;
	sf::Vector2f size;
};