#include <string>
#include <list>
#ifndef RPG_FUNCTION_H
#define RPG_FUNCTION_H
enum ConsoleColor{};
void clear();
int input_int(const std::string& name);
std::string input_str(const std::string& name);
void SetColor(ConsoleColor text, ConsoleColor background);
int choice(const std::string& question, const std::list<std::string>& variants);
int choiceWhile(const std::string& question, const std::list<std::string>& variants, bool IsZero=false);
bool percentageChance(int percentage);
int randInt(int from, int before);
#endif //RPG_FUNCTION_H
