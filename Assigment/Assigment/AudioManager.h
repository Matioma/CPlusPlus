#pragma once
#include "Singleton.h"'
#include <stdio.h>
#include <SFML\Audio\Music.hpp>
#include <SFML/Audio.hpp>


class AudioManager :public Singleton<AudioManager> {
public:
	sf::Music music;
	sf::SoundBuffer buffer;
	sf::Sound sound;

	void SetBackgroundMusic(std::string fileName);
	void StopBackgroundMusic();
	void PlaySound(std::string fileName);

	~AudioManager() {};
	AudioManager() {};
protected:
};