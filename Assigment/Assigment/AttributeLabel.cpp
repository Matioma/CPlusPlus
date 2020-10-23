#include "AttributeLabel.h"

#include "Resources.h"

AttributeLabel::AttributeLabel(const int& attributeValue, int width, int height, std::string filePath ):AttributeLabel(attributeValue)
{
	Resources& instance = Resources::GetInstance();
	sf::Font* font = instance.GetFont(filePath);

	if (font != nullptr) {
		labelText.setFont(*font);
	}
	labelText.setString("Random");
	labelText.setFillColor(sf::Color::Black);

	size.x= width;
	size.y = height;
}

AttributeLabel::AttributeLabel(const int& attributeValue):value(attributeValue)
{
}

AttributeLabel::~AttributeLabel()
{
}


void AttributeLabel::SetBackground(std::string path) {
	if (background != nullptr) {
		background->SetSprite(path);
	}
	else {
		background = new Sprite(path);
		AddChild(background);
	}
	background->SetSpriteSize(size.x, size.y);
}

void AttributeLabel::moveLabelText(float x, float y) {
	labelTextDisplacement.x = x;
	labelTextDisplacement.y = y;
}


void AttributeLabel::Step()
{
	labelText.setPosition(getPosition());
	labelText.move(labelTextDisplacement);

	std::string message= std::to_string(value);
	labelText.setString(message);
	
	GameObject::Step();
}

void AttributeLabel::Draw(sf::RenderWindow& window) const
{
	GameObject::Draw(window);
	window.draw(labelText);
}
