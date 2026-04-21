#pragma once

#include "Tile.hpp"
#include "Ui.hpp"

namespace DungeonRoad
{
    class Wall : public Tile
    {
    public:
        Wall() = default;
        virtual ~Wall() {};

    public:
        char render(Coord *) override;
        bool effectOnPlayer(Player *) override;
    };

}