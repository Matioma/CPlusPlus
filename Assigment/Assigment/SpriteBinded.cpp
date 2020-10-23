#include "SpriteBinded.h"

SpriteBinded::SpriteBinded(const std::string& filePath):fileName(filePath)
{}

void SpriteBinded::Step()
{
	
	//spriteObject.setScale(2, 2);
	//spriteObject.scale(1.01, 1.01);
	SpriteSetTexture(fileName);
	Sprite::Step();
}
