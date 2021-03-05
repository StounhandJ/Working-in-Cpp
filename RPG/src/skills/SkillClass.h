#include <string>
#ifndef RPG_SKILLCLASS_H
#define RPG_SKILLCLASS_H
// SkillClass(Название, Уровень, Урон, ЦенаМаны, ТипЕлемента, МасовыйЛиУрон)


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
    bool IsAreaDamage() const{return this->areaDamage;}
    std::string getElementName() const{
        std::string text;
        switch (this->element) {
            case SkillElement::NON_ELEMENT:
                text = "Нет";
                break;
        }
        return text;}

    std::string getInfo() const {
        return "Название:"+ this->name+
        "\nСтихия:"+ this->getElementName()+
        "\nУровень: "+std::to_string(this->level)+
        "\nСила:"+std::to_string(this->power)+
        "\nМана:"+std::to_string(this->cost);
    }

    explicit SkillClass(std::string name, int level, int power, int cost, int element, bool areaDamage):
        name(std::move(name)), level(level), power(power), cost(cost), element(element), areaDamage(areaDamage)
    {

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
