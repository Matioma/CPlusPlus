#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class GameObject{
	public:
		std::vector<GameObject*> Children;

		GameObject();
		~GameObject();
		
		
		void AddChild(GameObject* gameObject);

		void RemoveChild(GameObject* gameObject);
		void SetParent(GameObject& gameObject);
		GameObject* GetParent() const;




		virtual void Step();
		virtual void Draw(sf::RenderWindow& window);

	private:
		GameObject* Parent;
};