#pragma once

#include "Tile.hpp"
#include "Ui.hpp"

class Wall : public Ui, public Tile
{
public:
    void render(char);
};