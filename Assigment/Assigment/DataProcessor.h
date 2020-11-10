#pragma once
#include <string>
class DataProccesor {

	static DataProccesor* Instance;
	
	DataProccesor();
	~DataProccesor();

	public:
		static DataProccesor& GetInstance();

		void SaveData(std::string file);

};