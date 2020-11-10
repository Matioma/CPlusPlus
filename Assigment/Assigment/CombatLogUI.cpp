#include "CombatLogUI.h"
#include <iostream>

CombatLogUI::CombatLogUI()
{
}

void CombatLogUI::LogData(const std::string& data)
{
	this->Log.push_front(data);
	
	if (Log.size() > messagesToDisplay) {
		Log.pop_back();
	}


	std::string newMessage = "";
	for (auto iterator = Log.begin(); iterator != Log.end(); ++iterator) {
		newMessage = newMessage + *iterator + "\n" ;
	}
	SetMessage(newMessage);
}
