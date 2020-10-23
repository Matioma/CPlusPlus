#pragma once

#include "GameObject.h"
class AttributeLabel: public GameObject {

	sf::Font font;
	sf::Text textObject;
	std::string message;


	const int& value;

	public:
		AttributeLabel(const int& attributeValue, int i, std::string fontFile = "Roboto-Black.ttf");
		AttributeLabel(const int& attributeValue);
		~AttributeLabel();


		void Step() override;
		void Draw(sf::RenderWindow& window) const override;
};