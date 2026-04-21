#pragma once

#include "Tile.hpp"
#include "Ui.hpp"

namespace DungeonRoad
{

    class Monster : public Tile
    {
    public:
        virtual ~Monster() {};

    private:
        int pv;

    public:
        char render(Coord *) override;
        bool effectOnPlayer(Player *) override;
    };
} // namespace DungeonRoad