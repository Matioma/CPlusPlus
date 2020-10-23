#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
class Resources {
	public:
		static Resources& GetInstance();



		bool LoadTexture(const std::string path);
		sf::Texture* GetTexture(const std::string path);


		bool LoadFont(const std::string path);
		sf::Font* GetFont(const std::string path);

		~Resources();
	private:
		std::map<std::string, sf::Texture> LoadedTextures;
		std::map<std::string, sf::Font> LoadedFonts;

		static Resources* Instance;
		Resources();
};