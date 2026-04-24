#include "Dungeon/Treasure.hpp"

char DungeonRoad::Treasure::render(Coord *)
{
    return 'X';
}


bool DungeonRoad::Treasure::effectOnPlayer(Player*){
    return true;
}