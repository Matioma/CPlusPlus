#include "Button.h"

#include "TextBox.h"

Button::Button(std::string path):Sprite(path)
{
	BuildElement();
}

void Button::BuildElement() {

}


void Button::AddText(std::string message)
{
	TextBox* textBox = new TextBox(5, 10, message);
	AddChild(textBox);
}

void Button::SetSize(sf::Vector2f size)
{
	SetSpriteSize(size.x, size.y);
}

//void Button::OnClick()
//{
//	printf_s("Default button Pressed");
//}
