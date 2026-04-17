#pragma once
#include "Tile.hpp"
#include <string>

class TileFactory{
public:
    Tile* create(std::string);
};