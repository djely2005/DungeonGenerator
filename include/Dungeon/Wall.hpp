#pragma once

#include "Tile.hpp"
#include "Ui.hpp"

namespace DungeonRoad
{
    class Wall : public Tile
    {
    public:
        Wall();
        virtual ~Wall() {};

    public:
        char render(Coord *) override;
        void effectOnPlayer(Player *, Coord&) override;
    };

}