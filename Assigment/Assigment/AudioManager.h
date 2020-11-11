#pragma once
#include "Singleton.h"'
#include <stdio.h>
#include <SFML\Audio\Music.hpp>


class AudioManager :public Singleton<AudioManager> {
public:
	sf::Music music;
	

	void SetBackgroundMusic(std::string fileName);

	~AudioManager() {};
	AudioManager() {};
protected:
};