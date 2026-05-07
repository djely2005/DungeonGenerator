#include "Dungeon/Trap.hpp"
#include "Dungeon/Player.hpp"
#include "Dungeon/Dungeon.hpp"

char DungeonRoad::Trap::render(Coord *)
{
    return 'T';
}


void DungeonRoad::Trap::effectOnPlayer(Player* player, Coord& coord){
    player->moveTo(coord);
    player->removeHealth(10);  
    Dungeon& d = Dungeon::getInstance();
    d.replaceCase(player->getPosition(), TileType::Path);
}