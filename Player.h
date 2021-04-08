#pragma once
#include "Creature.h"
class Player : public Creature
{
private:
    /* data */
public:
    Player(string name);
    ~Player();
};

Player::Player(string name):Creature(name,'@',10,1,0)
{
}

Player::~Player()
{
}
