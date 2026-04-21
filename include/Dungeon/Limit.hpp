#pragma once

#include "Tile.hpp"
#include "Ui.hpp"

namespace DungeonRoad
{
    class Limit : public Tile
    {
    public:
        Limit() = default;
        virtual ~Limit() {};

    public:
        char render(Coord *) override;
        bool effectOnPlayer(Player *) override;
    };

}