#pragma once

#include "TextLabel.h"

class StringLabel : public TextLabel {
	const std::string& value;

public:
	StringLabel(const std::string& pValue);
	~StringLabel();

	void Step() override;
};