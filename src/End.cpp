#include "Dungeon/End.hpp"

char DungeonRoad::End::render(Coord *)
{
    return 'E';
}


bool DungeonRoad::End::effectOnPlayer(Player*){
    return true;
}