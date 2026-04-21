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
    addLimits();
    grid.resize(this->height * this->width);
    std::fill(grid.begin(), grid.end() - 1, TileFactory::create(TileType::Wall));
    std::fill(grid.begin(), grid.end() - 1, TileFactory::create(TileType::Wall));

}

std::span<Tile *> Dungeon::operator[](int index)
{
    return {grid.begin() + (width * index), static_cast<size_t>(width)};
}

std::views<Tile *> Dungeon::getColumn(int index)
{
    auto view =
    grid
    | std::views::enumerate
    | std::views::filter([](auto p){return p.first % this->width == index})
    | std::views::transform([](auto p){ return p.second; });
    return view;
}

Tile *Dungeon::getTile(Coord coord)
{
    return this->grid[coord.x + width * coord.y];
}

void Dungeon::addLimits()
{
    ++height;
    ++width;
}

void Dungeon::generate()
{
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
            /* code */
            std::span<Tile *> line = (*this)[i];
            Coord coord{
                static_cast<int>(i),
                static_cast<int>(j),
            };
            std::cout << line[j]->render(&coord);
        }
        std::cout << '\n';
    }
}