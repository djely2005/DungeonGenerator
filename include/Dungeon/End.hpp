#pragma once

#include "Tile.hpp"
#include "Ui.hpp"

namespace DungeonRoad
{
    class End : public Tile
    {
    public:
        virtual ~End() {};

    private:

    public:
        char render(Coord *) override;
        bool effectOnPlayer(Player *) override;
    };
}