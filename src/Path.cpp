#include "Dungeon/Path.hpp"

DungeonRoad::Path::Path()
{
    visited = true;
}


char DungeonRoad::Path::render(Coord *)
{
    return ' ';
}


bool DungeonRoad::Path::effectOnPlayer(Player*){
    return true;
}