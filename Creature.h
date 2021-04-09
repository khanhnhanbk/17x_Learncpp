#pragma once

#include <string>
using namespace std;
class Creature
{
protected:
    string m_name;
    char m_symbol;
    int m_health;
    int m_damAttack;
    int m_gold;

public:
    Creature(string name, char symbol, int health, int damActtack, int gold);
    ~Creature();

    string getName() const;
    int getHealth() const;
    int getGold() const;
    char getSymbol() const;
    int getDame() const;

    void reduceHealth(int HP);
    bool isDead();
    void addGold(int gold);
};

Creature::Creature(string name, char symbol, int health, int damActtack, int gold) : m_name{name}, m_symbol{symbol}, m_health{health}, m_damAttack{damActtack}, m_gold{gold}
{
}
Creature::~Creature()
{
}
void Creature::reduceHealth(int HP)
{
    m_health -= HP;
}
bool Creature::isDead()
{
    return m_health <= 0;
}
void Creature::addGold(int gold)
{
    m_gold += gold;
}
std::string Creature::getName() const
{
    return m_name;
}
int Creature::getHealth() const
{
    return m_health;
}
int Creature::getGold() const
{
    return m_gold;
}
char Creature::getSymbol() const
{
    return m_symbol;
}
int Creature::getDame() const
{
    return m_damAttack;
}