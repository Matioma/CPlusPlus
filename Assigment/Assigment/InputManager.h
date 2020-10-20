#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

class InputManager {
public:
	~InputManager();
	static InputManager* GetInstance();


	void Initialize(sf::RenderWindow& window, SceneManager& sceneManager);
	void PollEvents();
	const sf::Vector2i GetMousePos() const;
	void HandleSceneInput(const sf::Event& eventType);
private:

	sf::Event event;
	sf::RenderWindow* renderWindow;
	SceneManager* sceneManager;

	static InputManager* Instance;
	InputManager();
};