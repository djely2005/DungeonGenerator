#include "Dungeon/Treasure.hpp"
#include "Dungeon/Player.hpp"
#include "iostream"

char DungeonRoad::Treasure::render(Coord *)
{
    return 'X';
}


bool DungeonRoad::Treasure::effectOnPlayer(Player* player){
    player->addToInventory(10);
    return true;
}