#include <iostream>
#include <string>
#include "Creature.h"
#include "Player.h"
#include "Monter.h"
using namespace std;
int main()
{
    Monter m{Monter::Type::orc};
    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

    return 0;
}