#include "Dungeon/Treasure.hpp"

char DungeonRoad::Treasure::render(Coord *)
{
    return '+';
}


bool DungeonRoad::Treasure::effectOnPlayer(Player*){
    return true;
}