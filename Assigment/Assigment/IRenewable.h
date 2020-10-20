#pragma once
#include <SFML\Graphics\RenderWindow.hpp>


class IRenuable {
	virtual void Draw(sf::RenderWindow& window) const =0;
	virtual void Step() =0;
};