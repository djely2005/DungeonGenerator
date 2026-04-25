#pragma once
#include "Tile.hpp"
#include "TileType.hpp"

class TileFactory
{
public:
    static Tile *create(TileType);
};