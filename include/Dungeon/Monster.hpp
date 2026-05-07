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
        int health;

    public:
        char render(Coord *) override;
        void effectOnPlayer(Player *, Coord&) override;
    };
} // namespace DungeonRoad