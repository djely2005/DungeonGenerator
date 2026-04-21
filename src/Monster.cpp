#include "Dungeon/Monster.hpp"

char DungeonRoad::Monster::render(Coord *)
{
    return 'M';
}


bool DungeonRoad::Monster::effectOnPlayer(Player*){
    return true;
}