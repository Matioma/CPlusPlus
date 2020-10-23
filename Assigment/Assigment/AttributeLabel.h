#pragma once

#include "GameObject.h"
#include "Sprite.h"
class AttributeLabel: public GameObject {

	sf::Text textObject;
	std::string message;



	Sprite* background;



	const int& value;

	public:
		AttributeLabel(const int& attributeValue, std::string fontFile = "Roboto-Black.ttf");
		AttributeLabel(const int& attributeValue, bool separate);
		~AttributeLabel();

		void SetBackground(std::string path);


		void Step() override;
		void Draw(sf::RenderWindow& window) const override;
};