#include "GameObject.h"
#include <iostream>
#include "InputManager.h"

GameObject& GameObject::AddChild(GameObject* gameObject)
{
	if (gameObject == nullptr) {
		printf_s("Tried to add a null pointer object as a child");
	} 

	gameObject->SetParent(*this);
	Children.push_back(gameObject);

	return *gameObject;
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
		GetParent()->RemoveChild(this);
	}
	this->Parent = &gameObject;
}

GameObject* const GameObject::GetParent() const { return Parent; }

/// <summary>
/// Computes the position of the sprite in global world by 
/// summing up all the offset of parents
/// </summary>
/// <returns> Global Position of the GameObject</returns>
const sf::Vector2f GameObject::getPosition() const
{
	sf::Vector2f globalPosition =Transformable::getPosition();
	GameObject* referenceObject = GetParent();
	
	//Loop through all parents
	while (referenceObject) {
		globalPosition += referenceObject->getPosition();
		referenceObject = referenceObject->GetParent();
	}
	return globalPosition;
}

void GameObject::Step() 
{
	for (GameObject* obj : Children) {
		obj->Step();
	}
}

void GameObject::Draw(sf::RenderWindow& window) const 
{
	for (GameObject* obj : Children) {
		obj->Draw(window);
	}
}

void GameObject::HandleInput(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (this->IsMouseOver())
				this->OnClick();
		}
	}
	for (GameObject* obj : Children) {
		obj->HandleInput(event);
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