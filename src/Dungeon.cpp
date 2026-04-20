#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"
#include "Dungeon/TileFactory.hpp"
#include "iostream"
Dungeon *Dungeon::instance = nullptr;

Dungeon::Dungeon(size_t height, size_t width) : height(height), width(width)
{   
    for (size_t i = 0; i < height * width; i++)
    {
        this->grid.push_back(TileFactory::create(TileType::Wall));
    }
}

#include <span>

std::span<Tile*> Dungeon::operator[](int index)
{
    return {grid.begin() + (width * index), static_cast<size_t>(width)};
}

Tile *Dungeon::getTile(Coord coord)
{
    return this->grid[coord.x + width * coord.y];
}

void Dungeon::generate()
{
}

void Dungeon::findPath()
{
}

char Dungeon::render()
{
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            /* code */
            std::span<Tile *> line = (*this)[i];
            std::cout << line[j]->render() ;
        }
        std::cout << '\n';
    }
    return '?';
}