#ifndef RPG_MANAGEMENTSAVE_H
#define RPG_MANAGEMENTSAVE_H
namespace ManagementSave{
    bool checkSave(std::string name);
    std::string getGrade(std::string name);
    json getSave(std::string name);
    void saveJSON(std::string name, json data);
}
#endif //RPG_MANAGEMENTSAVE_H
