#pragma once
class GameObject{
	public:
		virtual void Step() {};
		virtual void Draw(sf::RenderWindow& window) {};
};