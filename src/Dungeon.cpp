#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"
#include "Dungeon/TileFactory.hpp"
#include "Dungeon/Direction.hpp"
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

Tile *Dungeon::getTile(const Coord &coord)
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
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> boolDistrib(0, 1);
    std::uniform_int_distribution<> rowDistrib(0, getWidth() - 1);
    std::uniform_int_distribution<> columnDistrib(0, getHeight() - 1);
    Coord startingCell;
    if (boolDistrib(gen))
    {
        startingCell.x = columnDistrib(gen);
        startingCell.y = boolDistrib(gen) * (getHeight() - 1);
    }
    else
    {
        startingCell.x = boolDistrib(gen) * (getWidth() - 1);
        startingCell.y = rowDistrib(gen);
    }
    
    Coord currentCell = startingCell;
    do
    {
        // First Check
        std::vector<Direction> OneStepPossible{};
        if (currentCell.x + 1 < static_cast<int>(getWidth()) && !getTile({currentCell.x + 1, currentCell.y})->visited)
        {
            OneStepPossible.push_back(Direction::Right);
        }
        if (currentCell.x - 1 > 0 && !getTile({currentCell.x - 1, currentCell.y})->visited)
        {
            OneStepPossible.push_back(Direction::Left);
        }
        if (currentCell.y + 1 < static_cast<int>(getHeight()) && !getTile({currentCell.x, currentCell.y + 1})->visited)
        {
            OneStepPossible.push_back(Direction::Bottom);
        }
        if (currentCell.y - 1 > 0 && !getTile({currentCell.x, currentCell.y - 1})->visited)
        {
            OneStepPossible.push_back(Direction::Top);
        }
        std::vector<Direction> TwoStepPossible{};

        if (currentCell.x + 2 < static_cast<int>(getWidth()) && !getTile({currentCell.x + 2, currentCell.y})->visited)
        {
            TwoStepPossible.push_back(Direction::Right);
        }
        if (currentCell.x - 2 > 0 && !getTile({currentCell.x - 2, currentCell.y})->visited)
        {
            TwoStepPossible.push_back(Direction::Left);
        }
        if (currentCell.y + 2 < static_cast<int>(getHeight()) && !getTile({currentCell.x, currentCell.y + 2})->visited)
        {
            TwoStepPossible.push_back(Direction::Bottom);
        }
        if (currentCell.y - 2 > 0 && !getTile({currentCell.x, currentCell.y - 2})->visited)
        {
            TwoStepPossible.push_back(Direction::Top);
        }

    } while (currentCell.x != startingCell.x && currentCell.y != startingCell.y);
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