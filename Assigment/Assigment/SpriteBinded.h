#pragma once
#include "Sprite.h"

class SpriteBinded :public Sprite{

	const std::string& fileName;
	public:
		SpriteBinded(const std::string& filePath);

		void Step() override;
};