#include <iostream>
#include <string>
#include "Creature.h"
#include "Player.h"

using namespace std;
int main()
{
    // Creature o{"orc", 'o', 4, 2, 10};
    // o.addGold(5);
    // o.reduceHealth(1);
    // std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";
    cout << "Enter your name: ";
    string playerName;
    cin >> playerName;
    Player player(playerName);

    std::cout << "You has " << player.getHealth() << " health and is carrying " << player.getGold() << " gold.\n"
              << "You in " << player.getLevel() << " level\n";
    player.levelUp();
    std::cout << "You has " << player.getHealth() << " health and is carrying " << player.getGold() << " gold.\n"
              << "You in " << player.getLevel() << " level\n";
    return 0;
}