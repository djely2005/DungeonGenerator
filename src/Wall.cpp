#include "Dungeon/Wall.hpp"
#include "iostream"

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
    std::cout << "You can't move there, it's a wall!" << std::endl;
    return true;
}