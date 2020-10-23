#include "StringLabel.h"



StringLabel::StringLabel(const std::string& pValue):value(pValue)
{
}

StringLabel::~StringLabel()
{
}

void StringLabel::Step()
{
	TextLabel::Step();
	labelText.setString(value);
}
