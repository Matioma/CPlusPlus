#include "DataProcessor.h"
#include <iostream>



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
