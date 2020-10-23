#include "AttributeElement.h"

AttributeLabel::AttributeLabel(const int& attributeValue, int i, std::string filePath ):AttributeLabel(attributeValue)
{
	std::string path = "../Resources/Fonts/" + filePath;



	//Loads font
	if (!this->font.loadFromFile(path))
	{
		printf_s("Unable to locate font file %s", filePath.c_str());
	}
	textObject.setFont(font);
	textObject.setString(message);
	//textObject.setCharacterSize(24);
	textObject.setFillColor(sf::Color::Black);
	//textObject.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

AttributeLabel::AttributeLabel(const int& attributeValue):value(attributeValue)
{
	
}

AttributeLabel::~AttributeLabel()
{
}

void AttributeLabel::Step()
{
}

void AttributeLabel::Draw(sf::RenderWindow& window) const
{
}
