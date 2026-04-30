#include "Dungeon/Trap.hpp"
#include "Dungeon/Player.hpp"

char DungeonRoad::Trap::render(Coord *)
{
    return 'T';
}


bool DungeonRoad::Trap::effectOnPlayer(Player* player){
    if(player->isAlive())
    {
        player->removeHealth(10);
    }
    return true;
}