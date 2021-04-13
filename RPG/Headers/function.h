#ifndef RPG_FUNCTION_H
#define RPG_FUNCTION_H
void clear();
bool is_number(const std::string& s);
int input_int(const std::string& name);
std::string input_str(const std::string& name);
int choice(const std::string& question, const std::list<std::string>& variants);
int choiceWhile(const std::string& question, const std::list<std::string>& variants, bool IsZero=false);
bool percentageChance(int percentage);
int randInt(int from, int before);

bool sortLevel(std::vector<std::string> i1, std::vector<std::string> i2);
bool sortGold(std::vector<std::string> i1, std::vector<std::string> i2);
#endif //RPG_FUNCTION_H
