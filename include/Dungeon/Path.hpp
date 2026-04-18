#pragma once
#include "Tile.hpp"
#include "Ui.hpp"

class Path : public Ui, public Tile
{
public:
    void render(char);
};