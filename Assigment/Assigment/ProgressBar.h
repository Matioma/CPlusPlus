#pragma once

#include "GameObject.h"

#include "Sprite.h"

class ProgressBar :public  GameObject {
	Sprite& background;
	Sprite& foreground;

	float progress =1.0f;

	int width;
	int height;




	public:
	ProgressBar(std::string backgroundFile, std::string foreGroundFile,  float progress = 1.0f);
	void SetDimensions(int width, int height);
	void SetProgress(float value);




	void Step() override;
	void Draw(sf::RenderWindow& window) const override;
};
