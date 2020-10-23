#include "TextBox.h"
#include "Resources.h"

TextBox::TextBox( std::string message, std::string filePath) {
	Resources& resources = *Resources::GetInstance();
	sf::Font* font = resources.GetFont(filePath);
	if (font != nullptr) {
		textObject.setFont(*font);
	}

	textObject.setString(message);
	textObject.setFillColor(sf::Color::Black);
}

TextBox::TextBox(float x, float y, std::string message, std::string filePath ): TextBox(message, filePath) {
	setPosition(x, y);
	textObject.setPosition(x, y);
}

void TextBox::SetMessage(std::string newMessage)
{
	textObject.setString(newMessage);
}

void TextBox::Step()
{
	textObject.setPosition(getPosition());
}

void TextBox::Draw(sf::RenderWindow& window) const
{
	window.draw(textObject);
}




