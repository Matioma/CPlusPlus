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
