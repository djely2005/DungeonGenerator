#include "Dungeon/Treasure.hpp"
#include "Dungeon/Player.hpp"
#include "Dungeon/Dungeon.hpp"
#include "iostream"

char DungeonRoad::Treasure::render(Coord *)
{
    return '+';
}


bool DungeonRoad::Treasure::effectOnPlayer(Player* player){
    player->addToInventory(1);
    Dungeon& d = Dungeon::getInstance();
    d.replaceCase(player->getPosition(), TileType::Path);
    return true;
}