#pragma once
#include <string>
#include "TextBox.h"
#include <list>

class CombatLogUI :public TextBox{
	public:	
		std::list<std::string> Log;

		int messagesToDisplay =10;
		//std::queue<std::string> Log;

	CombatLogUI();
	void LogData(std::string& data);
};