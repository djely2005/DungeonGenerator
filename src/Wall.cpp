#include "Dungeon/Wall.hpp"
#include "Dungeon/Player.hpp"
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

void DungeonRoad::Wall::effectOnPlayer(Player* player, Coord& coord)
{
    std::cout << "You can't move there, it's a wall!" << std::endl;
}