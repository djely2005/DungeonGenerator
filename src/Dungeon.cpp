#include "Dungeon.hpp"

Dungeon* Dungeon::instance = nullptr;

Dungeon::Dungeon(size_t size) : size(size)
{
    instance->grid.resize(size);
}

Tile *Dungeon::getTile(Coord coord)
{
    return this->grid[coord.x + size * coord.y];
}

void Dungeon::generate()
{
}

void Dungeon::findPath()
{
}

void Dungeon::render(char)
{
}