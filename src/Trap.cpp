#include "Dungeon/Trap.hpp"

char DungeonRoad::Trap::render(Coord *)
{
    return 'T';
}


bool DungeonRoad::Trap::effectOnPlayer(Player*){
    return true;
}