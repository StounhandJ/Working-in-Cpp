#include <string>
#include "nlohmann/json.hpp"

#ifndef RPG_ARTIFACTCLASS_CPP
#define RPG_ARTIFACTCLASS_CPP
using json = nlohmann::json;
// ArtifactClass(Название, Тип, HP, Мана, ФизУрон, МагУрон, Защита, Знания, Цена);

namespace Artifact {
    int const HELMET = 0;
    int const ARMOR = 1;
    int const HANDS = 2;
    int const LEGS = 3;
}

class ArtifactClass {
public:
    std::string getArtifactName() const{return ArtifactName;}
    int getType() const{return type;}
    int getGold() const{return gold;}
    int getDamage() const{return optionally_damage;}
    int getHP() const{return optionally_HP;}
    int getDefense() const{return optionally_defense;}
    int getKnowledge() const{return optionally_knowledge;}
    int getMagicPower() const{return optionally_magic_power;}
    int getMana() const{return optionally_mana;}
    std::string getTypeName() const{
        std::string text;
        switch (this->type) {
            case Artifact::HELMET:
                text = "Голова";
                break;
            case Artifact::ARMOR:
                text = "Тело";
                break;
            case Artifact::HANDS:
                text = "Руки";
                break;
            case Artifact::LEGS:
                text = "Ноги";
                break;
        }
        return text;}

    std::string getInfo() const {
        std::string text = this->ArtifactName+"\n";
        text+= this->optionally_HP!=0?"HP:"+std::to_string(this->optionally_HP)+"\n":"";
        text+= this->optionally_mana!=0?"Мана:"+std::to_string(this->optionally_mana)+"\n":"";
        text+= this->optionally_damage!=0?"Урон:"+std::to_string(this->optionally_damage)+"\n":"";
        text+= this->optionally_magic_power!=0?"Маг.сила:"+std::to_string(this->optionally_magic_power)+"\n":"";
        text+= this->optionally_defense!=0?"Защита:"+std::to_string(this->optionally_defense)+"\n":"";
        text+= this->optionally_knowledge!=0?"Знания:"+std::to_string(this->optionally_knowledge)+"\n":"";
        text+= "За "+std::to_string(this->gold)+" золотых";
        return text;
    }

    explicit ArtifactClass(std::string name, int type=Artifact::ARMOR, int optionally_HP=0, int optionally_mana = 0, int optionally_damage=0,
                           int optionally_magic_power=0, int optionally_defense=0, int optionally_knowledge=0, int gold=0):
    ArtifactName(std::move(name)), type(type), gold(gold), optionally_damage(optionally_damage), optionally_HP(optionally_HP),
    optionally_defense(optionally_defense), optionally_knowledge(optionally_knowledge), optionally_magic_power(optionally_magic_power), optionally_mana(optionally_mana)
    {

    }

    json getSave()
    {
        return json{
                {"ArtifactName", ArtifactName},
                {"type", type},
                {"gold", gold},
                {"optionally_damage", optionally_damage},
                {"optionally_HP", optionally_HP},
                {"optionally_defense", optionally_defense},
                {"optionally_knowledge", optionally_knowledge},
                {"optionally_magic_power", optionally_magic_power},
                {"optionally_mana", optionally_mana},

        };
    }

    static ArtifactClass Load(json data)
    {
        return  ArtifactClass(
                    data["ArtifactName"].get<std::string>(), data["type"].get<int>(),
                    data["optionally_HP"].get<int>(), data["optionally_mana"].get<int>(),
                    data["optionally_damage"].get<int>(),data["optionally_magic_power"].get<int>(),
                    data["optionally_defense"].get<int>(), data["optionally_knowledge"].get<int>(),
                    data["gold"].get<int>());
    }



private:
    std::string ArtifactName;
    int type,
        gold,
        optionally_damage,
        optionally_HP,
        optionally_defense,
        optionally_knowledge,
        optionally_magic_power,
        optionally_mana;
};
#endif //RPG_ARTIFACTCLASS_CPP
