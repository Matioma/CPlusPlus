#include "ProgressBar.h"
#include <iostream>


ProgressBar::ProgressBar(std::string backgroundFile, std::string foreGroundFile, float progress):
	background(*(new Sprite(backgroundFile))), foreground(*(new Sprite(foreGroundFile)))
{

	AddChild(&background);
	AddChild(&foreground);
}

void ProgressBar::SetDimensions(int width, int height)
{
	this->width = width;
	this->height = height;
	background.SetSpriteSize(width, height);
	foreground.SetSpriteSize(width, height);
}

void ProgressBar::SetProgress(float value)
{
	if (value != this->progress) {
		this->progress = value; 
		foreground.SetSpriteSize(width* value,height);
	}
}

void ProgressBar::Step()
{
	GameObject::Step();
}

void ProgressBar::Draw(sf::RenderWindow& window) const
{
	GameObject::Draw(window);
}
