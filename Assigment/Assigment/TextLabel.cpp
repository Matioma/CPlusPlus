#include "TextLabel.h"

#include "Resources.h"

TextLabel::TextLabel(std::string message, std::string fontFile)
{
	Resources& instance = Resources::GetInstance();
	sf::Font* font = instance.GetFont(fontFile);

	if (font != nullptr) {
		labelText.setFont(*font);
	}
	labelText.setString(message);
	labelText.setFillColor(sf::Color::Black);
}

TextLabel::~TextLabel()
{
}

void TextLabel::SetLabel(std::string message)
{
	labelText.setString(message);
}

void TextLabel::Step()
{
	labelText.setPosition(getPosition());
}

void TextLabel::Draw(sf::RenderWindow& window) const
{
	GameObject::Draw(window);
	window.draw(labelText);
}
