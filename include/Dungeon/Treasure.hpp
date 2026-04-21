#pragma once

#include "Tile.hpp"
#include "Ui.hpp"

namespace DungeonRoad
{
    class Treasure : public Tile
    {
    public:
        virtual ~Treasure() {};

    private:
        int value;

    public:
        char render(Coord *) override;
        bool effectOnPlayer(Player *) override;
    };
}