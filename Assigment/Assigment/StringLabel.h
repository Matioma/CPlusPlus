#pragma once

#include "TextLabel.h"

class BindedLabel : public TextLabel {
	const std::string& value;

public:
	BindedLabel(const std::string& pValue);
	~BindedLabel();

	void Step() override;
};