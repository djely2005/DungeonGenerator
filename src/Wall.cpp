#include "Dungeon/Wall.hpp"

char DungeonRoad::Wall::render(Coord *)
{
    return '#';
}

bool DungeonRoad::Wall::effectOnPlayer(Player*){
    return true;
}