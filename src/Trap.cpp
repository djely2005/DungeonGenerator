#include "Dungeon/Trap.hpp"
#include "Dungeon/Player.hpp"
#include "Dungeon/Dungeon.hpp"

char DungeonRoad::Trap::render(Coord *)
{
    return 'T';
}


bool DungeonRoad::Trap::effectOnPlayer(Player* player){
    if(player->isAlive())
    {
        player->removeHealth(10);
    }
    Dungeon& d = Dungeon::getInstance();
    d.replaceCase(player->getPosition(), TileType::Path);
    return true;
}