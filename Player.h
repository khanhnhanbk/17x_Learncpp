#pragma once
#include "Creature.h"
class Player : public Creature
{
protected:
    int m_level{};

public:
    Player(string name);
    ~Player();

    int getLevel() const;

    void levelUp();
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
