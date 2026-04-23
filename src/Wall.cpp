#include "Dungeon/Wall.hpp"

DungeonRoad::Wall::Wall()
{
    visited = false;
}

char DungeonRoad::Wall::render(Coord *)
{
    return '#';
}

bool DungeonRoad::Wall::effectOnPlayer(Player *)
{
    return true;
}