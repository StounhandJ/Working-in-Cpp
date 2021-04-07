#include <string>
#include "nlohmann/json.hpp"
#ifndef RPG_SKILLCLASS_H
#define RPG_SKILLCLASS_H
using json = nlohmann::json;
// SkillClass(Название, Уровень, Урон, ЦенаМаны, ТипЕлемента, МасовыйЛиУрон)


namespace SkillElement {
    int const NON_ELEMENT = 0;
    int const LIGHT = 1;
    int const DARK = 2;
    int const SPOILAGE = 3;
    int const FIRE = 4;
    int const WATER = 5;
    std::string getElementName(int element){
        std::string text;
        switch (element) {
            case SkillElement::NON_ELEMENT:
                text = "Нет";
                break;
            case SkillElement::LIGHT:
                text = "Свет";
                break;
            case SkillElement::DARK:
                text = "Тьма";
                break;
            case SkillElement::SPOILAGE:
                text = "Порча";
                break;
            case SkillElement::FIRE:
                text = "Огонь";
                break;
            case SkillElement::WATER:
                text = "Вода";
                break;
        }
        return text;}
}

class SkillClass {
public:
    std::string getName() const{return this->name;}
    int getLevel() const{return this->level;}
    int getPower() const{return this->power;}
    int getCost() const{return this->cost;}
    int getElement() const{return this->element;}
    bool IsAreaDamage() const{return this->areaDamage;}

    std::string getInfo() const {
        return "Название:"+ this->name+
        "\nСтихия:"+ SkillElement::getElementName(this->element)+
        "\nУровень: "+std::to_string(this->level)+
        "\nСила:"+std::to_string(this->power)+
        "\nМана:"+std::to_string(this->cost);
    }

    explicit SkillClass(std::string name, int level, int power, int cost, int element, bool areaDamage):
        name(std::move(name)), level(level), power(power), cost(cost), element(element), areaDamage(areaDamage)
    {

    }

    json getSave()
    {
        return json{
                {"name", name},
                {"level", level},
                {"power", power},
                {"cost", cost},
                {"element", element},
                {"areaDamage", areaDamage}

        };
    }

    static SkillClass Load(json data)
    {
        return  SkillClass(data["name"].get<std::string>(), data["level"].get<int>(),
                data["power"].get<int>(), data["cost"].get<int>(),
                data["element"].get<int>(), data["areaDamage"].get<bool>());
    }

private:
    int level,
        power,
        cost,
        element;
    bool areaDamage;
    std::string name;
};
#endif //RPG_SKILLCLASS_H
