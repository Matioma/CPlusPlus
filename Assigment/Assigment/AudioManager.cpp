#include "AudioManager.h"

void AudioManager::SetBackgroundMusic(std::string fileName)
{
	if (!fileName.compare("")) {
		return;
	}
	music.stop();
	if (!music.openFromFile(fileName)) {
		printf_s("unable to open the file %s", fileName);
	}
	music.play();
}

void AudioManager::StopBackgroundMusic() {
	music.stop();

}


void AudioManager::PlaySound(std::string fileName)
{
	if (!buffer.loadFromFile(fileName)) {
		printf_s("unable to open sound file %s", fileName);
	}
	sound.setBuffer(buffer);
	sound.play();
}
