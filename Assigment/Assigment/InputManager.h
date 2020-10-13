#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

class InputManager {
public:
	~InputManager();
	static InputManager* getInstance();


	void Initialize(sf::RenderWindow& window, SceneManager& sceneManager);
	
	void PollEvents();
	const sf::Vector2i GetMousePos() const;
private:
	void HandleActiveSceneInput(sf::Event::EventType eventType);
	void CallInputEvents(GameObject* obj, sf::Event::EventType& eventType);

	sf::Event event;
	sf::RenderWindow* renderWindow;
	SceneManager* sceneManager;

	static InputManager* Instance;
	InputManager();
};