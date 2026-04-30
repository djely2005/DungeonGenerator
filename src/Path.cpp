#include "Dungeon/Path.hpp"
#include "Dungeon/Player.hpp"
#include "Dungeon/Coord.hpp"

DungeonRoad::Path::Path()
{
    visited = true;
    type = TileType::Path;
}


char DungeonRoad::Path::render(Coord* coord)
{
    return ' ';
}


bool DungeonRoad::Path::effectOnPlayer(Player* player){
    return true;
}