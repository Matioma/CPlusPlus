#include "DataProcessor.h"
#include <iostream>
#include <fstream>



DataProccesor* DataProccesor::Instance = 0;
DataProccesor::DataProccesor() {
}

DataProccesor::~DataProccesor()
{
}

DataProccesor& DataProccesor::GetInstance()
{
    if (Instance == 0) {
        Instance = new DataProccesor();
    }
    return *Instance;
}

void DataProccesor::SaveData(std::string file)
{
    std::cout << "Save to " << file << std::endl;
}


void DataProccesor::LoadHighScore() {
    std::ifstream highScoreFile(highScoreFile);
    std::string scoreLine;

    if (highScoreFile.is_open()) {
        while (std::getline(highScoreFile, scoreLine)) {
            scores.push_back(scoreLine);
        }
    }
    highScoreFile.close();

}

void DataProccesor::ResetHighScores() {
    std::ofstream myfile;
    myfile.open(highScoreFile);
    myfile << "";
    myfile.close();
}


void DataProccesor::SaveHighScore(int score) {
    std:std::string newScore = std::to_string(score);
    scores.push_back(newScore);

    std::ofstream myfile;
    myfile.open(highScoreFile);
    for(auto iterator = scores.begin(); iterator != scores.end(); iterator++){
        myfile << *iterator << "\n";
    }
    myfile.close();
}
