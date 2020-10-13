#include "TextBox.h"

TextBox::TextBox( std::string message, std::string filePath) {
	std::string path = "../Resources/Fonts/" + filePath;


	if (!this->font.loadFromFile(path))
	{
		printf_s("Unable to locate font file %s",filePath.c_str());
	}
	textObject.setFont(font);
	textObject.setString(message);
	//textObject.setCharacterSize(24);
	textObject.setFillColor(sf::Color::Black);
	//textObject.setStyle(sf::Text::Bold | sf::Text::Underlined);
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




