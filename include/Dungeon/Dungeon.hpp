#pragma once
#include <vector>
#include <random>
#include <span>
#include "Ui.hpp"
#include "Coord.hpp"
#include "Direction.hpp"

class Tile;

class Dungeon
{
private:
    std::vector<std::vector<Tile *>> grid;
    size_t row;
    size_t column;
    size_t padding;
    int seed = 0;
    static Dungeon *instance;

private:
    Dungeon() = default;
    Dungeon(size_t, size_t);

public:
    size_t getCol() const { return column; }
    size_t getRow() const { return row; }
    size_t getPadding() const { return padding; }
    int getSeed() const { return seed; }

    void setPadding(size_t p) { padding = p; }

public:
    Dungeon(const Dungeon &) = delete;
    Dungeon &operator=(const Dungeon &) = delete;

    Tile *getTile(const Coord &);
    void applyDirection(Coord &, Direction&);
    bool checkRowBoundaries(int);
    bool checkColumnBoundaries(int);
    void getPossibleDirection(std::vector<Direction> &, const Coord &);
    void getUnvisitedPossibleDirection(std::vector<Direction> &, const Coord &, int);
    void generate();
    void render();
    void findPath();
    void addLimits();
    void addPadding();
    static Dungeon *getInstance(size_t height = 5, size_t width = 5)
    {
        if (instance == nullptr)
            instance = new Dungeon(height, width);
        return instance;
    }
};