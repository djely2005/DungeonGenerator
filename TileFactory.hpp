#pragma once
#include "Tile.hpp"
#include "TileType.hpp"

class TileFactory
{
public:
    Tile *create(TileType);
};