#include "Button.h"

#include "TextBox.h"

Button::Button(std::string path):Sprite(path),
		textBox(*(new TextBox(0,0)))
{
	AddChild(&textBox);
}


void Button::BuildElement() {

}


void Button::SetText(std::string message)
{
	textBox.SetMessage(message);
}




//void Button::SetSize(sf::Vector2f size)
//{
//	SetSpriteSize(size.x, size.y);
//}
