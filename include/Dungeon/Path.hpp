#pragma once
#include "Tile.hpp"
#include "Ui.hpp"

namespace DungeonRoad
{

    class Path : public Tile
    {
    public:
        virtual ~Path() {};

    public:
        char render() override;
    };
} // namespace DungeonRoad