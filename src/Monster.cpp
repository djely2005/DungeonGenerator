#include "Dungeon/Monster.hpp"
#include "Dungeon/Player.hpp"
#include "Dungeon/Coord.hpp"

char DungeonRoad::Monster::render(Coord* coord)
{
    return 'M';
}


bool DungeonRoad::Monster::effectOnPlayer(Player* player){
    return true;
}