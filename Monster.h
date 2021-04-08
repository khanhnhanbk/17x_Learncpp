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
            {{"dragon", 'D', 20, 4, 100},
             {"orc", 'o', 4, 2, 25},
             {"slime", 's', 1, 1, 10}}};

        return monsterData.at(static_cast<std::size_t>(type));
    }

public:
    Monster(Type type);
    ~Monster();
};

Monster::Monster(Type type) : Creature(getDefaultCreature(type))
{
}

Monster::~Monster()
{
}
