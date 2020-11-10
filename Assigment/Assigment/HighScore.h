#pragma once

#include "GameObject.h"
#include "TextBox.h"

class HighScore :public TextBox {
		int numberOfEntries = 5;

	public:
		HighScore();

		void DisplayScore(std::vector<std::string> scores);


};