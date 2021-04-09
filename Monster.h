#pragma once
#include "Creature.h"
#include <array>
class Monster : public Creature
{
public:
    enum class Type
    {
        dragon,
        orc,
        slime,
        max_types
    };

protected:
    /* data */
    static const Creature &getDefaultCreature(Type type)
    {
        static std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
            {{"Dragon", 'D', 20, 4, 100},
             {"Orc", 'o', 4, 2, 25},
             {"Slime", 's', 1, 1, 10}}};

        return monsterData.at(static_cast<std::size_t>(type));
    }

public:
    Monster(Type type);
    ~Monster();
    static Monster::Type getRandomMonster();
};

Monster::Monster(Type type) : Creature(getDefaultCreature(type))
{
}

Monster::~Monster()
{
}
Monster::Type Monster::getRandomMonster()
{
    int randomNumber = rand() % int(Type::max_types);
    return Monster::Type(randomNumber);
}
std::ostream &operator<<(std::ostream &out, Monster &monster)
{
    out << monster.getName() << " (HP = " << monster.getHealth() << ", Gold = " << monster.getGold()
        << ", Damage= " << monster.getDame() << ")\n";
    return out;
}