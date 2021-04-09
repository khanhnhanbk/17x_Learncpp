#include <iostream>
#include <ctime> // for time()
#include <string>
#include <cstdlib> // for rand() and srand()
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
using namespace std;
bool isPlayerRun()
{
    return rand() % 2;
}
void attackPlayer(Player &player, Monster &monster)
{
    cout << "The " << monster.getName() << " hit you for " << monster.getDame() << " damage.\n";
    player.reduceHealth(monster.getDame());
    cout << player;
    if (player.isDead())
    {
        cout << "You lost";
    }
}
void attackMonster(Player &player, Monster &monster)
{
    cout << "You hit the " << monster.getName() << " for " << player.getDame() << " damage.\n";
    monster.reduceHealth(player.getDame());
    if (monster.isDead())
    {
        cout << "You killed the " << monster.getName() << '\n';
        player.addGold(monster.getGold());
        player.levelUp();
        cout << player;
    }
    else
    {
        attackPlayer(player, monster);
    }
}
void fightMonster(Player &player, Monster &monster)
{
    system("pause");
    system("cls");
    cout << "You have encountered a " << monster.getName() << '\n';
    cout << monster;
    while (!monster.isDead() && !player.isDead() && !player.hasWon())
    {
        cout << "(R)un or (F)ight:";
        char ch;
        cin >> ch;
        if (ch == 'r')
        {
            if (isPlayerRun())
            {
                cout << "You successfully fled.\n";
                break;
            }
            else
            {
                cout << "You failed to flee.\n";
                attackPlayer(player, monster);
            }
        }
        else if (ch == 'f')
        {
            attackMonster(player, monster);
        }
    }
}
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand();                                               // get rid of first result

    cout << "Game\n";
    cout << "Enter your name: ";
    string playerName;
    cin >> playerName;

    Player player(playerName);

    cout << "You has " << player.getHealth() << " HP, " << player.getGold() << " golds\n";

    while (!player.isDead())
    {
        Monster monster{Monster::getRandomMonster()};
        fightMonster(player, monster);
    }

    return 0;
}