#pragma once

#include "Tile.hpp"
#include "Ui.hpp"

namespace DungeonRoad
{
    class Trap : public Tile
    {
    public:
        virtual ~Trap() {};

    private:
        int degats;

    public:
        char render(Coord *) override;
        void effectOnPlayer(Player *, Coord&) override;
    };
}