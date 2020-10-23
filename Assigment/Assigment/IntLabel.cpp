#include "IntLabel.h"

IntLabel::IntLabel(const int& pValue):value(pValue)
{
}

IntLabel::~IntLabel()
{
}

void IntLabel::Step()
{
	TextLabel::Step();

	std::string message = std::to_string(value);
	labelText.setString(message);
}
