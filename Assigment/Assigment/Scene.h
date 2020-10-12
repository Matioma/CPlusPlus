#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Scene: public GameObject {
	public:
	std::vector<sf::Sprite> sceneSprites;

	Scene();
	~Scene();

	virtual void InitializeScene()=0;


	void Step() override;
	void Draw(sf::RenderWindow& window) override;
};