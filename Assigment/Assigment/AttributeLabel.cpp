#include "AttributeLabel.h"

#include "Resources.h"

AttributeLabel::AttributeLabel(const int& attributeValue, std::string filePath ):AttributeLabel(attributeValue,false)
{
	Resources& instance = Resources::GetInstance();
	sf::Font* font = instance.GetFont(filePath);

	if (font != nullptr) {
		textObject.setFont(*font);
	}
	textObject.setString("Random");
	textObject.setFillColor(sf::Color::Black);

}

AttributeLabel::AttributeLabel(const int& attributeValue,bool separate):value(attributeValue)
{
}

AttributeLabel::~AttributeLabel()
{
}

void AttributeLabel::Step()
{
	textObject.setPosition(getPosition());
	std::string message= std::to_string(value);
	textObject.setString(message);
	GameObject::Step();
}

void AttributeLabel::Draw(sf::RenderWindow& window) const
{
	window.draw(textObject);
}
