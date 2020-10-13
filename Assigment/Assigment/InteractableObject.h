#pragma once
#include <functional>

class InteractableObject {
	public:
		virtual bool IsMouseOver() const { return false; };
		virtual void OnClick() { 
			printf_s("On click called");
			if (onClick) { 
				printf_s("event is valid");
				std::invoke(onClick);
			}
		};

		std::function<void()> onClick =0;
};