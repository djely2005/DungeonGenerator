#include "Dungeon/Dungeon.hpp"

Dungeon* Dungeon::instance = nullptr;

Dungeon::Dungeon(size_t height, size_t width) : height(height), width(width)
{
    instance->grid.resize(height * width);
}

std::vector<Tile*> Dungeon::operator[](int index){
    std::vector<Tile*> sub = {this->grid.begin() + width * index, this->grid.begin() + width * (index + 1) - 1};
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

void Dungeon::render(char)
{
}