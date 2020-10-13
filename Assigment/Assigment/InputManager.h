#pragma once
#include <SFML/Graphics.hpp>

class InputManager {
public:
	~InputManager();
	static InputManager* getInstance();


	void Initialize(sf::RenderWindow& window);
	void Update();


	const sf::Event GetLastEvent() const;

	const sf::Vector2i GetMousePos() const;
private:
	sf::Event event;
	sf::RenderWindow* renderWindow;

	static InputManager* Instance;
	InputManager();
};