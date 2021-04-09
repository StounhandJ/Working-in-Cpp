#include <iostream>
#include <fstream>
#include <windows.h>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;
namespace ManagementSave {

    string saveDirectory = "saves";
    string pathRecord = "record.json";

    void createDir()
    {
       CreateDirectory(saveDirectory.c_str(), NULL);
    }

    bool checkSave(string name) {
        createDir();
        fstream fileStream;
        fileStream.open(saveDirectory+"/"+name+".json");
        if (fileStream.is_open()) {
            fileStream.close();
            return true;
        }
        return false;
    }

    string getGrade(string name)
    {
        string GradeName = "";
        ifstream ifs(saveDirectory+"/"+name+".json");
        if (ifs.is_open()) {
            json data;
            ifs >> data;
            ifs.close();
            GradeName = data.contains("GradeName")? data["GradeName"].get<std::string>():"";
        }
        return GradeName;
    }

    json getSave(string name)
    {
        json data;
        ifstream ifs(saveDirectory+"/"+name+".json");
        if (ifs.is_open()) {
            ifs >> data;
            ifs.close();
        }
        return data;
    }

    void saveJSON(string name, json data)
    {
        createDir();
        std::ofstream file(saveDirectory+"/"+name+".json");
        file << data;
        file.close();
    }

    json gerRecords()
    {
        json data;
        ifstream ifs(pathRecord);
        if (ifs.is_open()) {
            ifs >> data;
            ifs.close();
        }
        return data;
    }

    void setRecord(string name, json data)
    {
        json records = gerRecords();
        records[name] = data;
        std::ofstream file(pathRecord);
        file << records;
        file.close();
    }


}