#include "Dungeon/Dungeon.hpp"
#include "Dungeon/TileFactory.hpp"
Dungeon *Dungeon::instance = nullptr;

Dungeon::Dungeon(size_t height, size_t width) : height(height), width(width)
{   
    for (size_t i = 0; i < height * width; i++)
    {
        this->grid.push_back(TileFactory::create(TileType::Wall));
    }
}

std::vector<Tile *> Dungeon::operator[](int index)
{
    std::vector<Tile *> sub = {this->grid.begin() + width * index, this->grid.begin() + width * (index + 1) - 1};
    return sub;
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

    return '?';
}