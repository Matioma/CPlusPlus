#pragma once
class InteractableObject {
	public:
		virtual bool IsMouseOver() const { return false; };
		virtual void OnClick() {};
};