#include <iostream>
#include <string>
#include <utility>
#ifndef RPG_SKILLCLASS_H
#define RPG_SKILLCLASS_H
namespace SkillElement {
    int const NON_ELEMENT = 0;
}

class SkillClass {
public:
    std::string getName() const{return this->name;}
    int getLevel() const{return this->level;}
    int getPower() const{return this->power;}
    int getCost() const{return this->cost;}
    int getElement() const{return this->element;}
    std::string getElementName() const{
        std::string text;
        switch (this->element) {
            case SkillElement::NON_ELEMENT:
                text = "Нет";
                break;
        }
        return text;}

    explicit SkillClass(std::string name, int level, int power, int cost, int element):
        name(std::move(name)), level(level), power(power), cost(cost), element(element)
    {

    }

private:
    int level,
        power,
        cost,
        element;
    std::string name;
};
#endif //RPG_SKILLCLASS_H
