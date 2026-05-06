#include "Dungeon/Monster.hpp"
#include "Dungeon/Player.hpp"
#include "Dungeon/Coord.hpp"
#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Console.hpp"
#include "iostream"
#include <conio.h>

char DungeonRoad::Monster::render(Coord* coord)
{
    return 'M';
}


bool DungeonRoad::Monster::effectOnPlayer(Player* player){
    char input;
    Console& console = Console::getInstance();
    std::cout << "\n A monster attacks you! Do you want to fight 'F' (-20 health), run away 'R' (-5 health) Or stay where you are 'S' ?\n";
    do
    {
        input = tolower(console.getKeyDown());
        if(input=='f') 
        {
            player->removeHealth(20);
            if (player->isAlive()) 
            {
                player->addToInventory(1);
            }
            Dungeon& d = Dungeon::getInstance();
            d.replaceCase(player->getPosition(), TileType::Path);
            break;
        }
        else if(input=='r')
        {
            player->removeHealth(5);
            break;
        }
        else if(input=='s')
        {
            return false;
        }
    } while (input != 'f' || input != 'r' || input != 's');
    
    return true;
}