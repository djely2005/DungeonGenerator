#pragma once
#include <vector>
#include <span>
#include "Ui.hpp"
#include "Coord.hpp"

class Tile;

class Dungeon
{
private:
    std::vector<Tile *> grid;
    size_t height;
    size_t width;
    static Dungeon *instance;

private:
    Dungeon() = default;
    Dungeon(size_t, size_t);

public:
    size_t getHeight() const { return height; }
    size_t getWidth() const { return width; }

public:
    Dungeon(const Dungeon &) = delete;
    Dungeon &operator=(const Dungeon &) = delete;

    Tile *getTile(Coord);
    void generate();
    void render();
    void findPath();
    void addLimits();
    std::span<Tile *> operator[](int);
    std::span<Tile *> getColumn(int);
    static Dungeon *getInstance(size_t height = 5, size_t width = 5)
    {
        if (instance == nullptr)
            instance = new Dungeon(height, width);
        return instance;
    }
};