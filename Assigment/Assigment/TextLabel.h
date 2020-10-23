#pragma once
#include "GameObject.h"

class TextLabel :public GameObject{
	protected:
		sf::Text labelText;

	public:
		TextLabel(std::string message="Default Message", std::string fontFile = "Roboto-Black.ttf");
		~TextLabel();

		void Step() override;
		void Draw(sf::RenderWindow& window) const override;
};