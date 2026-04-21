#include "Dungeon/Limit.hpp"
#include "Dungeon/Dungeon.hpp"

char DungeonRoad::Limit::render(Coord * coord)
{
    Dungeon *dungeon = Dungeon::getInstance();
    if (coord->x == coord->y)
    {
        return '+';
    }
    else if (coord->x == 0 || coord->x == static_cast<int>(dungeon->getWidth()) - 1)
    {
        return '|';
    }
    else if (coord->y == 0 || coord->y == static_cast<int>(dungeon->getHeight()) - 1)
    {
        return '-';
    }

    return '?';
}


bool DungeonRoad::Limit::effectOnPlayer(Player*){
    return true;
}