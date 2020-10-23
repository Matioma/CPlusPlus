#pragma once
#include "TextLabel.h"

class IntLabel : public TextLabel {
	const int& value;
	
	public:
		IntLabel(const int& pValue);
		~IntLabel();

		void Step() override;
};