#include "Dungeon/Limit.hpp"
#include "Dungeon/Dungeon.hpp"

DungeonRoad::Limit::Limit()
{
    visited = false;
}

char DungeonRoad::Limit::render(Coord *coord)
{
    Dungeon *dungeon = Dungeon::getInstance();
    char c = '?';

    if (coord->y == 0 || coord->y == static_cast<int>(dungeon->getHeight()) - 1)
    {
        c = '-';
    }

    if (coord->x == 0 || coord->x == static_cast<int>(dungeon->getWidth()) - 1)
    {
        c = '|';
    }

    if ((coord->x == 0 && coord->y == 0) ||
        (coord->x == static_cast<int>(dungeon->getWidth()) - 1 && coord->y == static_cast<int>(dungeon->getHeight()) - 1) ||
        (coord->x == 0 && coord->y == static_cast<int>(dungeon->getHeight()) - 1) ||
        (coord->x == static_cast<int>(dungeon->getWidth()) - 1 && coord->y == 0))
    {
        c = '+';
    }

    return c;
}

bool DungeonRoad::Limit::effectOnPlayer(Player *)
{
    return true;
}