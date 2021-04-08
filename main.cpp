#include <iostream>
#include <string>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
using namespace std;
int main()
{
    Monster m{Monster::Type::orc};
    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

    return 0;
}