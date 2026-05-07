#pragma once
#include "Tile.hpp"
#include "Ui.hpp"

namespace DungeonRoad
{

    class Path : public Tile
    {
    public:
        Path();
        virtual ~Path() {};

    public:
        char render(Coord *) override;
        void effectOnPlayer(Player *, Coord&) override;
    };
} // namespace DungeonRoad