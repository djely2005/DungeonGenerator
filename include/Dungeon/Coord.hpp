#pragma once

struct Coord
{
    int x;
    int y;

    bool operator==(const Coord &other) const
    {
        return x == other.x && y == other.y;
    }
};
