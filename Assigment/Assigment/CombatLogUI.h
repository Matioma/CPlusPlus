#pragma once
#include <string>
#include "TextBox.h"
#include <list>

class CombatLogUI :public TextBox{
	public:	
		std::list<std::string> Log;

		int messagesToDisplay =5;

	CombatLogUI();
	void LogData(const std::string& data);
};