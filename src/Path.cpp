#include "Dungeon/Path.hpp"

DungeonRoad::Path::Path()
{
    visited = true;
    type = TileType::Path;
}


char DungeonRoad::Path::render(Coord *)
{
    return ' ';
}


bool DungeonRoad::Path::effectOnPlayer(Player*){
    return true;
}