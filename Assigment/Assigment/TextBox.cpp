#include "TextBox.h"

TextBox::TextBox(std::string filePath) {
	if (!this->font.loadFromFile("../Resources/Roboto-Black.ttf"))
	{
		printf_s("Unable to locate font file %s",filePath.c_str());
	}
}

TextBox::TextBox(float x, float y, std::string filePath): TextBox(filePath) {
	setPosition(x, y);
}

void TextBox::Step()
{
}

void TextBox::Draw(sf::RenderWindow& window) const
{
}




