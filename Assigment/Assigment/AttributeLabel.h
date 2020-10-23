#pragma once

#include "GameObject.h"
#include "Sprite.h"
class AttributeLabel: public GameObject {
	sf::Text labelText;

	sf::Vector2i size;
	
	Sprite* background = nullptr;




	const int& value;
	sf::Vector2f labelTextDisplacement;


	public:
		AttributeLabel(const int& attributeValue,int width, int height, std::string fontFile = "Roboto-Black.ttf");
		AttributeLabel(const int& attributeValue);
		~AttributeLabel();

		void SetBackground(std::string path);

		void moveLabelText(float x, float y);


		void Step() override;
		void Draw(sf::RenderWindow& window) const override;
};