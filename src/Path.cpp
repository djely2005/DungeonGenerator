#include "Dungeon/Path.hpp"

char DungeonRoad::Path::render(Coord *)
{
    return ' ';
}


bool DungeonRoad::Path::effectOnPlayer(Player*){
    return true;
}