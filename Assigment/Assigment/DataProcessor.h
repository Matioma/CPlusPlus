#pragma once
#include <string>

#include <vector>

class DataProccesor {
	std::string highScoreFile = "highScore.cmgt";

	static DataProccesor* Instance;

	std::vector<std::string> scores;


	DataProccesor();
	~DataProccesor();

	public:
		static DataProccesor& GetInstance();

		void SaveData(std::string file);

		void LoadHighScore();

		void SaveHighScore(int score);
};