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
        printf_s("unable to load find the texture %s", path.c_str());
        return false;
    }

    LoadedTextures.emplace(path, texture);
    return true;
}


bool Resources::LoadFont(const std::string path) {
    sf::Font font;
    if (!font.loadFromFile(path))
    {
        printf_s("Unable to locate font file %s", path.c_str());
        return false;
    }
    LoadedFonts.emplace(path, font);
    return true;

}

/// <summary>
/// Get text reference
/// </summary>
/// <param name="pPath"> File name in texture derictory</param>
/// <returns></returns>

sf::Texture* Resources::GetTexture(const std::string pPath)
{
    std::string path = "./Resources/Textures/" + pPath;

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


/// <summary>
/// Gets a pointer to the file
/// </summary>
/// <param name="path">file name in fonst derictory</param>
/// <returns></returns>
sf::Font* Resources::GetFont(const std::string path)
{
    std::string filePath = "./Resources/Fonts/" + path;

    // If the font with "path" key is not present in the map
    if (!LoadedFonts.count(path)) {
        //If managed to load "path"  file
        if (LoadFont(filePath)) {
            return  &LoadedFonts[filePath];
        }
        //It was Not possible to locate the file
        else {
            return nullptr;
        }
    }
    else {
        return &LoadedFonts[path];
    }

    return nullptr;
}




Resources& Resources::GetInstance()
{
    if (Instance == 0) {
        Instance = new Resources;
    }
    return *Instance;
}



