#pragma once
#include <iostream>
#include <string>
using namespace std;
class Equipment
{
private:
    string m_name;
    // char m_symbol;
    int m_AddHP;
    int m_AddDam;
    int m_cost;

public:
    Equipment(const string name = "", int HP = 0, int Dame = 0, int cost = 0);
    ~Equipment();

    string getName() const;
    int getAddHP() const;
    int getCost() const;
    int getAddDam() const;
};

Equipment::Equipment(const string name, int HP, int Dame, int cost)
    : m_name{name}, m_AddHP{HP}, m_AddDam{Dame}, m_cost{cost}
{
}

Equipment::~Equipment()
{
}
int Equipment::getAddHP() const
{
    return m_AddHP;
}
int Equipment::getAddDam() const
{
    return m_AddDam;
}
int Equipment::getCost() const
{
    return m_cost;
}
string Equipment::getName() const
{
    return m_name;
}
std::ostream &operator<<(std::ostream &out, Equipment equip)
{
    out << "*" << equip.getName() << "(Cost " << equip.getCost() << " gold, +HP: " << equip.getAddHP()
        << ", +Dame: " << equip.getAddDam() << ")\n";
    return out;
}