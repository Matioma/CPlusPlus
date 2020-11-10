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
		std::vector<std::string>& getScores() { return scores; };


		void SaveData(std::string file);

		void LoadHighScore();

		void ResetHighScores();

		void SaveHighScore(int score);
};