#include "GameObject.h"

void GameObject::AddChild(GameObject* gameObject)
{
	if (gameObject == nullptr) return;

	
	gameObject->SetParent(*this);
	Children.push_back(gameObject);
}

void GameObject::RemoveChild(GameObject* gameObject)
{
	for (int i = 0; i < Children.size(); i++) {
		if (Children[i] == gameObject) {
			Children.erase(Children.begin() + i);
		}
	}
}

void GameObject::SetParent(GameObject& gameObject)
{
	//Make sure that previous parent no longer has a reference to this GameObject
	if (GetParent() != nullptr) {
		GetParent()->RemoveChild(&gameObject);
	}
	this->Parent = &gameObject;
}

GameObject* GameObject::GetParent() const
{
	return Parent;
}

void GameObject::Step()
{
	for (GameObject* obj : Children) {
		obj->Step();
	}
}

void GameObject::Draw(sf::RenderWindow& window)
{
	for (GameObject* obj : Children) {
		obj->Draw(window);
	}
}


GameObject::GameObject()
{
}

GameObject::~GameObject() {
	for (auto obj : Children) {
		delete obj;
	}
	Children.clear();
}