#pragma once
class GameObject{
	public:
		virtual void Step() = 0;
		virtual void Draw(sf::RenderWindow& window) = 0;
};