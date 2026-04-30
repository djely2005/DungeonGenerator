#include "Dungeon/Dungeon.hpp"
#include "Dungeon/Tile.hpp"
#include "Dungeon/TileFactory.hpp"
#include "Dungeon/Player.hpp"
#include "iostream"
#include <span>
#include <algorithm>
#include <ranges>
#include <map>
#define pad 2

std::unique_ptr<Dungeon> Dungeon::instance = nullptr;

Dungeon::Dungeon(size_t row, size_t column) : padding(pad)
{
    this->row = row + pad;
    this->column = column + pad;
    grid.resize(getRow());
    for (size_t i = 0; i < getRow(); i++)
    {
        grid[i].resize(getCol());
        for (size_t j = 0; j < getCol(); j++)
        {
            grid[i][j] = std::unique_ptr<Tile>(TileFactory::create(TileType::Wall));;
        }
    }
    addLimits();
}

Tile *Dungeon::getTile(const Coord &coord)
{
    return this->grid[coord.y][coord.x].get();
}

void Dungeon::addLimits()
{
    for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < column; ++j)
        {
            if (i % (row - 1) == 0 || j % (column - 1) == 0)
            {
                grid[i][j] = std::unique_ptr<Tile>(TileFactory::create(TileType::Limit));
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

void Dungeon::replaceCase(const Coord &coord, TileType tileType)
{
    grid[coord.y][coord.x] = std::unique_ptr<Tile>(TileFactory::create(tileType));
}

void Dungeon::replaceCase(const std::vector<Coord> &coords, TileType tileType)
{
    for (auto &&coord : coords)
    {
        grid[coord.y][coord.x] = std::unique_ptr<Tile>(TileFactory::create(tileType));
    }
}

Coord Dungeon::applyDirection(const Coord &coord, Direction &direction)
{
    Coord newCoord = coord;
    switch (direction)
    {
    case Direction::Top:
        newCoord.y -= 1;
        break;
    case Direction::Bottom:
        newCoord.y += 1;
        break;
    case Direction::Left:
        newCoord.x -= 1;
        break;
    case Direction::Right:
        newCoord.x += 1;
        break;
    default:
        break;
    }
    return newCoord;
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
    replaceCase(coord, TileType::Path);

    std::vector<Direction> dirs = {Direction::Top, Direction::Bottom, Direction::Left, Direction::Right};
    std::shuffle(dirs.begin(), dirs.end(), gen);

    for (Direction dir : dirs)
    {
        Coord mid = applyDirection(coord, dir);
        Coord target = applyDirection(mid, dir);

        if (checkRowBoundaries(target.y) && checkColumnBoundaries(target.x))
        {
            if (!getTile(target)->visited)
            {

                replaceCase(mid, TileType::Path);
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

TileLocationType Dungeon::getTileLocationType(const Coord &coord)
{
    std::vector<Direction> adjacentCells;
    std::vector<Direction> dirs = {Direction::Top, Direction::Bottom, Direction::Left, Direction::Right};
    for (Direction dir : dirs)
    {
        Coord adjacent = applyDirection(coord, dir);

        if (checkRowBoundaries(adjacent.y) && checkColumnBoundaries(adjacent.x))
        {
            if (getTile(adjacent)->type == Wall)
            {
                adjacentCells.push_back(dir);
            }
        }
    }
    switch (adjacentCells.size())
    {
    case 0:
        return TileLocationType::Open;
        break;

    case 1:
        return TileLocationType::Intersection;
        break;

    case 2:
        if (
            (
                std::find(adjacentCells.begin(), adjacentCells.end(), Direction::Top) != adjacentCells.end() && std::find(adjacentCells.begin(), adjacentCells.end(), Direction::Bottom) != adjacentCells.end()) ||
            (std::find(adjacentCells.begin(), adjacentCells.end(), Direction::Left) != adjacentCells.end() && std::find(adjacentCells.begin(), adjacentCells.end(), Direction::Right) != adjacentCells.end()))
        {
            return TileLocationType::Corridor;
        }
        return TileLocationType::Turn;
        break;

    case 3:
        return TileLocationType::Deadend;
        break;
    default:
        return TileLocationType::Blocked;
        break;
    }
};

void Dungeon::populate()
{
    std::bernoulli_distribution monsterDistrib(monsterSpawnChances);
    std::bernoulli_distribution treasureTurnDistrib(treasureTurnSpawnChances);
    std::bernoulli_distribution treasureDeadendDistrib(treasureDeadendSpawnChances);
    std::bernoulli_distribution trapDistrib(trapSpawnChances);
    std::vector<Coord> monsterCoords;
    std::vector<Coord> treasureCoords;
    std::vector<Coord> trapCoords;
    std::vector<Coord> endPossibleCoords;
    for (size_t i = 0; i < getRow(); ++i)
    {
        for (size_t j = 0; j < getCol(); ++j)
        {
            Coord coord{
                static_cast<int>(j),
                static_cast<int>(i),
            };
            if (getTile(coord)->type == TileType::Path)
            {
                TileLocationType tileLocation = getTileLocationType(coord);
                if (tileLocation == TileLocationType::Corridor && monsterDistrib(gen))
                {
                    monsterCoords.push_back(coord);
                }
                else if ((tileLocation == TileLocationType::Deadend && treasureDeadendDistrib(gen)) || (tileLocation == TileLocationType::Turn && treasureTurnDistrib(gen)))
                {
                    treasureCoords.push_back(coord);
                }
                else if ((tileLocation == TileLocationType::Turn || tileLocation == TileLocationType::Corridor) && trapDistrib(gen))
                {
                    trapCoords.push_back(coord);
                }
            }
        }
    }
    for (size_t i = 0; i < getRow(); ++i)
    {
        if (i == 0)
        {
            for (size_t j = 0; j < getCol(); ++j)
            {
                if (j != 0 || j != getCol() - 1)
                {
                    Coord coord{
                        static_cast<int>(j),
                        static_cast<int>(i),
                    };
                    Direction dir = Direction::Bottom;
                    Coord adjacent = applyDirection(coord, dir);
                    if (getTile(adjacent)->type != TileType::Wall)
                    {
                        endPossibleCoords.push_back(coord);
                    }
                }
            }
        }
        else if (i == getRow() - 1)
        {
            for (size_t j = 0; j < getCol(); ++j)
            {
                if (j != 0 || j != getCol() - 1)
                {
                    Coord coord{
                        static_cast<int>(j),
                        static_cast<int>(i),
                    };
                    Direction dir = Direction::Top;
                    Coord adjacent = applyDirection(coord, dir);

                    if (getTile(adjacent)->type != TileType::Wall)
                    {
                        endPossibleCoords.push_back(coord);
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < getRow(); i++)
    {
        Coord coord{
            static_cast<int>(0),
            static_cast<int>(i),
        };
        Direction dir = Direction::Right;
        Coord adjacent = applyDirection(coord, dir);
        if (getTile(adjacent)->type != TileType::Wall)
        {
            endPossibleCoords.push_back(coord);
        }
    }
    for (size_t i = 0; i < getRow(); i++)
    {
        Coord coord{
            static_cast<int>(getRow() - 1),
            static_cast<int>(i),
        };
        Direction dir = Direction::Left;
        Coord adjacent = applyDirection(coord, dir);
        if (getTile(adjacent)->type != TileType::Wall)
        {
            endPossibleCoords.push_back(coord);
        }
    }
    std::uniform_int_distribution<> endDistrib(0, endPossibleCoords.size() - 1);
    replaceCase(monsterCoords, TileType::Monster);
    replaceCase(treasureCoords, TileType::Treasure);
    replaceCase(trapCoords, TileType::Trap);
    replaceCase(endPossibleCoords[endDistrib(gen)], TileType::End);
}

void Dungeon::findPath()
{
}

void Dungeon::render(Player* player) {
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < column; ++j) {
            Coord coord{
                static_cast<int>(j),
                static_cast<int>(i),
            };
            
            // Si un joueur est passé en paramètre et que la coordonnée correspond à sa position
            if (player != nullptr && player->getPosition().x == coord.x && player->getPosition().y == coord.y) {
                std::cout << '@';
            } else {
                std::cout << this->getTile(coord)->render(&coord);
            }
        }
        std::cout << '\n';
    }
}

Coord Dungeon::getSpawnPoint() {
    for (size_t i = 0; i < getRow(); ++i) {
        for (size_t j = 0; j < getCol(); ++j) {
            Coord current{static_cast<int>(j), static_cast<int>(i)};
            if (getTile(current)->type == TileType::Path) {
                return current;
            }
        }
    }
    return {1, 1}; // Fallback just in case
}