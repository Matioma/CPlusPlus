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
                break;
        }

    }

    return character;
}
