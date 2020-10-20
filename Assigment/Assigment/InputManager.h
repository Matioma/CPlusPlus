#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

class InputManager {
public:
	~InputManager();
	InputManager(sf::RenderWindow& windowRef);
	static InputManager* GetInstance();


	void PollEvents();
	const sf::Vector2i GetMousePos() const;
	void HandleSceneInput(const sf::Event& eventType);
private:
	sf::Event event;
	sf::RenderWindow& renderWindow;
	static InputManager* Instance;
	
};