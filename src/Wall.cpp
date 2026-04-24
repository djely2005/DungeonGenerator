#include "Dungeon/Wall.hpp"

DungeonRoad::Wall::Wall()
{
    visited = false;
    type = TileType::Wall;
}

char DungeonRoad::Wall::render(Coord *)
{
    return '#';
}

bool DungeonRoad::Wall::effectOnPlayer(Player *)
{
    return true;
}