#pragma once

#include "Tile.hpp"
#include "Ui.hpp"

namespace DungeonRoad
{
    class Limit : public Tile
    {
    public:
        Limit();
        virtual ~Limit() {};

    public:
        char render(Coord *) override;
        void effectOnPlayer(Player *, Coord&) override;
    };

}