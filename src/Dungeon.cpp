#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"
#include "Dungeon/TileFactory.hpp"
#include "iostream"
#include <span>
#include <algorithm>
#include <ranges>

Dungeon *Dungeon::instance = nullptr;

Dungeon::Dungeon(size_t height, size_t width) : height(height), width(width)
{
    setPadding(2);
    addPadding();
    grid.resize(this->height);
    for (auto &&row : grid)
    {
        row.resize(this->width);
        for (auto &&cell : row)
        {
            cell = TileFactory::create(TileType::Wall);
        }
    }
    addLimits();
}

Tile *Dungeon::getTile(Coord &coord)
{
    return this->grid[coord.x][coord.y];
}

void Dungeon::addLimits()
{
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            if (i % (height - 1) == 0 || j % (width - 1) == 0)
            {
                grid[i][j] = TileFactory::create(TileType::Limit);
            }
        }
    }
}

void Dungeon::addPadding()
{
    height += padding;
    width += padding;
}

void Dungeon::generate()
{
    startingCell = Coord{}; 
}

void Dungeon::findPath()
{
}

void Dungeon::render()
{
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            Coord coord{
                static_cast<int>(i),
                static_cast<int>(j),
            };
            std::cout << this->getTile(coord)->render(&coord);
        }
        std::cout << '\n';
    }
}