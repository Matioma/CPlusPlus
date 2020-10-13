#pragma once
#include <functional>

class InteractableObject {
	public:
		virtual bool IsMouseOver() const { return false; };
		virtual void OnClick() { 
			if (onClick) { 
				std::invoke(onClick);
			}
		};

		std::function<void()> onClick =0;
};