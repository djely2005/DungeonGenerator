#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"
#include "Dungeon/TileFactory.hpp"
#include "iostream"
#include <span>
#include <algorithm>
#include <ranges>
#include <map>

Dungeon *Dungeon::instance = nullptr;

Dungeon::Dungeon(size_t row, size_t column)
{
    padding = 2;
    this->row = row + padding;
    this->column = column + padding;
    grid.resize(getRow());
    for (size_t i = 0; i < getRow(); i++)
    {
        grid[i].resize(getCol());
        for (size_t j = 0; j < getCol(); j++)
        {
            grid[i][j] = TileFactory::create(TileType::Wall);
        }
    }
    addLimits();
}

Tile *Dungeon::getTile(const Coord &coord)
{
    return this->grid[coord.y][coord.x];
}

void Dungeon::addLimits()
{
    for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < column; ++j)
        {
            if (i % (row - 1) == 0 || j % (column - 1) == 0)
            {
                grid[i][j] = TileFactory::create(TileType::Limit);
            }
        }
    }
}

bool Dungeon::checkRowBoundaries(int row)
{
    return 0 <= row && row < static_cast<int>(getRow());
}

bool Dungeon::checkColumnBoundaries(int col)
{
    return 0 <= col && col < static_cast<int>(getCol());
}

void Dungeon::replaceCase(const Coord &coord, Tile *tile)
{
    grid[coord.y][coord.x] = tile;
}

void Dungeon::applyDirection(Coord &coord, Direction &direction)
{
    switch (direction)
    {
    case Direction::Top:
        if (checkRowBoundaries(coord.y - 1))
        {
            coord.y -= 1;
        }
        break;
    case Direction::Bottom:
        if (checkRowBoundaries(coord.y + 1))
        {
            coord.y += 1;
        }
        break;
    case Direction::Left:
        if (checkColumnBoundaries(coord.x - 1))
        {
            coord.x -= 1;
        }
        break;
    case Direction::Right:
        if (checkColumnBoundaries(coord.x + 1))
        {
            coord.x += 1;
        }
        break;

    default:
        break;
    }
};

Coord Dungeon::getStartingCell()
{
    std::uniform_int_distribution<> boolDistrib(0, 1);
    std::uniform_int_distribution<> rowDistrib(padding / 2, getCol() - 1 - padding / 2);
    std::uniform_int_distribution<> columnDistrib(padding / 2, getRow() - 1 - padding / 2);
    return {
        columnDistrib(gen),
        rowDistrib(gen),
    };
}

void Dungeon::generate(Coord &coord)
{
    replaceCase(coord, TileFactory::create(TileType::Path));
    render();

    std::vector<Direction> dirs = {Direction::Top, Direction::Bottom, Direction::Left, Direction::Right};
    std::shuffle(dirs.begin(), dirs.end(), gen);

    for (Direction dir : dirs)
    {
        Coord mid = coord;
        applyDirection(mid, dir);
        Coord target = mid;
        applyDirection(target, dir);

        if (checkRowBoundaries(target.y) && checkColumnBoundaries(target.x))
        {
            if (!getTile(target)->visited)
            {

                replaceCase(mid, TileFactory::create(TileType::Path));
                getTile(mid)->visited = true;

                generate(target);
            }
        }
    }
}

void Dungeon::generate()
{
    Coord coord = getStartingCell();
    generate(coord);


}

void Dungeon::findPath()
{
}

void Dungeon::render()
{
    for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < column; ++j)
        {
            Coord coord{
                static_cast<int>(j),
                static_cast<int>(i),
            };
            std::cout << this->getTile(coord)->render(&coord);
        }
        std::cout << '\n';
    }
}