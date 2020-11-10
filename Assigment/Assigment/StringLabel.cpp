#include "StringLabel.h"



BindedLabel::BindedLabel(const std::string& pValue):value(pValue)
{
}

BindedLabel::~BindedLabel()
{
}

void BindedLabel::Step()
{
	TextLabel::Step();
	labelText.setString(value);
}
