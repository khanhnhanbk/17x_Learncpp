#pragma once
#include "Creature.h"
#include "Equipment.h"
class Player : public Creature
{
protected:
    int m_level{};

public:
    Player(string name);
    ~Player();

    int getLevel() const;
    void levelUp();

    bool canEquipped(Equipment &equipment);
    void equippedWith(Equipment &equipment);

    bool hasWon();
};

Player::Player(string name) : Creature(name, '@', 10, 1, 0), m_level{1}
{
}

Player::~Player()
{
}

int Player::getLevel() const
{
    return m_level;
}

void Player::levelUp()
{
    if (!hasWon())
    {
        m_level++;
        m_damAttack++;
    }
}
bool Player::hasWon()
{
    return m_level >= 20;
}
std::ostream &operator<<(std::ostream &out, Player &player)
{
    out << player.getName() << " (Level " << player.getLevel() << ", HP = " << player.getHealth() << ", Gold = " << player.getGold()
        << ", Damage= " << player.getDame() << ")\n";
    return out;
}
// cout << "You level " << m_level << ", you HP " << m_health << "\n";
bool Player::canEquipped(Equipment &equipment)
{
    return m_gold >= equipment.getCost();
}

void Player::equippedWith(Equipment &equipment)
{
    if (canEquipped(equipment))
    {
        m_gold -= equipment.getCost();
        m_health += equipment.getAddHP();
        m_damAttack += equipment.getAddDam();
    }
    else
    {
        cout << "Not gold enough. \n";
    }
}