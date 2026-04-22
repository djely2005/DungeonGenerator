#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"
#include "Dungeon/TileFactory.hpp"
#include "iostream"
#include <span>
#include <algorithm>
#include <ranges>
#include <map>

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
    return this->grid[coord.y][coord.x];
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

void Dungeon::getUnvisitedPossibleDirection(std::vector<Direction> &v, const Coord &coord, int length)
{
    if (coord.x + length < static_cast<int>(getWidth()) && !getTile({coord.x + length, coord.y})->visited)
    {
        v.push_back(Direction::Right);
    }
    if (coord.x - length > 0 && !getTile({coord.x - length, coord.y})->visited)
    {
        v.push_back(Direction::Left);
    }
    if (coord.y + length < static_cast<int>(getHeight()) && !getTile({coord.x, coord.y + length})->visited)
    {
        v.push_back(Direction::Bottom);
    }
    if (coord.y - length > 0 && !getTile({coord.x, coord.y - length})->visited)
    {
        v.push_back(Direction::Top);
    }
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
    std::vector<Coord> visitedCells;
    do
    {
        if(!getTile(currentCell)->visited || visitedCells.empty())
            grid[currentCell.y][currentCell.x] = TileFactory::create(TileType::Path);
        
        auto test = grid[currentCell.y];
        render();
        std::vector<Direction> oneStepPossible;
        getUnvisitedPossibleDirection(oneStepPossible, currentCell, 1);
        std::vector<Direction> twoStepPossible;
        getUnvisitedPossibleDirection(twoStepPossible, currentCell, 2);

        std::map<Direction, int> directions;
        for (auto &&p : oneStepPossible)
        {
            directions.insert({p, 1});
        }
        for (auto &&p : twoStepPossible)
        {
            if (!directions.count(p))
            {
                directions.insert({p, 1});
            }
            else
            {
                directions[p] += 1;
            }
        }
        std::vector<Direction> possibleDirections;
        for (auto &&p : directions)
        {
            if (p.second == 2)
            {
                possibleDirections.push_back(p.first);
            }
        }
        if(std::distance(possibleDirections.begin(), possibleDirections.end()) == 0){
            currentCell = visitedCells.back();
            visitedCells.pop_back();
            continue;
        }
        
        std::uniform_int_distribution<> directionDistrib(0, possibleDirections.size() - 1);
        Direction future_direction = possibleDirections[directionDistrib(gen)];
        visitedCells.push_back(currentCell);
        if (future_direction == Direction::Top)
        {
            currentCell.y -= 1;
        }
        else if (future_direction == Direction::Bottom)
        {
            currentCell.y += 1;
        }
        else if (future_direction == Direction::Left)
        {
            currentCell.x -= 1;
        }
        else if (future_direction == Direction::Right)
        {
            currentCell.x += 1;
        }

    } while (!visitedCells.empty());
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
                static_cast<int>(j),
                static_cast<int>(i),
            };
            std::cout << this->getTile(coord)->render(&coord);
        }
        std::cout << '\n';
    }
}