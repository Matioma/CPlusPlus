#include "HighScore.h"

HighScore::HighScore()
{
}

void HighScore::DisplayScore(std::vector<std::string> scores)
{
	std::string newMessage = " High Score \n";
	for (int i = 0; i < numberOfEntries; i++) {
		if (scores.size() > i) {
			newMessage += std::to_string(i + 1) + ".   " + scores[i] + "\n";
		}
	}
	this->SetMessage(newMessage);
}
