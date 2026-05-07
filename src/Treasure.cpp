#include "Dungeon/Treasure.hpp"
#include "Dungeon/Player.hpp"
#include "Dungeon/Dungeon.hpp"
#include "iostream"

char DungeonRoad::Treasure::render(Coord *)
{
    return '+';
}


void DungeonRoad::Treasure::effectOnPlayer(Player* player, Coord& coord){
    player->moveTo(coord);
    player->addToInventory(1);
    Dungeon& d = Dungeon::getInstance();
    d.replaceCase(player->getPosition(), TileType::Path);
}