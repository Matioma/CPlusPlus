#include "CharacterBuilder.h"

#include <fstream>
#include <iostream>

void CharacterBuilder::LoadNames()
{
    std::string namesFile = "./Data/Names.txt";

    std::ifstream myFileRead(namesFile);
    std::string line;

    if (myFileRead.is_open()) {
        while (std::getline(myFileRead, line)) {
            PossibleNames.push_back(line);
        }
    }
    else {
        printf_s("Could not open file %s \n", namesFile.c_str());
    }
    myFileRead.close();
}


void CharacterBuilder::LoadCharacterSprites() {
    std::string namesFile = "./Data/CharacterSpriteNames.txt";

    std::ifstream myFileRead(namesFile);
    std::string line;

    if (myFileRead.is_open()) {
        while (std::getline(myFileRead, line)) {
            SpriteFileNames.push_back(line);
        }
    }
    else {
        printf_s("Could not open file %s \n", namesFile.c_str());
    }
    myFileRead.close();


}



CharacterBuilder::CharacterBuilder()
{
    LoadNames();
    LoadCharacterSprites();
}

CharacterBuilder::~CharacterBuilder()
{
}
Character CharacterBuilder::CreateCharacter(int skillPoints)
{
    if (skillPoints < 2) {
        printf_s("Imposible to create caracter with only 1 skill point");
    }

    Character character;
    int skillPointsToDistribute =skillPoints;

    std::cout << skillPointsToDistribute << std::endl;

    int nameIndex = rand() % PossibleNames.size();

    std::string& newName = this->PossibleNames[nameIndex];
    character.SetName(newName);


    int spriteIndex = rand() % SpriteFileNames.size();
    std::string& spriteFileName = this->SpriteFileNames[spriteIndex];
    character.SetSpriteFileName("/Characters/" +spriteFileName);




    //Set initial skillPoints
    skillPointsToDistribute -= 2;
    character.AddStrength();
    character.AddWits();

    std::cout << skillPointsToDistribute << " skill points," << character.GetStrength() << " Strength, " << character.GetAgility() << " Agility, " << character.GetWits() << "wits, " << std::endl;


    //Destributing the skill Points
    while (skillPointsToDistribute > 0) {
        int attributeToChange = rand() % 3;

        skillPointsToDistribute--;
        switch (attributeToChange)
        {
            case 0:
                character.AddStrength();
                break;
            case 1:
                character.AddAgility();
                break;
            case 2:
                character.AddWits();
                break;
            default:
                std::cout << "unkown attribute" << std::endl;
                break;
        }
        std::cout << skillPointsToDistribute << " skill points," << character.GetStrength() << " Strength, " << character.GetAgility() << " Agility, " << character.GetWits() << "wits, " << std::endl;
    }

    //std::cout << skillPointsToDistribute << " skill points," << character.GetStrength() << " Strength, " << character.GetAgility() << " Agility, " << character.GetWits() << "wits, " << std::endl;

    return character;
}
