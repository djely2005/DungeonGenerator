#include "Dungeon/Monster.hpp"
#include "Dungeon/Player.hpp"
#include "Dungeon/Coord.hpp"
#include "Dungeon/Dungeon.hpp"
#include "iostream"
#include <conio.h>

char DungeonRoad::Monster::render(Coord* coord)
{
    return 'M';
}


bool DungeonRoad::Monster::effectOnPlayer(Player* player){
    char input;
    std::cout << "\n A monster attacks you! Do you want to fight 'F' (-20 health) or run away 'R' (-5 health) ? ";
    input = _getch(); 
    if(tolower(input)=='f') 
    {
        player->removeHealth(20);
        if (!player->isAlive())
        {
            //
        }
        else 
        {
            player->addToInventory(1);
        }
        Dungeon& d = Dungeon::getInstance();
        d.replaceCase(player->getPosition(), TileType::Path);
    }
    else if(tolower(input)=='r')
    {
        player->removeHealth(5);
        if (!player->isAlive())
        {
            //
        }
    }     
    return true;
}