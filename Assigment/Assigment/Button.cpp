#include "Button.h"

#include "TextBox.h"

Button::Button(std::string path):Sprite(path)
{
	BuildElement();
}

void Button::BuildElement() {
	TextBox* textBox = new TextBox(5, 10, "Hello");
	AddChild(textBox);
	//auto button = AddChild(&textBox);
}


void Button::AddText(std::string message)
{
	
}

void Button::SetSize(sf::Vector2f size)
{
	SetSpriteSize(size.x, size.y);
}

void Button::OnClick()
{
	printf_s("Default button Pressed");
}
