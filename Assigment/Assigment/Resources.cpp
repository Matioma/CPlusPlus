#include "Resources.h"

Resources* Resources::Instance = 0;

Resources::Resources() {}

Resources::~Resources()
{
    delete  Instance;
}

bool Resources::LoadTexture(const std::string path)
{
    if (LoadedTextures.count(path)) {
        return true;
    }


    sf::Texture texture;
    if (!texture.loadFromFile(path))
    {
        printf_s("unable to load find the texture %s", path);
        return false;
    }

    LoadedTextures.emplace(path, texture);
    return true;
}

sf::Texture* Resources::GetTexture(const std::string path)
{
    printf_s("%d \n", LoadedTextures.size());
    // If the texture with "path" key is not present in the map
    if (!LoadedTextures.count(path)) {
        //If managed to load "path"  file
        if (LoadTexture(path)) {
            return  &LoadedTextures[path];
        }
        //It was Not possible to locate the file
        else {
            return nullptr;
        
        }
    }
    //Get the Texture pointer
    else {
        return &LoadedTextures[path];
    }
    return nullptr;
}


Resources* Resources::GetInstance()
{
    if (Instance == 0) {
        Instance = new Resources;
    }
    return Instance;
}



