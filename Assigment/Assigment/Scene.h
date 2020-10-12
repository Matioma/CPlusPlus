#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Sprite.h"

class Scene: public GameObject {
	public:
	Scene();
	~Scene();

	virtual void InitializeScene()=0;


	void Step() override;
	void Draw(sf::RenderWindow& window) const override;
};