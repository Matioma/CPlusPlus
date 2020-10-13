#include "GameObject.h"
#include <iostream>

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

const sf::Vector2f GameObject::getPosition() const
{
	sf::Vector2f globalPosition =Transformable::getPosition();
	GameObject* referenceObject = GetParent();

	//referenceObject = GetParent();

	
	while (referenceObject) {
		//std::cout << referenceObject << std::endl;
		
		globalPosition += referenceObject->getPosition();
		referenceObject = referenceObject->GetParent();
	}
	return globalPosition;
}

void GameObject::Step()
{
	for (GameObject* obj : Children) {
		obj->IsMouseOver();
		obj->Step();
	}
}

void GameObject::Draw(sf::RenderWindow& window) const
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